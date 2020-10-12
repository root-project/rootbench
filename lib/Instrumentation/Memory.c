/// \file Memory.c
///
/// The file contains code of the C memory instrumentation library.
///
/// \author Vassil Vassilev <vvasilev@cern.ch>
///
/// \date Oct, 2020
///


#include "rootbench/Instrumentation/Memory.h"

#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#undef _GNU_SOURCE

static void* (*real_malloc)(size_t) = NULL;

static void mtrace_init(void) {
  real_malloc = dlsym(RTLD_NEXT, "malloc");
  if (!real_malloc) {
    fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
  }
}

static struct malloc_stats cur_malloc_stats;
void reset_malloc_stats() {
  cur_malloc_stats.num_malloc_calls = 0;
  cur_malloc_stats.max_bytes_used = 0;
}

const struct malloc_stats get_current_malloc_stats() {
  return cur_malloc_stats;
}

void *malloc(size_t size) {
  if(!real_malloc)
    mtrace_init();

  void *p = NULL;
  p = real_malloc(size);
  cur_malloc_stats.num_malloc_calls++;
  cur_malloc_stats.max_bytes_used += size;

  return p;
}
