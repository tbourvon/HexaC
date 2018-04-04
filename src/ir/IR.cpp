#include "IR.h"

IRInstr::IRInstr(BasicBlock* bb_, Operation op_, const Type* t_, vector<string> params_) : bb(bb_), op(op_), t(t_), params(params_) {

}

bool IRInstr::isLastInstruction()
{
  return this == bb->instrs.back();
}

string IRInstr::suffix_for_size(int size) {
  switch (size) {
    case 1: return "b";
    case 4: return "l";
    case 8: return "q";
    default: return to_string(size);
  }
}

const Type* CFG::get_var_type(string name) {
  return SymbolType.at(name);
}

void IRInstr::gen_asm(ostream& out) {
    int indexDest;
    int indexParam1;
    int indexParam2;
    string s = suffix_for_size(bb->cfg->get_size_for_type(t));

    switch(op) {
      case Operation::ldconst :
          indexDest = bb->cfg->get_var_index(params[0]);
          out << "mov" << s << " $" << params[1] << "," << indexDest <<"(%rbp)" << endl;
          break;
      case Operation::add :
      indexDest = bb->cfg->get_var_index(params[0]);
          indexParam1 = bb->cfg->get_var_index(params[1]);
          indexParam2 = bb->cfg->get_var_index(params[2]);

          if (params[1] == "!bp") {
            out << "movq %rbp, %rax" << endl;
          } else {
            out << "movq " << indexParam1 << "(%rbp), %rax" << endl;
          }
          out << "addq " << indexParam2 << "(%rbp), %rax" << endl;
          out << "movq %rax, " << indexDest << "(%rbp)" << endl;
          break;
    case Operation::sub :
      indexDest = bb->cfg->get_var_index(params[0]);
          indexParam1 = bb->cfg->get_var_index(params[1]);
          indexParam2 = bb->cfg->get_var_index(params[2]);
          out << "movq " << indexParam1 << "(%rbp), %rax" << endl;
          out << "subq " << indexParam2 << "(%rbp), %rax" << endl;
          out << "movq %rax, " << indexDest << "(%rbp)" << endl;
          break;
    case Operation::mul :
      indexDest = bb->cfg->get_var_index(params[0]);
          indexParam1 = bb->cfg->get_var_index(params[1]);
          indexParam2 = bb->cfg->get_var_index(params[2]);
          out << "movq " << indexParam1 << "(%rbp), %rax" << endl;
          out << "imulq " << indexParam2 << "(%rbp), %rax" << endl;
          out << "movq %rax, " << indexDest << "(%rbp)" << endl;
          break;
    case Operation::rmem :

      break;
    case Operation::wmem :
      indexDest = bb->cfg->get_var_index(params[0]);
          indexParam1 = bb->cfg->get_var_index(params[1]);
          out << "movq " << indexDest << "(%rbp), %rax" << endl;
          out << "movq " << indexParam1 << "(%rbp), %r10" << endl;
          out << "movq %r10, (%rax)" << endl;
      break;
    case Operation::call : {
      std::string funcToCall = params[1];
      if(funcToCall == "putchar") {
        #ifdef __APPLE__
          funcToCall = "_putchar";
        #endif
      }

      indexDest = bb->cfg->get_var_index(params[0]);
      indexParam1 = bb->cfg->get_var_index(params[1]);
      //indexParam2 = bb->cfg->get_var_index(params[2]);
      //out << "movl " << indexParam2 << "(%rbp), %edi" << endl;

      for (int i = 2; i < params.size(); i++) {
          switch(i-2) {
              case 0: out << "movq " << bb->cfg->get_var_index(params[i]) << "(%rbp), %rdi" << endl; break;
              case 1: out << "movq " << bb->cfg->get_var_index(params[i]) << "(%rbp), %rsi" << endl; break;
              case 2: out << "movq " << bb->cfg->get_var_index(params[i]) << "(%rbp), %rdx" << endl; break;
              case 3: out << "movq " << bb->cfg->get_var_index(params[i]) << "(%rbp), %rcx" << endl; break;
              case 4: out << "movq "  << bb->cfg->get_var_index(params[i]) << "(%rbp), %r8" << endl; break;
              case 5: out << "movq "  << bb->cfg->get_var_index(params[i]) << "(%rbp), %rç" << endl; break;
          }
      }

      out << "movb $0, %al" << endl;
      out << "callq " << funcToCall << endl;
      break;
    }
    case Operation::cmp_eq :
        if(!isLastInstruction())
        {
            indexDest = bb->cfg->get_var_index(params[0]);
            indexParam1 = bb->cfg->get_var_index(params[1]);
            indexParam2 = bb->cfg->get_var_index(params[2]);

        }
        else
        {
            indexDest = bb->cfg->get_var_index(params[0]);
            indexParam1 = bb->cfg->get_var_index(params[1]);
            indexParam2 = bb->cfg->get_var_index(params[2]);
            out << "movq " << indexParam2 << "(%rbp), %rax" << endl;
            out << "cmpq " << indexParam1 << "(%rbp), %rax" << endl;
            out << "jne " << bb->exit_false->label << endl;
        }

      break;
    case Operation::cmp_lt :
        if(!isLastInstruction())
        {
            indexDest = bb->cfg->get_var_index(params[0]);
            indexParam1 = bb->cfg->get_var_index(params[1]);
            indexParam2 = bb->cfg->get_var_index(params[2]);

        }
        else
        {
            indexDest = bb->cfg->get_var_index(params[0]);
            indexParam1 = bb->cfg->get_var_index(params[1]);
            indexParam2 = bb->cfg->get_var_index(params[2]);
            out << "movq " << indexParam2 << "(%rbp), %rax" << endl;
            out << "cmpq " << "%rax, " << indexParam1 << "(%rbp)" << endl;
            out << "jge " << bb->exit_false->label << endl;
        }


      break;
    case Operation::cmp_le :
      break;
  }
}

