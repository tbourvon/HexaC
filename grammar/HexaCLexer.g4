lexer grammar HexaCLexer;

// Terminals

IF : 'if' ;
ELSE : 'else' ;
WHILE : 'while' ;
RETURN : 'return' ;
INT32_T : 'int32_t' ;
INT64_T : 'int64_t' ;
CHAR : 'char' ;
VOID : 'void' ;
INCLUDE : 'include' ;
INT_LIT : ('0'..'9')+ ;
CHAR_LIT : '\'' .*? '\'' ;
OPEN_PAR : '(' ;
CLOSE_PAR : ')' ;
OPEN_BRACE : '{' ;
CLOSE_BRACE : '}' ;
OPEN_BRACKET : '[' ;
CLOSE_BRACKET : ']' ;
SEMICOLON : ';' ;
STAR : '*' ;
PLUS : '+' ;
DIV : '/' ;
MINUS : '-' ;
MOD : '%' ;
EQ : '=' ;
PLUS_EQ : '+=' ;
MINUS_EQ : '-=' ;
DIV_EQ : '/=' ;
STAR_EQ : '*=' ;
MOD_EQ : '%=' ;
AND_EQ : '&=' ;
OR_EQ : '|=' ;
XOR_EQ : '^=' ;
EQ_EQ : '==' ;
NOT_EQ : '!=' ;
GT : '>' ;
LT : '<' ;
GE : '>=' ;
LE : '<=' ;
NOT : '!' ;
PLUS_PLUS : '++' ;
MINUS_MINUS : '--' ;
COMMA : ',' ;
AND_AND : '&&' ;
OR_OR : '||' ;
AND : '&' ;
OR : '|' ;
LSH : '<<' ;
RSH : '>>' ;
XOR : '^' ;
TILDE : '~' ;
HASH : '#' ;
DOT : '.' ;
ID : [_a-zA-Z][_a-zA-Z0-9]* ;

WS: [ \n\t\r]+ -> channel(HIDDEN);