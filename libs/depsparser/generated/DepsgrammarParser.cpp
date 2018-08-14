
// Generated from D:/masteraplikasi/stuff/projectall/rilis/chromium_deps_fetcher/libs/depsparser/Depsgrammar.g4 by ANTLR 4.7.1


#include "DepsgrammarListener.h"
#include "DepsgrammarVisitor.h"

#include "DepsgrammarParser.h"


using namespace antlrcpp;
using namespace Depsgrammar;
using namespace antlr4;

DepsgrammarParser::DepsgrammarParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

DepsgrammarParser::~DepsgrammarParser() {
  delete _interpreter;
}

std::string DepsgrammarParser::getGrammarFileName() const {
  return "Depsgrammar.g4";
}

const std::vector<std::string>& DepsgrammarParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& DepsgrammarParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

DepsgrammarParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DepsgrammarParser::ProgContext::EOF() {
  return getToken(DepsgrammarParser::EOF, 0);
}

std::vector<DepsgrammarParser::ExprContext *> DepsgrammarParser::ProgContext::expr() {
  return getRuleContexts<DepsgrammarParser::ExprContext>();
}

DepsgrammarParser::ExprContext* DepsgrammarParser::ProgContext::expr(size_t i) {
  return getRuleContext<DepsgrammarParser::ExprContext>(i);
}


size_t DepsgrammarParser::ProgContext::getRuleIndex() const {
  return DepsgrammarParser::RuleProg;
}

void DepsgrammarParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void DepsgrammarParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


antlrcpp::Any DepsgrammarParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DepsgrammarVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

DepsgrammarParser::ProgContext* DepsgrammarParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, DepsgrammarParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(20);
      expr();
      setState(23); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DepsgrammarParser::ID);
    setState(25);
    match(DepsgrammarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

DepsgrammarParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DepsgrammarParser::VarlineContext* DepsgrammarParser::ExprContext::varline() {
  return getRuleContext<DepsgrammarParser::VarlineContext>(0);
}


size_t DepsgrammarParser::ExprContext::getRuleIndex() const {
  return DepsgrammarParser::RuleExpr;
}

void DepsgrammarParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void DepsgrammarParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any DepsgrammarParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DepsgrammarVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

DepsgrammarParser::ExprContext* DepsgrammarParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, DepsgrammarParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    varline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarlineContext ------------------------------------------------------------------

DepsgrammarParser::VarlineContext::VarlineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DepsgrammarParser::VarlineContext::ID() {
  return getToken(DepsgrammarParser::ID, 0);
}

tree::TerminalNode* DepsgrammarParser::VarlineContext::EQ() {
  return getToken(DepsgrammarParser::EQ, 0);
}

DepsgrammarParser::RightexprContext* DepsgrammarParser::VarlineContext::rightexpr() {
  return getRuleContext<DepsgrammarParser::RightexprContext>(0);
}


size_t DepsgrammarParser::VarlineContext::getRuleIndex() const {
  return DepsgrammarParser::RuleVarline;
}

void DepsgrammarParser::VarlineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarline(this);
}

void DepsgrammarParser::VarlineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarline(this);
}


antlrcpp::Any DepsgrammarParser::VarlineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DepsgrammarVisitor*>(visitor))
    return parserVisitor->visitVarline(this);
  else
    return visitor->visitChildren(this);
}

DepsgrammarParser::VarlineContext* DepsgrammarParser::varline() {
  VarlineContext *_localctx = _tracker.createInstance<VarlineContext>(_ctx, getState());
  enterRule(_localctx, 4, DepsgrammarParser::RuleVarline);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(DepsgrammarParser::ID);
    setState(30);
    match(DepsgrammarParser::EQ);
    setState(31);
    rightexpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RightexprContext ------------------------------------------------------------------

DepsgrammarParser::RightexprContext::RightexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DepsgrammarParser::BentuktwojsonvalContext* DepsgrammarParser::RightexprContext::bentuktwojsonval() {
  return getRuleContext<DepsgrammarParser::BentuktwojsonvalContext>(0);
}

DepsgrammarParser::BasicvalueContext* DepsgrammarParser::RightexprContext::basicvalue() {
  return getRuleContext<DepsgrammarParser::BasicvalueContext>(0);
}

DepsgrammarParser::BentukonejsonvalContext* DepsgrammarParser::RightexprContext::bentukonejsonval() {
  return getRuleContext<DepsgrammarParser::BentukonejsonvalContext>(0);
}


size_t DepsgrammarParser::RightexprContext::getRuleIndex() const {
  return DepsgrammarParser::RuleRightexpr;
}

void DepsgrammarParser::RightexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRightexpr(this);
}

