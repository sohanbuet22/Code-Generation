
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetVisitor.h"


/**
 * This class provides an empty implementation of CSubsetVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CSubsetBaseVisitor : public CSubsetVisitor {
public:

  virtual std::any visitStart_rule(CSubsetParser::Start_ruleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram_to_unit(CSubsetParser::Program_to_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram_to_program_unit(CSubsetParser::Program_to_program_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnit_to_var_declaration(CSubsetParser::Unit_to_var_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnit_to_func_declaration(CSubsetParser::Unit_to_func_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnit_to_func_definition(CSubsetParser::Unit_to_func_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_declaration_with_param(CSubsetParser::Func_declaration_with_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_declaration_without_param(CSubsetParser::Func_declaration_without_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_def_with_param(CSubsetParser::Func_def_with_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_def_without_param(CSubsetParser::Func_def_without_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingle_param_with_id(CSubsetParser::Single_param_with_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiple_param_without_id(CSubsetParser::Multiple_param_without_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiple_param_with_id(CSubsetParser::Multiple_param_with_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingle_param_without_id(CSubsetParser::Single_param_without_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound_with_statement(CSubsetParser::Compound_with_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound_without_statement(CSubsetParser::Compound_without_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_declaration(CSubsetParser::Var_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntType(CSubsetParser::IntTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatType(CSubsetParser::FloatTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVoidType(CSubsetParser::VoidTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSiglArrDecl(CSubsetParser::SiglArrDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSiglVarDecl(CSubsetParser::SiglVarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiVarDecl(CSubsetParser::MultiVarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiVarDeclWithArr(CSubsetParser::MultiVarDeclWithArrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiple_statement(CSubsetParser::Multiple_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingle_statement(CSubsetParser::Single_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_declaration_statement(CSubsetParser::Var_declaration_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintln_statement(CSubsetParser::Println_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_statement_statement(CSubsetParser::Expression_statement_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound_statement_statement(CSubsetParser::Compound_statement_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_statement(CSubsetParser::For_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_statement(CSubsetParser::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_else_statement(CSubsetParser::If_else_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile_statement(CSubsetParser::While_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_statement(CSubsetParser::Return_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_statement_to_semicolon(CSubsetParser::Expression_statement_to_semicolonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_statement_to_expression_semicolon(CSubsetParser::Expression_statement_to_expression_semicolonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleVar(CSubsetParser::SimpleVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrVar(CSubsetParser::ArrVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_to_logic_expression(CSubsetParser::Expression_to_logic_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_to_logic_expression_with_assignop(CSubsetParser::Expression_to_logic_expression_with_assignopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_to_rel_expression_simple(CSubsetParser::Logic_to_rel_expression_simpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_to_rel_expression_complex(CSubsetParser::Logic_to_rel_expression_complexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRel_expression_simple_expresssion_simple(CSubsetParser::Rel_expression_simple_expresssion_simpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRel_expression_simple_expresssion_complex(CSubsetParser::Rel_expression_simple_expresssion_complexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expression_to_term(CSubsetParser::Simple_expression_to_termContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expression_to_term_with_plus(CSubsetParser::Simple_expression_to_term_with_plusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm_times_unary_expression(CSubsetParser::Term_times_unary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm_unary_expression(CSubsetParser::Term_unary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_expression_addop(CSubsetParser::Unary_expression_addopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_expression_not(CSubsetParser::Unary_expression_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_expression_to_factor(CSubsetParser::Unary_expression_to_factorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_to_variable(CSubsetParser::Factor_to_variableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_function_call(CSubsetParser::Factor_function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_parenthesized_expression(CSubsetParser::Factor_parenthesized_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_const_int(CSubsetParser::Factor_const_intContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_const_float(CSubsetParser::Factor_const_floatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_post_increment(CSubsetParser::Factor_post_incrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_post_decrement(CSubsetParser::Factor_post_decrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg_list_with_args(CSubsetParser::Arg_list_with_argsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg_list_empty(CSubsetParser::Arg_list_emptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulti_arguments(CSubsetParser::Multi_argumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingle_argument(CSubsetParser::Single_argumentContext *ctx) override {
    return visitChildren(ctx);
  }


};

