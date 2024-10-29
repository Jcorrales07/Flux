//
// Created by Corra on 10/28/2024.
//

#include "FluxLexer.h"
#include "FluxTokens.h"

#include "iostream"
#include "fstream"
#include "string"

#include "filesystem"

void readFluxFile(const char *inputFile) {
    std::filesystem::path filePath = inputFile;

    if (!(filePath.extension() == ".flux")) {
        std::cout << "Archivo distinto a .flux \n";
        return;
    }

    std::cout << "Leyendo archivo Flux\n";

    std::ifstream FluxFile;
    std::string content;
    char line;

    FluxFile.open(inputFile);

    while (FluxFile) {
        line = FluxFile.get();
        std::cout << line;

        if (line == ' ') return;
    }
}