void DepsgrammarParser::RightexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRightexpr(this);
}


antlrcpp::Any DepsgrammarParser::RightexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DepsgrammarVisitor*>(visitor))
    return parserVisitor->visitRightexpr(this);
  else
    return visitor->visitChildren(this);
}

DepsgrammarParser::RightexprContext* DepsgrammarParser::rightexpr() {
  RightexprContext *_localctx = _tracker.createInstance<RightexprContext>(_ctx, getState());
  enterRule(_localctx, 6, DepsgrammarParser::RuleRightexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(37);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(33);
      bentuktwojsonval();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(34);
      basicvalue();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(35);
      bentukonejsonval();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);

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

//----------------- BentukonejsonvalContext ------------------------------------------------------------------

DepsgrammarParser::BentukonejsonvalContext::BentukonejsonvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DepsgrammarParser::StringContext *> DepsgrammarParser::BentukonejsonvalContext::string() {
  return getRuleContexts<DepsgrammarParser::StringContext>();
}

DepsgrammarParser::StringContext* DepsgrammarParser::BentukonejsonvalContext::string(size_t i) {
  return getRuleContext<DepsgrammarParser::StringContext>(i);
}

std::vector<tree::TerminalNode *> DepsgrammarParser::BentukonejsonvalContext::COMMA() {
  return getTokens(DepsgrammarParser::COMMA);
}

tree::TerminalNode* DepsgrammarParser::BentukonejsonvalContext::COMMA(size_t i) {
  return getToken(DepsgrammarParser::COMMA, i);
}


size_t DepsgrammarParser::BentukonejsonvalContext::getRuleIndex() const {
  return DepsgrammarParser::RuleBentukonejsonval;
}

void DepsgrammarParser::BentukonejsonvalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBentukonejsonval(this);
}

void DepsgrammarParser::BentukonejsonvalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBentukonejsonval(this);
}


antlrcpp::Any DepsgrammarParser::BentukonejsonvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DepsgrammarVisitor*>(visitor))
    return parserVisitor->visitBentukonejsonval(this);
  else
    return visitor->visitChildren(this);
}

DepsgrammarParser::BentukonejsonvalContext* DepsgrammarParser::bentukonejsonval() {
  BentukonejsonvalContext *_localctx = _tracker.createInstance<BentukonejsonvalContext>(_ctx, getState());
  enterRule(_localctx, 8, DepsgrammarParser::RuleBentukonejsonval);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(39);
    match(DepsgrammarParser::T__0);
    setState(41);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DepsgrammarParser::SIMPLESTRINGEXPRDOUBLEQUOTE

    || _la == DepsgrammarParser::SIMPLESTRINGEXPRSINGLEQUOTE) {
      setState(40);
      string();
    }
    setState(47);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(43);
        match(DepsgrammarParser::COMMA);
        setState(44);
        string(); 
      }
      setState(49);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
    setState(51);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DepsgrammarParser::COMMA) {
      setState(50);
      match(DepsgrammarParser::COMMA);
    }
    setState(53);
    match(DepsgrammarParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BentuktwojsonvalContext ------------------------------------------------------------------

DepsgrammarParser::BentuktwojsonvalContext::BentuktwojsonvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DepsgrammarParser::SingledictexprContext *> DepsgrammarParser::BentuktwojsonvalContext::singledictexpr() {
  return getRuleContexts<DepsgrammarParser::SingledictexprContext>();
}

DepsgrammarParser::SingledictexprContext* DepsgrammarParser::BentuktwojsonvalContext::singledictexpr(size_t i) {
  return getRuleContext<DepsgrammarParser::SingledictexprContext>(i);
}

std::vector<tree::TerminalNode *> DepsgrammarParser::BentuktwojsonvalContext::COMMA() {
  return getTokens(DepsgrammarParser::COMMA);
}

tree::TerminalNode* DepsgrammarParser::BentuktwojsonvalContext::COMMA(size_t i) {
  return getToken(DepsgrammarParser::COMMA, i);
}


size_t DepsgrammarParser::BentuktwojsonvalContext::getRuleIndex() const {
  return DepsgrammarParser::RuleBentuktwojsonval;
}

void DepsgrammarParser::BentuktwojsonvalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBentuktwojsonval(this);
}

