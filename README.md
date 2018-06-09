# chromium_deps_fetcher 

A simple tool to selectively fetch chromium based project of DEPS file git submodule.
When working with chromium based project, sometimes it is useful to have selectively
to fetch only certain git submodule. But wait, there has been a tool called [depot](https://commondatastorage.googleapis.com/chrome-infra-docs/flat/depot_tools/docs/html/depot_tools_tutorial.html).
Why want to re-invent another wheel? 

1. The depot tool always downloads blindly the submodule repository, 
this is very detrimental if you have fast bandwidth but limited internet quota volume.
With using this tool you can just fetch from sysroot git local cloned repo of certain DEPS file.
2. Supporting initial download all repository from certain DEPS file [TODO]. 
3. Auto download fresh copy of repository from missing local sysroot of cloned git repository. 

### Installation

Some requirements to build this tool :

1. [Qt 5.6>=](https://www.qt.io/) (only qt core module)
2. [CMake](https://cmake.org/download/) (the lastest version is better, currently 3.11)
3. [Ninja](https://github.com/ninja-build/ninja) (Optional)
4. C++17 compiler (MSVC 2017, Clang 6 or 7)
5. Git (Lastest version is better)

### Building 

Try run :

```
cmake -DCMAKE_BUILD_TYPE=Release -DQt5Core_DIR=$QT_ROOT/lib/cmake/Qt5Core -G Ninja /where/src/chromium_deps_fetcher
ninja
```

Where $QT_ROOT is your sysroot of your Qt 5 directory.

### Usage 
```
$ ./chromium_deps_fetcher
Usage: chromium_deps_fetcher [options]

Options:
  -?, -h, --help                             Displays this help.
  -v, --version                              Displays version information.
  -l                                         From local copy mode, currently
                                             must invoke this, default
  --dbg                                      Show critical debugging msessage
  --adl                                      Auto download fresh copy repo if
                                             missing from sysroot dir
  --pfr                                      Print all failed repo to be
                                             procceed
  -e, --exclude <separate_comma_repo_names>  excluded repo (in separate
                                             commas)...
  --fd, --fromdir <from_dir>                 target local copy dir of your
                                             cloned repo, assuming any DEPS 
                                             repos is on this directory
  -g, --git <git_exe_dir>                    From git app exe dir
  -o, --outdir <out_dir>                     output directory folder to unpack 
  --dp <DEPS_FILE>                           Choose DEPS file

```

The -l mode flag is currently default and must be invoked since I want to have another possible usecase as well when working 
with DEPS file or feel free you can suggest a new feature request.

### Limitions
Currently this tool is heavily tested against [Google Skia](https://skia.org) project. 
If you find any bugs, welcome any pull request.


### License 
MIT License