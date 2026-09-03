///\file Utilities to measure the memory usage of child processes.
#ifndef RB_MEMORYMEASUREMENT_H
#define RB_MEMORYMEASUREMENT_H

#include <string>

namespace RB {
/// Runs the given command through the shell, like std::system(), and stores
/// the maximum resident set size of the child process tree in KiB in
/// maxRssKiB, as reported by wait4(). This is the same value that
/// "/usr/bin/time -v" reports as "Maximum resident set size", but without
/// depending on an external time binary.
///
///\returns the exit status of the command as reported by std::system(), or -1
/// if the child process could not be created.
int RunCommandMeasuringRss(const std::string &cmd, long &maxRssKiB);
} // namespace RB

#endif
