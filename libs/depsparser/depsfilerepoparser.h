#ifndef DEPSFILEREPOPARSER_H
#define DEPSFILEREPOPARSER_H

#include <visitordeps.h>

struct ParsingRepoResult {
  bool status;
  std::string errormsg;
  std::unordered_map<std::string, std::pair<std::string, std::string>>
      repoInfos;
  int varLineCount=0;
  bool isContainDepsVar;
};

class DepsFileRepoParser {
 public:
  DepsFileRepoParser(const std::string &fn);
  ~DepsFileRepoParser();
  ParsingRepoResult doParse();

 private:
  std::string fname;
  std::vector<char> readfile(const char *fname);
};

#endif  // DEPSFILEREPOPARSER_H