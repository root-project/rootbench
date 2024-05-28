# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "2.8.3")
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.8.3...3.26)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS LLVMDemangle LLVMSupport LLVMTableGen LLVMTableGenGlobalISel llvm-tblgen LLVMCore LLVMFuzzerCLI LLVMFuzzMutate LLVMFileCheck LLVMInterfaceStub LLVMIRPrinter LLVMIRReader LLVMCodeGen LLVMSelectionDAG LLVMAsmPrinter LLVMMIRParser LLVMGlobalISel LLVMBinaryFormat LLVMBitReader LLVMBitWriter LLVMBitstreamReader LLVMDWARFLinker LLVMDWARFLinkerParallel LLVMExtensions LLVMFrontendHLSL LLVMFrontendOpenACC LLVMFrontendOpenMP LLVMTransformUtils LLVMInstrumentation LLVMAggressiveInstCombine LLVMInstCombine LLVMScalarOpts LLVMipo LLVMVectorize LLVMObjCARCOpts LLVMCoroutines LLVMCFGuard LLVMLinker LLVMAnalysis LLVMLTO LLVMMC LLVMMCParser LLVMMCDisassembler LLVMMCA LLVMObjCopy LLVMObject LLVMObjectYAML LLVMOption LLVMRemarks LLVMDebuginfod LLVMDebugInfoDWARF LLVMDebugInfoGSYM LLVMDebugInfoLogicalView LLVMDebugInfoMSF LLVMDebugInfoCodeView LLVMDebugInfoPDB LLVMSymbolize LLVMDWP LLVMExecutionEngine LLVMInterpreter LLVMJITLink LLVMMCJIT LLVMOrcJIT LLVMOrcShared LLVMOrcTargetProcess LLVMRuntimeDyld LLVMTarget LLVMAArch64CodeGen LLVMAArch64AsmParser LLVMAArch64Disassembler LLVMAArch64Desc LLVMAArch64Info LLVMAArch64Utils LLVMNVPTXCodeGen LLVMNVPTXDesc LLVMNVPTXInfo LLVMAsmParser LLVMLineEditor LLVMProfileData LLVMCoverage LLVMPasses LLVMTargetParser LLVMTextAPI LLVMDlltoolDriver LLVMLibDriver LLVMXRay LLVMWindowsDriver LLVMWindowsManifest LTO LLVMCFIVerify LLVMDiff LLVMExegesisAArch64 LLVMExegesis Remarks)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target LLVMDemangle
add_library(LLVMDemangle STATIC IMPORTED)

# Create imported target LLVMSupport
add_library(LLVMSupport STATIC IMPORTED)

set_target_properties(LLVMSupport PROPERTIES
  INTERFACE_LINK_LIBRARIES "m;ZLIB::ZLIB;zstd::libzstd_shared;Terminfo::terminfo;LLVMDemangle"
)

# Create imported target LLVMTableGen
add_library(LLVMTableGen STATIC IMPORTED)

