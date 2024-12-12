#include "FluxParser.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include "RuntimeVariables.h"

RuntimeVariables runtimeVariables;
RuntimeVariables runtime;

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

std::variant<int, double, std::string, bool, std::vector<int>> FluxParser::evaluateExpression() {
    std::stack<std::variant<int, double, std::string, bool>> operands; // Stack to store operands
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

    auto applyOperator = [&](std::variant<int, double, std::string, bool> left,
                             std::variant<int, double, std::string, bool> right,
                             TokenType op) {
        if (op == TokenType::ADD) {
            if (std::holds_alternative<std::string>(left) || std::holds_alternative<std::string>(right)) {
                std::string leftStr = std::holds_alternative<std::string>(left) ? std::get<std::string>(left) : std::to_string(std::get<double>(left));
                std::string rightStr = std::holds_alternative<std::string>(right) ? std::get<std::string>(right) : std::to_string(std::get<double>(right));
                return std::variant<int, double, std::string, bool>(leftStr + rightStr);
            } else {
                return std::variant<int, double, std::string, bool>(
                    std::get<double>(left) + std::get<double>(right));
            }
        } else if (op == TokenType::SUBSTRACT) {
            return std::variant<int, double, std::string, bool>(
                std::get<double>(left) - std::get<double>(right));
        } else if (op == TokenType::MULTIPLY) {
            return std::variant<int, double, std::string, bool>(
                std::get<double>(left) * std::get<double>(right));
        } else if (op == TokenType::DIVIDE) {
            if (std::get<double>(right) == 0) throw std::runtime_error("Division by zero.");
            return std::variant<int, double, std::string, bool>(
                std::get<double>(left) / std::get<double>(right));
        } else if (op == TokenType::GREATER_EQUAL) {
            return std::variant<int, double, std::string, bool>(
                std::get<double>(left) > std::get<double>(right));
        } else if (op == TokenType::LESS) {
            return std::variant<int, double, std::string, bool>(
                std::get<double>(left) < std::get<double>(right));
        } else if (op == TokenType::EQUAL) {
            return std::variant<int, double, std::string, bool>(
                std::get<double>(left) == std::get<double>(right));
        } else if (op == TokenType::NOT_EQUAL) {
            return std::variant<int, double, std::string, bool>(
                std::get<double>(left) != std::get<double>(right));
        } else {
            throw std::runtime_error("Unknown operator.");
        }
    };

    while (currentToken.type != TokenType::SEMICOLON && currentToken.type != TokenType::EOFF) {
        if (currentToken.type == TokenType::NUMBER) {
            operands.push(std::variant<int, double, std::string, bool>(std::stod(currentToken.lexeme)));
            consumeToken();
        } else if (currentToken.type == TokenType::STRING) {
            operands.push(std::variant<int, double, std::string, bool>(currentToken.lexeme));
            consumeToken();
        } else if (currentToken.type == TokenType::IDENTIFIER) {
            std::string identifier = currentToken.lexeme;
            if (runtime.hasVariable(identifier)) {
                auto variableValue = runtime.getVariable(identifier);
                if (std::holds_alternative<int>(variableValue)) {
                    operands.push(std::variant<int, double, std::string, bool>(std::get<int>(variableValue)));
                } else if (std::holds_alternative<double>(variableValue)) {
                    operands.push(std::variant<int, double, std::string, bool>(std::get<double>(variableValue)));
                } else if (std::holds_alternative<std::string>(variableValue)) {
                    operands.push(std::variant<int, double, std::string, bool>(std::get<std::string>(variableValue)));
                } else if (std::holds_alternative<bool>(variableValue)) {
                    operands.push(std::variant<int, double, std::string, bool>(std::get<bool>(variableValue)));
                } else {
                    throw std::runtime_error("Unsupported variable type for: " + identifier);
                }
            } else {
                throw std::runtime_error("Variable not found: " + identifier);
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
            // Handle operators
            while (!operators.empty() && precedence(operators.top().type) >= precedence(currentToken.type)) {
                auto right = operands.top(); operands.pop();
                auto left = operands.top(); operands.pop();
                Token op = operators.top(); operators.pop();
                operands.push(applyOperator(left, right, op.type));
            }
            operators.push(currentToken);
            consumeToken();  // Move to the next token
        }
    }

    // Apply remaining operators in the stack
    while (!operators.empty()) {
        auto right = operands.top(); operands.pop();
        auto left = operands.top(); operands.pop();
        Token op = operators.top(); operators.pop();
        operands.push(applyOperator(left, right, op.type));
    }

    // Ensure there is only one result left on the operand stack
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

    // Check if the variable has already been declared
    if (runtimeVariables.hasVariable(variableName)) {
        throw std::runtime_error("Variable already declared: " + variableName);
    }

    consumeToken();

    // Parse optional initialization
    VariableValue initialValue;
    if (currentToken.type == TokenType::ASSIGN) {
        consumeToken(); // Consume '='

        initialValue = parseExpression();
    } else {
        if (varType == TokenType::VAR_NUMBER) {
            initialValue = 0.0;  // Initialize as a double
        } else if (varType == TokenType::VAR_STRING) {
            initialValue = std::string("");  // Initialize as an empty string
        } else if (varType == TokenType::VAR_BOOLEAN) {
            initialValue = false;  // Initialize as false
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
    std::vector<std::variant<int, double, std::string, bool, std::vector<int>>> parsedResults;
    parsedResults.push_back(parseExpression());
    while (currentToken.type == TokenType::COMMA) {
        consumeToken();
        parsedResults.push_back(parseExpression());
    }
    consumeToken();
    printResults(parsedResults);
}

void FluxParser::printResults(const std::vector<std::variant<int, double, std::string, bool, std::vector<int>>>& parsedResults) {
    std::cout << "All parsed expressions:" << std::endl;
    for (const auto& result : parsedResults) {
        print(result);
    }
}

void FluxParser::print(const std::variant<int, double, std::string, bool, std::vector<int>>& result) {
    std::visit([](auto&& arg) {
        if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, int>) {
            std::cout << arg << std::endl;
        } else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, double>) {
            std::cout << arg << std::endl;
        } else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, std::string>) {
            std::cout << arg << std::endl;
        } else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, bool>) {
            std::cout << (arg ? "true" : "false") << std::endl;
        } else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, std::vector<int>>) {
            std::cout << "[";
            for (const auto& val : arg) {
                std::cout << val << " ";
            }
            std::cout << "]" << std::endl;
        }
    }, result);
}


