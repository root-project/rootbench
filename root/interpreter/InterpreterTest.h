#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include <unistd.h>

#include "benchmark/benchmark.h"

#include <chrono>

static int runTutorial(const std::string& dir, const std::string& filename, const std::string& perffile) {
  if (getenv("ROOTSYS") == nullptr) {
    std::cerr << "Couldn't find ROOTSYS environment variable!\n";
    exit(1);
  }
  std::string rootsys = getenv("ROOTSYS");
  std::string fullpath = rootsys + "/" + dir + "/" + filename;
  std::string thisroot = rootsys + "/bin/thisroot.sh";
  // FIXME: no source in /usr/dash
  // We are writing /usr/bin/time -v output in file to get maximum resident memory for the benchmark
  std::string rootInvocation = "source \"" + thisroot + "\" && /usr/bin/time -v -o \"" + perffile + "\" root.exe -l -q -b -n -x \"" + fullpath + "\" -e return ";
    return std::system(rootInvocation.c_str());
}

static void TestTutorial(benchmark::State &state, const char *dir, const char *tutorial) {
  int peakSize = 0;
  std::string perftutorial ("perfile.txt");
  for(auto _ : state){
      auto start = std::chrono::high_resolution_clock::now();
      runTutorial(dir, tutorial,perftutorial);
      auto end   = std::chrono::high_resolution_clock::now();
      auto elapsed_seconds =
      std::chrono::duration_cast<std::chrono::duration<double>>(
        end - start);
      state.SetIterationTime(elapsed_seconds.count());
      std::string memorytutorial = "cat \"" + perftutorial + "\"| grep 'Maximum resident set size' | awk '{print $6}' > tmp_mem_file";
      std::system(memorytutorial.c_str());
      std::ifstream("tmp_mem_file") >> peakSize;
   }
   state.counters.insert({{"RSS", peakSize}});
}