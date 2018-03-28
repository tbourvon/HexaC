#include <iostream>
#include <string>
#include <antlr4-runtime.h>
#include "HexaCLexer.h"
#include "HexaCParser.h"
#include "HexaCParserBaseListener.h"
#include "ast/astgenerator.h"
#include "ast/astprinter.h"
#include "ir/IR.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {

  if(argc != 3 || argv[1] == "-h" || argv[1] == "-help"){
    std::cout << "Usage of HexaCompiler : ./HexaC input.s outputName" << std::endl;
    return 1;
  }

  std::string inputFileName = argv[1];
  std::string inputFileNameWithOExtension = inputFileName;
  inputFileNameWithOExtension.pop_back();
  inputFileNameWithOExtension += "o";
  std::string outputFileName = argv[2];

  std::cout << inputFileName <<std::endl;
  std::cout << inputFileNameWithOExtension<< std::endl;
  std::cout << outputFileName<<std::endl;


  std::ifstream stream;
  stream.open(inputFileName);
  ANTLRInputStream input(stream);
  HexaC::HexaCLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  HexaC::HexaCParser parser(&tokens);

  tree::ParseTree *tree = parser.program();

  ASTGenerator astVisitor;
  Program *program = astVisitor.visit(tree);
  AST ast(program);
  IR ir(program);

  std::cout << ir.gen_asm() << std::endl;

  ASTPrinter printer;
  printer.visitAST(&ast);

  
  return 0;
}


