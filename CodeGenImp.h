#pragma once

#include "CSubsetBaseVisitor.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <vector>

struct CodeGenVarInfo
{
    std::string type;
    bool isArray = false;
    int arraySize = 1;
    // Stack offset relative to EBP. Only meaningful for locals/params:
    // positive  -> parameter (e.g. EBP+8, EBP+12, ...)
    // negative  -> local variable (e.g. EBP-4, EBP-8, ...)
    // Unused (0) for globals, which are addressed directly by symbol name.
    int offset = 0;
};

class CodeGenEmitter
{
public:
    explicit CodeGenEmitter(const std::string &tempPath) : tempPath(tempPath)
    {
        temp.open(tempPath, std::ios::out | std::ios::trunc);
    }
    void emit(const std::string &line)
    {
        std::ostream &out = inGlobalInit ? static_cast<std::ostream &>(globalInit) : static_cast<std::ostream &>(temp);
        out << "\t" << line << "\n";
    }
    void comment(const std::string &text)
    {
        std::ostream &out = inGlobalInit ? static_cast<std::ostream &>(globalInit) : static_cast<std::ostream &>(temp);
        out << "\t; " << text << "\n";
    }
    void emitLabel(const std::string &label)
    {
        std::ostream &out = inGlobalInit ? static_cast<std::ostream &>(globalInit) : static_cast<std::ostream &>(temp);
        out << label << ":\n";
    }
    void declareScalar(const std::string &name) { dataDecls << name << " dd 0\n"; }
    void declareArray(const std::string &name, int size)
    {
        dataDecls << name << " dd " << size << " dup(0)\n";
    }
    std::string newLabel() { return "L" + std::to_string(labelCounter++); }

    // Global variable initializers (e.g. "int x = 5;" at file scope) must run
    // once, before main is called, since they sit outside any function body.
    // Routes emit()/comment() into a separate buffer that finalize() places
    // in `start:` ahead of the call into func_main.
    void beginGlobalInit() { inGlobalInit = true; }
    void endGlobalInit() { inGlobalInit = false; }

    void finalize(const std::string &outPath);

private:
    static std::string printIntProcedureAsm();
    std::string tempPath;
    std::ofstream temp;
    std::ostringstream dataDecls;
    std::ostringstream globalInit;
    bool inGlobalInit = false;
    int labelCounter = 0;
};

class CodeGenImp : public CSubsetBaseVisitor
{
public:
    CodeGenImp(CodeGenEmitter &emitter) : emitter(emitter) {}

    // ---- Declarations (drive the .data section) ----
    virtual std::any visitVar_declaration(CSubsetParser::Var_declarationContext *ctx) override;
    virtual std::any visitSiglVarDecl(CSubsetParser::SiglVarDeclContext *ctx) override;
    virtual std::any visitMultiVarDecl(CSubsetParser::MultiVarDeclContext *ctx) override;
    virtual std::any visitSiglArrDecl(CSubsetParser::SiglArrDeclContext *ctx) override;
    virtual std::any visitMultiVarDeclWithArr(CSubsetParser::MultiVarDeclWithArrContext *ctx) override;

    // ---- Expressions ----
    virtual std::any visitExpression_to_logic_expression_with_assignop(
        CSubsetParser::Expression_to_logic_expression_with_assignopContext *ctx) override;
    virtual std::any visitLogic_to_rel_expression_complex(
        CSubsetParser::Logic_to_rel_expression_complexContext *ctx) override;
    virtual std::any visitRel_expression_simple_expresssion_complex(
        CSubsetParser::Rel_expression_simple_expresssion_complexContext *ctx) override;
    virtual std::any visitSimple_expression_to_term_with_plus(
        CSubsetParser::Simple_expression_to_term_with_plusContext *ctx) override;
    virtual std::any visitTerm_times_unary_expression(
        CSubsetParser::Term_times_unary_expressionContext *ctx) override;
    virtual std::any visitUnary_expression_addop(
        CSubsetParser::Unary_expression_addopContext *ctx) override;
    virtual std::any visitUnary_expression_not(
        CSubsetParser::Unary_expression_notContext *ctx) override;

    // ---- Factor leaves ----
    virtual std::any visitFactor_to_variable(CSubsetParser::Factor_to_variableContext *ctx) override;
    virtual std::any visitFactor_const_int(CSubsetParser::Factor_const_intContext *ctx) override;
    virtual std::any visitFactor_parenthesized_expression(
        CSubsetParser::Factor_parenthesized_expressionContext *ctx) override;
    virtual std::any visitFactor_post_increment(CSubsetParser::Factor_post_incrementContext *ctx) override;
    virtual std::any visitFactor_post_decrement(CSubsetParser::Factor_post_decrementContext *ctx) override;

