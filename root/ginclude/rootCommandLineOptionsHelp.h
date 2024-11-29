#ifndef ROOT_rootCommandLineOptionsHelp
#define ROOT_rootCommandLineOptionsHelp
constexpr static const char kCommandLineOptionsHelp[] = R"RAW(
usage: root [-b B] [-x X] [-e E] [-n N] [-t T] [-q Q] [-l L] [-a A] [-config CONFIG] [-h HELP]
            [--version VERSION] [--notebook NOTEBOOK] [--web WEB] [--web=<browser> WEB=<BROWSER>]
            [dir] [data1.root...dataN.root] [file1.C...fileN.C]

ROOTs Object-Oriented Technologies.

root is an interactive interpreter of C++ code. It uses the ROOT  framework.  For  more information on ROOT, please refer to

An extensive Users Guide is available from that site (see below).


OPTIONS:
  -b                                   Run in batch mode without graphics
  -x                                   Exit on exceptions
  -e                                   Execute the command passed between single quotes
  -n                                   Do not execute logon and logoff macros as specified in .rootrc
  -t                                   Enable thread-safety and implicit multi-threading (IMT)
  -q                                   Exit after processing command line macro files
  -l                                   Do not show the ROOT banner
  -a                                   Show the ROOT splash screen
  -config                              print ./configure options
  -h, -?, --help                       Show summary of options
  --version                            Show the ROOT version
  --notebook                           Execute ROOT notebook
  --web                                Display graphics in a default web browser
  --web=<browser>                      Display graphics in specified web browser
  [dir]                                if dir is a valid directory cd to it before executing
  [data1.root...dataN.root]            Open the given ROOT files; remote protocols (such as http://) are supported
  [file1.C...fileN.C]                  Execute the ROOT macro file1.C ... fileN.C.
                                       Compilation flags as well as macro arguments can be passed, see format in https://root.cern/manual/root_macros_and_shared_libraries/
)RAW";
#endif
