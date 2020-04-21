# Copyright (C) 1995-2019, Rene Brun and Fons Rademakers.
# All rights reserved.
#
# For the licensing terms see $ROOTSYS/LICENSE.
# For the list of contributors see $ROOTSYS/README/CREDITS.

#---------------------------------------------------------------------------------------------------
#  RootMacros.cmake
#---------------------------------------------------------------------------------------------------
# 21/04/2020

function(find_python_module module)
   CMAKE_PARSE_ARGUMENTS(ARG "REQUIRED;QUIET" "" "" ${ARGN})
   string(TOUPPER ${module} module_upper)
   if(NOT ${module_upper})
      if(ARG_REQUIRED)
         set(${module}_FIND_REQUIRED TRUE)
      endif()
      if(ARG_QUIET)
         set(${module}_FIND_QUIETLY TRUE)
      endif()
      # A module's location is usually a directory, but for binary modules
      # it's a .so file.
      execute_process(COMMAND "${PYTHON_EXECUTABLE}" "-c"
         "import re, ${module}; print(re.compile('/__init__.py.*').sub('',${module}.__file__))"
         RESULT_VARIABLE _${module}_status
         OUTPUT_VARIABLE _${module}_location
         ERROR_VARIABLE _${module}_error
         OUTPUT_STRIP_TRAILING_WHITESPACE
         ERROR_STRIP_TRAILING_WHITESPACE)
      if(NOT _${module}_status)
         set(${module_upper} ${_${module}_location} CACHE STRING "Location of Python module ${module}")
         mark_as_advanced(${module_upper})
      else()
         if(NOT ARG_QUIET)
            message(STATUS "Failed to find Python module ${module}: ${_${module}_error}")
          endif()
      endif()
   endif()
   find_package_handle_standard_args(${module} DEFAULT_MSG ${module_upper})
   set(${module_upper}_FOUND ${${module_upper}_FOUND} CACHE INTERNAL "" FORCE)
endfunction()