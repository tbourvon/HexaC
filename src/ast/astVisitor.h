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
    return visitProgram(ast->getProgram());
  }

  virtual ErrorType visitProgram(const Program *program) {
    std::vector<Decl *> decls = program->getDecls();
    bool to_return = true;
    for (int i = 0; i < decls.size(); i++) {
      to_return = to_return && visitDecl(decls[i]);
    }
    return to_return;
  }

  virtual ErrorType visitDecl(const Decl *decl) {
    if (const FuncDecl *fd = dynamic_cast<const FuncDecl *>(decl)) {
      return visitFuncDecl(fd);
    }
    if (const VarDecl *vd = dynamic_cast<const VarDecl *>(decl)) {
      return visitVarDecl(vd);
    }
    return false;
  }

  virtual ErrorType visitFuncDecl(const FuncDecl *fd) {
    this->currentFunc = fd;
    bool to_return = true;
    for (auto param : fd->getParams()) {
      to_return = to_return && visitParam(param);
    }
    return to_return && visitBlockStmt(fd->getBlock());
  }

  virtual ErrorType visitVarDecl(const VarDecl *vd) {
    return visitExpr(vd->getExpr());
  }

  virtual ErrorType visitExpr(const Expr *expr) {
    if (const BinaryOp *bo = dynamic_cast<const BinaryOp *>(expr)) {
      return visitBinaryOp(bo);
    }
    if (const UnaryOp *uo = dynamic_cast<const UnaryOp *>(expr)) {
      return visitUnaryOp(uo);
    }
    if (const CallExpr *ce = dynamic_cast<const CallExpr *>(expr)) {
      return visitCallExpr(ce);
    }
    if (const GroupExpr *ge = dynamic_cast<const GroupExpr *>(expr)) {
      return visitGroupExpr(ge);
    }
    if (const LiteralExpr *le = dynamic_cast<const LiteralExpr *>(expr)) {
      return visitLiteralExpr(le);
    }
    if (const DeclRefExpr *dre = dynamic_cast<const DeclRefExpr *>(expr)) {
      return visitDeclRefExpr(dre);
    }
    return false;
  }

  virtual ErrorType visitLiteralExpr(const LiteralExpr *le) {
    if (const IntegerLiteral *il = dynamic_cast<const IntegerLiteral *>(le)) {
      return visitIntegerLiteral(il);
    }
    if (const CharLiteral *cl = dynamic_cast<const CharLiteral *>(le)) {
      return visitCharLiteral(cl);
    }
    return false;
  }

  virtual ErrorType visitIntegerLiteral(const IntegerLiteral *il) {
    return true;
  }

  virtual ErrorType visitCharLiteral(const CharLiteral *cl) {
    return true;
  }

  virtual ErrorType visitBinaryOp(const BinaryOp *bo) {
    return visitExpr(bo->getLeftHandSide()) && visitExpr(bo->getRightHandSide());
  }

  virtual ErrorType visitUnaryOp(const UnaryOp *uo) {
    return visitExpr(uo->getExpr());
  }

  virtual ErrorType visitCallExpr(const CallExpr *ce) {
    bool to_return = visitExpr(ce->getCallee());
    for (auto arg : ce->getArgs()) {
      to_return = to_return && visitExpr(arg);
    }
    return to_return;
  }

  virtual ErrorType visitGroupExpr(const GroupExpr *ge) {
    return visitExpr(ge->getSubExpr());
  }

  virtual ErrorType visitDeclRefExpr(const DeclRefExpr *dre) {
    return true;
  }

  virtual ErrorType visitStmt(const Stmt *stmt) {
    if (const DeclStmt *dStmt = dynamic_cast<const DeclStmt *>(stmt)) {
      return visitDeclStmt(dStmt);
    }
    if (const ExprStmt *eStmt = dynamic_cast<const ExprStmt *>(stmt)) {
      return visitExprStmt(eStmt);
    }
    if (const IfStmt *ifStmt = dynamic_cast<const IfStmt *>(stmt)) {
      return visitIfStmt(ifStmt);
    }
    if (const WhileStmt *wStmt = dynamic_cast<const WhileStmt *>(stmt)) {
      return visitWhileStmt(wStmt);
    }
    if (const BlockStmt *bStmt = dynamic_cast<const BlockStmt *>(stmt)) {
      return visitBlockStmt(bStmt);
    }
    if (const ReturnStmt *rStmt = dynamic_cast<const ReturnStmt *>(stmt)) {
      return visitReturnStmt(rStmt);
    }
    return false;
  }

  virtual ErrorType visitDeclStmt(const DeclStmt *dStmt) {
    return visitDecl(dStmt->getDecl());
  }

  virtual ErrorType visitExprStmt(const ExprStmt *eStmt) {
    return visitExpr(eStmt->getExpr());
  }

  virtual ErrorType visitReturnStmt(const ReturnStmt *returnStmt) {
    if (!returnStmt->getExpr()) {
      return true;
    }

    return visitExpr(returnStmt->getExpr());
  }

  virtual ErrorType visitIfStmt(const IfStmt *ifStmt) {
    return visitExpr(ifStmt->getCond()) && visitStmt(ifStmt->getStmt()) && (!ifStmt->getElseStmt() || visitStmt(ifStmt->getElseStmt()));
  }

  virtual ErrorType visitWhileStmt(const WhileStmt *wStmt) {
    return visitExpr(wStmt->getCond()) && visitStmt(wStmt->getStmt());
  }

  virtual ErrorType visitBlockStmt(const BlockStmt *bStmt) {
    std::vector<Stmt *> stmts = bStmt->getBody();
    bool to_return = true;
    for (int i = 0; i < stmts.size(); i++) {
      to_return = to_return && visitStmt(stmts[i]);
    }
    return to_return;
  }

  virtual ErrorType visitParam(const Param *param) {
    return visitExpr(param->getExpr());
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
      const Expr* lhs = binop->getLeftHandSide();
      return getExpressionType(lhs);
    }

    if (const UnaryOp *uop = dynamic_cast<const UnaryOp *>(expr)) {
      const Expr* expression = uop->getExpr();
      return getExpressionType(expression);
    }
    return new Type();
  }

protected:
  Program *program;
  const FuncDecl *currentFunc;
};

#endif // ASTVISITOR_H