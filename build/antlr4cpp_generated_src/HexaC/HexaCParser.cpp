
// Generated from /Users/tbourvon/Drive/Projects/Programming/HexaC/grammar/HexaCParser.g4 by ANTLR 4.7.1


#include "HexaCParserListener.h"
#include "HexaCParserVisitor.h"

#include "HexaCParser.h"


using namespace antlrcpp;
using namespace HexaC;
using namespace antlr4;

HexaCParser::HexaCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

HexaCParser::~HexaCParser() {
  delete _interpreter;
}

std::string HexaCParser::getGrammarFileName() const {
  return "HexaCParser.g4";
}

const std::vector<std::string>& HexaCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& HexaCParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

HexaCParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HexaCParser::Toplevel_itemContext *> HexaCParser::ProgramContext::toplevel_item() {
  return getRuleContexts<HexaCParser::Toplevel_itemContext>();
}

HexaCParser::Toplevel_itemContext* HexaCParser::ProgramContext::toplevel_item(size_t i) {
  return getRuleContext<HexaCParser::Toplevel_itemContext>(i);
}


size_t HexaCParser::ProgramContext::getRuleIndex() const {
  return HexaCParser::RuleProgram;
}

void HexaCParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void HexaCParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any HexaCParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::ProgramContext* HexaCParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, HexaCParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << HexaCParser::INT32_T)
      | (1ULL << HexaCParser::INT64_T)
      | (1ULL << HexaCParser::CHAR)
      | (1ULL << HexaCParser::VOID)
      | (1ULL << HexaCParser::HASH))) != 0)) {
      setState(42);
      toplevel_item();
      setState(47);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Toplevel_itemContext ------------------------------------------------------------------

HexaCParser::Toplevel_itemContext::Toplevel_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HexaCParser::Preproc_dirContext* HexaCParser::Toplevel_itemContext::preproc_dir() {
  return getRuleContext<HexaCParser::Preproc_dirContext>(0);
}

HexaCParser::DeclContext* HexaCParser::Toplevel_itemContext::decl() {
  return getRuleContext<HexaCParser::DeclContext>(0);
}


size_t HexaCParser::Toplevel_itemContext::getRuleIndex() const {
  return HexaCParser::RuleToplevel_item;
}

void HexaCParser::Toplevel_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToplevel_item(this);
}

void HexaCParser::Toplevel_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToplevel_item(this);
}


