parser grammar Flux;
options { tokenVocab=FluxLexer; }

program
    : (statement
    | funcDec
    | funcCall
    | ifStatement)* EOF
    ;

// statement
statement: type IDENTIFIER '=' expr ';'
         | type IDENTIFIER ';'
         | expr ';'
         ;

// declaración de funciones
funcDec : type 'func' IDENTIFIER '(' (paramList)? ')' '{' statement* (returnStmt)? '}'
        | 'func' IDENTIFIER '(' (paramList)? ')' '{' statement* (returnStmt)? '}'; // para void

// Lista de parámetros: tipo + identificador, separados por comas
paramList : param (',' param)*;

// Un solo parámetro: tipo + identificador
param : type IDENTIFIER;

// expresiones
expr: expr '+' term
    | expr '-' term
    | expr op term
    | term
    ;

term: term '*' factor
    | term '/' factor
    | factor
    ;

factor
    : BOOL_LIT
    | DECIMAL_LIT
    | INT_LIT
    | STRING_LIT
    | IDENTIFIER
    | '(' expr ')'
    | factor POWER factor
    ;

op  : AND
    | OR
    |'=='
    | '>='
    | '<='
    | '>'
    | '<'
    | '!='
    ;

funcCall : IDENTIFIER '(' expr (',' expr)* ')' ';';

ifStatement : 'if' '(' expr ')' '{' statement* '}'
            ('elseif' '(' expr ')' '{' statement* '}')*
            ('else' '{' statement* '}')? ;

// return para funciones con tipo
returnStmt : 'return' expr? ';';  // Return opcional si tiene tipo

type: 'number'
    | 'string'
    | 'bool'
    | CLASS_IDENTIFIER
    ;
