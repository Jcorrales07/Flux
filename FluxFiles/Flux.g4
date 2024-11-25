parser grammar Flux;
options { tokenVocab=FluxLexer; }

// Programa principal
program
    : (declaration
    | statement
    | funcCall)* EOF
    ;

// Declaraciones
declaration
    : constDeclaration
    | varDeclaration
    | funcDeclaration
    ;

constDeclaration
    : 'const' type UPPERCASE_IDENTIFIER '=' (expr | arrayLiteral) ';'
    ;

varDeclaration
    : type IDENTIFIER ('=' (expr | arrayLiteral))? ';'
    ;

// Statements
statement
    : declaration
    | assignmentStatement
    | arrayAssignmentStatement
    | ifStatement
    | forStatement
    | whileStatement
    | doWhileStatement   // Nuevo: do-while statement
    | breakStatement
    | continueStatement  // Nuevo: continue statement
    | returnStmt
    | block
    | expr ';'
    ;

// While statement
whileStatement
    : 'while' '(' expr ')' block
    ;

// Nuevo: Do-while statement
doWhileStatement
    : 'do' block 'while' '(' expr ')' ';'
    ;

// Break statement
breakStatement
    : 'break' ';'
    ;

// Nuevo: Continue statement
continueStatement
    : 'continue' ';'
    ;


// For loop statements
forStatement
    : 'for' '(' IDENTIFIER 'in' forRange ')' block
    ;

forRange
    : rangeExpr          // range(start, end)
    | expr               // Para iterar sobre arrays u otras secuencias
    ;

// Range expression para for loops
rangeExpr
    : 'range' '(' expr (',' expr (',' expr)?)? ')'  // Permite range(end) o range(start, end)
    ;

// Built-in function calls
builtInCall
    : PRINT_FUNC '(' expr ')'
    | rangeExpr
    ;

block
    : '{' statement* '}'
    ;

assignmentStatement
    : IDENTIFIER assignOp expr ';'
    ;

arrayAssignmentStatement
    : arrayAccess '=' expr ';'
    ;

// Array literal
arrayLiteral
    : '[' (expr (',' expr)*)? ']'
    ;

// Array access
arrayAccess
    : IDENTIFIER '[' expr ']'
    | UPPERCASE_IDENTIFIER '[' expr ']'
    ;

// Control de flujo
ifStatement
    : 'if' '(' expr ')' block
      ('elseif' '(' expr ')' block)*
      ('else' block)?
    ;

// Expresiones
expr
    : expr arithmeticOp term
    | expr compareOp term
    | expr logicalOp term
    | notExpr
    | term
    ;

// Operadores aritméticos
arithmeticOp
    : '+'
    | '-'
    | '*'
    | '/'
    | POWER
    | '%'
    ;

// Operadores de comparación
compareOp
    : '=='
    | '!='
    | '>='
    | '<='
    | '>'
    | '<'
    ;

// Operadores lógicos
logicalOp
    : AND
    | OR
    ;

assignOp
    : ASSIGN
    | ADD_ASSIGN
    | SUB_ASSIGN
    | MUL_ASSIGN
    | DIV_ASSIGN
    ;

notExpr
    : NOT expr
    ;

term
    : factor
    ;

factor
    : BOOL_LIT
    | DECIMAL_LIT
    | INT_LIT
    | STRING_LIT
    | IDENTIFIER
    | arrayAccess
    | funcCall
    | builtInCall        // Agregado: llamadas a funciones built-in
    | '(' expr ')'
    ;

// Funciones
funcDeclaration
    : type 'func' IDENTIFIER '(' paramList? ')' block
    | 'func' IDENTIFIER '(' paramList? ')' block
    ;

funcCall
    : IDENTIFIER '(' (expr (',' expr)*)? ')'
    ;

// Parámetros de funciones
paramList
    : param (',' param)*
    ;

param
    : type IDENTIFIER
    ;

// Return statement
returnStmt
    : 'return' expr? ';'
    ;

// Tipos
type
    : 'number'
    | 'string'
    | 'bool'
    | CLASS_IDENTIFIER
    ;