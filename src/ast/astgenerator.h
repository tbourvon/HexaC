#ifndef ASTGENERATOR_H
#define ASTGENERATOR_H

#include <HexaCParserBaseVisitor.h>
#include <HexaCLexer.h>
#include <vector>
#include "ast.h"


using namespace HexaC;

class ASTGenerator : public HexaCParserBaseVisitor
{
public:
    ASTGenerator() : m_topScopeNumber(0), m_currentScope(0), m_nextDeclRefIsLvalue(false) {
BuiltinType *bit = new BuiltinType(BuiltinType::Kind::CHAR);
Param *p = new Param("c", bit, NULL);
std::vector<Param*> vect;
vect.push_back(p);
        m_scopeDeclarationTable[0] = {
            {"putchar", new FuncDecl("putchar", new BuiltinType(BuiltinType::Kind::VOID), vect, new BlockStmt({}))}
        };
    }

    virtual antlrcpp::Any visitProgram(HexaCParser::ProgramContext *ctx) override {
      std::vector<Decl*> decls;
      for (HexaCParser::Toplevel_itemContext* top_level_ctx : ctx->toplevel_item()) {
          Decl* decl = (Decl*) visitToplevel_item(top_level_ctx);
          decls.push_back(decl);
      }

      return new Program(decls, ctx->start->getLine());
    }

    virtual antlrcpp::Any visitToplevel_item(HexaCParser::Toplevel_itemContext *ctx) override {
        if (HexaCParser::DeclContext *decl_ctx = ctx->decl()) {
            return (Decl*)visit(decl_ctx);
        } else {
            return (Decl*)nullptr;
        }
    }

    virtual antlrcpp::Any visitExpr(HexaCParser::ExprContext *ctx) override {
        if (ctx->bin_op) {
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
            std::cout << "ligne " << ctx->start->getLine() << std::endl;
            if (kind == BinaryOp::Kind::ASSIGN) {
                m_nextDeclRefIsLvalue = true;
            }
            Expr* lhs = visit(ctx->bin_lhs);
            m_nextDeclRefIsLvalue = false;
            Expr* rhs = visit(ctx->bin_rhs);

            return (Expr*)(new BinaryOp(kind, lhs, rhs, ctx->start->getLine()));
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

            return (Expr*)(new UnaryOp(kind, expr, ctx->start->getLine()));
        } else if (ctx->group_expr) {
            return (Expr*)(new GroupExpr((Expr*)visit(ctx->group_expr)));
        } else if (ctx->callee) {
            Expr* callee = visit(ctx->callee);
            std::vector<Expr*> argList = visit(ctx->arg_list());

            return (Expr*)(new CallExpr(callee, argList, ctx->start->getLine()));
        } else if (ctx->literal()) {
            return (Expr*)(visit(ctx->literal()));
        } else {
            return (Expr*)nullptr;
        }
    }

    virtual antlrcpp::Any visitArg_list(HexaCParser::Arg_listContext *ctx) override {
        std::vector<Expr*> exprs;
        for (auto exprCtx : ctx->expr()) {
            exprs.push_back(visit(exprCtx));
        }

        return exprs;
    }

    virtual antlrcpp::Any visitLiteral(HexaCParser::LiteralContext *ctx) override {
        if (ctx->INT_LIT()) {
            return (Expr*)(new IntegerLiteral(stoi(ctx->INT_LIT()->getText()), ctx->start->getLine()));
        } else if (ctx->CHAR_LIT()) {
            return (Expr*)(new CharLiteral(ctx->CHAR_LIT()->getText()[1], ctx->start->getLine()));
        } else if (ctx->ID()) {
            return (Expr*)(new DeclRefExpr(getDeclByName(ctx->ID()->getText()), m_nextDeclRefIsLvalue ? DeclRefExpr::Kind::LVALUE : DeclRefExpr::Kind::RVALUE, ctx->start->getLine()));
        }

        return nullptr;
    }

    virtual antlrcpp::Any visitStmt(HexaCParser::StmtContext *ctx) override {
        if(HexaCParser::BlockContext *block_ctx = ctx->block()){
            return (Stmt*)visit(ctx->block()).as<BlockStmt*>();
        }
        else if(HexaCParser::If_stmtContext *if_ctx = ctx->if_stmt()){
            return (Stmt*)visit(ctx->if_stmt()).as<IfStmt*>();
        }
        else if(HexaCParser::While_stmtContext *while_ctx = ctx->while_stmt()){
            return (Stmt*)visit(ctx->while_stmt()).as<WhileStmt*>();
        }
        else if(HexaCParser::Expr_stmtContext *expr_ctx = ctx->expr_stmt()){
            return (Stmt*)visit(ctx->expr_stmt()).as<ExprStmt*>();
        }
        else if(HexaCParser::Var_declContext *var_ctx = ctx->var_decl()){
            return (Stmt*)(new DeclStmt((Decl*)visitVar_decl(var_ctx), ctx->start->getLine()));
        }
        else if(HexaCParser::Return_stmtContext *return_ctx = ctx->return_stmt()){
            return (Stmt*)visit(ctx->return_stmt()).as<ReturnStmt*>();
        } else {
            return (Stmt*)nullptr;
        }

    }

