# ROOT Benchmarks

This repository contains a set of relatively small programs (usually based on [gbenchmark](https://github.com/google/benchmark) micro benchmarking infrastructure) built on top of [ROOT](https://github.com/root-project/root). Their primary goal is to provide stable performance metrics which can be monitored over time.

# Project Health
|       |     |
| :---: |:---:|
| Linux/OSX [![Build Status](https://travis-ci.org/root-project/rootbench.svg?branch=master)](https://travis-ci.org/root-project/rootbench) | Experimental Benchmark Coverage: [![Coverage Status](https://coveralls.io/repos/github/root-project/rootbench/badge.svg?branch=master)](https://coveralls.io/github/root-project/rootbench?branch=master)  |  


## About
Collection of benchmarks and performance monitoring applications

## Building
ROOTBench can be built standalone and as part of ROOT. If you want to enable ROOTBench for ROOT just add the `-Drootbench=On` option to your cmake configuration.

### Building ROOTBench standalone
ROOTBench should be able to find ROOT at configuration time. Make sure you ran `source $ROOTSYS/bin/thisroot.sh`.
```bash
git clone https://github.com/root-project/rootbench.git
mkdir build
cd build
cmake ../rootbench
cmake --build . -- -j4
```
## Extending the benchmarks
ROOTBench relies on [Google Benchmark](https://github.com/google/benchmark). We recommend to read the [available documentation](https://github.com/google/benchmark/blob/master/README.md) and browse the existing examples [here](https://github.com/google/benchmark/tree/master/test) for more advanced usage.

### Background
This repository is being integrated in two steps:
  * We run TravisCI on each pull request -- the public infrastructure is time limited and we use the latest ROOT nightly build available in CVMFS and EOS. This way we can integrate with public services such as Coveralls. Based on the TravisCI information we compute the benchmarking coverage of ROOTBench against ROOT. The idea is to make sure that we have well-distributed benchmarking coverage.
  * We run on dedicated CERN OpenLab machines twice a day -- we build ROOT and ROOTBench from scratch and collect performance data. The data is uploaded to our Grafana service available [here](https://rootbnch-grafana-test.cern.ch) (requires CERN login).
  
The integration process depends on the overall benchmarking time. Contributors are encouraged to write well-focused microbenchmarks ensuring good benchmarking coverage. Non-overlapping microbenchmarks seem to be the only reasonable way to control the pressure on the infrastructure.

### Conventions
There are several practical conventions that we should follow:
  * Coding conventions -- ROOTBench follows the [coding conventions of ROOT](https://root.cern.ch/coding-conventions) to a great extent.
  * The routines used for benchmarking shall have the following names `BM_CLASSNAME_ROUTINE` -- the `BM` prefix allows us (or tools) to easily identify which is the main benchmarking function.  

### Simple benchmark template
Add file called CLASSNAMEBenchmarks.cxx where CLASSNAME is the name of the ROOT class we benchmark.

```cpp
#include "ROOT_HEADER_TO_BENCHMARK.h"

#include "benchmark/benchmark.h"

// Replace the CLASSNAME and ROUTINE with the ROOT class and routine you are benchmarking respectively. 
static void BM_CLASSNAME_ROUTINE(benchmark::State &state) {
  // Initialization section before actual benchmarking.
  for (auto _ : state) {
    // The benchmarking code goes here.
  }
  // Teardown.
}
BENCHMARK(BM_CLASSNAME_ROUTINE);

// In the end of the file we add our main().
BENCHMARK_MAIN();
```

Register the benchmark in the system. Add an entry to the `CMakeLists.txt` next to the source code of the benchmark.

```cmake
RB_ADD_GBENCHMARK(CLASSNAMEBenchmarks
  CLASSNAMEBenchmarks.cxx
  LABEL short
  LIBRARIES LIST OF LIB DEPENDENCIES)
```

This is a very basic working example. If you need extra functionality please read the [Google Benchmark Docs](https://github.com/google/benchmark/blob/master/README.md).
