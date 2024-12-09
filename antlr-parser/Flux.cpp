
// Generated from ./FluxFiles/Flux.g4 by ANTLR 4.13.2


#include "FluxListener.h"

#include "Flux.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct FluxStaticData final {
  FluxStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FluxStaticData(const FluxStaticData&) = delete;
  FluxStaticData(FluxStaticData&&) = delete;
  FluxStaticData& operator=(const FluxStaticData&) = delete;
  FluxStaticData& operator=(FluxStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag fluxParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<FluxStaticData> fluxParserStaticData = nullptr;

void fluxParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (fluxParserStaticData != nullptr) {
    return;
  }
#else
  assert(fluxParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<FluxStaticData>(
    std::vector<std::string>{
      "program", "declaration", "importDeclaration", "importList", "importItem", 
      "exportDeclaration", "classDeclaration", "publicBlock", "privateBlock", 
      "constructorDeclaration", "superCall", "constructorInitStatement", 
      "methodDeclaration", "constDeclaration", "varDeclaration", "statement", 
      "whileStatement", "doWhileStatement", "breakStatement", "continueStatement", 
      "forStatement", "forRange", "rangeExpr", "builtInCall", "block", "assignmentStatement", 
      "arrayAssignmentStatement", "arrayLiteral", "arrayAccess", "ifStatement", 
      "valueAccess", "expr", "arithmeticOp", "compareOp", "logicalOp", "assignOp", 
      "notExpr", "classInstantiation", "term", "factor", "funcDeclaration", 
      "funcCall", "paramList", "param", "returnStmt", "type"
    },
    std::vector<std::string>{
      "", "'class'", "'extends'", "'public'", "'private'", "'super'", "'this'", 
      "'new'", "'export'", "'import'", "'from'", "'struct'", "'func'", "'return'", 
      "'if'", "'elseif'", "'else'", "'while'", "'do'", "'break'", "'continue'", 
      "'for'", "'in'", "'switch'", "'case'", "'default'", "'try'", "'catch'", 
      "'finally'", "'const'", "'number'", "'string'", "'bool'", "", "", 
      "", "'print'", "'range'", "'='", "'+='", "'-='", "'*='", "'/='", "'+'", 
      "'-'", "'*'", "'/'", "'%'", "'**'", "'<'", "'>'", "'<='", "'>='", 
      "'=='", "'!='", "'&&'", "'||'", "'!'", "','", "'.'", "';'", "':'", 
      "'('", "')'", "'{'", "'}'", "'['", "']'"
    },
    std::vector<std::string>{
      "", "CLASS", "EXTENDS", "PUBLIC", "PRIVATE", "SUPER", "THIS", "NEW", 
      "EXPORT", "IMPORT", "FROM", "STRUCT", "FUNC", "RETURN", "IF", "ELSEIF", 
      "ELSE", "WHILE", "DO", "BREAK", "CONTINUE", "FOR", "IN", "SWITCH", 
      "CASE", "DEFAULT", "TRY", "CATCH", "FINALLY", "CONST", "NUMBER_VAR", 
      "STRING_VAR", "BOOLEAN_VAR", "UPPERCASE_IDENTIFIER", "CLASS_IDENTIFIER", 
      "IDENTIFIER", "PRINT_FUNC", "RANGE_FUNC", "ASSIGN", "ADD_ASSIGN", 
      "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "ADD", "SUBTRACT", "MULTIPLY", 
      "DIVIDE", "MOD", "POWER", "LESS", "GREATER", "LESS_EQUAL", "GREATER_EQUAL", 
      "EQUAL", "NOT_EQUAL", "AND", "OR", "NOT", "COMMA", "DOT", "SEMICOLON", 
      "COLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", 
      "BOOL_LIT", "INT_LIT", "DECIMAL_LIT", "STRING_LIT", "COMMENT", "BLOCK_COMMENT", 
      "WS", "ILLEGAL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,75,568,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,1,0,5,0,94,8,0,10,0,12,0,97,9,0,1,0,
  	1,0,1,0,5,0,102,8,0,10,0,12,0,105,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,
  	3,1,115,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,5,3,126,8,3,10,3,12,3,
  	129,9,3,1,4,1,4,1,5,1,5,1,5,1,5,3,5,137,8,5,1,6,1,6,1,6,1,6,3,6,143,8,
  	6,1,6,1,6,3,6,147,8,6,1,6,3,6,150,8,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,5,7,
  	159,8,7,10,7,12,7,162,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,5,8,171,8,8,10,
  	8,12,8,174,9,8,1,8,1,8,1,9,1,9,1,9,3,9,181,8,9,1,9,1,9,1,9,1,9,1,9,5,
  	9,188,8,9,10,9,12,9,191,9,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,5,10,200,
  	8,10,10,10,12,10,203,9,10,3,10,205,8,10,1,10,1,10,1,10,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,3,12,222,8,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,3,12,231,8,12,1,12,1,12,3,12,235,8,12,1,13,1,
  	13,1,13,1,13,1,13,1,13,3,13,243,8,13,1,13,1,13,1,14,1,14,1,14,1,14,1,
  	14,3,14,252,8,14,3,14,254,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,5,14,267,8,14,10,14,12,14,270,9,14,3,14,272,8,14,1,14,
  	1,14,1,14,3,14,277,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,3,15,294,8,15,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,19,1,19,
  	1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,3,21,326,8,21,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,3,22,335,8,22,3,22,337,8,22,1,22,1,
  	22,1,23,1,23,1,23,1,23,1,23,1,23,3,23,347,8,23,1,24,1,24,5,24,351,8,24,
  	10,24,12,24,354,9,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	5,25,366,8,25,10,25,12,25,369,9,25,3,25,371,8,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,387,8,25,1,26,
  	1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,5,27,398,8,27,10,27,12,27,401,
  	9,27,3,27,403,8,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,
  	1,28,1,28,3,28,417,8,28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,1,29,5,29,430,8,29,10,29,12,29,433,9,29,1,29,1,29,3,29,437,8,29,
  	1,30,1,30,1,30,1,30,3,30,443,8,30,1,31,1,31,1,31,3,31,448,8,31,1,31,1,
  	31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,5,31,462,8,31,10,
  	31,12,31,465,9,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,1,
  	36,1,37,1,37,1,37,1,37,1,37,5,37,483,8,37,10,37,12,37,486,9,37,3,37,488,
  	8,37,1,37,1,37,1,38,1,38,1,38,1,38,3,38,496,8,38,3,38,498,8,38,1,39,1,
  	39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,3,39,513,8,
  	39,1,40,1,40,1,40,1,40,1,40,3,40,520,8,40,1,40,1,40,1,40,1,40,1,40,1,
  	40,1,40,3,40,529,8,40,1,40,1,40,3,40,533,8,40,1,41,1,41,1,41,1,41,1,41,
  	5,41,540,8,41,10,41,12,41,543,9,41,3,41,545,8,41,1,41,1,41,1,42,1,42,
  	1,42,5,42,552,8,42,10,42,12,42,555,9,42,1,43,1,43,1,43,1,44,1,44,3,44,
  	562,8,44,1,44,1,44,1,45,1,45,1,45,0,1,62,46,0,2,4,6,8,10,12,14,16,18,
  	20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,
  	66,68,70,72,74,76,78,80,82,84,86,88,90,0,6,1,0,33,35,1,0,43,48,1,0,49,
  	54,1,0,55,56,1,0,38,42,2,0,30,32,34,34,609,0,95,1,0,0,0,2,114,1,0,0,0,
  	4,116,1,0,0,0,6,122,1,0,0,0,8,130,1,0,0,0,10,132,1,0,0,0,12,138,1,0,0,
  	0,14,153,1,0,0,0,16,165,1,0,0,0,18,177,1,0,0,0,20,194,1,0,0,0,22,209,
  	1,0,0,0,24,234,1,0,0,0,26,236,1,0,0,0,28,276,1,0,0,0,30,293,1,0,0,0,32,
  	295,1,0,0,0,34,301,1,0,0,0,36,309,1,0,0,0,38,312,1,0,0,0,40,315,1,0,0,
  	0,42,325,1,0,0,0,44,327,1,0,0,0,46,346,1,0,0,0,48,348,1,0,0,0,50,386,
  	1,0,0,0,52,388,1,0,0,0,54,393,1,0,0,0,56,416,1,0,0,0,58,418,1,0,0,0,60,
  	438,1,0,0,0,62,447,1,0,0,0,64,466,1,0,0,0,66,468,1,0,0,0,68,470,1,0,0,
  	0,70,472,1,0,0,0,72,474,1,0,0,0,74,477,1,0,0,0,76,497,1,0,0,0,78,512,
  	1,0,0,0,80,532,1,0,0,0,82,534,1,0,0,0,84,548,1,0,0,0,86,556,1,0,0,0,88,
  	559,1,0,0,0,90,565,1,0,0,0,92,94,3,4,2,0,93,92,1,0,0,0,94,97,1,0,0,0,
  	95,93,1,0,0,0,95,96,1,0,0,0,96,103,1,0,0,0,97,95,1,0,0,0,98,102,3,2,1,
  	0,99,102,3,30,15,0,100,102,3,82,41,0,101,98,1,0,0,0,101,99,1,0,0,0,101,
  	100,1,0,0,0,102,105,1,0,0,0,103,101,1,0,0,0,103,104,1,0,0,0,104,106,1,
  	0,0,0,105,103,1,0,0,0,106,107,5,0,0,1,107,1,1,0,0,0,108,115,3,26,13,0,
  	109,115,3,28,14,0,110,115,3,80,40,0,111,115,3,12,6,0,112,115,3,4,2,0,
  	113,115,3,10,5,0,114,108,1,0,0,0,114,109,1,0,0,0,114,110,1,0,0,0,114,
  	111,1,0,0,0,114,112,1,0,0,0,114,113,1,0,0,0,115,3,1,0,0,0,116,117,5,10,
  	0,0,117,118,5,35,0,0,118,119,5,9,0,0,119,120,3,6,3,0,120,121,5,60,0,0,
  	121,5,1,0,0,0,122,127,3,8,4,0,123,124,5,58,0,0,124,126,3,8,4,0,125,123,
  	1,0,0,0,126,129,1,0,0,0,127,125,1,0,0,0,127,128,1,0,0,0,128,7,1,0,0,0,
  	129,127,1,0,0,0,130,131,7,0,0,0,131,9,1,0,0,0,132,136,5,8,0,0,133,137,
  	3,12,6,0,134,137,3,80,40,0,135,137,3,26,13,0,136,133,1,0,0,0,136,134,
  	1,0,0,0,136,135,1,0,0,0,137,11,1,0,0,0,138,139,5,1,0,0,139,142,5,34,0,
  	0,140,141,5,2,0,0,141,143,5,34,0,0,142,140,1,0,0,0,142,143,1,0,0,0,143,
  	144,1,0,0,0,144,146,5,64,0,0,145,147,3,14,7,0,146,145,1,0,0,0,146,147,
  	1,0,0,0,147,149,1,0,0,0,148,150,3,16,8,0,149,148,1,0,0,0,149,150,1,0,
  	0,0,150,151,1,0,0,0,151,152,5,65,0,0,152,13,1,0,0,0,153,154,5,3,0,0,154,
  	160,5,64,0,0,155,159,3,28,14,0,156,159,3,18,9,0,157,159,3,24,12,0,158,
  	155,1,0,0,0,158,156,1,0,0,0,158,157,1,0,0,0,159,162,1,0,0,0,160,158,1,
  	0,0,0,160,161,1,0,0,0,161,163,1,0,0,0,162,160,1,0,0,0,163,164,5,65,0,
  	0,164,15,1,0,0,0,165,166,5,4,0,0,166,172,5,64,0,0,167,171,3,28,14,0,168,
  	171,3,18,9,0,169,171,3,24,12,0,170,167,1,0,0,0,170,168,1,0,0,0,170,169,
  	1,0,0,0,171,174,1,0,0,0,172,170,1,0,0,0,172,173,1,0,0,0,173,175,1,0,0,
  	0,174,172,1,0,0,0,175,176,5,65,0,0,176,17,1,0,0,0,177,178,5,34,0,0,178,
  	180,5,62,0,0,179,181,3,84,42,0,180,179,1,0,0,0,180,181,1,0,0,0,181,182,
  	1,0,0,0,182,183,5,63,0,0,183,189,5,64,0,0,184,188,3,22,11,0,185,188,3,
  	50,25,0,186,188,3,20,10,0,187,184,1,0,0,0,187,185,1,0,0,0,187,186,1,0,
  	0,0,188,191,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,192,1,0,0,0,191,
  	189,1,0,0,0,192,193,5,65,0,0,193,19,1,0,0,0,194,195,5,5,0,0,195,204,5,
  	62,0,0,196,201,3,62,31,0,197,198,5,58,0,0,198,200,3,62,31,0,199,197,1,
  	0,0,0,200,203,1,0,0,0,201,199,1,0,0,0,201,202,1,0,0,0,202,205,1,0,0,0,
  	203,201,1,0,0,0,204,196,1,0,0,0,204,205,1,0,0,0,205,206,1,0,0,0,206,207,
  	5,63,0,0,207,208,5,60,0,0,208,21,1,0,0,0,209,210,5,6,0,0,210,211,5,59,
  	0,0,211,212,5,35,0,0,212,213,5,38,0,0,213,214,3,62,31,0,214,215,5,60,
  	0,0,215,23,1,0,0,0,216,217,3,90,45,0,217,218,5,12,0,0,218,219,5,35,0,
  	0,219,221,5,62,0,0,220,222,3,84,42,0,221,220,1,0,0,0,221,222,1,0,0,0,
  	222,223,1,0,0,0,223,224,5,63,0,0,224,225,3,48,24,0,225,235,1,0,0,0,226,
  	227,5,12,0,0,227,228,5,35,0,0,228,230,5,62,0,0,229,231,3,84,42,0,230,
  	229,1,0,0,0,230,231,1,0,0,0,231,232,1,0,0,0,232,233,5,63,0,0,233,235,
  	3,48,24,0,234,216,1,0,0,0,234,226,1,0,0,0,235,25,1,0,0,0,236,237,5,29,
  	0,0,237,238,3,90,45,0,238,239,5,33,0,0,239,242,5,38,0,0,240,243,3,62,
  	31,0,241,243,3,54,27,0,242,240,1,0,0,0,242,241,1,0,0,0,243,244,1,0,0,
  	0,244,245,5,60,0,0,245,27,1,0,0,0,246,247,3,90,45,0,247,253,5,35,0,0,
  	248,251,5,38,0,0,249,252,3,62,31,0,250,252,3,54,27,0,251,249,1,0,0,0,
  	251,250,1,0,0,0,252,254,1,0,0,0,253,248,1,0,0,0,253,254,1,0,0,0,254,255,
  	1,0,0,0,255,256,5,60,0,0,256,277,1,0,0,0,257,258,3,90,45,0,258,259,5,
  	35,0,0,259,260,5,38,0,0,260,261,5,7,0,0,261,262,5,34,0,0,262,271,5,62,
  	0,0,263,268,3,62,31,0,264,265,5,58,0,0,265,267,3,62,31,0,266,264,1,0,
  	0,0,267,270,1,0,0,0,268,266,1,0,0,0,268,269,1,0,0,0,269,272,1,0,0,0,270,
  	268,1,0,0,0,271,263,1,0,0,0,271,272,1,0,0,0,272,273,1,0,0,0,273,274,5,
  	63,0,0,274,275,5,60,0,0,275,277,1,0,0,0,276,246,1,0,0,0,276,257,1,0,0,
  	0,277,29,1,0,0,0,278,294,3,2,1,0,279,294,3,50,25,0,280,294,3,52,26,0,
  	281,294,3,60,30,0,282,294,3,58,29,0,283,294,3,40,20,0,284,294,3,32,16,
  	0,285,294,3,34,17,0,286,294,3,36,18,0,287,294,3,38,19,0,288,294,3,88,
  	44,0,289,294,3,48,24,0,290,291,3,62,31,0,291,292,5,60,0,0,292,294,1,0,
  	0,0,293,278,1,0,0,0,293,279,1,0,0,0,293,280,1,0,0,0,293,281,1,0,0,0,293,
  	282,1,0,0,0,293,283,1,0,0,0,293,284,1,0,0,0,293,285,1,0,0,0,293,286,1,
  	0,0,0,293,287,1,0,0,0,293,288,1,0,0,0,293,289,1,0,0,0,293,290,1,0,0,0,
  	294,31,1,0,0,0,295,296,5,17,0,0,296,297,5,62,0,0,297,298,3,62,31,0,298,
  	299,5,63,0,0,299,300,3,48,24,0,300,33,1,0,0,0,301,302,5,18,0,0,302,303,
  	3,48,24,0,303,304,5,17,0,0,304,305,5,62,0,0,305,306,3,62,31,0,306,307,
  	5,63,0,0,307,308,5,60,0,0,308,35,1,0,0,0,309,310,5,19,0,0,310,311,5,60,
  	0,0,311,37,1,0,0,0,312,313,5,20,0,0,313,314,5,60,0,0,314,39,1,0,0,0,315,
  	316,5,21,0,0,316,317,5,62,0,0,317,318,5,35,0,0,318,319,5,22,0,0,319,320,
  	3,42,21,0,320,321,5,63,0,0,321,322,3,48,24,0,322,41,1,0,0,0,323,326,3,
  	44,22,0,324,326,3,62,31,0,325,323,1,0,0,0,325,324,1,0,0,0,326,43,1,0,
  	0,0,327,328,5,37,0,0,328,329,5,62,0,0,329,336,3,62,31,0,330,331,5,58,
  	0,0,331,334,3,62,31,0,332,333,5,58,0,0,333,335,3,62,31,0,334,332,1,0,
  	0,0,334,335,1,0,0,0,335,337,1,0,0,0,336,330,1,0,0,0,336,337,1,0,0,0,337,
  	338,1,0,0,0,338,339,5,63,0,0,339,45,1,0,0,0,340,341,5,36,0,0,341,342,
  	5,62,0,0,342,343,3,62,31,0,343,344,5,63,0,0,344,347,1,0,0,0,345,347,3,
  	44,22,0,346,340,1,0,0,0,346,345,1,0,0,0,347,47,1,0,0,0,348,352,5,64,0,
  	0,349,351,3,30,15,0,350,349,1,0,0,0,351,354,1,0,0,0,352,350,1,0,0,0,352,
  	353,1,0,0,0,353,355,1,0,0,0,354,352,1,0,0,0,355,356,5,65,0,0,356,49,1,
  	0,0,0,357,358,5,35,0,0,358,359,5,38,0,0,359,360,5,7,0,0,360,361,5,34,
  	0,0,361,370,5,62,0,0,362,367,3,62,31,0,363,364,5,58,0,0,364,366,3,62,
  	31,0,365,363,1,0,0,0,366,369,1,0,0,0,367,365,1,0,0,0,367,368,1,0,0,0,
  	368,371,1,0,0,0,369,367,1,0,0,0,370,362,1,0,0,0,370,371,1,0,0,0,371,372,
  	1,0,0,0,372,373,5,63,0,0,373,387,5,60,0,0,374,375,5,35,0,0,375,376,3,
  	70,35,0,376,377,3,62,31,0,377,378,5,60,0,0,378,387,1,0,0,0,379,380,5,
  	6,0,0,380,381,5,59,0,0,381,382,5,35,0,0,382,383,3,70,35,0,383,384,3,62,
  	31,0,384,385,5,60,0,0,385,387,1,0,0,0,386,357,1,0,0,0,386,374,1,0,0,0,
  	386,379,1,0,0,0,387,51,1,0,0,0,388,389,3,56,28,0,389,390,5,38,0,0,390,
  	391,3,62,31,0,391,392,5,60,0,0,392,53,1,0,0,0,393,402,5,66,0,0,394,399,
  	3,62,31,0,395,396,5,58,0,0,396,398,3,62,31,0,397,395,1,0,0,0,398,401,
  	1,0,0,0,399,397,1,0,0,0,399,400,1,0,0,0,400,403,1,0,0,0,401,399,1,0,0,
  	0,402,394,1,0,0,0,402,403,1,0,0,0,403,404,1,0,0,0,404,405,5,67,0,0,405,
  	55,1,0,0,0,406,407,5,35,0,0,407,408,5,66,0,0,408,409,3,62,31,0,409,410,
  	5,67,0,0,410,417,1,0,0,0,411,412,5,33,0,0,412,413,5,66,0,0,413,414,3,
  	62,31,0,414,415,5,67,0,0,415,417,1,0,0,0,416,406,1,0,0,0,416,411,1,0,
  	0,0,417,57,1,0,0,0,418,419,5,14,0,0,419,420,5,62,0,0,420,421,3,62,31,
  	0,421,422,5,63,0,0,422,431,3,48,24,0,423,424,5,15,0,0,424,425,5,62,0,
  	0,425,426,3,62,31,0,426,427,5,63,0,0,427,428,3,48,24,0,428,430,1,0,0,
  	0,429,423,1,0,0,0,430,433,1,0,0,0,431,429,1,0,0,0,431,432,1,0,0,0,432,
  	436,1,0,0,0,433,431,1,0,0,0,434,435,5,16,0,0,435,437,3,48,24,0,436,434,
  	1,0,0,0,436,437,1,0,0,0,437,59,1,0,0,0,438,439,5,35,0,0,439,442,5,59,
  	0,0,440,443,3,82,41,0,441,443,5,35,0,0,442,440,1,0,0,0,442,441,1,0,0,
  	0,442,443,1,0,0,0,443,61,1,0,0,0,444,445,6,31,-1,0,445,448,3,72,36,0,
  	446,448,3,76,38,0,447,444,1,0,0,0,447,446,1,0,0,0,448,463,1,0,0,0,449,
  	450,10,5,0,0,450,451,3,64,32,0,451,452,3,76,38,0,452,462,1,0,0,0,453,
  	454,10,4,0,0,454,455,3,66,33,0,455,456,3,76,38,0,456,462,1,0,0,0,457,
  	458,10,3,0,0,458,459,3,68,34,0,459,460,3,76,38,0,460,462,1,0,0,0,461,
  	449,1,0,0,0,461,453,1,0,0,0,461,457,1,0,0,0,462,465,1,0,0,0,463,461,1,
  	0,0,0,463,464,1,0,0,0,464,63,1,0,0,0,465,463,1,0,0,0,466,467,7,1,0,0,
  	467,65,1,0,0,0,468,469,7,2,0,0,469,67,1,0,0,0,470,471,7,3,0,0,471,69,
  	1,0,0,0,472,473,7,4,0,0,473,71,1,0,0,0,474,475,5,57,0,0,475,476,3,62,
  	31,0,476,73,1,0,0,0,477,478,5,34,0,0,478,487,5,62,0,0,479,484,3,62,31,
  	0,480,481,5,58,0,0,481,483,3,62,31,0,482,480,1,0,0,0,483,486,1,0,0,0,
  	484,482,1,0,0,0,484,485,1,0,0,0,485,488,1,0,0,0,486,484,1,0,0,0,487,479,
  	1,0,0,0,487,488,1,0,0,0,488,489,1,0,0,0,489,490,5,63,0,0,490,75,1,0,0,
  	0,491,498,3,78,39,0,492,495,5,6,0,0,493,494,5,59,0,0,494,496,5,35,0,0,
  	495,493,1,0,0,0,495,496,1,0,0,0,496,498,1,0,0,0,497,491,1,0,0,0,497,492,
  	1,0,0,0,498,77,1,0,0,0,499,513,5,68,0,0,500,513,5,70,0,0,501,513,5,69,
  	0,0,502,513,5,71,0,0,503,513,5,35,0,0,504,513,3,56,28,0,505,513,3,82,
  	41,0,506,513,3,46,23,0,507,508,5,62,0,0,508,509,3,62,31,0,509,510,5,63,
  	0,0,510,513,1,0,0,0,511,513,3,74,37,0,512,499,1,0,0,0,512,500,1,0,0,0,
  	512,501,1,0,0,0,512,502,1,0,0,0,512,503,1,0,0,0,512,504,1,0,0,0,512,505,
  	1,0,0,0,512,506,1,0,0,0,512,507,1,0,0,0,512,511,1,0,0,0,513,79,1,0,0,
  	0,514,515,3,90,45,0,515,516,5,12,0,0,516,517,5,35,0,0,517,519,5,62,0,
  	0,518,520,3,84,42,0,519,518,1,0,0,0,519,520,1,0,0,0,520,521,1,0,0,0,521,
  	522,5,63,0,0,522,523,3,48,24,0,523,533,1,0,0,0,524,525,5,12,0,0,525,526,
  	5,35,0,0,526,528,5,62,0,0,527,529,3,84,42,0,528,527,1,0,0,0,528,529,1,
  	0,0,0,529,530,1,0,0,0,530,531,5,63,0,0,531,533,3,48,24,0,532,514,1,0,
  	0,0,532,524,1,0,0,0,533,81,1,0,0,0,534,535,5,35,0,0,535,544,5,62,0,0,
  	536,541,3,62,31,0,537,538,5,58,0,0,538,540,3,62,31,0,539,537,1,0,0,0,
  	540,543,1,0,0,0,541,539,1,0,0,0,541,542,1,0,0,0,542,545,1,0,0,0,543,541,
  	1,0,0,0,544,536,1,0,0,0,544,545,1,0,0,0,545,546,1,0,0,0,546,547,5,63,
  	0,0,547,83,1,0,0,0,548,553,3,86,43,0,549,550,5,58,0,0,550,552,3,86,43,
  	0,551,549,1,0,0,0,552,555,1,0,0,0,553,551,1,0,0,0,553,554,1,0,0,0,554,
  	85,1,0,0,0,555,553,1,0,0,0,556,557,3,90,45,0,557,558,5,35,0,0,558,87,
  	1,0,0,0,559,561,5,13,0,0,560,562,3,62,31,0,561,560,1,0,0,0,561,562,1,
  	0,0,0,562,563,1,0,0,0,563,564,5,60,0,0,564,89,1,0,0,0,565,566,7,5,0,0,
  	566,91,1,0,0,0,57,95,101,103,114,127,136,142,146,149,158,160,170,172,
  	180,187,189,201,204,221,230,234,242,251,253,268,271,276,293,325,334,336,
  	346,352,367,370,386,399,402,416,431,436,442,447,461,463,484,487,495,497,
  	512,519,528,532,541,544,553,561
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  fluxParserStaticData = std::move(staticData);
}

}

Flux::Flux(TokenStream *input) : Flux(input, antlr4::atn::ParserATNSimulatorOptions()) {}

Flux::Flux(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  Flux::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *fluxParserStaticData->atn, fluxParserStaticData->decisionToDFA, fluxParserStaticData->sharedContextCache, options);
}

Flux::~Flux() {
  delete _interpreter;
}

const atn::ATN& Flux::getATN() const {
  return *fluxParserStaticData->atn;
}

std::string Flux::getGrammarFileName() const {
  return "Flux.g4";
}

const std::vector<std::string>& Flux::getRuleNames() const {
  return fluxParserStaticData->ruleNames;
}

const dfa::Vocabulary& Flux::getVocabulary() const {
  return fluxParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView Flux::getSerializedATN() const {
  return fluxParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

Flux::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ProgramContext::EOF() {
  return getToken(Flux::EOF, 0);
}

std::vector<Flux::ImportDeclarationContext *> Flux::ProgramContext::importDeclaration() {
  return getRuleContexts<Flux::ImportDeclarationContext>();
}

Flux::ImportDeclarationContext* Flux::ProgramContext::importDeclaration(size_t i) {
  return getRuleContext<Flux::ImportDeclarationContext>(i);
}

std::vector<Flux::DeclarationContext *> Flux::ProgramContext::declaration() {
  return getRuleContexts<Flux::DeclarationContext>();
}

Flux::DeclarationContext* Flux::ProgramContext::declaration(size_t i) {
  return getRuleContext<Flux::DeclarationContext>(i);
}

std::vector<Flux::StatementContext *> Flux::ProgramContext::statement() {
  return getRuleContexts<Flux::StatementContext>();
}

Flux::StatementContext* Flux::ProgramContext::statement(size_t i) {
  return getRuleContext<Flux::StatementContext>(i);
}

std::vector<Flux::FuncCallContext *> Flux::ProgramContext::funcCall() {
  return getRuleContexts<Flux::FuncCallContext>();
}

Flux::FuncCallContext* Flux::ProgramContext::funcCall(size_t i) {
  return getRuleContext<Flux::FuncCallContext>(i);
}


size_t Flux::ProgramContext::getRuleIndex() const {
  return Flux::RuleProgram;
}

void Flux::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void Flux::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

Flux::ProgramContext* Flux::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, Flux::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(95);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(92);
        importDeclaration(); 
      }
      setState(97);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4755801480848373058) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 241) != 0)) {
      setState(101);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(98);
        declaration();
        break;
      }

      case 2: {
        setState(99);
        statement();
        break;
      }

      case 3: {
        setState(100);
        funcCall();
        break;
      }

      default:
        break;
      }
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(106);
    match(Flux::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

Flux::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Flux::ConstDeclarationContext* Flux::DeclarationContext::constDeclaration() {
  return getRuleContext<Flux::ConstDeclarationContext>(0);
}

Flux::VarDeclarationContext* Flux::DeclarationContext::varDeclaration() {
  return getRuleContext<Flux::VarDeclarationContext>(0);
}

Flux::FuncDeclarationContext* Flux::DeclarationContext::funcDeclaration() {
  return getRuleContext<Flux::FuncDeclarationContext>(0);
}

Flux::ClassDeclarationContext* Flux::DeclarationContext::classDeclaration() {
  return getRuleContext<Flux::ClassDeclarationContext>(0);
}

Flux::ImportDeclarationContext* Flux::DeclarationContext::importDeclaration() {
  return getRuleContext<Flux::ImportDeclarationContext>(0);
}

Flux::ExportDeclarationContext* Flux::DeclarationContext::exportDeclaration() {
  return getRuleContext<Flux::ExportDeclarationContext>(0);
}


size_t Flux::DeclarationContext::getRuleIndex() const {
  return Flux::RuleDeclaration;
}

void Flux::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void Flux::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}

