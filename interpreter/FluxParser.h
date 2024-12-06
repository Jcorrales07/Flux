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

    //movements
    void advance();
    void consumeToken();
    void match(TokenType expectedType);

    // statements
    void parseProgram();
    void parseStatement();
    void parseThisVariable();
    void parseArray();
    void parseConstantDeclaration();
    void parseVariableDeclaration();
    void parseExpression();
    void parsePrimaryExpression();
    void parseComment();
    bool isExpressionStart(TokenType type);

    // class functions
    void parseFunction();
    void parseClass();
    void parseConstructorCall();
    void parseArguments();
    void parseBlock();
    void parseClassBody();
    void parseClassConstructor();
    void parseThrow();
    void parseCallParams();

    // imports
    void parseImportStatement();

    // access methods
    void parseClassAccess();
    void parseAccessSpecifier();

    // condicionales
    void parseSwitch();

    // loops
    void parseForLoop();
    void parseWhileLoop();

    //try catch
    void parseTryCatchFinally();

    std::vector<Function> functions;

public:
    FluxParser(const std::vector<Token>& tokens);
    Token getCurrentToken() const;
    void parse();
};
