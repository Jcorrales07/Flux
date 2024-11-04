#include "FluxLexer.h"
#include <cctype>
#include <stdexcept>
#include <sstream>

#define EOF_CHAR '\0'

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
    return filename.size() > 5 && filename.substr(filename.size() - 5) == ".flux";
}

// Lee el siguiente carácter del archivo
bool FluxLexer::readNextChar() {
    currentChar = fileStream.get();
    if (fileStream.eof()) {
        currentChar = EOF_CHAR;
        return false;
    }

    if (currentChar == '\n') {
        line++;
        column = 0;
    } else {
        column++;
    }
    return true;
}

// Lee el siguiente carácter solo si es parte de un operador de dos caracteres
char FluxLexer::readNextOp() {
    char nextChar = fileStream.get();  // Lee el siguiente carácter en el flujo
    column++;  // Avanza la columna ya que hemos leído otro carácter
    return nextChar;
}


// Tokeniza el contenido del archivo
std::vector<Token> FluxLexer::tokenize() {
    std::vector<Token> tokens;
    while (readNextChar()) {
        Token token = nextToken();
        if (token.type != TokenType::ILLEGAL) {
            tokens.push_back(token);
        }
    }
    tokens.push_back(Token{"", TokenType::EOFF, line, column, filename}); // Agrega el token de EOF
    return tokens;
}

// Genera el siguiente token basado en el carácter actual
Token FluxLexer::nextToken() {
    skipWhitespace();

    if (currentChar == EOF_CHAR) {
        return Token{"", TokenType::EOFF, line, column, filename};
    }

    if (std::isalpha(currentChar) || currentChar == '_') {
        return makeIdentifierOrKeyword();
    } else if (std::isdigit(currentChar)) {
        return makeNumber();
    } else if (currentChar == '"') {
        return makeString();
    }

    // Manejo de operadores de uno y dos caracteres
    if (currentChar == '=' || currentChar == '!' || currentChar == '>' || currentChar == '<') {
        char firstChar = currentChar;  // Guarda el primer carácter del operador
        char secondChar = readNextOp();  // Lee el siguiente carácter en el flujo

        // Verifica si es un operador de dos caracteres
        if (secondChar == '=') {
            if (firstChar == '=') return Token{"==", TokenType::EQUAL, line, column - 1, filename};
            else if (firstChar == '!') return Token{"!=", TokenType::NOT_EQUAL, line, column - 1, filename};
            else if (firstChar == '>') return Token{">=", TokenType::GREATER_EQUAL, line, column - 1, filename};
            else if (firstChar == '<') return Token{"<=", TokenType::LESS_EQUAL, line, column - 1, filename};
        }

        // Si no es un operador de dos caracteres, retrocede el carácter
        fileStream.unget();
        column--;  // Ajusta la columna

        // Devuelve el operador de un solo carácter
        if (firstChar == '=') return Token{"=", TokenType::ASSIGN, line, column, filename};
        else if (firstChar == '!') return Token{"!", TokenType::NOT, line, column, filename};
        else if (firstChar == '>') return Token{">", TokenType::GREATER, line, column, filename};
        else if (firstChar == '<') return Token{"<", TokenType::LESS, line, column, filename};
    }

    switch (currentChar) {
        case '+': return Token{std::string(1, currentChar), TokenType::ADD, line, column, filename};
        case '-': return Token{std::string(1, currentChar), TokenType::SUBSTRACT, line, column, filename};
        case '*': return Token{std::string(1, currentChar), TokenType::MULTIPLY, line, column, filename};
        case '/': return Token{std::string(1, currentChar), TokenType::DIVIDE, line, column, filename};
        case '%': return Token{std::string(1, currentChar), TokenType::MODULE, line, column, filename};

        case '>': return Token{std::string(1, currentChar), TokenType::GREATER, line, column, filename};
        case '<': return Token{std::string(1, currentChar), TokenType::LESS, line, column, filename};
        case '=': return Token{std::string(1, currentChar), TokenType::ASSIGN, line, column, filename};

        case ',': return Token{std::string(1, currentChar), TokenType::COMMA, line, column, filename};
        case '(': return Token{std::string(1, currentChar), TokenType::LPAREN, line, column, filename};
        case ')': return Token{std::string(1, currentChar), TokenType::RPAREN, line, column, filename};
        case '{': return Token{std::string(1, currentChar), TokenType::LBRACE, line, column, filename};
        case '}': return Token{std::string(1, currentChar), TokenType::RBRACE, line, column, filename};
        case '[': return Token{std::string(1, currentChar), TokenType::LBRACK, line, column, filename};
        case ']': return Token{std::string(1, currentChar), TokenType::RBRACK, line, column, filename};

        case '!': return Token{std::string(1, currentChar), TokenType::NOT, line, column, filename};

        default: {
            std::ostringstream errorMessage;
            errorMessage << "Error: Unexpected token '" << currentChar
                         << "' at line: " << line
                         << ", column: " << column
                         << " in file: " << filename;

            throw std::runtime_error(errorMessage.str());
        }
    }
}

