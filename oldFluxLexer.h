//
// Created by Corra on 10/30/2024.
//


#include <fstream>
#include "iostream"
#include "filesystem"

#include "vector"
#include "interpreter/FluxTokens.h"


class oldFluxLexer {

// Para leer las lineas, solo que lo lee caracter por caracter, no hace el token como tal
    void readFluxFile(std::string &sourceCode) {
        std::filesystem::path filePath = sourceCode;


        if (!(filePath.extension() == ".flux")) {
            std::cout << "Archivo distinto a .flux \n";
            return;
        }

        std::cout << "Leyendo archivo Flux\n";

        std::ifstream FluxFile;
        std::string content;
        char line;

        FluxFile.open(sourceCode);

        while (FluxFile) {
            line = FluxFile.get();
            std::cout << line;
        }
    }

//Ocupo que, cada encuentre un caracter especial () {} [] , . "",
// lo que sea pero que sea distinto a una letra, que lo separe en su propio token
    std::vector<std::string> splitString(const std::string &sourceCode) {
        std::vector<std::string> words;
        std::string word;

        std::filesystem::path filePath = sourceCode;

        if (!(filePath.extension() == ".flux")) {
            std::cout << "Archivo distinto a .flux \n";
            return words;
        }

        std::ifstream FluxFile;
        FluxFile.open(sourceCode);
        char ch;

        // Itera por el codigo convertido a texto y arma palabras
        // ignorando los espacios, no importa cuantos halla

        while (FluxFile) {
            ch = FluxFile.get();
            if (ch != ' ') {
                word += ch;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }

        return words;
    }


    std::vector<Token> tokenizeFluxFile(std::string &sourceCode) {
        std::vector<Token> fileTokens;
        std::vector<std::string> src = splitString(sourceCode);

        printf("src size: %zu", src.size());

        while (!src.empty()) {
            std::cout << src.front() << std::endl;
            src.pop_back();
        }

        return fileTokens;
    }

};


//
// Created by Corra on 10/28/2024.
//

//#ifndef FLUX_FLUXLEXER_H
//#define FLUX_FLUXLEXER_H
//
//#include <string>
//#include <vector>
//#include "istream"
//
//#include "FluxTokens.h"
//
////Pruebas anteriores
////void readFluxFile(std::string &sourceCode);
////std::vector<std::string> splitString(const std::string &sourceCode);
////std::vector<Token> tokenizeFluxFile(std::string &sourceCode);
//
//
//// Clase para manejar el estado del lexer
//// Iterando por [t]odo el texto del archivo
//
//// El estado se conforma por:
//// la posicion del flujo de datos con streampos
//// el numero de linea actual, en donde esta posicionado el Lexer
//// el texto de la linea actual
//
//class LexerState {
//
//public:
//    LexerState() {}
//
//    LexerState(std::streampos pos, int line, const std::string &text):
//            stream_pos(pos),  src_line(line), text(text)
//    {};
//
//    std::streampos stream_pos;
//    int src_line;
//    const std::string text;
//};
//
//
//// Clase para el Lexer de Flux
//class FluxLexer {
//
//public:
//    FluxLexer(std::istream &in): in(in), src_line(1) {}
//
//    // Destructor
//    ~FluxLexer() {}
//
//    // Un getter, para saber en que numero de linea estamos
//    int getLine() {
//        return src_line;
//    }
//
//    // Metodo que nos retorna el siguiente token (METODO PRINCIPAL)
//    Token getNextToken();
//
//    // Metodo que nos retorna el texto actual del estado del lexer
//    std::string getText() const {
//        return text;
//    }
//
//    // Para actualizar el estado del Lexer al del momento
//    void setCurrentState(const LexerState &lstate) {
//        // stream_pos es para posicionar el cursor del flujo en la posicion del estado del lexer
//        // el segundo parametro es como la referencia para el primero. Es para darle una direccion al offset
//        // Y se da como referencia el inicio del flujo
//        in.seekg(lstate.stream_pos, std::istream::beg);
//
//        // para actualizar el # de la linea que estamos tokenizando
//        src_line = lstate.src_line;
//
//        // para actualizar el texto de la linea que estamos tokenizando
//        text = lstate.text;
//    }
//
//    // Metodo para conseguir el estado actual
//    LexerState getCurrentState() const {
//        return LexerState(in.tellg(), src_line, text);
//    }
//
//private:
//    void ungetChar(int ch);
//    int nextChar();
//
//private:
//    std::istream &in;
//    int src_line;
//    std::string text;
//};
//
//#endif //FLUX_FLUXLEXER_H
