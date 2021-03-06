#ifndef SINKRONGITHANDLER_H
#define SINKRONGITHANDLER_H

#include <QDir>
#include <QStringList>

class SinkronGitHandler {
 public:
  SinkronGitHandler();
  ~SinkronGitHandler();
  static bool processDirs(const QString &basedir, const QString &baseName,
                          const QString &gitexedir, const QString &gitCommitID,
                          const QString &outputDir, bool isDebugCriticalMode);

  static bool cloneMissingRepo(const QString &gitexedir, const QString &url,
                               const QString &outputDir,
                               bool isDebugCriticalMode);

 private:
  static bool runGitAndEkstractCommit(const QString &path,
                                      const QString &gitexedir,
                                      const QString &commitID,
                                      bool isDebugCriticalMode);
  static bool cloneFreshRepoFromCommit(const QString &gitexedir,
                                       const QString &url,
                                       const QString &outDir,
                                       bool isDebugCriticalMode);
									   
  static bool maybeNeedUpdateRepo(const QString &path,
                                      const QString &gitexedir);

  /*
   * TODO
   *  require proper git check dir and it's exit status code.
   * */
  static bool isThatFolderisGitDir(const QString &fromdir,
                                   const QString &gitexedir);

  static QString getDefaultGitInPath();
};

#endif  // SINKRONGITHANDLER_H