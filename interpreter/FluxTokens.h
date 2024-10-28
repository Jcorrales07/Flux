//
// Created by Corra on 10/28/2024.
//

#ifndef FLUX_FLUXTOKENS_H
#define FLUX_FLUXTOKENS_H

#include "string"

enum class TokenType {
    IDENTIFIER,  // Variables y constantes
    KEYWORD,     // Palabras reservadas
    INTEGER,     // Valores enteros
    FLOAT,       // Valores decimales
    STRING,      // Cadenas de texto
    OPERATOR,    // +, -, *, /, %, <, >, =
    PUNCTUATION, // ;, (, ), {, }, !
    ILLEGAL,     // Cualquier cosa que no este aceptado
    EOFF,         // End Of Flux File
};

enum class FluxOperator {
    // Operadores de Aritmetica
    ADD, SUBSTRACT, MULTIPLY, DIVIDE, MODULE,

    // Operadores de comparación
    LESS, GREATER, ASSIGN, LESS_EQUAL, GREATER_EQUAL,

    // Operadores logicos
    AND, OR, NOT, EQUAL, NOT_EQUAL,

    NA, // No Aplica
};

enum class FluxKeywords {
    // Definicion de variables y literales
    VAR, CONST,

    // Definicion de estructuras de control
    IF, ELSEIF, ELSE, FOR, WHILE, BREAK, CONTINUE, PASS, TRY, CATCH, FINALLY, THROW,

    // Definicion de funciones
    FUNC, RETURN, LAMBDA,
};

enum class FluxPunctuation {
    COMMA,          // ,
    LPAREN, RPAREN, // ()
    LBRACE, RBRACE, // {}
    LBRACK, RBRACK, // []
    EXCLAMATION,    // !
    NA,             // No Aplica
};

struct Token {
    // Informacion del token
    std::string lexeme;          // El token como tal
    TokenType type;             // Tipo de token
    FluxOperator opType;        // Si es un operador, especificar cual
    FluxPunctuation puncType;   // Si es un signo de punctuacion, especificar cual

    // Direccion del token en el archivo
    int line;                   // El numero de la linea en donde el token esta
    int column;                 // El numero de columna en donde el token esta
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