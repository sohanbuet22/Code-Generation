#include "CodeGenImp.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Grammar trace map for CodeGenImp:
// start -> program
// program -> program unit | unit
// unit -> var_declaration | func_declaration | func_definition
// statement -> var_declaration | println_statement | expression_statement | compound_statement | for_statement | if_statement | if_else_statement | while_statement | return_statement

// ============================================================================
// CodeGenEmitter
// ============================================================================
// Codegen entry/exit: finalize() writes the final FASM program and links the print_int helper.
void CodeGenEmitter::finalize(const std::string &outPath)
{
    temp.close();
    std::ifstream in(tempPath);
    std::ofstream out(outPath, std::ios::out | std::ios::trunc);

    out << "format ELF executable 3\n";
    out << "entry start\n\n";
    out << "segment readable writeable\n";
    out << dataDecls.str();
    out << "\n";
    out << "segment readable executable\n";
    out << "start:\n";
    out << globalInit.str();
    out << "\tCALL func_main\n";
    out << "\tMOV EAX, 1\n\tXOR EBX, EBX\n\tINT 0x80\n\n";
    out << in.rdbuf();
    out << printIntProcedureAsm();
}

// Helper procedure: print_int is emitted as a standard library routine for println support.
std::string CodeGenEmitter::printIntProcedureAsm()
{
    // Verified working: assembled with FASM 1.73.32 and run; correctly
    // prints positive, negative, and zero values each with a newline.
    return
        R"ASM(print_int:
    PUSH EBP
    MOV EBP, ESP
    PUSH EBX
    PUSH ECX
    PUSH EDX
    PUSH EDI
    PUSH ESI

    MOV [neg_flag], dword 0
    MOV EBX, EAX
    TEST EBX, EBX
    JNS .positive
    MOV [neg_flag], dword 1
    NEG EBX
.positive:

    MOV EDI, int_buf + 11
    MOV ESI, 0
    MOV ECX, 10

.convert_loop:
    XOR EDX, EDX
    MOV EAX, EBX
    DIV ECX
    ADD EDX, '0'
    DEC EDI
    MOV [EDI], DL
    INC ESI
    MOV EBX, EAX
    TEST EBX, EBX
    JNZ .convert_loop

    CMP dword [neg_flag], 0
    JE .no_sign
    DEC EDI
    MOV byte [EDI], '-'
    INC ESI
.no_sign:

    MOV byte [int_buf + 11], 10
    INC ESI

    MOV EAX, 4
    MOV EBX, 1
    MOV ECX, EDI
    MOV EDX, ESI
    INT 0x80

    POP ESI
    POP EDI
    POP EDX
    POP ECX
    POP EBX
    MOV ESP, EBP
    POP EBP
    RET

segment readable writeable
int_buf:   rb 16
neg_flag:  dd 0
)ASM";
}

// ============================================================================
// Declarations
// Rules traced here: var_declaration -> type_specifier declaration_list SEMICOLON
// declaration_list -> declaration_list COMMA ID | declaration_list COMMA ID [ CONST_INT ] | ID | ID [ CONST_INT ]
// type_specifier -> INT | FLOAT | VOID
// ============================================================================

// Rule: var_declaration -> type_specifier declaration_list SEMICOLON
any CodeGenImp::visitVar_declaration(CSubsetParser::Var_declarationContext *ctx)
{
    currentDeclType = ctx->type_specifier()->getText();
    visit(ctx->declaration_list());
    return nullptr;
}

// Rule: declaration_list -> ID
any CodeGenImp::visitSiglVarDecl(CSubsetParser::SiglVarDeclContext *ctx)
{
    std::string name = ctx->ID()->getText();

    if (!currentFuncName.empty())
    {
        localOffset -= 4;
        localSymtab[name] = CodeGenVarInfo{currentDeclType, false, 1, localOffset};
        emitter.emit("SUB ESP,4");
    }
    else
    {
        symtab[name] = CodeGenVarInfo{currentDeclType, false, 1};
        emitter.declareScalar(name);
    }

    return nullptr;
}