Flux::DeclarationContext* Flux::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, Flux::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(114);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(108);
      constDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(109);
      varDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(110);
      funcDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(111);
      classDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(112);
      importDeclaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(113);
      exportDeclaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportDeclarationContext ------------------------------------------------------------------

Flux::ImportDeclarationContext::ImportDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ImportDeclarationContext::FROM() {
  return getToken(Flux::FROM, 0);
}

tree::TerminalNode* Flux::ImportDeclarationContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}

tree::TerminalNode* Flux::ImportDeclarationContext::IMPORT() {
  return getToken(Flux::IMPORT, 0);
}

Flux::ImportListContext* Flux::ImportDeclarationContext::importList() {
  return getRuleContext<Flux::ImportListContext>(0);
}

tree::TerminalNode* Flux::ImportDeclarationContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}


size_t Flux::ImportDeclarationContext::getRuleIndex() const {
  return Flux::RuleImportDeclaration;
}

void Flux::ImportDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportDeclaration(this);
}

void Flux::ImportDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportDeclaration(this);
}

Flux::ImportDeclarationContext* Flux::importDeclaration() {
  ImportDeclarationContext *_localctx = _tracker.createInstance<ImportDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, Flux::RuleImportDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    match(Flux::FROM);
    setState(117);
    match(Flux::IDENTIFIER);
    setState(118);
    match(Flux::IMPORT);
    setState(119);
    importList();
    setState(120);
    match(Flux::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportListContext ------------------------------------------------------------------

Flux::ImportListContext::ImportListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Flux::ImportItemContext *> Flux::ImportListContext::importItem() {
  return getRuleContexts<Flux::ImportItemContext>();
}

Flux::ImportItemContext* Flux::ImportListContext::importItem(size_t i) {
  return getRuleContext<Flux::ImportItemContext>(i);
}

std::vector<tree::TerminalNode *> Flux::ImportListContext::COMMA() {
  return getTokens(Flux::COMMA);
}

tree::TerminalNode* Flux::ImportListContext::COMMA(size_t i) {
  return getToken(Flux::COMMA, i);
}


size_t Flux::ImportListContext::getRuleIndex() const {
  return Flux::RuleImportList;
}

void Flux::ImportListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportList(this);
}

void Flux::ImportListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportList(this);
}

