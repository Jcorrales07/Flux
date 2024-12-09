
// Generated from ./FluxFiles/FluxLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  FluxLexer : public antlr4::Lexer {
public:
  enum {
    CLASS = 1, EXTENDS = 2, PUBLIC = 3, PRIVATE = 4, SUPER = 5, THIS = 6, 
    NEW = 7, EXPORT = 8, IMPORT = 9, FROM = 10, STRUCT = 11, FUNC = 12, 
    RETURN = 13, IF = 14, ELSEIF = 15, ELSE = 16, WHILE = 17, DO = 18, BREAK = 19, 
    CONTINUE = 20, FOR = 21, IN = 22, SWITCH = 23, CASE = 24, DEFAULT = 25, 
    TRY = 26, CATCH = 27, FINALLY = 28, CONST = 29, NUMBER_VAR = 30, STRING_VAR = 31, 
    BOOLEAN_VAR = 32, UPPERCASE_IDENTIFIER = 33, CLASS_IDENTIFIER = 34, 
    IDENTIFIER = 35, PRINT_FUNC = 36, RANGE_FUNC = 37, ASSIGN = 38, ADD_ASSIGN = 39, 
    SUB_ASSIGN = 40, MUL_ASSIGN = 41, DIV_ASSIGN = 42, ADD = 43, SUBTRACT = 44, 
    MULTIPLY = 45, DIVIDE = 46, MOD = 47, POWER = 48, LESS = 49, GREATER = 50, 
    LESS_EQUAL = 51, GREATER_EQUAL = 52, EQUAL = 53, NOT_EQUAL = 54, AND = 55, 
    OR = 56, NOT = 57, COMMA = 58, DOT = 59, SEMICOLON = 60, COLON = 61, 
    LPAREN = 62, RPAREN = 63, LBRACE = 64, RBRACE = 65, LBRACK = 66, RBRACK = 67, 
    BOOL_LIT = 68, INT_LIT = 69, DECIMAL_LIT = 70, STRING_LIT = 71, COMMENT = 72, 
    BLOCK_COMMENT = 73, WS = 74, ILLEGAL = 75
  };

  explicit FluxLexer(antlr4::CharStream *input);

  ~FluxLexer();


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