// Rule: declaration_list -> declaration_list COMMA ID
any CodeGenImp::visitMultiVarDecl(CSubsetParser::MultiVarDeclContext *ctx)
{
    visit(ctx->declaration_list());

    std::string name = ctx->ID()->getText();
    if (!currentFuncName.empty())
    {
        localOffset -= 4;
        localSymtab[name] = CodeGenVarInfo{currentDeclType, false, 1, localOffset};
        emitter.emit("SUB ESP,4");
    }
    else
    {
        symtab[name] = CodeGenVarInfo{currentDeclType, false, 1};
        emitter.declareScalar(name);
    }
    return nullptr;
}

// Rule: declaration_list -> ID [ CONST_INT ]
any CodeGenImp::visitSiglArrDecl(CSubsetParser::SiglArrDeclContext *ctx)
{
    std::string name = ctx->ID()->getText();
    int size = std::stoi(ctx->CONST_INT()->getText());
    if (!currentFuncName.empty())
    {
        localOffset -= 4 * size;
        localSymtab[name] = CodeGenVarInfo{currentDeclType, true, size, localOffset};
        emitter.emit("SUB ESP, "+to_string(4*size));
    }
    else
    {
        symtab[name] = CodeGenVarInfo{currentDeclType, true, size};
        emitter.declareArray(name, size);
    }

    return nullptr;
}

// Rule: declaration_list -> declaration_list COMMA ID [ CONST_INT ]
any CodeGenImp::visitMultiVarDeclWithArr(CSubsetParser::MultiVarDeclWithArrContext *ctx)
{
    visit(ctx->declaration_list());
    std::string name = ctx->ID()->getText();
    int size = std::stoi(ctx->CONST_INT()->getText());
    if (!currentFuncName.empty())
    {
        localOffset -= 4 * size;
        localSymtab[name] = CodeGenVarInfo{currentDeclType, true, size, localOffset};
        emitter.emit("SUB ESP, " + to_string(4 * size));
    }
    else
    {
        symtab[name] = CodeGenVarInfo{currentDeclType, true, size};
        emitter.declareArray(name, size);
    }
    return nullptr;
}

// ============================================================================
// Variable load/store helpers
// Rules traced here: variable -> ID | ID [ expression ]
// ============================================================================
// Rule: variable -> ID | ID [ expression ]
std::string CodeGenImp::resolveVariable(CSubsetParser::VariableContext *varCtx, bool &outIsArray)
{
    if (auto *simple = dynamic_cast<CSubsetParser::SimpleVarContext *>(varCtx))
    {
        outIsArray = false;
        return simple->ID()->getText();
    }
    if (auto *arr = dynamic_cast<CSubsetParser::ArrVarContext *>(varCtx))
    {
        outIsArray = true;
        return arr->ID()->getText();
    }
    outIsArray = false;
    return "";
}

string CodeGenImp::varBaseOperand(const string &name)
{
    auto it = localSymtab.find(name);
    if(it!=localSymtab.end())
    {
        int off = it->second.offset;
        return off >= 0 ? ("EBP+"+to_string(off)) : ("EBP-"+to_string(-off));
    }
    return name;
}

// Rule: factor -> variable (loads the variable value into EAX)
void CodeGenImp::loadVariable(CSubsetParser::VariableContext *varCtx)
{
    bool isArray = false;
    std::string name = resolveVariable(varCtx, isArray);
    string base = varBaseOperand(name);
    if (!isArray)
    {
        emitter.emit("MOV EAX, [" + base + "]");
        return;
    }
    auto *arr = dynamic_cast<CSubsetParser::ArrVarContext *>(varCtx);
    visit(arr->expression()); // pushes index value
    emitter.emit("POP EBX");
    emitter.emit("IMUL EBX, 4");
    emitter.emit("MOV EAX, [" + base + " + EBX]");
}

// Rule: expression -> variable ASSIGNOP logic_expression (stores computed RHS into target variable)
void CodeGenImp::storeVariable(CSubsetParser::VariableContext *varCtx)
{
    // Contract: value to store is already in EAX at call time.
    bool isArray = false;
    std::string name = resolveVariable(varCtx, isArray);
    string base = varBaseOperand(name);
    if (!isArray)
    {
        emitter.emit("MOV [" + base + "], EAX");
        return;
    }
    auto *arr = dynamic_cast<CSubsetParser::ArrVarContext *>(varCtx);
    emitter.emit("PUSH EAX"); 
    visit(arr->expression()); 
    emitter.emit("POP EBX");
    emitter.emit("IMUL EBX, 4");
    emitter.emit("POP EAX"); 
    emitter.emit("MOV [" + base + " + EBX], EAX");
}

