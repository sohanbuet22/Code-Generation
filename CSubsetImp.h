#pragma once

#include "CSubsetBaseVisitor.h"

// Recovery information is collected while the input is normalized in main.cpp.
// Keeping it here lets the visitor emit each diagnostic at the same point as the
// corresponding grammar-rule log entry.
void noteUnnamedParameter(int line);
void noteBadDeclaration(int line);
void noteBadAddAssign(int line);
void noteMissingSemicolon(int line, const std::string &expression);
bool hasUnnamedParameter(int line);
bool takeBadDeclaration(int line);
bool takeBadAddAssign(int line);
bool takeMissingSemicolon(int line, const std::string &expression);
void writeSyntaxError(int line, const std::string &message);
void appendLogSummary(int totalLines);

class CSubsetImp : public CSubsetBaseVisitor
{
public:
  CSubsetImp()
  {
  }
  virtual std::any visitIntType(CSubsetParser::IntTypeContext *ctx) override;

  virtual std::any visitFloatType(CSubsetParser::FloatTypeContext *ctx) override;

  virtual std::any visitVoidType(CSubsetParser::VoidTypeContext *ctx) override;

  virtual std::any visitVar_declaration(CSubsetParser::Var_declarationContext *ctx) override;

  virtual std::any visitSiglVarDecl(CSubsetParser::SiglVarDeclContext *ctx) override;

  virtual std::any visitMultiVarDecl(CSubsetParser::MultiVarDeclContext *ctx) override;

  virtual std::any visitFunc_declaration_with_param(CSubsetParser::Func_declaration_with_paramContext *ctx) override;

  virtual std::any visitFunc_declaration_without_param(CSubsetParser::Func_declaration_without_paramContext *ctx) override;

  virtual std::any visitFunc_def_with_param(CSubsetParser::Func_def_with_paramContext *ctx) override;

  virtual std::any visitSingle_param_with_id(CSubsetParser::Single_param_with_idContext *ctx) override;

  virtual std::any visitMultiple_param_with_id(CSubsetParser::Multiple_param_with_idContext *ctx) override;

  virtual std::any visitMultiple_param_without_id(CSubsetParser::Multiple_param_without_idContext *ctx) override;

  virtual std::any visitSingle_param_without_id(CSubsetParser::Single_param_without_idContext *ctx) override;

  virtual std::any visitSimpleVar(CSubsetParser::SimpleVarContext *ctx) override;

  virtual std::any visitArrVar(CSubsetParser::ArrVarContext *ctx) override;

  virtual std::any visitCompound_with_statement(CSubsetParser::Compound_with_statementContext *ctx) override;
  virtual std::any visitSingle_statement(CSubsetParser::Single_statementContext *ctx) override;

  virtual std::any visitReturn_statement(CSubsetParser::Return_statementContext *ctx) override;

  virtual std::any visitExpression_to_logic_expression(CSubsetParser::Expression_to_logic_expressionContext *ctx) override;
  virtual std::any visitLogic_to_rel_expression_complex(CSubsetParser::Logic_to_rel_expression_complexContext *ctx) override;

  virtual std::any visitLogic_to_rel_expression_simple(CSubsetParser::Logic_to_rel_expression_simpleContext *ctx) override;

  virtual std::any visitRel_expression_simple_expresssion_simple(CSubsetParser::Rel_expression_simple_expresssion_simpleContext *ctx) override;

  virtual std::any visitSimple_expression_to_term(CSubsetParser::Simple_expression_to_termContext *ctx) override;

  virtual std::any visitTerm_unary_expression(CSubsetParser::Term_unary_expressionContext *ctx) override;

  virtual std::any visitUnary_expression_to_factor(CSubsetParser::Unary_expression_to_factorContext *ctx) override;

  virtual std::any visitFactor_to_variable(CSubsetParser::Factor_to_variableContext *ctx) override;

  virtual std::any visitSimple_expression_to_term_with_plus(CSubsetParser::Simple_expression_to_term_with_plusContext *ctx) override;

  virtual std::any visitProgram_to_unit(CSubsetParser::Program_to_unitContext *ctx) override;

  virtual std::any visitUnit_to_var_declaration(CSubsetParser::Unit_to_var_declarationContext *ctx) override;