void BasicBlock::gen_asm(ostream& out) {
  #ifdef __APPLE__
    if(label == "main"){
      out << endl << "_main" << ":" << endl;
    } else {
      out << endl << label << ":" << endl;
    }
  #else
    out << endl << label << ":" << endl;
  #endif

  if (label == cfg->ast->getName()) {
    cfg->gen_asm_prologue(out);
  }

  for (auto instr : instrs) {
    instr->gen_asm(out);
  }

  if (exit_true) {
    out << "jmp " << exit_true->label << endl;
  } else if (!exit_false) {
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

  SymbolType["!bp"] = new BuiltinType(BuiltinType::Kind::VOID);
  SymbolIndex["!bp"] = 0;

  SymbolType["putchar"] = new BuiltinType(BuiltinType::Kind::VOID);
  SymbolIndex["putchar"] = 0;
}

std::string CFG::new_BB_name() {
  //return "bb" + std::to_string(nextBBnumber++);
  return ast->getName() + "_bb" + std::to_string(nextBBnumber++);
}

int CFG::get_var_index(string name) {
  return SymbolIndex.at(name);
}

void CFG::add_bb(BasicBlock *bb) {
  bbs.push_back(bb);
}

std::string CFG::create_new_tempvar(const Type* t) {
  nextFreeSymbolIndex -= get_size_for_type(t);

  std::string name = "!tmp" + std::to_string(-nextFreeSymbolIndex);
  if (get_size_for_type(t) == 0) {
    int i = 1;
    while (SymbolType.count(name + "_" + to_string(i))) {
      i++;
    }
    name = name + "_" + to_string(i);
  }

  SymbolType[name] = t;
  SymbolIndex[name] = nextFreeSymbolIndex;

  return name;
}

void CFG::add_to_symbol_table(string name, const Type* t) {
  nextFreeSymbolIndex -= get_size_for_type(t);

  SymbolType[name] = t;
  SymbolIndex[name] = nextFreeSymbolIndex;
}

void CFG::gen_asm(ostream& out) {
  for (auto bb : bbs) {
    bb->gen_asm(out);
  }
}

void CFG::gen_asm_prologue(ostream& out) {
  int size = 0;
  for (const auto& symbol_pair : SymbolType) {
    size += get_size_for_type(symbol_pair.second);
  }

  size += 16 - (size % 16); // align to 16 bytes.

  out << "pushq  %rbp" << endl;
  out << "movq  %rsp, %rbp" << endl;
  out << "subq  $" << size << ", %rsp" << endl;
  out << endl;
}

void CFG::gen_asm_epilogue(ostream& out) {
  out << endl;
  out << "leave" << endl;
  out << "ret" << endl;
}

int CFG::get_size_for_type(const Type* t) {
  auto builtin = dynamic_cast<const BuiltinType*>(t);
  if (!builtin) {
    return 0;
  }

  switch (builtin->getKind()) {
    case BuiltinType::Kind::CHAR: return 8;
    case BuiltinType::Kind::INT32_T: return 8;
    case BuiltinType::Kind::INT64_T: return 8;
    case BuiltinType::Kind::VOID: return 0;
  }
}