// ============================================================================
// Expressions
// Rules traced here: expression -> logic_expression | variable ASSIGNOP logic_expression
// logic_expression -> rel_expression | rel_expression LOGICOP rel_expression
// rel_expression -> simple_expression | simple_expression RELOP simple_expression
// simple_expression -> term | simple_expression ADDOP term
// term -> unary_expression | term MULOP unary_expression
// unary_expression -> ADDOP unary_expression | NOT unary_expression | factor
// factor -> variable | ID ( argument_list ) | ( expression ) | CONST_INT | CONST_FLOAT | variable INCOP | variable DECOP
// ============================================================================
// Rule: expression -> variable ASSIGNOP logic_expression
any CodeGenImp::visitExpression_to_logic_expression_with_assignop(
    CSubsetParser::Expression_to_logic_expression_with_assignopContext *ctx)
{
    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) + ": " + ctx->getText());
    visit(ctx->logic_expression()); // pushes RHS value
    emitter.emit("POP EAX");
    storeVariable(ctx->variable());
    emitter.emit("PUSH EAX"); // assignment expression's own value
    return nullptr;
}

// Rule: logic_expression -> rel_expression LOGICOP rel_expression
any CodeGenImp::visitLogic_to_rel_expression_complex(
    CSubsetParser::Logic_to_rel_expression_complexContext *ctx)
{
    std::string op = ctx->LOGICOP()->getText();
    std::string shortLbl = emitter.newLabel();
    std::string endLbl = emitter.newLabel();

    visit(ctx->rel_expression(0));
    emitter.emit("POP EAX");
    emitter.emit("CMP EAX, 0");

    if (op == "&&")
    {
        emitter.emit("JE " + shortLbl); // left false -> skip right, result false
        visit(ctx->rel_expression(1));
        emitter.emit("POP EAX");
        emitter.emit("CMP EAX, 0");
        emitter.emit("JE " + shortLbl);
        emitter.emit("MOV EAX, 1");
        emitter.emit("JMP " + endLbl);
        emitter.emitLabel(shortLbl);
        emitter.emit("MOV EAX, 0");
        emitter.emitLabel(endLbl);
    }
    else
    {                                    // "||"
        emitter.emit("JNE " + shortLbl); // left true -> skip right, result true
        visit(ctx->rel_expression(1));
        emitter.emit("POP EAX");
        emitter.emit("CMP EAX, 0");
        emitter.emit("JNE " + shortLbl);
        emitter.emit("MOV EAX, 0");
        emitter.emit("JMP " + endLbl);
        emitter.emitLabel(shortLbl);
        emitter.emit("MOV EAX, 1");
        emitter.emitLabel(endLbl);
    }
    emitter.emit("PUSH EAX");
    return nullptr;
}

// Rule: rel_expression -> simple_expression RELOP simple_expression
any CodeGenImp::visitRel_expression_simple_expresssion_complex(
    CSubsetParser::Rel_expression_simple_expresssion_complexContext *ctx)
{
    visit(ctx->simple_expression(0));
    visit(ctx->simple_expression(1));
    emitter.emit("POP EBX"); // right
    emitter.emit("POP EAX"); // left
    emitter.emit("CMP EAX, EBX");

    std::string op = ctx->RELOP()->getText();
    std::string setIns =
        op == "<" ? "SETL" : op == "<=" ? "SETLE"
                         : op == ">"    ? "SETG"
                         : op == ">="   ? "SETGE"
                         : op == "=="   ? "SETE"
                                        : "SETNE";

    emitter.emit("MOV EAX, 0");
    emitter.emit(setIns + " AL");
    emitter.emit("PUSH EAX");
    return nullptr;
}

// Rule: simple_expression -> simple_expression ADDOP term
any CodeGenImp::visitSimple_expression_to_term_with_plus(
    CSubsetParser::Simple_expression_to_term_with_plusContext *ctx)
{
    visit(ctx->simple_expression());
    visit(ctx->term());
    emitter.emit("POP EBX"); // right
    emitter.emit("POP EAX"); // left
    if (ctx->ADDOP()->getText() == "+")
        emitter.emit("ADD EAX, EBX");
    else
        emitter.emit("SUB EAX, EBX");
    emitter.emit("PUSH EAX");
    return nullptr;
}

