#include "FluxParser.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include "RuntimeVariables.h"
#include <stdexcept>

RuntimeVariables runtimeVariables;
// You can modify it to include 'int' as well:
using VariableValue = std::variant<int, double, std::string, bool, std::monostate>;
struct VariableEntry {
    VariableValue value;
    bool isConst; // Indicates if the variable is a constant
};

std::stack<std::unordered_map<std::string, VariableEntry>> scopes;

// Helper functions for scope management
void enterScope() {
    scopes.push({});
}

void exitScope() {
    if (!scopes.empty()) {
        scopes.pop();
    } else {
        throw std::runtime_error("No scope to exit!");
    }
}

void setVariable(const std::string& name, VariableValue value, bool isConst = false) {
    if (!scopes.empty()) {
        scopes.top()[name] = {value, isConst};
    } else {
        throw std::runtime_error("No active scope to set variable!");
    }
}

VariableEntry getVariable(const std::string& name) {
    std::stack<std::unordered_map<std::string, VariableEntry>> tempStack = scopes;
    while (!tempStack.empty()) {
        auto& currentScope = tempStack.top();
        if (currentScope.find(name) != currentScope.end()) {
            return currentScope[name];
        }
        tempStack.pop();
    }
    throw std::runtime_error("Undefined variable: " + name);
}

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

std::variant<int, double, std::string, bool, std::monostate> FluxParser::evaluateExpression() {
    std::stack<std::variant<double, std::string, bool>> operands; // Stack to store operands
    std::stack<Token> operators;  // Stack to store operators

    auto precedence = [](TokenType type) {
        switch (type) {
        case TokenType::ADD:
        case TokenType::SUBSTRACT:
            return 1;
        case TokenType::MULTIPLY:
        case TokenType::DIVIDE:
        case TokenType::MOD:
            return 2;
        case TokenType::POWER:
            return 3;
        case TokenType::GREATER:
        case TokenType::LESS_EQUAL:
        case TokenType::EQUAL:
        case TokenType::NOT_EQUAL:
            return 0;  // Relational operators have lower precedence
        default:
            return 0;
        }
    };

    auto applyOperator = [&](std::variant<double, std::string, bool> left,
                             std::variant<double, std::string, bool> right,
                             TokenType op) {
        if (op == TokenType::ADD) {
            if (std::holds_alternative<std::string>(left) || std::holds_alternative<std::string>(right)) {
                std::string leftStr = std::holds_alternative<std::string>(left) ? std::get<std::string>(left) : std::to_string(std::get<double>(left));
                std::string rightStr = std::holds_alternative<std::string>(right) ? std::get<std::string>(right) : std::to_string(std::get<double>(right));
                return std::variant<double, std::string, bool>(leftStr + rightStr);
            } else {
                return std::variant<double, std::string, bool>(
                    std::get<double>(left) + std::get<double>(right));
            }
        } else if (op == TokenType::SUBSTRACT) {
            return std::variant<double, std::string, bool>(
                std::get<double>(left) - std::get<double>(right));
        } else if (op == TokenType::MULTIPLY) {
            return std::variant<double, std::string, bool>(
                std::get<double>(left) * std::get<double>(right));
        } else if (op == TokenType::DIVIDE) {
            if (std::get<double>(right) == 0) throw std::runtime_error("Division by zero.");
            return std::variant<double, std::string, bool>(
                std::get<double>(left) / std::get<double>(right));
        } else if (op == TokenType::MOD) {
            return std::variant<double, std::string, bool>(
                fmod(std::get<double>(left), std::get<double>(right)));
        } else if (op == TokenType::POWER) {
            return std::variant<double, std::string, bool>(
                pow(std::get<double>(left), std::get<double>(right)));
        } else if (op == TokenType::GREATER_EQUAL) {
            return std::variant<double, std::string, bool>(
                std::get<double>(left) > std::get<double>(right));
        } else if (op == TokenType::LESS) {
            return std::variant<double, std::string, bool>(
                std::get<double>(left) < std::get<double>(right));
        } else if (op == TokenType::EQUAL) {
            return std::variant<double, std::string, bool>(
                std::get<double>(left) == std::get<double>(right));
        } else if (op == TokenType::NOT_EQUAL) {
            return std::variant<double, std::string, bool>(
                std::get<double>(left) != std::get<double>(right));
        } else {
            throw std::runtime_error("Unknown operator.");
        }
    };

    while (currentToken.type != TokenType::SEMICOLON && currentToken.type != TokenType::EOFF) {
        if (currentToken.type == TokenType::NUMBER) {
            operands.push(std::stod(currentToken.lexeme));
            consumeToken();
        } else if (currentToken.type == TokenType::STRING) {
            operands.push(currentToken.lexeme);
            consumeToken();
        } else if (currentToken.type == TokenType::IDENTIFIER) {
            // Handle variable lookup from runtime
            if (runtime.hasVariable(currentToken.lexeme)) {
                // Assuming runtime.getVariable() returns a VariableValue
                std::string identifier = currentToken.lexeme;
                std::cout << identifier<< "ping" << std::endl;
                // VariableValue value = runtime.getVariable(currentToken.lexeme);
                // operands.push(value);
            } else {
                throw std::runtime_error("Variable not found: " + currentToken.lexeme);
            }
            consumeToken();
        } else if (currentToken.type == TokenType::LPAREN) {
            operators.push(currentToken);
            consumeToken();
        } else if (currentToken.type == TokenType::RPAREN) {
            while (!operators.empty() && operators.top().type != TokenType::LPAREN) {
                auto right = operands.top(); operands.pop();
                auto left = operands.top(); operands.pop();
                Token op = operators.top(); operators.pop();
                operands.push(applyOperator(left, right, op.type));
            }
            if (!operators.empty() && operators.top().type == TokenType::LPAREN) {
                operators.pop();
            }
            consumeToken();
        } else {
            while (!operators.empty() && precedence(operators.top().type) >= precedence(currentToken.type)) {
                auto right = operands.top(); operands.pop();
                auto left = operands.top(); operands.pop();
                Token op = operators.top(); operators.pop();
                operands.push(applyOperator(left, right, op.type));
            }
            operators.push(currentToken);
            consumeToken();
        }
    }

    while (!operators.empty()) {
        auto right = operands.top(); operands.pop();
        auto left = operands.top(); operands.pop();
        Token op = operators.top(); operators.pop();
        operands.push(applyOperator(left, right, op.type));
    }

    if (operands.size() != 1) {
        throw std::runtime_error("Invalid expression.");
    }

    auto result = operands.top();
    if (std::holds_alternative<bool>(result)) {
        return std::get<bool>(result);  // Return boolean result for conditional expressions
    } else if (std::holds_alternative<double>(result)) {
        return std::get<double>(result);  // Return numeric result
    } else if (std::holds_alternative<std::string>(result)) {
        return std::get<std::string>(result);  // Return string result
    } else {
        throw std::runtime_error("Unknown result type.");
    }
}