    // ---- println ----
    virtual std::any visitPrintln_statement(CSubsetParser::Println_statementContext *ctx) override;
    virtual std::any visitExpression_statement_to_expression_semicolon(CSubsetParser::Expression_statement_to_expression_semicolonContext *ctx) override;
    virtual std::any visitReturn_statement(CSubsetParser::Return_statementContext *ctx) override;

    // extra things
    virtual std::any visitSiglVarDeclWithInit(CSubsetParser::SiglVarDeclWithInitContext *ctx) override;
    virtual std::any visitMultiVarDeclWithInit(CSubsetParser::MultiVarDeclWithInitContext *ctx) override;
    virtual std::any visitExpression_to_logic_expression_with_compound_assignop(CSubsetParser::Expression_to_logic_expression_with_compound_assignopContext *ctx) override;

    // control flow patterns

    virtual std::any visitFor_statement(CSubsetParser::For_statementContext *ctx) override;

    virtual std::any visitIf_statement(CSubsetParser::If_statementContext *ctx) override;

    virtual std::any visitIf_else_statement(CSubsetParser::If_else_statementContext *ctx) override;

    virtual std::any visitWhile_statement(CSubsetParser::While_statementContext *ctx) override;
    

    //function calling related   

    virtual std::any visitFactor_function_call(CSubsetParser::Factor_function_callContext *ctx);

    virtual std::any visitArg_list_with_args(CSubsetParser::Arg_list_with_argsContext *ctx);

    virtual std::any visitArg_list_empty(CSubsetParser::Arg_list_emptyContext *ctx);

    virtual std::any visitMulti_arguments(CSubsetParser::Multi_argumentsContext *ctx);

    virtual std::any visitSingle_argument(CSubsetParser::Single_argumentContext *ctx);

    // ---- Function declarations / definitions ----
    virtual std::any visitFunc_def_with_param(CSubsetParser::Func_def_with_paramContext *ctx) override;
    virtual std::any visitFunc_def_without_param(CSubsetParser::Func_def_without_paramContext *ctx) override;
    virtual std::any visitFunc_declaration_with_param(CSubsetParser::Func_declaration_with_paramContext *ctx) override;
    virtual std::any visitFunc_declaration_without_param(CSubsetParser::Func_declaration_without_paramContext *ctx) override;

private:
    CodeGenEmitter &emitter;
    std::unordered_map<std::string, CodeGenVarInfo> symtab;      // globals (data segment)
    std::unordered_map<std::string, CodeGenVarInfo> localSymtab; // params + locals of the function currently being generated
    std::string currentDeclType;

    // Set to the function's name while its body is being visited, empty at file scope.
    // Used to decide whether a declaration_list rule allocates a global (data segment)
    // or a local (stack) variable.
    std::string currentFuncName;
    // Running stack-offset cursor for the function currently being generated.
    // Starts at 0 and moves further negative as locals are declared.
    int localOffset = 0;
    // Parameter count of the function currently being generated, used to
    // compute N for the callee-cleanup "RET N" at every exit point.
    int currentParamCount = 0;

    std::string resolveVariable(CSubsetParser::VariableContext *varCtx, bool &outIsArray);

    void loadVariable(CSubsetParser::VariableContext *varCtx);
    void storeVariable(CSubsetParser::VariableContext *varCtx);

    // Returns the addressing base for a variable: "EBP+N"/"EBP-N" for a
    // param/local of the function currently being generated, or just the
    // symbol name for a global.
    std::string varBaseOperand(const std::string &name);

    // Collects parameter names in left-to-right declaration order.
    // Anonymous parameters (prototype-only, no ID) contribute an empty string.
    void collectParamNames(CSubsetParser::Parameter_listContext *ctx, std::vector<std::string> &names);

    // Collects call-site argument expressions in left-to-right order.
    void collectArgumentExprs(CSubsetParser::ArgumentsContext *ctx,
                               std::vector<CSubsetParser::Logic_expressionContext *> &out);

    // Shared setup/teardown for a function body (func_definition).
    // paramCtx may be nullptr for a parameterless function.
    void beginFunction(const std::string &name, CSubsetParser::Parameter_listContext *paramCtx);
    void endFunction();
};