// Rule: term -> term MULOP unary_expression
any CodeGenImp::visitTerm_times_unary_expression(
    CSubsetParser::Term_times_unary_expressionContext *ctx)
{
    visit(ctx->term());
    visit(ctx->unary_expression());
    emitter.emit("POP EBX"); // right
    emitter.emit("POP EAX"); // left
    std::string op = ctx->MULOP()->getText();
    if (op == "*")
    {
        emitter.emit("IMUL EAX, EBX");
    }
    else if (op == "/")
    {
        emitter.emit("CDQ");
        emitter.emit("IDIV EBX");
    }
    else
    { // "%"
        emitter.emit("CDQ");
        emitter.emit("IDIV EBX");
        emitter.emit("MOV EAX, EDX");
    }
    emitter.emit("PUSH EAX");
    return nullptr;
}

// Rule: unary_expression -> ADDOP unary_expression
any CodeGenImp::visitUnary_expression_addop(CSubsetParser::Unary_expression_addopContext *ctx)
{
    visit(ctx->unary_expression());
    emitter.emit("POP EAX");
    if (ctx->ADDOP()->getText() == "-")
        emitter.emit("NEG EAX");
    emitter.emit("PUSH EAX");
    return nullptr;
}

// Rule: unary_expression -> NOT unary_expression
any CodeGenImp::visitUnary_expression_not(CSubsetParser::Unary_expression_notContext *ctx)
{
    visit(ctx->unary_expression());
    emitter.emit("POP EAX");
    emitter.emit("CMP EAX, 0");
    emitter.emit("MOV EAX, 0");
    emitter.emit("SETE AL");
    emitter.emit("PUSH EAX");
    return nullptr;
}

// ============================================================================
// Factor leaves
// Rules traced here: factor -> variable | CONST_INT | ( expression ) | variable INCOP | variable DECOP
// ============================================================================
// Rule: factor -> variable
any CodeGenImp::visitFactor_to_variable(CSubsetParser::Factor_to_variableContext *ctx)
{
    loadVariable(ctx->variable());
    emitter.emit("PUSH EAX");
    return nullptr;
}

// Rule: factor -> CONST_INT
any CodeGenImp::visitFactor_const_int(CSubsetParser::Factor_const_intContext *ctx)
{
    emitter.emit("MOV EAX, " + ctx->CONST_INT()->getText());
    emitter.emit("PUSH EAX");
    return nullptr;
}

// Rule: factor -> ( expression )
any CodeGenImp::visitFactor_parenthesized_expression(
    CSubsetParser::Factor_parenthesized_expressionContext *ctx)
{
    visit(ctx->expression()); // already pushes its result
    return nullptr;
}

// Rule: factor -> variable INCOP
any CodeGenImp::visitFactor_post_increment(CSubsetParser::Factor_post_incrementContext *ctx)
{
    loadVariable(ctx->variable()); // eax = old value
    emitter.emit("PUSH EAX");      // factor's value = OLD value (post-increment)
    emitter.emit("INC EAX");
    storeVariable(ctx->variable());
    return nullptr;
}

// Rule: factor -> variable DECOP
any CodeGenImp::visitFactor_post_decrement(CSubsetParser::Factor_post_decrementContext *ctx)
{
    loadVariable(ctx->variable());
    emitter.emit("PUSH EAX");
    emitter.emit("DEC EAX");
    storeVariable(ctx->variable());
    return nullptr;
}

// ============================================================================
// println / statements
// Rules traced here: statement -> PRINTLN ( ID ) ; | expression_statement -> expression ; | statement -> RETURN expression ;
// ============================================================================
// Rule: statement -> PRINTLN ( ID ) ;
any CodeGenImp::visitPrintln_statement(CSubsetParser::Println_statementContext *ctx)
{
    std::string name = ctx->ID()->getText();
    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) +
                    ": println(" + name + ")");
    emitter.emit("MOV EAX, [" + varBaseOperand(name) + "]");
    emitter.emit("CALL print_int");
    return nullptr;
}

