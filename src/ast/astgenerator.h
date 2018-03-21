#ifndef ASTGENERATOR_H
#define ASTGENERATOR_H

#include <HexaCParserBaseVisitor.h>
#include "ast.h"


using namespace HexaC;

class ASTGenerator : public HexaCParserBaseVisitor
{
public:
    ASTGenerator();

    virtual antlrcpp::Any visitProgram(HexaCParser::ProgramContext *ctx) override {
      std::vector<Decl*> decls;
      for (HexaCParser::Toplevel_itemContext* top_level_ctx : ctx->toplevel_item()) {
          if (DeclContext *decl = top_level_ctx->decl()) {
              visit(decl);
              decls.push_back(decl);
          }
      }

      return new Program(decl);
    }
};

#endif // ASTGENERATOR_H