void DepsgrammarParser::BentuktwojsonvalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBentuktwojsonval(this);
}


antlrcpp::Any DepsgrammarParser::BentuktwojsonvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DepsgrammarVisitor*>(visitor))
    return parserVisitor->visitBentuktwojsonval(this);
  else
    return visitor->visitChildren(this);
}

DepsgrammarParser::BentuktwojsonvalContext* DepsgrammarParser::bentuktwojsonval() {
  BentuktwojsonvalContext *_localctx = _tracker.createInstance<BentuktwojsonvalContext>(_ctx, getState());
  enterRule(_localctx, 10, DepsgrammarParser::RuleBentuktwojsonval);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(55);
    match(DepsgrammarParser::T__2);
    setState(57);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DepsgrammarParser::SIMPLESTRINGEXPRDOUBLEQUOTE

    || _la == DepsgrammarParser::SIMPLESTRINGEXPRSINGLEQUOTE) {
      setState(56);
      singledictexpr();
    }
    setState(63);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(59);
        match(DepsgrammarParser::COMMA);
        setState(60);
        singledictexpr(); 
      }
      setState(65);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
    setState(67);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DepsgrammarParser::COMMA) {
      setState(66);
      match(DepsgrammarParser::COMMA);
    }
    setState(69);
    match(DepsgrammarParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingledictexprContext ------------------------------------------------------------------

DepsgrammarParser::SingledictexprContext::SingledictexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DepsgrammarParser::StringContext* DepsgrammarParser::SingledictexprContext::string() {
  return getRuleContext<DepsgrammarParser::StringContext>(0);
}

DepsgrammarParser::BasicvalueContext* DepsgrammarParser::SingledictexprContext::basicvalue() {
  return getRuleContext<DepsgrammarParser::BasicvalueContext>(0);
}


size_t DepsgrammarParser::SingledictexprContext::getRuleIndex() const {
  return DepsgrammarParser::RuleSingledictexpr;
}

void DepsgrammarParser::SingledictexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingledictexpr(this);
}

void DepsgrammarParser::SingledictexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingledictexpr(this);
}


antlrcpp::Any DepsgrammarParser::SingledictexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DepsgrammarVisitor*>(visitor))
    return parserVisitor->visitSingledictexpr(this);
  else
    return visitor->visitChildren(this);
}

DepsgrammarParser::SingledictexprContext* DepsgrammarParser::singledictexpr() {
  SingledictexprContext *_localctx = _tracker.createInstance<SingledictexprContext>(_ctx, getState());
  enterRule(_localctx, 12, DepsgrammarParser::RuleSingledictexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    string();
    setState(72);
    match(DepsgrammarParser::T__4);
    setState(73);
    basicvalue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicvalueContext ------------------------------------------------------------------

DepsgrammarParser::BasicvalueContext::BasicvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DepsgrammarParser::BasicvalueContext::True() {
  return getToken(DepsgrammarParser::True, 0);
}

tree::TerminalNode* DepsgrammarParser::BasicvalueContext::False() {
  return getToken(DepsgrammarParser::False, 0);
}

DepsgrammarParser::StringContext* DepsgrammarParser::BasicvalueContext::string() {
  return getRuleContext<DepsgrammarParser::StringContext>(0);
}

tree::TerminalNode* DepsgrammarParser::BasicvalueContext::NUM() {
  return getToken(DepsgrammarParser::NUM, 0);
}

DepsgrammarParser::VarfuncContext* DepsgrammarParser::BasicvalueContext::varfunc() {
  return getRuleContext<DepsgrammarParser::VarfuncContext>(0);
}

DepsgrammarParser::BentuktwojsonvalContext* DepsgrammarParser::BasicvalueContext::bentuktwojsonval() {
  return getRuleContext<DepsgrammarParser::BentuktwojsonvalContext>(0);
}


size_t DepsgrammarParser::BasicvalueContext::getRuleIndex() const {
  return DepsgrammarParser::RuleBasicvalue;
}

void DepsgrammarParser::BasicvalueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicvalue(this);
}

void DepsgrammarParser::BasicvalueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicvalue(this);
}


antlrcpp::Any DepsgrammarParser::BasicvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DepsgrammarVisitor*>(visitor))
    return parserVisitor->visitBasicvalue(this);
  else
    return visitor->visitChildren(this);
}

