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
    std::vector<Decl *> decls = program->getDecls();
    for (int i = 0; i < decls.size(); i++) {
      visitDecl(decls[i]);
    }
  }

  virtual ErrorType visitDecl(const Decl *decl) {
    if (const FuncDecl *fd = dynamic_cast<const FuncDecl *>(decl)) {
      visitFuncDecl(fd);
    }
    if (const VarDecl *vd = dynamic_cast<const VarDecl *>(decl)) {
      visitVarDecl(vd);
    }
  }

  virtual ErrorType visitFuncDecl(const FuncDecl *fd) {
    std::vector<Param *> params = fd->getParams();
    for (int i = 0; i < params.size(); i++) {
      // visit params[i]
    }
    visitBlock(fd->getBlock());
  }

  virtual ErrorType visitVarDecl(const VarDecl *vd) {
    visitExpr(vd->getExpr());
  }

  virtual ErrorType visitExpr(const Expr *expr) {
    if (const BinaryOp *bo = dynamic_cast<const BinaryOp *>(expr)) {
      visitBinaryOp(bo);
    }
    if (const CallExpr *ce = dynamic_cast<const CallExpr *>(expr)) {
      visitCallerExpr(ce);
    }
    if (const GroupExpr *ge = dynamic_cast<const GroupExpr *>(expr)) {
      visitGroupExpr(ge);
    }
    if (const LiteralExpr *le = dynamic_cast<const LiteralExpr *>(expr)) {
    }
    if (const IntegerLiteral *il = dynamic_cast<const IntegerLiteral *>(expr)) {
    }
    if (const DeclRefExpr *dre = dynamic_cast<const DeclRefExpr *>(expr)) {
      visitDeclRefExpr(dre);
    }
  }

  virtual ErrorType visitBinaryOp(const BinaryOp *bo) {
    visitExpr(bo->getLeftHandSide());
    visitExpr(bo->getRightHandSide());
  }

  virtual ErrorType visitCallerExpr(const CallExpr *ce) {
    visitExpr(ce->getCallee());
  }

  virtual ErrorType visitGroupExpr(const GroupExpr *ge) {
    visitExpr(ge->getSubExpr());
  }

  virtual ErrorType visitDeclRefExpr(const DeclRefExpr *dre) {
    visitDecl(dre->getDecl());
  }

  virtual ErrorType visitBlock(const BlockStmt *block) {
    std::vector<Stmt *> stmts = block->getBody();
    for (int i = 0; i < stmts.size(); i++) {
      visitStmt(stmts[i]);
    }
  }

  virtual ErrorType visitStmt(const Stmt *stmt) {
    if (const DeclStmt *dStmt = dynamic_cast<const DeclStmt *>(stmt)) {
      visitDeclStmt(dStmt);
    }
    if (const ExprStmt *eStmt = dynamic_cast<const ExprStmt *>(stmt)) {
      visitExprStmt(eStmt);
    }
    if (const IfStmt *ifStmt = dynamic_cast<const IfStmt *>(stmt)) {
      visitIfStmt(ifStmt);
    }
    if (const WhileStmt *wStmt = dynamic_cast<const WhileStmt *>(stmt)) {
      visitWhileStmt(wStmt);
    }
    if (const BlockStmt *bStmt = dynamic_cast<const BlockStmt *>(stmt)) {
      visitBlockStmt(bStmt);
    }
  }

  virtual ErrorType visitDeclStmt(const DeclStmt *dStmt) {
    visitDecl(dStmt->getDecl());
  }

  virtual ErrorType visitExprStmt(const ExprStmt *eStmt) {
    visitExpr(eStmt->getExpr());
  }

  virtual ErrorType visitIfStmt(const IfStmt *ifStmt) {
    visitExpr(ifStmt->getCond());
    visitStmt(ifStmt->getStmt());
    visitStmt(ifStmt->getElseStmt());
  }

  virtual ErrorType visitWhileStmt(const WhileStmt *wStmt) {
    visitExpr(wStmt->getCond());
    visitStmt(wStmt->getStmt());
  }

  virtual ErrorType visitBlockStmt(const BlockStmt *bStmt) {
    std::vector<Stmt *> stmts = bStmt->getBody();
    for (int i = 0; i < stmts.size(); i++) {
      visitStmt(stmts[i]);
    }
  }

  virtual ErrorType visitBlock(const BlockStmt *block) {}

  virtual ErrorType visitParam(const Param *param) {}

  virtual BuiltinType::Kind getExpressionType(const Expr *expr) {
    if (const CallExpr *ce = dynamic_cast<const CallExpr *>(expr)) {
      return getExpressionType(ce->getCallee());
    }

    if (const GroupExpr *ge = dynamic_cast<const GroupExpr *>(expr)) {
      return getExpressionType(ge->getSubExpr());
    }

    if (const LiteralExpr *le = dynamic_cast<const LiteralExpr *>(expr)) {
      return BuiltinType::Kind::CHAR;
    }

    if (const IntegerLiteral *il = dynamic_cast<const IntegerLiteral *>(expr)) {
      return BuiltinType::Kind::INT64_T;
    }

    if (const DeclRefExpr *dre = dynamic_cast<const DeclRefExpr *>(expr)) {
      const Decl *d = dre->getDecl();
      if (const VarDecl *vd = dynamic_cast<const VarDecl *>(dre)) {
        const Type *type = vd->getType();
        if (const BuiltinType *bit = dynamic_cast<const BuiltinType *>(type)) {
          return bit->getKind();
        }
      }
      if (const FuncDecl *fd = dynamic_cast<const FuncDecl *>(dre)) {
        const Type *type = fd->getType();
        if (const BuiltinType *bit = dynamic_cast<const BuiltinType *>(type)) {
          return bit->getKind();
        }
      }
    }
  }

protected:
  Program *program;
};

#endif // ASTVISITOR_H