
// Generated from /Users/tbourvon/Drive/Projects/Programming/HexaC/grammar/HexaCLexer.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace HexaC {


class  HexaCLexer : public antlr4::Lexer {
public:
  enum {
    ID = 1, IF = 2, ELSE = 3, WHILE = 4, RETURN = 5, INT32_T = 6, INT64_T = 7, 
    CHAR = 8, VOID = 9, INCLUDE = 10, INT_LIT = 11, CHAR_LIT = 12, OPEN_PAR = 13, 
    CLOSE_PAR = 14, OPEN_BRACE = 15, CLOSE_BRACE = 16, OPEN_BRACKET = 17, 
    CLOSE_BRACKET = 18, SEMICOLON = 19, STAR = 20, PLUS = 21, DIV = 22, 
    MINUS = 23, MOD = 24, EQ = 25, PLUS_EQ = 26, MINUS_EQ = 27, DIV_EQ = 28, 
    STAR_EQ = 29, MOD_EQ = 30, EQ_EQ = 31, NOT_EQ = 32, GT = 33, LT = 34, 
    GE = 35, LE = 36, NOT = 37, PLUS_PLUS = 38, MINUS_MINUS = 39, COMMA = 40, 
    AND_AND = 41, OR_OR = 42, HASH = 43, DOT = 44
  };

  HexaCLexer(antlr4::CharStream *input);
  ~HexaCLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.
  void IDAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace HexaC
