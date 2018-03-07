parser grammar HexaCParser;

options {
	tokenVocab = HexaCLexer;
}

// Rules

program
  : toplevel_item*
  ;

toplevel_item
  : preproc_dir
  | decl
  ;

preproc_dir
  : HASH INCLUDE LT ID DOT ID GT
  ;

decl
  : func_decl
  | var_decl
  ;

func_decl
  : type ID OPEN_PAR param_list CLOSE_PAR block
  ;

type
  : INT32_T
  | INT64_T
  | CHAR
  | VOID
  ;

param_list
  : param (COMMA param)*
  |
  ;

param
  : type ID
  ;

block
  : OPEN_BRACE stmt_list CLOSE_BRACE
  ;

stmt_list
  : (stmt)*
  ;

stmt
  : var_decl
  | expr_stmt
  | if_stmt
  | while_stmt
  | block
  ;

var_decl
  : type ID SEMICOLON
  ;

expr_stmt
  : expr SEMICOLON
  ;

expr
  : binary_op
  ;

expr_lit
  : INT_LIT
  | CHAR_LIT
  ;

call_expr_
  : ID OPEN_PAR arg_list CLOSE_PAR
  | expr_lit
  ;

arg_list
  : expr (COMMA expr)*
  |
  ;

unary_op
  : OPEN_PAR unary_op CLOSE_PAR
  | PLUS unary_op
  | MINUS unary_op
  | PLUS_PLUS unary_op
  | MINUS_MINUS unary_op
  | NOT unary_op
  | unary_op PLUS_PLUS
  | unary_op MINUS_MINUS
  | call_expr_
  ;

binary_op
  : unary_op STAR binary_op
  | unary_op DIV binary_op
  | unary_op MOD binary_op
  | unary_op PLUS binary_op
  | unary_op MINUS binary_op
  | unary_op EQ binary_op
  | unary_op STAR_EQ binary_op
  | unary_op DIV_EQ binary_op
  | unary_op MOD_EQ binary_op
  | unary_op PLUS_EQ binary_op
  | unary_op MINUS_EQ binary_op
  | unary_op AND_AND binary_op
  | unary_op OR_OR binary_op
  | unary_op EQ_EQ binary_op
  | unary_op NOT_EQ binary_op
  | unary_op GT binary_op
  | unary_op LT binary_op
  | unary_op GE binary_op
  | unary_op LE binary_op
  | unary_op
  ;

if_stmt
  : IF OPEN_PAR expr CLOSE_PAR stmt (ELSE stmt)?
  ;

while_stmt
  : WHILE OPEN_PAR expr CLOSE_PAR stmt
  ;
