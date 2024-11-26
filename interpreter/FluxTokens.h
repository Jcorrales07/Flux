#ifndef FLUX_FLUXTOKENS_H
#define FLUX_FLUXTOKENS_H

#include "string"

enum class TokenType {
    // Variables y constantes
    CONST,            // Constante
    VAR_NUMBER,       // Variable de tipo numérico
    NUMBER,           // Valor numérico
    VAR_STRING,       // Variable de tipo texto
    STRING,           // Valor de texto
    VAR_BOOLEAN,      // Variable de tipo booleano
    TRUE,             // Valor booleano
    FALSE,            // Valor booleano
    IDENTIFIER,       // Identificadores de las variables, funciones, clases, etc.

    // Operadores de asignación
    ASSIGN,           // Operador de asignación

    ADD_ASSIGN,       // +=
    SUB_ASSIGN,       // -=
    MUL_ASSIGN,       // *=
    DIV_ASSIGN,       // /=

    // Operadores aritméticos
    ADD,              // +
    SUBSTRACT,        // -
    MULTIPLY,         // *
    DIVIDE,           // /
    MODULE,           // %

    // Operadores de comparación
    LESS,             // <
    GREATER,          // >
    LESS_EQUAL,       // <=
    GREATER_EQUAL,    // >=
    EQUAL,            // ==
    NOT_EQUAL,        // !=

    // Operadores lógicos
    AND,              // &&
    OR,               // ||
    NOT,              // !

    // Puntuación
    COMMA,            // ,
    DOT,              // .
    SEMICOLON,        // ;
    COLON,            // :
    LPAREN,           // (
    RPAREN,           // )
    LBRACE,           // {
    RBRACE,           // }
    LBRACK,           // [
    RBRACK,           // ]

    // Definición de estructuras de control
    IF,               // if
    ELSEIF,           // elseif
    ELSE,             // else
    FOR,              // for
    WHILE,            // while
    BREAK,            // break
    CONTINUE,         // continue
    PASS,             // pass
    TRY,              // try
    CATCH,            // catch
    FINALLY,          // finally
    THROW,            // throw

    // Definición de funciones
    FUNC,             // Función
    RETURN,           // return
    LAMBDA,           // Funciones anónimas (lambda)

    // Definición de POO (Programación Orientada a Objetos)
    CLASS,            // Clase
    SUPER,            // Para acceder a la clase padre
    NEW,              // Para crear nuevas instancias de clases
    THIS,             // Para hacer referencia a la instancia actual

    // Otros
    COMMENT,          // Commentarios
    ILLEGAL,          // Cualquier cosa no reconocida
    EOFF,             // Fin del archivo (End of File)
};

struct Token {
    // Información del token
    std::string lexeme;   // El token como tal
    TokenType type;       // Tipo de token

    // Dirección del token en el archivo
    int line = 0;         // Número de la línea donde el token está
    int column = 0;       // Número de columna donde el token está
    std::string file;     // Nombre del archivo donde está el token
};

#endif // FLUX_FLUXTOKENS_H

// NOTAS:
// THROW: Para lanzar una excepción o error
// FUNC: Define una función
// LAMBDA: Funciones anónimas (lambda)

// Nuevos tokens para POO:
// CLASS: Para definir una clase
// SUPER: Para acceder a la clase base o padre
// NEW: Para crear nuevas instancias de clases
// THIS: Para hacer referencia a la instancia actual