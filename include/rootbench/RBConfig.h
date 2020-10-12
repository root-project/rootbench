///\file This file contains utility functions which simplify running benchmarks.
#ifndef RB_CONFIG_H
#define RB_CONFIG_H

#include <rootbench/Constants.h> // RB::kDatasetDirectory

#include "rootbench/Support/ErrorHandling.h"

#include <string>

#include <stdlib.h>

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

  constexpr const char* GetPreloadEnvVar() {
#ifdef __APPLE__
    // FIXME: Remove the need of DYLD_FORCE_FLAT_NAMESPACE by using interposing.
    return "DYLD_INSERT_LIBRARIES";
#elif defined(RB_ON_UNIX)
    return "LD_PRELOAD";
#else
# error Unsupported Platform;
#endif
  }

  /// Checks if we have set up the LD_PRELOAD mechanism for binary
  /// instrumentation
  inline bool IsLdPreloadEnabled() {
    if (char* rootsys = std::getenv(GetPreloadEnvVar()))
      return true;
    return false;
  }

  /// Return the absolute path to the directory where data will be downloaded
  inline std::string GetDataDir() {
    return RB::kDatasetDirectory;
  }

  /// Like assert, but it does not disappear if -DNDEBUG
  inline void Ensure(bool b, const std::string& reason = "")
  {
    if (!b) {
      printf("Aborting with reason: '%s'\n", reason.c_str());
      std::abort();
    }
  }
}

#endif
