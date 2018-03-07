///\file Contains utilities to handle error situations.

#include "rootbench/ErrorHandling.h"

#include <iostream>

void RB::rb_unreachable_internal(const char *msg, const char *file,
                                   unsigned line) {
  // This code intentionally doesn't call the ErrorHandler callback, because
  // rb_unreachable is intended to be used to indicate "impossible"  situations,
  // and not legitimate runtime errors.
  if (msg)
    std::cerr << msg << "\n";
  std::cerr << "UNREACHABLE executed";
  if (file)
    std::cerr << " at " << file << ":" << line;
  std::cerr << "!\n";
  abort();
#ifdef RB_BUILTIN_UNREACHABLE
  // Windows systems and possibly others don't declare abort() to be noreturn,
  // so use the unreachable builtin to avoid a Clang self-host warning.
  RB_BUILTIN_UNREACHABLE;
#endif
}
