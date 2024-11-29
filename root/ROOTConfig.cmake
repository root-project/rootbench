# ROOT CMake Configuration File for External Projects
# This file is configured by ROOT for use by an external project
# As this file is configured by ROOT's CMake system it SHOULD NOT BE EDITED
# It defines the following variables
#  ROOT_INCLUDE_DIRS - include directories for ROOT
#  ROOT_DEFINITIONS  - compile definitions needed to use ROOT
#  ROOT_LIBRARIES    - libraries to link against
#  ROOT_USE_FILE     - path to a CMake module which may be included to help
#                      setup CMake variables and useful Macros
#
# You may supply a version number through find_package which will be checked
# against the version of this build. Standard CMake logic is used so that
# the EXACT flag may be passed, and otherwise this build will report itself
# as compatible with the requested version if:
#
#  VERSION_OF_THIS_BUILD >= VERSION_REQUESTED
#
#
# If you specify components and use the REQUIRED option to find_package, then
# the module will issue a FATAL_ERROR if this build of ROOT does not have
# the requested component(s). Components are any optional ROOT library, which
# will be added into the ROOT_LIBRARIES variable.
#
# The list of options available generally corresponds to the optional extras
# that ROOT can be built are also made available to the dependent project as
# ROOT_{option}_FOUND
#
#
# ===========================================================================

# Set any policies required by this module. Note that there is no check for
# whether a given policy exists or not. If it is required, it is required...
cmake_policy(PUSH)
cmake_policy(SET CMP0074 NEW)

#----------------------------------------------------------------------------
# DEBUG : print out the variables passed via find_package arguments
#
if(ROOT_CONFIG_DEBUG)
    message(STATUS "ROOTCFG_DEBUG : ROOT_VERSION         = ${ROOT_VERSION}")
    message(STATUS "ROOTCFG_DEBUG : ROOT_FIND_VERSION    = ${ROOT_FIND_VERSION}")
    message(STATUS "ROOTCFG_DEBUG : ROOT_FIND_REQUIRED   = ${ROOT_FIND_REQUIRED}")
    message(STATUS "ROOTCFG_DEBUG : ROOT_FIND_COMPONENTS = ${ROOT_FIND_COMPONENTS}")
    foreach(_cpt ${ROOT_FIND_COMPONENTS})
       message(STATUS "ROOTCFG_DEBUG : ROOT_FIND_REQUIRED_${_cpt} = ${ROOT_FIND_REQUIRED_${_cpt}}")
    endforeach()
endif()

#----------------------------------------------------------------------------
# Locate ourselves, since all other config files should have been installed
# alongside us...
#
get_filename_component(_thisdir "${CMAKE_CURRENT_LIST_FILE}" PATH)

#-----------------------------------------------------------------------
# Provide *recommended* compiler flags used by this build of ROOT
# Don't mess with the actual CMAKE_CXX_FLAGS!!!
# It's up to the user what to do with these
#
set(ROOT_DEFINITIONS "")
set(ROOT_CXX_FLAGS " -std=c++17 -m64 -pipe -fsigned-char -fno-common -Qunused-arguments -pthread -stdlib=libc++")
set(ROOT_C_FLAGS " -m64 -pipe -fsigned-char -fno-common -Qunused-arguments -pthread")
set(ROOT_fortran_FLAGS " -std=legacy")
set(ROOT_EXE_LINKER_FLAGS " -mmacosx-version-min=13.5")

#-----------------------------------------------------------------------
# Provide the C++ standard used by this build of ROOT
#
set(ROOT_CXX_STANDARD 17)

#----------------------------------------------------------------------------
# Configure the path to the ROOT headers, using a relative path if possible.
# This is only known at CMake time, so we expand a CMake supplied variable.
#

# ROOT configured for use from the build tree - absolute paths are used.
set(ROOT_INCLUDE_DIRS /Users/abhiacherjee/Documents/rootbench/root/include)


# ROOT configured for use from the build tree - absolute paths are used.
set(ROOT_LIBRARY_DIR /Users/abhiacherjee/Documents/rootbench/root/lib)


# ROOT configured for use from the build tree - absolute paths are used.
set(ROOT_BINDIR /Users/abhiacherjee/Documents/rootbench/root/bin)


# Deprecated value, please don't use it and use ROOT_BINDIR instead.
set(ROOT_BINARY_DIR /Users/abhiacherjee/Documents/rootbench/root/bin)


# ROOT configured for use from the build tree - absolute paths are used.
set(ROOT_CMAKE_DIR /Users/abhiacherjee/Documents/root_src/cmake)


# Python version used to build ROOT
set(ROOT_PYTHON_VERSION 3.11.7)

#----------------------------------------------------------------------------
# Include RootMacros.cmake to get ROOT's CMake macros
include("${_thisdir}/RootMacros.cmake")

#----------------------------------------------------------------------------
# Include the file listing all the imported targets and options
if(NOT CMAKE_PROJECT_NAME STREQUAL ROOT)
  include("${_thisdir}/ROOTConfig-targets.cmake")
endif()

