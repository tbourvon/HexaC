#ifndef TYPEVISITOR_H
#define TYPEVISITOR_H

#include "ast.h"
#include "astVisitor.h"
#include <HexaCLexer.h>
#include <HexaCParserBaseVisitor.h>
#include <iostream>

using namespace HexaC;

class TypeVisitor : public ASTVisitor {
  virtual ErrorType visitBinaryOp(const BinaryOp *bo) {

    const BuiltinType *bitl;
    const BuiltinType *bitr;
    if (bitl = dynamic_cast<const BuiltinType *>(getExpressionType(bo->getLeftHandSide()))) {
     
    } else {
      std::cout << "casting bop" << std::endl;
      return false;
    }
    if (bitr = dynamic_cast<const BuiltinType *>(getExpressionType(bo->getRightHandSide()))) {
      
    } else {
      std::cout << "casting bop" << std::endl;
      return false;
    }
    int intls = (int)bitl->getKind();
    int intrs = (int)bitr->getKind();
    //std::cout << "lhs : " << (int)bitl->getKind()
    //            << " / rhs : " << (int)bitr->getKind() << std::endl;

    if (!( (intls == intrs) 
        || ((intls == 0) && (intrs == 1)) 
        || ((intls == 1) && (intrs == 0)) )) {

      std::cout << "debug binary op" << std::endl;
      std::cout << "lhs : " << (int)bitl->getKind()
                << " / rhs : " << (int)bitr->getKind() << std::endl;
      return false;
    }

    visitExpr(bo->getLeftHandSide());
    visitExpr(bo->getRightHandSide());
  }

  virtual ErrorType visitCallExpr(const CallExpr *ce) {
    const Expr *expr = ce->getCallee();
    const std::vector<Expr *> args = ce->getArgs();

    if (const DeclRefExpr *dre = dynamic_cast<const DeclRefExpr *>(expr)) {
      const Decl *d = dre->getDecl();
      if (const FuncDecl *fd = dynamic_cast<const FuncDecl *>(d)) {
        const std::vector<Param *> params = fd->getParams();
        if (params.size() != args.size()) {

          std::cout << "debug function decl size" << std::endl;
          std::cout << "nb param : " << params.size() << " nb args : " << args.size() << std::endl;
          return false;
        }
        int i = 0;
        for (auto param : params) {
          const Type *t_param = param->getType();
          const Type *t_arg = getExpressionType(args[i]);
          const BuiltinType *bit_param = dynamic_cast<const BuiltinType *>(t_param);
          const BuiltinType *bit_arg = dynamic_cast<const BuiltinType *>(t_arg);

          if(!bit_param || !bit_arg){
            std::cout << "casting uo" << std::endl;
            return false;
          }

          if (bit_param->getKind() != bit_arg->getKind() ) {
            std::cout << "debug function decl param" << std::endl;
            std::cout << "param : " << param << " nb args : " << args.size() << std::endl;
            return false;
          }
          i++;
        }
        return true;
      }
    }
    std::cout << "debug call expr" << std::endl;
    return false;
  }

  virtual ErrorType visitUnaryOp(const UnaryOp *uo) {
    auto builtin =
        dynamic_cast<const BuiltinType *>(getExpressionType(uo->getExpr()));
        std::cout << (int) builtin->getKind() << std::endl;
    if (!builtin) {
      std::cout << "debug unary op" << std::endl;
      return false;
    }
    if((builtin->getKind() == BuiltinType::Kind::INT32_T) ||
           (builtin->getKind() == BuiltinType::Kind::INT64_T)){
             std::cout << "unary op true" << std::endl;
           } else{
             std::cout << "unary op false" << std::endl;
           }
    return (builtin->getKind() == BuiltinType::Kind::INT32_T) ||
           (builtin->getKind() == BuiltinType::Kind::INT64_T);
  }
};

#endif // TYPEVISITOR_H