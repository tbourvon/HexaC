#include <iostream>
#include <antlr4-runtime.h>
#include "HexaCLexer.h"
#include "HexaCParser.h"
#include "HexaCParserBaseListener.h"
#include "ast/astgenerator.h"
#include "ast/astprinter.h"
#include "ast/typeVisitor.h"
#include "ir/IR.h"
#include "ir/irgenerator.h"

#define GENEXEC

using namespace antlr4;

int main(int argc, const char* argv[]) {

  if(argc != 3 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
    std::cout << "Usage of HexaCompiler : ./HexaC input.c outputName" << std::endl;
    return 1;
  }

  std::string inputFileName = argv[1];
  std::string outputFileName = argv[2];

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

  ASTPrinter printer;
    cout << endl << "-----------------------------" << endl << "AST : " << endl << endl;

  printer.visitAST(&ast);

  TypeVisitor typeChecking;
  cout << endl << "-----------------------------" << endl << "Vérification Type : " << endl << endl;
  if (!typeChecking.visitAST(&ast)) {
    return -1;
  }

  IRGenerator irg;
  auto cfgs = irg.generateIR(&ast);

  std::stringstream assembly;

  assembly << ".text" << std::endl;
  std::string lineToWrite = ".global main";
  #ifdef __APPLE__
    lineToWrite = ".globl _main";
  #endif
  assembly << lineToWrite << std::endl;
  assembly << std::endl;

  for (auto cfg : cfgs) {
    cfg->gen_asm(assembly);
  }

  std::ofstream outfile;
  outfile.open(outputFileName+".s");
  outfile << assembly.str();
  outfile.close();

#ifdef GENEXEC
    //as command
    std::string asCommand = "as -o " + outputFileName+".o " + outputFileName+".s";
    system(asCommand.c_str());

    //gcc command
    std::string gccCommand = "gcc " + outputFileName +".o -o " + outputFileName;
    system(gccCommand.c_str());
#endif

  return 0;
}
