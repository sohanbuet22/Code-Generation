
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CSubsetParser.
 */
class  CSubsetListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart_rule(CSubsetParser::Start_ruleContext *ctx) = 0;
  virtual void exitStart_rule(CSubsetParser::Start_ruleContext *ctx) = 0;

  virtual void enterProgram_to_unit(CSubsetParser::Program_to_unitContext *ctx) = 0;
  virtual void exitProgram_to_unit(CSubsetParser::Program_to_unitContext *ctx) = 0;

  virtual void enterProgram_to_program_unit(CSubsetParser::Program_to_program_unitContext *ctx) = 0;
  virtual void exitProgram_to_program_unit(CSubsetParser::Program_to_program_unitContext *ctx) = 0;

  virtual void enterUnit_to_var_declaration(CSubsetParser::Unit_to_var_declarationContext *ctx) = 0;
  virtual void exitUnit_to_var_declaration(CSubsetParser::Unit_to_var_declarationContext *ctx) = 0;

  virtual void enterUnit_to_func_declaration(CSubsetParser::Unit_to_func_declarationContext *ctx) = 0;
  virtual void exitUnit_to_func_declaration(CSubsetParser::Unit_to_func_declarationContext *ctx) = 0;

  virtual void enterUnit_to_func_definition(CSubsetParser::Unit_to_func_definitionContext *ctx) = 0;
  virtual void exitUnit_to_func_definition(CSubsetParser::Unit_to_func_definitionContext *ctx) = 0;

  virtual void enterFunc_declaration_with_param(CSubsetParser::Func_declaration_with_paramContext *ctx) = 0;
  virtual void exitFunc_declaration_with_param(CSubsetParser::Func_declaration_with_paramContext *ctx) = 0;

  virtual void enterFunc_declaration_without_param(CSubsetParser::Func_declaration_without_paramContext *ctx) = 0;
  virtual void exitFunc_declaration_without_param(CSubsetParser::Func_declaration_without_paramContext *ctx) = 0;

  virtual void enterFunc_def_with_param(CSubsetParser::Func_def_with_paramContext *ctx) = 0;
  virtual void exitFunc_def_with_param(CSubsetParser::Func_def_with_paramContext *ctx) = 0;

  virtual void enterFunc_def_without_param(CSubsetParser::Func_def_without_paramContext *ctx) = 0;
  virtual void exitFunc_def_without_param(CSubsetParser::Func_def_without_paramContext *ctx) = 0;

  virtual void enterSingle_param_with_id(CSubsetParser::Single_param_with_idContext *ctx) = 0;
  virtual void exitSingle_param_with_id(CSubsetParser::Single_param_with_idContext *ctx) = 0;

  virtual void enterMultiple_param_without_id(CSubsetParser::Multiple_param_without_idContext *ctx) = 0;
  virtual void exitMultiple_param_without_id(CSubsetParser::Multiple_param_without_idContext *ctx) = 0;

  virtual void enterMultiple_param_with_id(CSubsetParser::Multiple_param_with_idContext *ctx) = 0;
  virtual void exitMultiple_param_with_id(CSubsetParser::Multiple_param_with_idContext *ctx) = 0;

  virtual void enterSingle_param_without_id(CSubsetParser::Single_param_without_idContext *ctx) = 0;
  virtual void exitSingle_param_without_id(CSubsetParser::Single_param_without_idContext *ctx) = 0;

  virtual void enterCompound_with_statement(CSubsetParser::Compound_with_statementContext *ctx) = 0;
  virtual void exitCompound_with_statement(CSubsetParser::Compound_with_statementContext *ctx) = 0;

  virtual void enterCompound_without_statement(CSubsetParser::Compound_without_statementContext *ctx) = 0;
  virtual void exitCompound_without_statement(CSubsetParser::Compound_without_statementContext *ctx) = 0;

  virtual void enterVar_declaration(CSubsetParser::Var_declarationContext *ctx) = 0;
  virtual void exitVar_declaration(CSubsetParser::Var_declarationContext *ctx) = 0;

  virtual void enterIntType(CSubsetParser::IntTypeContext *ctx) = 0;
  virtual void exitIntType(CSubsetParser::IntTypeContext *ctx) = 0;

  virtual void enterFloatType(CSubsetParser::FloatTypeContext *ctx) = 0;
  virtual void exitFloatType(CSubsetParser::FloatTypeContext *ctx) = 0;

  virtual void enterVoidType(CSubsetParser::VoidTypeContext *ctx) = 0;
  virtual void exitVoidType(CSubsetParser::VoidTypeContext *ctx) = 0;

  virtual void enterSiglArrDecl(CSubsetParser::SiglArrDeclContext *ctx) = 0;
  virtual void exitSiglArrDecl(CSubsetParser::SiglArrDeclContext *ctx) = 0;

  virtual void enterSiglVarDecl(CSubsetParser::SiglVarDeclContext *ctx) = 0;
  virtual void exitSiglVarDecl(CSubsetParser::SiglVarDeclContext *ctx) = 0;

  virtual void enterMultiVarDecl(CSubsetParser::MultiVarDeclContext *ctx) = 0;
  virtual void exitMultiVarDecl(CSubsetParser::MultiVarDeclContext *ctx) = 0;

  virtual void enterMultiVarDeclWithArr(CSubsetParser::MultiVarDeclWithArrContext *ctx) = 0;
  virtual void exitMultiVarDeclWithArr(CSubsetParser::MultiVarDeclWithArrContext *ctx) = 0;

  virtual void enterMultiple_statement(CSubsetParser::Multiple_statementContext *ctx) = 0;
  virtual void exitMultiple_statement(CSubsetParser::Multiple_statementContext *ctx) = 0;

  virtual void enterSingle_statement(CSubsetParser::Single_statementContext *ctx) = 0;
  virtual void exitSingle_statement(CSubsetParser::Single_statementContext *ctx) = 0;

  virtual void enterVar_declaration_statement(CSubsetParser::Var_declaration_statementContext *ctx) = 0;
  virtual void exitVar_declaration_statement(CSubsetParser::Var_declaration_statementContext *ctx) = 0;

  virtual void enterPrintln_statement(CSubsetParser::Println_statementContext *ctx) = 0;
  virtual void exitPrintln_statement(CSubsetParser::Println_statementContext *ctx) = 0;

  virtual void enterExpression_statement_statement(CSubsetParser::Expression_statement_statementContext *ctx) = 0;
  virtual void exitExpression_statement_statement(CSubsetParser::Expression_statement_statementContext *ctx) = 0;

  virtual void enterCompound_statement_statement(CSubsetParser::Compound_statement_statementContext *ctx) = 0;
  virtual void exitCompound_statement_statement(CSubsetParser::Compound_statement_statementContext *ctx) = 0;

  virtual void enterFor_statement(CSubsetParser::For_statementContext *ctx) = 0;
  virtual void exitFor_statement(CSubsetParser::For_statementContext *ctx) = 0;

  virtual void enterIf_statement(CSubsetParser::If_statementContext *ctx) = 0;
  virtual void exitIf_statement(CSubsetParser::If_statementContext *ctx) = 0;

  virtual void enterIf_else_statement(CSubsetParser::If_else_statementContext *ctx) = 0;
  virtual void exitIf_else_statement(CSubsetParser::If_else_statementContext *ctx) = 0;

  virtual void enterWhile_statement(CSubsetParser::While_statementContext *ctx) = 0;
  virtual void exitWhile_statement(CSubsetParser::While_statementContext *ctx) = 0;

  virtual void enterReturn_statement(CSubsetParser::Return_statementContext *ctx) = 0;
  virtual void exitReturn_statement(CSubsetParser::Return_statementContext *ctx) = 0;

  virtual void enterExpression_statement_to_semicolon(CSubsetParser::Expression_statement_to_semicolonContext *ctx) = 0;
  virtual void exitExpression_statement_to_semicolon(CSubsetParser::Expression_statement_to_semicolonContext *ctx) = 0;

  virtual void enterExpression_statement_to_expression_semicolon(CSubsetParser::Expression_statement_to_expression_semicolonContext *ctx) = 0;
  virtual void exitExpression_statement_to_expression_semicolon(CSubsetParser::Expression_statement_to_expression_semicolonContext *ctx) = 0;

  virtual void enterSimpleVar(CSubsetParser::SimpleVarContext *ctx) = 0;
  virtual void exitSimpleVar(CSubsetParser::SimpleVarContext *ctx) = 0;

  virtual void enterArrVar(CSubsetParser::ArrVarContext *ctx) = 0;
  virtual void exitArrVar(CSubsetParser::ArrVarContext *ctx) = 0;

  virtual void enterExpression_to_logic_expression(CSubsetParser::Expression_to_logic_expressionContext *ctx) = 0;
  virtual void exitExpression_to_logic_expression(CSubsetParser::Expression_to_logic_expressionContext *ctx) = 0;

  virtual void enterExpression_to_logic_expression_with_assignop(CSubsetParser::Expression_to_logic_expression_with_assignopContext *ctx) = 0;
  virtual void exitExpression_to_logic_expression_with_assignop(CSubsetParser::Expression_to_logic_expression_with_assignopContext *ctx) = 0;

  virtual void enterLogic_to_rel_expression_simple(CSubsetParser::Logic_to_rel_expression_simpleContext *ctx) = 0;
  virtual void exitLogic_to_rel_expression_simple(CSubsetParser::Logic_to_rel_expression_simpleContext *ctx) = 0;

  virtual void enterLogic_to_rel_expression_complex(CSubsetParser::Logic_to_rel_expression_complexContext *ctx) = 0;
  virtual void exitLogic_to_rel_expression_complex(CSubsetParser::Logic_to_rel_expression_complexContext *ctx) = 0;

  virtual void enterRel_expression_simple_expresssion_simple(CSubsetParser::Rel_expression_simple_expresssion_simpleContext *ctx) = 0;
  virtual void exitRel_expression_simple_expresssion_simple(CSubsetParser::Rel_expression_simple_expresssion_simpleContext *ctx) = 0;

  virtual void enterRel_expression_simple_expresssion_complex(CSubsetParser::Rel_expression_simple_expresssion_complexContext *ctx) = 0;
  virtual void exitRel_expression_simple_expresssion_complex(CSubsetParser::Rel_expression_simple_expresssion_complexContext *ctx) = 0;

  virtual void enterSimple_expression_to_term(CSubsetParser::Simple_expression_to_termContext *ctx) = 0;
  virtual void exitSimple_expression_to_term(CSubsetParser::Simple_expression_to_termContext *ctx) = 0;

  virtual void enterSimple_expression_to_term_with_plus(CSubsetParser::Simple_expression_to_term_with_plusContext *ctx) = 0;
  virtual void exitSimple_expression_to_term_with_plus(CSubsetParser::Simple_expression_to_term_with_plusContext *ctx) = 0;

  virtual void enterTerm_times_unary_expression(CSubsetParser::Term_times_unary_expressionContext *ctx) = 0;
  virtual void exitTerm_times_unary_expression(CSubsetParser::Term_times_unary_expressionContext *ctx) = 0;

  virtual void enterTerm_unary_expression(CSubsetParser::Term_unary_expressionContext *ctx) = 0;
  virtual void exitTerm_unary_expression(CSubsetParser::Term_unary_expressionContext *ctx) = 0;

  virtual void enterUnary_expression_addop(CSubsetParser::Unary_expression_addopContext *ctx) = 0;
  virtual void exitUnary_expression_addop(CSubsetParser::Unary_expression_addopContext *ctx) = 0;

  virtual void enterUnary_expression_not(CSubsetParser::Unary_expression_notContext *ctx) = 0;
  virtual void exitUnary_expression_not(CSubsetParser::Unary_expression_notContext *ctx) = 0;

  virtual void enterUnary_expression_to_factor(CSubsetParser::Unary_expression_to_factorContext *ctx) = 0;
  virtual void exitUnary_expression_to_factor(CSubsetParser::Unary_expression_to_factorContext *ctx) = 0;

  virtual void enterFactor_to_variable(CSubsetParser::Factor_to_variableContext *ctx) = 0;
  virtual void exitFactor_to_variable(CSubsetParser::Factor_to_variableContext *ctx) = 0;

  virtual void enterFactor_function_call(CSubsetParser::Factor_function_callContext *ctx) = 0;
  virtual void exitFactor_function_call(CSubsetParser::Factor_function_callContext *ctx) = 0;

  virtual void enterFactor_parenthesized_expression(CSubsetParser::Factor_parenthesized_expressionContext *ctx) = 0;
  virtual void exitFactor_parenthesized_expression(CSubsetParser::Factor_parenthesized_expressionContext *ctx) = 0;

  virtual void enterFactor_const_int(CSubsetParser::Factor_const_intContext *ctx) = 0;
  virtual void exitFactor_const_int(CSubsetParser::Factor_const_intContext *ctx) = 0;

  virtual void enterFactor_const_float(CSubsetParser::Factor_const_floatContext *ctx) = 0;
  virtual void exitFactor_const_float(CSubsetParser::Factor_const_floatContext *ctx) = 0;

  virtual void enterFactor_post_increment(CSubsetParser::Factor_post_incrementContext *ctx) = 0;
  virtual void exitFactor_post_increment(CSubsetParser::Factor_post_incrementContext *ctx) = 0;

  virtual void enterFactor_post_decrement(CSubsetParser::Factor_post_decrementContext *ctx) = 0;
  virtual void exitFactor_post_decrement(CSubsetParser::Factor_post_decrementContext *ctx) = 0;

  virtual void enterArg_list_with_args(CSubsetParser::Arg_list_with_argsContext *ctx) = 0;
  virtual void exitArg_list_with_args(CSubsetParser::Arg_list_with_argsContext *ctx) = 0;

  virtual void enterArg_list_empty(CSubsetParser::Arg_list_emptyContext *ctx) = 0;
  virtual void exitArg_list_empty(CSubsetParser::Arg_list_emptyContext *ctx) = 0;

  virtual void enterMulti_arguments(CSubsetParser::Multi_argumentsContext *ctx) = 0;
  virtual void exitMulti_arguments(CSubsetParser::Multi_argumentsContext *ctx) = 0;

  virtual void enterSingle_argument(CSubsetParser::Single_argumentContext *ctx) = 0;
  virtual void exitSingle_argument(CSubsetParser::Single_argumentContext *ctx) = 0;


};

