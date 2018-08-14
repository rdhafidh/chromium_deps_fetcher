
// Generated from D:/masteraplikasi/stuff/projectall/rilis/chromium_deps_fetcher/libs/depsparser/Depsgrammar.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "DepsgrammarVisitor.h"


namespace Depsgrammar {

/**
 * This class provides an empty implementation of DepsgrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  DepsgrammarBaseVisitor : public DepsgrammarVisitor {
public:

  virtual antlrcpp::Any visitProg(DepsgrammarParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(DepsgrammarParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarline(DepsgrammarParser::VarlineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRightexpr(DepsgrammarParser::RightexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBentukonejsonval(DepsgrammarParser::BentukonejsonvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBentuktwojsonval(DepsgrammarParser::BentuktwojsonvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingledictexpr(DepsgrammarParser::SingledictexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBasicvalue(DepsgrammarParser::BasicvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarfunc(DepsgrammarParser::VarfuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(DepsgrammarParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace Depsgrammar
