#include "localsourcesfetcher.h"
#include <depsfilerepoparser.h>
#include <sinkrongithandler.h>
#include <QDebug>
#include <QDirIterator>
#include <QFile>
#include <QProcess>
#include <algorithm>
#include <utility>

LocalSourcesFetcher::LocalSourcesFetcher() {}

LocalSourcesFetcher::~LocalSourcesFetcher() {}

QDebug operator<<(QDebug &out, const QVector<std::pair<std::string, std::pair<std::string,std::string>> > &pfr) {
  for (const std::pair<std::string, std::pair<std::string,std::string>> &mpfr : pfr) {
    out << " "<<mpfr.first.c_str();
  }
  return out;
}

void LocalSourcesFetcher::doFetch(
    const QString &fromdeps, const QStringList &excludedrepo,
    const QString &localsourcedir, const QString &outdir,
    const QString &gitexedir, bool isdebugCriticalMode,
    bool printFailedProceedRepo, bool autoDldIFMissingRepoFromSys) {
  DepsFileRepoParser depsparser(fromdeps.toStdString ());
  ParsingRepoResult repos = depsparser.doParse();
  if(!repos.status){
      qDebug()<<repos.errormsg.c_str ();
      return;
  }
  QDir dirs(localsourcedir);
  if (!dirs.makeAbsolute()) {
    if (isdebugCriticalMode) qDebug() << "warning failed to make absolute dir";
    return;
  }
  dirs.setFilter(QDir::Dirs | QDir::Readable | QDir::NoDotAndDotDot);

 
  auto sanitizeRepoName = [](const QString &reponame) -> QString {
    QStringList lst = reponame.split('/');
    if (lst.size() == 0) return reponame;

    return lst.at(lst.size() - 1);
  };
  int ok = 0;
  auto isThatRepoNameIsExcluded = [](const QString &reponame,
                                     const QStringList &exlist) -> bool {
    bool found = false;
    for (const auto &exname : exlist) {
      if (reponame.compare(exname, Qt::CaseInsensitive) == 0) {
        found = true;
      }
    }
    return found == true;
  };
  
  
  QVector< std::pair<std::string, std::pair<std::string,std::string>> > pfr;
  int idx = 0;
  for (const std::pair<std::string, std::pair<std::string,std::string>> &rep : repos.repoInfos) {
    QString reponame = sanitizeRepoName(rep.first.c_str());
    bool found = false;
    if (isThatRepoNameIsExcluded(reponame, excludedrepo)) {
      qDebug() << "ignoring reponame " << reponame << "skipped..";
      continue;
    }
    for (const QString &dir_to_s : dirs.entryList()) {
      if (dir_to_s.compare(reponame, Qt::CaseInsensitive) == 0) {
        bool e = SinkronGitHandler::processDirs(dirs.path(), reponame, gitexedir,
                                                rep.second.second.c_str(), outdir,
                                                isdebugCriticalMode);
        if (!e) {
          pfr << rep;
          continue;
        }
        found = true;
        ok++;
      }
    }
    if (!found) {
      qDebug() << "[-] failed finding reponame " << reponame << "in "
               << dirs.path();
      if (printFailedProceedRepo) {
        pfr << rep;
      }
    }
    idx++;
  }
  qDebug() << "had been processed num repos" << ok << "from total of repo "
           << repos.repoInfos.size ();
  if (printFailedProceedRepo) {
    qDebug() << "Repo list that failed to be processed:" << pfr << " count "
             << pfr.size();
  }
  if (autoDldIFMissingRepoFromSys) {
    for (const auto &ms : pfr) {
      QString reponame = sanitizeRepoName(ms.first.c_str());

      qDebug() << "cloning reponame" << reponame << ms.second.second.c_str()
               << ms.second.first.c_str();
      QString outrepo = dirs.path() + "/" + reponame;
      if (!SinkronGitHandler::cloneMissingRepo(gitexedir, ms.second.first.c_str(), outrepo,
                                               isdebugCriticalMode)) {
        qDebug() << "warning auto download repo failed " << ms.second.first.c_str()
                 << "to outrepo" << outrepo;
      } else {
        qDebug() << "done auto download repo " << ms.second.first.c_str() << "to repo"
                 << outrepo;

        // then try to archive and put in outdir
        bool e = SinkronGitHandler::processDirs(dirs.path(), reponame, gitexedir,
                                                ms.second.second.c_str(), outdir,
                                                isdebugCriticalMode);
        if (!e) {
          qDebug() << "warning couldnt archive " << reponame << "giving up..";
        } else {
          qDebug() << "done archived repo" << reponame;
        }
      }
    }
  }
}
