#include "FluxLexer.h"
#include <cctype>
#include <stdexcept>
#include <sstream>
#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <regex>

using std::pmr::unordered_map;

// Constructor: abre el archivo y verifica si es .flux
FluxLexer::FluxLexer(const std::string &filename) : filename(filename) {
    if (!isFluxFile()) {
        throw std::runtime_error("Error: The file is not of extension .flux");
    }

    fileStream.open(filename);

    if (!fileStream.is_open()) {
        throw std::runtime_error("Error: Can't read the file");
    }
}

// Verifica que el archivo tenga extensión .flux
bool FluxLexer::isFluxFile() {
    std::filesystem::path filePath = filename;
    return filePath.extension() == ".flux";
}

// Analizar esta funcion, debe de haber una mejor forma de iterar en los caracteres ::
// Lee el siguiente carácter del archivo
char FluxLexer::readNextChar() {
    column++;
    return fileStream.get();
}

bool FluxLexer::isEOF() {
    return fileStream.eof();
}

// Tokeniza el contenido del archivo
std::vector<Token> FluxLexer::tokenize() {
    std::vector<Token> tokens;

    currentChar = readNextChar();
    // Itera cuando tengamos caracteres que leer
    while (!isEOF()) {

        // extraemos el token
        Token token = nextToken();

        // si no es de tipo EOF
        if (token.type != TokenType::ILLEGAL && token.type != TokenType::EOFF) {
            // guardamos el token
            tokens.push_back(token);
        } else if (token.type == TokenType::ILLEGAL) {
            std::ostringstream errorMessage;
            errorMessage << "Error: Unexpected token '" << token.lexeme
                         << "' at line: " << line
                         << ", column: " << column
                         << " in file: " << filename;

            throw std::runtime_error(errorMessage.str());
        }
    }

    Token eofToken = {"EOFF", TokenType::EOFF, line, column, filename};
    tokens.push_back(eofToken);

    return tokens;
}

