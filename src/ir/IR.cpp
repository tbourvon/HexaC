#include "IR.h"

IRInstr::IRInstr(BasicBlock* bb_, Operation op, Type* t, vector<string> params) {

}

bool IRInstr::isLastInstruction()
{
  return this == bb->instrs.back();
}

void IRInstr::gen_asm(ostream& out) {
    int indexDest;
    int indexParam1;
    int indexParam2;

    switch(op) {
      case Operation::ldconst :
          indexDest = bb->cfg->get_var_index(params[0]);
          out << "movq $" << params[1] << "," << indexDest <<"(%rbp)";
          break;
      case Operation::add :
      indexDest = bb->cfg->get_var_index(params[0]);
          indexParam1 = bb->cfg->get_var_index(params[1]);
          indexParam2 = bb->cfg->get_var_index(params[2]);
          out << "movq " << indexParam1 << "(%rbp), %rax";
          out << "addq " << indexParam2 << "(%rbp), %rax";
          out << "movq %rax, " << indexDest << "(%rbp)";
          break;
    case Operation::sub :
      indexDest = bb->cfg->get_var_index(params[0]);
          indexParam1 = bb->cfg->get_var_index(params[1]);
          indexParam2 = bb->cfg->get_var_index(params[2]);
          out << "movq " << indexParam1 << "(%rbp), %rax";
          out << "subq " << indexParam2 << "(%rbp), %rax";
          out << "movq %rax, " << indexDest << "(%rbp)";
          break;
    case Operation::mul :
      indexDest = bb->cfg->get_var_index(params[0]);
          indexParam1 = bb->cfg->get_var_index(params[1]);
          indexParam2 = bb->cfg->get_var_index(params[2]);
          out << "movq " << indexParam1 << "(%rbp)";
          out << "multq " << indexParam2 << "(%rbp), %rax";
          out << "movq %rax, " << indexDest << "(%rbp)";
          break;
    case Operation::rmem :

      break;
    case Operation::wmem :
      break;
    case Operation::call :
      break;
    case Operation::cmp_eq :
        if(!isLastInstruction())
        {
            indexDest = bb->cfg->get_var_index(params[0]);
            indexParam1 = bb->cfg->get_var_index(params[1]);
            indexParam2 = bb->cfg->get_var_index(params[2]);

        }
        else
        {

        }

      break;
    case Operation::cmp_lt :
      break;
    case Operation::cmp_le :
      break;
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
