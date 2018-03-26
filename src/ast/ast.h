#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

class Decl {
public:
Decl(const std::string &m_name) : m_name(m_name) {}
    Decl() {}
  virtual ~Decl() = default;
  const std::string getExpr() const { return m_name; }
    

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

protected:
  Program *m_program;
};

class BuiltinType : public Type {
public:
  enum class Kind { INT32_T, INT64_T, CHAR, VOID };
  const Kind getKind() const { return m_kind; }
        
        BuiltinType(Kind m_kind) : m_kind(m_kind) {}

    protected:
        Kind m_kind;
};

class Param {
public:
  const std::string getName() const { return m_name; }
  const Type *getType() const { return m_type; }
        Param(const std::string &m_name, Type *m_type) : m_name(m_name),
                                                         m_type(m_type) {}
    protected:
        std::string m_name;
    Type* m_type;
};
class Stmt {
  public:
  virtual ~Stmt() = default;
};
class BlockStmt : public Stmt {
public:
  const std::vector<Stmt *> getBody() const { return m_body; }

protected:
  std::vector<Stmt *> m_body;
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

class Expr {};
class VarDecl : public Decl {
public:
VarDecl(const std::string &m_name, Type *m_type, Expr *m_initExpr)
                : Decl(m_name), m_type(m_type), m_initExpr(m_initExpr) {}
  const Type *getType() const { return m_type; }
  const Expr *getExpr() const { return m_initExpr; }

protected:

  Type *m_type;
  Expr *m_initExpr;
};

class DeclStmt : public Stmt {
public:
  const Decl *getDecl() const { return m_decl; }

protected:
  Decl *m_decl;
};

class ExprStmt : public Stmt {
public:
  const Expr *getExpr() const { return m_expr; }

protected:
  Expr *m_expr;
};

class IfStmt : public Stmt {
public:
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

  const Kind getKind() const { return m_kind; }
  const Expr *getLeftHandSide() const { return m_lhs; }
  const Expr *getRightHandSide() const { return m_rhs; }

protected:
  Kind m_kind;
  Expr *m_lhs;
  Expr *m_rhs;
};

class UnaryOp : public Expr {
public:
  enum class Kind { PLUS, MINUS, NOT, PRE_INC, PRE_DEC, POST_INC, POST_DEC };

  const Kind getKind() const { return m_kind; }
  const Expr *getExpr() const { return m_expr; }

protected:
  Kind m_kind;
  Expr *m_expr;
};

class CallExpr : public Expr {
public:
  const std::vector<Expr *> getArgs() const { return m_args; }
  const Expr *getCallerExpr() const { return m_callerExpr; }

protected:
  std::vector<Expr *> m_args;
  Expr *m_callerExpr;
};

class GroupExpr : public Expr {
public:
  const Expr *getSubExpr() const { return m_subExpr; }

protected:
  Expr *m_subExpr;
};

class LiteralExpr : public Expr {};

class IntegerLiteral : public LiteralExpr {
public:
  const int64_t getValue() const { return m_value; }

protected:
  int64_t m_value;
};

class CharLiteral : public LiteralExpr {
public:
  const char getValue() const { return m_value; }

protected:
  char m_value;
};

class DeclRefExpr : public Expr {
public:
  const Decl *getDecl() const { return m_decl; }
  const std::string getUnresolvedName() const { return m_unresolvedName; }

protected:
  Decl *m_decl;
  std::string m_unresolvedName;
};

#endif // AST_H