set_target_properties(LLVMTableGen PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMTableGenGlobalISel
add_library(LLVMTableGenGlobalISel STATIC IMPORTED)

set_target_properties(LLVMTableGenGlobalISel PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport;LLVMTableGen"
)

# Create imported target llvm-tblgen
add_executable(llvm-tblgen IMPORTED)

# Create imported target LLVMCore
add_library(LLVMCore STATIC IMPORTED)

set_target_properties(LLVMCore PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMRemarks;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMFuzzerCLI
add_library(LLVMFuzzerCLI STATIC IMPORTED)

set_target_properties(LLVMFuzzerCLI PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMFuzzMutate
add_library(LLVMFuzzMutate STATIC IMPORTED)

set_target_properties(LLVMFuzzMutate PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMBitReader;LLVMBitWriter;LLVMCore;LLVMScalarOpts;LLVMSupport;LLVMTarget;LLVMTargetParser;LLVMTransformUtils"
)

# Create imported target LLVMFileCheck
add_library(LLVMFileCheck STATIC IMPORTED)

set_target_properties(LLVMFileCheck PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMInterfaceStub
add_library(LLVMInterfaceStub STATIC IMPORTED)

set_target_properties(LLVMInterfaceStub PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMMC;LLVMObject;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMIRPrinter
add_library(LLVMIRPrinter STATIC IMPORTED)

set_target_properties(LLVMIRPrinter PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCore;LLVMSupport"
)

# Create imported target LLVMIRReader
add_library(LLVMIRReader STATIC IMPORTED)

set_target_properties(LLVMIRReader PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAsmParser;LLVMBitReader;LLVMCore;LLVMSupport"
)

# Create imported target LLVMCodeGen
add_library(LLVMCodeGen STATIC IMPORTED)

set_target_properties(LLVMCodeGen PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMBitReader;LLVMBitWriter;LLVMCore;LLVMMC;LLVMObjCARCOpts;LLVMProfileData;LLVMScalarOpts;LLVMSupport;LLVMTarget;LLVMTargetParser;LLVMTransformUtils"
)

# Create imported target LLVMSelectionDAG
add_library(LLVMSelectionDAG STATIC IMPORTED)

set_target_properties(LLVMSelectionDAG PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCodeGen;LLVMCore;LLVMMC;LLVMSupport;LLVMTarget;LLVMTargetParser;LLVMTransformUtils"
)

# Create imported target LLVMAsmPrinter
add_library(LLVMAsmPrinter STATIC IMPORTED)

set_target_properties(LLVMAsmPrinter PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMBinaryFormat;LLVMCodeGen;LLVMCore;LLVMDebugInfoCodeView;LLVMDebugInfoDWARF;LLVMDebugInfoMSF;LLVMMC;LLVMMCParser;LLVMRemarks;LLVMSupport;LLVMTarget;LLVMTargetParser"
)

# Create imported target LLVMMIRParser
add_library(LLVMMIRParser STATIC IMPORTED)

set_target_properties(LLVMMIRParser PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAsmParser;LLVMBinaryFormat;LLVMCodeGen;LLVMCore;LLVMMC;LLVMSupport;LLVMTarget"
)

# Create imported target LLVMGlobalISel
add_library(LLVMGlobalISel STATIC IMPORTED)

set_target_properties(LLVMGlobalISel PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCodeGen;LLVMCore;LLVMMC;LLVMSelectionDAG;LLVMSupport;LLVMTarget;LLVMTransformUtils"
)

# Create imported target LLVMBinaryFormat
add_library(LLVMBinaryFormat STATIC IMPORTED)

set_target_properties(LLVMBinaryFormat PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMBitReader
add_library(LLVMBitReader STATIC IMPORTED)

set_target_properties(LLVMBitReader PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBitstreamReader;LLVMCore;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMBitWriter
add_library(LLVMBitWriter STATIC IMPORTED)

set_target_properties(LLVMBitWriter PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCore;LLVMMC;LLVMObject;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMBitstreamReader
add_library(LLVMBitstreamReader STATIC IMPORTED)

set_target_properties(LLVMBitstreamReader PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMDWARFLinker
add_library(LLVMDWARFLinker STATIC IMPORTED)

set_target_properties(LLVMDWARFLinker PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMDebugInfoDWARF;LLVMAsmPrinter;LLVMCodeGen;LLVMMC;LLVMObject;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMDWARFLinkerParallel
add_library(LLVMDWARFLinkerParallel STATIC IMPORTED)

set_target_properties(LLVMDWARFLinkerParallel PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMDebugInfoDWARF;LLVMAsmPrinter;LLVMCodeGen;LLVMMC;LLVMObject;LLVMSupport"
)

# Create imported target LLVMExtensions
add_library(LLVMExtensions STATIC IMPORTED)

set_target_properties(LLVMExtensions PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMFrontendHLSL
add_library(LLVMFrontendHLSL STATIC IMPORTED)

set_target_properties(LLVMFrontendHLSL PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCore;LLVMSupport"
)

# Create imported target LLVMFrontendOpenACC
add_library(LLVMFrontendOpenACC STATIC IMPORTED)

set_target_properties(LLVMFrontendOpenACC PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMFrontendOpenMP
add_library(LLVMFrontendOpenMP STATIC IMPORTED)

set_target_properties(LLVMFrontendOpenMP PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCore;LLVMSupport;LLVMTargetParser;LLVMTransformUtils;LLVMAnalysis;LLVMMC;LLVMScalarOpts"
)

# Create imported target LLVMTransformUtils
add_library(LLVMTransformUtils STATIC IMPORTED)

set_target_properties(LLVMTransformUtils PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCore;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMInstrumentation
add_library(LLVMInstrumentation STATIC IMPORTED)

set_target_properties(LLVMInstrumentation PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCore;LLVMDemangle;LLVMMC;LLVMSupport;LLVMTargetParser;LLVMTransformUtils;LLVMProfileData"
)

# Create imported target LLVMAggressiveInstCombine
add_library(LLVMAggressiveInstCombine STATIC IMPORTED)

set_target_properties(LLVMAggressiveInstCombine PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCore;LLVMSupport;LLVMTransformUtils"
)

# Create imported target LLVMInstCombine
add_library(LLVMInstCombine STATIC IMPORTED)

set_target_properties(LLVMInstCombine PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCore;LLVMSupport;LLVMTransformUtils"
)

# Create imported target LLVMScalarOpts
add_library(LLVMScalarOpts STATIC IMPORTED)

set_target_properties(LLVMScalarOpts PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAggressiveInstCombine;LLVMAnalysis;LLVMCore;LLVMInstCombine;LLVMSupport;LLVMTransformUtils"
)

# Create imported target LLVMipo
add_library(LLVMipo STATIC IMPORTED)

set_target_properties(LLVMipo PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAggressiveInstCombine;LLVMAnalysis;LLVMBitReader;LLVMBitWriter;LLVMCore;LLVMFrontendOpenMP;LLVMInstCombine;LLVMIRReader;LLVMLinker;LLVMObject;LLVMProfileData;LLVMScalarOpts;LLVMSupport;LLVMTargetParser;LLVMTransformUtils;LLVMVectorize;LLVMInstrumentation"
)

# Create imported target LLVMVectorize
add_library(LLVMVectorize STATIC IMPORTED)

set_target_properties(LLVMVectorize PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCore;LLVMSupport;LLVMTransformUtils"
)

# Create imported target LLVMObjCARCOpts
add_library(LLVMObjCARCOpts STATIC IMPORTED)

set_target_properties(LLVMObjCARCOpts PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCore;LLVMSupport;LLVMTransformUtils"
)

# Create imported target LLVMCoroutines
add_library(LLVMCoroutines STATIC IMPORTED)

set_target_properties(LLVMCoroutines PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCore;LLVMipo;LLVMScalarOpts;LLVMSupport;LLVMTransformUtils"
)

# Create imported target LLVMCFGuard
add_library(LLVMCFGuard STATIC IMPORTED)

set_target_properties(LLVMCFGuard PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCore;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMLinker
add_library(LLVMLinker STATIC IMPORTED)

set_target_properties(LLVMLinker PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCore;LLVMObject;LLVMSupport;LLVMTransformUtils;LLVMTargetParser"
)

# Create imported target LLVMAnalysis
add_library(LLVMAnalysis STATIC IMPORTED)

set_target_properties(LLVMAnalysis PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMCore;LLVMObject;LLVMProfileData;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMLTO
add_library(LLVMLTO STATIC IMPORTED)

set_target_properties(LLVMLTO PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAggressiveInstCombine;LLVMAnalysis;LLVMBinaryFormat;LLVMBitReader;LLVMBitWriter;LLVMCodeGen;LLVMCore;LLVMExtensions;LLVMipo;LLVMInstCombine;LLVMInstrumentation;LLVMLinker;LLVMMC;LLVMObjCARCOpts;LLVMObject;LLVMPasses;LLVMRemarks;LLVMScalarOpts;LLVMSupport;LLVMTarget;LLVMTargetParser;LLVMTransformUtils"
)

# Create imported target LLVMMC
add_library(LLVMMC STATIC IMPORTED)

set_target_properties(LLVMMC PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport;LLVMTargetParser;LLVMBinaryFormat;LLVMDebugInfoCodeView"
)

# Create imported target LLVMMCParser
add_library(LLVMMCParser STATIC IMPORTED)

set_target_properties(LLVMMCParser PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMMC;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMMCDisassembler
add_library(LLVMMCDisassembler STATIC IMPORTED)

set_target_properties(LLVMMCDisassembler PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMMC;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMMCA
add_library(LLVMMCA STATIC IMPORTED)

set_target_properties(LLVMMCA PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMMC;LLVMSupport"
)

# Create imported target LLVMObjCopy
add_library(LLVMObjCopy STATIC IMPORTED)

set_target_properties(LLVMObjCopy PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMObject;LLVMSupport;LLVMMC"
)

# Create imported target LLVMObject
add_library(LLVMObject STATIC IMPORTED)

set_target_properties(LLVMObject PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBitReader;LLVMCore;LLVMMC;LLVMIRReader;LLVMBinaryFormat;LLVMMCParser;LLVMSupport;LLVMTargetParser;LLVMTextAPI"
)

# Create imported target LLVMObjectYAML
add_library(LLVMObjectYAML STATIC IMPORTED)

set_target_properties(LLVMObjectYAML PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMObject;LLVMSupport;LLVMTargetParser;LLVMDebugInfoCodeView;LLVMMC"
)

# Create imported target LLVMOption
add_library(LLVMOption STATIC IMPORTED)

set_target_properties(LLVMOption PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMRemarks
add_library(LLVMRemarks STATIC IMPORTED)

set_target_properties(LLVMRemarks PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBitstreamReader;LLVMSupport"
)

# Create imported target LLVMDebuginfod
add_library(LLVMDebuginfod STATIC IMPORTED)

set_target_properties(LLVMDebuginfod PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport;LLVMSymbolize;LLVMDebugInfoDWARF;LLVMBinaryFormat;LLVMObject"
)

# Create imported target LLVMDebugInfoDWARF
add_library(LLVMDebugInfoDWARF STATIC IMPORTED)

set_target_properties(LLVMDebugInfoDWARF PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMObject;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMDebugInfoGSYM
add_library(LLVMDebugInfoGSYM STATIC IMPORTED)

set_target_properties(LLVMDebugInfoGSYM PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMMC;LLVMObject;LLVMSupport;LLVMTargetParser;LLVMDebugInfoDWARF"
)

# Create imported target LLVMDebugInfoLogicalView
add_library(LLVMDebugInfoLogicalView STATIC IMPORTED)

set_target_properties(LLVMDebugInfoLogicalView PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMObject;LLVMMC;LLVMSupport;LLVMTargetParser;LLVMDebugInfoDWARF"
)

# Create imported target LLVMDebugInfoMSF
add_library(LLVMDebugInfoMSF STATIC IMPORTED)

set_target_properties(LLVMDebugInfoMSF PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMDebugInfoCodeView
add_library(LLVMDebugInfoCodeView STATIC IMPORTED)

set_target_properties(LLVMDebugInfoCodeView PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMDebugInfoPDB
add_library(LLVMDebugInfoPDB STATIC IMPORTED)

set_target_properties(LLVMDebugInfoPDB PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMObject;LLVMSupport;LLVMDebugInfoCodeView;LLVMDebugInfoMSF"
)

# Create imported target LLVMSymbolize
add_library(LLVMSymbolize STATIC IMPORTED)

set_target_properties(LLVMSymbolize PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMDebugInfoDWARF;LLVMDebugInfoPDB;LLVMObject;LLVMSupport;LLVMDemangle;LLVMTargetParser"
)

# Create imported target LLVMDWP
add_library(LLVMDWP STATIC IMPORTED)

set_target_properties(LLVMDWP PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMDebugInfoDWARF;LLVMMC;LLVMObject;LLVMSupport;LLVMTarget"
)

# Create imported target LLVMExecutionEngine
add_library(LLVMExecutionEngine STATIC IMPORTED)

set_target_properties(LLVMExecutionEngine PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCore;LLVMMC;LLVMObject;LLVMOrcTargetProcess;LLVMRuntimeDyld;LLVMSupport;LLVMTarget;LLVMTargetParser"
)

# Create imported target LLVMInterpreter
add_library(LLVMInterpreter STATIC IMPORTED)

set_target_properties(LLVMInterpreter PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCodeGen;LLVMCore;LLVMExecutionEngine;LLVMSupport"
)

# Create imported target LLVMJITLink
add_library(LLVMJITLink STATIC IMPORTED)

set_target_properties(LLVMJITLink PROPERTIES
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:LLVMObject>;\$<LINK_ONLY:LLVMOrcShared>;\$<LINK_ONLY:LLVMOrcTargetProcess>;\$<LINK_ONLY:LLVMSupport>;\$<LINK_ONLY:LLVMTargetParser>;LLVMBinaryFormat;LLVMObject;LLVMOption;LLVMOrcTargetProcess;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMMCJIT
add_library(LLVMMCJIT STATIC IMPORTED)

set_target_properties(LLVMMCJIT PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCore;LLVMExecutionEngine;LLVMObject;LLVMRuntimeDyld;LLVMSupport;LLVMTarget"
)

# Create imported target LLVMOrcJIT
add_library(LLVMOrcJIT STATIC IMPORTED)

set_target_properties(LLVMOrcJIT PROPERTIES
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:LLVMAnalysis>;\$<LINK_ONLY:LLVMBitReader>;\$<LINK_ONLY:LLVMBitWriter>;\$<LINK_ONLY:LLVMPasses>;LLVMCore;LLVMExecutionEngine;LLVMJITLink;LLVMObject;LLVMOrcShared;LLVMOrcTargetProcess;LLVMWindowsDriver;LLVMMC;LLVMMCDisassembler;LLVMPasses;LLVMRuntimeDyld;LLVMSupport;LLVMTarget;LLVMTargetParser;LLVMTransformUtils"
)

# Create imported target LLVMOrcShared
add_library(LLVMOrcShared STATIC IMPORTED)

set_target_properties(LLVMOrcShared PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMOrcTargetProcess
add_library(LLVMOrcTargetProcess STATIC IMPORTED)

set_target_properties(LLVMOrcTargetProcess PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMOrcShared;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMRuntimeDyld
add_library(LLVMRuntimeDyld STATIC IMPORTED)

set_target_properties(LLVMRuntimeDyld PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCore;LLVMMC;LLVMObject;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMTarget
add_library(LLVMTarget STATIC IMPORTED)

set_target_properties(LLVMTarget PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCore;LLVMMC;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMAArch64CodeGen
add_library(LLVMAArch64CodeGen STATIC IMPORTED)

set_target_properties(LLVMAArch64CodeGen PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAArch64Desc;LLVMAArch64Info;LLVMAArch64Utils;LLVMAnalysis;LLVMAsmPrinter;LLVMCodeGen;LLVMCore;LLVMMC;LLVMScalarOpts;LLVMSelectionDAG;LLVMSupport;LLVMTarget;LLVMTargetParser;LLVMTransformUtils;LLVMGlobalISel;LLVMCFGuard"
)

# Create imported target LLVMAArch64AsmParser
add_library(LLVMAArch64AsmParser STATIC IMPORTED)

set_target_properties(LLVMAArch64AsmParser PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAArch64Desc;LLVMAArch64Info;LLVMAArch64Utils;LLVMMC;LLVMMCParser;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMAArch64Disassembler
add_library(LLVMAArch64Disassembler STATIC IMPORTED)

set_target_properties(LLVMAArch64Disassembler PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAArch64Desc;LLVMAArch64Info;LLVMAArch64Utils;LLVMMC;LLVMMCDisassembler;LLVMSupport"
)

# Create imported target LLVMAArch64Desc
add_library(LLVMAArch64Desc STATIC IMPORTED)

set_target_properties(LLVMAArch64Desc PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAArch64Info;LLVMAArch64Utils;LLVMMC;LLVMBinaryFormat;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMAArch64Info
add_library(LLVMAArch64Info STATIC IMPORTED)

set_target_properties(LLVMAArch64Info PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMMC;LLVMSupport"
)

# Create imported target LLVMAArch64Utils
add_library(LLVMAArch64Utils STATIC IMPORTED)

set_target_properties(LLVMAArch64Utils PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport;LLVMCore"
)

# Create imported target LLVMNVPTXCodeGen
add_library(LLVMNVPTXCodeGen STATIC IMPORTED)

set_target_properties(LLVMNVPTXCodeGen PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMAsmPrinter;LLVMCodeGen;LLVMCore;LLVMipo;LLVMMC;LLVMNVPTXDesc;LLVMNVPTXInfo;LLVMScalarOpts;LLVMSelectionDAG;LLVMSupport;LLVMTarget;LLVMTargetParser;LLVMTransformUtils;LLVMVectorize"
)

# Create imported target LLVMNVPTXDesc
add_library(LLVMNVPTXDesc STATIC IMPORTED)

set_target_properties(LLVMNVPTXDesc PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMMC;LLVMNVPTXInfo;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMNVPTXInfo
add_library(LLVMNVPTXInfo STATIC IMPORTED)

set_target_properties(LLVMNVPTXInfo PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMMC;LLVMSupport"
)

# Create imported target LLVMAsmParser
add_library(LLVMAsmParser STATIC IMPORTED)

set_target_properties(LLVMAsmParser PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMCore;LLVMSupport"
)

# Create imported target LLVMLineEditor
add_library(LLVMLineEditor STATIC IMPORTED)

set_target_properties(LLVMLineEditor PROPERTIES
  INTERFACE_LINK_LIBRARIES "LibEdit::LibEdit;LLVMSupport"
)

# Create imported target LLVMProfileData
add_library(LLVMProfileData STATIC IMPORTED)

set_target_properties(LLVMProfileData PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCore;LLVMObject;LLVMSupport;LLVMDemangle;LLVMSymbolize;LLVMDebugInfoDWARF;LLVMTargetParser"
)

# Create imported target LLVMCoverage
add_library(LLVMCoverage STATIC IMPORTED)

set_target_properties(LLVMCoverage PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCore;LLVMObject;LLVMProfileData;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMPasses
add_library(LLVMPasses STATIC IMPORTED)

set_target_properties(LLVMPasses PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAggressiveInstCombine;LLVMAnalysis;LLVMCodeGen;LLVMCore;LLVMCoroutines;LLVMipo;LLVMInstCombine;LLVMIRPrinter;LLVMObjCARCOpts;LLVMScalarOpts;LLVMSupport;LLVMTarget;LLVMTransformUtils;LLVMVectorize;LLVMInstrumentation"
)

# Create imported target LLVMTargetParser
add_library(LLVMTargetParser STATIC IMPORTED)

set_target_properties(LLVMTargetParser PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMTextAPI
add_library(LLVMTextAPI STATIC IMPORTED)

set_target_properties(LLVMTextAPI PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport;LLVMBinaryFormat;LLVMTargetParser"
)

# Create imported target LLVMDlltoolDriver
add_library(LLVMDlltoolDriver STATIC IMPORTED)

set_target_properties(LLVMDlltoolDriver PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMObject;LLVMOption;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMLibDriver
add_library(LLVMLibDriver STATIC IMPORTED)

set_target_properties(LLVMLibDriver PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMBinaryFormat;LLVMBitReader;LLVMObject;LLVMOption;LLVMSupport;LLVMTargetParser;LLVMBinaryFormat;LLVMBitReader;LLVMObject;LLVMOption;LLVMSupport"
)

# Create imported target LLVMXRay
add_library(LLVMXRay STATIC IMPORTED)

set_target_properties(LLVMXRay PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport;LLVMObject;LLVMTargetParser"
)

# Create imported target LLVMWindowsDriver
add_library(LLVMWindowsDriver STATIC IMPORTED)

set_target_properties(LLVMWindowsDriver PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMOption;LLVMSupport;LLVMTargetParser"
)

# Create imported target LLVMWindowsManifest
add_library(LLVMWindowsManifest STATIC IMPORTED)

set_target_properties(LLVMWindowsManifest PROPERTIES
  INTERFACE_LINK_LIBRARIES "LibXml2::LibXml2;LLVMSupport"
)

# Create imported target LTO
add_library(LTO SHARED IMPORTED)

# Create imported target LLVMCFIVerify
add_library(LLVMCFIVerify STATIC IMPORTED)

set_target_properties(LLVMCFIVerify PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMDebugInfoDWARF;LLVMMC;LLVMMCParser;LLVMObject;LLVMSupport;LLVMSymbolize;LLVMTargetParser"
)

# Create imported target LLVMDiff
add_library(LLVMDiff STATIC IMPORTED)

set_target_properties(LLVMDiff PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMCore;LLVMSupport"
)

# Create imported target LLVMExegesisAArch64
add_library(LLVMExegesisAArch64 STATIC IMPORTED)

set_target_properties(LLVMExegesisAArch64 PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAArch64CodeGen;LLVMAArch64AsmParser;LLVMAArch64Desc;LLVMAArch64Disassembler;LLVMAArch64Info;LLVMAArch64Utils;LLVMExegesis;LLVMCore;LLVMSupport;LLVMMC"
)

# Create imported target LLVMExegesis
add_library(LLVMExegesis STATIC IMPORTED)

set_target_properties(LLVMExegesis PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMAnalysis;LLVMCodeGen;LLVMCore;LLVMExecutionEngine;LLVMGlobalISel;LLVMMC;LLVMMCA;LLVMMCDisassembler;LLVMMCJIT;LLVMMCParser;LLVMObject;LLVMObjectYAML;LLVMRuntimeDyld;LLVMSupport;LLVMTargetParser"
)

# Create imported target Remarks
add_library(Remarks SHARED IMPORTED)

if(CMAKE_VERSION VERSION_LESS 2.8.12)
  message(FATAL_ERROR "This file relies on consumers using CMake 2.8.12 or greater.")
endif()

# Load information for each installed configuration.
file(GLOB _cmake_config_files "${CMAKE_CURRENT_LIST_DIR}/LLVMExports-*.cmake")
foreach(_cmake_config_file IN LISTS _cmake_config_files)
  include("${_cmake_config_file}")
endforeach()
unset(_cmake_config_file)
unset(_cmake_config_files)

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(_cmake_target IN LISTS _cmake_import_check_targets)
  foreach(_cmake_file IN LISTS "_cmake_import_check_files_for_${_cmake_target}")
    if(NOT EXISTS "${_cmake_file}")
      message(FATAL_ERROR "The imported target \"${_cmake_target}\" references the file
   \"${_cmake_file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_cmake_file)
  unset("_cmake_import_check_files_for_${_cmake_target}")
endforeach()
unset(_cmake_target)
unset(_cmake_import_check_targets)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
