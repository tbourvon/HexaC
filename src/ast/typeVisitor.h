#ifndef TYPEVISITOR_H
#define TYPEVISITOR_H

#include <HexaCParserBaseVisitor.h>
#include <HexaCLexer.h>
#include "ast.h"
#include "astVisitor.h"


using namespace HexaC;

class TypeVisitor : public ASTVisitor
{
    virtual ErrorType visitBinaryOp(const BinaryOp *expr) {
      if (const BinaryOp *bo = dynamic_cast<const BinaryOp *>(expr)) {
          if(getExpressionType(bo->getLeftHandSide()) != getExpressionType(bo->getRightHandSide())){
              return false;
          }
        visitExpr(bo->getLeftHandSide());
        visitExpr(bo->getRightHandSide());
      }
      if (const CallExpr *ce = dynamic_cast<const CallExpr *>(expr)) {
        visitExpr(ce->getCallee());
      }
      if (const GroupExpr *ge = dynamic_cast<const GroupExpr *>(expr)) {
        visitExpr(ge->getSubExpr());
      }
      if (const LiteralExpr *le = dynamic_cast<const LiteralExpr *>(expr)) {
      }
      if (const IntegerLiteral *il = dynamic_cast<const IntegerLiteral *>(expr)) {
      }
    }
};

#endif // TYPEVISITOR_H