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
          if (HexaCParser::DeclContext *decl_ctx = top_level_ctx->decl()) {
              decls.push_back((Decl*)visit(decl_ctx));
          }
      }

      return new Program(decls);
    }


};

#endif // ASTGENERATOR_H
