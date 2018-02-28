
// Generated from /Users/tbourvon/Drive/Projects/Programming/HexaC/grammar/HexaCParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "HexaCParser.h"


namespace HexaC {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by HexaCParser.
 */
class  HexaCParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by HexaCParser.
   */
    virtual antlrcpp::Any visitProgram(HexaCParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitToplevel_item(HexaCParser::Toplevel_itemContext *context) = 0;

    virtual antlrcpp::Any visitPreproc_dir(HexaCParser::Preproc_dirContext *context) = 0;

    virtual antlrcpp::Any visitDecl(HexaCParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitFunc_decl(HexaCParser::Func_declContext *context) = 0;

    virtual antlrcpp::Any visitType(HexaCParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitParam_list(HexaCParser::Param_listContext *context) = 0;

    virtual antlrcpp::Any visitParam(HexaCParser::ParamContext *context) = 0;

    virtual antlrcpp::Any visitBlock(HexaCParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStmt_list(HexaCParser::Stmt_listContext *context) = 0;

    virtual antlrcpp::Any visitStmt(HexaCParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitVar_decl(HexaCParser::Var_declContext *context) = 0;

    virtual antlrcpp::Any visitExpr_stmt(HexaCParser::Expr_stmtContext *context) = 0;

    virtual antlrcpp::Any visitExpr(HexaCParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitExpr_lit(HexaCParser::Expr_litContext *context) = 0;

    virtual antlrcpp::Any visitCall_expr_(HexaCParser::Call_expr_Context *context) = 0;

    virtual antlrcpp::Any visitArg_list(HexaCParser::Arg_listContext *context) = 0;

    virtual antlrcpp::Any visitUnary_op(HexaCParser::Unary_opContext *context) = 0;

    virtual antlrcpp::Any visitBinary_op(HexaCParser::Binary_opContext *context) = 0;

    virtual antlrcpp::Any visitIf_stmt(HexaCParser::If_stmtContext *context) = 0;

    virtual antlrcpp::Any visitWhile_stmt(HexaCParser::While_stmtContext *context) = 0;


};

}  // namespace HexaC
