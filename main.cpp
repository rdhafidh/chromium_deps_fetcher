#include <QCoreApplication>
#include <QCommandLineParser>
#include <iostream>
#include <QDebug>
#include <localsourcesfetcher.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("Chromium DEPS Fetcher");
    QCoreApplication::setApplicationVersion("0.1.0");
     
    QCommandLineParser parser;
    parser.addHelpOption ();
    parser.addVersionOption ();
    QCommandLineOption localCpMode("l", QCoreApplication::translate("main", "From local copy mode, currently must invoke this, default"));
    parser.addOption(localCpMode);
    
    QCommandLineOption dbgMode("dbg", QCoreApplication::translate("main", "Show critical debugging msessage"));
    parser.addOption(dbgMode);
    
    QCommandLineOption printFailedRepo("pfr", QCoreApplication::translate("main", "Print all failed repo to be procceed"));
    parser.addOption(printFailedRepo);
    
    QCommandLineOption ex(QStringList()<<"e"<<"exclude", QCoreApplication::translate("main", "excluded repo (in separate commas)..."),"separate_comma_repo_names");
    parser.addOption (ex);
    
    QCommandLineOption localCPDir(QStringList()<<"fd"<<"fromdir", QCoreApplication::translate("main", "target local copy dir of your cloned repo, assuming any DEPS  repos is on this directory"),"from_dir");
    parser.addOption (localCPDir);
    
    QCommandLineOption gitExeDir(QStringList()<<"g"<<"git", QCoreApplication::translate("main", "From git app exe dir"),"git_exe_dir");
    parser.addOption (gitExeDir);
    
    QCommandLineOption outDir(QStringList()<<"o"<<"outdir", QCoreApplication::translate("main", "output directory folder to unpack  "),"out_dir");
    parser.addOption (outDir);
    
    QCommandLineOption depsfile("dp", QCoreApplication::translate("main", "Choose DEPS file"),"DEPS_FILE");
    parser.addOption(depsfile);
    parser.process (a);
    if( parser.isSet (depsfile) &&
            parser.isSet (localCpMode) && parser.isSet (localCPDir)
            && parser.isSet (outDir) && 
            parser.isSet (gitExeDir)) { 
        LocalSourcesFetcher lsf; 
        QStringList excludedrepo;
        if(parser.isSet (ex)){
            excludedrepo=parser.value (ex).split (',');
        }
        lsf.doFetch (parser.value (depsfile),excludedrepo,parser.value (localCPDir)
                     ,parser.value (outDir),parser.value (gitExeDir),parser.isSet (dbgMode)
                     ,parser.isSet (printFailedRepo));
    }else{
        parser.showHelp (0);
    }
    return 0;
}