// Identifica y crea tokens para identificadores o palabras clave
Token FluxLexer::makeIdentifierOrKeyword() {
    std::string lexeme(1, currentChar);

    while (readNextChar() && (std::isalnum(currentChar) || currentChar == '_')) {
        lexeme += currentChar;
    }

    TokenType type = TokenType::IDENTIFIER; // Cambiar si es palabra clave

    if (lexeme == "if") type = TokenType::IF;
    else if (lexeme == "elseif") type = TokenType::ELSEIF;
    else if (lexeme == "else") type = TokenType::ELSE;
    else if (lexeme == "for") type = TokenType::FOR;
    else if (lexeme == "while") type = TokenType::WHILE;
    else if (lexeme == "break") type = TokenType::BREAK;
    else if (lexeme == "continue") type = TokenType::CONTINUE;
    else if (lexeme == "pass") type = TokenType::PASS;
    else if (lexeme == "try") type = TokenType::TRY;
    else if (lexeme == "catch") type = TokenType::CATCH;
    else if (lexeme == "finally") type = TokenType::FINALLY;
    else if (lexeme == "throw") type = TokenType::THROW;

    else if (lexeme == "func") type = TokenType::FUNC;
    else if (lexeme == "return") type = TokenType::RETURN;
    else if (lexeme == "lambda") type = TokenType::LAMBDA;

    else if (lexeme == "const") type = TokenType::CONST;
    else if (lexeme == "number") type = TokenType::VAR_NUMBER;
    else if (lexeme == "string") type = TokenType::VAR_STRING;
    else if (lexeme == "bool") type = TokenType::VAR_BOOLEAN;
    else if (lexeme == "true") type = TokenType::TRUE;
    else if (lexeme == "false") type = TokenType::FALSE;

    else if (lexeme == "and") type = TokenType::AND;
    else if (lexeme == "or") type = TokenType::OR;

    // Más palabras clave según TokenType

    // Si readNextChar ha avanzado un carácter extra, retrocede.
    if (!std::isalnum(currentChar) && currentChar != '_') {
        column--; // Retrocede en la columna
        fileStream.unget(); // Deshace la lectura en el stream
    }

    return Token{lexeme, type, line, column, filename};
}

// Identifica y crea tokens para números enteros y decimales
Token FluxLexer::makeNumber() {
    std::string lexeme(1, currentChar);
    TokenType type = TokenType::NUMBER;  // Se establece como NUMBER para ambos tipos
    bool hasDecimal = false;

    while (readNextChar() && (std::isdigit(currentChar) || currentChar == '.')) {
        if (currentChar == '.') {
            if (hasDecimal) break;  // Si ya tiene un decimal, termina el número
            hasDecimal = true;
        }
        lexeme += currentChar;
    }

    if (!std::isdigit(currentChar)) {
        column--;
        fileStream.unget();
    }

    return Token{lexeme, type, line, column, filename};
}


// Identifica y crea tokens para cadenas de texto
Token FluxLexer::makeString() {
    std::string lexeme;
    while (readNextChar() && currentChar != '"') {
        lexeme += currentChar;
    }
    return Token{lexeme, TokenType::STRING, line, column, filename};
}

// Omite espacios en blanco y saltos de línea
void FluxLexer::skipWhitespace() {
    while (std::isspace(currentChar)) {
        readNextChar();
    }
}
