#ifndef ANTLR4CPP_FETCHER_CFG_H
#define ANTLR4CPP_FETCHER_CFG_H

#include "BasicBlock.h"
#include "DefFonction.h"

class CFG {
    public:
        CFG(DefFonction* ast);

        DefFonction* ast; /**< The AST this CFG comes from */

        void add_bb(BasicBlock* bb);

        // x86 code generation: could be encapsulated in a processor class in a retargetable compiler
        void gen_asm(std::ostream& o);
        std::string IR_reg_to_asm(std::string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
        void gen_asm_prologue(std::ostream& o);
        void gen_asm_epilogue(std::ostream& o);

        // symbol table methods
        void add_to_symbol_table(std::string name, Type t);
        std::string create_new_tempvar(Type t);
        int get_var_index(std::string name);
        Type get_var_type(std::string name);

        // basic block management
        std::string new_BB_name();
        BasicBlock* current_bb;

    protected:
        std::map<std::string, Type> SymbolType; /**< part of the symbol table  */
        std::map<std::string, int> SymbolIndex; /**< part of the symbol table  */
        int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
        int nextBBnumber; /**< just for naming */

        std::vector<BasicBlock*> bbs; /**< all the basic blocks of this CFG*/
};

#endif //ANTLR4CPP_FETCHER_CFG_H
