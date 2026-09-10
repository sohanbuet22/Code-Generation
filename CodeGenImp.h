#pragma once

#include "CSubsetBaseVisitor.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

struct CodeGenVarInfo
{
    std::string type;
    bool isArray = false;
    int arraySize = 1;
};

class CodeGenEmitter
{
public:
    explicit CodeGenEmitter(const std::string &tempPath) : tempPath(tempPath)
    {
        temp.open(tempPath, std::ios::out | std::ios::trunc);
    }
    void emit(const std::string &line) { temp << "\t" << line << "\n"; }
    void comment(const std::string &text) { temp << "\t; " << text << "\n"; }
    void emitLabel(const std::string &label) { temp << label << ":\n"; }
    void declareScalar(const std::string &name) { dataDecls << name << " dd 0\n"; }
    void declareArray(const std::string &name, int size)
    {
        dataDecls << name << " dd " << size << " dup(0)\n";
    }
    std::string newLabel() { return "L" + std::to_string(labelCounter++); }

    void finalize(const std::string &outPath);

private:
    static std::string printIntProcedureAsm();
    std::string tempPath;
    std::ofstream temp;
    std::ostringstream dataDecls;
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

private:
    CodeGenEmitter &emitter;
    std::unordered_map<std::string, CodeGenVarInfo> symtab;
    std::string currentDeclType;

    std::string resolveVariable(CSubsetParser::VariableContext *varCtx, bool &outIsArray);

    void loadVariable(CSubsetParser::VariableContext *varCtx);
    void storeVariable(CSubsetParser::VariableContext *varCtx);
};
