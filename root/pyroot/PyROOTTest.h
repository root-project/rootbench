#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include <unistd.h>

#include "benchmark/benchmark.h"

#include <chrono>

#include "rootbench/RBConfig.h"

static int runTutorial(const std::string& dir, const std::string& filename) {
  std::string rootsys = RB::GetRootSys();
  std::string fullpath = rootsys + "/" + dir + "/" + filename;
  std::string rootInvocation = "root -l -b -q -e 'TPython::Exec(\" exec( open(\"" + fullpath + "\").read())\")'";
    return std::system(rootInvocation.c_str());
}

static void TestTutorial(benchmark::State &state, const char *dir, const char *tutorial) {
  int peakSize = 0;
  for(auto _ : state){
      auto start = std::chrono::high_resolution_clock::now();
      runTutorial(dir, tutorial);
      auto end   = std::chrono::high_resolution_clock::now();
      auto elapsed_seconds =
      std::chrono::duration_cast<std::chrono::duration<double>>(
        end - start);
      state.SetIterationTime(elapsed_seconds.count());
   }
   state.counters.insert({{"RSS", peakSize}});
}
