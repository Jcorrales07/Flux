lexer grammar FluxLexer;

CLASS        : 'class';
MODULE       : 'module';
STRUCT       : 'struct';
PUBLIC       : 'public:';
PRIVATE      : 'private:';
FUNC         : 'func';
RETURN       : 'return';
IF           : 'if';
ELSEIF       : 'elseif';
ELSE         : 'else';
WHILE        : 'while';
FOR          : 'for';
SWITCH       : 'switch';
CASE         : 'case';
DEFAULT      : 'default';
TRY          : 'try';
CATCH        : 'catch';
FINALLY      : 'finally';
IMPORT       : 'import';
FROM         : 'from';
CONST        : 'const';
NUMBER_VAR   : 'number';
STRING_VAR   : 'string';
BOOLEAN_VAR  : 'bool';
VOID_VAR     : 'void';
IDENTIFIER   : [a-zA-Z_][a-zA-Z0-9_]*;
CLASS_IDENTIFIER: [A-Z][a-zA-Z0-9_]*;

ASSIGN       : '=';
ADD_ASSIGN   : '+=';
SUB_ASSIGN   : '-=';
MUL_ASSIGN   : '*=';
DIV_ASSIGN   : '/=';

ADD          : '+';
SUBTRACT     : '-';
MULTIPLY     : '*';
DIVIDE       : '/';
MOD          : '%';
POWER        : '**';

LESS         : '<';
GREATER      : '>';
LESS_EQUAL   : '<=';
GREATER_EQUAL: '>=';
EQUAL        : '==';
NOT_EQUAL    : '!=';

AND          : '&&' ;
OR           : '||' ;
NOT          : '!'  ;

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

BOOL_LIT     : 'true' | 'false'; // tengo duda si dejarlo asi o si definirlo como palabra reservada
INT_LIT      : [0-9]+ ;
DECIMAL_LIT  : [0-9]+ '.' [0-9]+;
STRING_LIT   : '"' (~["\\] | '\\' .)* '"';

COMMENT      : '//' .*? '\n' -> skip;
BLOCK_COMMENT: '/**' .*? '**/' -> skip;
WS           : [ \t\r\n]+ -> skip;

ILLEGAL      : .;
