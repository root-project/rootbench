#ifndef ROOT_hist2workspaceCommandLineOptionsHelp
#define ROOT_hist2workspaceCommandLineOptionsHelp
constexpr static const char kCommandLineOptionsHelp[] = R"RAW(
usage: hist2workspace [-h] [-v] [-vv] [-disable_binned_fit_optimization]

hist2workspace is a utility to create RooFit/RooStats workspace from histograms

OPTIONS:
  -h, --help                                  show this help message and exit
  -v                                          switch HistFactory message stream to INFO level
  -vv                                         switch HistFactory message stream to DEBUG level
  -disable_binned_fit_optimization            disable the binned fit optimization used in HistFactory since ROOT 6.28
)RAW";
#endif
