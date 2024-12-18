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
    VOID,             // Sin Valor
    VAR_BOOLEAN,      // Variable de tipo booleano
    TRUE,             // Valor booleano
    FALSE,            // Valor booleano
    IDENTIFIER,       // Identificadores de las variables, funciones, clases, etc.
    CLASS_IDENTIFIER,
    UPPERCASE_IDENTIFIER,

    // Salidas
    PRINT,

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
    MOD,              // %
    POWER,            // **

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
    IN,               // in
    WHILE,            // while
    BREAK,            // break
    CONTINUE,         // continue
    PASS,             // pass

    SWITCH,
    CASE,
    DEFAULT,

    TRY,              // try
    CATCH,            // catch
    FINALLY,          // finally
    THROW,            // throw
    ERROR,

    // Definición de funciones
    FUNC,             // Función
    RETURN,           // return
    LAMBDA,           // Funciones anónimas (lambda)

    // Definición de POO (Programación Orientada a Objetos)
    CLASS,            // Clase
    SUPER,            // Para acceder a la clase padre
    EXTENDS,          // Para manejar la herencia
    PUBLIC,           // Para propiedades publicas en la clase
    PRIVATE,          // Para propiedades privadas en la clase
    NEW,              // Para crear nuevas instancias de clases
    THIS,             // Para hacer referencia a la instancia actual

    EXPORT,
    IMPORT,
    FROM,

    // Otros
    COMMENT,          // Comentarios
    BLOCK_COMMENT,    // Comentario en bloque
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