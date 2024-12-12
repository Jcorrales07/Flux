#include <vector>
#include <variant>
#include <string>
#include <iostream>
#include <stdexcept>
#include "RuntimeVariables.h"

// Helper function for printing variable values
void RuntimeVariables::printValue(const VariableValue& value) const {
    if (std::holds_alternative<int>(value)) {
        std::cout << std::get<int>(value);
    } else if (std::holds_alternative<double>(value)) {
        std::cout << std::get<double>(value);
    } else if (std::holds_alternative<std::string>(value)) {
        std::cout << std::get<std::string>(value);
    } else if (std::holds_alternative<bool>(value)) {
        std::cout << (std::get<bool>(value) ? "true" : "false");
    } else if (std::holds_alternative<std::vector<int>>(value)) {
        std::cout << "[";

        const auto& vec = std::get<std::vector<int>>(value);
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) std::cout << ", ";
        }
        std::cout << "]";
    }
}

void RuntimeVariables::declareVariable(const std::string& name, const VariableValue& value) {
    variables[name] = value;
    std::cout << "Variable " << name << " declared with value: ";
    printValue(value);
    std::cout << std::endl;
}

VariableValue RuntimeVariables::getVariable(const std::string& name) {
    if (variables.find(name) != variables.end()) {
        std::cout << "Variable " << name << " returned value: ";
        printValue(variables[name]);
        std::cout << std::endl;
        return variables[name];
    } else {
        throw std::runtime_error("Variable not found: " + name);
    }
}

bool RuntimeVariables::hasVariable(const std::string& name) const {
    printAllVariables();
    return variables.find(name) != variables.end();
}

// Function to print all variables (now it's a member function)
void RuntimeVariables::printAllVariables() const {
    std::cout << "All declared variables:\n";
    for (const auto& var : variables) {
        std::cout << "Variable " << var.first << " has value: ";
        printValue(var.second);
        std::cout << std::endl;
    }
}

// Function to print a specific variable's value
void RuntimeVariables::printVariable(const std::string& name) const {
    if (variables.find(name) != variables.end()) {
        VariableValue value = variables.at(name);  // Safely access using at()
        std::cout << "Variable " << name << " has value: ";
        printValue(value);  // Use the helper function to print the value
        std::cout << std::endl;
    } else {
        std::cout << "Variable " << name << " not found!" << std::endl;
    }
}