Flux::ImportListContext* Flux::importList() {
  ImportListContext *_localctx = _tracker.createInstance<ImportListContext>(_ctx, getState());
  enterRule(_localctx, 6, Flux::RuleImportList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    importItem();
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Flux::COMMA) {
      setState(123);
      match(Flux::COMMA);
      setState(124);
      importItem();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportItemContext ------------------------------------------------------------------

Flux::ImportItemContext::ImportItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ImportItemContext::UPPERCASE_IDENTIFIER() {
  return getToken(Flux::UPPERCASE_IDENTIFIER, 0);
}

tree::TerminalNode* Flux::ImportItemContext::CLASS_IDENTIFIER() {
  return getToken(Flux::CLASS_IDENTIFIER, 0);
}

tree::TerminalNode* Flux::ImportItemContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}


size_t Flux::ImportItemContext::getRuleIndex() const {
  return Flux::RuleImportItem;
}

void Flux::ImportItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportItem(this);
}

void Flux::ImportItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportItem(this);
}

Flux::ImportItemContext* Flux::importItem() {
  ImportItemContext *_localctx = _tracker.createInstance<ImportItemContext>(_ctx, getState());
  enterRule(_localctx, 8, Flux::RuleImportItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 60129542144) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExportDeclarationContext ------------------------------------------------------------------

Flux::ExportDeclarationContext::ExportDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ExportDeclarationContext::EXPORT() {
  return getToken(Flux::EXPORT, 0);
}

Flux::ClassDeclarationContext* Flux::ExportDeclarationContext::classDeclaration() {
  return getRuleContext<Flux::ClassDeclarationContext>(0);
}

Flux::FuncDeclarationContext* Flux::ExportDeclarationContext::funcDeclaration() {
  return getRuleContext<Flux::FuncDeclarationContext>(0);
}

Flux::ConstDeclarationContext* Flux::ExportDeclarationContext::constDeclaration() {
  return getRuleContext<Flux::ConstDeclarationContext>(0);
}


size_t Flux::ExportDeclarationContext::getRuleIndex() const {
  return Flux::RuleExportDeclaration;
}

void Flux::ExportDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExportDeclaration(this);
}

void Flux::ExportDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExportDeclaration(this);
}

Flux::ExportDeclarationContext* Flux::exportDeclaration() {
  ExportDeclarationContext *_localctx = _tracker.createInstance<ExportDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, Flux::RuleExportDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(Flux::EXPORT);
    setState(136);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Flux::CLASS: {
        setState(133);
        classDeclaration();
        break;
      }

      case Flux::FUNC:
      case Flux::NUMBER_VAR:
      case Flux::STRING_VAR:
      case Flux::BOOLEAN_VAR:
      case Flux::CLASS_IDENTIFIER: {
        setState(134);
        funcDeclaration();
        break;
      }

      case Flux::CONST: {
        setState(135);
        constDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDeclarationContext ------------------------------------------------------------------

Flux::ClassDeclarationContext::ClassDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ClassDeclarationContext::CLASS() {
  return getToken(Flux::CLASS, 0);
}

std::vector<tree::TerminalNode *> Flux::ClassDeclarationContext::CLASS_IDENTIFIER() {
  return getTokens(Flux::CLASS_IDENTIFIER);
}

tree::TerminalNode* Flux::ClassDeclarationContext::CLASS_IDENTIFIER(size_t i) {
  return getToken(Flux::CLASS_IDENTIFIER, i);
}

tree::TerminalNode* Flux::ClassDeclarationContext::LBRACE() {
  return getToken(Flux::LBRACE, 0);
}

tree::TerminalNode* Flux::ClassDeclarationContext::RBRACE() {
  return getToken(Flux::RBRACE, 0);
}

tree::TerminalNode* Flux::ClassDeclarationContext::EXTENDS() {
  return getToken(Flux::EXTENDS, 0);
}

Flux::PublicBlockContext* Flux::ClassDeclarationContext::publicBlock() {
  return getRuleContext<Flux::PublicBlockContext>(0);
}

Flux::PrivateBlockContext* Flux::ClassDeclarationContext::privateBlock() {
  return getRuleContext<Flux::PrivateBlockContext>(0);
}


size_t Flux::ClassDeclarationContext::getRuleIndex() const {
  return Flux::RuleClassDeclaration;
}

void Flux::ClassDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDeclaration(this);
}

void Flux::ClassDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDeclaration(this);
}

