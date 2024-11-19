#include "FluxParser.h"
#include <stdexcept>
#include <iostream>
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
    } else if (currentToken.type == TokenType::FUNC) {
        std::cout << "Parsing Function Declaration...\n";
        parseFunction();
    } else if (currentToken.type == TokenType::CLASS) {
        std::cout << "Parsing Class Declaration...\n";
        parseClass();
    } else if (currentToken.type == TokenType::RETURN) {
        std::cout << "Parsing Return Statement...\n";
        match(TokenType::RETURN);
        parseExpression();
        match(TokenType::SEMICOLON);
    } else if (currentToken.type == TokenType::CONST || currentToken.type == TokenType::VAR_NUMBER ||
        currentToken.type == TokenType::VAR_STRING || currentToken.type == TokenType::VAR_BOOLEAN){
        std::cout << "Parsing Variable Declaration...\n";
        parseVariableDeclaration();
    } else if (currentToken.type == TokenType::IDENTIFIER) {
        std::cout << "Parsing Assignment Statement...\n";
        std::string identifier = currentToken.lexeme;
        std::cout << identifier;
        consumeToken();

        match(TokenType::ASSIGN);

        parseExpression();

        match(TokenType::SEMICOLON);
    } else {
        throw std::runtime_error("Unknown statement type.");
    }
}

void FluxParser::parseVariableDeclaration() {
    TokenType varType = currentToken.type;
    if (varType != TokenType::VAR_NUMBER && varType != TokenType::VAR_STRING && varType != TokenType::VAR_BOOLEAN) {
        throw std::runtime_error("Expected variable type (VAR_NUMBER, VAR_STRING, VAR_BOOLEAN).");
    }
    consumeToken();

    if (currentToken.type != TokenType::IDENTIFIER) {
        throw std::runtime_error("Expected variable name (identifier).");
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
    match(TokenType::IDENTIFIER);
    std::cout << "Class name: " << currentToken.lexeme << "\n";

    if (currentToken.type == TokenType::SUPER) {
        match(TokenType::SUPER);
        match(TokenType::IDENTIFIER);
        std::cout << "Inheriting from class: " << currentToken.lexeme << "\n";
    }

    match(TokenType::LBRACE);
    while (currentToken.type != TokenType::RBRACE) {
        parseStatement();
    }
    match(TokenType::RBRACE);
}

void FluxParser::parseFunction() {
    std::cout << "Parsing Function Declaration...\n";

    if (currentToken.type != TokenType::FUNC) {
        throw std::runtime_error("Expected 'FUNC' keyword at the beginning of function definition.");
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
    if (currentToken.type == TokenType::SUPER) {
        match(TokenType::SUPER);
        match(TokenType::LPAREN);
        parseArguments();
        match(TokenType::RPAREN);
    }
}

void FluxParser::parseClassBody() {
    parseConstructorCall();
}

void FluxParser::parseArguments() {
    std::cout << "Parsing Arguments...\n";
    while (currentToken.type != TokenType::RPAREN && currentToken.type != TokenType::EOFF) {
        parseExpression();
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