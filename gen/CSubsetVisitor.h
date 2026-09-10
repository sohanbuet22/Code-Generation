
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CSubsetParser.
 */
class  CSubsetVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CSubsetParser.
   */
    virtual std::any visitStart_rule(CSubsetParser::Start_ruleContext *context) = 0;

    virtual std::any visitProgram_to_unit(CSubsetParser::Program_to_unitContext *context) = 0;

    virtual std::any visitProgram_to_program_unit(CSubsetParser::Program_to_program_unitContext *context) = 0;

    virtual std::any visitUnit_to_var_declaration(CSubsetParser::Unit_to_var_declarationContext *context) = 0;

    virtual std::any visitUnit_to_func_declaration(CSubsetParser::Unit_to_func_declarationContext *context) = 0;

    virtual std::any visitUnit_to_func_definition(CSubsetParser::Unit_to_func_definitionContext *context) = 0;

    virtual std::any visitFunc_declaration_with_param(CSubsetParser::Func_declaration_with_paramContext *context) = 0;

    virtual std::any visitFunc_declaration_without_param(CSubsetParser::Func_declaration_without_paramContext *context) = 0;

    virtual std::any visitFunc_def_with_param(CSubsetParser::Func_def_with_paramContext *context) = 0;

    virtual std::any visitFunc_def_without_param(CSubsetParser::Func_def_without_paramContext *context) = 0;

    virtual std::any visitSingle_param_with_id(CSubsetParser::Single_param_with_idContext *context) = 0;

    virtual std::any visitMultiple_param_without_id(CSubsetParser::Multiple_param_without_idContext *context) = 0;

    virtual std::any visitMultiple_param_with_id(CSubsetParser::Multiple_param_with_idContext *context) = 0;

    virtual std::any visitSingle_param_without_id(CSubsetParser::Single_param_without_idContext *context) = 0;

    virtual std::any visitCompound_with_statement(CSubsetParser::Compound_with_statementContext *context) = 0;

    virtual std::any visitCompound_without_statement(CSubsetParser::Compound_without_statementContext *context) = 0;

    virtual std::any visitVar_declaration(CSubsetParser::Var_declarationContext *context) = 0;

    virtual std::any visitIntType(CSubsetParser::IntTypeContext *context) = 0;

    virtual std::any visitFloatType(CSubsetParser::FloatTypeContext *context) = 0;

    virtual std::any visitVoidType(CSubsetParser::VoidTypeContext *context) = 0;

    virtual std::any visitSiglArrDecl(CSubsetParser::SiglArrDeclContext *context) = 0;

    virtual std::any visitSiglVarDecl(CSubsetParser::SiglVarDeclContext *context) = 0;

    virtual std::any visitMultiVarDecl(CSubsetParser::MultiVarDeclContext *context) = 0;

    virtual std::any visitMultiVarDeclWithArr(CSubsetParser::MultiVarDeclWithArrContext *context) = 0;

    virtual std::any visitMultiple_statement(CSubsetParser::Multiple_statementContext *context) = 0;

    virtual std::any visitSingle_statement(CSubsetParser::Single_statementContext *context) = 0;

    virtual std::any visitVar_declaration_statement(CSubsetParser::Var_declaration_statementContext *context) = 0;

    virtual std::any visitPrintln_statement(CSubsetParser::Println_statementContext *context) = 0;

    virtual std::any visitExpression_statement_statement(CSubsetParser::Expression_statement_statementContext *context) = 0;

    virtual std::any visitCompound_statement_statement(CSubsetParser::Compound_statement_statementContext *context) = 0;

    virtual std::any visitFor_statement(CSubsetParser::For_statementContext *context) = 0;

    virtual std::any visitIf_statement(CSubsetParser::If_statementContext *context) = 0;

    virtual std::any visitIf_else_statement(CSubsetParser::If_else_statementContext *context) = 0;

    virtual std::any visitWhile_statement(CSubsetParser::While_statementContext *context) = 0;

    virtual std::any visitReturn_statement(CSubsetParser::Return_statementContext *context) = 0;

    virtual std::any visitExpression_statement_to_semicolon(CSubsetParser::Expression_statement_to_semicolonContext *context) = 0;

    virtual std::any visitExpression_statement_to_expression_semicolon(CSubsetParser::Expression_statement_to_expression_semicolonContext *context) = 0;

    virtual std::any visitSimpleVar(CSubsetParser::SimpleVarContext *context) = 0;

    virtual std::any visitArrVar(CSubsetParser::ArrVarContext *context) = 0;

    virtual std::any visitExpression_to_logic_expression(CSubsetParser::Expression_to_logic_expressionContext *context) = 0;

    virtual std::any visitExpression_to_logic_expression_with_assignop(CSubsetParser::Expression_to_logic_expression_with_assignopContext *context) = 0;

    virtual std::any visitLogic_to_rel_expression_simple(CSubsetParser::Logic_to_rel_expression_simpleContext *context) = 0;

    virtual std::any visitLogic_to_rel_expression_complex(CSubsetParser::Logic_to_rel_expression_complexContext *context) = 0;

    virtual std::any visitRel_expression_simple_expresssion_simple(CSubsetParser::Rel_expression_simple_expresssion_simpleContext *context) = 0;

    virtual std::any visitRel_expression_simple_expresssion_complex(CSubsetParser::Rel_expression_simple_expresssion_complexContext *context) = 0;

    virtual std::any visitSimple_expression_to_term(CSubsetParser::Simple_expression_to_termContext *context) = 0;

    virtual std::any visitSimple_expression_to_term_with_plus(CSubsetParser::Simple_expression_to_term_with_plusContext *context) = 0;

    virtual std::any visitTerm_times_unary_expression(CSubsetParser::Term_times_unary_expressionContext *context) = 0;

    virtual std::any visitTerm_unary_expression(CSubsetParser::Term_unary_expressionContext *context) = 0;

    virtual std::any visitUnary_expression_addop(CSubsetParser::Unary_expression_addopContext *context) = 0;

    virtual std::any visitUnary_expression_not(CSubsetParser::Unary_expression_notContext *context) = 0;

    virtual std::any visitUnary_expression_to_factor(CSubsetParser::Unary_expression_to_factorContext *context) = 0;

    virtual std::any visitFactor_to_variable(CSubsetParser::Factor_to_variableContext *context) = 0;

    virtual std::any visitFactor_function_call(CSubsetParser::Factor_function_callContext *context) = 0;

    virtual std::any visitFactor_parenthesized_expression(CSubsetParser::Factor_parenthesized_expressionContext *context) = 0;

    virtual std::any visitFactor_const_int(CSubsetParser::Factor_const_intContext *context) = 0;

    virtual std::any visitFactor_const_float(CSubsetParser::Factor_const_floatContext *context) = 0;

    virtual std::any visitFactor_post_increment(CSubsetParser::Factor_post_incrementContext *context) = 0;

    virtual std::any visitFactor_post_decrement(CSubsetParser::Factor_post_decrementContext *context) = 0;

    virtual std::any visitArg_list_with_args(CSubsetParser::Arg_list_with_argsContext *context) = 0;

    virtual std::any visitArg_list_empty(CSubsetParser::Arg_list_emptyContext *context) = 0;

    virtual std::any visitMulti_arguments(CSubsetParser::Multi_argumentsContext *context) = 0;

    virtual std::any visitSingle_argument(CSubsetParser::Single_argumentContext *context) = 0;


};

