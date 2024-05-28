file(REMOVE_RECURSE
  "AArch64GenAsmMatcher.inc"
  "AArch64GenAsmWriter.inc"
  "AArch64GenAsmWriter1.inc"
  "AArch64GenCallingConv.inc"
  "AArch64GenDAGISel.inc"
  "AArch64GenDisassemblerTables.inc"
  "AArch64GenExegesis.inc"
  "AArch64GenFastISel.inc"
  "AArch64GenGlobalISel.inc"
  "AArch64GenInstrInfo.inc"
  "AArch64GenMCCodeEmitter.inc"
  "AArch64GenMCPseudoLowering.inc"
  "AArch64GenO0PreLegalizeGICombiner.inc"
  "AArch64GenPostLegalizeGICombiner.inc"
  "AArch64GenPostLegalizeGILowering.inc"
  "AArch64GenPreLegalizeGICombiner.inc"
  "AArch64GenRegisterBank.inc"
  "AArch64GenRegisterInfo.inc"
  "AArch64GenSubtargetInfo.inc"
  "AArch64GenSystemOperands.inc"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/AArch64.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