DepsgrammarParser::BasicvalueContext* DepsgrammarParser::basicvalue() {
  BasicvalueContext *_localctx = _tracker.createInstance<BasicvalueContext>(_ctx, getState());
  enterRule(_localctx, 14, DepsgrammarParser::RuleBasicvalue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(81);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DepsgrammarParser::True: {
        enterOuterAlt(_localctx, 1);
        setState(75);
        match(DepsgrammarParser::True);
        break;
      }

      case DepsgrammarParser::False: {
        enterOuterAlt(_localctx, 2);
        setState(76);
        match(DepsgrammarParser::False);
        break;
      }

      case DepsgrammarParser::SIMPLESTRINGEXPRDOUBLEQUOTE:
      case DepsgrammarParser::SIMPLESTRINGEXPRSINGLEQUOTE: {
        enterOuterAlt(_localctx, 3);
        setState(77);
        string();
        break;
      }

      case DepsgrammarParser::NUM: {
        enterOuterAlt(_localctx, 4);
        setState(78);
        match(DepsgrammarParser::NUM);
        break;
      }

      case DepsgrammarParser::Var: {
        enterOuterAlt(_localctx, 5);
        setState(79);
        varfunc();
        break;
      }

      case DepsgrammarParser::T__2: {
        enterOuterAlt(_localctx, 6);
        setState(80);
        bentuktwojsonval();
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

//----------------- VarfuncContext ------------------------------------------------------------------

DepsgrammarParser::VarfuncContext::VarfuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DepsgrammarParser::VarfuncContext::Var() {
  return getToken(DepsgrammarParser::Var, 0);
}

DepsgrammarParser::StringContext* DepsgrammarParser::VarfuncContext::string() {
  return getRuleContext<DepsgrammarParser::StringContext>(0);
}


size_t DepsgrammarParser::VarfuncContext::getRuleIndex() const {
  return DepsgrammarParser::RuleVarfunc;
}

void DepsgrammarParser::VarfuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarfunc(this);
}

void DepsgrammarParser::VarfuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarfunc(this);
}


antlrcpp::Any DepsgrammarParser::VarfuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DepsgrammarVisitor*>(visitor))
    return parserVisitor->visitVarfunc(this);
  else
    return visitor->visitChildren(this);
}

