#include <iostream>
#include <cstdlib>
#include <string>

#include <unistd.h>

#include "benchmark/benchmark.h"

static int runTutorial(const std::string& dir, const std::string& filename) {
  if (getenv("ROOTSYS") == nullptr) {
    std::cerr << "Couldn't find ROOTSYS environment variable!\n";
    exit(1);
  }
  std::string rootsys = getenv("ROOTSYS");
  std::string fullpath = rootsys + "/" + dir + "/" + filename;
  std::string thisroot = rootsys + "/bin/thisroot.sh";
  // FIXME: no source in /usr/dash
  std::string rootInvocation = "source \"" + thisroot + "\" && root.exe -l -q -b -n -x \"" + fullpath + "\" -e return ";
    return std::system(rootInvocation.c_str());
}

static void TestTutorial(benchmark::State &state, const char *dir, const char *tutorial) {
  // size_t peakSize = 0;
  for(auto _ : state){
      runTutorial(dir, tutorial);
   }
  // state.counters["PeakRSS"] = peakSize;
}