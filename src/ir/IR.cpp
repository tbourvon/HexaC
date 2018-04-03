#include "IR.h"

IRInstr::IRInstr(BasicBlock* bb_, Operation op, Type* t, vector<string> params) {

}

void IRInstr::gen_asm(ostream& out) {

}

void BasicBlock::gen_asm(ostream& out) {
  if (label == cfg->ast->getName()) {
    cfg->gen_asm_prologue(out);
  }

  out << label << ":";

  for (auto instr : instrs) {
    instr->gen_asm(out);
  }

  if (!exit_true && !exit_false) {
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
  out << "subq  $" << size << ", %rsp" << endl;
  out << endl;
}

void CFG::gen_asm_epilogue(ostream& out) {
  out << "leave" << endl;
  out << "ret" << endl;
}