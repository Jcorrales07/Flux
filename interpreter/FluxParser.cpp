#include "FluxParser.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

FluxParser::FluxParser(const std::vector<Token>& tokens)
    : tokens(tokens), currentIndex(0), currentToken(tokens[0]) {}

void FluxParser::advance() {
    currentIndex++;
    if (currentIndex < tokens.size()) {
        currentToken = tokens[currentIndex];
    }
}

Token FluxParser::getCurrentToken() const {
    return currentToken;
}


void FluxParser::consumeToken() {
    std::cout << "Consuming token: " << currentToken.lexeme << " (Type: " << static_cast<int>(currentToken.type) << ")\n";
    advance();
}

void FluxParser::match(TokenType expectedType) {
    if (currentToken.type == expectedType) {
        std::cout << "Matched token: " << currentToken.lexeme << " (Type: " << static_cast<int>(currentToken.type) << ")\n";
        advance();
    } else {
        throw std::runtime_error("Unexpected token: " + currentToken.lexeme);
    }
}

void FluxParser::parse() {
    std::cout << "Starting parse...\n";
    parseProgram();
}

void FluxParser::parseProgram() {
    std::cout << "Parsing Program...\n";
    while (currentToken.type != TokenType::EOFF) {
        parseStatement();
    }
}

void FluxParser::parseStatement() {
    std::cout << "Parsing Statement...\n";
    try {
        if (currentToken.type == TokenType::IF) {
            std::cout << "Parsing IF statement...\n";
            match(TokenType::IF);
            parseExpression();
            match(TokenType::LBRACE);
            parseBlock();
            match(TokenType::RBRACE);
        } else if (currentToken.type == TokenType::ELSEIF) {
            std::cout << "Parsing ELSEIF statement...\n";
            match(TokenType::ELSEIF);
            parseExpression();
            match(TokenType::LBRACE);
            parseBlock();
            match(TokenType::RBRACE);
        } else if (currentToken.type == TokenType::ELSE) {
            std::cout << "Parsing ELSE statement...\n";
            match(TokenType::ELSE);
            match(TokenType::LBRACE);
            parseBlock();
            match(TokenType::RBRACE);
        } else if (currentToken.type == TokenType::CLASS) {
            std::cout << "Parsing Class Declaration...\n";
            parseClass();
        } else if (currentToken.type == TokenType::RETURN) {
            std::cout << "Parsing Return Statement...\n";
            match(TokenType::RETURN);
            parseExpression();
            match(TokenType::SEMICOLON);
        } else if (currentToken.type == TokenType::CONST || currentToken.type == TokenType::VAR_NUMBER ||
            currentToken.type == TokenType::VAR_STRING || currentToken.type == TokenType::VAR_BOOLEAN || currentToken.type == TokenType::VOID){
            std::cout << "Parsing Variable Declaration...\n";
            parseVariableDeclaration();
        } else if (currentToken.type == TokenType::IDENTIFIER) {
            std::cout << "Parsing Assignment Statement...\n";
            std::string identifier = currentToken.lexeme;
            consumeToken();
            if (TokenType::ASSIGN == currentToken.type) {
                match(TokenType::ASSIGN);
                parseExpression();
                match(TokenType::SEMICOLON);
            }else if (TokenType::LPAREN == currentToken.type) {
                match(TokenType::RPAREN);
                parseArguments();
                match(TokenType::RPAREN);
                match(TokenType::LBRACE);
                parseBlock();
                match(TokenType::RBRACE);
            }
        } else if (currentToken.type == TokenType::COMMENT) {
            std::cout << "Single-line comment: " << currentToken.lexeme << "\n";
            consumeToken();
        } else if (currentToken.type == TokenType::BLOCK_COMMENT) {
            std::cout << "Block comment: " << currentToken.lexeme << "\n";
            consumeToken();
        } else if (currentToken.type == TokenType::FOR) {
            std::cout << "Parsing For Statement...\n";
            parseForLoop();
        } else if (currentToken.type == TokenType::FROM) {
            std::cout << "Parsing From Statement...\n";
            parseImportStatement();
        } else if (currentToken.type == TokenType::WHILE) {
            std::cout << "Parsing While Statement...\n";
            parseWhileLoop();
        } else if (currentToken.type == TokenType::SWITCH) {
            std::cout << "Parsing Switch Statement...\n";
            parseSwitch();
        } else if (currentToken.type == TokenType::CLASS_IDENTIFIER){
            std::cout << "Parsing Class Identifier Statement...\n";
            parseClassConstructor();
        } else if (currentToken.type == TokenType::THIS) {
            std::cout << "Parsing This. Statement...\n";
            parseThisVariable();
        } else if (currentToken.type == TokenType::BREAK){
            std::cout << "Parsing Break Statement...\n";
            match(TokenType::BREAK);
            match(TokenType::SEMICOLON);
        }else {
            throw std::runtime_error("Unknown statement type. " + currentToken.lexeme);
        }
    } catch (const std::runtime_error& e) {
        std::ostringstream errorMessage;
        errorMessage << "Error parsing statement: " << e.what() << "\n";
        throw std::runtime_error(errorMessage.str());
    }
}

