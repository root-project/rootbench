#[============================================================================[

Author:         Federico Sossai (fsossai), 2021
Description:    CMake script for finding the ONNXRuntime library.
Usage:          The user must provide the directory in which ONNXRuntime is installed
                together with the one in which it has been built by setting the
                following variables:
                ONNXRuntime_SRC       (e.g. /home/repo/onnxruntime) [MADATORY]
                ONNXRuntime_BUILD     (e.g. /home/repo/onnxruntime/build)
                If ONNXRuntime_BUILD is not set ${ONNXRuntime_SRC}/build is assumed
                as default value.

Result Variables
^^^^^^^^^^^^^^^^

This module defines the following variables::

  ONNXRuntime_FOUND           - True if ONNXRuntime was found
  ONNXRuntime_INCLUDE_DIRS    - include directories for ONNXRuntime
  ONNXRuntime_LIBRARIES       - link against this library to use ONNXRuntime
  ONNXRuntime_VERSION_STRING  - Full version of ONNXRuntime (e.g. 1.8.0)
  ONNXRuntime_VERSION_MAJOR   - The major version of the ONNXRuntime implementation
  ONNXRuntime_VERSION_MINOR   - The minor version of the ONNXRuntime implementation
  ONNXRuntime_VERSION_PATCH   - The patch version of the ONNXRuntime implementation
  ONNXRuntime_BUILD_TYPE      - Describes whether the current build is
                              - Debug, MinSizeRel Release or RelWithDebInfo
  

The module will also define two cache variables::

  ONNXRuntime_OS              - Operating system that the library has been built for
  ONNXRuntime_INCLUDE_DIR     - Identical to ONNXRuntime_INCLUDE_DIRS
  ONNXRuntime_LIBRARY         - Identical to ONNXRuntime_LIBRARIES

#]============================================================================]


if(ONNXRuntime_SRC)

  if(NOT ONNXRuntime_BUILD)
    set(ONNXRuntime_BUILD ${ONNXRuntime_SRC}/build)
    message(STATUS "Assuming ${ONNXRuntime_BUILD} as the build directory for ONNXRuntime")
  endif()

  # Setting ONNXRuntime_OS
  #set(all_os "Linux" "Windows" "MacOS" "iOS" "Android")
  #foreach(os ${all_os})
  #  if(IS_DIRECTORY ${ONNXRuntime_BUILD}/${os})
  #    set(ONNXRuntime_OS ${os})
  ##    break()
  #  endif()
  #endforeach()

#  if(NOT ONNXRuntime_OS)
#    message(FATAL_ERROR "ONNXRuntime: no suitable operating system found in the build directory")
#  endif()

  # Setting ONNXRuntime_BUILD_TYPE
#  set(all_types "Debug" "MinSizeRel" "Release" "RelWithDebInfo")
#  foreach(type ${all_types})
#    if(IS_DIRECTORY ${ONNXRuntime_BUILD}/${ONNXRuntime_OS}/${type})
#      set(ONNXRuntime_BUILD_TYPE ${type})
#      break()
#    endif()
#  endforeach()

  # Setting ONNXRuntime_LIBRARIES
#  if(EXISTS ${ONNXRuntime_BUILD}/${ONNXRuntime_OS}/${ONNXRuntime_BUILD_TYPE}/libonnxruntime.so)
  if(EXISTS ${ONNXRuntime_BUILD}/libonnxruntime.so)
    set(ONNXRuntime_LIBRARIES ${ONNXRuntime_BUILD}/${ONNXRuntime_OS}/${ONNXRuntime_BUILD_TYPE})
    set(ONNXRuntime_LIBRARY ${ONNXRuntime_LIBRARIES})

    # Setting ONNXRuntime_VERSION_*
    file(GLOB match REGEX "${ONNXRuntime_LIBRARIES}/libonnxruntime.so.*")
    foreach(fname ${match})
      get_filename_component(fname ${fname} NAME)
      string(REGEX MATCH "[0-9][0-9.]+" ONNXRuntime_VERSION_STRING ${fname})
      string(REPLACE "." ";" version ${ONNXRuntime_VERSION_STRING})
      list(LENGTH version version_length)
      if(${version_length} GREATER 2)
        list(GET version 0 ONNXRuntime_VERSION_MAJOR)
        list(GET version 1 ONNXRuntime_VERSION_MINOR)
        list(GET version 2 ONNXRuntime_VERSION_PATCH)
        break()
      endif()
    endforeach()
  endif()

  # Setting ONNXRuntime_INCLUDE_DIRS
  if(IS_DIRECTORY ${ONNXRuntime_SRC}/include)
    set(ONNXRuntime_INCLUDE_DIRS ${ONNXRuntime_SRC}/include)
    set(ONNXRuntime_INCLUDE_DIR ${ONNXRuntime_INCLUDE_DIRS})
  endif()

endif()

find_package_handle_standard_args(
  ONNXRuntime
  FOUND_VAR ONNXRuntime_FOUND
  REQUIRED_VARS ONNXRuntime_LIBRARIES ONNXRuntime_INCLUDE_DIRS
  VERSION_VAR ONNXRuntime_VERSION_STRING
)
