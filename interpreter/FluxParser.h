#pragma once

#include <vector>
#include <string>
#include <variant>
#include "FluxTokens.h"
#include "RuntimeVariables.h"
#include <functional>

// Structure representing a function with its name and parameters
struct Function {
    std::string name;
    std::vector<std::string> parameters;
};

// Type alias for variable value (can hold multiple types using std::variant)
using VariableValue = std::variant<int, double, std::string, bool, std::vector<int>>;

class FluxParser {
    std::vector<Token> tokens;            // List of tokens to parse
    size_t currentIndex;                  // Current index in the token list
    Token currentToken;                   // Current token being processed

    // Evaluations
    std::variant<int, double, std::string, bool, std::vector<int>> evaluateExpression();

    // Movements
    void advance();                       // Move to the next token
    void consumeToken();                  // Consume the current token
    void match(TokenType expectedType);   // Match expected token type

    // Statements
    void parseProgram();                  // Parse the entire program
    void parseStatement();                // Parse a single statement
    void parseThisVariable();             // Parse a "this" variable
    void parseArray();                    // Parse array declarations
    void parseConstantDeclaration();      // Parse constant declarations
    void parseVariableDeclaration();      // Parse variable declarations
    std::variant<int, double, std::string, bool, std::vector<int>> parseExpression();
    void parsePrimaryExpression();        // Parse primary expressions
    void parseComment();                  // Parse comments
    bool isExpressionStart(TokenType type); // Check if token starts an expression
    std::variant<int, double, std::string, bool> convertToVariant(const VariableValue& value);

    // Class functions
    void parseFunction();                 // Parse function declarations
    void parseClass();                    // Parse class declarations
    void parseConstructorCall();          // Parse constructor calls
    void parseArguments();                // Parse function arguments
    void parseBlock();                    // Parse blocks of code (e.g., function body)
    void parseClassBody();                // Parse class body
    void parseClassConstructor();         // Parse class constructors
    void parseThrow();                    // Parse throw statements
    void parseCallParams();               // Parse function call parameters
    void parseFunctionParameters();       // Parse function parameters
    void parseParameter();                // Parse a single parameter
    void printResults(const std::vector<std::variant<int, double, std::string, bool, std::vector<int>>>& parsedResults);
    void print(const std::variant<int, double, std::string, bool, std::vector<int>>& result);

    // Imports
    void parseImportStatement();          // Parse import statements

    // Access methods
    void parseClassAccess();              // Parse class access (e.g., public, private)
    void parseAccessSpecifier();          // Parse access specifiers

    // Conditionals
    void parseSwitch();                   // Parse switch statements
    void parseCase();                     // Parse case statements within a switch
    void parseDefault();                  // Parse default case in switch
    bool evaluateCondition();
    std::variant<bool, int, std::string> parseConditionExpression();
    bool evaluateComparison(
    const std::variant<bool, int, std::string>& leftOperand,
    const Token& operatorToken,
    const std::variant<bool, int, std::string>& rightOperand);
    std::variant<bool, int, std::string> parseOperand();
    void skipBlock();
    void skipRemainingElseBranches();

    // Loops
    void parseForLoop();                  // Parse for loops
    void parseWhileLoop();                // Parse while loops
    void executeWhileLoop(std::function<bool()> condition, std::function<void()> body);

    // Try-catch blocks
    void parseTryCatchFinally();          // Parse try-catch-finally blocks

    // Functions container
    std::vector<Function> functions;      // Store all functions parsed

public:
    FluxParser(const std::vector<Token>& tokens); // Constructor that takes tokens for parsing
    Token getCurrentToken() const;              // Get the current token
    void parse();                               // Start the parsing process
};
