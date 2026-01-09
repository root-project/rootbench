# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BINARY_BUNDLE "OFF")
set(CPACK_BINARY_DEB "OFF")
set(CPACK_BINARY_DRAGNDROP "OFF")
set(CPACK_BINARY_FREEBSD "OFF")
set(CPACK_BINARY_IFW "OFF")
set(CPACK_BINARY_NSIS "OFF")
set(CPACK_BINARY_PRODUCTBUILD "OFF")
set(CPACK_BINARY_RPM "OFF")
set(CPACK_BINARY_STGZ "ON")
set(CPACK_BINARY_TBZ2 "OFF")
set(CPACK_BINARY_TGZ "ON")
set(CPACK_BINARY_TXZ "OFF")
set(CPACK_BUILD_SOURCE_DIRS "/Users/abhiacherjee/Documents/root_src;/Users/abhiacherjee/Documents/rootbench/root")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENTS_ALL "LLVMAArch64AsmParser;LLVMAArch64CodeGen;LLVMAArch64Desc;LLVMAArch64Disassembler;LLVMAArch64Info;LLVMAArch64Utils;LLVMAggressiveInstCombine;LLVMAnalysis;LLVMAsmParser;LLVMAsmPrinter;LLVMBinaryFormat;LLVMBitReader;LLVMBitWriter;LLVMBitstreamReader;LLVMCFGuard;LLVMCFIVerify;LLVMCodeGen;LLVMCore;LLVMCoroutines;LLVMCoverage;LLVMDWARFLinker;LLVMDWARFLinkerParallel;LLVMDWP;LLVMDebugInfoCodeView;LLVMDebugInfoDWARF;LLVMDebugInfoGSYM;LLVMDebugInfoLogicalView;LLVMDebugInfoMSF;LLVMDebugInfoPDB;LLVMDebuginfod;LLVMDemangle;LLVMDiff;LLVMDlltoolDriver;LLVMExecutionEngine;LLVMExegesis;LLVMExegesisAArch64;LLVMExtensions;LLVMFileCheck;LLVMFrontendHLSL;LLVMFrontendOpenACC;LLVMFrontendOpenMP;LLVMFuzzMutate;LLVMFuzzerCLI;LLVMGlobalISel;LLVMIRPrinter;LLVMIRReader;LLVMInstCombine;LLVMInstrumentation;LLVMInterfaceStub;LLVMInterpreter;LLVMJITLink;LLVMLTO;LLVMLibDriver;LLVMLineEditor;LLVMLinker;LLVMMC;LLVMMCA;LLVMMCDisassembler;LLVMMCJIT;LLVMMCParser;LLVMMIRParser;LLVMNVPTXCodeGen;LLVMNVPTXDesc;LLVMNVPTXInfo;LLVMObjCARCOpts;LLVMObjCopy;LLVMObject;LLVMObjectYAML;LLVMOption;LLVMOrcJIT;LLVMOrcShared;LLVMOrcTargetProcess;LLVMPasses;LLVMProfileData;LLVMRemarks;LLVMRuntimeDyld;LLVMScalarOpts;LLVMSelectionDAG;LLVMSupport;LLVMSymbolize;LLVMTableGen;LLVMTableGenGlobalISel;LLVMTarget;LLVMTargetParser;LLVMTextAPI;LLVMTransformUtils;LLVMVectorize;LLVMWindowsDriver;LLVMWindowsManifest;LLVMXRay;LLVMipo;LTO;Remarks;Unspecified;aarch64-resource-headers;applications;arm-common-resource-headers;arm-resource-headers;bash-autocomplete;clang;clang-cmake-exports;clang-cpp;clang-headers;clang-resource-headers;clang-tblgen;clangAPINotes;clangAST;clangASTMatchers;clangAnalysis;clangAnalysisFlowSensitive;clangAnalysisFlowSensitiveModels;clangBasic;clangCodeGen;clangCrossTU;clangDependencyScanning;clangDirectoryWatcher;clangDriver;clangDynamicASTMatchers;clangEdit;clangExtractAPI;clangFormat;clangFrontend;clangFrontendTool;clangIndex;clangIndexSerialization;clangInterpreter;clangLex;clangParse;clangRewrite;clangRewriteFrontend;clangSema;clangSerialization;clangStaticAnalyzerCheckers;clangStaticAnalyzerCore;clangStaticAnalyzerFrontend;clangSupport;clangTooling;clangToolingASTDiff;clangToolingCore;clangToolingInclusions;clangToolingInclusionsStdlib;clangToolingRefactoring;clangToolingSyntax;clangTransformer;cling-cmake-exports;clingDemoPlugin;clingInterpreter;clingMetaProcessor;clingUtils;cmake-exports;core-resource-headers;cuda-resource-headers;headers;hexagon-resource-headers;hip-resource-headers;hlsl-resource-headers;hmaptool;libraries;llvm-headers;llvm-tblgen;loongarch-resource-headers;mips-resource-headers;opencl-resource-headers;openmp-resource-headers;opt-viewer;ppc-htm-resource-headers;ppc-resource-headers;systemz-resource-headers;tests;utility-resource-headers;ve-resource-headers;webassembly-resource-headers;windows-resource-headers;x86-resource-headers")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/opt/homebrew/Cellar/cmake/3.28.2/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "ROOT built using CMake")
set(CPACK_DMG_SLA_USE_RESOURCE_FILE_LICENSE "ON")
set(CPACK_GENERATOR "TGZ;productbuild")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "/Users/abhiacherjee/Documents/rootbench/root;ROOT;ALL;/")
set(CPACK_INSTALL_PREFIX "/Users/abhiacherjee/Documents/install_root")
set(CPACK_MODULE_PATH "/Users/abhiacherjee/Documents/root_src/cmake/modules")
set(CPACK_NSIS_DISPLAY_NAME "root_v6.31.01")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "root_v6.31.01")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJDUMP_EXECUTABLE "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
set(CPACK_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk")
set(CPACK_OUTPUT_CONFIG_FILE "/Users/abhiacherjee/Documents/rootbench/root/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION "ROOT project")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/Users/abhiacherjee/Documents/rootbench/root/README.html")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ROOT project")
set(CPACK_PACKAGE_EXECUTABLES "root;ROOT")
set(CPACK_PACKAGE_FILE_NAME "root_v6.31.01.macos-13.5-arm64-clang150.relwithdebinfo")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "root_v6.31.01")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "root_v6.31.01")
set(CPACK_PACKAGE_NAME "ROOT")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "ROOT project")
set(CPACK_PACKAGE_VERSION "6.31.01")
set(CPACK_PACKAGE_VERSION_MAJOR "6")
set(CPACK_PACKAGE_VERSION_MINOR "31")
set(CPACK_PACKAGE_VERSION_PATCH "01")
set(CPACK_PROJECT_CONFIG_FILE "/Users/abhiacherjee/Documents/rootbench/root/CMakeCPackOptions.cmake")
set(CPACK_RESOURCE_FILE_LICENSE "/Users/abhiacherjee/Documents/rootbench/root/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "/Users/abhiacherjee/Documents/rootbench/root/README.html")
set(CPACK_RESOURCE_FILE_WELCOME "/opt/homebrew/Cellar/cmake/3.28.2/share/cmake/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ;TBZ2")
set(CPACK_SOURCE_IGNORE_FILES "/Users/abhiacherjee/Documents/rootbench/root;/Users/abhiacherjee/Documents/root_src/tests;~$;/CVS/;/.svn/;/\\\\.svn/;/.git/;/\\\\.git/;\\\\.swp$;\\\\.swp$;\\.swp;\\\\.#;/#")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/Users/abhiacherjee/Documents/rootbench/root/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_STRIP_FILES "")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_SYSTEM_NAME "Darwin")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Darwin")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/Users/abhiacherjee/Documents/rootbench/root/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()