Flux::ClassDeclarationContext* Flux::classDeclaration() {
  ClassDeclarationContext *_localctx = _tracker.createInstance<ClassDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, Flux::RuleClassDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(Flux::CLASS);
    setState(139);
    match(Flux::CLASS_IDENTIFIER);
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Flux::EXTENDS) {
      setState(140);
      match(Flux::EXTENDS);
      setState(141);
      match(Flux::CLASS_IDENTIFIER);
    }
    setState(144);
    match(Flux::LBRACE);
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Flux::PUBLIC) {
      setState(145);
      publicBlock();
    }
    setState(149);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Flux::PRIVATE) {
      setState(148);
      privateBlock();
    }
    setState(151);
    match(Flux::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PublicBlockContext ------------------------------------------------------------------

Flux::PublicBlockContext::PublicBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::PublicBlockContext::PUBLIC() {
  return getToken(Flux::PUBLIC, 0);
}

tree::TerminalNode* Flux::PublicBlockContext::LBRACE() {
  return getToken(Flux::LBRACE, 0);
}

tree::TerminalNode* Flux::PublicBlockContext::RBRACE() {
  return getToken(Flux::RBRACE, 0);
}

std::vector<Flux::VarDeclarationContext *> Flux::PublicBlockContext::varDeclaration() {
  return getRuleContexts<Flux::VarDeclarationContext>();
}

Flux::VarDeclarationContext* Flux::PublicBlockContext::varDeclaration(size_t i) {
  return getRuleContext<Flux::VarDeclarationContext>(i);
}

std::vector<Flux::ConstructorDeclarationContext *> Flux::PublicBlockContext::constructorDeclaration() {
  return getRuleContexts<Flux::ConstructorDeclarationContext>();
}

Flux::ConstructorDeclarationContext* Flux::PublicBlockContext::constructorDeclaration(size_t i) {
  return getRuleContext<Flux::ConstructorDeclarationContext>(i);
}

std::vector<Flux::MethodDeclarationContext *> Flux::PublicBlockContext::methodDeclaration() {
  return getRuleContexts<Flux::MethodDeclarationContext>();
}

Flux::MethodDeclarationContext* Flux::PublicBlockContext::methodDeclaration(size_t i) {
  return getRuleContext<Flux::MethodDeclarationContext>(i);
}


size_t Flux::PublicBlockContext::getRuleIndex() const {
  return Flux::RulePublicBlock;
}

void Flux::PublicBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPublicBlock(this);
}

void Flux::PublicBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPublicBlock(this);
}

Flux::PublicBlockContext* Flux::publicBlock() {
  PublicBlockContext *_localctx = _tracker.createInstance<PublicBlockContext>(_ctx, getState());
  enterRule(_localctx, 14, Flux::RulePublicBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(Flux::PUBLIC);
    setState(154);
    match(Flux::LBRACE);
    setState(160);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 24696066048) != 0)) {
      setState(158);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(155);
        varDeclaration();
        break;
      }

      case 2: {
        setState(156);
        constructorDeclaration();
        break;
      }

      case 3: {
        setState(157);
        methodDeclaration();
        break;
      }

      default:
        break;
      }
      setState(162);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(163);
    match(Flux::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrivateBlockContext ------------------------------------------------------------------

Flux::PrivateBlockContext::PrivateBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::PrivateBlockContext::PRIVATE() {
  return getToken(Flux::PRIVATE, 0);
}

tree::TerminalNode* Flux::PrivateBlockContext::LBRACE() {
  return getToken(Flux::LBRACE, 0);
}

tree::TerminalNode* Flux::PrivateBlockContext::RBRACE() {
  return getToken(Flux::RBRACE, 0);
}

std::vector<Flux::VarDeclarationContext *> Flux::PrivateBlockContext::varDeclaration() {
  return getRuleContexts<Flux::VarDeclarationContext>();
}

Flux::VarDeclarationContext* Flux::PrivateBlockContext::varDeclaration(size_t i) {
  return getRuleContext<Flux::VarDeclarationContext>(i);
}

std::vector<Flux::ConstructorDeclarationContext *> Flux::PrivateBlockContext::constructorDeclaration() {
  return getRuleContexts<Flux::ConstructorDeclarationContext>();
}

Flux::ConstructorDeclarationContext* Flux::PrivateBlockContext::constructorDeclaration(size_t i) {
  return getRuleContext<Flux::ConstructorDeclarationContext>(i);
}

std::vector<Flux::MethodDeclarationContext *> Flux::PrivateBlockContext::methodDeclaration() {
  return getRuleContexts<Flux::MethodDeclarationContext>();
}

Flux::MethodDeclarationContext* Flux::PrivateBlockContext::methodDeclaration(size_t i) {
  return getRuleContext<Flux::MethodDeclarationContext>(i);
}


size_t Flux::PrivateBlockContext::getRuleIndex() const {
  return Flux::RulePrivateBlock;
}

void Flux::PrivateBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrivateBlock(this);
}

void Flux::PrivateBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrivateBlock(this);
}

Flux::PrivateBlockContext* Flux::privateBlock() {
  PrivateBlockContext *_localctx = _tracker.createInstance<PrivateBlockContext>(_ctx, getState());
  enterRule(_localctx, 16, Flux::RulePrivateBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(Flux::PRIVATE);
    setState(166);
    match(Flux::LBRACE);
    setState(172);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 24696066048) != 0)) {
      setState(170);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
      case 1: {
        setState(167);
        varDeclaration();
        break;
      }

      case 2: {
        setState(168);
        constructorDeclaration();
        break;
      }

      case 3: {
        setState(169);
        methodDeclaration();
        break;
      }

      default:
        break;
      }
      setState(174);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(175);
    match(Flux::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstructorDeclarationContext ------------------------------------------------------------------

Flux::ConstructorDeclarationContext::ConstructorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ConstructorDeclarationContext::CLASS_IDENTIFIER() {
  return getToken(Flux::CLASS_IDENTIFIER, 0);
}

tree::TerminalNode* Flux::ConstructorDeclarationContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

tree::TerminalNode* Flux::ConstructorDeclarationContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

tree::TerminalNode* Flux::ConstructorDeclarationContext::LBRACE() {
  return getToken(Flux::LBRACE, 0);
}

tree::TerminalNode* Flux::ConstructorDeclarationContext::RBRACE() {
  return getToken(Flux::RBRACE, 0);
}

Flux::ParamListContext* Flux::ConstructorDeclarationContext::paramList() {
  return getRuleContext<Flux::ParamListContext>(0);
}

std::vector<Flux::ConstructorInitStatementContext *> Flux::ConstructorDeclarationContext::constructorInitStatement() {
  return getRuleContexts<Flux::ConstructorInitStatementContext>();
}

Flux::ConstructorInitStatementContext* Flux::ConstructorDeclarationContext::constructorInitStatement(size_t i) {
  return getRuleContext<Flux::ConstructorInitStatementContext>(i);
}

std::vector<Flux::AssignmentStatementContext *> Flux::ConstructorDeclarationContext::assignmentStatement() {
  return getRuleContexts<Flux::AssignmentStatementContext>();
}

Flux::AssignmentStatementContext* Flux::ConstructorDeclarationContext::assignmentStatement(size_t i) {
  return getRuleContext<Flux::AssignmentStatementContext>(i);
}

std::vector<Flux::SuperCallContext *> Flux::ConstructorDeclarationContext::superCall() {
  return getRuleContexts<Flux::SuperCallContext>();
}

Flux::SuperCallContext* Flux::ConstructorDeclarationContext::superCall(size_t i) {
  return getRuleContext<Flux::SuperCallContext>(i);
}


size_t Flux::ConstructorDeclarationContext::getRuleIndex() const {
  return Flux::RuleConstructorDeclaration;
}

void Flux::ConstructorDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructorDeclaration(this);
}

void Flux::ConstructorDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructorDeclaration(this);
}

Flux::ConstructorDeclarationContext* Flux::constructorDeclaration() {
  ConstructorDeclarationContext *_localctx = _tracker.createInstance<ConstructorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 18, Flux::RuleConstructorDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(Flux::CLASS_IDENTIFIER);
    setState(178);
    match(Flux::LPAREN);
    setState(180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 24696061952) != 0)) {
      setState(179);
      paramList();
    }
    setState(182);
    match(Flux::RPAREN);
    setState(183);
    match(Flux::LBRACE);
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34359738464) != 0)) {
      setState(187);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
      case 1: {
        setState(184);
        constructorInitStatement();
        break;
      }

      case 2: {
        setState(185);
        assignmentStatement();
        break;
      }

      case 3: {
        setState(186);
        superCall();
        break;
      }

      default:
        break;
      }
      setState(191);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(192);
    match(Flux::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuperCallContext ------------------------------------------------------------------

Flux::SuperCallContext::SuperCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::SuperCallContext::SUPER() {
  return getToken(Flux::SUPER, 0);
}

tree::TerminalNode* Flux::SuperCallContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

tree::TerminalNode* Flux::SuperCallContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

tree::TerminalNode* Flux::SuperCallContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}

std::vector<Flux::ExprContext *> Flux::SuperCallContext::expr() {
  return getRuleContexts<Flux::ExprContext>();
}

Flux::ExprContext* Flux::SuperCallContext::expr(size_t i) {
  return getRuleContext<Flux::ExprContext>(i);
}

std::vector<tree::TerminalNode *> Flux::SuperCallContext::COMMA() {
  return getTokens(Flux::COMMA);
}

tree::TerminalNode* Flux::SuperCallContext::COMMA(size_t i) {
  return getToken(Flux::COMMA, i);
}


size_t Flux::SuperCallContext::getRuleIndex() const {
  return Flux::RuleSuperCall;
}

void Flux::SuperCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuperCall(this);
}

void Flux::SuperCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuperCall(this);
}

Flux::SuperCallContext* Flux::superCall() {
  SuperCallContext *_localctx = _tracker.createInstance<SuperCallContext>(_ctx, getState());
  enterRule(_localctx, 20, Flux::RuleSuperCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(Flux::SUPER);
    setState(195);
    match(Flux::LPAREN);
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4755801472791216192) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 15) != 0)) {
      setState(196);
      expr(0);
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Flux::COMMA) {
        setState(197);
        match(Flux::COMMA);
        setState(198);
        expr(0);
        setState(203);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(206);
    match(Flux::RPAREN);
    setState(207);
    match(Flux::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstructorInitStatementContext ------------------------------------------------------------------

Flux::ConstructorInitStatementContext::ConstructorInitStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ConstructorInitStatementContext::THIS() {
  return getToken(Flux::THIS, 0);
}

tree::TerminalNode* Flux::ConstructorInitStatementContext::DOT() {
  return getToken(Flux::DOT, 0);
}

tree::TerminalNode* Flux::ConstructorInitStatementContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}

tree::TerminalNode* Flux::ConstructorInitStatementContext::ASSIGN() {
  return getToken(Flux::ASSIGN, 0);
}

Flux::ExprContext* Flux::ConstructorInitStatementContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}

tree::TerminalNode* Flux::ConstructorInitStatementContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}


size_t Flux::ConstructorInitStatementContext::getRuleIndex() const {
  return Flux::RuleConstructorInitStatement;
}

void Flux::ConstructorInitStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructorInitStatement(this);
}

void Flux::ConstructorInitStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructorInitStatement(this);
}

Flux::ConstructorInitStatementContext* Flux::constructorInitStatement() {
  ConstructorInitStatementContext *_localctx = _tracker.createInstance<ConstructorInitStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, Flux::RuleConstructorInitStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(Flux::THIS);
    setState(210);
    match(Flux::DOT);
    setState(211);
    match(Flux::IDENTIFIER);
    setState(212);
    match(Flux::ASSIGN);
    setState(213);
    expr(0);
    setState(214);
    match(Flux::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclarationContext ------------------------------------------------------------------

Flux::MethodDeclarationContext::MethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Flux::TypeContext* Flux::MethodDeclarationContext::type() {
  return getRuleContext<Flux::TypeContext>(0);
}

tree::TerminalNode* Flux::MethodDeclarationContext::FUNC() {
  return getToken(Flux::FUNC, 0);
}

tree::TerminalNode* Flux::MethodDeclarationContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}

tree::TerminalNode* Flux::MethodDeclarationContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

tree::TerminalNode* Flux::MethodDeclarationContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

Flux::BlockContext* Flux::MethodDeclarationContext::block() {
  return getRuleContext<Flux::BlockContext>(0);
}

Flux::ParamListContext* Flux::MethodDeclarationContext::paramList() {
  return getRuleContext<Flux::ParamListContext>(0);
}


size_t Flux::MethodDeclarationContext::getRuleIndex() const {
  return Flux::RuleMethodDeclaration;
}

void Flux::MethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDeclaration(this);
}

