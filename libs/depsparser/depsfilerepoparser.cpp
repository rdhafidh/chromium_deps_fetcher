#include "depsfilerepoparser.h"
#include <DepsgrammarLexer.h>
#include <DepsgrammarListener.h>
#include <DepsgrammarParser.h>
#include <parsererrorlistener.h>
#include <fstream>

DepsFileRepoParser::DepsFileRepoParser(const std::string &fn) : fname(fn) {}

DepsFileRepoParser::~DepsFileRepoParser() {}

ParsingRepoResult DepsFileRepoParser::doParse() {
  ParsingRepoResult result;
  result.status = false;
  result.errormsg = "";
  result.isContainDepsVar=false;
  result.varLineCount=0;
  auto buffer = readfile(fname.c_str());
  antlr4::ANTLRInputStream input(buffer.data(), buffer.size());
  Depsgrammar::DepsgrammarLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  Depsgrammar::DepsgrammarParser parser(&tokens);
  ParserErrorListener listen;
  try {
    VisitorDeps dep;
    parser.addErrorListener(&listen);
    parser.setBuildParseTree(true);
    tokens.fill();
    antlr4::tree::ParseTree *tree = parser.prog();
    dep.visit(tree);
    result.repoInfos = dep.getCurrentFoundRepos();
    result.status = true;
    result.varLineCount=dep.getVarLineFound (); 
    result.isContainDepsVar=dep.isContainDepsRepo ();
  } catch (const std::exception &e) {
    result.errormsg = e.what();
  }catch(...){
      result.errormsg="unknown error";
  }
  
  
  return result;
}

std::vector<char> DepsFileRepoParser::readfile(const char *fname) {
  std::vector<char> buf;
  std::ifstream fs(fname);
  if(fs.is_open ()){
      fs.seekg(0, std::ios::end);
      size_t length = fs.tellg();
      fs.seekg(0, std::ios::beg);
      buf.resize(length);
      fs.read(buf.data(), length);
  }
  return buf;
}
