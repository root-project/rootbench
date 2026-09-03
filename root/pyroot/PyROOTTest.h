#include <chrono>
#include <string>

#include "benchmark/benchmark.h"

#include "rootbench/MemoryMeasurement.h"
#include "rootbench/RBConfig.h"

static int runTutorial(const std::string& dir, const std::string& filename, long& maxRssKiB) {
  std::string rootsys = RB::GetRootSys();
  std::string fullpath = rootsys + "/" + dir + "/" + filename;
  // Exit with a non-zero status if the Python tutorial fails, since a failure
  // of the interpreted code does not propagate into the exit status of root
  // by itself.
  std::string rootInvocation =
      "root -l -b -q -e 'gSystem->Exit(!TPython::Exec(\"exec(open(\\\"" + fullpath + "\\\").read())\"))'";
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