# Configuration for installation type "full"
list(APPEND CPACK_ALL_INSTALL_TYPES full)
set(CPACK_INSTALL_TYPE_FULL_DISPLAY_NAME "Full Installation")

# Configuration for installation type "minimal"
list(APPEND CPACK_ALL_INSTALL_TYPES minimal)
set(CPACK_INSTALL_TYPE_MINIMAL_DISPLAY_NAME "Minimal Installation")

# Configuration for installation type "developer"
list(APPEND CPACK_ALL_INSTALL_TYPES developer)
set(CPACK_INSTALL_TYPE_DEVELOPER_DISPLAY_NAME "Developer Installation")

# Configuration for component "applications"

SET(CPACK_COMPONENTS_ALL LLVMAArch64AsmParser LLVMAArch64CodeGen LLVMAArch64Desc LLVMAArch64Disassembler LLVMAArch64Info LLVMAArch64Utils LLVMAggressiveInstCombine LLVMAnalysis LLVMAsmParser LLVMAsmPrinter LLVMBinaryFormat LLVMBitReader LLVMBitWriter LLVMBitstreamReader LLVMCFGuard LLVMCFIVerify LLVMCodeGen LLVMCore LLVMCoroutines LLVMCoverage LLVMDWARFLinker LLVMDWARFLinkerParallel LLVMDWP LLVMDebugInfoCodeView LLVMDebugInfoDWARF LLVMDebugInfoGSYM LLVMDebugInfoLogicalView LLVMDebugInfoMSF LLVMDebugInfoPDB LLVMDebuginfod LLVMDemangle LLVMDiff LLVMDlltoolDriver LLVMExecutionEngine LLVMExegesis LLVMExegesisAArch64 LLVMExtensions LLVMFileCheck LLVMFrontendHLSL LLVMFrontendOpenACC LLVMFrontendOpenMP LLVMFuzzMutate LLVMFuzzerCLI LLVMGlobalISel LLVMIRPrinter LLVMIRReader LLVMInstCombine LLVMInstrumentation LLVMInterfaceStub LLVMInterpreter LLVMJITLink LLVMLTO LLVMLibDriver LLVMLineEditor LLVMLinker LLVMMC LLVMMCA LLVMMCDisassembler LLVMMCJIT LLVMMCParser LLVMMIRParser LLVMNVPTXCodeGen LLVMNVPTXDesc LLVMNVPTXInfo LLVMObjCARCOpts LLVMObjCopy LLVMObject LLVMObjectYAML LLVMOption LLVMOrcJIT LLVMOrcShared LLVMOrcTargetProcess LLVMPasses LLVMProfileData LLVMRemarks LLVMRuntimeDyld LLVMScalarOpts LLVMSelectionDAG LLVMSupport LLVMSymbolize LLVMTableGen LLVMTableGenGlobalISel LLVMTarget LLVMTargetParser LLVMTextAPI LLVMTransformUtils LLVMVectorize LLVMWindowsDriver LLVMWindowsManifest LLVMXRay LLVMipo LTO Remarks Unspecified aarch64-resource-headers applications arm-common-resource-headers arm-resource-headers bash-autocomplete clang clang-cmake-exports clang-cpp clang-headers clang-resource-headers clang-tblgen clangAPINotes clangAST clangASTMatchers clangAnalysis clangAnalysisFlowSensitive clangAnalysisFlowSensitiveModels clangBasic clangCodeGen clangCrossTU clangDependencyScanning clangDirectoryWatcher clangDriver clangDynamicASTMatchers clangEdit clangExtractAPI clangFormat clangFrontend clangFrontendTool clangIndex clangIndexSerialization clangInterpreter clangLex clangParse clangRewrite clangRewriteFrontend clangSema clangSerialization clangStaticAnalyzerCheckers clangStaticAnalyzerCore clangStaticAnalyzerFrontend clangSupport clangTooling clangToolingASTDiff clangToolingCore clangToolingInclusions clangToolingInclusionsStdlib clangToolingRefactoring clangToolingSyntax clangTransformer cling-cmake-exports clingDemoPlugin clingInterpreter clingMetaProcessor clingUtils cmake-exports core-resource-headers cuda-resource-headers headers hexagon-resource-headers hip-resource-headers hlsl-resource-headers hmaptool libraries llvm-headers llvm-tblgen loongarch-resource-headers mips-resource-headers opencl-resource-headers openmp-resource-headers opt-viewer ppc-htm-resource-headers ppc-resource-headers systemz-resource-headers tests utility-resource-headers ve-resource-headers webassembly-resource-headers windows-resource-headers x86-resource-headers)
set(CPACK_COMPONENT_APPLICATIONS_DISPLAY_NAME "ROOT Applications")
set(CPACK_COMPONENT_APPLICATIONS_DESCRIPTION "ROOT executables such as root.exe")
set(CPACK_COMPONENT_APPLICATIONS_INSTALL_TYPES full minimal developer)

