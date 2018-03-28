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
  IR ir(program);

  std::string assemblyCode = ir.gen_asm();
  std::cout << assemblyCode << std::endl;

  std::ofstream outfile;
  outfile.open(outputFileName+".s");
  outfile << assemblyCode;
  outfile.close();

#ifdef GENEXEC
    //as command
    std::string asCommand = "as -o " + outputFileName+".o " + outputFileName+".s";
    system(asCommand.c_str());

    //gcc command
    std::string gccCommand = "gcc " + outputFileName +".o -o " + outputFileName;
    system(gccCommand.c_str());

#endif

  ASTPrinter printer;
  printer.visitAST(&ast);


  return 0;
}


