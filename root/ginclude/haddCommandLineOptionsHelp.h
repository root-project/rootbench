#ifndef ROOT_haddCommandLineOptionsHelp
#define ROOT_haddCommandLineOptionsHelp
constexpr static const char kCommandLineOptionsHelp[] = R"RAW(
usage: hadd [-a] [-f] [-f[0-9]] [-fk] [-ff] [-k] [-O] [-T] [-v V] [-j J] [-dbg] [-d D] [-n N]
            [-cachesize CACHESIZE] [-experimental-io-features EXPERIMENTAL_IO_FEATURES]
            TARGET SOURCES

This program will add histograms, trees and other objects from a list
of ROOT files and write them to a target ROOT file. The target file is
newly created and must not exist, or if -f ("force") is given, must
not be one of the source files.

OPTIONS:
  -a                                   Append to the output
  -f                                   Force overwriting of output file
  -f[0-9]                              Gives the ability to specify the compression level of the target file.
                                       Default is 1 (kDefaultZLIB), 0 is uncompressed, 9 is maximum
                                       compression (see TFile::TFile documentation). You can also specify the
                                       full compresion algorithm, e.g. -f206
  -fk                                  Sets the target file to contain the baskets with the same compression
                                       as the input files (unless -O is specified). Compresses the meta data
                                       using the compression level specified in the first input or the
                                       compression setting after fk (for example 206 when using -fk206)
  -ff                                  The compression level use is the one specified in the first input
  -k                                   Skip corrupt or non-existent files, do not exit
  -O                                   Re-optimize basket size when merging TTree
  -T                                   Do not merge Trees
  -v                                   Explicitly set the verbosity level: 0 request no output, 99 is the
                                       default
  -j                                   Parallelize the execution in 'J' processes. If the number of processes
                                       is not specified, use the system maximum.
  -dbg                                 Enable verbosity. If -j was specified, do not not delete partial files
                                       stored inside working directory.
  -d                                   Carry out the partial multiprocess execution in the specified
                                       directory
  -n                                   Open at most 'N' files at once (use 0 to request to use the system
                                       maximum)
  -cachesize                           Resize the prefetching cache use to speed up I/O operations (use 0 to
                                       disable)
  -experimental-io-features            Used with an argument provided, enables the corresponding experimental
                                       feature for output trees. See ROOT::Experimental::EIOFeatures
  TARGET                               Target file
  SOURCES                              Source files

If TARGET and SOURCES have different compression settings a slower
method is used. For options that takes a size as argument, a decimal
number of bytes is expected. If the number ends with a ``k'', ``m'',
``g'', etc., the number is multiplied by 1000 (1K), 1000000 (1MB),
1000000000 (1G), etc. If this prefix is followed by i, the number is
multiplied by the traditional 1024 (1KiB), 1048576 (1MiB), 1073741824
(1GiB), etc. The prefix can be optionally followed by B whose casing
is ignored, eg. 1k, 1K, 1Kb and 1KB are the same.
)RAW";
#endif