void Flux::MethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDeclaration(this);
}

Flux::MethodDeclarationContext* Flux::methodDeclaration() {
  MethodDeclarationContext *_localctx = _tracker.createInstance<MethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 24, Flux::RuleMethodDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(234);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Flux::NUMBER_VAR:
      case Flux::STRING_VAR:
      case Flux::BOOLEAN_VAR:
      case Flux::CLASS_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(216);
        type();
        setState(217);
        match(Flux::FUNC);
        setState(218);
        match(Flux::IDENTIFIER);
        setState(219);
        match(Flux::LPAREN);
        setState(221);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 24696061952) != 0)) {
          setState(220);
          paramList();
        }
        setState(223);
        match(Flux::RPAREN);
        setState(224);
        block();
        break;
      }

      case Flux::FUNC: {
        enterOuterAlt(_localctx, 2);
        setState(226);
        match(Flux::FUNC);
        setState(227);
        match(Flux::IDENTIFIER);
        setState(228);
        match(Flux::LPAREN);
        setState(230);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 24696061952) != 0)) {
          setState(229);
          paramList();
        }
        setState(232);
        match(Flux::RPAREN);
        setState(233);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclarationContext ------------------------------------------------------------------

Flux::ConstDeclarationContext::ConstDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ConstDeclarationContext::CONST() {
  return getToken(Flux::CONST, 0);
}

Flux::TypeContext* Flux::ConstDeclarationContext::type() {
  return getRuleContext<Flux::TypeContext>(0);
}

tree::TerminalNode* Flux::ConstDeclarationContext::UPPERCASE_IDENTIFIER() {
  return getToken(Flux::UPPERCASE_IDENTIFIER, 0);
}

tree::TerminalNode* Flux::ConstDeclarationContext::ASSIGN() {
  return getToken(Flux::ASSIGN, 0);
}

tree::TerminalNode* Flux::ConstDeclarationContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}

Flux::ExprContext* Flux::ConstDeclarationContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}

Flux::ArrayLiteralContext* Flux::ConstDeclarationContext::arrayLiteral() {
  return getRuleContext<Flux::ArrayLiteralContext>(0);
}


size_t Flux::ConstDeclarationContext::getRuleIndex() const {
  return Flux::RuleConstDeclaration;
}

void Flux::ConstDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDeclaration(this);
}

void Flux::ConstDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDeclaration(this);
}

Flux::ConstDeclarationContext* Flux::constDeclaration() {
  ConstDeclarationContext *_localctx = _tracker.createInstance<ConstDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 26, Flux::RuleConstDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    match(Flux::CONST);
    setState(237);
    type();
    setState(238);
    match(Flux::UPPERCASE_IDENTIFIER);
    setState(239);
    match(Flux::ASSIGN);
    setState(242);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Flux::THIS:
      case Flux::UPPERCASE_IDENTIFIER:
      case Flux::CLASS_IDENTIFIER:
      case Flux::IDENTIFIER:
      case Flux::PRINT_FUNC:
      case Flux::RANGE_FUNC:
      case Flux::NOT:
      case Flux::LPAREN:
      case Flux::BOOL_LIT:
      case Flux::INT_LIT:
      case Flux::DECIMAL_LIT:
      case Flux::STRING_LIT: {
        setState(240);
        expr(0);
        break;
      }

      case Flux::LBRACK: {
        setState(241);
        arrayLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(244);
    match(Flux::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationContext ------------------------------------------------------------------

Flux::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Flux::TypeContext* Flux::VarDeclarationContext::type() {
  return getRuleContext<Flux::TypeContext>(0);
}

tree::TerminalNode* Flux::VarDeclarationContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}

tree::TerminalNode* Flux::VarDeclarationContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}

tree::TerminalNode* Flux::VarDeclarationContext::ASSIGN() {
  return getToken(Flux::ASSIGN, 0);
}

std::vector<Flux::ExprContext *> Flux::VarDeclarationContext::expr() {
  return getRuleContexts<Flux::ExprContext>();
}

Flux::ExprContext* Flux::VarDeclarationContext::expr(size_t i) {
  return getRuleContext<Flux::ExprContext>(i);
}

Flux::ArrayLiteralContext* Flux::VarDeclarationContext::arrayLiteral() {
  return getRuleContext<Flux::ArrayLiteralContext>(0);
}

tree::TerminalNode* Flux::VarDeclarationContext::NEW() {
  return getToken(Flux::NEW, 0);
}

tree::TerminalNode* Flux::VarDeclarationContext::CLASS_IDENTIFIER() {
  return getToken(Flux::CLASS_IDENTIFIER, 0);
}

tree::TerminalNode* Flux::VarDeclarationContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

tree::TerminalNode* Flux::VarDeclarationContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

std::vector<tree::TerminalNode *> Flux::VarDeclarationContext::COMMA() {
  return getTokens(Flux::COMMA);
}

tree::TerminalNode* Flux::VarDeclarationContext::COMMA(size_t i) {
  return getToken(Flux::COMMA, i);
}


size_t Flux::VarDeclarationContext::getRuleIndex() const {
  return Flux::RuleVarDeclaration;
}

void Flux::VarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclaration(this);
}

void Flux::VarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclaration(this);
}

Flux::VarDeclarationContext* Flux::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 28, Flux::RuleVarDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(276);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(246);
      type();
      setState(247);
      match(Flux::IDENTIFIER);
      setState(253);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == Flux::ASSIGN) {
        setState(248);
        match(Flux::ASSIGN);
        setState(251);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case Flux::THIS:
          case Flux::UPPERCASE_IDENTIFIER:
          case Flux::CLASS_IDENTIFIER:
          case Flux::IDENTIFIER:
          case Flux::PRINT_FUNC:
          case Flux::RANGE_FUNC:
          case Flux::NOT:
          case Flux::LPAREN:
          case Flux::BOOL_LIT:
          case Flux::INT_LIT:
          case Flux::DECIMAL_LIT:
          case Flux::STRING_LIT: {
            setState(249);
            expr(0);
            break;
          }

          case Flux::LBRACK: {
            setState(250);
            arrayLiteral();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
      }
      setState(255);
      match(Flux::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(257);
      type();
      setState(258);
      match(Flux::IDENTIFIER);
      setState(259);
      match(Flux::ASSIGN);
      setState(260);
      match(Flux::NEW);
      setState(261);
      match(Flux::CLASS_IDENTIFIER);
      setState(262);
      match(Flux::LPAREN);
      setState(271);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4755801472791216192) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 15) != 0)) {
        setState(263);
        expr(0);
        setState(268);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == Flux::COMMA) {
          setState(264);
          match(Flux::COMMA);
          setState(265);
          expr(0);
          setState(270);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(273);
      match(Flux::RPAREN);
      setState(274);
      match(Flux::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

Flux::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Flux::DeclarationContext* Flux::StatementContext::declaration() {
  return getRuleContext<Flux::DeclarationContext>(0);
}

Flux::AssignmentStatementContext* Flux::StatementContext::assignmentStatement() {
  return getRuleContext<Flux::AssignmentStatementContext>(0);
}

Flux::ArrayAssignmentStatementContext* Flux::StatementContext::arrayAssignmentStatement() {
  return getRuleContext<Flux::ArrayAssignmentStatementContext>(0);
}

Flux::ValueAccessContext* Flux::StatementContext::valueAccess() {
  return getRuleContext<Flux::ValueAccessContext>(0);
}

Flux::IfStatementContext* Flux::StatementContext::ifStatement() {
  return getRuleContext<Flux::IfStatementContext>(0);
}

Flux::ForStatementContext* Flux::StatementContext::forStatement() {
  return getRuleContext<Flux::ForStatementContext>(0);
}

Flux::WhileStatementContext* Flux::StatementContext::whileStatement() {
  return getRuleContext<Flux::WhileStatementContext>(0);
}

Flux::DoWhileStatementContext* Flux::StatementContext::doWhileStatement() {
  return getRuleContext<Flux::DoWhileStatementContext>(0);
}

Flux::BreakStatementContext* Flux::StatementContext::breakStatement() {
  return getRuleContext<Flux::BreakStatementContext>(0);
}

Flux::ContinueStatementContext* Flux::StatementContext::continueStatement() {
  return getRuleContext<Flux::ContinueStatementContext>(0);
}

Flux::ReturnStmtContext* Flux::StatementContext::returnStmt() {
  return getRuleContext<Flux::ReturnStmtContext>(0);
}

Flux::BlockContext* Flux::StatementContext::block() {
  return getRuleContext<Flux::BlockContext>(0);
}

Flux::ExprContext* Flux::StatementContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}

tree::TerminalNode* Flux::StatementContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}


size_t Flux::StatementContext::getRuleIndex() const {
  return Flux::RuleStatement;
}

void Flux::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void Flux::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

Flux::StatementContext* Flux::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 30, Flux::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(293);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(278);
      declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(279);
      assignmentStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(280);
      arrayAssignmentStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(281);
      valueAccess();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(282);
      ifStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(283);
      forStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(284);
      whileStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(285);
      doWhileStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(286);
      breakStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(287);
      continueStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(288);
      returnStmt();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(289);
      block();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(290);
      expr(0);
      setState(291);
      match(Flux::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

Flux::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::WhileStatementContext::WHILE() {
  return getToken(Flux::WHILE, 0);
}

tree::TerminalNode* Flux::WhileStatementContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

Flux::ExprContext* Flux::WhileStatementContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}

tree::TerminalNode* Flux::WhileStatementContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

Flux::BlockContext* Flux::WhileStatementContext::block() {
  return getRuleContext<Flux::BlockContext>(0);
}


size_t Flux::WhileStatementContext::getRuleIndex() const {
  return Flux::RuleWhileStatement;
}

void Flux::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}

void Flux::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}

Flux::WhileStatementContext* Flux::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, Flux::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    match(Flux::WHILE);
    setState(296);
    match(Flux::LPAREN);
    setState(297);
    expr(0);
    setState(298);
    match(Flux::RPAREN);
    setState(299);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoWhileStatementContext ------------------------------------------------------------------

Flux::DoWhileStatementContext::DoWhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::DoWhileStatementContext::DO() {
  return getToken(Flux::DO, 0);
}

Flux::BlockContext* Flux::DoWhileStatementContext::block() {
  return getRuleContext<Flux::BlockContext>(0);
}

tree::TerminalNode* Flux::DoWhileStatementContext::WHILE() {
  return getToken(Flux::WHILE, 0);
}

tree::TerminalNode* Flux::DoWhileStatementContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

Flux::ExprContext* Flux::DoWhileStatementContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}

tree::TerminalNode* Flux::DoWhileStatementContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

tree::TerminalNode* Flux::DoWhileStatementContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}


size_t Flux::DoWhileStatementContext::getRuleIndex() const {
  return Flux::RuleDoWhileStatement;
}

void Flux::DoWhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoWhileStatement(this);
}

void Flux::DoWhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoWhileStatement(this);
}

Flux::DoWhileStatementContext* Flux::doWhileStatement() {
  DoWhileStatementContext *_localctx = _tracker.createInstance<DoWhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, Flux::RuleDoWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    match(Flux::DO);
    setState(302);
    block();
    setState(303);
    match(Flux::WHILE);
    setState(304);
    match(Flux::LPAREN);
    setState(305);
    expr(0);
    setState(306);
    match(Flux::RPAREN);
    setState(307);
    match(Flux::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

Flux::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::BreakStatementContext::BREAK() {
  return getToken(Flux::BREAK, 0);
}

tree::TerminalNode* Flux::BreakStatementContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}


size_t Flux::BreakStatementContext::getRuleIndex() const {
  return Flux::RuleBreakStatement;
}

void Flux::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void Flux::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

Flux::BreakStatementContext* Flux::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, Flux::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    match(Flux::BREAK);
    setState(310);
    match(Flux::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

Flux::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ContinueStatementContext::CONTINUE() {
  return getToken(Flux::CONTINUE, 0);
}

tree::TerminalNode* Flux::ContinueStatementContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}


size_t Flux::ContinueStatementContext::getRuleIndex() const {
  return Flux::RuleContinueStatement;
}

void Flux::ContinueStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStatement(this);
}

void Flux::ContinueStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStatement(this);
}

