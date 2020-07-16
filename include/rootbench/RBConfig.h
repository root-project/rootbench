///\file This file contains utility functions which simplify running benchmarks.
#ifndef RB_CONFIG_H
#define RB_CONFIG_H

#include <stdlib.h>

#include "rootbench/ErrorHandling.h"
#include <rootbench/Constants.h> // RB::kDatasetDirectory
#include <string>

namespace RB {
  /// Returns a path to temporary file system (preferably in-memory). The path
  /// is set in the RB_TEMP_FS environment variable.
  ///
  ///\returns invalid path if the variable is not set.
  ///
  inline std::string GetTempFs() {
    if (char* tempfs = std::getenv("RB_TEMP_FS"))
      return tempfs;

    rb_abort("Please set the RB_TEMP_FS env variable!");
  }

  inline std::string GetRootSys() {
    if (char* rootsys = std::getenv("ROOTSYS"))
      return rootsys;

    rb_abort("Please set the ROOTSYS env variable!");
  }

  /// Return the absolute path to the directory where data will be downloaded
  inline std::string GetDataDir() {
      return RB::kDatasetDirectory;
  }

  /// Like assert, but it does not disappear if -DNDEBUG
  inline void Ensure(bool b)
  {
     if (!b)
        std::abort();
  }
}

#endif
