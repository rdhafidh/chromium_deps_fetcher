#ifndef VISITORDEPS_H
#define VISITORDEPS_H

#include <DepsgrammarBaseVisitor.h>
#include <iostream>
#include <unordered_map>
#include <utility>

using namespace Depsgrammar;

class VisitorDeps : public DepsgrammarVisitor {
 public:
  VisitorDeps();
  ~VisitorDeps();

  std::unordered_map<std::string, std::pair<std::string, std::string>>
  getCurrentFoundRepos() const;
  int getVarLineFound()const;
  bool isContainDepsRepo()const;

 protected:
  virtual antlrcpp::Any visitProg(DepsgrammarParser::ProgContext *context);

  virtual antlrcpp::Any visitExpr(DepsgrammarParser::ExprContext *context);

  virtual antlrcpp::Any visitVarline(
      DepsgrammarParser::VarlineContext *context);

  virtual antlrcpp::Any visitRightexpr(
      DepsgrammarParser::RightexprContext *context);

  virtual antlrcpp::Any visitBentukonejsonval(
      DepsgrammarParser::BentukonejsonvalContext *context);

  virtual antlrcpp::Any visitBentuktwojsonval(
      DepsgrammarParser::BentuktwojsonvalContext *context);

  virtual antlrcpp::Any visitSingledictexpr(
      DepsgrammarParser::SingledictexprContext *context);

  virtual antlrcpp::Any visitBasicvalue(
      DepsgrammarParser::BasicvalueContext *context);

  virtual antlrcpp::Any visitVarfunc(
      DepsgrammarParser::VarfuncContext *context);

  virtual antlrcpp::Any visitString(DepsgrammarParser::StringContext *context);

 private:
  std::pair<std::string, std::string> splitString(const std::string &str,
                                                  char delim);

  int manyVarLine = 0;
  std::unordered_map<std::string, std::pair<std::string, std::string>>
      foundRepos;
  bool iscurlineDeps = 0;
  bool isContainDeps=false;
  std::string currDepsTmp = ""; 
};

#endif  // VISITORDEPS_H