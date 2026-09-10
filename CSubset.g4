grammar CSubset;
import Lexer;

start : program     #start_rule;

program
    : program unit       #program_to_program_unit
    | unit                #program_to_unit
    ;

unit
    : var_declaration     #unit_to_var_declaration
    | func_declaration    #unit_to_func_declaration
    | func_definition     #unit_to_func_definition
    ;

func_declaration
    : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  #func_declaration_with_param
    | type_specifier ID LPAREN RPAREN SEMICOLON                 #func_declaration_without_param
    ;

func_definition
    : type_specifier ID LPAREN parameter_list RPAREN compound_statement         #func_def_with_param
    | type_specifier ID LPAREN RPAREN compound_statement                        #func_def_without_param
    ;

parameter_list
    : parameter_list COMMA type_specifier ID        #multiple_param_with_id
    | parameter_list COMMA type_specifier           #multiple_param_without_id
    | type_specifier ID                             #single_param_with_id
    | type_specifier                                #single_param_without_id
    ;

compound_statement
    : LCURL statements RCURL                        #compound_with_statement
    | LCURL RCURL                                   #compound_without_statement
    ;

var_declaration
    : type_specifier declaration_list SEMICOLON         
    ;
    
type_specifier
    : INT       #IntType
    | FLOAT     #FloatType
    | VOID      #VoidType
    ;

declaration_list
    : declaration_list COMMA ID                             #MultiVarDecl
    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD     #MultiVarDeclWithArr
    | ID                                                    #SiglVarDecl
    | ID LTHIRD CONST_INT RTHIRD                            #SiglArrDecl
    | ID ASSIGNOP logic_expression                          #SiglVarDeclWithInit
    | declaration_list COMMA ID ASSIGNOP logic_expression   #MultiVarDeclWithInit
    ;

statements
    : statement                                             #single_statement
    | statements statement                                  #multiple_statement
    ;

statement
    : var_declaration                                           #var_declaration_statement
    | PRINTLN LPAREN ID RPAREN SEMICOLON                         #println_statement
    | expression_statement                                       #expression_statement_statement
    | compound_statement                                         #compound_statement_statement
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement      #for_statement
    | IF LPAREN expression RPAREN statement                     #if_statement
    | IF LPAREN expression RPAREN statement ELSE statement      #if_else_statement
    | WHILE LPAREN expression RPAREN statement                  #while_statement
    | RETURN expression SEMICOLON                               #return_statement
    ;

expression_statement
    : SEMICOLON                         #expression_statement_to_semicolon
    | expression SEMICOLON              #expression_statement_to_expression_semicolon
    ;

variable
    : ID                                #SimpleVar
    | ID LTHIRD expression RTHIRD       #ArrVar
    ;

expression
    : logic_expression                                           #expression_to_logic_expression
    | variable ASSIGNOP logic_expression                         #expression_to_logic_expression_with_assignop
    | variable COMPOUND_ASSIGNOP   logic_expression              #expression_to_logic_expression_with_compound_assignop
    ;

logic_expression
    : rel_expression                                            #logic_to_rel_expression_simple
    | rel_expression LOGICOP rel_expression                     #logic_to_rel_expression_complex
    ;

rel_expression
    : simple_expression                                         #rel_expression_simple_expresssion_simple
    | simple_expression RELOP simple_expression                 #rel_expression_simple_expresssion_complex
    ;

simple_expression
    : term                              #simple_expression_to_term
    | simple_expression ADDOP term      #simple_expression_to_term_with_plus
    ;

term
    : unary_expression                  #term_unary_expression
    | term MULOP unary_expression       #term_times_unary_expression
    ;

unary_expression
    : ADDOP unary_expression                    #unary_expression_addop
    | NOT unary_expression                      #unary_expression_not
    | factor                                    #unary_expression_to_factor
    ;

factor
    : variable                                  #factor_to_variable
    | ID LPAREN argument_list RPAREN            #factor_function_call
    | LPAREN expression RPAREN                  #factor_parenthesized_expression
    | CONST_INT                                 #factor_const_int
    | CONST_FLOAT                               #factor_const_float
    | variable INCOP                            #factor_post_increment
    | variable DECOP                            #factor_post_decrement
    ;


argument_list
    : arguments #arg_list_with_args
    |           #arg_list_empty
    ;

arguments
    : arguments COMMA logic_expression #multi_arguments
    | logic_expression                #single_argument
    ;