#ifndef RUNTIMEVARIABLES_H
#define RUNTIMEVARIABLES_H

#include <string>
#include <unordered_map>
#include <variant>
#include <stdexcept>
#include <iostream>
// Define a VariableValue type as a std::variant to hold different types of variables
using VariableValue = std::variant<int, double, std::string, bool, std::monostate>;

class RuntimeVariables {
public:
    // Map to store variables by their name
    std::unordered_map<std::string, VariableValue> variables;

    // Declare a variable and store it in the map
    void declareVariable(const std::string& name, const VariableValue& value);

    // Retrieve a variable by its name
    VariableValue getVariable(const std::string& name);

    bool hasVariable(const std::string& name) const;
    // Print the value of a variable for debugging
    void printVariable(const std::string& name);
};

#endif // RUNTIMEVARIABLES_H