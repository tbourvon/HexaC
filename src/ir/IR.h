//
// Created by JC on 28/03/2018.
//

#ifndef ANTLR4CPP_FETCHER_IR_H
#define ANTLR4CPP_FETCHER_IR_H


#include "../ast/ast.h"
#include "CFG.h"
#include <vector>
#include <map>

class IR {
    public:
        IR(Program *prog) {
            std::vector<Decl *> decls = prog->getDecls();

            for (Decl* decl : decls) {
                if (FuncDecl* fd = dynamic_cast<FuncDecl*>(decl)) {
                    CFG *bf = new CFG(fd);
                    listCFG.push_back(bf);
                }
            }
        }

        std::string gen_asm(){
            std::string res;
            res += ".text                       # section declaration\r\n";
            res += ".global main                # entry point\r\n";
            res += "\r\n";

            for (CFG* cfg : listCFG) {
                res += cfg->gen_asm();
            }

            return res;
        }

    private:
        std::vector<CFG*> listCFG;
};


#endif //ANTLR4CPP_FETCHER_IR_H
