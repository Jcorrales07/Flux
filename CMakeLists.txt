cmake_minimum_required(VERSION 3.27)
project(Flux)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_ARCHITECTURES "arm64")

add_executable(Flux main.cpp
        interpreter/FluxTokens.h
        interpreter/FluxLexer.cpp
        interpreter/FluxLexer.h
        interpreter/FluxParser.h
        interpreter/FluxParser.cpp
        interpreter/RuntimeVariables.cpp
        interpreter/RuntimeVariables.h
)
