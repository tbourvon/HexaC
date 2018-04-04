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
  | return_stmt
  ;

var_decl
  : type ID (EQ expr)? SEMICOLON
  ;

expr_stmt
  : expr SEMICOLON
  ;

expr returns[bool postfix]
  : bin_lhs=expr bin_op=STAR bin_rhs=expr
  | bin_lhs=expr bin_op=DIV bin_rhs=expr
  | bin_lhs=expr bin_op=MOD bin_rhs=expr
  | bin_lhs=expr bin_op=PLUS bin_rhs=expr
  | bin_lhs=expr bin_op=MINUS bin_rhs=expr
  | bin_lhs=expr bin_op=EQ bin_rhs=expr
  | bin_lhs=expr bin_op=STAR_EQ bin_rhs=expr
  | bin_lhs=expr bin_op=DIV_EQ bin_rhs=expr
  | bin_lhs=expr bin_op=MOD_EQ bin_rhs=expr
  | bin_lhs=expr bin_op=PLUS_EQ bin_rhs=expr
  | bin_lhs=expr bin_op=MINUS_EQ bin_rhs=expr
  | bin_lhs=expr bin_op=AND_AND bin_rhs=expr
  | bin_lhs=expr bin_op=OR_OR bin_rhs=expr
  | bin_lhs=expr bin_op=EQ_EQ bin_rhs=expr
  | bin_lhs=expr bin_op=NOT_EQ bin_rhs=expr
  | bin_lhs=expr bin_op=GT bin_rhs=expr
  | bin_lhs=expr bin_op=LT bin_rhs=expr
  | bin_lhs=expr bin_op=GE bin_rhs=expr
  | bin_lhs=expr bin_op=LE bin_rhs=expr

  | OPEN_PAR group_expr=expr CLOSE_PAR

  | un_op=PLUS un_expr=expr { $postfix = false; }
  | un_op=MINUS un_expr=expr { $postfix = false; }
  | un_op=PLUS_PLUS un_expr=expr { $postfix = false; }
  | un_op=MINUS_MINUS un_expr=expr { $postfix = false; }
  | un_op=NOT un_expr=expr { $postfix = false; }
  | un_expr=expr un_op=PLUS_PLUS { $postfix = true; }
  | un_expr=expr un_op=MINUS_MINUS { $postfix = true; }

  | callee=expr OPEN_PAR arg_list CLOSE_PAR

  | literal
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
  : IF OPEN_PAR expr CLOSE_PAR stmt_if=stmt (ELSE stmt_else=stmt)?
  ;

while_stmt
  : WHILE OPEN_PAR expr CLOSE_PAR stmt
  ;

return_stmt
  : RETURN (expr)? SEMICOLON
  ;
