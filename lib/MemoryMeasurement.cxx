///\file Contains utilities to measure the memory usage of child processes.
#include "rootbench/MemoryMeasurement.h"

#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>

namespace RB {

int RunCommandMeasuringRss(const std::string &cmd, long &maxRssKiB)
{
   maxRssKiB = 0;

   pid_t pid = fork();
   if (pid < 0)
      return -1;
   if (pid == 0) {
      execl("/bin/sh", "sh", "-c", cmd.c_str(), static_cast<char *>(nullptr));
      _exit(127);
   }

   int status = 0;
   rusage usage{};
   if (wait4(pid, &status, 0, &usage) < 0)
      return -1;
#ifdef __APPLE__
   // On macOS, ru_maxrss is in bytes instead of KiB.
   maxRssKiB = usage.ru_maxrss / 1024;
#else
   maxRssKiB = usage.ru_maxrss;
#endif
   return status;
}

} // namespace RB
