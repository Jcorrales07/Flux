#include "interpreter/FluxLexer.h"
#include <iostream>

int main() {
    std::string file = R"(C:\Users\Corra\CLionProjects\Flux\fluxProgram.flux)";

    try {
        FluxLexer lexer(file);
        std::vector<Token> tokens = lexer.tokenize();

        for (const auto &token : tokens) {
            std::cout << "Token: " << token.lexeme
            << " Type: " << static_cast<int>(token.type) << std::endl;
//            << " Line: " << token.line << " Column: "
//            << token.column << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
