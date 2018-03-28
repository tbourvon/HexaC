#ifndef ANTLR4CPP_FETCHER_IR_H
#define ANTLR4CPP_FETCHER_IR_H

#include <string>
#include <vector>

#include <iostream>
#include <initializer_list>
#include <HexaCLexer.h>
#include "BasicBlock.h"
#include "Operation.h"

//! The class for one 3-address instruction
class IRInstr {

    public:
        /** The instructions themselves -- feel free to subclass instead */


        /**  constructor */
        IRInstr(BasicBlock* bb_, Operation op, Type t, std::vector<std::string> params);

        /** Actual code generation */
        void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */

    private:
        BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
        Operation op;
        Type t;
        std::vector<std::string> params; /**< For 3-op instrs: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
        // if you subclass IRInstr, each IRInstr subclass has its parameters and the previous (very important) comment becomes useless: it would be a better design.
};



#endif //ANTLR4CPP_FETCHER_IR_H