# Configuration for component "libraries"

SET(CPACK_COMPONENTS_ALL LLVMAArch64AsmParser LLVMAArch64CodeGen LLVMAArch64Desc LLVMAArch64Disassembler LLVMAArch64Info LLVMAArch64Utils LLVMAggressiveInstCombine LLVMAnalysis LLVMAsmParser LLVMAsmPrinter LLVMBinaryFormat LLVMBitReader LLVMBitWriter LLVMBitstreamReader LLVMCFGuard LLVMCFIVerify LLVMCodeGen LLVMCore LLVMCoroutines LLVMCoverage LLVMDWARFLinker LLVMDWARFLinkerParallel LLVMDWP LLVMDebugInfoCodeView LLVMDebugInfoDWARF LLVMDebugInfoGSYM LLVMDebugInfoLogicalView LLVMDebugInfoMSF LLVMDebugInfoPDB LLVMDebuginfod LLVMDemangle LLVMDiff LLVMDlltoolDriver LLVMExecutionEngine LLVMExegesis LLVMExegesisAArch64 LLVMExtensions LLVMFileCheck LLVMFrontendHLSL LLVMFrontendOpenACC LLVMFrontendOpenMP LLVMFuzzMutate LLVMFuzzerCLI LLVMGlobalISel LLVMIRPrinter LLVMIRReader LLVMInstCombine LLVMInstrumentation LLVMInterfaceStub LLVMInterpreter LLVMJITLink LLVMLTO LLVMLibDriver LLVMLineEditor LLVMLinker LLVMMC LLVMMCA LLVMMCDisassembler LLVMMCJIT LLVMMCParser LLVMMIRParser LLVMNVPTXCodeGen LLVMNVPTXDesc LLVMNVPTXInfo LLVMObjCARCOpts LLVMObjCopy LLVMObject LLVMObjectYAML LLVMOption LLVMOrcJIT LLVMOrcShared LLVMOrcTargetProcess LLVMPasses LLVMProfileData LLVMRemarks LLVMRuntimeDyld LLVMScalarOpts LLVMSelectionDAG LLVMSupport LLVMSymbolize LLVMTableGen LLVMTableGenGlobalISel LLVMTarget LLVMTargetParser LLVMTextAPI LLVMTransformUtils LLVMVectorize LLVMWindowsDriver LLVMWindowsManifest LLVMXRay LLVMipo LTO Remarks Unspecified aarch64-resource-headers applications arm-common-resource-headers arm-resource-headers bash-autocomplete clang clang-cmake-exports clang-cpp clang-headers clang-resource-headers clang-tblgen clangAPINotes clangAST clangASTMatchers clangAnalysis clangAnalysisFlowSensitive clangAnalysisFlowSensitiveModels clangBasic clangCodeGen clangCrossTU clangDependencyScanning clangDirectoryWatcher clangDriver clangDynamicASTMatchers clangEdit clangExtractAPI clangFormat clangFrontend clangFrontendTool clangIndex clangIndexSerialization clangInterpreter clangLex clangParse clangRewrite clangRewriteFrontend clangSema clangSerialization clangStaticAnalyzerCheckers clangStaticAnalyzerCore clangStaticAnalyzerFrontend clangSupport clangTooling clangToolingASTDiff clangToolingCore clangToolingInclusions clangToolingInclusionsStdlib clangToolingRefactoring clangToolingSyntax clangTransformer cling-cmake-exports clingDemoPlugin clingInterpreter clingMetaProcessor clingUtils cmake-exports core-resource-headers cuda-resource-headers headers hexagon-resource-headers hip-resource-headers hlsl-resource-headers hmaptool libraries llvm-headers llvm-tblgen loongarch-resource-headers mips-resource-headers opencl-resource-headers openmp-resource-headers opt-viewer ppc-htm-resource-headers ppc-resource-headers systemz-resource-headers tests utility-resource-headers ve-resource-headers webassembly-resource-headers windows-resource-headers x86-resource-headers)
set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "ROOT Libraries")
set(CPACK_COMPONENT_LIBRARIES_DESCRIPTION "All ROOT libraries and dictionaries")
set(CPACK_COMPONENT_LIBRARIES_INSTALL_TYPES full minimal developer)