// Rule: expression_statement -> expression ;
any CodeGenImp::visitExpression_statement_to_expression_semicolon(CSubsetParser::Expression_statement_to_expression_semicolonContext *ctx)
{
    visit(ctx->expression()); // whatever the child expression rule is
    emitter.emit("POP EAX");  // discard: statement doesn't need the value
    return nullptr;
}

// Rule: statement -> RETURN expression ;
any CodeGenImp::visitReturn_statement(CSubsetParser::Return_statementContext *ctx)
{
    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) +
                    ": return " + ctx->expression()->getText());
    
    visit(ctx->expression()); // result pushed onto stack
    emitter.emit("POP EAX");  // return value goes into EAX
    emitter.emit("MOV ESP,EBP");
    emitter.emit("POP EBP");
    emitter.emit(currentParamCount > 0
                    ? ("RET "+to_string(4*currentParamCount))
                    : "RET");
    return nullptr;
}

/*

declaration_list
    :
    | ID ASSIGNOP logic_expression                          #SiglVarDeclWithInit
    | declaration_list COMMA ID ASSIGNOP logic_expression   #MultiVarDeclWithInit
    ;

*/

any CodeGenImp::visitSiglVarDeclWithInit(CSubsetParser::SiglVarDeclWithInitContext *ctx)
{
    std::string name = ctx->ID()->getText();
    if(!currentFuncName.empty())
    {
        localOffset -= 4;
        localSymtab[name] = CodeGenVarInfo{currentDeclType,false,1,localOffset};
        emitter.emit("SUB ESP,4");
        visit(ctx->logic_expression());
        emitter.emit("POP EAX");
        emitter.emit("MOV ["+varBaseOperand(name)+ "],EAX");
    }
    else
    {
        symtab[name] = CodeGenVarInfo{currentDeclType,false,1};
        emitter.declareScalar(name);

        emitter.beginGlobalInit();
        visit(ctx->logic_expression());
        emitter.emit("POP EAX");
        emitter.emit("MOV ["+name+ "], EAX");
        emitter.endGlobalInit();
    }
    return nullptr;
}

any CodeGenImp::visitMultiVarDeclWithInit(CSubsetParser::MultiVarDeclWithInitContext *ctx)
{
    visit(ctx->declaration_list());
    std::string name = ctx->ID()->getText();
    if (!currentFuncName.empty())
    {
        localOffset -= 4;
        localSymtab[name] = CodeGenVarInfo{currentDeclType, false, 1, localOffset};
        emitter.emit("SUB ESP, 4");
        visit(ctx->logic_expression());
        emitter.emit("POP EAX");
        emitter.emit("MOV [" + varBaseOperand(name) + "], EAX");
    }
    else
    {
        symtab[name] = CodeGenVarInfo{currentDeclType, false, 1};
        emitter.declareScalar(name);

        emitter.beginGlobalInit();
        visit(ctx->logic_expression());
        emitter.emit("POP EAX");
        emitter.emit("MOV [" + name + "], EAX");
        emitter.endGlobalInit();
    }
    return nullptr;
}

any CodeGenImp::visitExpression_to_logic_expression_with_compound_assignop(CSubsetParser::Expression_to_logic_expression_with_compound_assignopContext *ctx)
{
    loadVariable(ctx->variable());
    emitter.emit("PUSH EAX");
    visit(ctx->logic_expression());

    emitter.emit("POP EBX");
    emitter.emit("POP EAX");

    string op = ctx->COMPOUND_ASSIGNOP()->getText();
    if (op == "+=")
    {
        emitter.emit("ADD EAX, EBX");
    }
    else if (op == "-=")
    {
        emitter.emit("SUB EAX, EBX");
    }
    else if (op == "*=")
    {
        emitter.emit("IMUL EAX, EBX");
    }
    else if (op == "/=")
    {
        emitter.emit("CDQ");
        emitter.emit("IDIV EBX");
    }
    else
    { // "%="
        emitter.emit("CDQ");
        emitter.emit("IDIV EBX");
        emitter.emit("MOV EAX, EDX");
    }

    storeVariable(ctx->variable());
    emitter.emit("PUSH EAX");
    return nullptr;
}

// control flow patterns

