#include "sinkrongithandler.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QString>
#include <libs/elzip.hpp>

SinkronGitHandler::SinkronGitHandler() {}

SinkronGitHandler::~SinkronGitHandler() {}

bool SinkronGitHandler::haveGitInPath(const QString &gitexedir) {
  QFileInfo inf(gitexedir);
  return inf.isFile();
}

bool SinkronGitHandler::isThatFolderisGitDir(const QString &fromdir,
                                             const QString &gitexedir) {
  QStringList cmd;
  cmd << "-C";
  cmd << fromdir;
  cmd << "show";

  int ret = QProcess::execute(gitexedir, cmd);
  if (ret != 0) {
    qDebug() << "failed to spawn git in path";
    return false;
  }
  return true;
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

bool SinkronGitHandler::cloneMissingRepo(
                                         const QString &gitexedir,
                                         const QString &url,
                                         const QString &outputDir,
                                         bool isDebugCriticalMode) {
    
    if(!cloneFreshRepoFromCommit(gitexedir,url,outputDir,isDebugCriticalMode)){
        qDebug()<<"warning cloneFreshRepoFromCommit failed ";
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
  if (isDebugCriticalMode) qDebug() << "generated cmd" << list;
  int ret = QProcess::execute(gitexedir, list);
  if (isDebugCriticalMode)
    qDebug() << "ret runGitAndEkstractCommit " << ret << "using gitexe from"
             << gitexedir;
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
  int ret = QProcess::execute(gitexedir, cmd);
  if (isDebugCriticalMode)
    qDebug() << "ret cloneFreshRepoFromCommit " << ret << "using gitexe from"
             << gitexedir;
  return ret == 0;
}
