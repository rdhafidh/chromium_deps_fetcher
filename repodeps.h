#ifndef REPODEPS_H
#define REPODEPS_H
#include <QString>


enum class FindRepoStatus{
      OK_GOOD=0x2,
      NOT_FOUND_ANY_REPO,
      PARSING_DEPS_FAILED,
     OTHER_INTERNAL_ERROR
};

struct  DEPSRepoFound{
        QString reponame;
        QString linkname;
        QString gitversion; 
};
#endif // REPODEPS_H
