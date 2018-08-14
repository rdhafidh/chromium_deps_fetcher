
// Generated from D:/masteraplikasi/stuff/projectall/rilis/chromium_deps_fetcher/libs/depsparser/Depsgrammar.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "DepsgrammarListener.h"


namespace Depsgrammar {

/**
 * This class provides an empty implementation of DepsgrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  DepsgrammarBaseListener : public DepsgrammarListener {
public:

  virtual void enterProg(DepsgrammarParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(DepsgrammarParser::ProgContext * /*ctx*/) override { }

  virtual void enterExpr(DepsgrammarParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(DepsgrammarParser::ExprContext * /*ctx*/) override { }

  virtual void enterVarline(DepsgrammarParser::VarlineContext * /*ctx*/) override { }
  virtual void exitVarline(DepsgrammarParser::VarlineContext * /*ctx*/) override { }

  virtual void enterRightexpr(DepsgrammarParser::RightexprContext * /*ctx*/) override { }
  virtual void exitRightexpr(DepsgrammarParser::RightexprContext * /*ctx*/) override { }

  virtual void enterBentukonejsonval(DepsgrammarParser::BentukonejsonvalContext * /*ctx*/) override { }
  virtual void exitBentukonejsonval(DepsgrammarParser::BentukonejsonvalContext * /*ctx*/) override { }

  virtual void enterBentuktwojsonval(DepsgrammarParser::BentuktwojsonvalContext * /*ctx*/) override { }
  virtual void exitBentuktwojsonval(DepsgrammarParser::BentuktwojsonvalContext * /*ctx*/) override { }

  virtual void enterSingledictexpr(DepsgrammarParser::SingledictexprContext * /*ctx*/) override { }
  virtual void exitSingledictexpr(DepsgrammarParser::SingledictexprContext * /*ctx*/) override { }

  virtual void enterBasicvalue(DepsgrammarParser::BasicvalueContext * /*ctx*/) override { }
  virtual void exitBasicvalue(DepsgrammarParser::BasicvalueContext * /*ctx*/) override { }

  virtual void enterVarfunc(DepsgrammarParser::VarfuncContext * /*ctx*/) override { }
  virtual void exitVarfunc(DepsgrammarParser::VarfuncContext * /*ctx*/) override { }

  virtual void enterString(DepsgrammarParser::StringContext * /*ctx*/) override { }
  virtual void exitString(DepsgrammarParser::StringContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace Depsgrammar
