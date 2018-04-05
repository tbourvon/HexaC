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

  std::vector<CFG*> generateIR(AST *ast) {
    visitProgram(ast->getProgram());
    return m_cfgs;
  }

  virtual ErrorType visitProgram(const Program *program) override {
    for (auto decl : program->getDecls()) {
      visitDecl(decl);
    }
  }

  virtual ErrorType visitFuncDecl(const FuncDecl *fd) override {
    CFG* cfg = new CFG(fd);
    m_currentCFG = cfg;

    visitBlockStmt(fd->getBlock());

    m_cfgs.push_back(cfg);
  }

  virtual ErrorType visitVarDecl(const VarDecl *vd) override {
    m_currentCFG->add_to_symbol_table(vd->getName(), vd->getType());
  }

  virtual ErrorType visitExprStmt(const ExprStmt* exprStmt) override {
    visitExprIR(exprStmt->getExpr());
  }

  virtual std::string visitExprIR(const Expr *expr) {
    if (const BinaryOp *bo = dynamic_cast<const BinaryOp *>(expr)) {
      return visitBinaryOpIR(bo);
    }
    if (const UnaryOp *uo = dynamic_cast<const UnaryOp *>(expr)) {
      return visitUnaryOpIR(uo);
    }
    if (const CallExpr *ce = dynamic_cast<const CallExpr *>(expr)) {
      return visitCallExprIR(ce);
    }
    if (const GroupExpr *ge = dynamic_cast<const GroupExpr *>(expr)) {
      return visitGroupExprIR(ge);
    }
    if (const LiteralExpr *le = dynamic_cast<const LiteralExpr *>(expr)) {
      return visitLiteralExprIR(le);
    }
    if (const DeclRefExpr *dre = dynamic_cast<const DeclRefExpr *>(expr)) {
      return visitDeclRefExprIR(dre);
    }
  }

  virtual std::string visitBinaryOpIR(const BinaryOp *binop) {
    std::string lhsTemp = visitExprIR(binop->getLeftHandSide());
    std::string rhsTemp = visitExprIR(binop->getRightHandSide());

    const Type* exprType = getExpressionType(binop);

    switch (binop->getKind()) {
      case BinaryOp::Kind::ADD: {
        std::string resTemp = m_currentCFG->create_new_tempvar(exprType);
        m_currentCFG->current_bb->add_IRInstr(IRInstr::add, exprType, {resTemp, lhsTemp, rhsTemp});
        return resTemp;
      }

      case BinaryOp::Kind::ASSIGN: {
        m_currentCFG->current_bb->add_IRInstr(IRInstr::wmem, exprType, {lhsTemp, rhsTemp});
        return rhsTemp;
      }

      case BinaryOp::Kind::MULT: {
        std::string resTemp = m_currentCFG->create_new_tempvar(exprType);
        m_currentCFG->current_bb->add_IRInstr(IRInstr::mul, exprType, {resTemp, lhsTemp, rhsTemp});
        return resTemp;
      }

      case BinaryOp::Kind::EQ: {
        std::string resTemp = m_currentCFG->create_new_tempvar(exprType);
        m_currentCFG->current_bb->add_IRInstr(IRInstr::cmp_eq, exprType, {resTemp, lhsTemp, rhsTemp});
        return resTemp;
      }

      case BinaryOp::Kind::LT: {
        std::string resTemp = m_currentCFG->create_new_tempvar(exprType);
        m_currentCFG->current_bb->add_IRInstr(IRInstr::cmp_lt, exprType, {resTemp, lhsTemp, rhsTemp});
        return resTemp;
      }
    }
  }

  virtual std::string visitGroupExprIR(const GroupExpr *ge) {
    return visitExprIR(ge->getSubExpr());
  }

  virtual std::string visitUnaryOpIR(const UnaryOp *unop) {
    std::string temp = visitExprIR(unop->getExpr());

    const Type* exprType = getExpressionType(unop);

    switch (unop->getKind()) {
      case UnaryOp::Kind::PRE_INC: {
        std::string resTmp = m_currentCFG->create_new_tempvar(exprType);
        std::string constTmp = m_currentCFG->create_new_tempvar(exprType);
        m_currentCFG->current_bb->add_IRInstr(IRInstr::ldconst, exprType, {constTmp, "1"});
        m_currentCFG->current_bb->add_IRInstr(IRInstr::add, exprType, {resTmp, temp, constTmp});
        m_currentCFG->current_bb->add_IRInstr(IRInstr::add, exprType, {temp, temp, constTmp});
        return resTmp;
      }
    }
  }

  virtual std::string visitDeclRefExprIR(const DeclRefExpr *ref) {
    switch (ref->getKind()) {
      case DeclRefExpr::Kind::RVALUE: {
        return ref->getDecl()->getName();
      }

      case DeclRefExpr::Kind::LVALUE: {
        std::string ptrVar = m_currentCFG->create_new_tempvar(getExpressionType(ref));
        int offset = m_currentCFG->get_var_index(ref->getDecl()->getName());
        m_currentCFG->current_bb->add_IRInstr(IRInstr::ldconst, new BuiltinType(BuiltinType::Kind::INT64_T), {ptrVar, std::to_string(offset)});
        m_currentCFG->current_bb->add_IRInstr(IRInstr::add, new BuiltinType(BuiltinType::Kind::INT64_T), {ptrVar, "!bp", ptrVar});

        return ptrVar;
      }
    }
  }

  virtual std::string visitLiteralExprIR(const LiteralExpr *le) {
    if (const IntegerLiteral *il = dynamic_cast<const IntegerLiteral *>(le)) {
      return visitIntegerLiteralIR(il);
    }
    if (const CharLiteral *cl = dynamic_cast<const CharLiteral *>(le)) {
      return visitCharLiteralIR(cl);
    }
  }

  virtual std::string visitIntegerLiteralIR(const IntegerLiteral *intLit) {
    std::string temp = m_currentCFG->create_new_tempvar(new BuiltinType(BuiltinType::Kind::INT64_T));
    m_currentCFG->current_bb->add_IRInstr(IRInstr::ldconst, new BuiltinType(BuiltinType::Kind::INT64_T), {temp, std::to_string(intLit->getValue())});
    return temp;
  }

  virtual std::string visitCharLiteralIR(const CharLiteral *charLit) {
    std::string temp = m_currentCFG->create_new_tempvar(new BuiltinType(BuiltinType::Kind::CHAR));
    m_currentCFG->current_bb->add_IRInstr(IRInstr::ldconst, new BuiltinType(BuiltinType::Kind::CHAR), {temp, std::to_string(charLit->getValue())});
    return temp;
  }

  virtual ErrorType visitIfStmt(const IfStmt *ifStmt) {
    visitExprIR(ifStmt->getCond());

    auto condBB = m_currentCFG->current_bb;

    auto thenBB = new BasicBlock(m_currentCFG, m_currentCFG->new_BB_name());
    m_currentCFG->add_bb(thenBB);
    m_currentCFG->current_bb = thenBB;
    visitStmt(ifStmt->getStmt());

    auto elseBB = new BasicBlock(m_currentCFG, m_currentCFG->new_BB_name());
    m_currentCFG->add_bb(elseBB);
    m_currentCFG->current_bb = elseBB;
    if (ifStmt->getElseStmt()) {
      visitStmt(ifStmt->getElseStmt());
    }

    auto afterIfBB = new BasicBlock(m_currentCFG, m_currentCFG->new_BB_name());
    m_currentCFG->add_bb(afterIfBB);
    m_currentCFG->current_bb = afterIfBB;

    afterIfBB->exit_true = condBB->exit_true;
    afterIfBB->exit_false = condBB->exit_false;

    condBB->exit_true = thenBB;
    condBB->exit_false = elseBB;

    thenBB->exit_true = afterIfBB;
    thenBB->exit_false = nullptr;

    elseBB->exit_true = afterIfBB;
    elseBB->exit_false = nullptr;

  }

  virtual ErrorType visitWhileStmt(const WhileStmt *whileStmt) {

    auto beforeWhileBB = m_currentCFG->current_bb;

    auto condBB = new BasicBlock(m_currentCFG, m_currentCFG->new_BB_name());
    m_currentCFG->add_bb(condBB);
    m_currentCFG->current_bb = condBB;
    visitExprIR(whileStmt->getCond());

    auto bodyBB = new BasicBlock(m_currentCFG, m_currentCFG->new_BB_name());
    m_currentCFG->add_bb(bodyBB);
    m_currentCFG->current_bb = bodyBB;
    visitStmt(whileStmt->getStmt());

    auto afterWhileBB = new BasicBlock(m_currentCFG, m_currentCFG->new_BB_name());
    m_currentCFG->add_bb(afterWhileBB);
    m_currentCFG->current_bb = afterWhileBB;

    afterWhileBB->exit_true = beforeWhileBB->exit_true;
    afterWhileBB->exit_false = beforeWhileBB->exit_false;

    beforeWhileBB->exit_true = condBB;
    beforeWhileBB->exit_false = nullptr;

    condBB->exit_true = bodyBB;
    condBB->exit_false = afterWhileBB;

    bodyBB->exit_true = condBB;
    bodyBB->exit_false = nullptr;
  }

  virtual std::string visitCallExprIR(const CallExpr* ce) {
    const Type* retType = getExpressionType(ce->getCallee());
    std::string temp = m_currentCFG->create_new_tempvar(retType);
    std::vector<std::string> irVec = {temp, visitExprIR(ce->getCallee())};
    for (auto arg : ce->getArgs()) {
      irVec.push_back(visitExprIR(arg));
    }
    m_currentCFG->current_bb->add_IRInstr(IRInstr::call, retType, irVec);

    return temp;
  }

  virtual ErrorType visitReturnStmt(const ReturnStmt *returnStmt) {
    if (returnStmt->getExpr()) {
      std::string temp = visitExprIR(returnStmt->getExpr());
      m_currentCFG->current_bb->add_IRInstr(IRInstr::ret, new BuiltinType(BuiltinType::Kind::INT32_T), {temp});
    } else {
      m_currentCFG->current_bb->add_IRInstr(IRInstr::ret, new BuiltinType(BuiltinType::Kind::VOID), {});
    }
  }

protected:
  std::vector<CFG*> m_cfgs;
  CFG* m_currentCFG;
};

#endif // IRGENERATOR_H