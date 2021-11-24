# Copyright (C) 1995-2019, Rene Brun and Fons Rademakers.
# All rights reserved.
#
# For the licensing terms see $ROOTSYS/LICENSE.
# For the list of contributors see $ROOTSYS/README/CREDITS.

# Find the ONNXRuntime includes and library.
#
# This module defines
# ONNXRuntime_INCLUDE_DIR, where to locate ONNXRuntime include file
# ONNXRuntime_LIBRARIES, the libraries to link against to use ONNXRuntime
# ONNXRuntime_FOUND.  If false, you cannot build anything that requires ONNXRuntime.
# ONNXRuntime_LIBRARY, where to find the libONNXRuntime library.

set(ONNXRuntime_FOUND 0)
if(ONNXRuntime_LIBRARY AND ONNXRuntime_INCLUDE_DIR)
  set(ONNXRuntime_FIND_QUIETLY TRUE)
endif()

find_path(ONNXRuntime_INCLUDE_DIR onnxruntime_cxx_api.h
  $ENV{ONNXRuntime_DIR}/include
  $ENV{ONNXRuntime} $ENV{ONNXRuntime}/include 
  /usr/local/include
  /usr/include
  DOC "Specify the directory containing ONNXRuntime.h"
)

find_library(ONNXRuntime_LIBRARY NAMES onnxruntime  PATHS
  $ENV{ONNXRuntime_DIR}/lib
  $ENV{ONNXRuntime} $ENV{ONNXRuntime}/lib $ENV{ONNXRuntime}/.libs
  /usr/local/lib
  /usr/lib
  /opt/ONNXRuntime/lib
  DOC "Specify the ONNXRuntime library here."
)

if(ONNXRuntime_INCLUDE_DIR AND ONNXRuntime_LIBRARY)
  set(ONNXRuntime_FOUND 1 )
  if(NOT ONNXRuntime_FIND_QUIETLY)
     message(STATUS "Found ONNXRuntime includes at ${ONNXRuntime_INCLUDE_DIR}")
     message(STATUS "Found ONNXRuntime library at ${ONNXRuntime_LIBRARY}")
  endif()
endif()

set(ONNXRuntime_LIBRARIES ${ONNXRuntime_LIBRARY})

mark_as_advanced(ONNXRuntime_FOUND ONNXRuntime_LIBRARY ONNXRuntime_INCLUDE_DIR)