void FluxParser::parseVariableDeclaration() {
    TokenType varType = currentToken.type;
    if (varType != TokenType::VAR_NUMBER && varType != TokenType::VAR_STRING && varType != TokenType::CONST && varType != TokenType::VAR_BOOLEAN && varType != TokenType::VOID) {
        throw std::runtime_error("Expected variable type (VAR_NUMBER, VAR_STRING, VAR_BOOLEAN, CONST, VOID).");
    }
    consumeToken();
    if (varType == TokenType::CONST ) {
        std::cout << "Parsing Constant type...\n";
        if (currentToken.type != TokenType::VAR_NUMBER && currentToken.type != TokenType::VAR_STRING && currentToken.type != TokenType::VAR_BOOLEAN) {
            throw std::runtime_error("Expected variable type (VAR_NUMBER, VAR_STRING, VAR_BOOLEAN).");
        }
        consumeToken();
    }

    if (currentToken.type == TokenType::FUNC && varType != TokenType::CONST) {
        std::cout << "Parsing Function Declaration...\n";
        parseFunction();
    } else {
        if (currentToken.type != TokenType::IDENTIFIER && currentToken.type != TokenType::UPPERCASE_IDENTIFIER) {
            throw std::runtime_error("Expected variable name (identifier, uppercase_identifier).");
        }
        std::string variableName = currentToken.lexeme;
        std::cout << "Variable name: " << variableName << "\n";
        consumeToken();

        if (currentToken.type == TokenType::ASSIGN) {
            consumeToken();
            parseExpression();
        }
        match(TokenType::SEMICOLON);
    }
}

void FluxParser::parseThisVariable() {
    if (currentToken.type != TokenType::THIS) {
        throw std::runtime_error("Expected this (variable).");
    }
    consumeToken();
    match(TokenType::DOT);
    match(TokenType::IDENTIFIER);
    if (currentToken.type != TokenType::ASSIGN) {
        throw std::runtime_error("Expected variable name (identifier).");
    }
    consumeToken();
    match(TokenType::IDENTIFIER);
    match(TokenType::SEMICOLON);
}

void FluxParser::parseConstantDeclaration() {
    std::cout << "Parsing Constant Declaration...\n";
    TokenType constType = currentToken.type;
    if (constType != TokenType::CONST) {
        throw std::runtime_error("Expected a valid constant type.");
    }
    consumeToken();
    if (currentToken.type != TokenType::VAR_NUMBER && currentToken.type != TokenType::VAR_STRING && currentToken.type != TokenType::VAR_BOOLEAN) {
        throw std::runtime_error("Expected const data type.");
    }
    consumeToken();
    if (currentToken.type != TokenType::UPPERCASE_IDENTIFIER) {
        throw std::runtime_error("Expected constant name.");
    }
    consumeToken();
    if (currentToken.type == TokenType::ASSIGN) {
        consumeToken();
        parseExpression();
    }
    match(TokenType::SEMICOLON);
}

