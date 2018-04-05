#ifndef ASTPRINTER_H
#define ASTPRINTER_H

#include <iostream>
#include "ast.h"
#include "astvisitor.h"

using namespace HexaC;

class ASTPrinter : public ASTVisitor {
public:
  ASTPrinter() {}

  virtual ErrorType visitProgram(const Program *program) override {
    prettyPrint("Program");

    pushLevel();
    for (auto decl : program->getDecls()) {
      visitDecl(decl);
    }
    popLevel();
  }

  virtual ErrorType visitFuncDecl(const FuncDecl *fd) override {
      std::string printString = "FuncDecl '" + typeToString(fd->getType()) + " " + fd->getName() + "' (";

      std::vector<Param *> params = fd->getParams();
      bool first = true;
      for (Param* param : params) {
        if (first) {
          first = false;
        } else {
          printString += ", ";
        }

        printString += typeToString(param->getType()) + " " + param->getName();
        // visit params[i]
      }
      printString += ")";

      prettyPrint(printString);

      pushLevel();
      visitBlockStmt(fd->getBlock());
      popLevel();
  }

  virtual ErrorType visitVarDecl(const VarDecl *vd) override {
      prettyPrint("VarDecl '" + typeToString(vd->getType()) + " " + vd->getName() + "'");
      pushLevel();
      visitExpr(vd->getExpr());
      popLevel();
  }

  virtual ErrorType visitBlockStmt(const BlockStmt *block) override {
    std::vector<Stmt *> stmts = block->getBody();
    for (int i = 0; i < stmts.size(); i++) {
      visitStmt(stmts[i]);
    }
  }

  virtual ErrorType visitBinaryOp(const BinaryOp *binop) override {
    prettyPrint("BinaryOp '" + binopKindToString(binop->getKind()) + "'");
    pushLevel();
    visitExpr(binop->getLeftHandSide());
    visitExpr(binop->getRightHandSide());
    popLevel();
  }

  virtual ErrorType visitUnaryOp(const UnaryOp *unop) override {
    prettyPrint("UnaryOp '" + unopKindToString(unop->getKind()) + "'");
    pushLevel();
    visitExpr(unop->getExpr());
    popLevel();
  }

  virtual ErrorType visitDeclRefExpr(const DeclRefExpr *ref) {
    prettyPrint("DeclRefExpr '" + ref->getDecl()->getName() + "' " + (ref->getKind() == DeclRefExpr::Kind::LVALUE ? "lvalue" : "rvalue"));
  }

  virtual ErrorType visitIntegerLiteral(const IntegerLiteral *intLit) {
    prettyPrint("IntegerLiteral '" + std::to_string(intLit->getValue()) + "'");
  }

  virtual ErrorType visitCharLiteral(const CharLiteral *charLit) {
    prettyPrint("CharLiteral '" + std::to_string(charLit->getValue()) + "'");
  }

  virtual ErrorType visitReturnStmt(const ReturnStmt *returnStmt) {
    prettyPrint("ReturnStmt");
    pushLevel();
    visitExpr(returnStmt->getExpr());
    popLevel();
  }

  virtual ErrorType visitIfStmt(const IfStmt *ifStmt) {
    prettyPrint("IfStmt");
    pushLevel();
    visitExpr(ifStmt->getCond());
    visitStmt(ifStmt->getStmt());
    if (ifStmt->getElseStmt()) {
      visitStmt(ifStmt->getElseStmt());
    }
    popLevel();
  }

  virtual ErrorType visitWhileStmt(const WhileStmt *whileStmt) {
    prettyPrint("WhileStmt");
    pushLevel();
    visitExpr(whileStmt->getCond());
    visitStmt(whileStmt->getStmt());
    popLevel();
  }

  virtual ErrorType visitCallExpr(const CallExpr* ce) {
    prettyPrint("CallExpr");
    pushLevel();
    visitExpr(ce->getCallee());
    for (auto arg : ce->getArgs()) {
      visitExpr(arg);
    }
    popLevel();
  }

protected:
  void prettyPrint(const std::string& content) {
    std::cout << m_currentPrefix << "-" << content << std::endl;
  }

  void pushLevel() {
    m_currentPrefix += " |";
  }

  void popLevel() {
    m_currentPrefix.resize(m_currentPrefix.size() - 2);
  }

  std::string typeToString(const Type* type) {
    if (auto builtin = dynamic_cast<const BuiltinType*>(type)) {
      switch (builtin->getKind()) {
        case BuiltinType::Kind::CHAR: return "char";
        case BuiltinType::Kind::INT32_T: return "int32_t";
        case BuiltinType::Kind::INT64_T: return "int64_t";
        case BuiltinType::Kind::VOID: return "void";
      }
    }
  }

  std::string binopKindToString(BinaryOp::Kind kind) {
    switch (kind) {
      case BinaryOp::Kind::ADD: return "+";
      case BinaryOp::Kind::AND: return "&&";
      case BinaryOp::Kind::BAND: return "&";
      case BinaryOp::Kind::ASSIGN: return "=";
      case BinaryOp::Kind::ASSIGN_ADD: return "+=";
      case BinaryOp::Kind::ASSIGN_DIV: return "/=";
      case BinaryOp::Kind::ASSIGN_MOD: return "%=";
      case BinaryOp::Kind::ASSIGN_MULT: return "*=";
      case BinaryOp::Kind::ASSIGN_SUB: return "-=";
      case BinaryOp::Kind::ASSIGN_OR: return "|=";
      case BinaryOp::Kind::ASSIGN_AND: return "&=";
      case BinaryOp::Kind::ASSIGN_XOR: return "^=";
      case BinaryOp::Kind::DIV: return "/";
      case BinaryOp::Kind::EQ: return "==";
      case BinaryOp::Kind::GE: return ">=";
      case BinaryOp::Kind::GT: return ">";
      case BinaryOp::Kind::LE: return "<=";
      case BinaryOp::Kind::LT: return "<";
      case BinaryOp::Kind::MOD: return "%";
      case BinaryOp::Kind::MULT: return "*";
      case BinaryOp::Kind::NEQ: return "!=";
      case BinaryOp::Kind::OR: return "||";
      case BinaryOp::Kind::BOR: return "|";
      case BinaryOp::Kind::XOR: return "^";
      case BinaryOp::Kind::SUB: return "-";
      case BinaryOp::Kind::LSH: return "<<";
      case BinaryOp::Kind::RSH: return ">>";
      case BinaryOp::Kind::COMMA: return ",";
    }
  }

  std::string unopKindToString(UnaryOp::Kind kind) {
    switch (kind) {
      case UnaryOp::Kind::MINUS: return "- (prefix)";
      case UnaryOp::Kind::BNOT: return "~ (prefix)";
      case UnaryOp::Kind::NOT: return "! (prefix)";
      case UnaryOp::Kind::PLUS: return "+ (prefix)";
      case UnaryOp::Kind::POST_DEC: return "-- (postfix)";
      case UnaryOp::Kind::POST_INC: return "++ (postfix)";
      case UnaryOp::Kind::PRE_DEC: return "-- (prefix)";
      case UnaryOp::Kind::PRE_INC: return "++ (prefix)";
    }
  }

  std::string m_currentPrefix;
};

#endif // ASTPRINTER_H