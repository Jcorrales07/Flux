#pragma once
#include <vector>
#include <string>
#include "FluxTokens.h"  // Assuming you have a Token class or structure

struct Function {
    std::string name;
    std::vector<std::string> parameters;
};

class FluxParser {
private:
    std::vector<Token> tokens;
    size_t currentIndex;
    Token currentToken;

    void advance();
    void consumeToken();
    void match(TokenType expectedType);

    void parseProgram();
    void parseStatement();

    void parseVariableDeclaration();
    void parseExpression();
    void parsePrimaryExpression();
    void parseClass();
    void parseFunction();
    void parseConstructorCall();
    void parseArguments();
    void parseBlock();
    void parseClassBody();

    std::vector<Function> functions;

public:
    FluxParser(const std::vector<Token>& tokens);
    Token getCurrentToken() const;
    void parse();
};
