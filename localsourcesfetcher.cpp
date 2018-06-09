#include "localsourcesfetcher.h"
#include <peglib.h>
#include <sinkrongithandler.h>
#include <QDebug>
#include <QDirIterator>
#include <QFile>
#include <QProcess>
#include <algorithm>

LocalSourcesFetcher::LocalSourcesFetcher() {}

LocalSourcesFetcher::~LocalSourcesFetcher() {}

void LocalSourcesFetcher::doFetch(const QString &fromdeps,
                                  const QStringList &excludedrepo,
                                  const QString &localsourcedir,
                                  const QString &outdir,
                                  const QString &gitexedir,
                                  bool isdebugCriticalMode,
                                  bool printFailedProceedRepo) {
  auto repos = findAnyRepos(fromdeps);
  QDir dirs(localsourcedir);
  if (!dirs.makeAbsolute()) {
    if (isdebugCriticalMode) qDebug() << "warning failed to make absolute dir";
    return;
  }
  dirs.setFilter(QDir::Dirs | QDir::Readable | QDir::NoDotAndDotDot);

  auto isContaingit = [&]() -> QString {
    QDir dirm(gitexedir);
    if (!dirm.isAbsolute()) {
      if (!dirm.makeAbsolute()) {
        if (isdebugCriticalMode)
          qDebug() << "make absolute path git exe failed";
        return QString("");
      }
    }
    QString path;
#ifdef Q_OS_WIN32
    path = dirm.path() + "/git.exe";
#else
    path = dirm.path() + "/git";
#endif
    qDebug() << "path" << path;
    return path;
  };
  QString gitpath = isContaingit();
  if (gitpath.isEmpty()) {
    return;
  }
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
  QSet<QString> pfr;
  for (const DEPSRepoFound &rep : repos) {
    QString reponame = sanitizeRepoName(rep.reponame);
    bool found = false;
    if (isThatRepoNameIsExcluded(reponame, excludedrepo)) {
      qDebug() << "ignoring reponame " << reponame << "skipped..";
      continue;
    }
    for (const QString &dir_to_s : dirs.entryList()) {
      if (dir_to_s.compare(reponame, Qt::CaseInsensitive) == 0) {
        bool e = SinkronGitHandler::processDirs(dirs.path(), reponame, gitpath,
                                                rep.gitversion, outdir,
                                                isdebugCriticalMode);
        if (!e) {
          pfr << reponame;
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
        pfr << reponame;
      }
    }
  }
  qDebug() << "procecced num repos" << ok << "from total of DEPS file "
           << repos.size();
  if (printFailedProceedRepo) {
    qDebug() << "List failed repo to proceed:" << pfr;
  }
}

std::vector<DEPSRepoFound> LocalSourcesFetcher::findAnyRepos(
    const QString &fromdeps) {
  std::vector<DEPSRepoFound> vec_res;
  typedef QPair<bool, QByteArray> ReadFileStatus;
  auto fileReader = [&](const QString &fromfile) -> ReadFileStatus {
    QFile fn(fromfile);
    if (!fn.open(QIODevice::ReadOnly)) {
      return qMakePair(false, QByteArray(""));
    }
    QByteArray buf;
    while (!fn.atEnd()) {
      buf += fn.readLine();
    }
    fn.close();
    return qMakePair(true, buf);
  };

  using namespace peg;
  parser p;
  ReadFileStatus gram_f = fileReader("://google_deps_grammar.peg");
  if (!gram_f.first) {
    qDebug() << "warning read internal grammar failed";
    return vec_res;
  }
  if (!p.load_grammar(gram_f.second)) {
    qDebug() << "warning load internal grammar failed";
    return vec_res;
  }
  p.log = [&](auto ln, auto col, const auto &msg) {
    qDebug() << "parse error " << fromdeps << ":" << ln << ":" << col << ": "
             << msg.c_str();
  };
  bool paircount = 0;
  DEPSRepoFound repo;
  p["REPODIR"] = [&](const SemanticValues &sv) -> std::string {
    if (paircount == 1) {
      auto str = QString::fromStdString(sv.str());
      str = str.remove(QChar(34), Qt::CaseInsensitive);
      QStringList gv = str.split('@');
      if (gv.size() == 2) {
        repo.linkname = gv.at(0);
        repo.gitversion = gv.at(1);
      }
      vec_res.emplace_back(repo);
      paircount = 0;
    }
    return sv.str();
  };
  p["REPONAME"] = [&](const SemanticValues &sv) -> std::string {
    if (paircount == 0) {
      repo.reponame = QString::fromStdString(sv.str());
      repo.reponame = repo.reponame.remove(QChar(34), Qt::CaseInsensitive);
      paircount = 1;
    }
    return sv.str();
  };
  ReadFileStatus inbuf = fileReader(fromdeps);
  if (!inbuf.first) {
    qDebug() << "warning read DEPS file  failed";
    return vec_res;
  }
  if (p.parse(inbuf.second.toStdString().c_str())) {
    qDebug() << "parse ok";
  } else {
    qDebug() << "parse failed";
  }

  return vec_res;
}