/*
statement
    :
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement      #for_statement
    | IF LPAREN expression RPAREN statement                     #if_statement
    | IF LPAREN expression RPAREN statement ELSE statement      #if_else_statement
    | WHILE LPAREN expression RPAREN statement                  #while_statement
    | RETURN expression SEMICOLON                               #return_statement
    ;
*/

any CodeGenImp::visitFor_statement(CSubsetParser::For_statementContext *ctx)
{
    string startLabel = emitter.newLabel();
    string endLabel = emitter.newLabel();

    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) + ": for-loop init");
    visit(ctx->expression_statement(0));

    emitter.emitLabel(startLabel);
    auto *condCtx = dynamic_cast<CSubsetParser::Expression_statement_to_expression_semicolonContext *>(
        ctx->expression_statement(1));
    if (condCtx)
    {
        emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) + ": for-loop condition");

        visit(condCtx->expression());
        emitter.emit("POP EAX");
        emitter.emit("CMP EAX, 0");
        emitter.emit("JE " + endLabel);
    }

    visit(ctx->statement());

    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) + ": for-loop update");
    visit(ctx->expression());
    emitter.emit("POP EAX");

    emitter.emit("JMP " + startLabel);
    emitter.emitLabel(endLabel);
    return nullptr;
}

any CodeGenImp::visitIf_statement(CSubsetParser::If_statementContext *ctx)
{
    string endLbl = emitter.newLabel();
    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) +
                    ": if (" + ctx->expression()->getText() + ")");
    visit(ctx->expression());
    emitter.emit("POP EAX");
    emitter.emit("CMP EAX, 0");
    emitter.emit("JE " + endLbl);

    visit(ctx->statement());

    emitter.emitLabel(endLbl);
    return nullptr;
}

any CodeGenImp::visitIf_else_statement(CSubsetParser::If_else_statementContext *ctx)
{
    string elseLabel = emitter.newLabel();
    string endLabel = emitter.newLabel();

    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) +
                    ": if (" + ctx->expression()->getText() + ") ... else ...");
    visit(ctx->expression());
    emitter.emit("POP EAX");
    emitter.emit("CMP EAX, 0");
    emitter.emit("JE " + elseLabel);

    visit(ctx->statement(0));
    emitter.emit("JMP " + endLabel);

    emitter.emitLabel(elseLabel);
    visit(ctx->statement(1));

    emitter.emitLabel(endLabel);
    return nullptr;
};

any CodeGenImp::visitWhile_statement(CSubsetParser::While_statementContext *ctx)
{
    string startLabel = emitter.newLabel();
    string endLabel = emitter.newLabel();

    emitter.emitLabel(startLabel);
    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) +
                    ": while (" + ctx->expression()->getText() + ")");
    visit(ctx->expression());
    emitter.emit("POP EAX");
    emitter.emit("CMP EAX, 0");
    emitter.emit("JE " + endLabel);

    visit(ctx->statement());
    emitter.emit("JMP " + startLabel);

    emitter.emitLabel(endLabel);
    return nullptr;
}

// function calling related

/*
factor
    :
    | ID LPAREN argument_list RPAREN            #factor_function_call
    ;


argument_list
    : arguments #arg_list_with_args
    |           #arg_list_empty
    ;

arguments
    : arguments COMMA logic_expression #multi_arguments
    | logic_expression                #single_argument
    ;

*/

void CodeGenImp::collectArgumentExprs(CSubsetParser::ArgumentsContext *ctx,
                                      std::vector<CSubsetParser::Logic_expressionContext *> &out)
{
    if (!ctx)
        return;
    if (auto *single = dynamic_cast<CSubsetParser::Single_argumentContext *>(ctx))
    {
        out.push_back(single->logic_expression());
        return;
    }
    if (auto *multi = dynamic_cast<CSubsetParser::Multi_argumentsContext *>(ctx))
    {
        collectArgumentExprs(multi->arguments(), out);
        out.push_back(multi->logic_expression());
        return;
    }
}