antlrcpp::Any HexaCParser::Toplevel_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitToplevel_item(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Toplevel_itemContext* HexaCParser::toplevel_item() {
  Toplevel_itemContext *_localctx = _tracker.createInstance<Toplevel_itemContext>(_ctx, getState());
  enterRule(_localctx, 2, HexaCParser::RuleToplevel_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HexaCParser::HASH: {
        enterOuterAlt(_localctx, 1);
        setState(48);
        preproc_dir();
        break;
      }

      case HexaCParser::INT32_T:
      case HexaCParser::INT64_T:
      case HexaCParser::CHAR:
      case HexaCParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(49);
        decl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Preproc_dirContext ------------------------------------------------------------------

HexaCParser::Preproc_dirContext::Preproc_dirContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HexaCParser::Preproc_dirContext::HASH() {
  return getToken(HexaCParser::HASH, 0);
}

tree::TerminalNode* HexaCParser::Preproc_dirContext::INCLUDE() {
  return getToken(HexaCParser::INCLUDE, 0);
}

tree::TerminalNode* HexaCParser::Preproc_dirContext::LT() {
  return getToken(HexaCParser::LT, 0);
}

std::vector<tree::TerminalNode *> HexaCParser::Preproc_dirContext::ID() {
  return getTokens(HexaCParser::ID);
}

tree::TerminalNode* HexaCParser::Preproc_dirContext::ID(size_t i) {
  return getToken(HexaCParser::ID, i);
}

tree::TerminalNode* HexaCParser::Preproc_dirContext::DOT() {
  return getToken(HexaCParser::DOT, 0);
}

tree::TerminalNode* HexaCParser::Preproc_dirContext::GT() {
  return getToken(HexaCParser::GT, 0);
}


size_t HexaCParser::Preproc_dirContext::getRuleIndex() const {
  return HexaCParser::RulePreproc_dir;
}

void HexaCParser::Preproc_dirContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreproc_dir(this);
}

void HexaCParser::Preproc_dirContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreproc_dir(this);
}


antlrcpp::Any HexaCParser::Preproc_dirContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitPreproc_dir(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Preproc_dirContext* HexaCParser::preproc_dir() {
  Preproc_dirContext *_localctx = _tracker.createInstance<Preproc_dirContext>(_ctx, getState());
  enterRule(_localctx, 4, HexaCParser::RulePreproc_dir);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(HexaCParser::HASH);
    setState(53);
    match(HexaCParser::INCLUDE);
    setState(54);
    match(HexaCParser::LT);
    setState(55);
    match(HexaCParser::ID);
    setState(56);
    match(HexaCParser::DOT);
    setState(57);
    match(HexaCParser::ID);
    setState(58);
    match(HexaCParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

HexaCParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HexaCParser::Func_declContext* HexaCParser::DeclContext::func_decl() {
  return getRuleContext<HexaCParser::Func_declContext>(0);
}

HexaCParser::Var_declContext* HexaCParser::DeclContext::var_decl() {
  return getRuleContext<HexaCParser::Var_declContext>(0);
}


size_t HexaCParser::DeclContext::getRuleIndex() const {
  return HexaCParser::RuleDecl;
}

void HexaCParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void HexaCParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


antlrcpp::Any HexaCParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::DeclContext* HexaCParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 6, HexaCParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(60);
      func_decl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(61);
      var_decl();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declContext ------------------------------------------------------------------

HexaCParser::Func_declContext::Func_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HexaCParser::TypeContext* HexaCParser::Func_declContext::type() {
  return getRuleContext<HexaCParser::TypeContext>(0);
}

tree::TerminalNode* HexaCParser::Func_declContext::ID() {
  return getToken(HexaCParser::ID, 0);
}

tree::TerminalNode* HexaCParser::Func_declContext::OPEN_PAR() {
  return getToken(HexaCParser::OPEN_PAR, 0);
}

HexaCParser::Param_listContext* HexaCParser::Func_declContext::param_list() {
  return getRuleContext<HexaCParser::Param_listContext>(0);
}

tree::TerminalNode* HexaCParser::Func_declContext::CLOSE_PAR() {
  return getToken(HexaCParser::CLOSE_PAR, 0);
}

HexaCParser::BlockContext* HexaCParser::Func_declContext::block() {
  return getRuleContext<HexaCParser::BlockContext>(0);
}


size_t HexaCParser::Func_declContext::getRuleIndex() const {
  return HexaCParser::RuleFunc_decl;
}

void HexaCParser::Func_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_decl(this);
}

void HexaCParser::Func_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_decl(this);
}


antlrcpp::Any HexaCParser::Func_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitFunc_decl(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Func_declContext* HexaCParser::func_decl() {
  Func_declContext *_localctx = _tracker.createInstance<Func_declContext>(_ctx, getState());
  enterRule(_localctx, 8, HexaCParser::RuleFunc_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    type();
    setState(65);
    match(HexaCParser::ID);
    setState(66);
    match(HexaCParser::OPEN_PAR);
    setState(67);
    param_list();
    setState(68);
    match(HexaCParser::CLOSE_PAR);
    setState(69);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

HexaCParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HexaCParser::TypeContext::INT32_T() {
  return getToken(HexaCParser::INT32_T, 0);
}

tree::TerminalNode* HexaCParser::TypeContext::INT64_T() {
  return getToken(HexaCParser::INT64_T, 0);
}

tree::TerminalNode* HexaCParser::TypeContext::CHAR() {
  return getToken(HexaCParser::CHAR, 0);
}

tree::TerminalNode* HexaCParser::TypeContext::VOID() {
  return getToken(HexaCParser::VOID, 0);
}


size_t HexaCParser::TypeContext::getRuleIndex() const {
  return HexaCParser::RuleType;
}

void HexaCParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void HexaCParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any HexaCParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::TypeContext* HexaCParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 10, HexaCParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << HexaCParser::INT32_T)
      | (1ULL << HexaCParser::INT64_T)
      | (1ULL << HexaCParser::CHAR)
      | (1ULL << HexaCParser::VOID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Param_listContext ------------------------------------------------------------------

HexaCParser::Param_listContext::Param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HexaCParser::ParamContext *> HexaCParser::Param_listContext::param() {
  return getRuleContexts<HexaCParser::ParamContext>();
}

HexaCParser::ParamContext* HexaCParser::Param_listContext::param(size_t i) {
  return getRuleContext<HexaCParser::ParamContext>(i);
}

std::vector<tree::TerminalNode *> HexaCParser::Param_listContext::COMMA() {
  return getTokens(HexaCParser::COMMA);
}

tree::TerminalNode* HexaCParser::Param_listContext::COMMA(size_t i) {
  return getToken(HexaCParser::COMMA, i);
}


size_t HexaCParser::Param_listContext::getRuleIndex() const {
  return HexaCParser::RuleParam_list;
}

void HexaCParser::Param_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam_list(this);
}

void HexaCParser::Param_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam_list(this);
}


antlrcpp::Any HexaCParser::Param_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitParam_list(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Param_listContext* HexaCParser::param_list() {
  Param_listContext *_localctx = _tracker.createInstance<Param_listContext>(_ctx, getState());
  enterRule(_localctx, 12, HexaCParser::RuleParam_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(82);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HexaCParser::INT32_T:
      case HexaCParser::INT64_T:
      case HexaCParser::CHAR:
      case HexaCParser::VOID: {
        enterOuterAlt(_localctx, 1);
        setState(73);
        param();
        setState(78);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == HexaCParser::COMMA) {
          setState(74);
          match(HexaCParser::COMMA);
          setState(75);
          param();
          setState(80);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case HexaCParser::CLOSE_PAR: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

HexaCParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HexaCParser::TypeContext* HexaCParser::ParamContext::type() {
  return getRuleContext<HexaCParser::TypeContext>(0);
}

tree::TerminalNode* HexaCParser::ParamContext::ID() {
  return getToken(HexaCParser::ID, 0);
}


size_t HexaCParser::ParamContext::getRuleIndex() const {
  return HexaCParser::RuleParam;
}

void HexaCParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void HexaCParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}


antlrcpp::Any HexaCParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::ParamContext* HexaCParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 14, HexaCParser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    type();
    setState(85);
    match(HexaCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

HexaCParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HexaCParser::BlockContext::OPEN_BRACE() {
  return getToken(HexaCParser::OPEN_BRACE, 0);
}

HexaCParser::Stmt_listContext* HexaCParser::BlockContext::stmt_list() {
  return getRuleContext<HexaCParser::Stmt_listContext>(0);
}

tree::TerminalNode* HexaCParser::BlockContext::CLOSE_BRACE() {
  return getToken(HexaCParser::CLOSE_BRACE, 0);
}


size_t HexaCParser::BlockContext::getRuleIndex() const {
  return HexaCParser::RuleBlock;
}

void HexaCParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void HexaCParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any HexaCParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::BlockContext* HexaCParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 16, HexaCParser::RuleBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(HexaCParser::OPEN_BRACE);
    setState(88);
    stmt_list();
    setState(89);
    match(HexaCParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stmt_listContext ------------------------------------------------------------------

HexaCParser::Stmt_listContext::Stmt_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HexaCParser::StmtContext *> HexaCParser::Stmt_listContext::stmt() {
  return getRuleContexts<HexaCParser::StmtContext>();
}

HexaCParser::StmtContext* HexaCParser::Stmt_listContext::stmt(size_t i) {
  return getRuleContext<HexaCParser::StmtContext>(i);
}


size_t HexaCParser::Stmt_listContext::getRuleIndex() const {
  return HexaCParser::RuleStmt_list;
}

void HexaCParser::Stmt_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_list(this);
}

void HexaCParser::Stmt_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_list(this);
}


antlrcpp::Any HexaCParser::Stmt_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitStmt_list(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Stmt_listContext* HexaCParser::stmt_list() {
  Stmt_listContext *_localctx = _tracker.createInstance<Stmt_listContext>(_ctx, getState());
  enterRule(_localctx, 18, HexaCParser::RuleStmt_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << HexaCParser::ID)
      | (1ULL << HexaCParser::IF)
      | (1ULL << HexaCParser::WHILE)
      | (1ULL << HexaCParser::INT32_T)
      | (1ULL << HexaCParser::INT64_T)
      | (1ULL << HexaCParser::CHAR)
      | (1ULL << HexaCParser::VOID)
      | (1ULL << HexaCParser::INT_LIT)
      | (1ULL << HexaCParser::CHAR_LIT)
      | (1ULL << HexaCParser::OPEN_PAR)
      | (1ULL << HexaCParser::OPEN_BRACE)
      | (1ULL << HexaCParser::PLUS)
      | (1ULL << HexaCParser::MINUS)
      | (1ULL << HexaCParser::NOT)
      | (1ULL << HexaCParser::PLUS_PLUS)
      | (1ULL << HexaCParser::MINUS_MINUS))) != 0)) {
      setState(91);
      stmt();
      setState(96);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

HexaCParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HexaCParser::Var_declContext* HexaCParser::StmtContext::var_decl() {
  return getRuleContext<HexaCParser::Var_declContext>(0);
}

HexaCParser::Expr_stmtContext* HexaCParser::StmtContext::expr_stmt() {
  return getRuleContext<HexaCParser::Expr_stmtContext>(0);
}

HexaCParser::If_stmtContext* HexaCParser::StmtContext::if_stmt() {
  return getRuleContext<HexaCParser::If_stmtContext>(0);
}

HexaCParser::While_stmtContext* HexaCParser::StmtContext::while_stmt() {
  return getRuleContext<HexaCParser::While_stmtContext>(0);
}

HexaCParser::BlockContext* HexaCParser::StmtContext::block() {
  return getRuleContext<HexaCParser::BlockContext>(0);
}


size_t HexaCParser::StmtContext::getRuleIndex() const {
  return HexaCParser::RuleStmt;
}

void HexaCParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void HexaCParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any HexaCParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::StmtContext* HexaCParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 20, HexaCParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HexaCParser::INT32_T:
      case HexaCParser::INT64_T:
      case HexaCParser::CHAR:
      case HexaCParser::VOID: {
        enterOuterAlt(_localctx, 1);
        setState(97);
        var_decl();
        break;
      }

      case HexaCParser::ID:
      case HexaCParser::INT_LIT:
      case HexaCParser::CHAR_LIT:
      case HexaCParser::OPEN_PAR:
      case HexaCParser::PLUS:
      case HexaCParser::MINUS:
      case HexaCParser::NOT:
      case HexaCParser::PLUS_PLUS:
      case HexaCParser::MINUS_MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(98);
        expr_stmt();
        break;
      }

      case HexaCParser::IF: {
        enterOuterAlt(_localctx, 3);
        setState(99);
        if_stmt();
        break;
      }

      case HexaCParser::WHILE: {
        enterOuterAlt(_localctx, 4);
        setState(100);
        while_stmt();
        break;
      }

      case HexaCParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 5);
        setState(101);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declContext ------------------------------------------------------------------

HexaCParser::Var_declContext::Var_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HexaCParser::TypeContext* HexaCParser::Var_declContext::type() {
  return getRuleContext<HexaCParser::TypeContext>(0);
}

tree::TerminalNode* HexaCParser::Var_declContext::ID() {
  return getToken(HexaCParser::ID, 0);
}

tree::TerminalNode* HexaCParser::Var_declContext::SEMICOLON() {
  return getToken(HexaCParser::SEMICOLON, 0);
}


size_t HexaCParser::Var_declContext::getRuleIndex() const {
  return HexaCParser::RuleVar_decl;
}

void HexaCParser::Var_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_decl(this);
}

void HexaCParser::Var_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_decl(this);
}


antlrcpp::Any HexaCParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Var_declContext* HexaCParser::var_decl() {
  Var_declContext *_localctx = _tracker.createInstance<Var_declContext>(_ctx, getState());
  enterRule(_localctx, 22, HexaCParser::RuleVar_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    type();
    setState(105);
    match(HexaCParser::ID);
    setState(106);
    match(HexaCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_stmtContext ------------------------------------------------------------------

HexaCParser::Expr_stmtContext::Expr_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HexaCParser::ExprContext* HexaCParser::Expr_stmtContext::expr() {
  return getRuleContext<HexaCParser::ExprContext>(0);
}

tree::TerminalNode* HexaCParser::Expr_stmtContext::SEMICOLON() {
  return getToken(HexaCParser::SEMICOLON, 0);
}


size_t HexaCParser::Expr_stmtContext::getRuleIndex() const {
  return HexaCParser::RuleExpr_stmt;
}

void HexaCParser::Expr_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_stmt(this);
}

void HexaCParser::Expr_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_stmt(this);
}


antlrcpp::Any HexaCParser::Expr_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitExpr_stmt(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Expr_stmtContext* HexaCParser::expr_stmt() {
  Expr_stmtContext *_localctx = _tracker.createInstance<Expr_stmtContext>(_ctx, getState());
  enterRule(_localctx, 24, HexaCParser::RuleExpr_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    expr();
    setState(109);
    match(HexaCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

HexaCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HexaCParser::Binary_opContext* HexaCParser::ExprContext::binary_op() {
  return getRuleContext<HexaCParser::Binary_opContext>(0);
}


size_t HexaCParser::ExprContext::getRuleIndex() const {
  return HexaCParser::RuleExpr;
}

void HexaCParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void HexaCParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any HexaCParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::ExprContext* HexaCParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 26, HexaCParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    binary_op();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_litContext ------------------------------------------------------------------

HexaCParser::Expr_litContext::Expr_litContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HexaCParser::Expr_litContext::INT_LIT() {
  return getToken(HexaCParser::INT_LIT, 0);
}

tree::TerminalNode* HexaCParser::Expr_litContext::CHAR_LIT() {
  return getToken(HexaCParser::CHAR_LIT, 0);
}


size_t HexaCParser::Expr_litContext::getRuleIndex() const {
  return HexaCParser::RuleExpr_lit;
}

void HexaCParser::Expr_litContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_lit(this);
}

void HexaCParser::Expr_litContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_lit(this);
}


antlrcpp::Any HexaCParser::Expr_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitExpr_lit(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Expr_litContext* HexaCParser::expr_lit() {
  Expr_litContext *_localctx = _tracker.createInstance<Expr_litContext>(_ctx, getState());
  enterRule(_localctx, 28, HexaCParser::RuleExpr_lit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    _la = _input->LA(1);
    if (!(_la == HexaCParser::INT_LIT

    || _la == HexaCParser::CHAR_LIT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Call_expr_Context ------------------------------------------------------------------

HexaCParser::Call_expr_Context::Call_expr_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HexaCParser::Call_expr_Context::ID() {
  return getToken(HexaCParser::ID, 0);
}

tree::TerminalNode* HexaCParser::Call_expr_Context::OPEN_PAR() {
  return getToken(HexaCParser::OPEN_PAR, 0);
}

HexaCParser::Arg_listContext* HexaCParser::Call_expr_Context::arg_list() {
  return getRuleContext<HexaCParser::Arg_listContext>(0);
}

tree::TerminalNode* HexaCParser::Call_expr_Context::CLOSE_PAR() {
  return getToken(HexaCParser::CLOSE_PAR, 0);
}

HexaCParser::Expr_litContext* HexaCParser::Call_expr_Context::expr_lit() {
  return getRuleContext<HexaCParser::Expr_litContext>(0);
}


size_t HexaCParser::Call_expr_Context::getRuleIndex() const {
  return HexaCParser::RuleCall_expr_;
}

void HexaCParser::Call_expr_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall_expr_(this);
}

void HexaCParser::Call_expr_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall_expr_(this);
}


antlrcpp::Any HexaCParser::Call_expr_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitCall_expr_(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Call_expr_Context* HexaCParser::call_expr_() {
  Call_expr_Context *_localctx = _tracker.createInstance<Call_expr_Context>(_ctx, getState());
  enterRule(_localctx, 30, HexaCParser::RuleCall_expr_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HexaCParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(115);
        match(HexaCParser::ID);
        setState(116);
        match(HexaCParser::OPEN_PAR);
        setState(117);
        arg_list();
        setState(118);
        match(HexaCParser::CLOSE_PAR);
        break;
      }

      case HexaCParser::INT_LIT:
      case HexaCParser::CHAR_LIT: {
        enterOuterAlt(_localctx, 2);
        setState(120);
        expr_lit();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arg_listContext ------------------------------------------------------------------

HexaCParser::Arg_listContext::Arg_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HexaCParser::ExprContext *> HexaCParser::Arg_listContext::expr() {
  return getRuleContexts<HexaCParser::ExprContext>();
}

HexaCParser::ExprContext* HexaCParser::Arg_listContext::expr(size_t i) {
  return getRuleContext<HexaCParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> HexaCParser::Arg_listContext::COMMA() {
  return getTokens(HexaCParser::COMMA);
}

tree::TerminalNode* HexaCParser::Arg_listContext::COMMA(size_t i) {
  return getToken(HexaCParser::COMMA, i);
}


size_t HexaCParser::Arg_listContext::getRuleIndex() const {
  return HexaCParser::RuleArg_list;
}

void HexaCParser::Arg_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg_list(this);
}

void HexaCParser::Arg_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg_list(this);
}


antlrcpp::Any HexaCParser::Arg_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitArg_list(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Arg_listContext* HexaCParser::arg_list() {
  Arg_listContext *_localctx = _tracker.createInstance<Arg_listContext>(_ctx, getState());
  enterRule(_localctx, 32, HexaCParser::RuleArg_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HexaCParser::ID:
      case HexaCParser::INT_LIT:
      case HexaCParser::CHAR_LIT:
      case HexaCParser::OPEN_PAR:
      case HexaCParser::PLUS:
      case HexaCParser::MINUS:
      case HexaCParser::NOT:
      case HexaCParser::PLUS_PLUS:
      case HexaCParser::MINUS_MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(123);
        expr();
        setState(128);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == HexaCParser::COMMA) {
          setState(124);
          match(HexaCParser::COMMA);
          setState(125);
          expr();
          setState(130);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case HexaCParser::CLOSE_PAR: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_opContext ------------------------------------------------------------------

HexaCParser::Unary_opContext::Unary_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HexaCParser::Unary_opContext::OPEN_PAR() {
  return getToken(HexaCParser::OPEN_PAR, 0);
}

HexaCParser::Unary_opContext* HexaCParser::Unary_opContext::unary_op() {
  return getRuleContext<HexaCParser::Unary_opContext>(0);
}

tree::TerminalNode* HexaCParser::Unary_opContext::CLOSE_PAR() {
  return getToken(HexaCParser::CLOSE_PAR, 0);
}

tree::TerminalNode* HexaCParser::Unary_opContext::PLUS() {
  return getToken(HexaCParser::PLUS, 0);
}

tree::TerminalNode* HexaCParser::Unary_opContext::MINUS() {
  return getToken(HexaCParser::MINUS, 0);
}

tree::TerminalNode* HexaCParser::Unary_opContext::PLUS_PLUS() {
  return getToken(HexaCParser::PLUS_PLUS, 0);
}

tree::TerminalNode* HexaCParser::Unary_opContext::MINUS_MINUS() {
  return getToken(HexaCParser::MINUS_MINUS, 0);
}

tree::TerminalNode* HexaCParser::Unary_opContext::NOT() {
  return getToken(HexaCParser::NOT, 0);
}

HexaCParser::Call_expr_Context* HexaCParser::Unary_opContext::call_expr_() {
  return getRuleContext<HexaCParser::Call_expr_Context>(0);
}


size_t HexaCParser::Unary_opContext::getRuleIndex() const {
  return HexaCParser::RuleUnary_op;
}

void HexaCParser::Unary_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_op(this);
}

void HexaCParser::Unary_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_op(this);
}


antlrcpp::Any HexaCParser::Unary_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitUnary_op(this);
  else
    return visitor->visitChildren(this);
}


HexaCParser::Unary_opContext* HexaCParser::unary_op() {
   return unary_op(0);
}

HexaCParser::Unary_opContext* HexaCParser::unary_op(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  HexaCParser::Unary_opContext *_localctx = _tracker.createInstance<Unary_opContext>(_ctx, parentState);
  HexaCParser::Unary_opContext *previousContext = _localctx;
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, HexaCParser::RuleUnary_op, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(150);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HexaCParser::OPEN_PAR: {
        setState(135);
        match(HexaCParser::OPEN_PAR);
        setState(136);
        unary_op(0);
        setState(137);
        match(HexaCParser::CLOSE_PAR);
        break;
      }

      case HexaCParser::PLUS: {
        setState(139);
        match(HexaCParser::PLUS);
        setState(140);
        unary_op(8);
        break;
      }

      case HexaCParser::MINUS: {
        setState(141);
        match(HexaCParser::MINUS);
        setState(142);
        unary_op(7);
        break;
      }

      case HexaCParser::PLUS_PLUS: {
        setState(143);
        match(HexaCParser::PLUS_PLUS);
        setState(144);
        unary_op(6);
        break;
      }

      case HexaCParser::MINUS_MINUS: {
        setState(145);
        match(HexaCParser::MINUS_MINUS);
        setState(146);
        unary_op(5);
        break;
      }

      case HexaCParser::NOT: {
        setState(147);
        match(HexaCParser::NOT);
        setState(148);
        unary_op(4);
        break;
      }

      case HexaCParser::ID:
      case HexaCParser::INT_LIT:
      case HexaCParser::CHAR_LIT: {
        setState(149);
        call_expr_();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(158);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(156);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Unary_opContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleUnary_op);
          setState(152);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(153);
          match(HexaCParser::PLUS_PLUS);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Unary_opContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleUnary_op);
          setState(154);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(155);
          match(HexaCParser::MINUS_MINUS);
          break;
        }

        } 
      }
      setState(160);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Binary_opContext ------------------------------------------------------------------

HexaCParser::Binary_opContext::Binary_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HexaCParser::Unary_opContext* HexaCParser::Binary_opContext::unary_op() {
  return getRuleContext<HexaCParser::Unary_opContext>(0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::STAR() {
  return getToken(HexaCParser::STAR, 0);
}

HexaCParser::Binary_opContext* HexaCParser::Binary_opContext::binary_op() {
  return getRuleContext<HexaCParser::Binary_opContext>(0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::DIV() {
  return getToken(HexaCParser::DIV, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::MOD() {
  return getToken(HexaCParser::MOD, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::PLUS() {
  return getToken(HexaCParser::PLUS, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::MINUS() {
  return getToken(HexaCParser::MINUS, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::EQ() {
  return getToken(HexaCParser::EQ, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::STAR_EQ() {
  return getToken(HexaCParser::STAR_EQ, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::DIV_EQ() {
  return getToken(HexaCParser::DIV_EQ, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::MOD_EQ() {
  return getToken(HexaCParser::MOD_EQ, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::PLUS_EQ() {
  return getToken(HexaCParser::PLUS_EQ, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::MINUS_EQ() {
  return getToken(HexaCParser::MINUS_EQ, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::AND_AND() {
  return getToken(HexaCParser::AND_AND, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::OR_OR() {
  return getToken(HexaCParser::OR_OR, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::EQ_EQ() {
  return getToken(HexaCParser::EQ_EQ, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::NOT_EQ() {
  return getToken(HexaCParser::NOT_EQ, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::GT() {
  return getToken(HexaCParser::GT, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::LT() {
  return getToken(HexaCParser::LT, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::GE() {
  return getToken(HexaCParser::GE, 0);
}

tree::TerminalNode* HexaCParser::Binary_opContext::LE() {
  return getToken(HexaCParser::LE, 0);
}


size_t HexaCParser::Binary_opContext::getRuleIndex() const {
  return HexaCParser::RuleBinary_op;
}

void HexaCParser::Binary_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_op(this);
}

void HexaCParser::Binary_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_op(this);
}


antlrcpp::Any HexaCParser::Binary_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitBinary_op(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::Binary_opContext* HexaCParser::binary_op() {
  Binary_opContext *_localctx = _tracker.createInstance<Binary_opContext>(_ctx, getState());
  enterRule(_localctx, 36, HexaCParser::RuleBinary_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(238);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(161);
      unary_op(0);
      setState(162);
      match(HexaCParser::STAR);
      setState(163);
      binary_op();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(165);
      unary_op(0);
      setState(166);
      match(HexaCParser::DIV);
      setState(167);
      binary_op();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(169);
      unary_op(0);
      setState(170);
      match(HexaCParser::MOD);
      setState(171);
      binary_op();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(173);
      unary_op(0);
      setState(174);
      match(HexaCParser::PLUS);
      setState(175);
      binary_op();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(177);
      unary_op(0);
      setState(178);
      match(HexaCParser::MINUS);
      setState(179);
      binary_op();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(181);
      unary_op(0);
      setState(182);
      match(HexaCParser::EQ);
      setState(183);
      binary_op();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(185);
      unary_op(0);
      setState(186);
      match(HexaCParser::STAR_EQ);
      setState(187);
      binary_op();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(189);
      unary_op(0);
      setState(190);
      match(HexaCParser::DIV_EQ);
      setState(191);
      binary_op();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(193);
      unary_op(0);
      setState(194);
      match(HexaCParser::MOD_EQ);
      setState(195);
      binary_op();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(197);
      unary_op(0);
      setState(198);
      match(HexaCParser::PLUS_EQ);
      setState(199);
      binary_op();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(201);
      unary_op(0);
      setState(202);
      match(HexaCParser::MINUS_EQ);
      setState(203);
      binary_op();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(205);
      unary_op(0);
      setState(206);
      match(HexaCParser::AND_AND);
      setState(207);
      binary_op();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(209);
      unary_op(0);
      setState(210);
      match(HexaCParser::OR_OR);
      setState(211);
      binary_op();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(213);
      unary_op(0);
      setState(214);
      match(HexaCParser::EQ_EQ);
      setState(215);
      binary_op();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(217);
      unary_op(0);
      setState(218);
      match(HexaCParser::NOT_EQ);
      setState(219);
      binary_op();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(221);
      unary_op(0);
      setState(222);
      match(HexaCParser::GT);
      setState(223);
      binary_op();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(225);
      unary_op(0);
      setState(226);
      match(HexaCParser::LT);
      setState(227);
      binary_op();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(229);
      unary_op(0);
      setState(230);
      match(HexaCParser::GE);
      setState(231);
      binary_op();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(233);
      unary_op(0);
      setState(234);
      match(HexaCParser::LE);
      setState(235);
      binary_op();
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(237);
      unary_op(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_stmtContext ------------------------------------------------------------------

HexaCParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HexaCParser::If_stmtContext::IF() {
  return getToken(HexaCParser::IF, 0);
}

tree::TerminalNode* HexaCParser::If_stmtContext::OPEN_PAR() {
  return getToken(HexaCParser::OPEN_PAR, 0);
}

HexaCParser::ExprContext* HexaCParser::If_stmtContext::expr() {
  return getRuleContext<HexaCParser::ExprContext>(0);
}

tree::TerminalNode* HexaCParser::If_stmtContext::CLOSE_PAR() {
  return getToken(HexaCParser::CLOSE_PAR, 0);
}

std::vector<HexaCParser::StmtContext *> HexaCParser::If_stmtContext::stmt() {
  return getRuleContexts<HexaCParser::StmtContext>();
}

HexaCParser::StmtContext* HexaCParser::If_stmtContext::stmt(size_t i) {
  return getRuleContext<HexaCParser::StmtContext>(i);
}

tree::TerminalNode* HexaCParser::If_stmtContext::ELSE() {
  return getToken(HexaCParser::ELSE, 0);
}


size_t HexaCParser::If_stmtContext::getRuleIndex() const {
  return HexaCParser::RuleIf_stmt;
}

void HexaCParser::If_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_stmt(this);
}

void HexaCParser::If_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_stmt(this);
}


antlrcpp::Any HexaCParser::If_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitIf_stmt(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::If_stmtContext* HexaCParser::if_stmt() {
  If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
  enterRule(_localctx, 38, HexaCParser::RuleIf_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    match(HexaCParser::IF);
    setState(241);
    match(HexaCParser::OPEN_PAR);
    setState(242);
    expr();
    setState(243);
    match(HexaCParser::CLOSE_PAR);
    setState(244);
    stmt();
    setState(247);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(245);
      match(HexaCParser::ELSE);
      setState(246);
      stmt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_stmtContext ------------------------------------------------------------------

HexaCParser::While_stmtContext::While_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HexaCParser::While_stmtContext::WHILE() {
  return getToken(HexaCParser::WHILE, 0);
}

tree::TerminalNode* HexaCParser::While_stmtContext::OPEN_PAR() {
  return getToken(HexaCParser::OPEN_PAR, 0);
}

HexaCParser::ExprContext* HexaCParser::While_stmtContext::expr() {
  return getRuleContext<HexaCParser::ExprContext>(0);
}

tree::TerminalNode* HexaCParser::While_stmtContext::CLOSE_PAR() {
  return getToken(HexaCParser::CLOSE_PAR, 0);
}

HexaCParser::StmtContext* HexaCParser::While_stmtContext::stmt() {
  return getRuleContext<HexaCParser::StmtContext>(0);
}


size_t HexaCParser::While_stmtContext::getRuleIndex() const {
  return HexaCParser::RuleWhile_stmt;
}

void HexaCParser::While_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_stmt(this);
}

void HexaCParser::While_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HexaCParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_stmt(this);
}


antlrcpp::Any HexaCParser::While_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HexaCParserVisitor*>(visitor))
    return parserVisitor->visitWhile_stmt(this);
  else
    return visitor->visitChildren(this);
}

HexaCParser::While_stmtContext* HexaCParser::while_stmt() {
  While_stmtContext *_localctx = _tracker.createInstance<While_stmtContext>(_ctx, getState());
  enterRule(_localctx, 40, HexaCParser::RuleWhile_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(HexaCParser::WHILE);
    setState(250);
    match(HexaCParser::OPEN_PAR);
    setState(251);
    expr();
    setState(252);
    match(HexaCParser::CLOSE_PAR);
    setState(253);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool HexaCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 17: return unary_opSempred(dynamic_cast<Unary_opContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool HexaCParser::unary_opSempred(Unary_opContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> HexaCParser::_decisionToDFA;
atn::PredictionContextCache HexaCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN HexaCParser::_atn;
std::vector<uint16_t> HexaCParser::_serializedATN;

std::vector<std::string> HexaCParser::_ruleNames = {
  "program", "toplevel_item", "preproc_dir", "decl", "func_decl", "type", 
  "param_list", "param", "block", "stmt_list", "stmt", "var_decl", "expr_stmt", 
  "expr", "expr_lit", "call_expr_", "arg_list", "unary_op", "binary_op", 
  "if_stmt", "while_stmt"
};

std::vector<std::string> HexaCParser::_literalNames = {
  "", "", "'if'", "'else'", "'while'", "'return'", "'int32_t'", "'int64_t'", 
  "'char'", "'void'", "'include'", "", "", "'('", "')'", "'['", "']'", "'{'", 
  "'}'", "';'", "'*'", "'+'", "'/'", "'-'", "'%'", "'='", "'+='", "'-='", 
  "'/='", "'*='", "'%='", "'=='", "'!='", "'>'", "'<'", "'>='", "'<='", 
  "'!'", "'++'", "'--'", "','", "'&&'", "'||'", "'#'", "'.'"
};

std::vector<std::string> HexaCParser::_symbolicNames = {
  "", "ID", "IF", "ELSE", "WHILE", "RETURN", "INT32_T", "INT64_T", "CHAR", 
  "VOID", "INCLUDE", "INT_LIT", "CHAR_LIT", "OPEN_PAR", "CLOSE_PAR", "OPEN_BRACE", 
  "CLOSE_BRACE", "OPEN_BRACKET", "CLOSE_BRACKET", "SEMICOLON", "STAR", "PLUS", 
  "DIV", "MINUS", "MOD", "EQ", "PLUS_EQ", "MINUS_EQ", "DIV_EQ", "STAR_EQ", 
  "MOD_EQ", "EQ_EQ", "NOT_EQ", "GT", "LT", "GE", "LE", "NOT", "PLUS_PLUS", 
  "MINUS_MINUS", "COMMA", "AND_AND", "OR_OR", "HASH", "DOT"
};

dfa::Vocabulary HexaCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> HexaCParser::_tokenNames;

HexaCParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2e, 0x102, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 0x7, 0x2, 0x2e, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x31, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x35, 
    0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x41, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x4f, 0xa, 0x8, 
    0xc, 0x8, 0xe, 0x8, 0x52, 0xb, 0x8, 0x3, 0x8, 0x5, 0x8, 0x55, 0xa, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x7, 0xb, 0x5f, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x62, 0xb, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x69, 0xa, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x7c, 0xa, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x81, 0xa, 0x12, 0xc, 0x12, 
    0xe, 0x12, 0x84, 0xb, 0x12, 0x3, 0x12, 0x5, 0x12, 0x87, 0xa, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x99, 0xa, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x9f, 0xa, 0x13, 0xc, 0x13, 0xe, 
    0x13, 0xa2, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0xf1, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xfa, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x2, 0x3, 0x24, 0x17, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2, 0x4, 0x3, 0x2, 0x8, 0xb, 0x3, 0x2, 0xd, 0xe, 0x2, 0x115, 
    0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x34, 0x3, 0x2, 0x2, 0x2, 0x6, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x40, 0x3, 0x2, 0x2, 0x2, 0xa, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x49, 0x3, 0x2, 0x2, 0x2, 0xe, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x56, 0x3, 0x2, 0x2, 0x2, 0x12, 0x59, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x16, 0x68, 0x3, 0x2, 0x2, 0x2, 0x18, 0x6a, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x73, 0x3, 0x2, 0x2, 0x2, 0x20, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x86, 0x3, 0x2, 0x2, 0x2, 0x24, 0x98, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x28, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2e, 0x5, 0x4, 0x3, 0x2, 0x2d, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x5, 0x6, 
    0x4, 0x2, 0x33, 0x35, 0x5, 0x8, 0x5, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x37, 0x7, 0x2d, 0x2, 0x2, 0x37, 0x38, 0x7, 0xc, 0x2, 0x2, 0x38, 
    0x39, 0x7, 0x24, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x3, 0x2, 0x2, 0x3a, 0x3b, 
    0x7, 0x2e, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x3, 0x2, 0x2, 0x3c, 0x3d, 0x7, 
    0x23, 0x2, 0x2, 0x3d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x5, 0xa, 
    0x6, 0x2, 0x3f, 0x41, 0x5, 0x18, 0xd, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x43, 0x5, 0xc, 0x7, 0x2, 0x43, 0x44, 0x7, 0x3, 0x2, 0x2, 0x44, 
    0x45, 0x7, 0xf, 0x2, 0x2, 0x45, 0x46, 0x5, 0xe, 0x8, 0x2, 0x46, 0x47, 
    0x7, 0x10, 0x2, 0x2, 0x47, 0x48, 0x5, 0x12, 0xa, 0x2, 0x48, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x4a, 0x9, 0x2, 0x2, 0x2, 0x4a, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x50, 0x5, 0x10, 0x9, 0x2, 0x4c, 0x4d, 0x7, 0x2a, 0x2, 
    0x2, 0x4d, 0x4f, 0x5, 0x10, 0x9, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x55, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x55, 0x3, 0x2, 0x2, 0x2, 0x54, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x57, 0x5, 0xc, 0x7, 0x2, 0x57, 0x58, 0x7, 0x3, 0x2, 
    0x2, 0x58, 0x11, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x11, 0x2, 0x2, 
    0x5a, 0x5b, 0x5, 0x14, 0xb, 0x2, 0x5b, 0x5c, 0x7, 0x12, 0x2, 0x2, 0x5c, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5f, 0x5, 0x16, 0xc, 0x2, 0x5e, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x69, 0x5, 0x18, 0xd, 
    0x2, 0x64, 0x69, 0x5, 0x1a, 0xe, 0x2, 0x65, 0x69, 0x5, 0x28, 0x15, 0x2, 
    0x66, 0x69, 0x5, 0x2a, 0x16, 0x2, 0x67, 0x69, 0x5, 0x12, 0xa, 0x2, 0x68, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x68, 0x64, 0x3, 0x2, 0x2, 0x2, 0x68, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x17, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x5, 0xc, 
    0x7, 0x2, 0x6b, 0x6c, 0x7, 0x3, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x15, 0x2, 
    0x2, 0x6d, 0x19, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0x1c, 0xf, 0x2, 
    0x6f, 0x70, 0x7, 0x15, 0x2, 0x2, 0x70, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x71, 
    0x72, 0x5, 0x26, 0x14, 0x2, 0x72, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 
    0x9, 0x3, 0x2, 0x2, 0x74, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 
    0x3, 0x2, 0x2, 0x76, 0x77, 0x7, 0xf, 0x2, 0x2, 0x77, 0x78, 0x5, 0x22, 
    0x12, 0x2, 0x78, 0x79, 0x7, 0x10, 0x2, 0x2, 0x79, 0x7c, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x7c, 0x5, 0x1e, 0x10, 0x2, 0x7b, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x7b, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x21, 0x3, 0x2, 0x2, 0x2, 0x7d, 
    0x82, 0x5, 0x1c, 0xf, 0x2, 0x7e, 0x7f, 0x7, 0x2a, 0x2, 0x2, 0x7f, 0x81, 
    0x5, 0x1c, 0xf, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x81, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x87, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x85, 0x87, 0x3, 0x2, 0x2, 0x2, 0x86, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x23, 0x3, 0x2, 0x2, 0x2, 0x88, 
    0x89, 0x8, 0x13, 0x1, 0x2, 0x89, 0x8a, 0x7, 0xf, 0x2, 0x2, 0x8a, 0x8b, 
    0x5, 0x24, 0x13, 0x2, 0x8b, 0x8c, 0x7, 0x10, 0x2, 0x2, 0x8c, 0x99, 0x3, 
    0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x17, 0x2, 0x2, 0x8e, 0x99, 0x5, 0x24, 
    0x13, 0xa, 0x8f, 0x90, 0x7, 0x19, 0x2, 0x2, 0x90, 0x99, 0x5, 0x24, 0x13, 
    0x9, 0x91, 0x92, 0x7, 0x28, 0x2, 0x2, 0x92, 0x99, 0x5, 0x24, 0x13, 0x8, 
    0x93, 0x94, 0x7, 0x29, 0x2, 0x2, 0x94, 0x99, 0x5, 0x24, 0x13, 0x7, 0x95, 
    0x96, 0x7, 0x27, 0x2, 0x2, 0x96, 0x99, 0x5, 0x24, 0x13, 0x6, 0x97, 0x99, 
    0x5, 0x20, 0x11, 0x2, 0x98, 0x88, 0x3, 0x2, 0x2, 0x2, 0x98, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x98, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x93, 0x3, 0x2, 0x2, 0x2, 0x98, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0xa0, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0x9b, 0xc, 0x5, 0x2, 0x2, 0x9b, 0x9f, 0x7, 0x28, 0x2, 0x2, 0x9c, 
    0x9d, 0xc, 0x4, 0x2, 0x2, 0x9d, 0x9f, 0x7, 0x29, 0x2, 0x2, 0x9e, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0x25, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0xa3, 0xa4, 0x5, 0x24, 0x13, 0x2, 0xa4, 0xa5, 0x7, 0x16, 0x2, 0x2, 
    0xa5, 0xa6, 0x5, 0x26, 0x14, 0x2, 0xa6, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0xa8, 0x5, 0x24, 0x13, 0x2, 0xa8, 0xa9, 0x7, 0x18, 0x2, 0x2, 0xa9, 0xaa, 
    0x5, 0x26, 0x14, 0x2, 0xaa, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x5, 
    0x24, 0x13, 0x2, 0xac, 0xad, 0x7, 0x1a, 0x2, 0x2, 0xad, 0xae, 0x5, 0x26, 
    0x14, 0x2, 0xae, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x24, 0x13, 
    0x2, 0xb0, 0xb1, 0x7, 0x17, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x26, 0x14, 0x2, 
    0xb2, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x5, 0x24, 0x13, 0x2, 0xb4, 
    0xb5, 0x7, 0x19, 0x2, 0x2, 0xb5, 0xb6, 0x5, 0x26, 0x14, 0x2, 0xb6, 0xf1, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x5, 0x24, 0x13, 0x2, 0xb8, 0xb9, 0x7, 
    0x1b, 0x2, 0x2, 0xb9, 0xba, 0x5, 0x26, 0x14, 0x2, 0xba, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xbb, 0xbc, 0x5, 0x24, 0x13, 0x2, 0xbc, 0xbd, 0x7, 0x1f, 0x2, 
    0x2, 0xbd, 0xbe, 0x5, 0x26, 0x14, 0x2, 0xbe, 0xf1, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xc0, 0x5, 0x24, 0x13, 0x2, 0xc0, 0xc1, 0x7, 0x1e, 0x2, 0x2, 0xc1, 
    0xc2, 0x5, 0x26, 0x14, 0x2, 0xc2, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 
    0x5, 0x24, 0x13, 0x2, 0xc4, 0xc5, 0x7, 0x20, 0x2, 0x2, 0xc5, 0xc6, 0x5, 
    0x26, 0x14, 0x2, 0xc6, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x5, 0x24, 
    0x13, 0x2, 0xc8, 0xc9, 0x7, 0x1c, 0x2, 0x2, 0xc9, 0xca, 0x5, 0x26, 0x14, 
    0x2, 0xca, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x24, 0x13, 0x2, 
    0xcc, 0xcd, 0x7, 0x1d, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x26, 0x14, 0x2, 0xce, 
    0xf1, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x5, 0x24, 0x13, 0x2, 0xd0, 0xd1, 
    0x7, 0x2b, 0x2, 0x2, 0xd1, 0xd2, 0x5, 0x26, 0x14, 0x2, 0xd2, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x24, 0x13, 0x2, 0xd4, 0xd5, 0x7, 0x2c, 
    0x2, 0x2, 0xd5, 0xd6, 0x5, 0x26, 0x14, 0x2, 0xd6, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0xd7, 0xd8, 0x5, 0x24, 0x13, 0x2, 0xd8, 0xd9, 0x7, 0x21, 0x2, 0x2, 
    0xd9, 0xda, 0x5, 0x26, 0x14, 0x2, 0xda, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xdc, 0x5, 0x24, 0x13, 0x2, 0xdc, 0xdd, 0x7, 0x22, 0x2, 0x2, 0xdd, 0xde, 
    0x5, 0x26, 0x14, 0x2, 0xde, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x5, 
    0x24, 0x13, 0x2, 0xe0, 0xe1, 0x7, 0x23, 0x2, 0x2, 0xe1, 0xe2, 0x5, 0x26, 
    0x14, 0x2, 0xe2, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x24, 0x13, 
    0x2, 0xe4, 0xe5, 0x7, 0x24, 0x2, 0x2, 0xe5, 0xe6, 0x5, 0x26, 0x14, 0x2, 
    0xe6, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x5, 0x24, 0x13, 0x2, 0xe8, 
    0xe9, 0x7, 0x25, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x26, 0x14, 0x2, 0xea, 0xf1, 
    0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x24, 0x13, 0x2, 0xec, 0xed, 0x7, 
    0x26, 0x2, 0x2, 0xed, 0xee, 0x5, 0x26, 0x14, 0x2, 0xee, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xef, 0xf1, 0x5, 0x24, 0x13, 0x2, 0xf0, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xab, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xb7, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0xf0, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xc7, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xcf, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xd7, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xeb, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x7, 0x4, 0x2, 0x2, 0xf3, 0xf4, 0x7, 
    0xf, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x1c, 0xf, 0x2, 0xf5, 0xf6, 0x7, 0x10, 
    0x2, 0x2, 0xf6, 0xf9, 0x5, 0x16, 0xc, 0x2, 0xf7, 0xf8, 0x7, 0x5, 0x2, 
    0x2, 0xf8, 0xfa, 0x5, 0x16, 0xc, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 
    0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 0x29, 0x3, 0x2, 0x2, 0x2, 0xfb, 
    0xfc, 0x7, 0x6, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0xf, 0x2, 0x2, 0xfd, 0xfe, 
    0x5, 0x1c, 0xf, 0x2, 0xfe, 0xff, 0x7, 0x10, 0x2, 0x2, 0xff, 0x100, 0x5, 
    0x16, 0xc, 0x2, 0x100, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x11, 0x2f, 0x34, 0x40, 
    0x50, 0x54, 0x60, 0x68, 0x7b, 0x82, 0x86, 0x98, 0x9e, 0xa0, 0xf0, 0xf9, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

HexaCParser::Initializer HexaCParser::_init;
