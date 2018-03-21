#ifndef ASTGENERATOR_H
#define ASTGENERATOR_H

#include <HexaCParserBaseVisitor.h>
#include "ast.h"


using namespace HexaC;

class ASTGenerator : public HexaCParserBaseVisitor
{
public:
    ASTGenerator();

    virtual antlrcpp::Any visitProgram(HexaCParser::ProgramContext *ctx) override {
      std::vector<Decl*> decls;
      for (HexaCParser::Toplevel_itemContext* top_level_ctx : ctx->toplevel_item()) {
          if (HexaCParser::DeclContext *decl_ctx = top_level_ctx->decl()) {
              decls.push_back((Decl*)visit(decl_ctx));
          }
      }

      return new Program(decls);
    }

    virtual antlrcpp::Any visitStmt(HexaCParser::StmtContext *ctx) override {
        if(HexaCParser::BlockContext *block_ctx = ctx->block()){
            return (Stmt*)visit(ctx->block());
        }
        else if(HexaCParser::If_stmtContext *if_ctx = ctx->if_stmt()){
            return (Stmt*)visit(ctx->if_stmt());
        }
        else if(HexaCParser::While_stmtContext *while_ctx = ctx->while_stmt()){
            return (Stmt*)visit(ctx->while_stmt());
        }
        else if(HexaCParser::Expr_stmtContext *expr_ctx = ctx->expr_stmt()){
            return (Stmt*)visit(ctx->expr_stmt());
        }
        else if(HexaCParser::Var_declContext *var_ctx = ctx->var_decl()){
            return (Stmt*)visit(ctx->var_decl());
        }
    }

    virtual antlrcpp::Any visitIf_stmt(HexaCParser::If_stmtContext *ctx) override {
        Expr* cond;
        Expr* m_stmt;
        Expr* m_elseStmt;

        
    };
};

#endif // ASTGENERATOR_H
