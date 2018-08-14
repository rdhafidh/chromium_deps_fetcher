#include "sinkrongithandler.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QProcess>
#include <QProcessEnvironment>
#include <QString>
#include <elzip.hpp>

SinkronGitHandler::SinkronGitHandler() {}

SinkronGitHandler::~SinkronGitHandler() {}

bool SinkronGitHandler::isThatFolderisGitDir(const QString &fromdir,
                                             const QString &gitexedir) {
  QStringList cmd;
  cmd << "-C";
  cmd << fromdir;
  cmd << "show";
  QString actualgit = gitexedir.isEmpty() ? getDefaultGitInPath() : gitexedir;
  int ret = QProcess::execute(actualgit, cmd);
  if (ret != 0) {
    qDebug() << "failed to spawn git in path";
    return false;
  }
  return true;
}

QString SinkronGitHandler::getDefaultGitInPath() {
  QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
  QString paths = env.value("PATH");
  QStringList path;
#ifdef Q_OS_WIN
  path = paths.split(';');
#else
  path = paths.split(':');
#endif
  QString gitpath = "";
  for (const QString &indivpath : path) {
    QString finalpath = indivpath;
#ifdef Q_OS_WIN
    finalpath += "\\git.exe";
#else
    finalpath += "/git";
#endif
    QFileInfo inf(finalpath);
    if (inf.exists() && inf.isExecutable()) {
      gitpath = finalpath;
      break;
    }
  }
  return gitpath;
}

bool SinkronGitHandler::processDirs(const QString &basedir,
                                    const QString &baseName,
                                    const QString &gitexedir,
                                    const QString &gitCommitID,
                                    const QString &outputDir,
                                    bool isDebugCriticalMode) {
  QString path = basedir + "/" + baseName;
  if (runGitAndEkstractCommit(path, gitexedir, gitCommitID,
                              isDebugCriticalMode)) {
    auto fp = path + "/" + "out.zip";
    auto outName = outputDir.toStdString() + "/" + baseName.toStdString();
    elz::extractZip(fp.toStdString(), outName, isDebugCriticalMode);
    QFile::remove(fp);
    qDebug() << "done processing " << baseName << "repo";
    return true;
  } else {
    qDebug() << "failed to process " << baseName << "repo";
  }
  return false;
}

bool SinkronGitHandler::cloneMissingRepo(const QString &gitexedir,
                                         const QString &url,
                                         const QString &outputDir,
                                         bool isDebugCriticalMode) {
  if (!cloneFreshRepoFromCommit(gitexedir, url, outputDir,
                                isDebugCriticalMode)) {
    qDebug() << "warning cloneFreshRepoFromCommit failed ";
    return false;
  }
  return true;
}

bool SinkronGitHandler::runGitAndEkstractCommit(const QString &path,
                                                const QString &gitexedir,
                                                const QString &commitID,
                                                bool isDebugCriticalMode) {
  QStringList list;
  QString fpout = path + "/" + "out.zip";
  list << "-C" << path << "archive" << commitID << "--format"
       << "zip"
       << "--output" << fpout;
  QString actualgit = gitexedir.isEmpty() ? getDefaultGitInPath() : gitexedir;
  if (isDebugCriticalMode) qDebug() << "generated cmd" << list;
  int ret = QProcess::execute(actualgit, list);
  if (isDebugCriticalMode)
    qDebug() << "ret runGitAndEkstractCommit " << ret << "using gitexe from"
             << actualgit;
  return ret == 0;
}

bool SinkronGitHandler::cloneFreshRepoFromCommit(const QString &gitexedir,
                                                 const QString &url,
                                                 const QString &outDir,
                                                 bool isDebugCriticalMode) {
  QStringList cmd;
  cmd << "clone";
  cmd << url << outDir;
  if (isDebugCriticalMode)
    qDebug() << "generated cmd cloneFreshRepoFromCommit" << cmd;
  QString actualgit = gitexedir.isEmpty() ? getDefaultGitInPath() : gitexedir;
  int ret = QProcess::execute(actualgit, cmd);
  if (isDebugCriticalMode)
    qDebug() << "ret cloneFreshRepoFromCommit " << ret << "using gitexe from"
             << actualgit;
  return ret == 0;
}
