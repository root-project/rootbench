
#include <stdlib.h>

namespace RB {
  /// Returns a path to temporary file system (preferably in-memory). The path
  /// is set in the RB_TEMP_FS environment variable.
  ///
  ///\returns invalid path if the variable is not set.
  ///
  const char* GetTempFs() {
    if (char* tempfs = std::getenv("RB_TEMP_FS"))
      return tempfs;
    // Instead of aborting return something that cannot be a path.
    return "@@@ Please set the RB_TEMP_FS env variable @@@";
  }
}
