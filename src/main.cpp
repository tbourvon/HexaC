#include <iostream>
#include <antlr4-runtime.h>
#include "HexaCLexer.h"
#include "HexaCParser.h"
#include "HexaCParserBaseListener.h"

using namespace antlr4;

class TreeShapeListener : public HexaC::HexaCParserBaseListener {
public:
  void enterProgram(HexaC::HexaCParser::ProgramContext * ctx) override {
	// Do something when entering the key rule.
  }
};


int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  HexaC::HexaCLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  HexaC::HexaCParser parser(&tokens);

  tree::ParseTree *tree = parser.program();
  TreeShapeListener listener;
  tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

  return 0;
}


