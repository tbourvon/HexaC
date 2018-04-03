#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

class Decl {
public:
Decl(const std::string &m_name) : m_name(m_name) {}
  virtual ~Decl() = default;
  const std::string getName() const { return m_name; }
    

    protected:
    std::string m_name;
};
class Program {
public:
  Program(std::vector<Decl *> decls) : m_decls(decls) {}
  const std::vector<Decl *> getDecls() const { return m_decls; }

protected:
  std::vector<Decl *> m_decls;
};
class AST {
public:
  AST(Program *program) : m_program(program) {}
  const Program *getProgram() const { return m_program; }
  
protected:
    Program* m_program;
};

class Type {
  public:
  virtual ~Type() = default;
};

class BuiltinType : public Type {
public:
  enum class Kind { INT32_T, INT64_T, CHAR, VOID };
    Kind getKind() const { return m_kind; }
        
    BuiltinType(Kind m_kind) : m_kind(m_kind) {}

    virtual ~BuiltinType() {}

    protected:
        Kind m_kind;
};
class Stmt {
  public:
  virtual ~Stmt() = default;
};
class BlockStmt : public Stmt {
public:
    BlockStmt(std::vector<Stmt *> body) : m_body(body) {}
  const std::vector<Stmt *> getBody() const { return m_body; }

protected:
  std::vector<Stmt *> m_body;
};

class Expr {
public:
  virtual ~Expr() = default;
};

class VarDecl : public Decl {
public:
VarDecl(const std::string &m_name, Type *m_type, Expr *m_initExpr)
                : Decl(m_name), m_type(m_type), m_initExpr(m_initExpr) {}
  virtual ~VarDecl() = default;
  const Type *getType() const { return m_type; }
  const Expr *getExpr() const { return m_initExpr; }

protected:

  Type *m_type;
  Expr *m_initExpr;
};

class Param : public VarDecl {
public:
    Param(const std::string &m_name, Type *m_type, Expr *m_initExpr)
                : VarDecl(m_name, m_type, m_initExpr) {}

};

class FuncDecl : public Decl {
public:
FuncDecl(const std::string &m_name, Type *m_returnType,
                 const std::vector<Param *> &m_params, BlockStmt *m_body)
                : Decl(m_name), m_returnType(m_returnType), m_params(m_params),
                  m_body(m_body) {}
  const Type *getType() const { return m_returnType; }
  const std::vector<Param *> getParams() const { return m_params; }
  const BlockStmt *getBlock() const { return m_body; }

protected:
  Type *m_returnType;
  std::vector<Param *> m_params;
  BlockStmt *m_body;
};


class DeclStmt : public Stmt {
public:
    DeclStmt(Decl* decl) : m_decl(decl) {}
    const Decl *getDecl() const { return m_decl; }

protected:
    Decl *m_decl;
};

class ExprStmt : public Stmt {
public:
    ExprStmt(Expr* expr) : m_expr(expr) {}
  const Expr *getExpr() const { return m_expr; }

protected:
  Expr *m_expr;
};

class IfStmt : public Stmt {
public:
    IfStmt(Expr* cond, Stmt* stmt, Stmt* elseStmt) : m_cond(cond), m_stmt(stmt), m_elseStmt(elseStmt) {}

    const Expr *getCond() const { return m_cond; }
    const Stmt *getStmt() const { return m_stmt; }
    const Stmt *getElseStmt() const { return m_elseStmt; }

protected:
    Expr *m_cond;
    Stmt *m_stmt;
    Stmt *m_elseStmt;
};

class WhileStmt : public Stmt {
public:
    WhileStmt(Expr* cond, Stmt* stmt) : m_cond(cond), m_stmt(stmt) {}

  const Expr *getCond() const { return m_cond; }
  const Stmt *getStmt() const { return m_stmt; }

protected:
  Expr *m_cond;
  Stmt *m_stmt;
};

class BinaryOp : public Expr {
public:
  enum class Kind {
    MULT,
    DIV,
    MOD,
    ADD,
    SUB,
    ASSIGN,
    ASSIGN_MULT,
    ASSIGN_DIV,
    ASSIGN_MOD,
    ASSIGN_ADD,
    ASSIGN_SUB,
    EQ,
    NEQ,
    OR,
    AND,
    GT,
    LT,
    GE,
    LE
  };

   Kind getKind() const { return m_kind; }
  const Expr *getLeftHandSide() const { return m_lhs; }
  const Expr *getRightHandSide() const { return m_rhs; }

  BinaryOp(Kind kind, Expr* lhs, Expr* rhs) : m_kind(kind), m_lhs(lhs), m_rhs(rhs) {}

protected:
  Kind m_kind;
  Expr *m_lhs;
  Expr *m_rhs;
};

class UnaryOp : public Expr {
public:
  enum class Kind { PLUS, MINUS, NOT, PRE_INC, PRE_DEC, POST_INC, POST_DEC };

   Kind getKind() const { return m_kind; }
  const Expr *getExpr() const { return m_expr; }

    UnaryOp(Kind kind, Expr* expr) : m_kind(kind), m_expr(expr) {}

protected:
  Kind m_kind;
  Expr *m_expr;
};

class CallExpr : public Expr {
public:
    CallExpr(Expr* callee, std::vector<Expr*> args) : m_callee(callee), m_args(args) {}

    const std::vector<Expr *> getArgs() const { return m_args; }
    const Expr *getCallee() const { return m_callee; }
protected:
    Expr* m_callee;
    std::vector<Expr*> m_args;
};

class GroupExpr : public Expr {
public:
    GroupExpr(Expr* subExpr) : m_subExpr(subExpr) {}
    const Expr *getSubExpr() const { return m_subExpr; }

protected:
  Expr *m_subExpr;
};

class LiteralExpr : public Expr {};

class IntegerLiteral : public LiteralExpr {
public:
    IntegerLiteral(int64_t value) : m_value(value) {}
     int64_t getValue() const { return m_value; }

protected:
  int64_t m_value;
};

class CharLiteral : public LiteralExpr {
public:
    CharLiteral(char value) : m_value(value) {}
     char getValue() const { return m_value; }

protected:
  char m_value;
};

class DeclRefExpr : public Expr {
public:
    enum class Kind {
      RVALUE,
      LVALUE
    };

    DeclRefExpr(Decl* decl, Kind kind) : m_decl(decl), m_kind(kind) {}
    const Decl *getDecl() const { return m_decl; }
    Kind getKind() const { return m_kind; }

protected:
    Decl *m_decl;
    Kind m_kind;
};

#endif // AST_H