  virtual std::any visitProgram_to_program_unit(CSubsetParser::Program_to_program_unitContext *ctx) override;

  virtual std::any visitFactor_const_int(CSubsetParser::Factor_const_intContext *ctx) override;

  virtual std::any visitFactor_const_float(CSubsetParser::Factor_const_floatContext *ctx) override;


// Start & Unit
  virtual std::any visitStart_rule(CSubsetParser::Start_ruleContext *ctx) override;
  virtual std::any visitUnit_to_func_declaration(CSubsetParser::Unit_to_func_declarationContext *ctx) override;
  virtual std::any visitUnit_to_func_definition(CSubsetParser::Unit_to_func_definitionContext *ctx) override;

  // Function Definition & Compound Statements
  virtual std::any visitFunc_def_without_param(CSubsetParser::Func_def_without_paramContext *ctx) override;
  virtual std::any visitCompound_without_statement(CSubsetParser::Compound_without_statementContext *ctx) override;

  // Declaration List
  virtual std::any visitMultiVarDeclWithArr(CSubsetParser::MultiVarDeclWithArrContext *ctx) override;
  virtual std::any visitSiglArrDecl(CSubsetParser::SiglArrDeclContext *ctx) override;

  // Statements
  virtual std::any visitMultiple_statement(CSubsetParser::Multiple_statementContext *ctx) override;
  virtual std::any visitVar_declaration_statement(CSubsetParser::Var_declaration_statementContext *ctx) override;
  virtual std::any visitExpression_statement_statement(CSubsetParser::Expression_statement_statementContext *ctx) override;
  virtual std::any visitCompound_statement_statement(CSubsetParser::Compound_statement_statementContext *ctx) override;
  virtual std::any visitFor_statement(CSubsetParser::For_statementContext *ctx) override;
  virtual std::any visitIf_statement(CSubsetParser::If_statementContext *ctx) override;
  virtual std::any visitIf_else_statement(CSubsetParser::If_else_statementContext *ctx) override;
  virtual std::any visitWhile_statement(CSubsetParser::While_statementContext *ctx) override;
  virtual std::any visitPrintln_statement(CSubsetParser::Println_statementContext *ctx) override;

  // Expression Statements
  virtual std::any visitExpression_statement_to_semicolon(CSubsetParser::Expression_statement_to_semicolonContext *ctx) override;
  virtual std::any visitExpression_statement_to_expression_semicolon(CSubsetParser::Expression_statement_to_expression_semicolonContext *ctx) override;

  // Expressions, Terms & Factors
  virtual std::any visitExpression_to_logic_expression_with_assignop(CSubsetParser::Expression_to_logic_expression_with_assignopContext *ctx) override;
  virtual std::any visitRel_expression_simple_expresssion_complex(CSubsetParser::Rel_expression_simple_expresssion_complexContext *ctx) override;
  virtual std::any visitTerm_times_unary_expression(CSubsetParser::Term_times_unary_expressionContext *ctx) override;
  virtual std::any visitUnary_expression_addop(CSubsetParser::Unary_expression_addopContext *ctx) override;
  virtual std::any visitUnary_expression_not(CSubsetParser::Unary_expression_notContext *ctx) override;
  virtual std::any visitFactor_function_call(CSubsetParser::Factor_function_callContext *ctx) override;
  virtual std::any visitFactor_parenthesized_expression(CSubsetParser::Factor_parenthesized_expressionContext *ctx) override;
  virtual std::any visitFactor_post_increment(CSubsetParser::Factor_post_incrementContext *ctx) override;
  virtual std::any visitFactor_post_decrement(CSubsetParser::Factor_post_decrementContext *ctx) override;

  // Arguments & Argument List
  virtual std::any visitArg_list_with_args(CSubsetParser::Arg_list_with_argsContext *ctx) override;
  virtual std::any visitArg_list_empty(CSubsetParser::Arg_list_emptyContext *ctx) override;
  virtual std::any visitMulti_arguments(CSubsetParser::Multi_argumentsContext *ctx) override;
  virtual std::any visitSingle_argument(CSubsetParser::Single_argumentContext *ctx) override;

};
