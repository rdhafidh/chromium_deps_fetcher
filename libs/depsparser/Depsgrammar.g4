grammar Depsgrammar;

prog:   expr+ EOF;

expr:   varline
   ;

varline:  
   ID EQ  rightexpr  
    ;

rightexpr :  
    bentuktwojsonval | basicvalue | bentukonejsonval |   
   ;

bentukonejsonval :
   '[' string?  (COMMA string )* COMMA? ']'
    ;

bentuktwojsonval :
    '{' singledictexpr?  (COMMA singledictexpr )* COMMA? '}'
   ;

singledictexpr :
    string ':' basicvalue
   ;

basicvalue :
	True
	| False
	| string
	| NUM
	| varfunc
	|  bentuktwojsonval
	;


varfunc :
 Var '(' string ')'
 ;

string :
	SIMPLESTRINGEXPRDOUBLEQUOTE
	| SIMPLESTRINGEXPRSINGLEQUOTE
;

Var : 'Var' ;
COMMA : ',' ;
NUM : [0-9]+;
True : [tT] [Rr] [Uu] [Ee];
False: [Ff] [Aa] [Ll] [Ss] [Ee];
ID : [a-zA-Z0-9_]+;

fragment SIMPLESTRINGEXPRDOUBLEQUOTEBASE :   ~ ( '\n' | '\r' | '"' )*  ;
SIMPLESTRINGEXPRDOUBLEQUOTE: '"' SIMPLESTRINGEXPRDOUBLEQUOTEBASE '"' ;
fragment SIMPLESTRINGEXPRSINGLEQUOTEBASE :   ~ ( '\n' | '\r' | '\'' )* ;
SIMPLESTRINGEXPRSINGLEQUOTE : '\'' SIMPLESTRINGEXPRSINGLEQUOTEBASE '\'' ;
EQ : '=';
COMMENT:
  '#' ~ ( '\n' | '\r' )* '\n' -> skip ;

WS : [ \n\t\r]+ -> skip ;