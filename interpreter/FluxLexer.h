//
// Created by Corra on 10/28/2024.
//

#ifndef FLUX_LEXER_H
#define FLUX_LEXER_H

#include <string>
#include <fstream>
#include <vector>
#include "FluxTokens.h"

class FluxLexer {
public:
    FluxLexer(const std::string &filename);
    std::vector<Token> tokenize();  // Método principal para la tokenización

private:
    std::ifstream fileStream;
    std::string filename;
    int line = 1;
    int column = 0;
    char currentChar;

    bool isFluxFile();
    bool isEOF();
    char readNextChar();
    char readNextOp();
    Token nextToken();
    Token makeIdentifierOrKeyword();
    Token makeNumber();
    Token makeString();
    void skipWhitespace();
};

#endif // FLUX_LEXER_H