// Genera el siguiente token basado en el carácter actual
Token FluxLexer::nextToken() {
    // Ignoramos los espacios en blanco
    skipWhitespace();

    // Si es un identificador (letras o guion bajo)
    if (std::isalpha(currentChar) || currentChar == '_') {
        return makeIdentifierOrKeyword();
    } else if (std::isdigit(currentChar)) {
        return makeNumber();
    } else if (currentChar == '"') {
        return makeString();
    } else if (currentChar == '/' && (fileStream.peek() == '/' || fileStream.peek() == '*')) {
        return makeComment();
    }

    // Operadores y delimitadores
    Token token;
    switch (currentChar) {
        case '(': token = {std::string(1, currentChar), TokenType::LPAREN, line, column, filename}; break;
        case ')': token = {std::string(1, currentChar), TokenType::RPAREN, line, column, filename}; break;
        case '{': token = {std::string(1, currentChar), TokenType::LBRACE, line, column, filename}; break;
        case '}': token = {std::string(1, currentChar), TokenType::RBRACE, line, column, filename}; break;
        case '[': token = {std::string(1, currentChar), TokenType::LBRACK, line, column, filename}; break;
        case ']': token = {std::string(1, currentChar), TokenType::RBRACK, line, column, filename}; break;
        case '=':
            // Verificar si es un operador de asignación (== o =)
            currentChar = readNextChar(); // Leemos el siguiente carácter
            if (currentChar == '=') {
                token = {std::string("=="), TokenType::EQUAL, line, column, filename}; // Es un "=="
            } else {
                token = {std::string("="), TokenType::ASSIGN, line, column, filename}; // Es un "="
            }
        break;
        case '>':
            currentChar = readNextChar(); // Leemos el siguiente carácter
            if (currentChar == '=') {
                token = {std::string(">="), TokenType::GREATER_EQUAL, line, column, filename}; // Es un "=="
            } else {
                token = {std::string(">"), TokenType::GREATER, line, column, filename}; // Es un "="
            }
            break;
        case '<':
            currentChar = readNextChar(); // Leemos el siguiente carácter
            if (currentChar == '=') {
                token = {std::string("<="), TokenType::LESS_EQUAL, line, column, filename}; // Es un "<="
            } else {
                token = {std::string(1, currentChar), TokenType::LESS, line, column, filename}; // Es un "<"
            }
        break;
        case ',': token = {std::string(1, currentChar), TokenType::COMMA, line, column, filename}; break;
        case '!':
            currentChar = readNextChar();
        if (currentChar == '=') {
            token = {std::string("!="), TokenType::NOT_EQUAL, line, column, filename}; // Es un "!="
        } else {
            token = {std::string("!"), TokenType::NOT, line, column, filename}; // Es un "!"
        }
        break;
        case ';': token = {std::string(1, currentChar), TokenType::SEMICOLON, line, column, filename}; break;

        case ':': token = {std::string(1, currentChar), TokenType::COLON, line, column, filename}; break;

        // Detectamos operadores compuestos como +=, -=, *=, /=, etc.
        case '+':
            currentChar = readNextChar();
            if (currentChar == '=') {
                token = {std::string("+="), TokenType::ADD_ASSIGN, line, column, filename};
            } else if (currentChar == ';'){
                token = {std::string("="), TokenType::SEMICOLON, line, column, filename};
            } else {
                token = {std::string("+"), TokenType::ADD, line, column, filename};
            }
            break;

        case '-':
            currentChar = readNextChar();
            if (currentChar == '=') {
                token = {std::string("-="), TokenType::SUB_ASSIGN, line, column, filename};
            } else if (currentChar == ';'){
                token = {std::string("="), TokenType::SEMICOLON, line, column, filename};
            }else {
                token = {std::string("-"), TokenType::SUBSTRACT, line, column, filename};
            }
            break;

        case '*':
            currentChar = readNextChar();
            if (currentChar == '=') {
                token = {std::string("*="), TokenType::MUL_ASSIGN, line, column, filename};
            } else if  (currentChar == '*') {
                token = {std::string("**"), TokenType::POWER, line, column, filename};
            } else {
                token = {std::string("*"), TokenType::MULTIPLY, line, column, filename};
            }
            break;

        case '/':
            currentChar = readNextChar();
            if (currentChar == '=') {
                token = {std::string("/="), TokenType::DIV_ASSIGN, line, column, filename};
            } else {
                token = {std::string("/"), TokenType::DIVIDE, line, column, filename};
            }
            break;

        case '%': token = {std::string(1, currentChar), TokenType::MOD, line, column, filename}; break;

        case '.': token = {std::string(1, currentChar), TokenType::DOT, line, column, filename}; break;

        default: {
            token = {std::string(1, currentChar), TokenType::ILLEGAL, line, column, filename};
            if (currentChar == EOF) {
                token = {std::string(1, currentChar), TokenType::EOFF, line, column, filename};
            }
        }
    }

    currentChar = readNextChar(); // Leemos el siguiente carácter
    return token;
}

