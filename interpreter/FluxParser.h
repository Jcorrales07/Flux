#pragma once
#include <vector>
#include <string>
#include <variant>
#include "FluxTokens.h"
#include <map>
#include "RuntimeVariables.h"

struct Function {
    std::string name;
    std::vector<std::string> parameters;
};

using VariableValue = std::variant<int, double, std::string, bool, std::monostate>;

class FluxParser {
private:
    std::vector<Token> tokens;
    size_t currentIndex;
    Token currentToken;

    // Runtime variables
    RuntimeVariables runtime; // Variable storage for the runtime

    // Evaluations
    std::variant<int, double, std::string, bool, std::monostate> evaluateExpression();

    // Movements
    void advance();
    void consumeToken();
    void match(TokenType expectedType);

    // Statements
    void parseProgram();
    void parseStatement();
    void parseThisVariable();
    void parseArray();
    void parseConstantDeclaration();
    void parseVariableDeclaration();
    std::variant<int, double, std::string, bool, std::monostate> parseExpression();
    void parsePrimaryExpression();
    void parseComment();
    bool isExpressionStart(TokenType type);
    std::variant<int, double, std::string, bool, std::monostate> convertToVariant(const VariableValue& value);

    // Class functions
    void parseFunction();
    void parseClass();
    void parseConstructorCall();
    void parseArguments();
    void parseBlock();
    void parseClassBody();
    void parseClassConstructor();
    void parseThrow();
    void parseCallParams();
    void parseFunctionParameters();
    void parseParameter();

    // Imports
    void parseImportStatement();

    // Access methods
    void parseClassAccess();
    void parseAccessSpecifier();

    // Conditionals
    void parseSwitch();
    void parseCase();
    void parseDefault();

    // Loops
    void parseForLoop();
    void parseWhileLoop();
    void executeWhileLoop(std::function<bool()> condition, std::function<void()> body);
    void executeSwitch(std::variant<int, double, std::string> expr,
                   const std::map<std::variant<int, double, std::string>, std::function<void()>>& cases,
                   std::function<void()> defaultCase);

    // Try-catch
    void parseTryCatchFinally();

    std::vector<Function> functions;

public:
    FluxParser(const std::vector<Token>& tokens);
    Token getCurrentToken() const;
    void parse();
};