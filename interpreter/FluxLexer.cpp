#include "FluxLexer.h"
#include <cctype>
#include <stdexcept>
#include <sstream>
#include <filesystem>

// Todo: Falta trabajar la parte de aumentar las columnas y filas

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
    // :: Porque lee aca
    // Itera cuando tengamos caracteres que leer
    while (!isEOF()) {

        // extraemos el token
        Token token = nextToken();
//        printf(" Token: %s Type: %d\n", token.lexeme.c_str(), static_cast<int>(token.type));
        printf("Token: %s \tType: %d Line: %d Column: %d\n", token.lexeme.c_str(), static_cast<int>(token.type), token.line, token.column);
//        printf("Token: %s \tType: %d Line: %d\n", token.lexeme.c_str(), static_cast<int>(token.type), token.line);

        // si no es de tipo EOF
        if (token.type != TokenType::ILLEGAL && token.type != TokenType::EOFF) {
//            if (token.type == TokenType::STRING) printf("metemos string\n");
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

    Token eofToken = {"", TokenType::EOFF, line, column, filename};
    tokens.push_back(eofToken);

    return tokens;
}

// Genera el siguiente token basado en el carácter actual
Token FluxLexer::nextToken() {

    // Ignoramos los espacios en blanco
    skipWhitespace();

    // Si saltamos la linea, actualizamos la linea y reseteamos la columna

    // revisamos el caracter actual
    // Hagamos un identificador
    if (std::isalpha(currentChar) || currentChar == '_') {
        return makeIdentifierOrKeyword();
        // si es un numero, formemos un numero
    } else if (std::isdigit(currentChar)) {
        return makeNumber();
        // si es un ", formemos un string
    } else if (currentChar == '"') {
        return makeString();
    }

    // Falta la parte de operadores compuestos

    // Para manejar operadores y variados

    Token token;

    switch (currentChar) {
        case '(': token = {std::string(1, currentChar), TokenType::LPAREN, line, column, filename}; break;
        case ')': token = {std::string(1, currentChar), TokenType::RPAREN, line, column, filename}; break;
        case '{': token = {std::string(1, currentChar), TokenType::LBRACE, line, column, filename}; break;
        case '}': token = {std::string(1, currentChar), TokenType::RBRACE, line, column, filename}; break;
        case '[': token = {std::string(1, currentChar), TokenType::LBRACK, line, column, filename}; break;
        case ']': token = {std::string(1, currentChar), TokenType::RBRACK, line, column, filename}; break;

        case '+': token = {std::string(1, currentChar), TokenType::ADD, line, column, filename}; break;
        case '-': token = {std::string(1, currentChar), TokenType::SUBSTRACT, line, column, filename}; break;
        case '*': token = {std::string(1, currentChar), TokenType::MULTIPLY, line, column, filename}; break;
        case '/': token = {std::string(1, currentChar), TokenType::DIVIDE, line, column, filename}; break;
        case '%': token = {std::string(1, currentChar), TokenType::MODULE, line, column, filename}; break;

        case '=': token = {std::string(1, currentChar), TokenType::ASSIGN, line, column, filename}; break;
        case '>': token = {std::string(1, currentChar), TokenType::GREATER, line, column, filename}; break;
        case '<': token = {std::string(1, currentChar), TokenType::LESS, line, column, filename}; break;
        case ',': token = {std::string(1, currentChar), TokenType::COMMA, line, column, filename}; break;
        case '!': token = {std::string(1, currentChar), TokenType::NOT, line, column, filename}; break;

        case '\0': token = {std::string(1, currentChar), TokenType::EOFF, line, column, filename}; break;

        default: token = {std::string(1, currentChar), TokenType::ILLEGAL, line, column, filename};
    }

    currentChar = readNextChar();
    return token;
}

// Identifica y crea tokens para identificadores o palabras clave
Token FluxLexer::makeIdentifierOrKeyword() {

    // Para guardar el string del identifier
    std::string lexeme(1, currentChar);

    // :: lee aca tambien
    // Mientras se un caracter y (contenga numero o _), iteramos...
    // my_ident1fier
    while (std::isalnum(currentChar) || currentChar == '_') {
        currentChar = readNextChar();

        if (std::isalnum(currentChar) || currentChar == '_') {
            lexeme += currentChar;
        }
    }

    // se construye la cadena y se le asiga el tipo identifier por default
    TokenType type = TokenType::IDENTIFIER;

    // Ahora, evaluamos si el token formado, coincide con alguna de las palabras reservadas
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

    Token token = {lexeme, type, line, column, filename};
    return token;
}

// Identifica y crea tokens para números enteros y decimales
Token FluxLexer::makeNumber() {
    std::string lexeme(1, currentChar);
    bool hasDecimal = false;

    // :: aca tambien
    while (std::isdigit(currentChar) || currentChar == '.') {
        if (currentChar == '.') {
            if (hasDecimal) break;
            hasDecimal = true;
            lexeme += currentChar;
        }

        currentChar = readNextChar();

        if (std::isdigit(currentChar)) {
            lexeme += currentChar;
        }
    }

    return Token{lexeme, TokenType::NUMBER, line, column, filename};
}


// Identifica y crea tokens para cadenas de texto
Token FluxLexer::makeString() {
    std::string lexeme(1, currentChar);

    // :: y aca tambien
    while (true) {
        currentChar = readNextChar();
        lexeme += currentChar;

        if (lexeme.back() == '"') {
            currentChar = readNextChar();
            break;
        }
    }

    return Token{lexeme, TokenType::STRING, line, column, filename};
}

// Omite espacios en blanco y saltos de línea
void FluxLexer::skipWhitespace() {
    while (std::isspace(currentChar)) {
//        printf("volvi a entrar\n");
        if (currentChar == '\n') {
            // Salto de linea natural
            line++;
            column = 0;
        }
        currentChar = readNextChar();
    }
}

// :: me puede estar causando el problema de leer characteres siguientes, y por eso se adelante y me descarta algunos
// :: En vez de leer, mejor solo verificar que !fileStream.eof(), mientras no estemos al final del archivo, leemos
