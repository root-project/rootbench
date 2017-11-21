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
  std::string rootInvocation = "root.exe -l -q -b -n -x \"" + fullpath + "\" -e return ";
  return std::system(rootInvocation.c_str());
}

static void TestTutorial(benchmark::State &state, const char *dir, const char *tutorial) {
   while (state.KeepRunning())
      runTutorial(dir, tutorial);
}

BENCHMARK_CAPTURE(TestTutorial, Test_hsimple, "tutorials/", "hsimple.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_TMVAGAexample, "tutorials/", "tmva/TMVAGAexample.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_hvector, "tutorials/", "tree/hvector.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_hinvertMatrix, "tutorials/", "matrix/invertMatrix.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_invertMatrix, "tutorials/", "math/invertMatrix.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_fitLinear, "tutorials/", "fit/fitLinear.C")->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
