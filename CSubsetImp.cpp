#include "CSubsetImp.h"
#include "symbol_table/2205047_symbol_table.h"
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

SymbolTable table(30);
ofstream file("log.txt");
ofstream err("error.txt");
string currentType = "";

static set<int> unnamedParameterLines, badDeclarationLines, badAddAssignLines;
static multimap<int, string> missingSemicolons;
// Function visitors create the outer function scope. Track that one exact
// compound-statement context; every other compound statement is nested.
static antlr4::ParserRuleContext *functionBodyContext = nullptr;

void noteUnnamedParameter(int line) { unnamedParameterLines.insert(line); }
void noteBadDeclaration(int line) { badDeclarationLines.insert(line); }
void noteBadAddAssign(int line) { badAddAssignLines.insert(line); }
void noteMissingSemicolon(int line, const string &expression) { missingSemicolons.emplace(line, expression); }
bool hasUnnamedParameter(int line) { return unnamedParameterLines.count(line) != 0; }
bool takeBadDeclaration(int line) { return badDeclarationLines.erase(line) != 0; }
bool takeBadAddAssign(int line) { return badAddAssignLines.erase(line) != 0; }
bool takeMissingSemicolon(int line, const string &expression) {
     auto range = missingSemicolons.equal_range(line);
     for (auto it = range.first; it != range.second; ++it) {
          if (it->second == expression) { missingSemicolons.erase(it); return true; }
     }
     return false;
}
void writeSyntaxError(int line, const string &message) {
     file << "Error at line " << line << ": syntax error, " << message << endl << endl;
     err << "Error at line " << line << ": syntax error, " << message << endl << endl;
}

void appendLogSummary(int totalLines)
{
     // Error messages are already written to error.txt, so count completed
     // diagnostics instead of duplicating error accounting in every visitor.
     err.flush();
     int totalErrors = 0;
     ifstream errorFile("error.txt");
     string line;
     while (getline(errorFile, line))
          if (line.rfind("Error at line ", 0) == 0)
               ++totalErrors;

     file << "Total lines: " << totalLines << endl;
     file << "Total errors: " << totalErrors << endl;
     file.flush();
}

std::string getRawText(antlr4::ParserRuleContext *ctx)
{
     if (!ctx || !ctx->getStart() || !ctx->getStop())
          return "";

     auto start = ctx->getStart()->getStartIndex();
     auto stop = ctx->getStop()->getStopIndex();

     if (start < 0 || stop < start)
          return "";

     return ctx->getStart()->getInputStream()->getText(
         antlr4::misc::Interval(start, stop));
}

void insertSymbol(SymbolInfo *symbol, antlr4::ParserRuleContext *ctx)
{
     int bucketIndex, position;
     int line_number = ctx->getStart()->getLine();
     if (!table.insert(symbol, bucketIndex, position))
     {
          file << "Error at line " << line_number << ": Multiple declaration of " << symbol->name << endl
               << endl;

          err << "Error at line " << line_number << ": Multiple declaration of " << symbol->name << endl
              << endl;
     }
}

void insertParameterSymbol(SymbolInfo *symbol, antlr4::ParserRuleContext *ctx)
{
     int bucketIndex, position;
     if (!table.insert(symbol, bucketIndex, position))
     {
          int line = ctx->getStart()->getLine();
          file << "Error at line " << line << ": Multiple declaration of " << symbol->name << " in parameter" << endl << endl;
          err << "Error at line " << line << ": Multiple declaration of " << symbol->name << " in parameter" << endl << endl;
     }
}

int isValidFloat(const string &s)
{
     if (s.empty())
          return 0;

     bool hasDigit = false;
     bool hasDot = false;
     bool hasExp = false;

     size_t i = 0;

     // Optional sign
     if (s[i] == '+' || s[i] == '-')
          i++;

     for (; i < s.length(); i++)
     {
          char c = s[i];

          if (c >= '0' && c <= '9')
          {
               hasDigit = true;
          }
          else if (c == '.')
          {
               if (hasDot || hasExp)
                    return 0;

               hasDot = true;
          }
          else if (c == 'e' || c == 'E')
          {
               if (!hasDigit || hasExp)
                    return 0;

               hasExp = true;
               hasDigit = false;

               // Optional exponent sign
               if (i + 1 < s.length() &&
                   (s[i + 1] == '+' || s[i + 1] == '-'))
               {
                    i++;
               }
          }
          else
          {
               return 0;
          }
     }

     // Must contain a decimal point OR exponent
     return hasDigit && (hasDot || hasExp);
}

bool isString(const string &s)
{
     if (s.empty())
          return false;

     // Check integer
     try
     {
          size_t pos;
          stoi(s, &pos);

          if (pos == s.length())
               return false; // It is an integer
     }
     catch (...)
     {
          // Not an integer, continue
     }

     // Check float
     try
     {
          size_t pos;
          stof(s, &pos);

          if (pos == s.length())
               return false; // It is a float
     }
     catch (...)
     {
          // Not a float
     }

     return true; // Neither integer nor float
}
/*
bool checkVoidFunctionCall(antlr4::tree::ParseTree *node)
{
    if (node == nullptr)
        return false;

    // Check whether this node itself is:
    // factor : ID LPAREN argument_list RPAREN
    //          #factor_function_call
    auto *function_call =
        dynamic_cast<CSubsetParser::Factor_function_callContext *>(node);

    if (function_call != nullptr)
    {
        string function_name = function_call->ID()->getText();

        int bucketIndex, position;
        string scopeId;

        SymbolInfo *symbol =
            table.lookup(
                function_name,
                bucketIndex,
                position,
                scopeId
            );

        if (symbol != nullptr && symbol->type == "void")
        {
            return true;
        }
    }

    // Recursively search all children
    if (node->children != nullptr)
    {
        for (auto *child : node->children)
        {
            if (checkVoidFunctionCall(child))
                return true;
        }
    }

    return false;
}

*/

/*=====================================================================================
    RULE: start
    start : program
=======================================================================================*/

any CSubsetImp::visitStart_rule(CSubsetParser::Start_ruleContext *ctx)
{
     visit(ctx->program());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": start : program" << endl
          << endl;
     table.printAllScopes(file);
     file << endl
          << endl
          << endl;
     return nullptr;
}

/*=====================================================================================
    RULE: program
    program : program unit
            | unit
=======================================================================================*/

// ---- program : program unit  (#program_to_program_unit) ----
std::any CSubsetImp::visitProgram_to_program_unit(
    CSubsetParser::Program_to_program_unitContext *ctx)
{

     visit(ctx->program());

     visit(ctx->unit());

     int line_number = ctx->unit()->getStart()->getLine();

     file << "Line " << line_number
          << ": program : program unit"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl
          << endl;

     return nullptr;
}

