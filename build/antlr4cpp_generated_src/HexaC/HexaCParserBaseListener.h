
// Generated from /Users/tbourvon/Drive/Projects/Programming/HexaC/grammar/HexaCParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "HexaCParserListener.h"


namespace HexaC {

/**
 * This class provides an empty implementation of HexaCParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  HexaCParserBaseListener : public HexaCParserListener {
public:

  virtual void enterProgram(HexaCParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(HexaCParser::ProgramContext * /*ctx*/) override { }

  virtual void enterToplevel_item(HexaCParser::Toplevel_itemContext * /*ctx*/) override { }
  virtual void exitToplevel_item(HexaCParser::Toplevel_itemContext * /*ctx*/) override { }

  virtual void enterPreproc_dir(HexaCParser::Preproc_dirContext * /*ctx*/) override { }
  virtual void exitPreproc_dir(HexaCParser::Preproc_dirContext * /*ctx*/) override { }

  virtual void enterDecl(HexaCParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(HexaCParser::DeclContext * /*ctx*/) override { }

  virtual void enterFunc_decl(HexaCParser::Func_declContext * /*ctx*/) override { }
  virtual void exitFunc_decl(HexaCParser::Func_declContext * /*ctx*/) override { }

  virtual void enterType(HexaCParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(HexaCParser::TypeContext * /*ctx*/) override { }

  virtual void enterParam_list(HexaCParser::Param_listContext * /*ctx*/) override { }
  virtual void exitParam_list(HexaCParser::Param_listContext * /*ctx*/) override { }

  virtual void enterParam(HexaCParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(HexaCParser::ParamContext * /*ctx*/) override { }

  virtual void enterBlock(HexaCParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(HexaCParser::BlockContext * /*ctx*/) override { }

  virtual void enterStmt_list(HexaCParser::Stmt_listContext * /*ctx*/) override { }
  virtual void exitStmt_list(HexaCParser::Stmt_listContext * /*ctx*/) override { }

  virtual void enterStmt(HexaCParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(HexaCParser::StmtContext * /*ctx*/) override { }

  virtual void enterVar_decl(HexaCParser::Var_declContext * /*ctx*/) override { }
  virtual void exitVar_decl(HexaCParser::Var_declContext * /*ctx*/) override { }

  virtual void enterExpr_stmt(HexaCParser::Expr_stmtContext * /*ctx*/) override { }
  virtual void exitExpr_stmt(HexaCParser::Expr_stmtContext * /*ctx*/) override { }

  virtual void enterExpr(HexaCParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(HexaCParser::ExprContext * /*ctx*/) override { }

  virtual void enterExpr_lit(HexaCParser::Expr_litContext * /*ctx*/) override { }
  virtual void exitExpr_lit(HexaCParser::Expr_litContext * /*ctx*/) override { }

  virtual void enterCall_expr_(HexaCParser::Call_expr_Context * /*ctx*/) override { }
  virtual void exitCall_expr_(HexaCParser::Call_expr_Context * /*ctx*/) override { }

  virtual void enterArg_list(HexaCParser::Arg_listContext * /*ctx*/) override { }
  virtual void exitArg_list(HexaCParser::Arg_listContext * /*ctx*/) override { }

  virtual void enterUnary_op(HexaCParser::Unary_opContext * /*ctx*/) override { }
  virtual void exitUnary_op(HexaCParser::Unary_opContext * /*ctx*/) override { }

  virtual void enterBinary_op(HexaCParser::Binary_opContext * /*ctx*/) override { }
  virtual void exitBinary_op(HexaCParser::Binary_opContext * /*ctx*/) override { }

  virtual void enterIf_stmt(HexaCParser::If_stmtContext * /*ctx*/) override { }
  virtual void exitIf_stmt(HexaCParser::If_stmtContext * /*ctx*/) override { }

  virtual void enterWhile_stmt(HexaCParser::While_stmtContext * /*ctx*/) override { }
  virtual void exitWhile_stmt(HexaCParser::While_stmtContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace HexaC