void FluxParser::parseExpression() {
    parsePrimaryExpression();
    while (currentToken.type == TokenType::ADD || currentToken.type == TokenType::SUBSTRACT || currentToken.type == TokenType::MULTIPLY
            || currentToken.type == TokenType::DIVIDE || currentToken.type == TokenType::LESS || currentToken.type == TokenType::GREATER) {
        Token op = currentToken;
        consumeToken();
        parsePrimaryExpression();
        std::cout << "Parsed binary operator: " << op.lexeme << std::endl;
    }
}

void FluxParser::parsePrimaryExpression() {
    std::cout << "Parsing Primary Expression...\n";
    if (currentToken.type == TokenType::NUMBER) {
        match(TokenType::NUMBER);
    } else if (currentToken.type == TokenType::STRING) {
        match(TokenType::STRING);
    } else if (currentToken.type == TokenType::TRUE ) {
        match(TokenType::TRUE);
    } else if (currentToken.type == TokenType::FALSE) {
        match(TokenType::FALSE);
    } else if (currentToken.type == TokenType::IDENTIFIER) {
        match(TokenType::IDENTIFIER);
    } else if (currentToken.type == TokenType::LPAREN) {
        match(TokenType::LPAREN);
        parseExpression();
        match(TokenType::RPAREN);
    } else if (currentToken.type == TokenType::LESS) {
        match(TokenType::LESS);
        parseExpression();
    } else if (currentToken.type == TokenType::GREATER) {
        match(TokenType::GREATER);
        parseExpression();
    } else {
        std::cout << "Unexpected token: " << currentToken.lexeme << "\n";
        throw std::runtime_error("Unexpected token in expression.");
    }
}

void FluxParser::parseClass() {
    std::cout << "Parsing Class...\n";
    match(TokenType::CLASS);
    std::cout << "Class name: " << currentToken.lexeme << "\n";
    match(TokenType::CLASS_IDENTIFIER);

    if (currentToken.type == TokenType::EXTENDS) {
        match(TokenType::EXTENDS);
        match(TokenType::IDENTIFIER);
        std::cout << "Extends name: " << currentToken.lexeme << "\n";
    }
    match(TokenType::LBRACE);
    parseClassBody();
}

void FluxParser::parseClassConstructor() {
    TokenType classType = currentToken.type;
    if (classType != TokenType::CLASS_IDENTIFIER) {
        throw std::runtime_error("Expected class name (identifier).");
    }
    consumeToken();
    if (currentToken.type == TokenType::LPAREN) {
        consumeToken();
        parseArguments();
        match(TokenType::RPAREN);
        match(TokenType::LBRACE);
        parseBlock();
        match(TokenType::RBRACE);
    }
}

void FluxParser::parseClassBody() {
    std::cout << "Parsing ClassBody...\n";
    parseClassAccess();
    parseClassAccess();
    match(TokenType::RBRACE);
}

void FluxParser::parseClassAccess() {
    TokenType accessType = currentToken.type;
    if (accessType == TokenType::PUBLIC) {
        match(TokenType::PUBLIC);
        match(TokenType::LBRACE);
        while (TokenType::RBRACE != currentToken.type) {
            if (currentToken.type == TokenType::VAR_NUMBER || currentToken.type == TokenType::VAR_STRING || currentToken.type == TokenType::VAR_BOOLEAN) {
                parseVariableDeclaration();
            } else if (currentToken.type == TokenType::CONST) {
                parseConstantDeclaration();
            } else if (currentToken.type == TokenType::CLASS_IDENTIFIER) {
                parseClassConstructor();
            }
        }
        match(TokenType::RBRACE);
    } else if (accessType == TokenType::PRIVATE) {
        match(TokenType::PRIVATE);
        match(TokenType::LBRACE);
        while (TokenType::RBRACE != currentToken.type) {
            if (currentToken.type == TokenType::VAR_NUMBER || currentToken.type == TokenType::VAR_STRING || currentToken.type == TokenType::VAR_BOOLEAN) {
                parseVariableDeclaration();
            } else if (currentToken.type == TokenType::CONST) {
                parseConstantDeclaration();
            } else if (currentToken.type == TokenType::CLASS_IDENTIFIER) {
                parseClassConstructor();
            }
        }
        match(TokenType::RBRACE);
    }
}

