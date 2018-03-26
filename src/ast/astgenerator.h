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

    virtual antlrcpp::Any visitExpr(HexaCParser::ExprContext *ctx) override {
        if (ctx->bin_op) {
            Expr* lhs = visit(ctx->bin_lhs);
            Expr* rhs = visit(ctx->bin_rhs);

            BinaryOp::Kind kind;
            switch (ctx->bin_op->getType()) {
            case HexaCLexer::STAR:     kind = BinaryOp::Kind::MULT;        break;
            case HexaCLexer::DIV:      kind = BinaryOp::Kind::DIV;         break;
            case HexaCLexer::MOD:      kind = BinaryOp::Kind::MOD;         break;
            case HexaCLexer::PLUS:     kind = BinaryOp::Kind::ADD;         break;
            case HexaCLexer::MINUS:    kind = BinaryOp::Kind::SUB;         break;
            case HexaCLexer::EQ:       kind = BinaryOp::Kind::ASSIGN;      break;
            case HexaCLexer::STAR_EQ:  kind = BinaryOp::Kind::ASSIGN_MULT; break;
            case HexaCLexer::DIV_EQ:   kind = BinaryOp::Kind::ASSIGN_DIV;  break;
            case HexaCLexer::MOD_EQ:   kind = BinaryOp::Kind::ASSIGN_MOD;  break;
            case HexaCLexer::PLUS_EQ:  kind = BinaryOp::Kind::ASSIGN_ADD;  break;
            case HexaCLexer::MINUS_EQ: kind = BinaryOp::Kind::ASSIGN_SUB;  break;
            case HexaCLexer::EQ_EQ:    kind = BinaryOp::Kind::EQ;          break;
            case HexaCLexer::NOT_EQ:   kind = BinaryOp::Kind::NEQ;         break;
            case HexaCLexer::OR_OR:    kind = BinaryOp::Kind::OR;          break;
            case HexaCLexer::AND_AND:  kind = BinaryOp::Kind::AND;         break;
            case HexaCLexer::GT:       kind = BinaryOp::Kind::GT;          break;
            case HexaCLexer::LT:       kind = BinaryOp::Kind::LT;          break;
            case HexaCLexer::GE:       kind = BinaryOp::Kind::GE;          break;
            case HexaCLexer::LE:       kind = BinaryOp::Kind::LE;          break;
            }

            return (Expr*)(new BinaryOp(kind, lhs, rhs));
        } else if (ctx->un_op) {
            Expr* expr = visit(ctx->un_expr);

            UnaryOp::Kind kind;
            switch (ctx->un_op->getType()) {
            case HexaCLexer::PLUS:        kind = UnaryOp::Kind::PLUS;         break;
            case HexaCLexer::MINUS:       kind = UnaryOp::Kind::MINUS;         break;
            case HexaCLexer::NOT:         kind = UnaryOp::Kind::NOT;        break;
            case HexaCLexer::PLUS_PLUS:   kind = ctx->postfix ? UnaryOp::Kind::POST_INC : UnaryOp::Kind::PRE_INC; break;
            case HexaCLexer::MINUS_MINUS: kind = ctx->postfix ? UnaryOp::Kind::POST_DEC : UnaryOp::Kind::PRE_DEC; break;
            }

            return (Expr*)(new UnaryOp(kind, expr));
        } else if (ctx->group_expr) {
            return (Expr*)(new GroupExpr((Expr*)visit(ctx->group_expr)));
        } else if (ctx->callee) {
            Expr* callee = visit(ctx->callee);
            std::vector<Expr*> argList = visit(ctx->arg_list());

            return (Expr*)(new CallExpr(callee, argList));
        } else if (ctx->literal()) {
            return (Expr*)(visit(ctx->literal()));
        } else {
            return (Expr*)nullptr;
        }
    }

    virtual antlrcpp::Any visitLiteral(HexaCParser::LiteralContext *ctx) override {
        if (ctx->INT_LIT()) {
            return (Expr*)(new IntegerLiteral(stoi(ctx->INT_LIT()->getText())));
        } else if (ctx->CHAR_LIT()) {
            return (Expr*)(new CharLiteral(ctx->CHAR_LIT()->getText()[1]));
        } else if (ctx->ID()) {
            return (Expr*)(new DeclRefExpr(getDeclByName(ctx->ID()->getText())));
        }

        return nullptr;
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
        } else {
            return (Stmt*)nullptr;
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
        } else {
            return (IfStmt*)nullptr;
        }
    };

    virtual antlrcpp::Any visitWhile_stmt(HexaCParser::While_stmtContext *ctx) override {
        if(HexaCParser::ExprContext *cond_ctx = ctx->expr()){
            return (WhileStmt*)visit(ctx->expr());
        }
        else if(HexaCParser::StmtContext *ifStmt = ctx->stmt()){
            return (WhileStmt*)visit(ctx->stmt());
        }

        return nullptr;
    };

    virtual antlrcpp::Any visitParam_list(HexaCParser::Param_listContext *ctx) override {
        std::vector<HexaCParser::ParamContext *> paramsRaw = ctx->param();
        std::vector<Param*> params;
        for(HexaCParser::ParamContext* param : paramsRaw) {
            BuiltinType::Kind kind = toKind(param->type()->type_id->getType());
            params.push_back(new Param(param->getText(), new BuiltinType(kind)));
        }
        return params;
    }

    virtual antlrcpp::Any visitParam(HexaCParser::ParamContext *ctx) override {
        BuiltinType::Kind kind = toKind(ctx->type()->type_id->getType());
        return new Param(ctx->getText(), new BuiltinType(kind));
    }

    virtual antlrcpp::Any visitFunc_decl(HexaCParser::Func_declContext *ctx) override {
        BuiltinType::Kind kind = toKind(ctx->type()->type_id->getType());
        return (Decl*)(new FuncDecl(ctx->ID()->getText(), new BuiltinType(kind), visitParam_list(ctx->param_list()), visitBlock(ctx->block())));
    }

    virtual antlrcpp::Any visitVar_decl(HexaCParser::Var_declContext *ctx) override {
        BuiltinType::Kind kind = toKind(ctx->type()->type_id->getType());
        return (Decl*)(new VarDecl(ctx->ID()->getText(), new BuiltinType(kind), visitExpr(ctx->expr())));
    }

    virtual antlrcpp::Any visitDecl(HexaCParser::DeclContext *ctx) override {
        if (HexaCParser::Func_declContext *func_ctx = ctx->func_decl()) {
            visitFunc_decl(ctx->func_decl());
        } else if (HexaCParser::Var_declContext *var_ctx = ctx->var_decl()) {
            visitVar_decl(ctx->var_decl());
        } else {
            return (Decl*) nullptr;
        }
    }

protected:
    Decl* getDeclByName(const std::string& name) {
        auto table = m_scopeDeclarationTable.at(m_currentScope);
        return table.at(name);
    }

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

    int m_topScopeNumber;
    int m_currentScope;
    std::unordered_map<int, std::unordered_map<std::string, Decl*> > m_scopeDeclarationTable;
};

#endif // ASTGENERATOR_H