Flux::ContinueStatementContext* Flux::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, Flux::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(Flux::CONTINUE);
    setState(313);
    match(Flux::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

Flux::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ForStatementContext::FOR() {
  return getToken(Flux::FOR, 0);
}

tree::TerminalNode* Flux::ForStatementContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

tree::TerminalNode* Flux::ForStatementContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}

tree::TerminalNode* Flux::ForStatementContext::IN() {
  return getToken(Flux::IN, 0);
}

Flux::ForRangeContext* Flux::ForStatementContext::forRange() {
  return getRuleContext<Flux::ForRangeContext>(0);
}

tree::TerminalNode* Flux::ForStatementContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

Flux::BlockContext* Flux::ForStatementContext::block() {
  return getRuleContext<Flux::BlockContext>(0);
}


size_t Flux::ForStatementContext::getRuleIndex() const {
  return Flux::RuleForStatement;
}

void Flux::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void Flux::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}

Flux::ForStatementContext* Flux::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 40, Flux::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    match(Flux::FOR);
    setState(316);
    match(Flux::LPAREN);
    setState(317);
    match(Flux::IDENTIFIER);
    setState(318);
    match(Flux::IN);
    setState(319);
    forRange();
    setState(320);
    match(Flux::RPAREN);
    setState(321);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForRangeContext ------------------------------------------------------------------

Flux::ForRangeContext::ForRangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Flux::RangeExprContext* Flux::ForRangeContext::rangeExpr() {
  return getRuleContext<Flux::RangeExprContext>(0);
}

Flux::ExprContext* Flux::ForRangeContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}


size_t Flux::ForRangeContext::getRuleIndex() const {
  return Flux::RuleForRange;
}

void Flux::ForRangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForRange(this);
}

void Flux::ForRangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForRange(this);
}

Flux::ForRangeContext* Flux::forRange() {
  ForRangeContext *_localctx = _tracker.createInstance<ForRangeContext>(_ctx, getState());
  enterRule(_localctx, 42, Flux::RuleForRange);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(323);
      rangeExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(324);
      expr(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeExprContext ------------------------------------------------------------------

Flux::RangeExprContext::RangeExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::RangeExprContext::RANGE_FUNC() {
  return getToken(Flux::RANGE_FUNC, 0);
}

tree::TerminalNode* Flux::RangeExprContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

std::vector<Flux::ExprContext *> Flux::RangeExprContext::expr() {
  return getRuleContexts<Flux::ExprContext>();
}

Flux::ExprContext* Flux::RangeExprContext::expr(size_t i) {
  return getRuleContext<Flux::ExprContext>(i);
}

tree::TerminalNode* Flux::RangeExprContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

std::vector<tree::TerminalNode *> Flux::RangeExprContext::COMMA() {
  return getTokens(Flux::COMMA);
}

tree::TerminalNode* Flux::RangeExprContext::COMMA(size_t i) {
  return getToken(Flux::COMMA, i);
}


size_t Flux::RangeExprContext::getRuleIndex() const {
  return Flux::RuleRangeExpr;
}

void Flux::RangeExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRangeExpr(this);
}

void Flux::RangeExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRangeExpr(this);
}

Flux::RangeExprContext* Flux::rangeExpr() {
  RangeExprContext *_localctx = _tracker.createInstance<RangeExprContext>(_ctx, getState());
  enterRule(_localctx, 44, Flux::RuleRangeExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    match(Flux::RANGE_FUNC);
    setState(328);
    match(Flux::LPAREN);
    setState(329);
    expr(0);
    setState(336);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Flux::COMMA) {
      setState(330);
      match(Flux::COMMA);
      setState(331);
      expr(0);
      setState(334);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == Flux::COMMA) {
        setState(332);
        match(Flux::COMMA);
        setState(333);
        expr(0);
      }
    }
    setState(338);
    match(Flux::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BuiltInCallContext ------------------------------------------------------------------

Flux::BuiltInCallContext::BuiltInCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::BuiltInCallContext::PRINT_FUNC() {
  return getToken(Flux::PRINT_FUNC, 0);
}

tree::TerminalNode* Flux::BuiltInCallContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

Flux::ExprContext* Flux::BuiltInCallContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}

tree::TerminalNode* Flux::BuiltInCallContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

Flux::RangeExprContext* Flux::BuiltInCallContext::rangeExpr() {
  return getRuleContext<Flux::RangeExprContext>(0);
}


size_t Flux::BuiltInCallContext::getRuleIndex() const {
  return Flux::RuleBuiltInCall;
}

void Flux::BuiltInCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBuiltInCall(this);
}

void Flux::BuiltInCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBuiltInCall(this);
}

Flux::BuiltInCallContext* Flux::builtInCall() {
  BuiltInCallContext *_localctx = _tracker.createInstance<BuiltInCallContext>(_ctx, getState());
  enterRule(_localctx, 46, Flux::RuleBuiltInCall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(346);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Flux::PRINT_FUNC: {
        enterOuterAlt(_localctx, 1);
        setState(340);
        match(Flux::PRINT_FUNC);
        setState(341);
        match(Flux::LPAREN);
        setState(342);
        expr(0);
        setState(343);
        match(Flux::RPAREN);
        break;
      }

      case Flux::RANGE_FUNC: {
        enterOuterAlt(_localctx, 2);
        setState(345);
        rangeExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

Flux::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::BlockContext::LBRACE() {
  return getToken(Flux::LBRACE, 0);
}

tree::TerminalNode* Flux::BlockContext::RBRACE() {
  return getToken(Flux::RBRACE, 0);
}

std::vector<Flux::StatementContext *> Flux::BlockContext::statement() {
  return getRuleContexts<Flux::StatementContext>();
}

Flux::StatementContext* Flux::BlockContext::statement(size_t i) {
  return getRuleContext<Flux::StatementContext>(i);
}


size_t Flux::BlockContext::getRuleIndex() const {
  return Flux::RuleBlock;
}

void Flux::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void Flux::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

Flux::BlockContext* Flux::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 48, Flux::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    match(Flux::LBRACE);
    setState(352);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4755801480848373058) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 241) != 0)) {
      setState(349);
      statement();
      setState(354);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(355);
    match(Flux::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

Flux::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::AssignmentStatementContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}

tree::TerminalNode* Flux::AssignmentStatementContext::ASSIGN() {
  return getToken(Flux::ASSIGN, 0);
}

tree::TerminalNode* Flux::AssignmentStatementContext::NEW() {
  return getToken(Flux::NEW, 0);
}

tree::TerminalNode* Flux::AssignmentStatementContext::CLASS_IDENTIFIER() {
  return getToken(Flux::CLASS_IDENTIFIER, 0);
}

tree::TerminalNode* Flux::AssignmentStatementContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

tree::TerminalNode* Flux::AssignmentStatementContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

tree::TerminalNode* Flux::AssignmentStatementContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}

std::vector<Flux::ExprContext *> Flux::AssignmentStatementContext::expr() {
  return getRuleContexts<Flux::ExprContext>();
}

Flux::ExprContext* Flux::AssignmentStatementContext::expr(size_t i) {
  return getRuleContext<Flux::ExprContext>(i);
}

std::vector<tree::TerminalNode *> Flux::AssignmentStatementContext::COMMA() {
  return getTokens(Flux::COMMA);
}

tree::TerminalNode* Flux::AssignmentStatementContext::COMMA(size_t i) {
  return getToken(Flux::COMMA, i);
}

Flux::AssignOpContext* Flux::AssignmentStatementContext::assignOp() {
  return getRuleContext<Flux::AssignOpContext>(0);
}

tree::TerminalNode* Flux::AssignmentStatementContext::THIS() {
  return getToken(Flux::THIS, 0);
}

tree::TerminalNode* Flux::AssignmentStatementContext::DOT() {
  return getToken(Flux::DOT, 0);
}


size_t Flux::AssignmentStatementContext::getRuleIndex() const {
  return Flux::RuleAssignmentStatement;
}

void Flux::AssignmentStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentStatement(this);
}

void Flux::AssignmentStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentStatement(this);
}

Flux::AssignmentStatementContext* Flux::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 50, Flux::RuleAssignmentStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(357);
      match(Flux::IDENTIFIER);
      setState(358);
      match(Flux::ASSIGN);
      setState(359);
      match(Flux::NEW);
      setState(360);
      match(Flux::CLASS_IDENTIFIER);
      setState(361);
      match(Flux::LPAREN);
      setState(370);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4755801472791216192) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 15) != 0)) {
        setState(362);
        expr(0);
        setState(367);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == Flux::COMMA) {
          setState(363);
          match(Flux::COMMA);
          setState(364);
          expr(0);
          setState(369);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(372);
      match(Flux::RPAREN);
      setState(373);
      match(Flux::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(374);
      match(Flux::IDENTIFIER);
      setState(375);
      assignOp();
      setState(376);
      expr(0);
      setState(377);
      match(Flux::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(379);
      match(Flux::THIS);
      setState(380);
      match(Flux::DOT);
      setState(381);
      match(Flux::IDENTIFIER);
      setState(382);
      assignOp();
      setState(383);
      expr(0);
      setState(384);
      match(Flux::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayAssignmentStatementContext ------------------------------------------------------------------

Flux::ArrayAssignmentStatementContext::ArrayAssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Flux::ArrayAccessContext* Flux::ArrayAssignmentStatementContext::arrayAccess() {
  return getRuleContext<Flux::ArrayAccessContext>(0);
}

tree::TerminalNode* Flux::ArrayAssignmentStatementContext::ASSIGN() {
  return getToken(Flux::ASSIGN, 0);
}

Flux::ExprContext* Flux::ArrayAssignmentStatementContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}

tree::TerminalNode* Flux::ArrayAssignmentStatementContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}


size_t Flux::ArrayAssignmentStatementContext::getRuleIndex() const {
  return Flux::RuleArrayAssignmentStatement;
}

void Flux::ArrayAssignmentStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayAssignmentStatement(this);
}

void Flux::ArrayAssignmentStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayAssignmentStatement(this);
}

Flux::ArrayAssignmentStatementContext* Flux::arrayAssignmentStatement() {
  ArrayAssignmentStatementContext *_localctx = _tracker.createInstance<ArrayAssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, Flux::RuleArrayAssignmentStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    arrayAccess();
    setState(389);
    match(Flux::ASSIGN);
    setState(390);
    expr(0);
    setState(391);
    match(Flux::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayLiteralContext ------------------------------------------------------------------

Flux::ArrayLiteralContext::ArrayLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ArrayLiteralContext::LBRACK() {
  return getToken(Flux::LBRACK, 0);
}

tree::TerminalNode* Flux::ArrayLiteralContext::RBRACK() {
  return getToken(Flux::RBRACK, 0);
}

std::vector<Flux::ExprContext *> Flux::ArrayLiteralContext::expr() {
  return getRuleContexts<Flux::ExprContext>();
}

Flux::ExprContext* Flux::ArrayLiteralContext::expr(size_t i) {
  return getRuleContext<Flux::ExprContext>(i);
}

std::vector<tree::TerminalNode *> Flux::ArrayLiteralContext::COMMA() {
  return getTokens(Flux::COMMA);
}

tree::TerminalNode* Flux::ArrayLiteralContext::COMMA(size_t i) {
  return getToken(Flux::COMMA, i);
}


size_t Flux::ArrayLiteralContext::getRuleIndex() const {
  return Flux::RuleArrayLiteral;
}

void Flux::ArrayLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayLiteral(this);
}

void Flux::ArrayLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayLiteral(this);
}

Flux::ArrayLiteralContext* Flux::arrayLiteral() {
  ArrayLiteralContext *_localctx = _tracker.createInstance<ArrayLiteralContext>(_ctx, getState());
  enterRule(_localctx, 54, Flux::RuleArrayLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    match(Flux::LBRACK);
    setState(402);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4755801472791216192) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 15) != 0)) {
      setState(394);
      expr(0);
      setState(399);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Flux::COMMA) {
        setState(395);
        match(Flux::COMMA);
        setState(396);
        expr(0);
        setState(401);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(404);
    match(Flux::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayAccessContext ------------------------------------------------------------------

Flux::ArrayAccessContext::ArrayAccessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ArrayAccessContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}

tree::TerminalNode* Flux::ArrayAccessContext::LBRACK() {
  return getToken(Flux::LBRACK, 0);
}

Flux::ExprContext* Flux::ArrayAccessContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}