void FluxParser::parseFunction() {
    std::cout << "Parsing Function Declaration...\n";

    TokenType varType = currentToken.type;
    if (varType != TokenType::VAR_NUMBER && varType != TokenType::VAR_STRING && varType != TokenType::VAR_BOOLEAN && varType != TokenType::VOID) {
        throw std::runtime_error("Expected variable type (VAR_NUMBER, VAR_STRING, VAR_BOOLEAN, VOID).");
    }
    consumeToken();

    if (currentToken.type != TokenType::FUNC) {
        throw std::runtime_error("Expected 'FUNC' keyword of function definition.");
    }
    consumeToken();

    if (currentToken.type != TokenType::IDENTIFIER) {
        throw std::runtime_error("Expected function name (identifier).");
    }
    std::string functionName = currentToken.lexeme;
    std::cout << "Function name: " << functionName << "\n";
    consumeToken();

    if (currentToken.type != TokenType::LPAREN) {
        throw std::runtime_error("Expected '(' after function name.");
    }
    consumeToken();

    std::vector<std::string> parameters;
    if (currentToken.type != TokenType::RPAREN) {
        while (currentToken.type != TokenType::RPAREN) {
            if (currentToken.type != TokenType::IDENTIFIER) {
                throw std::runtime_error("Expected parameter name (identifier).");
            }
            parameters.push_back(currentToken.lexeme);
            std::cout << "Parameter: " << currentToken.lexeme << "\n";
            consumeToken();

            if (currentToken.type == TokenType::COMMA) {
                consumeToken();
            } else if (currentToken.type != TokenType::RPAREN) {
                throw std::runtime_error("Expected ')' or ',' after parameter.");
            }
        }
    }

    consumeToken();

    if (currentToken.type != TokenType::LBRACE) {
        throw std::runtime_error("Expected '{' to begin function body.");
    }

    consumeToken();
    parseBlock();

    if (currentToken.type != TokenType::RBRACE) {
        throw std::runtime_error("Expected '}' to end function body.");
    }
    consumeToken();

    functions.push_back(Function{functionName, parameters});
}

void FluxParser::parseConstructorCall() {
}

void FluxParser::parseArguments() {
    std::cout << "Parsing Arguments...\n";
    while (currentToken.type != TokenType::RPAREN && currentToken.type != TokenType::EOFF) {
        TokenType varType = currentToken.type;
        if (varType != TokenType::VAR_NUMBER && varType != TokenType::VAR_STRING && varType != TokenType::CONST && varType != TokenType::VAR_BOOLEAN) {
            throw std::runtime_error("Expected variable type (VAR_NUMBER, VAR_STRING, VAR_BOOLEAN, CONST, VOID).");
        }
        consumeToken();
        if (currentToken.type != TokenType::IDENTIFIER) {
            throw std::runtime_error("Expected identifier (identifier).");
        }
        std::string identifier = currentToken.lexeme;
        consumeToken();
        std::cout << "Argument name: " << identifier << "\n";

        if (currentToken.type == TokenType::COMMA) {
            match(TokenType::COMMA);
        }
    }
}

void FluxParser::parseBlock() {
    std::cout << "Parsing Block...\n";
    while (currentToken.type != TokenType::RBRACE && currentToken.type != TokenType::EOFF) {
        parseStatement();
    }
}

void FluxParser::parseImportStatement() {
    std::cout << "Parsing Import Statement...\n";
    match(TokenType::FROM);

    if (currentToken.type != TokenType::IDENTIFIER) {
        throw std::runtime_error("Expected module name after 'from'.");
    }
    std::string moduleName = currentToken.lexeme;
    consumeToken();

    match(TokenType::IMPORT);

    while (currentToken.type == TokenType::IDENTIFIER) {
        std::string importedItem = currentToken.lexeme;
        std::cout << "Importing: " << importedItem << "\n";
        consumeToken();

        if (currentToken.type == TokenType::COMMA) {
            consumeToken();
        } else {
            break;
        }
    }
    match(TokenType::SEMICOLON);
}

