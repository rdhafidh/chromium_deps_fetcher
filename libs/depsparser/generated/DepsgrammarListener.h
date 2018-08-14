
// Generated from D:/masteraplikasi/stuff/projectall/rilis/chromium_deps_fetcher/libs/depsparser/Depsgrammar.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "DepsgrammarParser.h"


namespace Depsgrammar {

/**
 * This interface defines an abstract listener for a parse tree produced by DepsgrammarParser.
 */
class  DepsgrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(DepsgrammarParser::ProgContext *ctx) = 0;
  virtual void exitProg(DepsgrammarParser::ProgContext *ctx) = 0;

  virtual void enterExpr(DepsgrammarParser::ExprContext *ctx) = 0;
  virtual void exitExpr(DepsgrammarParser::ExprContext *ctx) = 0;

  virtual void enterVarline(DepsgrammarParser::VarlineContext *ctx) = 0;
  virtual void exitVarline(DepsgrammarParser::VarlineContext *ctx) = 0;

  virtual void enterRightexpr(DepsgrammarParser::RightexprContext *ctx) = 0;
  virtual void exitRightexpr(DepsgrammarParser::RightexprContext *ctx) = 0;

  virtual void enterBentukonejsonval(DepsgrammarParser::BentukonejsonvalContext *ctx) = 0;
  virtual void exitBentukonejsonval(DepsgrammarParser::BentukonejsonvalContext *ctx) = 0;

  virtual void enterBentuktwojsonval(DepsgrammarParser::BentuktwojsonvalContext *ctx) = 0;
  virtual void exitBentuktwojsonval(DepsgrammarParser::BentuktwojsonvalContext *ctx) = 0;

  virtual void enterSingledictexpr(DepsgrammarParser::SingledictexprContext *ctx) = 0;
  virtual void exitSingledictexpr(DepsgrammarParser::SingledictexprContext *ctx) = 0;

  virtual void enterBasicvalue(DepsgrammarParser::BasicvalueContext *ctx) = 0;
  virtual void exitBasicvalue(DepsgrammarParser::BasicvalueContext *ctx) = 0;

  virtual void enterVarfunc(DepsgrammarParser::VarfuncContext *ctx) = 0;
  virtual void exitVarfunc(DepsgrammarParser::VarfuncContext *ctx) = 0;

  virtual void enterString(DepsgrammarParser::StringContext *ctx) = 0;
  virtual void exitString(DepsgrammarParser::StringContext *ctx) = 0;


};

}  // namespace Depsgrammar
