#ifndef ASTVISITOR_H
#define ASTVISITOR_H

#include "ast.h"
#include <HexaCParserBaseVisitor.h>

using namespace HexaC;

class ASTVisitor : public HexaCParserBaseVisitor {
public:
  typedef bool ErrorType;

  ASTVisitor();
  virtual ErrorType visitAST(const AST *ast) {
    visitProgram(ast->getProgram());
  }

  virtual ErrorType visitProgram(const Program *program) {
    std::vector<Decl *> decls;
    for (int i = 0; i < decls.size(); i++) {
      visitDecl(decls[i]);
    }
  }
  virtual ErrorType visitDecl(const Decl *decl) {
    if (const FuncDecl *fd = dynamic_cast<const FuncDecl *>(decl)) {
      std::vector<Param *> params = fd->getParams();
      for (int i = 0; i < params.size(); i++) {
        // visit params[i]
      }
      visitBlock(fd->getBlock());
    }
    if (const VarDecl *vd = dynamic_cast<const VarDecl *>(decl)) {
        visitExpr(vd->getExpr());
    }
  }
  virtual ErrorType visitExpr(const Expr *expr) {}

  virtual ErrorType visitBlock(const BlockStmt *block) {
    std::vector<Stmt *> stmts = block->getBody();
    for (int i = 0; i < stmts.size(); i++) {
      visitStmt(stmts[i]);
    }
  }

  virtual ErrorType visitStmt(const Stmt *stmt) {
      if (const DeclStmt *dStmt = dynamic_cast<const DeclStmt *>(stmt)) {
        visitDecl(dStmt->getDecl());
      }
      if (const ExprStmt *eStmt = dynamic_cast<const ExprStmt *>(stmt)) {
          visitExpr(eStmt->getExpr());
      }
      if (const IfStmt *ifStmt = dynamic_cast<const IfStmt *>(stmt)) {
          visitExpr(ifStmt->getCond());
          visitStmt(ifStmt->getStmt());
          visitStmt(ifStmt->getElseStmt());
      }
      if (const WhileStmt *wStmt = dynamic_cast<const WhileStmt *>(stmt)) {
          visitExpr(wStmt->getCond());
          visitStmt(wStmt->getStmt());
      }
      if (const BlockStmt *bStmt = dynamic_cast<const BlockStmt *>(stmt)) {
          std::vector<Stmt*> stmts = bStmt->getBody();
          for(int i = 0; i < stmts.size(); i++){
              visitStmt(stmts[i]);
          }
      }
  }

protected:
  Program *program;
};

#endif // ASTVISITOR_H