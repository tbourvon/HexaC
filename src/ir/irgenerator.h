#ifndef IRGENERATOR_H
#define IRGENERATOR_H

#include <iostream>
#include "../ast/ast.h"
#include "../ast/astvisitor.h"
#include "ir.h"

using namespace HexaC;

class IRGenerator : public ASTVisitor {
public:
  IRGenerator() {}

  CFG* generateIR(AST *ast) {
    visitProgram(ast->getProgram());
    return m_cfg;
  }

  virtual ErrorType visitProgram(const Program *program) override {
    
  }

  virtual ErrorType visitFuncDecl(const FuncDecl *fd) override {

  }

  virtual ErrorType visitVarDecl(const VarDecl *vd) override {

  }

  virtual ErrorType visitBlockStmt(const BlockStmt *block) override {

  }

  virtual ErrorType visitBinaryOp(const BinaryOp *binop) override {

  }

  virtual ErrorType visitUnaryOp(const UnaryOp *unop) override {

  }

  virtual ErrorType visitDeclRefExpr(const DeclRefExpr *ref) {
  }

  virtual ErrorType visitIntegerLiteral(const IntegerLiteral *intLit) {
  }

  virtual ErrorType visitCharLiteral(const CharLiteral *charLit) {
  }

  virtual ErrorType visitIfStmt(const IfStmt *ifStmt) {

  }

  virtual ErrorType visitIfStmt(const WhileStmt *whileStmt) {
  }

  virtual ErrorType visitCallExpr(const CallExpr* ce) {
  }

protected:
  CFG* m_cfg;
};

#endif // IRGENERATOR_H