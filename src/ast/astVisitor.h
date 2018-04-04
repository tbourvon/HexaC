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
    for (auto param : fd->getParams()) {
      visitParam(param);
    }
    visitBlockStmt(fd->getBlock());
  }

  virtual ErrorType visitVarDecl(const VarDecl *vd) {
    visitExpr(vd->getExpr());
  }

  virtual ErrorType visitExpr(const Expr *expr) {
    if (const BinaryOp *bo = dynamic_cast<const BinaryOp *>(expr)) {
      visitBinaryOp(bo);
    }
    if (const UnaryOp *uo = dynamic_cast<const UnaryOp *>(expr)) {
      visitUnaryOp(uo);
    }
    if (const CallExpr *ce = dynamic_cast<const CallExpr *>(expr)) {
      visitCallExpr(ce);
    }
    if (const GroupExpr *ge = dynamic_cast<const GroupExpr *>(expr)) {
      visitGroupExpr(ge);
    }
    if (const LiteralExpr *le = dynamic_cast<const LiteralExpr *>(expr)) {
      visitLiteralExpr(le);
    }
    if (const DeclRefExpr *dre = dynamic_cast<const DeclRefExpr *>(expr)) {
      visitDeclRefExpr(dre);
    }
  }

  virtual ErrorType visitLiteralExpr(const LiteralExpr *le) {
    if (const IntegerLiteral *il = dynamic_cast<const IntegerLiteral *>(le)) {
      visitIntegerLiteral(il);
    }
    if (const CharLiteral *cl = dynamic_cast<const CharLiteral *>(le)) {
      visitCharLiteral(cl);
    }
  }

  virtual ErrorType visitIntegerLiteral(const IntegerLiteral *il) {

  }

  virtual ErrorType visitCharLiteral(const CharLiteral *cl) {

  }

  virtual ErrorType visitBinaryOp(const BinaryOp *bo) {
    visitExpr(bo->getLeftHandSide());
    visitExpr(bo->getRightHandSide());
  }

  virtual ErrorType visitUnaryOp(const UnaryOp *uo) {
    visitExpr(uo->getExpr());
  }

  virtual ErrorType visitCallExpr(const CallExpr *ce) {
    visitExpr(ce->getCallee());
    for (auto arg : ce->getArgs()) {
      visitExpr(arg);
    }
  }

  virtual ErrorType visitGroupExpr(const GroupExpr *ge) {
    visitExpr(ge->getSubExpr());
  }

  virtual ErrorType visitDeclRefExpr(const DeclRefExpr *dre) {
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

  virtual ErrorType visitParam(const Param *param) {
    visitExpr(param->getExpr());
  }

  virtual const Type* getExpressionType(const Expr *expr) {
    if (const CallExpr *ce = dynamic_cast<const CallExpr *>(expr)) {
      return getExpressionType(ce->getCallee());
    }

    if (const GroupExpr *ge = dynamic_cast<const GroupExpr *>(expr)) {
      return getExpressionType(ge->getSubExpr());
    }

    if (const CharLiteral *le = dynamic_cast<const CharLiteral *>(expr)) {
      return new BuiltinType(BuiltinType::Kind::CHAR);
    }

    if (const IntegerLiteral *il = dynamic_cast<const IntegerLiteral *>(expr)) {
      return new BuiltinType(BuiltinType::Kind::INT64_T);
    }

    if (const DeclRefExpr *dre = dynamic_cast<const DeclRefExpr *>(expr)) {
      const Decl *d = dre->getDecl();
      if (const VarDecl *vd = dynamic_cast<const VarDecl *>(d)) {
        const Type *type = vd->getType();
        return type;
      }
      if (const FuncDecl *fd = dynamic_cast<const FuncDecl *>(d)) {
        const Type *type = fd->getType();
        return type;
      }
    }

    if (const BinaryOp *binop = dynamic_cast<const BinaryOp *>(expr)) {
      return new BuiltinType(BuiltinType::Kind::INT64_T);
    }
  }

protected:
  Program *program;
};

#endif // ASTVISITOR_H