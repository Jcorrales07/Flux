//
// Created by Corra on 10/28/2024.
//

#ifndef FLUX_FLUXTOKENS_H
#define FLUX_FLUXTOKENS_H

#include "string"

enum class TokenType {
    // Variables y constantes
    CONST,
    VAR_NUMBER,     // Variable de tipo numerico
    NUMBER,         // Valor numerico
    VAR_STRING,     // Variable de tipo texto
    STRING,         // Valor de texto
    VAR_BOOLEAN,    // Variable de tipo booleano
    TRUE,        // Valor booleano
    FALSE,
    IDENTIFIER,  // Identificadores de las variables, funciones, classes y etc
    ASSIGN,


    // Keywords
    // Definicion de estructuras de control
    IF, ELSEIF, ELSE, FOR, WHILE, BREAK, CONTINUE, PASS, TRY, CATCH, FINALLY, THROW,

    // Definicion de funciones
    FUNC, RETURN, LAMBDA,

    //OPERATOR,    +, -, *, /, %,
    // Operadores de Aritmetica
    ADD, SUBSTRACT, MULTIPLY, DIVIDE, MODULE,

    // Operadores de comparación  <, >, =, <=, >=, ==, !=
    LESS, GREATER, LESS_EQUAL, GREATER_EQUAL, EQUAL, NOT_EQUAL,

    // Operadores Logicos &&, ||, !
    AND, OR, NOT,

    //PUNCTUATION: ,, (, ), {, }, !
    COMMA, SEMICOLON,   // , ;
    LPAREN, RPAREN,     // ()
    LBRACE, RBRACE,     // {}
    LBRACK, RBRACK,     // []

    ILLEGAL,     // Cualquier cosa que no este reconocido
    EOFF,         // End Of Flux File
};

struct Token {
    // Informacion del token
    std::string lexeme;         // El token como tal
    TokenType type;             // Tipo de token

    // Direccion del token en el archivo
    int line = 0;                   // El numero de la linea en donde el token esta
    int column = 0;                 // El numero de columna en donde el token esta
    std::string file;           // El nombre del archivo en donde esta el token
};

#endif //FLUX_FLUXTOKENS_H

// NOTAS
// THROW: Para lanzar una excepcion u error
// FUNC: definir una funcion
// LAMBDA: funciones anonimas


// Por añadir
// Definicion de POO
// CLASS, SUPER,