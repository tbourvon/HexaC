#ifndef AST_H
#define AST_H

#include <vector>

class AST
{
protected:
    Program* m_program;
};

class Program {
protected:
    std::vector<Decl*> m_decls;
};

class Type {

};

class BuiltinType : public Type {
public:
    enum class Kind {
        INT32_T,
        INT64_T,
        CHAR,
        VOID
    };

protected:
    Kind m_kind;
};

class Decl {
protected:
    std::string m_name;
};

class FuncDecl : public Decl {
protected:
    Type* m_returnType;
    std::vector<Param*> m_params;
    BlockStmt* m_body;
};

class Param {
protected:
    std::string m_name;
    Type* m_type;
};

class VarDecl: public Decl {
protected:
    Type* m_type;
    Expr* m_initExpr;
};

class Stmt {

};

class BlockStmt : public Stmt {
protected:
    std::vector<Stmt*> m_stmts;
};

class DeclStmt : public Stmt {
protected:
    Decl* m_decl;
};

class ExprStmt : public Stmt {
protected:
    Expr* m_expr;
};

class IfStmt : public Stmt {
protected:
    Expr* m_cond;
    Stmt* m_stmt;
    Stmt* m_elseStmt;
};

class WhileStmt : public Stmt {
protected:
    Expr* m_cond;
    Stmt* m_stmt;
};

class Expr {

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

protected:
    Kind m_kind;
    Expr* m_lhs;
    Expr* m_rhs;
};

class UnaryOp : public Expr {
public:
    enum class Kind {
        PLUS,
        MINUS,
        NOT,
        PRE_INC,
        PRE_DEC,
        POST_INC,
        POST_DEC
    };

protected:
    Kind m_kind;
    Expr* m_expr;
};

class CallExpr : public Expr {
protected:
    std::vector<Expr*> m_args;
    Expr* m_callerExpr;
};

class GroupExpr : public Expr {
protected:
    Expr* m_subExpr;
};

class LiteralExpr : public Expr {

};

class IntegerLiteral : public LiteralExpr {
protected:
    int64_t m_value;
};

class CharLiteral : public LiteralExpr {
protected:
    char m_value;
};

class DeclRefExpr : public Expr {
protected:
    Decl* m_decl;
};

#endif // AST_H