#include <chrono>
#include <string>

#include "benchmark/benchmark.h"

#include "rootbench/MemoryMeasurement.h"
#include "rootbench/RBConfig.h"

static int runTutorial(const std::string& dir, const std::string& filename, long& maxRssKiB) {
  std::string rootsys = RB::GetRootSys();
  std::string rootInvocation;
  if (!filename.empty()) {
    std::string fullpath = rootsys + "/" + dir + "/" + filename;
    rootInvocation = "root.exe -l -q -b -n -x \"" + fullpath + "\" -e return ";
  } else {
    rootInvocation = "root.exe -l -q -b ";
  }

  return RB::RunCommandMeasuringRss(rootInvocation, maxRssKiB);
}

static void TestTutorial(benchmark::State &state, const char *dir, const char *tutorial) {
  long peakSizeKiB = 0;
  for(auto _ : state){
      auto start = std::chrono::high_resolution_clock::now();
      int status = runTutorial(dir, tutorial, peakSizeKiB);
      auto end   = std::chrono::high_resolution_clock::now();
      if (status != 0) {
         state.SkipWithError(("failed to run tutorial \"" + std::string(tutorial) + "\"").c_str());
         return;
      }
      auto elapsed_seconds =
      std::chrono::duration_cast<std::chrono::duration<double>>(
        end - start);
      state.SetIterationTime(elapsed_seconds.count());
   }
   state.counters.insert({{"RSS", static_cast<double>(peakSizeKiB)}});
}
