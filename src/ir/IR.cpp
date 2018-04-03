#include "IR.h"

IRInstr::IRInstr(BasicBlock* bb_, Operation op, const Type* t, vector<string> params) {

}

void IRInstr::gen_asm(ostream& out) {

}

void BasicBlock::gen_asm(ostream& out) {
  out << label << ":" << endl;

  if (label == cfg->ast->getName()) {
    cfg->gen_asm_prologue(out);
  }

  for (auto instr : instrs) {
    instr->gen_asm(out);
  }

  if (!exit_true && !exit_false) {
    cfg->gen_asm_epilogue(out);
  }
  // TODO: truc bizarre des deux jumps conditionnels
}

BasicBlock::BasicBlock(CFG* _cfg, string _entry_label) : cfg(_cfg), label(_entry_label) {

}

void BasicBlock::add_IRInstr(IRInstr::Operation op, const Type* t, vector<string> params) {
  instrs.push_back(new IRInstr(this, op, t, params));
}

CFG::CFG(const FuncDecl* _ast) : ast(_ast), nextBBnumber(0), nextFreeSymbolIndex(0) {
  auto firstBB = new BasicBlock(this, ast->getName());
  add_bb(firstBB);

  auto lastBB = new BasicBlock(this, new_BB_name());
  add_bb(lastBB);

  firstBB->exit_false = nullptr;
  firstBB->exit_true = lastBB;

  lastBB->exit_false = nullptr;
  lastBB->exit_true = nullptr;

  current_bb = firstBB;
}

std::string CFG::new_BB_name() {
  return "bb" + std::to_string(nextBBnumber++);
}

int CFG::get_var_index(string name) {
  return SymbolIndex.at(name);
}

void CFG::add_bb(BasicBlock *bb) {
  bbs.push_back(bb);
} 

std::string CFG::create_new_tempvar(const Type* t) {
  std::string name = "!tmp" + std::to_string(nextFreeSymbolIndex);
  SymbolType[name] = t;
  SymbolIndex[name] = nextFreeSymbolIndex;

  nextFreeSymbolIndex += get_size_for_type(t);

  return name;
}

void CFG::add_to_symbol_table(string name, const Type* t) {
  SymbolType[name] = t;
  SymbolIndex[name] = nextFreeSymbolIndex;

  nextFreeSymbolIndex += get_size_for_type(t);
}

void CFG::gen_asm(ostream& out) {
  for (auto bb : bbs) {
    bb->gen_asm(out);
  }
}

void CFG::gen_asm_prologue(ostream& out) {
  unsigned int size = 0;
  for (const auto& symbol_pair : SymbolType) {
    size += get_size_for_type(symbol_pair.second);
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

int CFG::get_size_for_type(const Type* t) {
  auto builtin = dynamic_cast<const BuiltinType*>(t);
  if (!builtin) {
    return 0;
  }

  switch (builtin->getKind()) {
    case BuiltinType::Kind::CHAR: return 1;
    case BuiltinType::Kind::INT32_T: return 4;
    case BuiltinType::Kind::INT64_T: return 8;
    default: return 0;
  }
}