# Configuration for component "headers"

SET(CPACK_COMPONENTS_ALL LLVMAArch64AsmParser LLVMAArch64CodeGen LLVMAArch64Desc LLVMAArch64Disassembler LLVMAArch64Info LLVMAArch64Utils LLVMAggressiveInstCombine LLVMAnalysis LLVMAsmParser LLVMAsmPrinter LLVMBinaryFormat LLVMBitReader LLVMBitWriter LLVMBitstreamReader LLVMCFGuard LLVMCFIVerify LLVMCodeGen LLVMCore LLVMCoroutines LLVMCoverage LLVMDWARFLinker LLVMDWARFLinkerParallel LLVMDWP LLVMDebugInfoCodeView LLVMDebugInfoDWARF LLVMDebugInfoGSYM LLVMDebugInfoLogicalView LLVMDebugInfoMSF LLVMDebugInfoPDB LLVMDebuginfod LLVMDemangle LLVMDiff LLVMDlltoolDriver LLVMExecutionEngine LLVMExegesis LLVMExegesisAArch64 LLVMExtensions LLVMFileCheck LLVMFrontendHLSL LLVMFrontendOpenACC LLVMFrontendOpenMP LLVMFuzzMutate LLVMFuzzerCLI LLVMGlobalISel LLVMIRPrinter LLVMIRReader LLVMInstCombine LLVMInstrumentation LLVMInterfaceStub LLVMInterpreter LLVMJITLink LLVMLTO LLVMLibDriver LLVMLineEditor LLVMLinker LLVMMC LLVMMCA LLVMMCDisassembler LLVMMCJIT LLVMMCParser LLVMMIRParser LLVMNVPTXCodeGen LLVMNVPTXDesc LLVMNVPTXInfo LLVMObjCARCOpts LLVMObjCopy LLVMObject LLVMObjectYAML LLVMOption LLVMOrcJIT LLVMOrcShared LLVMOrcTargetProcess LLVMPasses LLVMProfileData LLVMRemarks LLVMRuntimeDyld LLVMScalarOpts LLVMSelectionDAG LLVMSupport LLVMSymbolize LLVMTableGen LLVMTableGenGlobalISel LLVMTarget LLVMTargetParser LLVMTextAPI LLVMTransformUtils LLVMVectorize LLVMWindowsDriver LLVMWindowsManifest LLVMXRay LLVMipo LTO Remarks Unspecified aarch64-resource-headers applications arm-common-resource-headers arm-resource-headers bash-autocomplete clang clang-cmake-exports clang-cpp clang-headers clang-resource-headers clang-tblgen clangAPINotes clangAST clangASTMatchers clangAnalysis clangAnalysisFlowSensitive clangAnalysisFlowSensitiveModels clangBasic clangCodeGen clangCrossTU clangDependencyScanning clangDirectoryWatcher clangDriver clangDynamicASTMatchers clangEdit clangExtractAPI clangFormat clangFrontend clangFrontendTool clangIndex clangIndexSerialization clangInterpreter clangLex clangParse clangRewrite clangRewriteFrontend clangSema clangSerialization clangStaticAnalyzerCheckers clangStaticAnalyzerCore clangStaticAnalyzerFrontend clangSupport clangTooling clangToolingASTDiff clangToolingCore clangToolingInclusions clangToolingInclusionsStdlib clangToolingRefactoring clangToolingSyntax clangTransformer cling-cmake-exports clingDemoPlugin clingInterpreter clingMetaProcessor clingUtils cmake-exports core-resource-headers cuda-resource-headers headers hexagon-resource-headers hip-resource-headers hlsl-resource-headers hmaptool libraries llvm-headers llvm-tblgen loongarch-resource-headers mips-resource-headers opencl-resource-headers openmp-resource-headers opt-viewer ppc-htm-resource-headers ppc-resource-headers systemz-resource-headers tests utility-resource-headers ve-resource-headers webassembly-resource-headers windows-resource-headers x86-resource-headers)
set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C++ Headers")
set(CPACK_COMPONENT_HEADERS_DESCRIPTION "These are needed to do any development")
set(CPACK_COMPONENT_HEADERS_INSTALL_TYPES full developer)

