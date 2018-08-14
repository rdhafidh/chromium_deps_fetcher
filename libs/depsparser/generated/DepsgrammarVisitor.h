
// Generated from D:/masteraplikasi/stuff/projectall/rilis/chromium_deps_fetcher/libs/depsparser/Depsgrammar.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "DepsgrammarParser.h"


namespace Depsgrammar {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by DepsgrammarParser.
 */
class  DepsgrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by DepsgrammarParser.
   */
    virtual antlrcpp::Any visitProg(DepsgrammarParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitExpr(DepsgrammarParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitVarline(DepsgrammarParser::VarlineContext *context) = 0;

    virtual antlrcpp::Any visitRightexpr(DepsgrammarParser::RightexprContext *context) = 0;

    virtual antlrcpp::Any visitBentukonejsonval(DepsgrammarParser::BentukonejsonvalContext *context) = 0;

    virtual antlrcpp::Any visitBentuktwojsonval(DepsgrammarParser::BentuktwojsonvalContext *context) = 0;

    virtual antlrcpp::Any visitSingledictexpr(DepsgrammarParser::SingledictexprContext *context) = 0;

    virtual antlrcpp::Any visitBasicvalue(DepsgrammarParser::BasicvalueContext *context) = 0;

    virtual antlrcpp::Any visitVarfunc(DepsgrammarParser::VarfuncContext *context) = 0;

    virtual antlrcpp::Any visitString(DepsgrammarParser::StringContext *context) = 0;


};

}  // namespace Depsgrammar
