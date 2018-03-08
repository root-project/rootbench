///\file This file contains utility functions which simplify running benchmarks.

#include <stdlib.h>

#include "rootbench/ErrorHandling.h"

namespace RB {
  /// Returns a path to temporary file system (preferably in-memory). The path
  /// is set in the RB_TEMP_FS environment variable.
  ///
  ///\returns invalid path if the variable is not set.
  ///
  const char* GetTempFs() {
    if (char* tempfs = std::getenv("RB_TEMP_FS"))
      return tempfs;
    else {
       rb_unreachable("Please set the RB_TEMP_FS env variable!");
       return nullptr;
    }
  }

  const char* GetRootSys() {
    if (char* rootsys = std::getenv("ROOTSYS"))
      return rootsys;
    else {
       rb_unreachable("Please set the ROOTSYS env variable!");
       return nullptr;
    }
  }
}