// Identifica y crea tokens para identificadores o palabras clave
Token FluxLexer::makeIdentifierOrKeyword() {
    std::string lexeme(1, currentChar);
    while (std::isalnum(currentChar) || currentChar == '_') {
        currentChar = readNextChar();

        if (std::isalnum(currentChar) || currentChar == '_') {
            lexeme += currentChar;
        }
    }

    TokenType type = TokenType::IDENTIFIER;

    // Expresiones regulares para identificar el tipo de identificador
    std::regex uppercaseRegex("^[A-Z][A-Z0-9_]*$");
    std::regex classRegex("^[A-Z][a-zA-Z0-9_]*$");
    std::regex identifierRegex("^[a-zA-Z_][a-zA-Z0-9_]*$");

    if (std::regex_match(lexeme, uppercaseRegex)) {
        type = TokenType::UPPERCASE_IDENTIFIER;
    } else if (std::regex_match(lexeme, classRegex)) {
        std::cout << lexeme << std::endl;
        type = TokenType::CLASS_IDENTIFIER;
    } else if (!std::regex_match(lexeme, identifierRegex)) {
        type = TokenType::ILLEGAL; // Si no coincide con ningún identificador válido
    }

    if (lexeme == "if") {
        type = TokenType::IF;
    } else if (lexeme == "elseif") {
        type = TokenType::ELSEIF;
    } else if (lexeme == "else") {
        type = TokenType::ELSE;
    } else if (lexeme == "switch") {
        type = TokenType::SWITCH;
    } else if (lexeme == "case") {
        type = TokenType::CASE;
    } else if (lexeme == "default") {
        type = TokenType::DEFAULT;
    } else if (lexeme == "for") {
        type = TokenType::FOR;
    } else if (lexeme == "in") {
        type = TokenType::IN;
    } else if (lexeme == "while") {
        type = TokenType::WHILE;
    } else if (lexeme == "break") {
        type = TokenType::BREAK;
    } else if (lexeme == "continue") {
        type = TokenType::CONTINUE;
    } else if (lexeme == "pass") {
        type = TokenType::PASS;
    } else if (lexeme == "try") {
        type = TokenType::TRY;
    } else if (lexeme == "catch") {
        type = TokenType::CATCH;
    } else if (lexeme == "finally") {
        type = TokenType::FINALLY;
    } else if (lexeme == "throw") {
        type = TokenType::THROW;
    } else if (lexeme == "func") {
        type = TokenType::FUNC;
    } else if (lexeme == "return") {
        type = TokenType::RETURN;
    } else if (lexeme == "lambda") {
        type = TokenType::LAMBDA;
    } else if (lexeme == "const") {
        type = TokenType::CONST;
    } else if (lexeme == "number") {
        type = TokenType::VAR_NUMBER;
    } else if (lexeme == "string") {
        type = TokenType::VAR_STRING;
    } else if (lexeme == "bool") {
        type = TokenType::VAR_BOOLEAN;
    } else if (lexeme == "true") {
        type = TokenType::TRUE;
    } else if (lexeme == "false") {
        type = TokenType::FALSE;
    } else if (lexeme == "and") {
        type = TokenType::AND;
    } else if (lexeme == "or") {
        type = TokenType::OR;
    } else if (lexeme == "class") {
        type = TokenType::CLASS;
    } else if (lexeme == "super") {
        type = TokenType::SUPER;
    } else if (lexeme == "extends") {
        type = TokenType::EXTENDS;
    } else if (lexeme == "public") {
        type = TokenType::PUBLIC;
    } else if (lexeme == "private") {
        type = TokenType::PRIVATE;
    } else if (lexeme == "new") {
        type = TokenType::NEW;
    } else if (lexeme == "this") {
        type = TokenType::THIS;
    } else if (lexeme == "export") {
        type = TokenType::EXPORT;
    } else if (lexeme == "import") {
        type = TokenType::IMPORT;
    } else if (lexeme == "from") {
        type = TokenType::FROM;
    } else if (lexeme == "print") {
        type = TokenType::PRINT;
    } else if (lexeme == "Error") {
        type = TokenType::ERROR;
    }
    return Token{lexeme, type, line, column, filename};
}

// Identifica y crea tokens para números enteros y decimales
Token FluxLexer::makeNumber() {
    std::string lexeme(1, currentChar);
    bool hasDecimal = false;

    while (std::isdigit(currentChar) || currentChar == '.') {
        if (currentChar == '.') {
            if (std::isdigit(fileStream.peek())) {
                if (hasDecimal) break;
                hasDecimal = true;
                lexeme += currentChar;
            } else {
                std::ostringstream errorMessage;
                errorMessage << "Unexpected number '" << lexeme
                             << "' at line: " << line
                             << ", column: " << column
                             << " in file: " << filename;

                throw std::runtime_error(errorMessage.str());
            }
        }
        currentChar = readNextChar();
        if (std::isalnum(currentChar)) {
            lexeme += currentChar;
        }
    }

    return Token{lexeme, TokenType::NUMBER, line, column, filename};
}