// ---- program : unit  (#program_to_unit) ----
any CSubsetImp::visitProgram_to_unit(CSubsetParser::Program_to_unitContext *ctx)
{
     visit(ctx->unit());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": program : unit" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl
          << endl;
     return nullptr;
}

/*=====================================================================================
    RULE: unit
    unit : var_declaration
         | func_declaration
         | func_definition
=======================================================================================*/

// ---- unit : var_declaration  (#unit_to_var_declaration) ----
any CSubsetImp::visitUnit_to_var_declaration(
    CSubsetParser::Unit_to_var_declarationContext *ctx)
{
     visit(ctx->var_declaration());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": unit : var_declaration"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl
          << endl;

     return nullptr;
}

// ---- unit : func_declaration  (#unit_to_func_declaration) ----
any CSubsetImp::visitUnit_to_func_declaration(CSubsetParser::Unit_to_func_declarationContext *ctx)
{
     visit(ctx->func_declaration());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": unit : func_declaration" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl
          << endl;
     return nullptr;
}

// ---- unit : func_definition  (#unit_to_func_definition) ----
any CSubsetImp::visitUnit_to_func_definition(CSubsetParser::Unit_to_func_definitionContext *ctx)
{
     visit(ctx->func_definition());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": unit : func_definition" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

/*=====================================================================================
    RULE: func_declaration
    func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
                      | type_specifier ID LPAREN RPAREN SEMICOLON
=======================================================================================*/

// ---- func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  (#func_declaration_with_param) ----
any CSubsetImp::visitFunc_declaration_with_param(CSubsetParser::Func_declaration_with_paramContext *ctx)
{
     int bucketIndex, position;
     string scopeID;
     SymbolInfo *symbol = table.lookup(ctx->ID()->getText(), bucketIndex, position, scopeID);

     string newParams = ctx->parameter_list()->getText();

     if (symbol && symbol->type == "FUNC")
     {
          FunctionInfo *funcInfo = symbol->funcInfo;
          string existingParams = funcInfo->parameters;
          if (existingParams != newParams)
          {
               SymbolInfo *newSymbol = new SymbolInfo(ctx->ID()->getText(), "FUNC");
               newSymbol->funcInfo = new FunctionInfo(ctx->type_specifier()->getText(), newParams);
               newSymbol->funcInfo->isDeclared = true;
               newSymbol->funcInfo->returnType = ctx->type_specifier()->getText();
               insertSymbol(newSymbol, ctx);
          }
          else if (funcInfo->returnType != ctx->type_specifier()->getText())
          {
               file << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                    << endl;
               err << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                   << endl;
          }
          else
          {
               file << "Error at line " << ctx->getStart()->getLine() << ": Multiple declaration of function " << ctx->ID()->getText() << endl
                    << endl;
               err << "Error at line " << ctx->getStart()->getLine() << ": Multiple declaration of function " << ctx->ID()->getText() << endl
                   << endl;
          }
     }
     else
     {
          SymbolInfo *symbol = new SymbolInfo(ctx->ID()->getText(), "FUNC");
          symbol->funcInfo = new FunctionInfo(ctx->type_specifier()->getText(), newParams);
          symbol->funcInfo->isDeclared = true;
          symbol->funcInfo->returnType = ctx->type_specifier()->getText();
          insertSymbol(symbol, ctx);
     }

     table.enterScope();
     visit(ctx->type_specifier());
     visit(ctx->parameter_list());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     table.exitScope();

     return nullptr;
}

// ---- func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON  (#func_declaration_without_param) ----
any CSubsetImp::visitFunc_declaration_without_param(CSubsetParser::Func_declaration_without_paramContext *ctx)
{

     int bucketIndex, position;
     string scopeID;
     SymbolInfo *symbol = table.lookup(ctx->ID()->getText(), bucketIndex, position, scopeID);

     if (symbol && symbol->type == "FUNC")
     {
          FunctionInfo *funcInfo = symbol->funcInfo;
          string existingParams = funcInfo->parameters;
          if (funcInfo->returnType != ctx->type_specifier()->getText())
          {
               file << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                    << endl;
               err << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                   << endl;
          }
          else
          {
               file << "Error at line " << ctx->getStart()->getLine() << ": Multiple declaration of function " << ctx->ID()->getText() << endl
                    << endl;
               err << "Error at line " << ctx->getStart()->getLine() << ": Multiple declaration of function " << ctx->ID()->getText() << endl
                   << endl;
          }
     }
     else
     {
          SymbolInfo *symbol = new SymbolInfo(ctx->ID()->getText(), "FUNC");
          symbol->funcInfo = new FunctionInfo(ctx->type_specifier()->getText(), "");
          symbol->funcInfo->isDeclared = true;
          symbol->funcInfo->returnType = ctx->type_specifier()->getText();
          insertSymbol(symbol, ctx);
     }

     visit(ctx->type_specifier());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON" << endl
          << endl;
     file << ctx->type_specifier()->getText() << " " << ctx->ID()->getText() << "();" << endl
          << endl
          << endl;
     table.enterScope();
     table.exitScope();
     return nullptr;
}

/*=====================================================================================
    RULE: func_definition
    func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
                    | type_specifier ID LPAREN RPAREN compound_statement
=======================================================================================*/

// ---- func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement  (#func_def_with_param) ----
any CSubsetImp::visitFunc_def_with_param(CSubsetParser::Func_def_with_paramContext *ctx)
{

     int bucketIndex, position;
     string scopeID;
     SymbolInfo *symbol = table.lookup(ctx->ID()->getText(), bucketIndex, position, scopeID);

     string newParams = ctx->parameter_list()->getText();
     int new_param_count = count(newParams.begin(), newParams.end(), ',') + 1;

     if (symbol && symbol->type == "FUNC")
     {
          FunctionInfo *funcInfo = symbol->funcInfo;
          string existingParams = funcInfo->parameters;
          int existing_param_count = count(existingParams.begin(), existingParams.end(), ',') + 1;

          if (funcInfo->isDeclared)
          {
               if (funcInfo->isDefined == false)
               {
                    if (existingParams != newParams)
                    {
                         if (existing_param_count != new_param_count)
                         {
                              file << "Error at line " << ctx->getStart()->getLine() << ": Total number of arguments mismatch with declaration in function " << ctx->ID()->getText() << endl
                                   << endl;
                              err << "Error at line " << ctx->getStart()->getLine() << ": Total number of arguments mismatch with declaration in function " << ctx->ID()->getText() << endl
                                  << endl;
                         }
                         else
                         {
                              file << "Error at line " << ctx->getStart()->getLine() << ": Parameter type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                                   << endl;
                              err << "Error at line " << ctx->getStart()->getLine() << ": Parameter type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                                  << endl;
                         }
                    }
                    else if (funcInfo->returnType != ctx->type_specifier()->getText())
                    {
                         file << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                              << endl;
                         err << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                             << endl;
                    }
                    else
                    {
                         funcInfo->isDefined = true;
                    }
               }
               else
               {
                    if (existingParams != newParams)
                    {

                         if (existing_param_count != new_param_count)
                         {
                              file << "Error at line " << ctx->getStart()->getLine() << ": Total number of arguments mismatch with declaration in function " << ctx->ID()->getText() << endl
                                   << endl;
                              err << "Error at line " << ctx->getStart()->getLine() << ": Total number of arguments mismatch with declaration in function " << ctx->ID()->getText() << endl
                                  << endl;
                         }
                         else
                         {
                              file << "Error at line " << ctx->getStart()->getLine() << ": Parameter type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                                   << endl;
                              err << "Error at line " << ctx->getStart()->getLine() << ": Parameter type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                                  << endl;
                         }
                    }
                    else if (funcInfo->returnType != ctx->type_specifier()->getText())
                    {
                         file << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                              << endl;
                         err << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                             << endl;
                    }
                    else
                    {
                         file << "Error at line " << ctx->getStart()->getLine() << ": Multiple definition of function " << ctx->ID()->getText() << endl
                              << endl;
                         err << "Error at line " << ctx->getStart()->getLine() << ": Multiple definition of function " << ctx->ID()->getText() << endl
                             << endl;
                    }
               }
          }
          else
          {
               SymbolInfo *newSymbol = new SymbolInfo(ctx->ID()->getText(), "FUNC");
               newSymbol->funcInfo = new FunctionInfo(ctx->type_specifier()->getText(), newParams);
               newSymbol->funcInfo->isDeclared = true;
               newSymbol->funcInfo->isDefined = true;
               newSymbol->funcInfo->returnType = ctx->type_specifier()->getText();
               insertSymbol(newSymbol, ctx);
          }
     }
     else
     {
          SymbolInfo *symbol = new SymbolInfo(ctx->ID()->getText(), "FUNC");
          symbol->funcInfo = new FunctionInfo(ctx->type_specifier()->getText(), newParams);
          symbol->funcInfo->isDeclared = true;
          symbol->funcInfo->isDefined = true;
          symbol->funcInfo->returnType = ctx->type_specifier()->getText();
          insertSymbol(symbol, ctx);
     }

     // Parameters belong to the function scope, while the function symbol above
     // must remain in the enclosing (global) scope.
     table.enterScope();
     visit(ctx->type_specifier());
     visit(ctx->ID());
     visit(ctx->parameter_list());

     auto *previousFunctionBody = functionBodyContext;
     functionBodyContext = ctx->compound_statement();
     visit(ctx->compound_statement());
     functionBodyContext = previousFunctionBody;

     table.printCurrentScope(file);
     table.exitScope();
     table.printCurrentScope(file);

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number << ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl
          << endl;

     return nullptr;
}

// ---- func_definition : type_specifier ID LPAREN RPAREN compound_statement  (#func_def_without_param) ----
any CSubsetImp::visitFunc_def_without_param(CSubsetParser::Func_def_without_paramContext *ctx)
{

     int bucketIndex, position;
     string scopeID;
     SymbolInfo *symbol = table.lookup(ctx->ID()->getText(), bucketIndex, position, scopeID);

     if (symbol && symbol->type == "FUNC")
     {
          FunctionInfo *funcInfo = symbol->funcInfo;
          string existingParams = funcInfo->parameters;

          if (funcInfo->isDeclared)
          {
               if (funcInfo->isDefined == false)
               {
                    if (funcInfo->returnType != ctx->type_specifier()->getText())
                    {
                         file << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                              << endl;
                         err << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                             << endl;
                    }
                    else
                    {
                         funcInfo->isDefined = true;
                    }
               }
               else
               {
                    if (funcInfo->returnType != ctx->type_specifier()->getText())
                    {
                         file << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                              << endl;
                         err << "Error at line " << ctx->getStart()->getLine() << ": Return type mismatch with function declaration in function " << ctx->ID()->getText() << endl
                             << endl;
                    }
                    else
                    {
                         file << "Error at line " << ctx->getStart()->getLine() << ": Multiple definition of function " << ctx->ID()->getText() << endl
                              << endl;
                         err << "Error at line " << ctx->getStart()->getLine() << ": Multiple definition of function " << ctx->ID()->getText() << endl
                             << endl;
                    }
               }
          }
          else
          {
               SymbolInfo *newSymbol = new SymbolInfo(ctx->ID()->getText(), "FUNC");
               newSymbol->funcInfo = new FunctionInfo(ctx->type_specifier()->getText(), "");
               newSymbol->funcInfo->isDeclared = true;
               newSymbol->funcInfo->isDefined = true;
               insertSymbol(newSymbol, ctx);
          }
     }
     else
     {
          SymbolInfo *symbol = new SymbolInfo(ctx->ID()->getText(), "FUNC");
          symbol->funcInfo = new FunctionInfo(ctx->type_specifier()->getText(), "");
          symbol->funcInfo->isDeclared = true;
          symbol->funcInfo->isDefined = true;
          symbol->funcInfo->returnType = ctx->type_specifier()->getText();
          insertSymbol(symbol, ctx);
     }

     table.enterScope();

     visit(ctx->type_specifier());
     auto *previousFunctionBody = functionBodyContext;
     functionBodyContext = ctx->compound_statement();
     visit(ctx->compound_statement());
     functionBodyContext = previousFunctionBody;
     int line_number = ctx->getStart()->getLine();

     table.printCurrentScope(file);
     table.exitScope();
     table.printCurrentScope(file);

     file << "Line " << line_number << ": func_definition : type_specifier ID LPAREN RPAREN compound_statement" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;

     return nullptr;
}

/*=====================================================================================
    RULE: parameter_list
    parameter_list : parameter_list COMMA type_specifier ID
                    | parameter_list COMMA type_specifier
                    | type_specifier ID
                    | type_specifier
=======================================================================================*/

// ---- parameter_list : parameter_list COMMA type_specifier ID  (#multiple_param_with_id) ----
any CSubsetImp::visitMultiple_param_with_id(CSubsetParser::Multiple_param_with_idContext *ctx)
{
     // cout << "hello" << endl;
     visit(ctx->parameter_list());
     // cout << ctx->type_specifier()->getText() << endl;
     visit(ctx->type_specifier());
     visit(ctx->ID());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number << ": parameter_list : parameter_list COMMA type_specifier ID" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;

     SymbolInfo *symbol = new SymbolInfo(ctx->ID()->getText(), ctx->type_specifier()->getText());
     insertParameterSymbol(symbol, ctx);
     return nullptr;
}

// ---- parameter_list : parameter_list COMMA type_specifier  (#multiple_param_without_id) ----
any CSubsetImp::visitMultiple_param_without_id(CSubsetParser::Multiple_param_without_idContext *ctx)
{
     return visitChildren(ctx);
}

// ---- parameter_list : type_specifier ID  (#single_param_with_id) ----
any CSubsetImp::visitSingle_param_with_id(CSubsetParser::Single_param_with_idContext *ctx)
{
     visit(ctx->type_specifier());
     visit(ctx->ID());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number << ": parameter_list : type_specifier ID" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;

     SymbolInfo *symbol = new SymbolInfo(ctx->ID()->getText(), ctx->type_specifier()->getText());
     insertParameterSymbol(symbol, ctx);
     return nullptr;
}

// ---- parameter_list : type_specifier  (#single_param_without_id) ----
any CSubsetImp::visitSingle_param_without_id(CSubsetParser::Single_param_without_idContext *ctx)
{
     visit(ctx->type_specifier());
     int line = ctx->getStart()->getLine();
     file << "Line " << line << ": parameter_list : type_specifier" << endl << endl;
     file << getRawText(ctx) << endl << endl;
     if (hasUnnamedParameter(line)) {
          auto *function = dynamic_cast<CSubsetParser::Func_def_with_paramContext *>(ctx->parent);
          string functionName = function ? function->ID()->getText() : "<unknown>";
          writeSyntaxError(line, "unexpected token(s) '-' before ')'");
          file << "Error at line " << line << ": 1th parameter's name not given in function definition of "
               << functionName << endl << endl;
          err << "Error at line " << line << ": 1th parameter's name not given in function definition of "
              << functionName << endl << endl;
     }
     return nullptr;
}

/*=====================================================================================
    RULE: compound_statement
    compound_statement : LCURL statements RCURL
                        | LCURL RCURL
=======================================================================================*/

// ---- compound_statement : LCURL statements RCURL  (#compound_with_statement) ----
any CSubsetImp::visitCompound_with_statement(CSubsetParser::Compound_with_statementContext *ctx)
{
     const bool createsScope = ctx != functionBodyContext;
     if (createsScope)
          table.enterScope();

     visit(ctx->statements());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number
          << ": compound_statement : LCURL statements RCURL"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     if (createsScope)
     {
          table.printCurrentScope(file);
          file << endl << endl;
          table.exitScope();
          table.printAllScopes(file);
          file << endl << endl;
     }

     return nullptr;
}

// ---- compound_statement : LCURL RCURL  (#compound_without_statement) ----
any CSubsetImp::visitCompound_without_statement(CSubsetParser::Compound_without_statementContext *ctx)
{
     const bool createsScope = ctx != functionBodyContext;
     if (createsScope)
          table.enterScope();

     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": compound_statement : LCURL RCURL" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;

     if (createsScope)
     {
          table.printCurrentScope(file);
          file << endl << endl;
          table.exitScope();
          table.printAllScopes(file);
          file << endl << endl;
     }

     return nullptr;
}

/*=====================================================================================
    RULE: var_declaration
    var_declaration : type_specifier declaration_list SEMICOLON
=======================================================================================*/

any CSubsetImp::visitVar_declaration(CSubsetParser::Var_declarationContext *ctx)
{
     // Line 1: var_declaration : type_specifier declaration_list SEMICOLON
     currentType = ctx->type_specifier()->getText();
     visit(ctx->type_specifier());
     visit(ctx->declaration_list());

     string type_specifier = ctx->type_specifier()->getText();
     if (type_specifier == "void")
     {
          file << "Error at line " << ctx->getStart()->getLine() << ": Variable type cannot be void" << endl
               << endl;
          err << "Error at line " << ctx->getStart()->getLine() << ": Variable type cannot be void" << endl
              << endl;
     }
     // cout << currentType << endl;
     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number << ": var_declaration : type_specifier declaration_list SEMICOLON" << endl
          << endl;

     file << ctx->type_specifier()->getText() << " " << ctx->declaration_list()->getText() << ";" << endl
          << endl;

     return nullptr;
}

/*=====================================================================================
    RULE: type_specifier
    type_specifier : INT
                    | FLOAT
                    | VOID
=======================================================================================*/

// ---- type_specifier : INT  (#IntType) ----
any CSubsetImp::visitIntType(
    CSubsetParser::IntTypeContext *ctx)
{
     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": type_specifier : INT\n\n";

     file << getRawText(ctx) << endl
          << endl;

     return nullptr;
}

// ---- type_specifier : FLOAT  (#FloatType) ----
any CSubsetImp::visitFloatType(
    CSubsetParser::FloatTypeContext *ctx)
{
     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": type_specifier : FLOAT\n\n";

     file << getRawText(ctx) << endl
          << endl;
     ;

     return nullptr;
}

// ---- type_specifier : VOID  (#VoidType) ----
any CSubsetImp::visitVoidType(
    CSubsetParser::VoidTypeContext *ctx)
{
     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": type_specifier : VOID\n\n";

     file << getRawText(ctx) << endl
          << endl;

     return nullptr;
}

/*=====================================================================================
    RULE: declaration_list
    declaration_list : declaration_list COMMA ID
                      | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
                      | ID
                      | ID LTHIRD CONST_INT RTHIRD
=======================================================================================*/

// ---- declaration_list : declaration_list COMMA ID  (#MultiVarDecl) ----
any CSubsetImp::visitMultiVarDecl(CSubsetParser::MultiVarDeclContext *ctx)
{
     int bucketIndex, position;
     visit(ctx->declaration_list());
     int line_number = ctx->getStart()->getLine();
     if (takeBadDeclaration(line_number))
          writeSyntaxError(line_number, "unexpected token(s) '- y' in declaration list");
     file << "Line " << line_number << ": declaration_list : declaration_list COMMA ID" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;

     SymbolInfo *symbol = new SymbolInfo(ctx->ID()->getText(), currentType);
     insertSymbol(symbol, ctx);
     return nullptr;
}

// ---- declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  (#MultiVarDeclWithArr) ----
any CSubsetImp::visitMultiVarDeclWithArr(CSubsetParser::MultiVarDeclWithArrContext *ctx)
{
     visit(ctx->declaration_list());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;

     // cout << ctx->ID()->getText()<<endl;
     SymbolInfo *symbol = new SymbolInfo(ctx->ID()->getText(), "ARRAY");
     symbol->arr_type = currentType;
     insertSymbol(symbol, ctx);
     return nullptr;
}

// ---- declaration_list : ID  (#SiglVarDecl) ----
any CSubsetImp::visitSiglVarDecl(CSubsetParser::SiglVarDeclContext *ctx)
{
     int line_number = ctx->getStart()->getLine();
     int bucketIndex, position;
     file << "Line " << line_number << ": declaration_list : ID" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;

     // //cout << currentType << endl;
     SymbolInfo *symbol = new SymbolInfo(ctx->ID()->getText(), currentType);
     insertSymbol(symbol, ctx);
     return nullptr;
}

// ---- declaration_list : ID LTHIRD CONST_INT RTHIRD  (#SiglArrDecl) ----
any CSubsetImp::visitSiglArrDecl(CSubsetParser::SiglArrDeclContext *ctx)
{
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": declaration_list : ID LTHIRD CONST_INT RTHIRD" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;

     // cout << ctx->ID()->getText()<<endl;
     SymbolInfo *symbol = new SymbolInfo(ctx->ID()->getText(), "ARRAY");
     symbol->arr_type = currentType;
     insertSymbol(symbol, ctx);
     return nullptr;
}

/*=====================================================================================
    RULE: statements
    statements : statement
               | statements statement
=======================================================================================*/

// ---- statements : statement  (#single_statement) ----
any CSubsetImp::visitSingle_statement(
    CSubsetParser::Single_statementContext *ctx)
{
     any name = visit(ctx->statement());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": statements : statement"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return name;
}

// ---- statements : statements statement  (#multiple_statement) ----
any CSubsetImp::visitMultiple_statement(CSubsetParser::Multiple_statementContext *ctx)
{
     visit(ctx->statements());
     any name = visit(ctx->statement());
     int line_number = ctx->statement()->getStart()->getLine();
     file << "Line " << line_number << ": statements : statements statement" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return name;
}

/*=====================================================================================
    RULE: statement
    statement : var_declaration
              | expression_statement
              | compound_statement
              | FOR LPAREN expression_statement expression_statement expression RPAREN statement
              | IF LPAREN expression RPAREN statement
              | IF LPAREN expression RPAREN statement ELSE statement
              | WHILE LPAREN expression RPAREN statement
              | PRINTLN LPAREN ID RPAREN SEMICOLON
              | RETURN expression SEMICOLON
=======================================================================================*/

// ---- statement : var_declaration  (#var_declaration_statement) ----
any CSubsetImp::visitVar_declaration_statement(CSubsetParser::Var_declaration_statementContext *ctx)
{
     visit(ctx->var_declaration());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": statement : var_declaration" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- statement : expression_statement  (#expression_statement_statement) ----
any CSubsetImp::visitExpression_statement_statement(CSubsetParser::Expression_statement_statementContext *ctx)
{
     any name = visit(ctx->expression_statement());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": statement : expression_statement" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return name;
}

// ---- statement : compound_statement  (#compound_statement_statement) ----
any CSubsetImp::visitCompound_statement_statement(CSubsetParser::Compound_statement_statementContext *ctx)
{
     visit(ctx->compound_statement());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": statement : compound_statement" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement  (#for_statement) ----
any CSubsetImp::visitFor_statement(CSubsetParser::For_statementContext *ctx)
{
     visit(ctx->expression_statement(0));
     visit(ctx->expression_statement(1));
     visit(ctx->expression());
     visit(ctx->statement());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- statement : IF LPAREN expression RPAREN statement  (#if_statement) ----
any CSubsetImp::visitIf_statement(CSubsetParser::If_statementContext *ctx)
{
     visit(ctx->expression());
     visit(ctx->statement());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": statement : IF LPAREN expression RPAREN statement" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- statement : IF LPAREN expression RPAREN statement ELSE statement  (#if_else_statement) ----
any CSubsetImp::visitIf_else_statement(CSubsetParser::If_else_statementContext *ctx)
{
     visit(ctx->expression());
     visit(ctx->statement(0));
     visit(ctx->statement(1));
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": statement : IF LPAREN expression RPAREN statement ELSE statement" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- statement : WHILE LPAREN expression RPAREN statement  (#while_statement) ----
any CSubsetImp::visitWhile_statement(CSubsetParser::While_statementContext *ctx)
{
     visit(ctx->expression());
     visit(ctx->statement());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": statement : WHILE LPAREN expression RPAREN statement" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- statement : PRINTLN LPAREN ID RPAREN SEMICOLON  (#println_statement) ----
any CSubsetImp::visitPrintln_statement(CSubsetParser::Println_statementContext *ctx)
{
     int line_number = ctx->getStart()->getLine();
     string id = ctx->ID()->getText();
     int b, p;
     string scopeId;
     SymbolInfo *symbol = table.lookup(id, b, p, scopeId);
     if (symbol == nullptr)
     {
          file << "Error at line " << line_number << ": Undeclared variable " << id << endl
               << endl;
          err << "Error at line " << line_number << ": Undeclared variable " << id << endl
               << endl;
     }

     file << "Line " << line_number << ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- statement : RETURN expression SEMICOLON  (#return_statement) ----
any CSubsetImp::visitReturn_statement(
    CSubsetParser::Return_statementContext *ctx)
{
     // Visit expression FIRST
     // so expression's children are printed before RETURN
     visit(ctx->expression());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": statement : RETURN expression SEMICOLON"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return nullptr;
}

/*=====================================================================================
    RULE: expression_statement
    expression_statement : SEMICOLON
                          | expression SEMICOLON
=======================================================================================*/

// ---- expression_statement : SEMICOLON  (#expression_statement_to_semicolon) ----
any CSubsetImp::visitExpression_statement_to_semicolon(CSubsetParser::Expression_statement_to_semicolonContext *ctx)
{
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": expression_statement : SEMICOLON" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- expression_statement : expression SEMICOLON  (#expression_statement_to_expression_semicolon) ----
any CSubsetImp::visitExpression_statement_to_expression_semicolon(CSubsetParser::Expression_statement_to_expression_semicolonContext *ctx)
{
     any name = visit(ctx->expression());
     int line_number = ctx->getStart()->getLine();
     if (takeMissingSemicolon(line_number, ctx->expression()->getText())) {
          file << "Error at line " << line_number << ": syntax error, missing ';' after expression '"
               << ctx->expression()->getText() << "'" << endl << endl;
          err << "Error at line " << line_number << ": syntax error, missing ';' after expression '"
              << ctx->expression()->getText() << "'" << endl << endl;
          file << "Line " << line_number << ": expression_statement : expression (missing SEMICOLON)" << endl << endl;
          file << ctx->expression()->getText() << endl << endl;
          return name;
     }
     file << "Line " << line_number << ": expression_statement : expression SEMICOLON" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return name;
}

/*=====================================================================================
    RULE: variable
    variable : ID
             | ID LTHIRD expression RTHIRD
=======================================================================================*/

// ---- variable : ID  (#SimpleVar) ----
any CSubsetImp::visitSimpleVar(
    CSubsetParser::SimpleVarContext *ctx)
{
     int line_number = ctx->getStart()->getLine();

     string symbol_name = ctx->ID()->getText();
     int bucketIndex, position;
     string scopeId;

     SymbolInfo *symbol = table.lookup(symbol_name, bucketIndex, position, scopeId);

     if (symbol && symbol->type == "ARRAY")
     {
          file << "Error at line " << line_number << ": Type mismatch, " << symbol_name << " is an array" << endl
               << endl;
          err << "Error at line " << line_number << ": Type mismatch, " << symbol_name << " is an array" << endl
              << endl;
     }

     file << "Line " << line_number << ": variable : ID"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return ctx->ID()->getText();
}

// ---- variable : ID LTHIRD expression RTHIRD  (#ArrVar) ----
any CSubsetImp::visitArrVar(
    CSubsetParser::ArrVarContext *ctx)
{
     any name = visit(ctx->expression());
     int line_number = ctx->getStart()->getLine();

     // check if ID is an array
     string symbol_name = ctx->ID()->getText();
     int bucketIndex, position;
     string scopeId;
     SymbolInfo *symbol = table.lookup(symbol_name, bucketIndex, position, scopeId);
     if (symbol && symbol->type != "ARRAY")
     {
          file << "Error at line " << line_number << ": " << symbol_name << " not an array" << endl
               << endl;
          err << "Error at line " << line_number << ": " << symbol_name << " not an array" << endl
              << endl;
     }

     if (name.has_value() && isValidFloat(any_cast<string>(name)) == 1)
     {
          file << "Error at line " << line_number << ": Expression inside third brackets not an integer" << endl
               << endl;
          err << "Error at line " << line_number << ": Expression inside third brackets not an integer" << endl
              << endl;
     }

     file << "Line " << line_number << ": variable : ID LTHIRD expression RTHIRD"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return ctx->ID()->getText();
}

/*=====================================================================================
    RULE: expression
    expression : logic_expression
               | variable ASSIGNOP logic_expression
=======================================================================================*/

// ---- expression : logic_expression  (#expression_to_logic_expression) ----
any CSubsetImp::visitExpression_to_logic_expression(
    CSubsetParser::Expression_to_logic_expressionContext *ctx)
{
     any name = visit(ctx->logic_expression());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": expression : logic expression"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return name;
}

// ---- expression : variable ASSIGNOP logic_expression  (#expression_to_logic_expression_with_assignop) ----
any CSubsetImp::visitExpression_to_logic_expression_with_assignop(CSubsetParser::Expression_to_logic_expression_with_assignopContext *ctx)
{
     visit(ctx->variable());
     visit(ctx->logic_expression());

     string var_name = ctx->variable()->getText();
     string var_value = ctx->logic_expression()->getText();

     // //cout<<"var_value: "<<var_value<<endl;

     int line_number = ctx->getStart()->getLine();

     string result = any_cast<string>(var_name);
     string symbol_name = result.substr(0, result.find('['));
     int bucketIndex, position;
     string scopeId;

     SymbolInfo *symbol = table.lookup(symbol_name, bucketIndex, position, scopeId);

     size_t openParen = var_value.find('(');
     if (openParen != string::npos) {
          string functionName = var_value.substr(0, openParen);
          SymbolInfo *function = table.lookup(functionName, bucketIndex, position, scopeId);
          if (function && function->type == "FUNC" && function->funcInfo->returnType == "void") {
               file << "Error at line " << line_number << ": Void function used in expression" << endl << endl;
               err << "Error at line " << line_number << ": Void function used in expression" << endl << endl;
          }
     }

     // error checking for type mismatch
     if (symbol && (symbol->type == "int" || symbol->arr_type == "int") && isValidFloat(var_value))
     {
          file << "Error at line " << line_number << ": Type Mismatch" << endl
               << endl;
          err << "Error at line " << line_number << ": Type Mismatch" << endl
              << endl;
     }

     if (!symbol)
     {
          file << "Error at line " << line_number << ": Undeclared variable " << var_name << endl
               << endl;
          err << "Error at line " << line_number << ": Undeclared variable " << var_name << endl
              << endl;
     }

     file << "Line " << line_number << ": expression : variable ASSIGNOP logic_expression" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

/*=====================================================================================
    RULE: logic_expression
    logic_expression : rel_expression
                      | rel_expression LOGICOP rel_expression
=======================================================================================*/

// ---- logic_expression : rel_expression  (#logic_to_rel_expression_simple) ----
any CSubsetImp::visitLogic_to_rel_expression_simple(
    CSubsetParser::Logic_to_rel_expression_simpleContext *ctx)
{
     any name = visit(ctx->rel_expression());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": logic_expression : rel_expression"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return name;
}

// ---- logic_expression : rel_expression LOGICOP rel_expression  (#logic_to_rel_expression_complex) ----
any CSubsetImp::visitLogic_to_rel_expression_complex(
    CSubsetParser::Logic_to_rel_expression_complexContext *ctx)
{
     visit(ctx->rel_expression(0));
     visit(ctx->rel_expression(1));
     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": logic_expression : rel_expression LOGICOP rel_expression"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return nullptr;
}

/*=====================================================================================
    RULE: rel_expression
    rel_expression : simple_expression
                    | simple_expression RELOP simple_expression
=======================================================================================*/

// ---- rel_expression : simple_expression  (#rel_expression_simple_expresssion_simple) ----
any CSubsetImp::visitRel_expression_simple_expresssion_simple(
    CSubsetParser::Rel_expression_simple_expresssion_simpleContext *ctx)
{
     any name = visit(ctx->simple_expression());

     int line_number = ctx->getStart()->getLine();

     if (takeBadAddAssign(line_number))
          writeSyntaxError(line_number, "invalid operand '=' after '+'");

     file << "Line " << line_number
          << ": rel_expression : simple_expression"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return name;
}

// ---- rel_expression : simple_expression RELOP simple_expression  (#rel_expression_simple_expresssion_complex) ----
any CSubsetImp::visitRel_expression_simple_expresssion_complex(CSubsetParser::Rel_expression_simple_expresssion_complexContext *ctx)
{
     visit(ctx->simple_expression(0));
     visit(ctx->simple_expression(1));
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": rel_expression : simple_expression RELOP simple_expression" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

/*=====================================================================================
    RULE: simple_expression
    simple_expression : term
                       | simple_expression ADDOP term
=======================================================================================*/

// ---- simple_expression : term  (#simple_expression_to_term) ----
any CSubsetImp::visitSimple_expression_to_term(
    CSubsetParser::Simple_expression_to_termContext *ctx)
{
     any name = visit(ctx->term());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": simple_expression : term"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return name;
}

// ---- simple_expression : simple_expression ADDOP term  (#simple_expression_to_term_with_plus) ----
any CSubsetImp::visitSimple_expression_to_term_with_plus(
    CSubsetParser::Simple_expression_to_term_with_plusContext *ctx)
{
     // simple_expression ADDOP term

     visit(ctx->simple_expression());
     visit(ctx->term());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": simple_expression : simple_expression ADDOP term"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return nullptr;
}

/*=====================================================================================
    RULE: term
    term : unary_expression
         | term MULOP unary_expression
=======================================================================================*/

// ---- term : unary_expression  (#term_unary_expression) ----
any CSubsetImp::visitTerm_unary_expression(
    CSubsetParser::Term_unary_expressionContext *ctx)
{
     any name = visit(ctx->unary_expression());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": term : unary_expression"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return name;
}

// ---- term : term MULOP unary_expression  (#term_times_unary_expression) ----
/*
any CSubsetImp::visitTerm_times_unary_expression(CSubsetParser::Term_times_unary_expressionContext *ctx)
{
     visit(ctx->term());
     visit(ctx->unary_expression());

     //check if there is any function call structure in unary expression and if present
     //check if its return type is void and write an error message
     //unary expression contains factor and factor can contain function call

     // error checking for modulus operator
     // if it is modulus operator, then both operands must be integers
     if (ctx->MULOP()->getText() == "%")
     {
          string left_operand = ctx->term()->getText();
          string right_operand = ctx->unary_expression()->getText();

          int bucketIndex, position;
          string scopeId;

          SymbolInfo *left_symbol = table.lookup(left_operand, bucketIndex, position, scopeId);
          SymbolInfo *right_symbol = table.lookup(right_operand, bucketIndex, position, scopeId);

          if ((left_symbol && left_symbol->type != "int") || (right_symbol && right_symbol->type != "int") ||
              isValidFloat(left_operand) || isValidFloat(right_operand))
          {
               int line_number = ctx->getStart()->getLine();
               file << "Error at line " << line_number << ": Non-Integer operand on modulus operator" << endl
                    << endl;
               err << "Error at line " << line_number << ": Non-Integer operand on modulus operator" << endl
                   << endl;
          }
     }

     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": term : term MULOP unary_expression" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

*/

// ---- term : term MULOP unary_expression (#term_times_unary_expression) ----
any CSubsetImp::visitTerm_times_unary_expression(
    CSubsetParser::Term_times_unary_expressionContext *ctx)
{
     visit(ctx->term());
     visit(ctx->unary_expression());

     int line_number = ctx->getStart()->getLine();

     auto *unary = ctx->unary_expression();

     if (unary != nullptr)
     {
          auto factors =
              unary->getRuleContexts<CSubsetParser::FactorContext>();

          for (auto *factor : factors)
          {
               if (factor == nullptr)
                    continue;

               auto *function_call =
                   dynamic_cast<CSubsetParser::Factor_function_callContext *>(
                       factor);

               if (function_call != nullptr)
               {
                    string function_name =
                        function_call->ID()->getText();

                    int bucketIndex, position;
                    string scopeId;

                    SymbolInfo *function_symbol =
                        table.lookup(
                            function_name,
                            bucketIndex,
                            position,
                            scopeId);

                    if (function_symbol != nullptr &&
                        function_symbol->funcInfo->returnType == "void")
                    {
                         file << "Error at line "
                              << line_number
                              << ": Void function used in expression"
                              << endl
                              << endl;

                         err << "Error at line "
                             << line_number
                             << ": Void function used in expression"
                             << endl
                             << endl;
                    }
               }
          }
     }

     if (ctx->MULOP()->getText() == "%")
     {
          string left_operand = ctx->term()->getText();
          string right_operand = ctx->unary_expression()->getText();

          if (right_operand == "0")
          {
               file << "Error at line " << line_number << ": Modulus by Zero" << endl
                    << endl;
               err << "Error at line " << line_number << ": Modulus by Zero" << endl
                   << endl;
          }

          int bucketIndex, position;
          string scopeId;

          SymbolInfo *left_symbol = table.lookup(left_operand, bucketIndex, position, scopeId);
          SymbolInfo *right_symbol = table.lookup(right_operand, bucketIndex, position, scopeId);

          if ((left_symbol && left_symbol->type != "int") || (right_symbol && right_symbol->type != "int") ||
              isValidFloat(left_operand) || isValidFloat(right_operand))
          {
               int line_number = ctx->getStart()->getLine();
               file << "Error at line " << line_number << ": Non-Integer operand on modulus operator" << endl
                    << endl;
               err << "Error at line " << line_number << ": Non-Integer operand on modulus operator" << endl
                   << endl;
          }
     }

     file << "Line "
          << line_number
          << ": term : term MULOP unary_expression"
          << endl
          << endl;

     file << getRawText(ctx)
          << endl
          << endl;

     return nullptr;
}

/*=====================================================================================
    RULE: unary_expression
    unary_expression : ADDOP unary_expression
                      | NOT unary_expression
                      | factor
=======================================================================================*/

// ---- unary_expression : ADDOP unary_expression  (#unary_expression_addop) ----
any CSubsetImp::visitUnary_expression_addop(CSubsetParser::Unary_expression_addopContext *ctx)
{
     visit(ctx->unary_expression());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": unary_expression : ADDOP unary_expression" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- unary_expression : NOT unary_expression  (#unary_expression_not) ----
any CSubsetImp::visitUnary_expression_not(CSubsetParser::Unary_expression_notContext *ctx)
{
     visit(ctx->unary_expression());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": unary_expression : NOT unary_expression" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- unary_expression : factor  (#unary_expression_to_factor) ----
any CSubsetImp::visitUnary_expression_to_factor(
    CSubsetParser::Unary_expression_to_factorContext *ctx)
{
     any name = visit(ctx->factor());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": unary_expression : factor"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return name;
}

/*=====================================================================================
    RULE: factor
    factor : variable
           | ID LPAREN argument_list RPAREN
           | LPAREN expression RPAREN
           | CONST_INT
           | CONST_FLOAT
           | variable INCOP
           | variable DECOP
=======================================================================================*/

// ---- factor : variable  (#factor_to_variable) ----
any CSubsetImp::visitFactor_to_variable(
    CSubsetParser::Factor_to_variableContext *ctx)
{
     any name = visit(ctx->variable());

     int line_number = ctx->getStart()->getLine();

     file << "Line " << line_number
          << ": factor : variable"
          << endl
          << endl;

     file << getRawText(ctx) << endl
          << endl;

     return name;
}

// ---- factor : ID LPAREN argument_list RPAREN  (#factor_function_call) ----
any CSubsetImp::visitFactor_function_call(CSubsetParser::Factor_function_callContext *ctx)
{
     visit(ctx->argument_list());

     int line_number = ctx->getStart()->getLine();

     int bucketIndex, position;
     string scopeId;
     SymbolInfo *symbol = table.lookup(ctx->ID()->getText(), bucketIndex, position, scopeId);

     if (symbol == nullptr)
     {
          file << "Error at line " << line_number << ": Undeclared function " << ctx->ID()->getText() << endl
               << endl;
          err << "Error at line " << line_number << ": Undeclared function " << ctx->ID()->getText() << endl
              << endl;
     }

     string curr_arg_list = ctx->argument_list()->getText();

     if (symbol && symbol->funcInfo->parameters != curr_arg_list)
     {
          string func_arg_list = symbol->funcInfo->parameters;

          vector<string> func_args;
          vector<string> curr_args;

          // -----------------------------
          // Split function arguments
          // -----------------------------
          stringstream ss(func_arg_list);
          string arg;

          while (getline(ss, arg, ','))
          {
               func_args.push_back(arg);
          }

          // -----------------------------
          // Split current arguments
          // -----------------------------
          stringstream ss2(curr_arg_list);

          while (getline(ss2, arg, ','))
          {
               curr_args.push_back(arg);
          }

          // -----------------------------
          // Check number of arguments
          // -----------------------------
          if (func_args.size() != curr_args.size())
          {
               file << "Error at line " << line_number << ": Total number of arguments mismatch in function " << ctx->ID()->getText() << endl
                    << endl;
               err << "Error at line " << line_number << ": Total number of arguments mismatch in function " << ctx->ID()->getText() << endl
                   << endl;
          }

          // -----------------------------
          // Check argument types
          // -----------------------------
          int min_size = min(func_args.size(), curr_args.size());

          for (int i = 0; i < min_size; i++)
          {
               if (isString(curr_args[i]))
               {
                    continue;
               }
               // =========================
               // Function argument type
               // =========================
               string func_arg_type;

               if (func_args[i].rfind("int", 0) == 0)
               {
                    func_arg_type = "int";
               }
               else if (func_args[i].rfind("float", 0) == 0)
               {
                    func_arg_type = "float";
               }
               else
               {
                    func_arg_type = "unknown";
               }

               // =========================
               // Current argument type
               // =========================
               string curr_arg_type;

               if (isValidFloat(curr_args[i]))
               {
                    curr_arg_type = "float";
               }
               else
               {
                    curr_arg_type = "int";
               }

               // =========================
               // Compare types
               // =========================
               if (func_arg_type != curr_arg_type)
               {
                    file << "Error at line " << line_number << ": " << i + 1 << "th argument mismatch in function " << ctx->ID()->getText() << endl
                         << endl;
                    err << "Error at line " << line_number << ": " << i + 1 << "th argument mismatch in function " << ctx->ID()->getText() << endl
                        << endl;
                    break;
               }
          }
     }
     file << "Line " << line_number << ": factor : ID LPAREN argument_list RPAREN" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- factor : LPAREN expression RPAREN  (#factor_parenthesized_expression) ----
any CSubsetImp::visitFactor_parenthesized_expression(CSubsetParser::Factor_parenthesized_expressionContext *ctx)
{
     visit(ctx->expression());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": factor : LPAREN expression RPAREN" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- factor : CONST_INT  (#factor_const_int) ----
any CSubsetImp::visitFactor_const_int(CSubsetParser::Factor_const_intContext *ctx)
{
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": factor : CONST_INT" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;

     return ctx->CONST_INT()->getText();
}

// ---- factor : CONST_FLOAT  (#factor_const_float) ----
any CSubsetImp::visitFactor_const_float(CSubsetParser::Factor_const_floatContext *ctx)
{
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": factor : CONST_FLOAT" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;

     return ctx->CONST_FLOAT()->getText();
}

// ---- factor : variable INCOP  (#factor_post_increment) ----
any CSubsetImp::visitFactor_post_increment(CSubsetParser::Factor_post_incrementContext *ctx)
{
     visit(ctx->variable());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": factor : variable INCOP" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- factor : variable DECOP  (#factor_post_decrement) ----
any CSubsetImp::visitFactor_post_decrement(CSubsetParser::Factor_post_decrementContext *ctx)
{
     visit(ctx->variable());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": factor : variable DECOP" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

/*=====================================================================================
    RULE: argument_list
    argument_list : arguments
                  |
=======================================================================================*/

// ---- argument_list : arguments  (#arg_list_with_args) ----
any CSubsetImp::visitArg_list_with_args(CSubsetParser::Arg_list_with_argsContext *ctx)
{
     visit(ctx->arguments());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": argument_list : arguments" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- argument_list :  (#arg_list_empty) ----
any CSubsetImp::visitArg_list_empty(CSubsetParser::Arg_list_emptyContext *ctx)
{
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": argument_list :" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

/*=====================================================================================
    RULE: arguments
    arguments : arguments COMMA logic_expression
              | logic_expression
=======================================================================================*/

// ---- arguments : arguments COMMA logic_expression  (#multi_arguments) ----
any CSubsetImp::visitMulti_arguments(CSubsetParser::Multi_argumentsContext *ctx)
{
     visit(ctx->arguments());
     visit(ctx->logic_expression());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": arguments : arguments COMMA logic_expression" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}

// ---- arguments : logic_expression  (#single_argument) ----
any CSubsetImp::visitSingle_argument(CSubsetParser::Single_argumentContext *ctx)
{
     visit(ctx->logic_expression());
     int line_number = ctx->getStart()->getLine();
     file << "Line " << line_number << ": arguments : logic_expression" << endl
          << endl;
     file << getRawText(ctx) << endl
          << endl;
     return nullptr;
}
