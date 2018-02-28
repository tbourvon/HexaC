
// Generated from /Users/tbourvon/Drive/Projects/Programming/HexaC/grammar/HexaCParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "HexaCParser.h"


namespace HexaC {

/**
 * This interface defines an abstract listener for a parse tree produced by HexaCParser.
 */
class  HexaCParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(HexaCParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(HexaCParser::ProgramContext *ctx) = 0;

  virtual void enterToplevel_item(HexaCParser::Toplevel_itemContext *ctx) = 0;
  virtual void exitToplevel_item(HexaCParser::Toplevel_itemContext *ctx) = 0;

  virtual void enterPreproc_dir(HexaCParser::Preproc_dirContext *ctx) = 0;
  virtual void exitPreproc_dir(HexaCParser::Preproc_dirContext *ctx) = 0;

  virtual void enterDecl(HexaCParser::DeclContext *ctx) = 0;
  virtual void exitDecl(HexaCParser::DeclContext *ctx) = 0;

  virtual void enterFunc_decl(HexaCParser::Func_declContext *ctx) = 0;
  virtual void exitFunc_decl(HexaCParser::Func_declContext *ctx) = 0;

  virtual void enterType(HexaCParser::TypeContext *ctx) = 0;
  virtual void exitType(HexaCParser::TypeContext *ctx) = 0;

  virtual void enterParam_list(HexaCParser::Param_listContext *ctx) = 0;
  virtual void exitParam_list(HexaCParser::Param_listContext *ctx) = 0;

  virtual void enterParam(HexaCParser::ParamContext *ctx) = 0;
  virtual void exitParam(HexaCParser::ParamContext *ctx) = 0;

  virtual void enterBlock(HexaCParser::BlockContext *ctx) = 0;
  virtual void exitBlock(HexaCParser::BlockContext *ctx) = 0;

  virtual void enterStmt_list(HexaCParser::Stmt_listContext *ctx) = 0;
  virtual void exitStmt_list(HexaCParser::Stmt_listContext *ctx) = 0;

  virtual void enterStmt(HexaCParser::StmtContext *ctx) = 0;
  virtual void exitStmt(HexaCParser::StmtContext *ctx) = 0;

  virtual void enterVar_decl(HexaCParser::Var_declContext *ctx) = 0;
  virtual void exitVar_decl(HexaCParser::Var_declContext *ctx) = 0;

  virtual void enterExpr_stmt(HexaCParser::Expr_stmtContext *ctx) = 0;
  virtual void exitExpr_stmt(HexaCParser::Expr_stmtContext *ctx) = 0;

  virtual void enterExpr(HexaCParser::ExprContext *ctx) = 0;
  virtual void exitExpr(HexaCParser::ExprContext *ctx) = 0;

  virtual void enterExpr_lit(HexaCParser::Expr_litContext *ctx) = 0;
  virtual void exitExpr_lit(HexaCParser::Expr_litContext *ctx) = 0;

  virtual void enterCall_expr_(HexaCParser::Call_expr_Context *ctx) = 0;
  virtual void exitCall_expr_(HexaCParser::Call_expr_Context *ctx) = 0;

  virtual void enterArg_list(HexaCParser::Arg_listContext *ctx) = 0;
  virtual void exitArg_list(HexaCParser::Arg_listContext *ctx) = 0;

  virtual void enterUnary_op(HexaCParser::Unary_opContext *ctx) = 0;
  virtual void exitUnary_op(HexaCParser::Unary_opContext *ctx) = 0;

  virtual void enterBinary_op(HexaCParser::Binary_opContext *ctx) = 0;
  virtual void exitBinary_op(HexaCParser::Binary_opContext *ctx) = 0;

  virtual void enterIf_stmt(HexaCParser::If_stmtContext *ctx) = 0;
  virtual void exitIf_stmt(HexaCParser::If_stmtContext *ctx) = 0;

  virtual void enterWhile_stmt(HexaCParser::While_stmtContext *ctx) = 0;
  virtual void exitWhile_stmt(HexaCParser::While_stmtContext *ctx) = 0;


};

}  // namespace HexaC
