lexer grammar FluxLexer;

CLASS        : 'class';
EXTENDS      : 'extends';
PUBLIC       : 'public';
PRIVATE      : 'private';
SUPER        : 'super';
THIS         : 'this';

EXPORT       : 'export';
IMPORT       : 'import';
FROM         : 'from';

STRUCT       : 'struct';

FUNC         : 'func';
RETURN       : 'return';

IF           : 'if';
ELSEIF       : 'elseif';
ELSE         : 'else';

WHILE        : 'while';
DO           : 'do';
BREAK        : 'break';
CONTINUE     : 'continue';

FOR          : 'for';
IN           : 'in';

SWITCH       : 'switch';
CASE         : 'case';
DEFAULT      : 'default';

TRY          : 'try';
CATCH        : 'catch';
FINALLY      : 'finally';

CONST        : 'const';
NUMBER_VAR   : 'number';
STRING_VAR   : 'string';
BOOLEAN_VAR  : 'bool';

UPPERCASE_IDENTIFIER: [A-Z][A-Z0-9_]*;  // Para constantes
CLASS_IDENTIFIER: [A-Z][a-zA-Z0-9_]*;
IDENTIFIER   : [a-zA-Z_][a-zA-Z0-9_]*;

PRINT_FUNC: 'print';
RANGE_FUNC: 'range';

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