// Identifica y crea tokens para cadenas de texto QUE SEA CON UN REGEX MEJOR
Token FluxLexer::makeString() {
    char openingQuote = currentChar;  // Puede ser " o '
    std::string lexeme;
    lexeme += openingQuote;

    // Avanzar al siguiente carácter después de la comilla inicial
    currentChar = readNextChar();

    bool isEscaped = false;
    while (!isEOF()) {
        // Manejar caracteres escapados
        if (isEscaped) {
            lexeme += currentChar;
            isEscaped = false;
        }
            // Manejar caracteres de escape
        else if (currentChar == '\\') {
            lexeme += currentChar;
            isEscaped = true;
        }
            // Verificar cierre de cadena
        else if (currentChar == openingQuote) {
            lexeme += currentChar;
            currentChar = readNextChar();
            break;
        }
            // Agregar caracteres normales
        else {
            lexeme += currentChar;
        }

        currentChar = readNextChar();
    }

    // Manejar error si no se cierra la cadena
    if (isEOF() && currentChar != openingQuote) {
        // Podrías lanzar un error o manejar esto según tu estrategia de manejo de errores
//        throw std::runtime_error("Unterminated string literal");

        std::ostringstream errorMessage;
        errorMessage << "Unterminated string literal"
                     << " at line: " << line
                     << ", column: " << column
                     << " in file: " << filename;

        throw std::runtime_error(errorMessage.str());
    }

    return Token{lexeme, TokenType::STRING, line, column, filename};
}

// Función para reconocer comentarios de línea
//Token FluxLexer::makeComment() {
//    std::string lexeme = "//";  // Comenzamos con los caracteres de inicio de comentario
//
//    currentChar = readNextChar(); // saltamos el 2do '/'
//    // Continúa leyendo caracteres hasta encontrar un salto de línea o fin de archivo
//    while (!isEOF() && currentChar != '\n' && currentChar != '\r') {
//        currentChar = readNextChar();
//        lexeme += currentChar;
//    }
//
//    // No incrementamos el contador de línea aquí, ya que skipWhitespace() lo hará
//    return Token{lexeme, TokenType::COMMENT, line, column, filename};
//}

Token FluxLexer::makeComment() {
    std::string lexeme;

    // Verifica si es un comentario de línea
    if (fileStream.peek() == '/') {
        lexeme = "/";
        currentChar = readNextChar(); // saltamos el 2do '/'
        // Continúa leyendo caracteres hasta encontrar un salto de línea o fin de archivo
        while (!isEOF() && currentChar != '\n' && currentChar != '\r') {
            lexeme += currentChar;
            currentChar = readNextChar();
        }
    } else if (fileStream.peek() == '*') { // Verifica si es un comentario de bloque
        lexeme = "/*";
        currentChar = readNextChar(); // saltamos el '*'
        // Continúa leyendo caracteres hasta encontrar el cierre del comentario de bloque `*/`
        while (!isEOF()) {
            currentChar = readNextChar();
            if (currentChar == '\n') {
                line++; column = 0;
            } else { column++; }

            lexeme += currentChar;

            if (currentChar == '*' && fileStream.peek() == '/') {
                lexeme += '/';
                currentChar = readNextChar(); // saltamos el '/'
                currentChar = readNextChar(); // pasamos al siguiente token
                break;
            }
        }
        return Token{lexeme, TokenType::BLOCK_COMMENT, line, column, filename};
    }

    return Token{lexeme, TokenType::COMMENT, line, column, filename};
}


// Omite espacios en blanco y saltos de línea
void FluxLexer::skipWhitespace() {
    while (std::isspace(currentChar) || currentChar == '\r') {
        if (currentChar == '\n' || currentChar == '\r') {
            line++;
            column = 0;
        }
        currentChar = readNextChar();
    }
}


