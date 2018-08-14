#include "visitordeps.h"
#include <DepsgrammarParser.h>
#include <algorithm>

using namespace Depsgrammar;

VisitorDeps::VisitorDeps() { foundRepos.clear(); }

VisitorDeps::~VisitorDeps() {}

std::unordered_map<std::string, std::pair<std::string, std::string> >
VisitorDeps::getCurrentFoundRepos() const {
    return foundRepos;
}

int VisitorDeps::getVarLineFound() const
{
    return manyVarLine;
}

bool VisitorDeps::isContainDepsRepo() const
{
    return isContainDeps;
}

antlrcpp::Any VisitorDeps::visitProg(DepsgrammarParser::ProgContext *context) {
  for (const auto &x : context->expr()) {
    visit(x);
  } 
  return nullptr;
}

antlrcpp::Any VisitorDeps::visitExpr(DepsgrammarParser::ExprContext *context) {
  visit(context->varline());
  manyVarLine += 1;
  return nullptr;
}

antlrcpp::Any VisitorDeps::visitVarline(
    DepsgrammarParser::VarlineContext *context) {
  if (context->ID()->getText() == "deps") {
    // only interested in deps reponame and it's url  atm
    if (context->rightexpr()) {
      iscurlineDeps = true;
      isContainDeps=true;
      visit(context->rightexpr());
    }
  } else {
    iscurlineDeps = false;
  }
  return nullptr;
}
antlrcpp::Any VisitorDeps::visitRightexpr(
    DepsgrammarParser::RightexprContext *context) {
  if (context->bentuktwojsonval()) {
    visit(context->bentuktwojsonval());
  }
  return nullptr;
}

antlrcpp::Any VisitorDeps::visitBentukonejsonval(
    DepsgrammarParser::BentukonejsonvalContext *context) {
  return nullptr;
}

antlrcpp::Any VisitorDeps::visitBentuktwojsonval(
    DepsgrammarParser::BentuktwojsonvalContext *context) {
  for (auto &x : context->singledictexpr()) {
    visit(x);
  }
  return nullptr;
}

antlrcpp::Any VisitorDeps::visitSingledictexpr(
    DepsgrammarParser::SingledictexprContext *context) {
  if (iscurlineDeps && context->basicvalue()) {
    currDepsTmp = context->string()->getText();
    currDepsTmp.erase(std::remove(currDepsTmp.begin(), currDepsTmp.end(), '"'),
                      currDepsTmp.end());
    visit(context->basicvalue());
  }
  return nullptr;
}

antlrcpp::Any VisitorDeps::visitBasicvalue(
    DepsgrammarParser::BasicvalueContext *context) {
  if (context->string()) {
    if (context->string()->SIMPLESTRINGEXPRDOUBLEQUOTE()) {
      auto str = context->string()->SIMPLESTRINGEXPRDOUBLEQUOTE()->toString();
      str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
      foundRepos.insert(std::make_pair(currDepsTmp, splitString(str, '@')));
    }
    if (context->string()->SIMPLESTRINGEXPRSINGLEQUOTE()) {
      auto str = context->string()->SIMPLESTRINGEXPRSINGLEQUOTE()->toString();
      str.erase(std::remove(str.begin(), str.end(), '\''), str.end());
      foundRepos.insert(std::make_pair(currDepsTmp, splitString(str, '@')));
    }
  }
  return nullptr;
}
antlrcpp::Any VisitorDeps::visitVarfunc(
    DepsgrammarParser::VarfuncContext *context) {
  return nullptr;
}
antlrcpp::Any VisitorDeps::visitString(
    DepsgrammarParser::StringContext *context) {
  return nullptr;
}

std::pair<std::string, std::string> VisitorDeps::splitString(
    const std::string &str, char delim) {
  std::istringstream input(str);
  std::string tmpToken;
  std::pair<std::string, std::string> mPair;
  int expectPair = 0;
  /*
   *  I expect value string format is grouped into two forms
   * */
  while (std::getline(input, tmpToken, delim)) {
    if (expectPair == 0) {
      mPair = std::make_pair(tmpToken, "");
    }
    if (expectPair == 1) {
      mPair = std::make_pair(mPair.first, tmpToken);
      break;
    }
    if (expectPair > 1) {
      break;
    }
    expectPair++;
  }
  return mPair;
}