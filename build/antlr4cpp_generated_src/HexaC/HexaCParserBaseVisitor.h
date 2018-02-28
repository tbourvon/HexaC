
// Generated from /Users/tbourvon/Drive/Projects/Programming/HexaC/grammar/HexaCParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "HexaCParserVisitor.h"


namespace HexaC {

/**
 * This class provides an empty implementation of HexaCParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  HexaCParserBaseVisitor : public HexaCParserVisitor {
public:

  virtual antlrcpp::Any visitProgram(HexaCParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToplevel_item(HexaCParser::Toplevel_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreproc_dir(HexaCParser::Preproc_dirContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl(HexaCParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_decl(HexaCParser::Func_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(HexaCParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam_list(HexaCParser::Param_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam(HexaCParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(HexaCParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt_list(HexaCParser::Stmt_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(HexaCParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_decl(HexaCParser::Var_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_stmt(HexaCParser::Expr_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(HexaCParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_lit(HexaCParser::Expr_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall_expr_(HexaCParser::Call_expr_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArg_list(HexaCParser::Arg_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_op(HexaCParser::Unary_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_op(HexaCParser::Binary_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_stmt(HexaCParser::If_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_stmt(HexaCParser::While_stmtContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace HexaC
