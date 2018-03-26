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
  : type_id=INT32_T
  | type_id=INT64_T
  | type_id=CHAR
  | type_id=VOID
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
  : lhs=expr STAR rhs=expr
  | expr DIV expr
  | expr MOD expr
  | expr PLUS expr
  | expr MINUS expr
  | expr EQ expr
  | expr STAR_EQ expr
  | expr DIV_EQ expr
  | expr MOD_EQ expr
  | expr PLUS_EQ expr
  | expr MINUS_EQ expr
  | expr AND_AND expr
  | expr OR_OR expr
  | expr EQ_EQ expr
  | expr NOT_EQ expr
  | expr GT expr
  | expr LT expr
  | expr GE expr
  | expr LE expr

  | OPEN_PAR unary_expr=expr CLOSE_PAR
  | PLUS expr
  | MINUS expr
  | PLUS_PLUS expr
  | MINUS_MINUS expr
  | NOT expr
  | expr PLUS_PLUS
  | expr MINUS_MINUS

  | call_expr

  | literal
  ;

call_expr
  : ID OPEN_PAR arg_list CLOSE_PAR
  ;

arg_list
  : expr (COMMA expr)*
  |
  ;

literal
  : INT_LIT
  | CHAR_LIT
  | ID
  ;

if_stmt
  : IF OPEN_PAR expr CLOSE_PAR stmtofif=stmt (ELSE stmtofelse=stmt)?
  ;

while_stmt
  : WHILE OPEN_PAR expr CLOSE_PAR stmt
  ;
