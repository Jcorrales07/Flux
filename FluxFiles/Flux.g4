parser grammar Flux;
options { tokenVocab=FluxLexer; }

// Programa principal
program
    : importDeclaration* (declaration | statement | funcCall)* EOF
    ;

// Declaraciones
declaration
    : constDeclaration
    | varDeclaration
    | funcDeclaration
    | classDeclaration
    | importDeclaration
    | exportDeclaration
    ;

//Import Declaration
importDeclaration
    : 'from' IDENTIFIER 'import' importList ';'
    ;

importList
    : (importItem) (',' importItem)*
    ;

importItem
    : (UPPERCASE_IDENTIFIER | CLASS_IDENTIFIER | IDENTIFIER)
    ;

//Export Declaration
exportDeclaration
    : 'export' (
        classDeclaration
        | funcDeclaration
        | constDeclaration
    )
    ;

// Class Declaration
classDeclaration
    : 'class' CLASS_IDENTIFIER
      ('extends' CLASS_IDENTIFIER)?  // Optional inheritance
      '{'
        (publicBlock)?
        (privateBlock)?
      '}'
    ;

// Public Block in Class
publicBlock
    : 'public' '{'
        (varDeclaration
        | constructorDeclaration
        | methodDeclaration)*
      '}'
    ;

// Private Block in Class
privateBlock
    : 'private' '{'
        (varDeclaration
        | constructorDeclaration
        | methodDeclaration)*
      '}'
    ;

// Constructor Declaration
constructorDeclaration
    : CLASS_IDENTIFIER '(' paramList? ')'
      '{'
        (constructorInitStatement
        | assignmentStatement
        | superCall)*
      '}'
    ;

// Super Constructor Call
superCall
    : 'super' '(' (expr (',' expr)*)? ')' ';'
    ;

// Constructor Initialization Statement
constructorInitStatement
    : 'this' '.' IDENTIFIER '=' expr ';'
    ;

// Method Declaration with optional return type
methodDeclaration
    : type 'func' IDENTIFIER '(' paramList? ')' block
    | 'func' IDENTIFIER '(' paramList? ')' block
    ;

constDeclaration
    : 'const' type UPPERCASE_IDENTIFIER '=' (expr | arrayLiteral) ';'
    ;

varDeclaration
    : type IDENTIFIER ('=' (expr | arrayLiteral))? ';'
    | type IDENTIFIER '=' NEW CLASS_IDENTIFIER '(' (expr (',' expr)*)? ')' ';'
    ;

// Statements
statement
    : declaration
    | assignmentStatement
    | arrayAssignmentStatement
    | valueAccess
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
    : IDENTIFIER '=' NEW CLASS_IDENTIFIER '(' (expr (',' expr)*)? ')' ';'
    | IDENTIFIER assignOp expr ';'
    | THIS '.' IDENTIFIER assignOp expr ';'
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

valueAccess
    : IDENTIFIER '.' (funcCall | IDENTIFIER )?
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
    | '**'
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

// Class Instantiation
classInstantiation
    : CLASS_IDENTIFIER '(' (expr (',' expr)*)? ')'
    ;

term
    : factor
    | THIS ('.' IDENTIFIER)?
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
    | classInstantiation
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