tree::TerminalNode* Flux::ArrayAccessContext::RBRACK() {
  return getToken(Flux::RBRACK, 0);
}

tree::TerminalNode* Flux::ArrayAccessContext::UPPERCASE_IDENTIFIER() {
  return getToken(Flux::UPPERCASE_IDENTIFIER, 0);
}


size_t Flux::ArrayAccessContext::getRuleIndex() const {
  return Flux::RuleArrayAccess;
}

void Flux::ArrayAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayAccess(this);
}

void Flux::ArrayAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayAccess(this);
}

Flux::ArrayAccessContext* Flux::arrayAccess() {
  ArrayAccessContext *_localctx = _tracker.createInstance<ArrayAccessContext>(_ctx, getState());
  enterRule(_localctx, 56, Flux::RuleArrayAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(416);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Flux::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(406);
        match(Flux::IDENTIFIER);
        setState(407);
        match(Flux::LBRACK);
        setState(408);
        expr(0);
        setState(409);
        match(Flux::RBRACK);
        break;
      }

      case Flux::UPPERCASE_IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(411);
        match(Flux::UPPERCASE_IDENTIFIER);
        setState(412);
        match(Flux::LBRACK);
        setState(413);
        expr(0);
        setState(414);
        match(Flux::RBRACK);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

Flux::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::IfStatementContext::IF() {
  return getToken(Flux::IF, 0);
}

std::vector<tree::TerminalNode *> Flux::IfStatementContext::LPAREN() {
  return getTokens(Flux::LPAREN);
}

tree::TerminalNode* Flux::IfStatementContext::LPAREN(size_t i) {
  return getToken(Flux::LPAREN, i);
}

std::vector<Flux::ExprContext *> Flux::IfStatementContext::expr() {
  return getRuleContexts<Flux::ExprContext>();
}

Flux::ExprContext* Flux::IfStatementContext::expr(size_t i) {
  return getRuleContext<Flux::ExprContext>(i);
}

std::vector<tree::TerminalNode *> Flux::IfStatementContext::RPAREN() {
  return getTokens(Flux::RPAREN);
}

tree::TerminalNode* Flux::IfStatementContext::RPAREN(size_t i) {
  return getToken(Flux::RPAREN, i);
}

std::vector<Flux::BlockContext *> Flux::IfStatementContext::block() {
  return getRuleContexts<Flux::BlockContext>();
}

Flux::BlockContext* Flux::IfStatementContext::block(size_t i) {
  return getRuleContext<Flux::BlockContext>(i);
}

std::vector<tree::TerminalNode *> Flux::IfStatementContext::ELSEIF() {
  return getTokens(Flux::ELSEIF);
}

tree::TerminalNode* Flux::IfStatementContext::ELSEIF(size_t i) {
  return getToken(Flux::ELSEIF, i);
}

tree::TerminalNode* Flux::IfStatementContext::ELSE() {
  return getToken(Flux::ELSE, 0);
}


size_t Flux::IfStatementContext::getRuleIndex() const {
  return Flux::RuleIfStatement;
}

void Flux::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void Flux::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

Flux::IfStatementContext* Flux::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 58, Flux::RuleIfStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    match(Flux::IF);
    setState(419);
    match(Flux::LPAREN);
    setState(420);
    expr(0);
    setState(421);
    match(Flux::RPAREN);
    setState(422);
    block();
    setState(431);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Flux::ELSEIF) {
      setState(423);
      match(Flux::ELSEIF);
      setState(424);
      match(Flux::LPAREN);
      setState(425);
      expr(0);
      setState(426);
      match(Flux::RPAREN);
      setState(427);
      block();
      setState(433);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(436);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Flux::ELSE) {
      setState(434);
      match(Flux::ELSE);
      setState(435);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueAccessContext ------------------------------------------------------------------

Flux::ValueAccessContext::ValueAccessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> Flux::ValueAccessContext::IDENTIFIER() {
  return getTokens(Flux::IDENTIFIER);
}

tree::TerminalNode* Flux::ValueAccessContext::IDENTIFIER(size_t i) {
  return getToken(Flux::IDENTIFIER, i);
}

tree::TerminalNode* Flux::ValueAccessContext::DOT() {
  return getToken(Flux::DOT, 0);
}

Flux::FuncCallContext* Flux::ValueAccessContext::funcCall() {
  return getRuleContext<Flux::FuncCallContext>(0);
}


size_t Flux::ValueAccessContext::getRuleIndex() const {
  return Flux::RuleValueAccess;
}

void Flux::ValueAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValueAccess(this);
}

void Flux::ValueAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValueAccess(this);
}

Flux::ValueAccessContext* Flux::valueAccess() {
  ValueAccessContext *_localctx = _tracker.createInstance<ValueAccessContext>(_ctx, getState());
  enterRule(_localctx, 60, Flux::RuleValueAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    match(Flux::IDENTIFIER);
    setState(439);
    match(Flux::DOT);
    setState(442);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(440);
      funcCall();
      break;
    }

    case 2: {
      setState(441);
      match(Flux::IDENTIFIER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

Flux::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Flux::NotExprContext* Flux::ExprContext::notExpr() {
  return getRuleContext<Flux::NotExprContext>(0);
}

Flux::TermContext* Flux::ExprContext::term() {
  return getRuleContext<Flux::TermContext>(0);
}

Flux::ExprContext* Flux::ExprContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}

Flux::ArithmeticOpContext* Flux::ExprContext::arithmeticOp() {
  return getRuleContext<Flux::ArithmeticOpContext>(0);
}

Flux::CompareOpContext* Flux::ExprContext::compareOp() {
  return getRuleContext<Flux::CompareOpContext>(0);
}

Flux::LogicalOpContext* Flux::ExprContext::logicalOp() {
  return getRuleContext<Flux::LogicalOpContext>(0);
}


size_t Flux::ExprContext::getRuleIndex() const {
  return Flux::RuleExpr;
}

void Flux::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void Flux::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


Flux::ExprContext* Flux::expr() {
   return expr(0);
}

Flux::ExprContext* Flux::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Flux::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  Flux::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, Flux::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(447);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Flux::NOT: {
        setState(445);
        notExpr();
        break;
      }

      case Flux::THIS:
      case Flux::UPPERCASE_IDENTIFIER:
      case Flux::CLASS_IDENTIFIER:
      case Flux::IDENTIFIER:
      case Flux::PRINT_FUNC:
      case Flux::RANGE_FUNC:
      case Flux::LPAREN:
      case Flux::BOOL_LIT:
      case Flux::INT_LIT:
      case Flux::DECIMAL_LIT:
      case Flux::STRING_LIT: {
        setState(446);
        term();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(463);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(461);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(449);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(450);
          arithmeticOp();
          setState(451);
          term();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(453);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(454);
          compareOp();
          setState(455);
          term();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(457);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(458);
          logicalOp();
          setState(459);
          term();
          break;
        }

        default:
          break;
        } 
      }
      setState(465);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArithmeticOpContext ------------------------------------------------------------------

Flux::ArithmeticOpContext::ArithmeticOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ArithmeticOpContext::ADD() {
  return getToken(Flux::ADD, 0);
}

tree::TerminalNode* Flux::ArithmeticOpContext::SUBTRACT() {
  return getToken(Flux::SUBTRACT, 0);
}

tree::TerminalNode* Flux::ArithmeticOpContext::MULTIPLY() {
  return getToken(Flux::MULTIPLY, 0);
}

tree::TerminalNode* Flux::ArithmeticOpContext::DIVIDE() {
  return getToken(Flux::DIVIDE, 0);
}

tree::TerminalNode* Flux::ArithmeticOpContext::POWER() {
  return getToken(Flux::POWER, 0);
}

tree::TerminalNode* Flux::ArithmeticOpContext::MOD() {
  return getToken(Flux::MOD, 0);
}


size_t Flux::ArithmeticOpContext::getRuleIndex() const {
  return Flux::RuleArithmeticOp;
}

void Flux::ArithmeticOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmeticOp(this);
}

void Flux::ArithmeticOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmeticOp(this);
}

Flux::ArithmeticOpContext* Flux::arithmeticOp() {
  ArithmeticOpContext *_localctx = _tracker.createInstance<ArithmeticOpContext>(_ctx, getState());
  enterRule(_localctx, 64, Flux::RuleArithmeticOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(466);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 554153860399104) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompareOpContext ------------------------------------------------------------------

Flux::CompareOpContext::CompareOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::CompareOpContext::EQUAL() {
  return getToken(Flux::EQUAL, 0);
}

tree::TerminalNode* Flux::CompareOpContext::NOT_EQUAL() {
  return getToken(Flux::NOT_EQUAL, 0);
}

tree::TerminalNode* Flux::CompareOpContext::GREATER_EQUAL() {
  return getToken(Flux::GREATER_EQUAL, 0);
}

tree::TerminalNode* Flux::CompareOpContext::LESS_EQUAL() {
  return getToken(Flux::LESS_EQUAL, 0);
}

tree::TerminalNode* Flux::CompareOpContext::GREATER() {
  return getToken(Flux::GREATER, 0);
}

tree::TerminalNode* Flux::CompareOpContext::LESS() {
  return getToken(Flux::LESS, 0);
}


size_t Flux::CompareOpContext::getRuleIndex() const {
  return Flux::RuleCompareOp;
}

void Flux::CompareOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompareOp(this);
}

void Flux::CompareOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompareOp(this);
}

Flux::CompareOpContext* Flux::compareOp() {
  CompareOpContext *_localctx = _tracker.createInstance<CompareOpContext>(_ctx, getState());
  enterRule(_localctx, 66, Flux::RuleCompareOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(468);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 35465847065542656) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOpContext ------------------------------------------------------------------

Flux::LogicalOpContext::LogicalOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::LogicalOpContext::AND() {
  return getToken(Flux::AND, 0);
}

tree::TerminalNode* Flux::LogicalOpContext::OR() {
  return getToken(Flux::OR, 0);
}


size_t Flux::LogicalOpContext::getRuleIndex() const {
  return Flux::RuleLogicalOp;
}

void Flux::LogicalOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOp(this);
}

void Flux::LogicalOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOp(this);
}

Flux::LogicalOpContext* Flux::logicalOp() {
  LogicalOpContext *_localctx = _tracker.createInstance<LogicalOpContext>(_ctx, getState());
  enterRule(_localctx, 68, Flux::RuleLogicalOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(470);
    _la = _input->LA(1);
    if (!(_la == Flux::AND

    || _la == Flux::OR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignOpContext ------------------------------------------------------------------

Flux::AssignOpContext::AssignOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::AssignOpContext::ASSIGN() {
  return getToken(Flux::ASSIGN, 0);
}

tree::TerminalNode* Flux::AssignOpContext::ADD_ASSIGN() {
  return getToken(Flux::ADD_ASSIGN, 0);
}

tree::TerminalNode* Flux::AssignOpContext::SUB_ASSIGN() {
  return getToken(Flux::SUB_ASSIGN, 0);
}

tree::TerminalNode* Flux::AssignOpContext::MUL_ASSIGN() {
  return getToken(Flux::MUL_ASSIGN, 0);
}

tree::TerminalNode* Flux::AssignOpContext::DIV_ASSIGN() {
  return getToken(Flux::DIV_ASSIGN, 0);
}


size_t Flux::AssignOpContext::getRuleIndex() const {
  return Flux::RuleAssignOp;
}

void Flux::AssignOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignOp(this);
}

void Flux::AssignOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignOp(this);
}

Flux::AssignOpContext* Flux::assignOp() {
  AssignOpContext *_localctx = _tracker.createInstance<AssignOpContext>(_ctx, getState());
  enterRule(_localctx, 70, Flux::RuleAssignOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(472);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8521215115264) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotExprContext ------------------------------------------------------------------

Flux::NotExprContext::NotExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::NotExprContext::NOT() {
  return getToken(Flux::NOT, 0);
}

Flux::ExprContext* Flux::NotExprContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}


size_t Flux::NotExprContext::getRuleIndex() const {
  return Flux::RuleNotExpr;
}

void Flux::NotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpr(this);
}

void Flux::NotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpr(this);
}

