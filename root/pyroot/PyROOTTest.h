#include "rootbench/MemoryMeasurement.h"
#include "benchmark/benchmark.h"
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

static int runTutorial(const std::string& dir, const std::string& filename, std::string& perftutorial) {
  std::string rootInvocation;
  std::string rootexe = "\" root -l -b -q -e 'TPython::Exec(\" exec( open('";
  std::string endInvoc = "').read())\")'";
  perftutorial = getMemoryStats(dir,filename,rootInvocation, rootexe, endInvoc);
  return std::system(rootInvocation.c_str());
}

static void TestTutorial(benchmark::State &state, const char *dir, const char *tutorial) {
  int peakSize = 0;
  for(auto _ : state){
      auto start = std::chrono::high_resolution_clock::now();
      std::string perftutorial="";
      runTutorial(dir, tutorial, perftutorial);
      auto end = std::chrono::high_resolution_clock::now();
      auto elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
      state.SetIterationTime(elapsed_seconds.count());
      peakSize = getMemoryMeasurement(perftutorial);
   }
   state.counters.insert({{"RSS", peakSize}});
}
