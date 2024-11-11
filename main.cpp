#include "interpreter/FluxLexer.h"
#include <iostream>

int main() {
    std::string file = "../fluxProgram.flux";

    try {
        FluxLexer lexer(file);
        std::vector<Token> tokens = lexer.tokenize();

        for (const auto &token : tokens) {
            printf("Token: %s \tType: %d Line: %d Column: %d\n", token.lexeme.c_str(), static_cast<int>(token.type), token.line, token.column);
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
