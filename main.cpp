#include "interpreter/FluxLexer.h"
#include "interpreter/FluxParser.h"
#include <iostream>
#include <stdexcept>
#include <vector>

int main(int argc, char **argv) {
    std::string file = R"(C:\Users\Corra\CLionProjects\Flux\fluxProgram.flux)";  // Default file path

    // Check if the user provided a file as a command-line argument
    if (argc > 1) {
        file = argv[1];
    }

    try {
        FluxLexer lexer(file);
        std::vector<Token> tokens = lexer.tokenize();
        std::cout << "Tokens parsed from file: " << file << std::endl;
        for (const auto &token: tokens) {
            std::cout << "Token: " << token.lexeme << "\tType: "
                      << static_cast<int>(token.type)
                      << "\tLine: " << token.line
                      << "\tColumn: " << token.column << std::endl;
        }
        // Now that we have the tokens, let's parse them
        FluxParser parser(tokens);
        parser.parse();  // Parse the tokens using the FluxParser
        // std::cout << "Parsing completed successfully." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
