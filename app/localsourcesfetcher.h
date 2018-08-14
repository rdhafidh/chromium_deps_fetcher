#ifndef LOCALSOURCESFETCHER_H
#define LOCALSOURCESFETCHER_H 

#include <vector>
#include <QByteArray>
#include <QStringList>

class LocalSourcesFetcher
{
public:
    LocalSourcesFetcher ();
    ~LocalSourcesFetcher(); 
    /*
     * fromdeps = DEPS file
     * excludedrepo = if any, that is comma separated
     * localsourcedir = target local copy dir of your cloned repo, assuming any DEPS  repos is on this directory
     * outdir = output directory folder to unpack  
     * gitexedir = git app exe dir
     * */
    void  doFetch(const QString &fromdeps, const QStringList &excludedrepo,  const QString &localsourcedir, const QString &outdir,
                  const QString &gitexedir, bool isdebugCriticalMode, bool printFailedProceedRepo, bool autoDldIFMissingRepoFromSys);
private: 
   
};

#endif // LOCALSOURCESFETCHER_H