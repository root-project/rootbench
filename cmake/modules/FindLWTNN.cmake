# Copyright (C) 1995-2019, Rene Brun and Fons Rademakers.
# All rights reserved.
#
# For the licensing terms see $ROOTSYS/LICENSE.
# For the list of contributors see $ROOTSYS/README/CREDITS.

# Find the LWTNN includes and library.
#
# This module defines
# LWTNN_INCLUDE_DIR, where to locate LWTNN.h file
# LWTNN_LIBRARIES, the libraries to link against to use LWTNN
# LWTNN_FOUND.  If false, you cannot build anything that requires LWTNN.
# LWTNN_LIBRARY, where to find the libLWTNN library.

set(LWTNN_FOUND 0)
if(LWTNN_LIBRARY AND LWTNN_INCLUDE_DIR)
  set(LWTNN_FIND_QUIETLY TRUE)
endif()

find_path(LWTNN_INCLUDE_DIR lwtnn/Graph.hh
  $ENV{LWTNN_DIR}/include
  $ENV{LWTNN} $ENV{LWTNN}/include 
  /usr/local/include
  /usr/include
  DOC "Specify the directory containing LWTNN.h"
)

find_library(LWTNN_LIBRARY NAMES lwtnn  PATHS
  $ENV{LWTNN_DIR}/lib
  $ENV{LWTNN} $ENV{LWTNN}/lib $ENV{LWTNN}/.libs
  /usr/local/lib
  /usr/lib
  /opt/LWTNN/lib
  DOC "Specify the lwtnn library here."
)

if(LWTNN_INCLUDE_DIR AND LWTNN_LIBRARY)
  set(LWTNN_FOUND 1 )
  if(NOT LWTNN_FIND_QUIETLY)
     message(STATUS "Found LWTNN includes at ${LWTNN_INCLUDE_DIR}")
     message(STATUS "Found LWTNN library at ${LWTNN_LIBRARY}")
  endif()
endif()

set(LWTNN_LIBRARIES ${LWTNN_LIBRARY})

mark_as_advanced(LWTNN_FOUND LWTNN_LIBRARY LWTNN_INCLUDE_DIR)
