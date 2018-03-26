//
// Created by JC on 26/03/2018.
//
#include "BasicBlock.h"
#ifndef ANTLR4CPP_FETCHER_CFG_H
#define ANTLR4CPP_FETCHER_CFG_H

class CFG {
    public:
        CFG(DefFonction* ast);

        DefFonction* ast; /**< The AST this CFG comes from */

        void add_bb(BasicBlock* bb);

        // x86 code generation: could be encapsulated in a processor class in a retargetable compiler
        void gen_asm(ostream& o);
        string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
        void gen_asm_prologue(ostream& o);
        void gen_asm_epilogue(ostream& o);

        // symbol table methods
        void add_to_symbol_table(string name, Type t);
        string create_new_tempvar(Type t);
        int get_var_index(string name);
        Type get_var_type(string name);

        // basic block management
        string new_BB_name();
        BasicBlock* current_bb;

    protected:
        map <string, Type> SymbolType; /**< part of the symbol table  */
        map <string, int> SymbolIndex; /**< part of the symbol table  */
        int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
        int nextBBnumber; /**< just for naming */

        vector <BasicBlock*> bbs; /**< all the basic blocks of this CFG*/
};

#endif //ANTLR4CPP_FETCHER_CFG_H