# Configuration for component "tests"

SET(CPACK_COMPONENTS_ALL LLVMAArch64AsmParser LLVMAArch64CodeGen LLVMAArch64Desc LLVMAArch64Disassembler LLVMAArch64Info LLVMAArch64Utils LLVMAggressiveInstCombine LLVMAnalysis LLVMAsmParser LLVMAsmPrinter LLVMBinaryFormat LLVMBitReader LLVMBitWriter LLVMBitstreamReader LLVMCFGuard LLVMCFIVerify LLVMCodeGen LLVMCore LLVMCoroutines LLVMCoverage LLVMDWARFLinker LLVMDWARFLinkerParallel LLVMDWP LLVMDebugInfoCodeView LLVMDebugInfoDWARF LLVMDebugInfoGSYM LLVMDebugInfoLogicalView LLVMDebugInfoMSF LLVMDebugInfoPDB LLVMDebuginfod LLVMDemangle LLVMDiff LLVMDlltoolDriver LLVMExecutionEngine LLVMExegesis LLVMExegesisAArch64 LLVMExtensions LLVMFileCheck LLVMFrontendHLSL LLVMFrontendOpenACC LLVMFrontendOpenMP LLVMFuzzMutate LLVMFuzzerCLI LLVMGlobalISel LLVMIRPrinter LLVMIRReader LLVMInstCombine LLVMInstrumentation LLVMInterfaceStub LLVMInterpreter LLVMJITLink LLVMLTO LLVMLibDriver LLVMLineEditor LLVMLinker LLVMMC LLVMMCA LLVMMCDisassembler LLVMMCJIT LLVMMCParser LLVMMIRParser LLVMNVPTXCodeGen LLVMNVPTXDesc LLVMNVPTXInfo LLVMObjCARCOpts LLVMObjCopy LLVMObject LLVMObjectYAML LLVMOption LLVMOrcJIT LLVMOrcShared LLVMOrcTargetProcess LLVMPasses LLVMProfileData LLVMRemarks LLVMRuntimeDyld LLVMScalarOpts LLVMSelectionDAG LLVMSupport LLVMSymbolize LLVMTableGen LLVMTableGenGlobalISel LLVMTarget LLVMTargetParser LLVMTextAPI LLVMTransformUtils LLVMVectorize LLVMWindowsDriver LLVMWindowsManifest LLVMXRay LLVMipo LTO Remarks Unspecified aarch64-resource-headers applications arm-common-resource-headers arm-resource-headers bash-autocomplete clang clang-cmake-exports clang-cpp clang-headers clang-resource-headers clang-tblgen clangAPINotes clangAST clangASTMatchers clangAnalysis clangAnalysisFlowSensitive clangAnalysisFlowSensitiveModels clangBasic clangCodeGen clangCrossTU clangDependencyScanning clangDirectoryWatcher clangDriver clangDynamicASTMatchers clangEdit clangExtractAPI clangFormat clangFrontend clangFrontendTool clangIndex clangIndexSerialization clangInterpreter clangLex clangParse clangRewrite clangRewriteFrontend clangSema clangSerialization clangStaticAnalyzerCheckers clangStaticAnalyzerCore clangStaticAnalyzerFrontend clangSupport clangTooling clangToolingASTDiff clangToolingCore clangToolingInclusions clangToolingInclusionsStdlib clangToolingRefactoring clangToolingSyntax clangTransformer cling-cmake-exports clingDemoPlugin clingInterpreter clingMetaProcessor clingUtils cmake-exports core-resource-headers cuda-resource-headers headers hexagon-resource-headers hip-resource-headers hlsl-resource-headers hmaptool libraries llvm-headers llvm-tblgen loongarch-resource-headers mips-resource-headers opencl-resource-headers openmp-resource-headers opt-viewer ppc-htm-resource-headers ppc-resource-headers systemz-resource-headers tests utility-resource-headers ve-resource-headers webassembly-resource-headers windows-resource-headers x86-resource-headers)
set(CPACK_COMPONENT_TESTS_DISPLAY_NAME "ROOT Tests and Tutorials")
set(CPACK_COMPONENT_TESTS_DESCRIPTION "These are needed to do any test and tutorial")
set(CPACK_COMPONENT_TESTS_INSTALL_TYPES full developer)