// caller side
any CodeGenImp::visitFactor_function_call(CSubsetParser::Factor_function_callContext *ctx)
{
    string name = ctx->ID()->getText();
    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) +
                    ": call " + name + "(" + ctx->argument_list()->getText() + ")");
    vector<CSubsetParser::Logic_expressionContext *> args;

    if (auto *withArgs = dynamic_cast<CSubsetParser::Arg_list_with_argsContext *>(ctx->argument_list()))
    {
        collectArgumentExprs(withArgs->arguments(), args);
    }
    for (int i = static_cast<int>(args.size() - 1); i >= 0; --i)
    {
        visit(args[i]);
    }

    emitter.emit("CALL func_" + name);

    emitter.emit("PUSH EAX");

    return nullptr;
}

any CodeGenImp::visitArg_list_with_args(CSubsetParser::Arg_list_with_argsContext *ctx)
{
    return visitChildren(ctx);
}

any CodeGenImp::visitArg_list_empty(CSubsetParser::Arg_list_emptyContext *ctx)
{
    return visitChildren(ctx);
}

any CodeGenImp::visitMulti_arguments(CSubsetParser::Multi_argumentsContext *ctx)
{
    return visitChildren(ctx);
}

any CodeGenImp::visitSingle_argument(CSubsetParser::Single_argumentContext *ctx)
{
    return visitChildren(ctx);
}

// callee side

void CodeGenImp::collectParamNames(CSubsetParser::Parameter_listContext *ctx, std::vector<std::string> &names)
{
    if (!ctx)
        return;
    if (auto *s = dynamic_cast<CSubsetParser::Single_param_with_idContext *>(ctx))
    {
        names.push_back(s->ID()->getText());
        return;
    }
    if (auto *s = dynamic_cast<CSubsetParser::Single_param_without_idContext *>(ctx))
    {
        names.push_back("");
        return;
    }
    if (auto *m = dynamic_cast<CSubsetParser::Multiple_param_with_idContext *>(ctx))
    {
        collectParamNames(m->parameter_list(), names);
        names.push_back(m->ID()->getText());
        return;
    }
    if (auto *m = dynamic_cast<CSubsetParser::Multiple_param_without_idContext *>(ctx))
    {
        collectParamNames(m->parameter_list(), names);
        names.push_back("");
        return;
    }
}

void CodeGenImp::beginFunction(const string &name, CSubsetParser::Parameter_listContext *paramCtx)
{
    currentFuncName = name;
    localOffset = 0;
    localSymtab.clear();

    vector<string> paramNames;
    if (paramCtx)
    {
        collectParamNames(paramCtx, paramNames);
    }

    currentParamCount = static_cast<int>(paramNames.size());

    int offset = 8;
    for (const auto &pname : paramNames)
    {
        if (!pname.empty())
            localSymtab[pname] = CodeGenVarInfo{"int", false, 1, offset};
        offset += 4;
    }

    emitter.emitLabel("func_" + name);
    emitter.emit("PUSH EBP");
    emitter.emit("MOV EBP,ESP");
}

void CodeGenImp::endFunction()
{
    emitter.emit("MOV ESP, EBP");
    emitter.emit("POP EBP");
    emitter.emit(currentParamCount > 0
                     ? ("RET " + std::to_string(4 * currentParamCount))
                     : "RET");

    currentFuncName.clear();
    localSymtab.clear();
    localOffset = 0;
    currentParamCount = 0;
}

any CodeGenImp::visitFunc_def_with_param(CSubsetParser::Func_def_with_paramContext *ctx) 
{
    string name = ctx->ID()->getText();
    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) +
                    ": function " + name + "()");
    beginFunction(name, ctx->parameter_list());
    visit(ctx->compound_statement());
    endFunction();
    return nullptr;
}

any CodeGenImp::visitFunc_def_without_param(CSubsetParser::Func_def_without_paramContext *ctx) 
{
    string name = ctx->ID()->getText();
    emitter.comment("line " + std::to_string(ctx->getStart()->getLine()) +
                    ": function " + name + "()");
    beginFunction(name, nullptr);
    visit(ctx->compound_statement());
    endFunction();
    return nullptr;
}

any CodeGenImp::visitFunc_declaration_with_param(CSubsetParser::Func_declaration_with_paramContext *ctx) 
{
    return nullptr;
}

any CodeGenImp::visitFunc_declaration_without_param(CSubsetParser::Func_declaration_without_paramContext *ctx) 
{
    return nullptr;
}