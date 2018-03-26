#ifndef ASTGENERATOR_H
#define ASTGENERATOR_H

#include <HexaCParserBaseVisitor.h>
#include <HexaCLexer.h>
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
        if(HexaCParser::ExprContext *cond_ctx = ctx->expr()){
            return (IfStmt*)visit(ctx->expr());
        }
        else if(HexaCParser::StmtContext *ifStmt = ctx->stmt().at(0)){
            return (IfStmt*)visit(ctx->stmt().at(0));
        }
        else if(HexaCParser::StmtContext *elseStmt = ctx->stmt().at(1)){
            return (IfStmt*)visit(ctx->stmt().at(1));
        }
    };

    virtual antlrcpp::Any visitWhile_stmt(HexaCParser::While_stmtContext *ctx) override {
        if(HexaCParser::ExprContext *cond_ctx = ctx->expr()){
            return (WhileStmt*)visit(ctx->expr());
        }
        else if(HexaCParser::StmtContext *ifStmt = ctx->stmt()){
            return (WhileStmt*)visit(ctx->stmt());
        }
    };

    virtual antlrcpp::Any visitDecl(HexaCParser::DeclContext *ctx) override {
        if (HexaCParser::Func_declContext *func_ctx = ctx->func_decl()) {

            BuiltinType::Kind kind = toKind(func_ctx->type()->type_id->getType());

            std::vector<HexaCParser::ParamContext *> paramsRaw = func_ctx->param_list()->param();
            std::vector<Param*> params;
            for(HexaCParser::ParamContext* param : paramsRaw) {

                BuiltinType::Kind kind = toKind(param->type()->type_id->getType());
                params.push_back(new Param(param->getText(), new BuiltinType(kind)));
            }
            return new FuncDecl(func_ctx->ID()->getText(), new BuiltinType(kind), params, visitBlock(func_ctx->block()));
        } else if (HexaCParser::Var_declContext *var_ctx = ctx->var_decl()) {
            BuiltinType::Kind kind = toKind(var_ctx->type()->type_id->getType());
            return new VarDecl(var_ctx->ID()->getText(), new BuiltinType(kind), visitExpr(var_ctx->expr()));
        } else {
            return (Decl*) nullptr;
        }
    }

private:
    BuiltinType::Kind toKind(int i) {
        BuiltinType::Kind kind;
        switch (i) {
            case HexaCLexer::INT32_T: kind = BuiltinType::Kind::INT32_T; break;
            case HexaCLexer::INT64_T: kind = BuiltinType::Kind::INT64_T; break;
            case HexaCLexer::CHAR:    kind = BuiltinType::Kind::CHAR;    break;
            case HexaCLexer::VOID:    kind = BuiltinType::Kind::VOID;    break;
        }
        return kind;
    }
};

#endif // ASTGENERATOR_H