DepsgrammarParser::VarfuncContext* DepsgrammarParser::varfunc() {
  VarfuncContext *_localctx = _tracker.createInstance<VarfuncContext>(_ctx, getState());
  enterRule(_localctx, 16, DepsgrammarParser::RuleVarfunc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(DepsgrammarParser::Var);
    setState(84);
    match(DepsgrammarParser::T__5);
    setState(85);
    string();
    setState(86);
    match(DepsgrammarParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

DepsgrammarParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DepsgrammarParser::StringContext::SIMPLESTRINGEXPRDOUBLEQUOTE() {
  return getToken(DepsgrammarParser::SIMPLESTRINGEXPRDOUBLEQUOTE, 0);
}

tree::TerminalNode* DepsgrammarParser::StringContext::SIMPLESTRINGEXPRSINGLEQUOTE() {
  return getToken(DepsgrammarParser::SIMPLESTRINGEXPRSINGLEQUOTE, 0);
}


size_t DepsgrammarParser::StringContext::getRuleIndex() const {
  return DepsgrammarParser::RuleString;
}

void DepsgrammarParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void DepsgrammarParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DepsgrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}


antlrcpp::Any DepsgrammarParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DepsgrammarVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

DepsgrammarParser::StringContext* DepsgrammarParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 18, DepsgrammarParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    _la = _input->LA(1);
    if (!(_la == DepsgrammarParser::SIMPLESTRINGEXPRDOUBLEQUOTE

    || _la == DepsgrammarParser::SIMPLESTRINGEXPRSINGLEQUOTE)) {
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

// Static vars and initialization.
std::vector<dfa::DFA> DepsgrammarParser::_decisionToDFA;
atn::PredictionContextCache DepsgrammarParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN DepsgrammarParser::_atn;
std::vector<uint16_t> DepsgrammarParser::_serializedATN;

std::vector<std::string> DepsgrammarParser::_ruleNames = {
  "prog", "expr", "varline", "rightexpr", "bentukonejsonval", "bentuktwojsonval", 
  "singledictexpr", "basicvalue", "varfunc", "string"
};

std::vector<std::string> DepsgrammarParser::_literalNames = {
  "", "'['", "']'", "'{'", "'}'", "':'", "'('", "')'", "'Var'", "','", "", 
  "", "", "", "", "", "'='"
};

std::vector<std::string> DepsgrammarParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "Var", "COMMA", "NUM", "True", "False", 
  "ID", "SIMPLESTRINGEXPRDOUBLEQUOTE", "SIMPLESTRINGEXPRSINGLEQUOTE", "EQ", 
  "COMMENT", "WS"
};

dfa::Vocabulary DepsgrammarParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> DepsgrammarParser::_tokenNames;

DepsgrammarParser::Initializer::Initializer() {
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
    0x3, 0x14, 0x5d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x3, 0x2, 0x6, 0x2, 0x18, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x19, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x28, 0xa, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x2c, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0x30, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x33, 0xb, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x36, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0x3c, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x40, 0xa, 0x7, 0xc, 0x7, 
    0xe, 0x7, 0x43, 0xb, 0x7, 0x3, 0x7, 0x5, 0x7, 0x46, 0xa, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x54, 0xa, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x2, 0x2, 0xc, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x2, 0x3, 0x3, 0x2, 0x10, 0x11, 0x2, 0x61, 0x2, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0xa, 0x29, 0x3, 0x2, 0x2, 0x2, 0xc, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x49, 0x3, 0x2, 0x2, 0x2, 0x10, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x55, 0x3, 0x2, 0x2, 0x2, 0x14, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x18, 0x5, 0x4, 0x3, 0x2, 0x17, 0x16, 0x3, 0x2, 0x2, 
    0x2, 0x18, 0x19, 0x3, 0x2, 0x2, 0x2, 0x19, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 
    0x1c, 0x7, 0x2, 0x2, 0x3, 0x1c, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 
    0x5, 0x6, 0x4, 0x2, 0x1e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x7, 
    0xf, 0x2, 0x2, 0x20, 0x21, 0x7, 0x12, 0x2, 0x2, 0x21, 0x22, 0x5, 0x8, 
    0x5, 0x2, 0x22, 0x7, 0x3, 0x2, 0x2, 0x2, 0x23, 0x28, 0x5, 0xc, 0x7, 
    0x2, 0x24, 0x28, 0x5, 0x10, 0x9, 0x2, 0x25, 0x28, 0x5, 0xa, 0x6, 0x2, 
    0x26, 0x28, 0x3, 0x2, 0x2, 0x2, 0x27, 0x23, 0x3, 0x2, 0x2, 0x2, 0x27, 
    0x24, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x26, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x9, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2b, 0x7, 
    0x3, 0x2, 0x2, 0x2a, 0x2c, 0x5, 0x14, 0xb, 0x2, 0x2b, 0x2a, 0x3, 0x2, 
    0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x2d, 0x2e, 0x7, 0xb, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x14, 0xb, 0x2, 
    0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 0x2, 0x31, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 0x36, 0x7, 
    0xb, 0x2, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x4, 0x2, 
    0x2, 0x38, 0xb, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3b, 0x7, 0x5, 0x2, 0x2, 
    0x3a, 0x3c, 0x5, 0xe, 0x8, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3b, 
    0x3c, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x41, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 
    0x7, 0xb, 0x2, 0x2, 0x3e, 0x40, 0x5, 0xe, 0x8, 0x2, 0x3f, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44, 0x46, 0x7, 0xb, 0x2, 0x2, 
    0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0x6, 0x2, 0x2, 0x48, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x14, 0xb, 0x2, 0x4a, 0x4b, 0x7, 
    0x7, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x10, 0x9, 0x2, 0x4c, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x54, 0x7, 0xd, 0x2, 0x2, 0x4e, 0x54, 0x7, 0xe, 0x2, 
    0x2, 0x4f, 0x54, 0x5, 0x14, 0xb, 0x2, 0x50, 0x54, 0x7, 0xc, 0x2, 0x2, 
    0x51, 0x54, 0x5, 0x12, 0xa, 0x2, 0x52, 0x54, 0x5, 0xc, 0x7, 0x2, 0x53, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x53, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x53, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x56, 0x7, 0xa, 0x2, 0x2, 0x56, 0x57, 0x7, 0x8, 0x2, 
    0x2, 0x57, 0x58, 0x5, 0x14, 0xb, 0x2, 0x58, 0x59, 0x7, 0x9, 0x2, 0x2, 
    0x59, 0x13, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x9, 0x2, 0x2, 0x2, 0x5b, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0xb, 0x19, 0x27, 0x2b, 0x31, 0x35, 0x3b, 0x41, 
    0x45, 0x53, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

DepsgrammarParser::Initializer DepsgrammarParser::_init;
