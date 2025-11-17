/// \file Memory.h
///
/// The file contains interfaces of the C memory instrumentation library.
///
/// \author Vassil Vassilev <vvasilev@cern.ch>
///
/// \date Oct, 2020
///

#ifndef RB_MEMORY_H
#define RB_MEMORY_H

#include <stddef.h>

struct malloc_stats {
  size_t num_malloc_calls;
  size_t max_bytes_used;
};

void reset_malloc_stats();
const struct malloc_stats get_current_malloc_stats();


#endif // RB_MEMORY_H
