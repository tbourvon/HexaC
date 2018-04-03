#include "IR.h"

IRInstr::IRInstr(BasicBlock* bb_, Operation op, Type* t, vector<string> params) {

}

void IRInstr::gen_asm(ostream& out) {
  switch(op) {
      case Operation.ldconst) :
        int indexDest = bb->cfg->SymbolIndex.at(params[0]);
        out << "movq $" << params[1] << "," << indexDest <<"(%rbp)";
      case Operation.add :
        int indexDest = bb->cfg->get_var_index(params[0]);
        int indexParam1 = bb->cfg->get_var_index(params[1]);
        int indexParam2 = bb->cfg->get_var_index(params[2]);
        out << "movq " << indexParam1 << "(%rbp), %rax";
        out << "addq " << indexParam2 << "(%rbp), %rax";
        out << "movq %rax, " << indexDest << "(%rbp)";
      case Operation.sub :
      int indexDest = bb->cfg->get_var_index(params[0]);
      int indexParam1 = bb->cfg->get_var_index(params[1]);
      int indexParam2 = bb->cfg->get_var_index(params[2]);
      out << "movq " << indexParam1 << "(%rbp), %rax";
      out << "subq " << indexParam2 << "(%rbp), %rax";
      out << "movq %rax, " << indexDest << "(%rbp)";
      case Operation.mul :
      case Operation.rmem :
      case Operation.wmem :
      case Operation.call :
      case Operation.cmp_eq :
      case Operation.cmp_lt :
      case Operation.cmp_le :
      case Operation.Operation :

  }
}

void BasicBlock::gen_asm(ostream& out) {
  if (label == cfg->ast->getName()) {
    cfg->gen_asm_prologue(out);
  }

  for (auto instr : instrs) {
    instr->gen_asm(out);
  }

  if (!exit_true) {
    cfg->gen_asm_epilogue(out);
  }
  // TODO: truc bizarre des deux jumps conditionnels
}

void BasicBlock::add_IRInstr(IRInstr::Operation op, Type* t, vector<string> params) {
  instrs.push_back(new IRInstr(this, op, t, params));
}

void CFG::gen_asm(ostream& out) {
  for (auto bb : bbs) {
    bb->gen_asm(out);
  }
}

void CFG::gen_asm_prologue(ostream& out) {
  unsigned int size = 0;
  for (const auto& symbol_pair : SymbolType) {
    auto builtin = dynamic_cast<BuiltinType*>(symbol_pair.second);
    if (!builtin) {
      continue;
    }

    switch (builtin->getKind()) {
      case BuiltinType::Kind::CHAR: size += 1; break;
      case BuiltinType::Kind::INT32_T: size += 4; break;
      case BuiltinType::Kind::INT64_T: size += 8; break;
      default: break;
    }
  }

  out << ".pushq  %rbp" << endl;
  out << "movq  %rsp, %rbp" << endl;
  out << "subq  $" <<  size << ", %rsp" << endl;
  out << endl;
}

void CFG::gen_asm_epilogue(ostream& out) {
  out << "leave" << endl;
  out << "ret" << endl;
}

int CFG::get_var_index(string name) {
  return SymbolIndex.at(name);
}
