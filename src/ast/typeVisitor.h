#ifndef TYPEVISITOR_H
#define TYPEVISITOR_H

#include "ast.h"
#include "astVisitor.h"
#include <HexaCLexer.h>
#include <HexaCParserBaseVisitor.h>

using namespace HexaC;

class TypeVisitor : public ASTVisitor {
  virtual ErrorType visitBinaryOp(const BinaryOp *bo) {
    if (getExpressionType(bo->getLeftHandSide()) !=
        getExpressionType(bo->getRightHandSide())) {
      return false;
    }
    visitExpr(bo->getLeftHandSide());
    visitExpr(bo->getRightHandSide());
  }

  virtual ErrorType visitCallExpr(const CallExpr *ce) {
    const Expr *expr =ce->getCallee();
    const std::vector<Expr*> args = ce->getArgs();

    if(const DeclRefExpr* dre = dynamic_cast<const DeclRefExpr*>(expr)){
      const Decl* d = dre->getDecl();
      if(const FuncDecl* fd = dynamic_cast<const FuncDecl*>(d)){
          const std::vector<Param *> params = fd->getParams();
          if(params.size() != args.size()){
            return false;
          }
          int i = 0;
          for(auto param : args){
            if(getExpressionType(param) != getExpressionType(args[i])){
              return false;
            }
            i++;
          }
          return true;
      }
    }
    return false;
  }

  virtual ErrorType visitUnaryOp(const UnaryOp *uo) {

    return (getExpressionType(uo->getExpr()) == BuiltinType::Kind::INT32_T) ||
            (getExpressionType(uo->getExpr()) == BuiltinType::Kind::INT64_T);
  }
}
;

#endif // TYPEVISITOR_H