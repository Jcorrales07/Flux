lexer grammar FluxLexer;

CONST        : 'const';
NUMBER_VAR   : 'number';
STRING_VAR   : 'string';
BOOLEAN_VAR  : 'bool';
TRUE         : 'true';
FALSE        : 'false';
IDENTIFIER   : [a-zA-Z_][a-zA-Z0-9_]*;

ASSIGN       : '=';
ADD_ASSIGN   : '+=';
SUB_ASSIGN   : '-=';
MUL_ASSIGN   : '*=';
DIV_ASSIGN   : '/=';

ADD          : '+';
SUBSTRACT    : '-';
MULTIPLY     : '*';
DIVIDE       : '/';
MODULE       : '%';

LESS         : '<';
GREATER      : '>';
LESS_EQUAL   : '<=';
GREATER_EQUAL: '>=';
EQUAL        : '==';
NOT_EQUAL    : '!=';

AND          : '&&';
OR           : '||';
NOT          : '!';

COMMA        : ',';
DOT          : '.';
SEMICOLON    : ';';
COLON        : ':';
LPAREN       : '(';
RPAREN       : ')';
LBRACE       : '{';
RBRACE       : '}';
LBRACK       : '[';
RBRACK       : ']';

IF           : 'if';
ELSEIF       : 'elseif';
ELSE         : 'else';
FOR          : 'for';
WHILE        : 'while';
BREAK        : 'break';
CONTINUE     : 'continue';
PASS         : 'pass';
TRY          : 'try';
CATCH        : 'catch';
FINALLY      : 'finally';
THROW        : 'throw';

FUNC         : 'func';
RETURN       : 'return';
LAMBDA       : 'lambda';

CLASS        : 'class';
SUPER        : 'super';
NEW          : 'new';
THIS         : 'this';

NUMBER_LIT   : [0-9]+;
STRING_LIT   : '"' .*? '"';

COMMENT      : '//' .*? '\n' -> skip;
BLOCK_COMMENT: '/**' .*? '**/' -> skip;
WS           : [ \t\r\n]+ -> skip;

ILLEGAL      : .;