void FluxParser::parseAccessSpecifier() {
    std::cout << "Parsing Access Specifier...\n";

    if (currentToken.type == TokenType::PUBLIC) {
        consumeToken();  // Consumiendo 'public'
        match(TokenType::LBRACE);  // Abre el bloque

        while (currentToken.type != TokenType::RBRACE && currentToken.type != TokenType::EOFF) {
            parseStatement();  // Parse de las declaraciones dentro del bloque
        }

        match(TokenType::RBRACE);  // Cierra el bloque
    } else if (currentToken.type == TokenType::PRIVATE) {
        consumeToken();  // Consumiendo 'private'
        match(TokenType::LBRACE);  // Abre el bloque

        while (currentToken.type != TokenType::RBRACE && currentToken.type != TokenType::EOFF) {
            parseStatement();  // Parse de las declaraciones dentro del bloque
        }

        match(TokenType::RBRACE);  // Cierra el bloque
    } else {
        throw std::runtime_error("Expected 'public' or 'private' block.");
    }
}

void FluxParser::parseArray() {
    std::cout << "Parsing Array...\n";
    match(TokenType::LBRACK);

    while (currentToken.type != TokenType::RBRACK && currentToken.type != TokenType::EOFF) {
        parseExpression();

        if (currentToken.type != TokenType::NUMBER && currentToken.type != TokenType::STRING) {
            throw std::runtime_error("Invalid element type in array. Expected NUMBER or STRING.");
        }

        if (currentToken.type == TokenType::COMMA) {
            consumeToken();
        }
    }

    match(TokenType::RBRACK);
}

void FluxParser::parseForLoop() {
    std::cout << "Parsing For Loop...\n";
    match(TokenType::FOR);

    if (currentToken.type == TokenType::LPAREN) {
        consumeToken();
    };

    if (currentToken.type != TokenType::IDENTIFIER) {
        throw std::runtime_error("Expected iterator variable.");
    }

    std::string iterator = currentToken.lexeme;
    std::cout << "Iterator variable: " << iterator << "\n";
    consumeToken();
    match(TokenType::IN);

    if (currentToken.type == TokenType::IDENTIFIER && currentToken.lexeme == "range") {
        match(TokenType::IDENTIFIER);
        match(TokenType::LPAREN);
        parseExpression();
        match(TokenType::COMMA);
        parseExpression();
        match(TokenType::RPAREN);
        if (currentToken.type == TokenType::RPAREN) {
            consumeToken();
        }
    } else {
        throw std::runtime_error("Expected range or array in 'for' loop.");
    }

    match(TokenType::LBRACE);
    parseBlock();
    match(TokenType::RBRACE);
}

void FluxParser::parseWhileLoop() {
    std::cout << "Parsing While Loop...\n";
    match(TokenType::WHILE);

    match(TokenType::LPAREN);
    parseExpression();
    match(TokenType::RPAREN);

    match(TokenType::LBRACE);
    parseBlock();
    match(TokenType::RBRACE);
}

void FluxParser::parseSwitch() {
    std::cout << "Parsing Switch Statement...\n";
    match(TokenType::SWITCH);
    match(TokenType::LPAREN);
    parseExpression();
    match(TokenType::RPAREN);
    match(TokenType::LBRACE);

    while (currentToken.type == TokenType::CASE || currentToken.type == TokenType::DEFAULT) {
        if (currentToken.type == TokenType::CASE) {
            std::cout << "Parsing Case Statement...\n";
            match(TokenType::CASE);
            parseExpression();
            match(TokenType::COLON);
            while (currentToken.type != TokenType::CASE && currentToken.type != TokenType::DEFAULT) {
                parseStatement();
            }
        } else if (currentToken.type == TokenType::DEFAULT) {
            std::cout << "Parsing Default Case...\n";
            match(TokenType::DEFAULT);
            match(TokenType::COLON);
            parseBlock();
        }
    }
    match(TokenType::RBRACE);
}

bool FluxParser::isExpressionStart(TokenType type) {
    return type == TokenType::IDENTIFIER ||
           type == TokenType::NUMBER ||
           type == TokenType::STRING ||
           type == TokenType::LPAREN ||
           type == TokenType::SUBSTRACT ||
           type == TokenType::NOT;
}