#----------------------------------------------------------------------------
# Setup components and options
set(_root_enabled_options  asimage builtin_afterimage builtin_clang builtin_cling builtin_davix builtin_freetype builtin_glew builtin_gtest builtin_llvm builtin_openui5 clad cocoa dataframe davix fitsio gdml http imt libcxx mysql opengl proof pyroot roofit webgui root7 rpath runtime_cxxmodules shared sqlite ssl tmva tmva-cpu tmva-pymva spectrum vdt xml xrootd)
set(_root_all_options  arrow asimage asserts builtin_afterimage builtin_cfitsio builtin_clang builtin_cling builtin_cppzmq builtin_davix builtin_fftw3 builtin_freetype builtin_ftgl builtin_gl2ps builtin_glew builtin_gsl builtin_gtest builtin_llvm builtin_lz4 builtin_lzma builtin_nlohmannjson builtin_openssl builtin_openui5 builtin_pcre builtin_tbb builtin_unuran builtin_vc builtin_vdt builtin_veccore builtin_xrootd builtin_xxhash builtin_zeromq builtin_zlib builtin_zstd ccache distcc cefweb clad cocoa coverage cuda cudnn cxxmodules daos dataframe test_distrdf_pyspark test_distrdf_dask davix dcache dev exceptions fftw3 fitsio fortran gdml gnuinstall gviz http fcgi imt libcxx macos_native mathmore memory_termination minuit2 minuit2_mpi minuit2_omp mpi mysql odbc opengl oracle pgsql proof pyroot pyroot-python2 pythia6_nolink pythia6 pythia8 qt5web qt6web r roofit roofit_multiprocess webgui root7 rpath runtime_cxxmodules shadowpw shared soversion sqlite ssl tmva tmva-cpu tmva-gpu tmva-sofie tmva-pymva tmva-rmva spectrum unfold unuran uring vc vdt veccore vecgeom win_broken_tests llvm13_broken_tests winrtdebug x11 xml xrootd)

foreach(_opt ${_root_enabled_options})
  set(ROOT_${_opt}_FOUND TRUE)
endforeach()

#----------------------------------------------------------------------------
# Make any modules bundled with ROOT visible to CMake
list(APPEND CMAKE_MODULE_PATH "${ROOT_CMAKE_DIR}/modules")

#----------------------------------------------------------------------------
# Find external packages which were used in ROOT
include(CMakeFindDependencyMacro)

if (NOT ROOT_builtin_nlohmannjson_FOUND)
  if(ROOT_FIND_COMPONENTS)
    # test all libs which uses nlohmann_json in public interface
    foreach(_cpt ROOTEve)
       list(FIND ROOT_FIND_COMPONENTS ${_cpt} _found_lib)
       if(NOT (${_found_lib} EQUAL -1))
          set(_need_json TRUE)
       endif()
    endforeach()
  else()
    # if components not specified - suppose all
    set(_need_json TRUE)
  endif()
endif()

if(_need_json)
   find_dependency(nlohmann_json 3.11.3)
endif()
if(ROOT_minuit2_mpi_FOUND)
  find_dependency(MPI)
endif()
if(ROOT_minuit2_omp_FOUND)
  find_dependency(OpenMP)
  find_dependency(Threads)
endif()
if(ROOT_vdt_FOUND AND NOT TARGET VDT::VDT)
  if(ROOT_builtin_vdt_FOUND)
    set(Vdt_ROOT "${_thisdir}/.." CACHE PATH "Location of (the builtin) VDT")
  endif()
  find_dependency(Vdt)
endif()

#----------------------------------------------------------------------------
# Now set them to ROOT_LIBRARIES
set(ROOT_LIBRARIES)
if(MSVC)
  set(CMAKE_FIND_LIBRARY_PREFIXES "lib")
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll")
endif()
foreach(_cpt Core Imt RIO Net Hist Graf Graf3d Gpad ROOTDataFrame Tree TreePlayer Rint Postscript Matrix Physics MathCore Thread MultiProc ROOTVecOps ${ROOT_FIND_COMPONENTS})
  find_library(ROOT_${_cpt}_LIBRARY ${_cpt} HINTS ${ROOT_LIBRARY_DIR})
  if(ROOT_${_cpt}_LIBRARY)
    mark_as_advanced(ROOT_${_cpt}_LIBRARY)
    list(APPEND ROOT_LIBRARIES ${ROOT_${_cpt}_LIBRARY})
    list(REMOVE_ITEM ROOT_FIND_COMPONENTS ${_cpt})
  endif()
endforeach()
if(ROOT_LIBRARIES)
  list(REMOVE_DUPLICATES ROOT_LIBRARIES)
endif()

#----------------------------------------------------------------------------
# Locate the tools
set(ROOT_ALL_TOOLS genreflex genmap root rootcint rootcling hadd rootls rootrm rootmv rootmkdir rootcp rootdraw rootbrowse)
foreach(_cpt ${ROOT_ALL_TOOLS})
  if(NOT ROOT_${_cpt}_CMD)
    find_program(ROOT_${_cpt}_CMD ${_cpt} HINTS ${ROOT_BINDIR})
    if(ROOT_${_cpt}_CMD)
      mark_as_advanced(ROOT_${_cpt}_CMD)
    endif()
  endif()
endforeach()

#----------------------------------------------------------------------------
set(ROOT_EXECUTABLE ${ROOT_root_CMD})

#----------------------------------------------------------------------------
# Point the user to the ROOTUseFile.cmake file which they may wish to include
# to help them with setting up ROOT
#
set(ROOT_USE_FILE ${_thisdir}/ROOTUseFile.cmake)

#----------------------------------------------------------------------------
# Finally, handle any remaining components.
# We should have dealt with all available components above, and removed them
# from the list of FIND_COMPONENTS so any left we either didn't find or don't
# know about. Emit a warning if REQUIRED isn't set, or FATAL_ERROR otherwise
#
list(REMOVE_DUPLICATES ROOT_FIND_COMPONENTS)
foreach(_remaining ${ROOT_FIND_COMPONENTS})
    if(ROOT_FIND_REQUIRED_${_remaining})
        message(FATAL_ERROR "ROOT component ${_remaining} not found")
    elseif(NOT ROOT_FIND_QUIETLY)
        message(WARNING " ROOT component ${_remaining} not found")
    endif()
    unset(ROOT_FIND_REQUIRED_${_remaining})
endforeach()

# Clear out any policy settings made for this module.
cmake_policy(POP)