std::variant<int, double, std::string, bool> convertToVariant(const VariableValue& value) {
    if (std::holds_alternative<int>(value)) {
        return std::get<int>(value);
    } else if (std::holds_alternative<double>(value)) {
        return std::get<double>(value);
    } else if (std::holds_alternative<std::string>(value)) {
        return std::get<std::string>(value);
    } else if (std::holds_alternative<bool>(value)) {
        return std::get<bool>(value);
    } else {
        throw std::runtime_error("Unsupported type in VariableValue");
    }
}

void FluxParser::parse() {
    std::cout << "Starting parse...\n";
    parseProgram();
}

void FluxParser::parseProgram() {
    while (currentToken.type != TokenType::EOFF) {
        while (currentToken.type == TokenType::COMMENT || currentToken.type == TokenType::BLOCK_COMMENT) {
            parseComment();
        }
        parseStatement();
    }
    std::cout << "Done.\n";
}

void FluxParser::parseComment() {
    if (currentToken.type == TokenType::COMMENT) {
        std::cout << "Single-line comment: " << currentToken.lexeme << "\n";
        consumeToken();
    } else if (currentToken.type == TokenType::BLOCK_COMMENT) {
        std::cout << "Block comment: " << currentToken.lexeme << "\n";
        consumeToken();
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
                match(TokenType::LPAREN);
                if (currentToken.type == TokenType::IDENTIFIER) {
                    parseCallParams();
                } else {
                    parseArguments();
                    match(TokenType::RPAREN);
                }
                if (TokenType::LBRACE == currentToken.type) {
                    match(TokenType::LBRACE);
                    parseBlock();
                    match(TokenType::RBRACE);
                }
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
        } else if (currentToken.type == TokenType::BREAK) {
            std::cout << "Parsing Break Statement...\n";
            match(TokenType::BREAK);
            match(TokenType::SEMICOLON);
        } else if (currentToken.type == TokenType::PRINT) {
            std::cout << "Parsing Print Statement...\n";
            match(TokenType::PRINT);
            match(TokenType::LPAREN);
            parseCallParams();
        } else if (currentToken.type == TokenType::COMMENT || currentToken.type == TokenType::BLOCK_COMMENT) {
            parseComment();
        } else if (currentToken.type == TokenType::TRY) {
            std::cout << "Parsing Try Statement...\n";
            parseTryCatchFinally();
        } else if (currentToken.type == TokenType::THROW) {
            std::cout << "Parsing Throw Statement...\n";
            parseThrow();
        } else if (currentToken.type == TokenType::ERROR) {
            std::cout << "Parsing Error Statement...\n";
            match(TokenType::ERROR);
            match(TokenType::LPAREN);
            parseCallParams();
        } else {
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

    // Ensure the type is valid
    if (varType != TokenType::VAR_NUMBER && varType != TokenType::VAR_STRING &&
        varType != TokenType::CONST && varType != TokenType::VAR_BOOLEAN && varType != TokenType::VOID) {
        throw std::runtime_error("Expected variable type (VAR_NUMBER, VAR_STRING, VAR_BOOLEAN, CONST, VOID).");
    }

    consumeToken(); // Consume the type token

    bool isConst = (varType == TokenType::CONST);
    if (isConst) {
        std::cout << "Parsing constant declaration...\n";

        // Consume inner type for CONST
        if (currentToken.type != TokenType::VAR_NUMBER && currentToken.type != TokenType::VAR_STRING &&
            currentToken.type != TokenType::VAR_BOOLEAN) {
            throw std::runtime_error("Expected variable type (VAR_NUMBER, VAR_STRING, VAR_BOOLEAN) for constant.");
        }
        consumeToken();
    }

    // Parse function declaration if FUNC token is encountered
    if (currentToken.type == TokenType::FUNC && !isConst) {
        std::cout << "Parsing function declaration...\n";
        parseFunction();
        return;
    }

    // Parse variable name
    if (currentToken.type != TokenType::IDENTIFIER && currentToken.type != TokenType::UPPERCASE_IDENTIFIER) {
        throw std::runtime_error("Expected variable name (identifier, uppercase_identifier).");
    }
    std::string variableName = currentToken.lexeme;
    consumeToken();

    // Parse optional initialization
    VariableValue initialValue;
    if (currentToken.type == TokenType::ASSIGN) {
        consumeToken(); // Consume '='

        initialValue = parseExpression();
    }
    else {
        // Default value based on type
        if (varType == TokenType::VAR_NUMBER) {
            initialValue = 0.0;  // Initialize as a double
        } else if (varType == TokenType::VAR_STRING) {
            initialValue = std::string("");  // Initialize as an empty string
        } else if (varType == TokenType::VAR_BOOLEAN) {
            initialValue = false;  // Initialize as false
        } else if (varType == TokenType::VOID) {
            // No initialization needed for VOID type, use std::monostate to represent uninitialized state
            initialValue = std::monostate{};  // Void represents an uninitialized state
        } else {
            throw std::runtime_error("Invalid variable type for initialization.");
        }
    }
    runtimeVariables.declareVariable(variableName, initialValue);
    match(TokenType::SEMICOLON);

    std::cout << "Declared variable " << variableName << " with value ";
    if (std::holds_alternative<double>(initialValue)) {
        std::cout << std::get<double>(initialValue);
    } else if (std::holds_alternative<std::string>(initialValue)) {
        std::cout << std::get<std::string>(initialValue);
    } else if (std::holds_alternative<bool>(initialValue)) {
        std::cout << (std::get<bool>(initialValue) ? "true" : "false");
    } else if (std::holds_alternative<std::monostate>(initialValue)) {
        std::cout << "void";  // Representing VOID (uninitialized state)
    }
    std::cout << "\n";
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

void FluxParser::parseCallParams() {
    parseExpression();

    while (currentToken.type == TokenType::COMMA) {
        consumeToken();
        parseExpression();
    }

    match(TokenType::RPAREN);
    match(TokenType::SEMICOLON);
}

std::variant<int, double, std::string, bool, std::monostate> FluxParser::parseExpression() {
    std::cout << "Parsing Expression...\n";

    // Example: evaluate an expression (this is a placeholder, replace with your actual logic)
    std::variant<int, double, std::string, bool, std::monostate> result = evaluateExpression();
    return result;  // result is of type double, which is valid for the variant
}

void FluxParser::parsePrimaryExpression() {
    std::cout << "Parsing Primary Expression...\n";
    if (currentToken.type == TokenType::NUMBER) {
        match(TokenType::NUMBER);
    } else if (currentToken.type == TokenType::STRING) {
        match(TokenType::STRING);
    } else if (currentToken.type == TokenType::TRUE) {
        match(TokenType::TRUE);
    } else if (currentToken.type == TokenType::FALSE) {
        match(TokenType::FALSE);
    } else if (currentToken.type == TokenType::IDENTIFIER) {
        match(TokenType::IDENTIFIER);
    } else if (currentToken.type == TokenType::LPAREN) {
        match(TokenType::LPAREN);
        parseExpression();
        match(TokenType::RPAREN);
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
    }

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

        // Parse the start of the range expression
        std::variant<int, double, std::string, bool, std::monostate> startExpr = evaluateExpression();
        if (std::holds_alternative<int>(startExpr)) {
            int startValue = std::get<int>(startExpr);
            std::cout << "Start value: " << startValue << std::endl;

            match(TokenType::COMMA);

            // Parse the end of the range expression
            std::variant<int, double, std::string, bool, std::monostate> endExpr = evaluateExpression();
            if (std::holds_alternative<int>(endExpr)) {
                int endValue = std::get<int>(endExpr);
                std::cout << "End value: " << endValue << std::endl;

                match(TokenType::RPAREN);

                if (currentToken.type == TokenType::RPAREN) {
                    consumeToken();
                }

                // Declare the iterator variable with the start value
                runtime.declareVariable(iterator, startValue);

                // Execute the loop body with the range [startValue, endValue)
                for (int i = startValue; i < endValue; ++i) {
                    // Update the iterator variable in the runtime
                    runtime.declareVariable(iterator, i);

                    // Execute the loop body (block of statements)
                    match(TokenType::LBRACE);
                    parseBlock();
                    match(TokenType::RBRACE);
                }

            } else {
                throw std::runtime_error("End value must be an integer in the 'range' function.");
            }
        } else {
            throw std::runtime_error("Start value must be an integer in the 'range' function.");
        }

    } else {
        throw std::runtime_error("Expected range in 'for' loop.");
    }
}

void FluxParser::parseWhileLoop() {
    std::cout << "Parsing While Loop...\n";
    match(TokenType::WHILE);

    match(TokenType::LPAREN);
    // Parse the condition expression for the while loop
    auto conditionExpr = evaluateExpression();  // Evaluate the expression

    match(TokenType::RPAREN);

    match(TokenType::LBRACE);
    // Parse and execute the block inside the loop
    parseBlock();  // Assumes parseBlock executes statements inside the loop
    match(TokenType::RBRACE);

    // Execute the while loop at runtime
    executeWhileLoop([this]() -> bool {
        // Evaluate the condition expression during each loop iteration
        auto condition = evaluateExpression();
        if (std::holds_alternative<bool>(condition)) {
            return std::get<bool>(condition);  // Return the boolean value
        } else {
            throw std::runtime_error("While loop condition must evaluate to a boolean.");
        }
    }, [&]() {
        // Execute the body of the loop
        parseBlock();  // Re-run the block code for the body of the loop
    });
}

void executeWhileLoop(std::function<bool()> condition, std::function<void()> body) {
    while (condition()) {
        body();  // Execute the body of the loop
    }
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

void FluxParser::parseTryCatchFinally() {
    match(TokenType::TRY);
    match(TokenType::LBRACE);
    parseBlock();
    match(TokenType::RBRACE);

    if (currentToken.type == TokenType::CATCH) {
        match(TokenType::CATCH);
        match(TokenType::LPAREN);
        if (currentToken.type == TokenType::IDENTIFIER) {
            advance();
        } else {
            throw std::runtime_error("Expected exception variable in catch block");
        }
        match(TokenType::RPAREN);
        match(TokenType::LBRACE);
        parseBlock();
        match(TokenType::RBRACE);
    }

    if (currentToken.type == TokenType::FINALLY) {
        match(TokenType::FINALLY);
        match(TokenType::LBRACE);
        parseBlock();
        match(TokenType::RBRACE);
    }
}

void FluxParser::parseThrow() {
    match(TokenType::THROW);
    match(TokenType::NEW);
    parseStatement();
}