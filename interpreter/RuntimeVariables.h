#ifndef RUNTIMEVARIABLES_H
#define RUNTIMEVARIABLES_H

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "FluxParser.h"

using VariableValue = std::variant<int, double, std::string, bool, std::vector<int>>;

class RuntimeVariables {
public:
    VariableValue getVariable(const std::string& name);
    void printValue(const VariableValue &value) const;
    void declareVariable(const std::string& name, const VariableValue& value);
    bool hasVariable(const std::string& name) const;
    void printAllVariables() const;
    void printVariable(const std::string &name) const;

private:
    std::string valueToString(const VariableValue& value) const;
    std::unordered_map<std::string, VariableValue> variables;
};

#endif // RUNTIMEVARIABLES_H
