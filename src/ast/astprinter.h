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

  virtual ErrorType visitDecl(const Decl *decl) override {
    if (const FuncDecl *fd = dynamic_cast<const FuncDecl *>(decl)) {
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
      visitBlock(fd->getBlock());
      popLevel();
    }
    if (const VarDecl *vd = dynamic_cast<const VarDecl *>(decl)) {
        prettyPrint("VarDecl '" + typeToString(vd->getType()) + " " + vd->getName() + "'");
        pushLevel();
        visitExpr(vd->getExpr());
        popLevel();
    }
  }
  virtual ErrorType visitExpr(const Expr *expr) override {}

  virtual ErrorType visitBlock(const BlockStmt *block) override {
    std::vector<Stmt *> stmts = block->getBody();
    for (int i = 0; i < stmts.size(); i++) {
      visitStmt(stmts[i]);
    }
  }

  virtual ErrorType visitStmt(const Stmt *stmt) override {
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

  std::string m_currentPrefix;
};

#endif // ASTPRINTER_H