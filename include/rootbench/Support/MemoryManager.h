/// \file MemoryManager.h
///
/// The file contains the implementation of benchmark memory tracking.
///
/// \author Vassil Vassilev <vvasilev@cern.ch>
///
/// \date Oct, 2020
///

#ifndef RB_MEMORY_MANAGER_H
#define RB_MEMORY_MANAGER_H

#include "benchmark/benchmark.h"

#include <memory>

namespace RB {
  /// Records number of allocations per iteration and the maximum bites used
  /// for a benchmark.
  struct MemoryManager : public benchmark::MemoryManager {
    size_t cur_num_allocs = 0;
    size_t cur_max_bytes_used = 0;
    void Start() override;
    void Stop(Result* result) override;
  };
} // end RB

namespace {
  static auto mm = std::unique_ptr<RB::MemoryManager>(new RB::MemoryManager());
  static struct InstrumentationRegistrer {
    InstrumentationRegistrer() {
      benchmark::RegisterMemoryManager(mm.get());
    }
    ~InstrumentationRegistrer() {
      benchmark::RegisterMemoryManager(nullptr);
    }
  } __mem_mgr_register;
}


#endif // RB_MEMORY_MANAGER_H
