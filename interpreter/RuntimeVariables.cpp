#include <vector>
#include <variant>
#include <string>
#include <iostream>
#include <map>

using VariableValue = std::variant<int, double, std::string, bool, std::monostate, std::vector<int>>;

class RuntimeVariables {
public:
    // Declare a variable and store it in the map
    void declareVariable(const std::string& name, const VariableValue& value);

    // Retrieve a variable by its name
    VariableValue getVariable(const std::string& name);

    // Check if the variable exists
    bool hasVariable(const std::string& name) const;

    // Print the value of a variable for debugging
    void printVariable(const std::string& name);

private:
    std::map<std::string, VariableValue> variables; // Store variables in a map
};

void RuntimeVariables::declareVariable(const std::string& name, const VariableValue& value) {
    variables[name] = value;
    std::cout << "Variable " << name << " declared with value: ";

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
        auto& vec = std::get<std::vector<int>>(value);
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) std::cout << ", ";
        }
        std::cout << "]";
    } else if (std::holds_alternative<std::monostate>(value)) {
        std::cout << "uninitialized (std::monostate)";
    }

    std::cout << std::endl;
}

VariableValue RuntimeVariables::getVariable(const std::string& name) {
    if (variables.find(name) != variables.end()) {
        return variables[name];  // Return the variable if found
    } else {
        throw std::runtime_error("Variable not found: " + name);  // Throw an error if not found
    }
}

bool RuntimeVariables::hasVariable(const std::string& name) const {
    return variables.find(name) != variables.end();  // Return true if found, false otherwise
}

void RuntimeVariables::printVariable(const std::string& name) {
    if (variables.find(name) != variables.end()) {
        VariableValue value = variables[name];
        std::cout << "Variable " << name << " has value: ";

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
            auto& vec = std::get<std::vector<int>>(value);
            for (size_t i = 0; i < vec.size(); ++i) {
                std::cout << vec[i];
                if (i < vec.size() - 1) std::cout << ", ";
            }
            std::cout << "]";
        } else if (std::holds_alternative<std::monostate>(value)) {
            std::cout << "uninitialized (std::monostate)";
        }

        std::cout << std::endl;
    } else {
        std::cout << "Variable " << name << " not found!" << std::endl;
    }
}