Flux::NotExprContext* Flux::notExpr() {
  NotExprContext *_localctx = _tracker.createInstance<NotExprContext>(_ctx, getState());
  enterRule(_localctx, 72, Flux::RuleNotExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(474);
    match(Flux::NOT);
    setState(475);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassInstantiationContext ------------------------------------------------------------------

Flux::ClassInstantiationContext::ClassInstantiationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ClassInstantiationContext::CLASS_IDENTIFIER() {
  return getToken(Flux::CLASS_IDENTIFIER, 0);
}

tree::TerminalNode* Flux::ClassInstantiationContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

tree::TerminalNode* Flux::ClassInstantiationContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

std::vector<Flux::ExprContext *> Flux::ClassInstantiationContext::expr() {
  return getRuleContexts<Flux::ExprContext>();
}

Flux::ExprContext* Flux::ClassInstantiationContext::expr(size_t i) {
  return getRuleContext<Flux::ExprContext>(i);
}

std::vector<tree::TerminalNode *> Flux::ClassInstantiationContext::COMMA() {
  return getTokens(Flux::COMMA);
}

tree::TerminalNode* Flux::ClassInstantiationContext::COMMA(size_t i) {
  return getToken(Flux::COMMA, i);
}


size_t Flux::ClassInstantiationContext::getRuleIndex() const {
  return Flux::RuleClassInstantiation;
}

void Flux::ClassInstantiationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassInstantiation(this);
}

void Flux::ClassInstantiationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassInstantiation(this);
}

Flux::ClassInstantiationContext* Flux::classInstantiation() {
  ClassInstantiationContext *_localctx = _tracker.createInstance<ClassInstantiationContext>(_ctx, getState());
  enterRule(_localctx, 74, Flux::RuleClassInstantiation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(477);
    match(Flux::CLASS_IDENTIFIER);
    setState(478);
    match(Flux::LPAREN);
    setState(487);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4755801472791216192) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 15) != 0)) {
      setState(479);
      expr(0);
      setState(484);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Flux::COMMA) {
        setState(480);
        match(Flux::COMMA);
        setState(481);
        expr(0);
        setState(486);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(489);
    match(Flux::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

Flux::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Flux::FactorContext* Flux::TermContext::factor() {
  return getRuleContext<Flux::FactorContext>(0);
}

tree::TerminalNode* Flux::TermContext::THIS() {
  return getToken(Flux::THIS, 0);
}

tree::TerminalNode* Flux::TermContext::DOT() {
  return getToken(Flux::DOT, 0);
}

tree::TerminalNode* Flux::TermContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}


size_t Flux::TermContext::getRuleIndex() const {
  return Flux::RuleTerm;
}

void Flux::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void Flux::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}

Flux::TermContext* Flux::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 76, Flux::RuleTerm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(497);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Flux::UPPERCASE_IDENTIFIER:
      case Flux::CLASS_IDENTIFIER:
      case Flux::IDENTIFIER:
      case Flux::PRINT_FUNC:
      case Flux::RANGE_FUNC:
      case Flux::LPAREN:
      case Flux::BOOL_LIT:
      case Flux::INT_LIT:
      case Flux::DECIMAL_LIT:
      case Flux::STRING_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(491);
        factor();
        break;
      }

      case Flux::THIS: {
        enterOuterAlt(_localctx, 2);
        setState(492);
        match(Flux::THIS);
        setState(495);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
        case 1: {
          setState(493);
          match(Flux::DOT);
          setState(494);
          match(Flux::IDENTIFIER);
          break;
        }

        default:
          break;
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

Flux::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::FactorContext::BOOL_LIT() {
  return getToken(Flux::BOOL_LIT, 0);
}

tree::TerminalNode* Flux::FactorContext::DECIMAL_LIT() {
  return getToken(Flux::DECIMAL_LIT, 0);
}

tree::TerminalNode* Flux::FactorContext::INT_LIT() {
  return getToken(Flux::INT_LIT, 0);
}

tree::TerminalNode* Flux::FactorContext::STRING_LIT() {
  return getToken(Flux::STRING_LIT, 0);
}

tree::TerminalNode* Flux::FactorContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}

Flux::ArrayAccessContext* Flux::FactorContext::arrayAccess() {
  return getRuleContext<Flux::ArrayAccessContext>(0);
}

Flux::FuncCallContext* Flux::FactorContext::funcCall() {
  return getRuleContext<Flux::FuncCallContext>(0);
}

Flux::BuiltInCallContext* Flux::FactorContext::builtInCall() {
  return getRuleContext<Flux::BuiltInCallContext>(0);
}

tree::TerminalNode* Flux::FactorContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

Flux::ExprContext* Flux::FactorContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}

tree::TerminalNode* Flux::FactorContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

Flux::ClassInstantiationContext* Flux::FactorContext::classInstantiation() {
  return getRuleContext<Flux::ClassInstantiationContext>(0);
}


size_t Flux::FactorContext::getRuleIndex() const {
  return Flux::RuleFactor;
}

void Flux::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void Flux::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

Flux::FactorContext* Flux::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 78, Flux::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(512);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(499);
      match(Flux::BOOL_LIT);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(500);
      match(Flux::DECIMAL_LIT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(501);
      match(Flux::INT_LIT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(502);
      match(Flux::STRING_LIT);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(503);
      match(Flux::IDENTIFIER);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(504);
      arrayAccess();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(505);
      funcCall();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(506);
      builtInCall();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(507);
      match(Flux::LPAREN);
      setState(508);
      expr(0);
      setState(509);
      match(Flux::RPAREN);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(511);
      classInstantiation();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDeclarationContext ------------------------------------------------------------------

Flux::FuncDeclarationContext::FuncDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Flux::TypeContext* Flux::FuncDeclarationContext::type() {
  return getRuleContext<Flux::TypeContext>(0);
}

tree::TerminalNode* Flux::FuncDeclarationContext::FUNC() {
  return getToken(Flux::FUNC, 0);
}

tree::TerminalNode* Flux::FuncDeclarationContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}

tree::TerminalNode* Flux::FuncDeclarationContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

tree::TerminalNode* Flux::FuncDeclarationContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

Flux::BlockContext* Flux::FuncDeclarationContext::block() {
  return getRuleContext<Flux::BlockContext>(0);
}

Flux::ParamListContext* Flux::FuncDeclarationContext::paramList() {
  return getRuleContext<Flux::ParamListContext>(0);
}


size_t Flux::FuncDeclarationContext::getRuleIndex() const {
  return Flux::RuleFuncDeclaration;
}

void Flux::FuncDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDeclaration(this);
}

void Flux::FuncDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDeclaration(this);
}

Flux::FuncDeclarationContext* Flux::funcDeclaration() {
  FuncDeclarationContext *_localctx = _tracker.createInstance<FuncDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 80, Flux::RuleFuncDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(532);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Flux::NUMBER_VAR:
      case Flux::STRING_VAR:
      case Flux::BOOLEAN_VAR:
      case Flux::CLASS_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(514);
        type();
        setState(515);
        match(Flux::FUNC);
        setState(516);
        match(Flux::IDENTIFIER);
        setState(517);
        match(Flux::LPAREN);
        setState(519);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 24696061952) != 0)) {
          setState(518);
          paramList();
        }
        setState(521);
        match(Flux::RPAREN);
        setState(522);
        block();
        break;
      }

      case Flux::FUNC: {
        enterOuterAlt(_localctx, 2);
        setState(524);
        match(Flux::FUNC);
        setState(525);
        match(Flux::IDENTIFIER);
        setState(526);
        match(Flux::LPAREN);
        setState(528);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 24696061952) != 0)) {
          setState(527);
          paramList();
        }
        setState(530);
        match(Flux::RPAREN);
        setState(531);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncCallContext ------------------------------------------------------------------

Flux::FuncCallContext::FuncCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::FuncCallContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}

tree::TerminalNode* Flux::FuncCallContext::LPAREN() {
  return getToken(Flux::LPAREN, 0);
}

tree::TerminalNode* Flux::FuncCallContext::RPAREN() {
  return getToken(Flux::RPAREN, 0);
}

std::vector<Flux::ExprContext *> Flux::FuncCallContext::expr() {
  return getRuleContexts<Flux::ExprContext>();
}

Flux::ExprContext* Flux::FuncCallContext::expr(size_t i) {
  return getRuleContext<Flux::ExprContext>(i);
}

std::vector<tree::TerminalNode *> Flux::FuncCallContext::COMMA() {
  return getTokens(Flux::COMMA);
}

tree::TerminalNode* Flux::FuncCallContext::COMMA(size_t i) {
  return getToken(Flux::COMMA, i);
}


size_t Flux::FuncCallContext::getRuleIndex() const {
  return Flux::RuleFuncCall;
}

void Flux::FuncCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncCall(this);
}

void Flux::FuncCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncCall(this);
}

Flux::FuncCallContext* Flux::funcCall() {
  FuncCallContext *_localctx = _tracker.createInstance<FuncCallContext>(_ctx, getState());
  enterRule(_localctx, 82, Flux::RuleFuncCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(534);
    match(Flux::IDENTIFIER);
    setState(535);
    match(Flux::LPAREN);
    setState(544);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4755801472791216192) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 15) != 0)) {
      setState(536);
      expr(0);
      setState(541);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Flux::COMMA) {
        setState(537);
        match(Flux::COMMA);
        setState(538);
        expr(0);
        setState(543);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(546);
    match(Flux::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

Flux::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Flux::ParamContext *> Flux::ParamListContext::param() {
  return getRuleContexts<Flux::ParamContext>();
}

Flux::ParamContext* Flux::ParamListContext::param(size_t i) {
  return getRuleContext<Flux::ParamContext>(i);
}

std::vector<tree::TerminalNode *> Flux::ParamListContext::COMMA() {
  return getTokens(Flux::COMMA);
}

tree::TerminalNode* Flux::ParamListContext::COMMA(size_t i) {
  return getToken(Flux::COMMA, i);
}


size_t Flux::ParamListContext::getRuleIndex() const {
  return Flux::RuleParamList;
}

void Flux::ParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamList(this);
}

void Flux::ParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamList(this);
}

Flux::ParamListContext* Flux::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 84, Flux::RuleParamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(548);
    param();
    setState(553);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Flux::COMMA) {
      setState(549);
      match(Flux::COMMA);
      setState(550);
      param();
      setState(555);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

Flux::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Flux::TypeContext* Flux::ParamContext::type() {
  return getRuleContext<Flux::TypeContext>(0);
}

tree::TerminalNode* Flux::ParamContext::IDENTIFIER() {
  return getToken(Flux::IDENTIFIER, 0);
}


size_t Flux::ParamContext::getRuleIndex() const {
  return Flux::RuleParam;
}

void Flux::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void Flux::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}

Flux::ParamContext* Flux::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 86, Flux::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(556);
    type();
    setState(557);
    match(Flux::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

Flux::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::ReturnStmtContext::RETURN() {
  return getToken(Flux::RETURN, 0);
}

tree::TerminalNode* Flux::ReturnStmtContext::SEMICOLON() {
  return getToken(Flux::SEMICOLON, 0);
}

Flux::ExprContext* Flux::ReturnStmtContext::expr() {
  return getRuleContext<Flux::ExprContext>(0);
}


size_t Flux::ReturnStmtContext::getRuleIndex() const {
  return Flux::RuleReturnStmt;
}

void Flux::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void Flux::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}

Flux::ReturnStmtContext* Flux::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 88, Flux::RuleReturnStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(559);
    match(Flux::RETURN);
    setState(561);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4755801472791216192) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 15) != 0)) {
      setState(560);
      expr(0);
    }
    setState(563);
    match(Flux::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

Flux::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Flux::TypeContext::NUMBER_VAR() {
  return getToken(Flux::NUMBER_VAR, 0);
}

tree::TerminalNode* Flux::TypeContext::STRING_VAR() {
  return getToken(Flux::STRING_VAR, 0);
}

tree::TerminalNode* Flux::TypeContext::BOOLEAN_VAR() {
  return getToken(Flux::BOOLEAN_VAR, 0);
}

tree::TerminalNode* Flux::TypeContext::CLASS_IDENTIFIER() {
  return getToken(Flux::CLASS_IDENTIFIER, 0);
}


size_t Flux::TypeContext::getRuleIndex() const {
  return Flux::RuleType;
}

void Flux::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void Flux::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FluxListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

Flux::TypeContext* Flux::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 90, Flux::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 24696061952) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool Flux::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 31: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool Flux::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void Flux::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  fluxParserInitialize();
#else
  ::antlr4::internal::call_once(fluxParserOnceFlag, fluxParserInitialize);
#endif
}
