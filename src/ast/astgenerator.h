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
    }

protected:
    Decl* getDeclByName(const std::string& name) {
        auto table = m_scopeDeclarationTable.at(m_currentScope);
        return table.at(name);
    }

    int m_topScopeNumber;
    int m_currentScope;
    std::unordered_map<int, std::unordered_map<std::string, Decl*> > m_scopeDeclarationTable;
};

#endif // ASTGENERATOR_H