    virtual antlrcpp::Any visitReturn_stmt(HexaCParser::Return_stmtContext *ctx) override {
        Expr* expr = nullptr;
        if (ctx->expr()) {
            expr = visit(ctx->expr());
        }

        return new ReturnStmt(expr, ctx->start->getLine());
    };

    virtual antlrcpp::Any visitIf_stmt(HexaCParser::If_stmtContext *ctx) override {
        Expr* cond = visit(ctx->expr());
        Stmt* ifStmt = visit(ctx->stmt_if);
        Stmt* elseStmt = ctx->stmt_else ? (Stmt*)visit(ctx->stmt_else) : nullptr;

        return new IfStmt(cond, ifStmt, elseStmt, ctx->start->getLine());
    };

    virtual antlrcpp::Any visitWhile_stmt(HexaCParser::While_stmtContext *ctx) override {
        Expr* cond = visit(ctx->expr());
        Stmt* stmt = visit(ctx->stmt());

        return new WhileStmt(cond, stmt, ctx->start->getLine());
    };

    virtual antlrcpp::Any visitBlock(HexaCParser::BlockContext *ctx) override {
        int parentScope = m_currentScope;
        m_scopeDeclarationTable[++m_topScopeNumber] = m_scopeDeclarationTable.at(parentScope);
        m_currentScope = m_topScopeNumber;

        std::vector<Stmt*> stmtList = visit(ctx->stmt_list());

        m_currentScope = parentScope;

        return new BlockStmt(stmtList, ctx->start->getLine());
    };

    virtual antlrcpp::Any visitStmt_list(HexaCParser::Stmt_listContext *ctx) override {
        std::vector<Stmt*> stmts;
        for (auto stmtCtx : ctx->stmt()) {
            stmts.push_back(visit(stmtCtx));
        }

        return stmts;
    };

    virtual antlrcpp::Any visitExpr_stmt(HexaCParser::Expr_stmtContext *ctx) override {
        Expr* expr = visit(ctx->expr());

        return new ExprStmt(expr, ctx->start->getLine());
    };

    virtual antlrcpp::Any visitType(HexaCParser::TypeContext *ctx) override {
        BuiltinType::Kind kind;
        switch (ctx->type_id->getType()) {
            case HexaCLexer::INT32_T: kind = BuiltinType::Kind::INT32_T; break;
            case HexaCLexer::INT64_T: kind = BuiltinType::Kind::INT64_T; break;
            case HexaCLexer::CHAR:    kind = BuiltinType::Kind::CHAR;    break;
            case HexaCLexer::VOID:    kind = BuiltinType::Kind::VOID;    break;
        }
        return (Type*)new BuiltinType(kind, ctx->start->getLine());
    }

    virtual antlrcpp::Any visitParam_list(HexaCParser::Param_listContext *ctx) override {
        std::vector<HexaCParser::ParamContext *> paramsRaw = ctx->param();
        std::vector<Param*> params;
        for(HexaCParser::ParamContext* param : paramsRaw) {
            params.push_back(visit(param));
        }
        return params;
    }

    virtual antlrcpp::Any visitParam(HexaCParser::ParamContext *ctx) override {
        return new Param(ctx->getText(), visitType(ctx->type()), nullptr, ctx->start->getLine()); // FIXME: add default value
    }

    virtual antlrcpp::Any visitFunc_decl(HexaCParser::Func_declContext *ctx) override {
        auto fd = new FuncDecl(ctx->ID()->getText(), visitType(ctx->type()), visitParam_list(ctx->param_list()), visitBlock(ctx->block()), ctx->start->getLine());
        m_scopeDeclarationTable.at(m_currentScope)[fd->getName()] = fd;
        return (Decl*)fd;
    }

    virtual antlrcpp::Any visitVar_decl(HexaCParser::Var_declContext *ctx) override {
        auto vd = new VarDecl(ctx->ID()->getText(), visitType(ctx->type()), nullptr, ctx->start->getLine());
        m_scopeDeclarationTable.at(m_currentScope)[vd->getName()] = vd;
        return (Decl*)vd;
    }

    virtual antlrcpp::Any visitDecl(HexaCParser::DeclContext *ctx) override {
        if (HexaCParser::Func_declContext *func_ctx = ctx->func_decl()) {
            return (Decl*)visitFunc_decl(ctx->func_decl());
        } else if (HexaCParser::Var_declContext *var_ctx = ctx->var_decl()) {
            return (Decl*)visitVar_decl(ctx->var_decl());
        } else {
            return (Decl*) nullptr;
        }
    }

protected:
    Decl* getDeclByName(const std::string& name) {
        auto table = m_scopeDeclarationTable.at(m_currentScope);
        return table.at(name);
    }

    bool m_nextDeclRefIsLvalue;

    int m_topScopeNumber;
    int m_currentScope;
    std::unordered_map<int, std::unordered_map<std::string, Decl*> > m_scopeDeclarationTable;
};

#endif // ASTGENERATOR_H