std::variant<int, double, std::string, bool, std::vector<int>> FluxParser::parseExpression() {
    std::cout << "Parsing Expression...\n";
    std::variant<int, double, std::string, bool, std::vector<int>> result = evaluateExpression();
    return result;
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
        std::variant<int, double, std::string, bool, std::vector<int>> startExpr = evaluateExpression();
        if (std::holds_alternative<int>(startExpr)) {
            int startValue = std::get<int>(startExpr);
            std::cout << "Start value: " << startValue << std::endl;

            match(TokenType::COMMA);

            // Parse the end of the range expression
            std::variant<int, double, std::string, bool, std::vector<int>> endExpr = evaluateExpression();
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
    bool conditionResult = evaluateCondition();
    match(TokenType::RPAREN);
    match(TokenType::LBRACE);

    executeWhileLoop([this, conditionResult]() mutable -> bool {  // Capture conditionResult by mutable reference
        bool currentCondition = evaluateCondition();  // Reevaluate the condition in each iteration
        conditionResult = currentCondition; // Update the stored condition value
        return conditionResult;  // Return the updated result
    }, [&]() {
        parseBlock();
    });
    match(TokenType::RBRACE);
}

std::variant<bool, int, std::string> FluxParser::parseConditionExpression() {
    auto leftOperand = parseOperand();

    if (currentToken.type == TokenType::EQUAL ||
        currentToken.type == TokenType::NOT_EQUAL ||
        currentToken.type == TokenType::LESS ||
        currentToken.type == TokenType::GREATER ||
        currentToken.type == TokenType::LESS_EQUAL ||
        currentToken.type == TokenType::GREATER_EQUAL) {
        Token expression = currentToken;
        consumeToken();
        auto rightOperand = parseOperand();
        return evaluateComparison(leftOperand, expression, rightOperand);
    }
    return leftOperand;
}


bool FluxParser::evaluateCondition() {
    auto condition = parseConditionExpression();
    if (std::holds_alternative<bool>(condition)) {
        return std::get<bool>(condition);
    } else if (std::holds_alternative<int>(condition)) {
        return std::get<int>(condition) != 0;
    } else if (std::holds_alternative<std::string>(condition)) {
        throw std::runtime_error("Una cadena no puede ser usada directamente como una condición.");
    } else {
        throw std::runtime_error("La condición del bucle while debe ser un booleano o un número.");
    }
}

std::variant<bool, int, std::string> FluxParser::parseOperand() {
    if (currentToken.type == TokenType::TRUE || currentToken.type == TokenType::FALSE) {
        consumeToken();
        return currentToken.type == TokenType::TRUE;
    }
    else if (currentToken.type == TokenType::NUMBER) {
        std::variant<bool, int, std::string> val = std::stoi(currentToken.lexeme);
        consumeToken();
        try {
            return val;
        } catch (const std::invalid_argument& e) {
            throw std::runtime_error("El valor del número no es válido: " + currentToken.lexeme);
        } catch (const std::out_of_range& e) {
            throw std::runtime_error("El número está fuera del rango permitido: " + currentToken.lexeme);
        }
    }
    else if (currentToken.type == TokenType::STRING) {
        std::string val = currentToken.lexeme;
        consumeToken();
        return val;
    } else {
        throw std::runtime_error("Operando inválido en la condición.");
    }
}

bool FluxParser::evaluateComparison(
    const std::variant<bool, int, std::string>& leftOperand,
    const Token& operatorToken,
    const std::variant<bool, int, std::string>& rightOperand) {

    if (leftOperand.index() != rightOperand.index()) {
        throw std::runtime_error("Los operandos deben ser del mismo tipo para la comparación.");
    }

    if (std::holds_alternative<bool>(leftOperand)) {
        bool left = std::get<bool>(leftOperand);
        bool right = std::get<bool>(rightOperand);

        if (operatorToken.type == TokenType::EQUAL) return left == right;
        if (operatorToken.type == TokenType::NOT_EQUAL) return left != right;
    }

    // Manejo de números
    else if (std::holds_alternative<int>(leftOperand)) {
        int left = std::get<int>(leftOperand);
        int right = std::get<int>(rightOperand);

        if (operatorToken.type == TokenType::EQUAL) return left == right;
        if (operatorToken.type == TokenType::NOT_EQUAL) return left != right;
        if (operatorToken.type == TokenType::LESS) return left < right;
        if (operatorToken.type == TokenType::GREATER) return left > right;
        if (operatorToken.type == TokenType::LESS_EQUAL) return left <= right;
        if (operatorToken.type == TokenType::GREATER_EQUAL) return left >= right;
    }

    // Manejo de cadenas
    else if (std::holds_alternative<std::string>(leftOperand)) {
        std::string left = std::get<std::string>(leftOperand);
        std::string right = std::get<std::string>(rightOperand);
        std::cout << left << operatorToken.lexeme << right << std::endl;

        if (operatorToken.type == TokenType::EQUAL) return left == right;
        if (operatorToken.type == TokenType::NOT_EQUAL) return left != right;
    }

    throw std::runtime_error("Operador o tipo de datos inválido para la comparación.");
}


void FluxParser::executeWhileLoop(std::function<bool()> condition, std::function<void()> body) {
    while (condition()) {
        body();
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