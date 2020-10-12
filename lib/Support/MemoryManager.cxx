/// \file MemoryManager.h
///
/// The file contains interfaces for benchmark memory tracking.
///
/// \author Vassil Vassilev <vvasilev@cern.ch>
///
/// \date Oct, 2020
///

#include <rootbench/Support/MemoryManager.h>

#include <rootbench/RBConfig.h>

extern "C" {
  #include <rootbench/Instrumentation/Memory.h>
}

#include <benchmark/benchmark.h>

// FIXME: Remove the need of DYLD_FORCE_FLAT_NAMESPACE by using interposing.
static void EnsureFlatNamespaceOSX() {
#ifdef __APPLE__
  RB::Ensure(std::getenv("DYLD_FORCE_FLAT_NAMESPACE"),
             "DYLD_FORCE_FLAT_NAMESPACE not set.");
#endif // __APPLE__
}

namespace RB {
  void MemoryManager::Start() {
    Ensure(IsLdPreloadEnabled(), std::string(GetPreloadEnvVar()) + " not set.");
    EnsureFlatNamespaceOSX();
    cur_num_allocs = 0;
    cur_max_bytes_used = 0;
    reset_malloc_stats();
  }

  void MemoryManager::Stop(Result* result) {
    Ensure(IsLdPreloadEnabled(), std::string(GetPreloadEnvVar()) + " not set.");
    EnsureFlatNamespaceOSX();
    const malloc_stats& stats = get_current_malloc_stats();
    result->num_allocs = stats.num_malloc_calls;
    result->max_bytes_used = stats.max_bytes_used;
  }
} // end RB
