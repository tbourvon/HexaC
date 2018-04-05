#ifndef TYPEVISITOR_H
#define TYPEVISITOR_H

#include "ast.h"
#include "astVisitor.h"
#include <HexaCLexer.h>
#include <HexaCParserBaseVisitor.h>
#include <iostream>

using namespace HexaC;

class TypeVisitor : public ASTVisitor {

  public:
  virtual ErrorType visitBinaryOp(const BinaryOp *bo) {

    const BuiltinType *bitl;
    const BuiltinType *bitr;
    if ((bitl = dynamic_cast<const BuiltinType *>(getExpressionType(bo->getLeftHandSide())))) {
     
    } else {
      std::cout << "casting bop" << std::endl;
      return false;
    }
    if ((bitr = dynamic_cast<const BuiltinType *>(getExpressionType(bo->getRightHandSide())))) {
      
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

      //std::cout << "debug binary op" << std::endl;
      //std::cout << "lhs : " << (int)bitl->getKind()
      //          << " / rhs : " << (int)bitr->getKind() << std::endl;
      std::cout  <<  "line " << bo->getLine() << " : incompatible type - expected (on the right hand side) " << bitl->getKindName() << ", found " << bitr->getKindName() << std::endl;
      return false;
    }

    return visitExpr(bo->getLeftHandSide()) && visitExpr(bo->getRightHandSide());
  }

  virtual ErrorType visitCallExpr(const CallExpr *ce) {
    const Expr *expr = ce->getCallee();
    const std::vector<Expr *> args = ce->getArgs();

    if (const DeclRefExpr *dre = dynamic_cast<const DeclRefExpr *>(expr)) {
      const Decl *d = dre->getDecl();
      if (const FuncDecl *fd = dynamic_cast<const FuncDecl *>(d)) {
        const std::vector<Param *> params = fd->getParams();
        if (params.size() != args.size()) {
          if(params.size() > args.size()){
                std::cout << "line " << ce->getLine() << " : not enough parameters - expected " << params.size() << " parameters, found " << args.size() << " parameters" << std::endl; 
          } else {
            std::cout << "line " << ce->getLine() << " : too many parameters - expected " << params.size() << " parameters, found " << args.size() << " parameters" << std::endl; 
          }
          //std::cout << "debug function decl size" << std::endl;
          //std::cout << "nb param : " << params.size() << " nb args : " << args.size() << std::endl;
          return false;
        }
        int i = 0;
        for (auto param : params) {
          const Type *t_param = param->getType();
          const Type *t_arg = getExpressionType(args[i]);
          const BuiltinType *bit_param = dynamic_cast<const BuiltinType *>(t_param);
          const BuiltinType *bit_arg = dynamic_cast<const BuiltinType *>(t_arg);

          if(!bit_param || !bit_arg){
            //std::cout << "casting uo" << std::endl;
            std::cout << "line " << ce->getLine() << " : invalid parameter" << std::endl;
            return false;
          }

          if (bit_param->getKind() != bit_arg->getKind() ) {
            //std::cout << "debug function decl param" << std::endl;
            //std::cout << "param : " << param << " nb args : " << args.size() << std::endl;
             std::cout << "line " << ce->getLine() << " : incompatible type - expected " << bit_param->getKindName() << ", found " << bit_arg->getKindName() << std::endl;
            return false;
          }
          i++;
        }
        return true;
      }
    }
    //std::cout << "debug call expr" << std::endl;
    return false;
  }

  virtual ErrorType visitUnaryOp(const UnaryOp *uo) {
    auto builtin =
        dynamic_cast<const BuiltinType *>(getExpressionType(uo->getExpr()));
    if (!builtin) {
      std::cout << "debug unary op" << std::endl;
      return false;
    }
    if((builtin->getKind() == BuiltinType::Kind::INT32_T) ||
           (builtin->getKind() == BuiltinType::Kind::INT64_T)){
             return true;
           } else{
             std::cout << "line " << uo->getLine() << " : incompatible type - expected int32 or int 64, found " << builtin->getKindName() << std::endl;
             return false;
           }
  }

  virtual ErrorType visitReturnStmt(const ReturnStmt *returnStmt) {
    
    const BuiltinType *bit_currentFunc = dynamic_cast<const BuiltinType *>(this->currentFunc->getType());
    const BuiltinType *bit_returnStmt = dynamic_cast<const BuiltinType *>(getExpressionType(returnStmt->getExpr()));
    
    bool typeChecking =  ( bit_currentFunc->getKind() == bit_returnStmt->getKind() );

    if(!typeChecking){
        std::cout << "line " << returnStmt->getLine() << " : invalid return type in function " << currentFunc->getName() << " - expected " << bit_currentFunc->getKindName() << ", found " << bit_returnStmt->getKindName() << std::endl;
    }

    return typeChecking;
  }


};

#endif // TYPEVISITOR_H