/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Register Enum Values                                                *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_ENUM
#undef GET_REGINFO_ENUM

namespace llvm {

class MCRegisterClass;
extern const MCRegisterClass NVPTXMCRegisterClasses[];

namespace NVPTX {
enum {
  NoRegister,
  VRDepot = 1,
  ENVREG0 = 2,
  ENVREG1 = 3,
  ENVREG2 = 4,
  ENVREG3 = 5,
  ENVREG4 = 6,
  ENVREG5 = 7,
  ENVREG6 = 8,
  ENVREG7 = 9,
  ENVREG8 = 10,
  ENVREG9 = 11,
  ENVREG10 = 12,
  ENVREG11 = 13,
  ENVREG12 = 14,
  ENVREG13 = 15,
  ENVREG14 = 16,
  ENVREG15 = 17,
  ENVREG16 = 18,
  ENVREG17 = 19,
  ENVREG18 = 20,
  ENVREG19 = 21,
  ENVREG20 = 22,
  ENVREG21 = 23,
  ENVREG22 = 24,
  ENVREG23 = 25,
  ENVREG24 = 26,
  ENVREG25 = 27,
  ENVREG26 = 28,
  ENVREG27 = 29,
  ENVREG28 = 30,
  ENVREG29 = 31,
  ENVREG30 = 32,
  ENVREG31 = 33,
  F0 = 34,
  F1 = 35,
  F2 = 36,
  F3 = 37,
  F4 = 38,
  FL0 = 39,
  FL1 = 40,
  FL2 = 41,
  FL3 = 42,
  FL4 = 43,
  H0 = 44,
  H1 = 45,
  H2 = 46,
  H3 = 47,
  H4 = 48,
  HH0 = 49,
  HH1 = 50,
  HH2 = 51,
  HH3 = 52,
  HH4 = 53,
  P0 = 54,
  P1 = 55,
  P2 = 56,
  P3 = 57,
  P4 = 58,
  R0 = 59,
  R1 = 60,
  R2 = 61,
  R3 = 62,
  R4 = 63,
  RL0 = 64,
  RL1 = 65,
  RL2 = 66,
  RL3 = 67,
  RL4 = 68,
  RS0 = 69,
  RS1 = 70,
  RS2 = 71,
  RS3 = 72,
  RS4 = 73,
  VRFrame32 = 74,
  VRFrame64 = 75,
  VRFrameLocal32 = 76,
  VRFrameLocal64 = 77,
  da0 = 78,
  da1 = 79,
  da2 = 80,
  da3 = 81,
  da4 = 82,
  fa0 = 83,
  fa1 = 84,
  fa2 = 85,
  fa3 = 86,
  fa4 = 87,
  ia0 = 88,
  ia1 = 89,
  ia2 = 90,
  ia3 = 91,
  ia4 = 92,
  la0 = 93,
  la1 = 94,
  la2 = 95,
  la3 = 96,
  la4 = 97,
  NUM_TARGET_REGS // 98
};
} // end namespace NVPTX

// Register classes

namespace NVPTX {
enum {
  Int1RegsRegClassID = 0,
  Float16RegsRegClassID = 1,
  Int16RegsRegClassID = 2,
  SpecialRegsRegClassID = 3,
  Int32RegsRegClassID = 4,
  Float16x2RegsRegClassID = 5,
  Float32ArgRegsRegClassID = 6,
  Float32RegsRegClassID = 7,
  Int32ArgRegsRegClassID = 8,
  Int32Regs_and_SpecialRegsRegClassID = 9,
  Int64RegsRegClassID = 10,
  Float64ArgRegsRegClassID = 11,
  Float64RegsRegClassID = 12,
  Int64ArgRegsRegClassID = 13,

};
} // end namespace NVPTX

// Register pressure sets enum.
namespace NVPTX {
enum RegisterPressureSets {
  Int32Regs_and_SpecialRegs = 0,
  Int1Regs = 1,
  Float16Regs = 2,
  Int16Regs = 3,
  Float16x2Regs = 4,
  Float32ArgRegs = 5,
  Float32Regs = 6,
  Int32ArgRegs = 7,
  Float64ArgRegs = 8,
  Float64Regs = 9,
  Int64ArgRegs = 10,
  Int32Regs = 11,
  Int64Regs = 12,
  SpecialRegs = 13,
  SpecialRegs_with_Int32Regs = 14,
};
} // end namespace NVPTX

} // end namespace llvm

#endif // GET_REGINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* MC Register Information                                                    *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_MC_DESC
#undef GET_REGINFO_MC_DESC

namespace llvm {

extern const MCPhysReg NVPTXRegDiffLists[] = {
  /* 0 */ 65535, 0,
};

extern const LaneBitmask NVPTXLaneMaskLists[] = {
  /* 0 */ LaneBitmask(0x0000000000000000), LaneBitmask::getAll(),
};

extern const uint16_t NVPTXSubRegIdxLists[] = {
  /* 0 */ 0,
};

extern const MCRegisterInfo::SubRegCoveredBits NVPTXSubRegIdxRanges[] = {
  { 65535, 65535 },
};


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverlength-strings"
#endif
extern const char NVPTXRegStrings[] = {
  /* 0 */ "ENVREG10\0"
  /* 9 */ "ENVREG20\0"
  /* 18 */ "ENVREG30\0"
  /* 27 */ "F0\0"
  /* 30 */ "ENVREG0\0"
  /* 38 */ "HH0\0"
  /* 42 */ "FL0\0"
  /* 46 */ "RL0\0"
  /* 50 */ "P0\0"
  /* 53 */ "R0\0"
  /* 56 */ "RS0\0"
  /* 60 */ "da0\0"
  /* 64 */ "fa0\0"
  /* 68 */ "ia0\0"
  /* 72 */ "la0\0"
  /* 76 */ "ENVREG11\0"
  /* 85 */ "ENVREG21\0"
  /* 94 */ "ENVREG31\0"
  /* 103 */ "F1\0"
  /* 106 */ "ENVREG1\0"
  /* 114 */ "HH1\0"
  /* 118 */ "FL1\0"
  /* 122 */ "RL1\0"
  /* 126 */ "P1\0"
  /* 129 */ "R1\0"
  /* 132 */ "RS1\0"
  /* 136 */ "da1\0"
  /* 140 */ "fa1\0"
  /* 144 */ "ia1\0"
  /* 148 */ "la1\0"
  /* 152 */ "ENVREG12\0"
  /* 161 */ "ENVREG22\0"
  /* 170 */ "VRFrame32\0"
  /* 180 */ "VRFrameLocal32\0"
  /* 195 */ "F2\0"
  /* 198 */ "ENVREG2\0"
  /* 206 */ "HH2\0"
  /* 210 */ "FL2\0"
  /* 214 */ "RL2\0"
  /* 218 */ "P2\0"
  /* 221 */ "R2\0"
  /* 224 */ "RS2\0"
  /* 228 */ "da2\0"
  /* 232 */ "fa2\0"
  /* 236 */ "ia2\0"
  /* 240 */ "la2\0"
  /* 244 */ "ENVREG13\0"
  /* 253 */ "ENVREG23\0"
  /* 262 */ "F3\0"
  /* 265 */ "ENVREG3\0"
  /* 273 */ "HH3\0"
  /* 277 */ "FL3\0"
  /* 281 */ "RL3\0"
  /* 285 */ "P3\0"
  /* 288 */ "R3\0"
  /* 291 */ "RS3\0"
  /* 295 */ "da3\0"
  /* 299 */ "fa3\0"
  /* 303 */ "ia3\0"
  /* 307 */ "la3\0"
  /* 311 */ "ENVREG14\0"
  /* 320 */ "ENVREG24\0"
  /* 329 */ "VRFrame64\0"
  /* 339 */ "VRFrameLocal64\0"
  /* 354 */ "F4\0"
  /* 357 */ "ENVREG4\0"
  /* 365 */ "HH4\0"
  /* 369 */ "FL4\0"
  /* 373 */ "RL4\0"
  /* 377 */ "P4\0"
  /* 380 */ "R4\0"
  /* 383 */ "RS4\0"
  /* 387 */ "da4\0"
  /* 391 */ "fa4\0"
  /* 395 */ "ia4\0"
  /* 399 */ "la4\0"
  /* 403 */ "ENVREG15\0"
  /* 412 */ "ENVREG25\0"
  /* 421 */ "ENVREG5\0"
  /* 429 */ "ENVREG16\0"
  /* 438 */ "ENVREG26\0"
  /* 447 */ "ENVREG6\0"
  /* 455 */ "ENVREG17\0"
  /* 464 */ "ENVREG27\0"
  /* 473 */ "ENVREG7\0"
  /* 481 */ "ENVREG18\0"
  /* 490 */ "ENVREG28\0"
  /* 499 */ "ENVREG8\0"
  /* 507 */ "ENVREG19\0"
  /* 516 */ "ENVREG29\0"
  /* 525 */ "ENVREG9\0"
  /* 533 */ "VRDepot\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const MCRegisterDesc NVPTXRegDesc[] = { // Descriptors
  { 8, 0, 0, 0, 0, 0 },
  { 533, 1, 1, 0, 1, 0 },
  { 30, 1, 1, 0, 1, 0 },
  { 106, 1, 1, 0, 1, 0 },
  { 198, 1, 1, 0, 1, 0 },
  { 265, 1, 1, 0, 1, 0 },
  { 357, 1, 1, 0, 1, 0 },
  { 421, 1, 1, 0, 1, 0 },
  { 447, 1, 1, 0, 1, 0 },
  { 473, 1, 1, 0, 1, 0 },
  { 499, 1, 1, 0, 1, 0 },
  { 525, 1, 1, 0, 1, 0 },
  { 0, 1, 1, 0, 1, 0 },
  { 76, 1, 1, 0, 1, 0 },
  { 152, 1, 1, 0, 1, 0 },
  { 244, 1, 1, 0, 1, 0 },
  { 311, 1, 1, 0, 1, 0 },
  { 403, 1, 1, 0, 1, 0 },
  { 429, 1, 1, 0, 1, 0 },
  { 455, 1, 1, 0, 1, 0 },
  { 481, 1, 1, 0, 1, 0 },
  { 507, 1, 1, 0, 1, 0 },
  { 9, 1, 1, 0, 1, 0 },
  { 85, 1, 1, 0, 1, 0 },
  { 161, 1, 1, 0, 1, 0 },
  { 253, 1, 1, 0, 1, 0 },
  { 320, 1, 1, 0, 1, 0 },
  { 412, 1, 1, 0, 1, 0 },
  { 438, 1, 1, 0, 1, 0 },
  { 464, 1, 1, 0, 1, 0 },
  { 490, 1, 1, 0, 1, 0 },
  { 516, 1, 1, 0, 1, 0 },
  { 18, 1, 1, 0, 1, 0 },
  { 94, 1, 1, 0, 1, 0 },
  { 27, 1, 1, 0, 1, 0 },
  { 103, 1, 1, 0, 1, 0 },
  { 195, 1, 1, 0, 1, 0 },
  { 262, 1, 1, 0, 1, 0 },
  { 354, 1, 1, 0, 1, 0 },
  { 42, 1, 1, 0, 1, 0 },
  { 118, 1, 1, 0, 1, 0 },
  { 210, 1, 1, 0, 1, 0 },
  { 277, 1, 1, 0, 1, 0 },
  { 369, 1, 1, 0, 1, 0 },
  { 39, 1, 1, 0, 1, 0 },
  { 115, 1, 1, 0, 1, 0 },
  { 207, 1, 1, 0, 1, 0 },
  { 274, 1, 1, 0, 1, 0 },
  { 366, 1, 1, 0, 1, 0 },
  { 38, 1, 1, 0, 1, 0 },
  { 114, 1, 1, 0, 1, 0 },
  { 206, 1, 1, 0, 1, 0 },
  { 273, 1, 1, 0, 1, 0 },
  { 365, 1, 1, 0, 1, 0 },
  { 50, 1, 1, 0, 1, 0 },
  { 126, 1, 1, 0, 1, 0 },
  { 218, 1, 1, 0, 1, 0 },
  { 285, 1, 1, 0, 1, 0 },
  { 377, 1, 1, 0, 1, 0 },
  { 53, 1, 1, 0, 1, 0 },
  { 129, 1, 1, 0, 1, 0 },
  { 221, 1, 1, 0, 1, 0 },
  { 288, 1, 1, 0, 1, 0 },
  { 380, 1, 1, 0, 1, 0 },
  { 46, 1, 1, 0, 1, 0 },
  { 122, 1, 1, 0, 1, 0 },
  { 214, 1, 1, 0, 1, 0 },
  { 281, 1, 1, 0, 1, 0 },
  { 373, 1, 1, 0, 1, 0 },
  { 56, 1, 1, 0, 1, 0 },
  { 132, 1, 1, 0, 1, 0 },
  { 224, 1, 1, 0, 1, 0 },
  { 291, 1, 1, 0, 1, 0 },
  { 383, 1, 1, 0, 1, 0 },
  { 170, 1, 1, 0, 1, 0 },
  { 329, 1, 1, 0, 1, 0 },
  { 180, 1, 1, 0, 1, 0 },
  { 339, 1, 1, 0, 1, 0 },
  { 60, 1, 1, 0, 1, 0 },
  { 136, 1, 1, 0, 1, 0 },
  { 228, 1, 1, 0, 1, 0 },
  { 295, 1, 1, 0, 1, 0 },
  { 387, 1, 1, 0, 1, 0 },
  { 64, 1, 1, 0, 1, 0 },
  { 140, 1, 1, 0, 1, 0 },
  { 232, 1, 1, 0, 1, 0 },
  { 299, 1, 1, 0, 1, 0 },
  { 391, 1, 1, 0, 1, 0 },
  { 68, 1, 1, 0, 1, 0 },
  { 144, 1, 1, 0, 1, 0 },
  { 236, 1, 1, 0, 1, 0 },
  { 303, 1, 1, 0, 1, 0 },
  { 395, 1, 1, 0, 1, 0 },
  { 72, 1, 1, 0, 1, 0 },
  { 148, 1, 1, 0, 1, 0 },
  { 240, 1, 1, 0, 1, 0 },
  { 307, 1, 1, 0, 1, 0 },
  { 399, 1, 1, 0, 1, 0 },
};

extern const MCPhysReg NVPTXRegUnitRoots[][2] = {
  { NVPTX::VRDepot },
  { NVPTX::ENVREG0 },
  { NVPTX::ENVREG1 },
  { NVPTX::ENVREG2 },
  { NVPTX::ENVREG3 },
  { NVPTX::ENVREG4 },
  { NVPTX::ENVREG5 },
  { NVPTX::ENVREG6 },
  { NVPTX::ENVREG7 },
  { NVPTX::ENVREG8 },
  { NVPTX::ENVREG9 },
  { NVPTX::ENVREG10 },
  { NVPTX::ENVREG11 },
  { NVPTX::ENVREG12 },
  { NVPTX::ENVREG13 },
  { NVPTX::ENVREG14 },
  { NVPTX::ENVREG15 },
  { NVPTX::ENVREG16 },
  { NVPTX::ENVREG17 },
  { NVPTX::ENVREG18 },
  { NVPTX::ENVREG19 },
  { NVPTX::ENVREG20 },
  { NVPTX::ENVREG21 },
  { NVPTX::ENVREG22 },
  { NVPTX::ENVREG23 },
  { NVPTX::ENVREG24 },
  { NVPTX::ENVREG25 },
  { NVPTX::ENVREG26 },
  { NVPTX::ENVREG27 },
  { NVPTX::ENVREG28 },
  { NVPTX::ENVREG29 },
  { NVPTX::ENVREG30 },
  { NVPTX::ENVREG31 },
  { NVPTX::F0 },
  { NVPTX::F1 },
  { NVPTX::F2 },
  { NVPTX::F3 },
  { NVPTX::F4 },
  { NVPTX::FL0 },
  { NVPTX::FL1 },
  { NVPTX::FL2 },
  { NVPTX::FL3 },
  { NVPTX::FL4 },
  { NVPTX::H0 },
  { NVPTX::H1 },
  { NVPTX::H2 },
  { NVPTX::H3 },
  { NVPTX::H4 },
  { NVPTX::HH0 },
  { NVPTX::HH1 },
  { NVPTX::HH2 },
  { NVPTX::HH3 },
  { NVPTX::HH4 },
  { NVPTX::P0 },
  { NVPTX::P1 },
  { NVPTX::P2 },
  { NVPTX::P3 },
  { NVPTX::P4 },
  { NVPTX::R0 },
  { NVPTX::R1 },
  { NVPTX::R2 },
  { NVPTX::R3 },
  { NVPTX::R4 },
  { NVPTX::RL0 },
  { NVPTX::RL1 },
  { NVPTX::RL2 },
  { NVPTX::RL3 },
  { NVPTX::RL4 },
  { NVPTX::RS0 },
  { NVPTX::RS1 },
  { NVPTX::RS2 },
  { NVPTX::RS3 },
  { NVPTX::RS4 },
  { NVPTX::VRFrame32 },
  { NVPTX::VRFrame64 },
  { NVPTX::VRFrameLocal32 },
  { NVPTX::VRFrameLocal64 },
  { NVPTX::da0 },
  { NVPTX::da1 },
  { NVPTX::da2 },
  { NVPTX::da3 },
  { NVPTX::da4 },
  { NVPTX::fa0 },
  { NVPTX::fa1 },
  { NVPTX::fa2 },
  { NVPTX::fa3 },
  { NVPTX::fa4 },
  { NVPTX::ia0 },
  { NVPTX::ia1 },
  { NVPTX::ia2 },
  { NVPTX::ia3 },
  { NVPTX::ia4 },
  { NVPTX::la0 },
  { NVPTX::la1 },
  { NVPTX::la2 },
  { NVPTX::la3 },
  { NVPTX::la4 },
};

namespace {     // Register classes...
  // Int1Regs Register Class...
  const MCPhysReg Int1Regs[] = {
    NVPTX::P0, NVPTX::P1, NVPTX::P2, NVPTX::P3, NVPTX::P4, 
  };

  // Int1Regs Bit set.
  const uint8_t Int1RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 
  };

  // Float16Regs Register Class...
  const MCPhysReg Float16Regs[] = {
    NVPTX::H0, NVPTX::H1, NVPTX::H2, NVPTX::H3, NVPTX::H4, 
  };

  // Float16Regs Bit set.
  const uint8_t Float16RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 
  };

  // Int16Regs Register Class...
  const MCPhysReg Int16Regs[] = {
    NVPTX::RS0, NVPTX::RS1, NVPTX::RS2, NVPTX::RS3, NVPTX::RS4, 
  };

  // Int16Regs Bit set.
  const uint8_t Int16RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 
  };

  // SpecialRegs Register Class...
  const MCPhysReg SpecialRegs[] = {
    NVPTX::VRFrame32, NVPTX::VRFrameLocal32, NVPTX::VRDepot, NVPTX::ENVREG0, NVPTX::ENVREG1, NVPTX::ENVREG2, NVPTX::ENVREG3, NVPTX::ENVREG4, NVPTX::ENVREG5, NVPTX::ENVREG6, NVPTX::ENVREG7, NVPTX::ENVREG8, NVPTX::ENVREG9, NVPTX::ENVREG10, NVPTX::ENVREG11, NVPTX::ENVREG12, NVPTX::ENVREG13, NVPTX::ENVREG14, NVPTX::ENVREG15, NVPTX::ENVREG16, NVPTX::ENVREG17, NVPTX::ENVREG18, NVPTX::ENVREG19, NVPTX::ENVREG20, NVPTX::ENVREG21, NVPTX::ENVREG22, NVPTX::ENVREG23, NVPTX::ENVREG24, NVPTX::ENVREG25, NVPTX::ENVREG26, NVPTX::ENVREG27, NVPTX::ENVREG28, NVPTX::ENVREG29, NVPTX::ENVREG30, NVPTX::ENVREG31, 
  };

  // SpecialRegs Bit set.
  const uint8_t SpecialRegsBits[] = {
    0xfe, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x14, 
  };

  // Int32Regs Register Class...
  const MCPhysReg Int32Regs[] = {
    NVPTX::R0, NVPTX::R1, NVPTX::R2, NVPTX::R3, NVPTX::R4, NVPTX::VRFrame32, NVPTX::VRFrameLocal32, 
  };

  // Int32Regs Bit set.
  const uint8_t Int32RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x14, 
  };

  // Float16x2Regs Register Class...
  const MCPhysReg Float16x2Regs[] = {
    NVPTX::HH0, NVPTX::HH1, NVPTX::HH2, NVPTX::HH3, NVPTX::HH4, 
  };

  // Float16x2Regs Bit set.
  const uint8_t Float16x2RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 
  };

  // Float32ArgRegs Register Class...
  const MCPhysReg Float32ArgRegs[] = {
    NVPTX::fa0, NVPTX::fa1, NVPTX::fa2, NVPTX::fa3, NVPTX::fa4, 
  };

  // Float32ArgRegs Bit set.
  const uint8_t Float32ArgRegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 
  };

  // Float32Regs Register Class...
  const MCPhysReg Float32Regs[] = {
    NVPTX::F0, NVPTX::F1, NVPTX::F2, NVPTX::F3, NVPTX::F4, 
  };

  // Float32Regs Bit set.
  const uint8_t Float32RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x7c, 
  };

  // Int32ArgRegs Register Class...
  const MCPhysReg Int32ArgRegs[] = {
    NVPTX::ia0, NVPTX::ia1, NVPTX::ia2, NVPTX::ia3, NVPTX::ia4, 
  };

  // Int32ArgRegs Bit set.
  const uint8_t Int32ArgRegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
  };

  // Int32Regs_and_SpecialRegs Register Class...
  const MCPhysReg Int32Regs_and_SpecialRegs[] = {
    NVPTX::VRFrame32, NVPTX::VRFrameLocal32, 
  };

  // Int32Regs_and_SpecialRegs Bit set.
  const uint8_t Int32Regs_and_SpecialRegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 
  };

  // Int64Regs Register Class...
  const MCPhysReg Int64Regs[] = {
    NVPTX::RL0, NVPTX::RL1, NVPTX::RL2, NVPTX::RL3, NVPTX::RL4, NVPTX::VRFrame64, NVPTX::VRFrameLocal64, 
  };

  // Int64Regs Bit set.
  const uint8_t Int64RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x28, 
  };

  // Float64ArgRegs Register Class...
  const MCPhysReg Float64ArgRegs[] = {
    NVPTX::da0, NVPTX::da1, NVPTX::da2, NVPTX::da3, NVPTX::da4, 
  };

  // Float64ArgRegs Bit set.
  const uint8_t Float64ArgRegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 
  };

  // Float64Regs Register Class...
  const MCPhysReg Float64Regs[] = {
    NVPTX::FL0, NVPTX::FL1, NVPTX::FL2, NVPTX::FL3, NVPTX::FL4, 
  };

  // Float64Regs Bit set.
  const uint8_t Float64RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 
  };

  // Int64ArgRegs Register Class...
  const MCPhysReg Int64ArgRegs[] = {
    NVPTX::la0, NVPTX::la1, NVPTX::la2, NVPTX::la3, NVPTX::la4, 
  };

  // Int64ArgRegs Bit set.
  const uint8_t Int64ArgRegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 
  };

} // end anonymous namespace


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverlength-strings"
#endif
extern const char NVPTXRegClassStrings[] = {
  /* 0 */ "Int1Regs\0"
  /* 9 */ "Float32Regs\0"
  /* 21 */ "Int32Regs\0"
  /* 31 */ "Float16x2Regs\0"
  /* 45 */ "Float64Regs\0"
  /* 57 */ "Int64Regs\0"
  /* 67 */ "Float16Regs\0"
  /* 79 */ "Int16Regs\0"
  /* 89 */ "Float32ArgRegs\0"
  /* 104 */ "Int32ArgRegs\0"
  /* 117 */ "Float64ArgRegs\0"
  /* 132 */ "Int64ArgRegs\0"
  /* 145 */ "Int32Regs_and_SpecialRegs\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const MCRegisterClass NVPTXMCRegisterClasses[] = {
  { Int1Regs, Int1RegsBits, 0, 5, sizeof(Int1RegsBits), NVPTX::Int1RegsRegClassID, 1, 1, true },
  { Float16Regs, Float16RegsBits, 67, 5, sizeof(Float16RegsBits), NVPTX::Float16RegsRegClassID, 16, 1, true },
  { Int16Regs, Int16RegsBits, 79, 5, sizeof(Int16RegsBits), NVPTX::Int16RegsRegClassID, 16, 1, true },
  { SpecialRegs, SpecialRegsBits, 159, 35, sizeof(SpecialRegsBits), NVPTX::SpecialRegsRegClassID, 32, 1, true },
  { Int32Regs, Int32RegsBits, 21, 7, sizeof(Int32RegsBits), NVPTX::Int32RegsRegClassID, 32, 1, true },
  { Float16x2Regs, Float16x2RegsBits, 31, 5, sizeof(Float16x2RegsBits), NVPTX::Float16x2RegsRegClassID, 32, 1, true },
  { Float32ArgRegs, Float32ArgRegsBits, 89, 5, sizeof(Float32ArgRegsBits), NVPTX::Float32ArgRegsRegClassID, 32, 1, true },
  { Float32Regs, Float32RegsBits, 9, 5, sizeof(Float32RegsBits), NVPTX::Float32RegsRegClassID, 32, 1, true },
  { Int32ArgRegs, Int32ArgRegsBits, 104, 5, sizeof(Int32ArgRegsBits), NVPTX::Int32ArgRegsRegClassID, 32, 1, true },
  { Int32Regs_and_SpecialRegs, Int32Regs_and_SpecialRegsBits, 145, 2, sizeof(Int32Regs_and_SpecialRegsBits), NVPTX::Int32Regs_and_SpecialRegsRegClassID, 32, 1, true },
  { Int64Regs, Int64RegsBits, 57, 7, sizeof(Int64RegsBits), NVPTX::Int64RegsRegClassID, 64, 1, true },
  { Float64ArgRegs, Float64ArgRegsBits, 117, 5, sizeof(Float64ArgRegsBits), NVPTX::Float64ArgRegsRegClassID, 64, 1, true },
  { Float64Regs, Float64RegsBits, 45, 5, sizeof(Float64RegsBits), NVPTX::Float64RegsRegClassID, 64, 1, true },
  { Int64ArgRegs, Int64ArgRegsBits, 132, 5, sizeof(Int64ArgRegsBits), NVPTX::Int64ArgRegsRegClassID, 64, 1, true },
};

extern const uint16_t NVPTXRegEncodingTable[] = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
};
static inline void InitNVPTXMCRegisterInfo(MCRegisterInfo *RI, unsigned RA, unsigned DwarfFlavour = 0, unsigned EHFlavour = 0, unsigned PC = 0) {
  RI->InitMCRegisterInfo(NVPTXRegDesc, 98, RA, PC, NVPTXMCRegisterClasses, 14, NVPTXRegUnitRoots, 97, NVPTXRegDiffLists, NVPTXLaneMaskLists, NVPTXRegStrings, NVPTXRegClassStrings, NVPTXSubRegIdxLists, 1,
NVPTXSubRegIdxRanges, NVPTXRegEncodingTable);

}

} // end namespace llvm

#endif // GET_REGINFO_MC_DESC

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Register Information Header Fragment                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_HEADER
#undef GET_REGINFO_HEADER

#include "llvm/CodeGen/TargetRegisterInfo.h"

namespace llvm {

class NVPTXFrameLowering;

struct NVPTXGenRegisterInfo : public TargetRegisterInfo {
  explicit NVPTXGenRegisterInfo(unsigned RA, unsigned D = 0, unsigned E = 0,
      unsigned PC = 0, unsigned HwMode = 0);
  const RegClassWeight &getRegClassWeight(const TargetRegisterClass *RC) const override;
  unsigned getRegUnitWeight(unsigned RegUnit) const override;
  unsigned getNumRegPressureSets() const override;
  const char *getRegPressureSetName(unsigned Idx) const override;
  unsigned getRegPressureSetLimit(const MachineFunction &MF, unsigned Idx) const override;
  const int *getRegClassPressureSets(const TargetRegisterClass *RC) const override;
  const int *getRegUnitPressureSets(unsigned RegUnit) const override;
  ArrayRef<const char *> getRegMaskNames() const override;
  ArrayRef<const uint32_t *> getRegMasks() const override;
  bool isGeneralPurposeRegister(const MachineFunction &, MCRegister) const override;
  bool isFixedRegister(const MachineFunction &, MCRegister) const override;
  bool isArgumentRegister(const MachineFunction &, MCRegister) const override;
  bool isConstantPhysReg(MCRegister PhysReg) const override final;
  /// Devirtualized TargetFrameLowering.
  static const NVPTXFrameLowering *getFrameLowering(
      const MachineFunction &MF);
};

namespace NVPTX { // Register classes
  extern const TargetRegisterClass Int1RegsRegClass;
  extern const TargetRegisterClass Float16RegsRegClass;
  extern const TargetRegisterClass Int16RegsRegClass;
  extern const TargetRegisterClass SpecialRegsRegClass;
  extern const TargetRegisterClass Int32RegsRegClass;
  extern const TargetRegisterClass Float16x2RegsRegClass;
  extern const TargetRegisterClass Float32ArgRegsRegClass;
  extern const TargetRegisterClass Float32RegsRegClass;
  extern const TargetRegisterClass Int32ArgRegsRegClass;
  extern const TargetRegisterClass Int32Regs_and_SpecialRegsRegClass;
  extern const TargetRegisterClass Int64RegsRegClass;
  extern const TargetRegisterClass Float64ArgRegsRegClass;
  extern const TargetRegisterClass Float64RegsRegClass;
  extern const TargetRegisterClass Int64ArgRegsRegClass;
} // end namespace NVPTX

} // end namespace llvm

#endif // GET_REGINFO_HEADER

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Register and Register Classes Information                           *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_TARGET_DESC
#undef GET_REGINFO_TARGET_DESC

namespace llvm {

extern const MCRegisterClass NVPTXMCRegisterClasses[];

static const MVT::SimpleValueType VTLists[] = {
  /* 0 */ MVT::i1, MVT::Other,
  /* 2 */ MVT::i16, MVT::Other,
  /* 4 */ MVT::i32, MVT::Other,
  /* 6 */ MVT::i64, MVT::Other,
  /* 8 */ MVT::f16, MVT::bf16, MVT::Other,
  /* 11 */ MVT::f32, MVT::Other,
  /* 13 */ MVT::f64, MVT::Other,
  /* 15 */ MVT::v2f16, MVT::v2bf16, MVT::Other,
};

static const char *SubRegIndexNameTable[] = { "" };


static const LaneBitmask SubRegIndexLaneMaskTable[] = {
  LaneBitmask::getAll(),
 };



static const TargetRegisterInfo::RegClassInfo RegClassInfos[] = {
  // Mode = 0 (Default)
  { 1, 1, 8, VTLists+0 },    // Int1Regs
  { 16, 16, 16, VTLists+8 },    // Float16Regs
  { 16, 16, 16, VTLists+2 },    // Int16Regs
  { 32, 32, 32, VTLists+4 },    // SpecialRegs
  { 32, 32, 32, VTLists+4 },    // Int32Regs
  { 32, 32, 32, VTLists+15 },    // Float16x2Regs
  { 32, 32, 32, VTLists+11 },    // Float32ArgRegs
  { 32, 32, 32, VTLists+11 },    // Float32Regs
  { 32, 32, 32, VTLists+4 },    // Int32ArgRegs
  { 32, 32, 32, VTLists+4 },    // Int32Regs_and_SpecialRegs
  { 64, 64, 64, VTLists+6 },    // Int64Regs
  { 64, 64, 64, VTLists+13 },    // Float64ArgRegs
  { 64, 64, 64, VTLists+13 },    // Float64Regs
  { 64, 64, 64, VTLists+6 },    // Int64ArgRegs
};

static const TargetRegisterClass *const NullRegClasses[] = { nullptr };

static const uint32_t Int1RegsSubClassMask[] = {
  0x00000001, 
};

static const uint32_t Float16RegsSubClassMask[] = {
  0x00000002, 
};

static const uint32_t Int16RegsSubClassMask[] = {
  0x00000004, 
};

static const uint32_t SpecialRegsSubClassMask[] = {
  0x00000208, 
};

static const uint32_t Int32RegsSubClassMask[] = {
  0x00000210, 
};

static const uint32_t Float16x2RegsSubClassMask[] = {
  0x00000020, 
};

static const uint32_t Float32ArgRegsSubClassMask[] = {
  0x00000040, 
};

static const uint32_t Float32RegsSubClassMask[] = {
  0x00000080, 
};

static const uint32_t Int32ArgRegsSubClassMask[] = {
  0x00000100, 
};

static const uint32_t Int32Regs_and_SpecialRegsSubClassMask[] = {
  0x00000200, 
};

static const uint32_t Int64RegsSubClassMask[] = {
  0x00000400, 
};

static const uint32_t Float64ArgRegsSubClassMask[] = {
  0x00000800, 
};

static const uint32_t Float64RegsSubClassMask[] = {
  0x00001000, 
};

static const uint32_t Int64ArgRegsSubClassMask[] = {
  0x00002000, 
};

static const uint16_t SuperRegIdxSeqs[] = {
  /* 0 */ 0,
};

static const TargetRegisterClass *const Int32Regs_and_SpecialRegsSuperclasses[] = {
  &NVPTX::SpecialRegsRegClass,
  &NVPTX::Int32RegsRegClass,
  nullptr
};


namespace NVPTX {   // Register class instances
  extern const TargetRegisterClass Int1RegsRegClass = {
    &NVPTXMCRegisterClasses[Int1RegsRegClassID],
    Int1RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Float16RegsRegClass = {
    &NVPTXMCRegisterClasses[Float16RegsRegClassID],
    Float16RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Int16RegsRegClass = {
    &NVPTXMCRegisterClasses[Int16RegsRegClassID],
    Int16RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass SpecialRegsRegClass = {
    &NVPTXMCRegisterClasses[SpecialRegsRegClassID],
    SpecialRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Int32RegsRegClass = {
    &NVPTXMCRegisterClasses[Int32RegsRegClassID],
    Int32RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Float16x2RegsRegClass = {
    &NVPTXMCRegisterClasses[Float16x2RegsRegClassID],
    Float16x2RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Float32ArgRegsRegClass = {
    &NVPTXMCRegisterClasses[Float32ArgRegsRegClassID],
    Float32ArgRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Float32RegsRegClass = {
    &NVPTXMCRegisterClasses[Float32RegsRegClassID],
    Float32RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Int32ArgRegsRegClass = {
    &NVPTXMCRegisterClasses[Int32ArgRegsRegClassID],
    Int32ArgRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Int32Regs_and_SpecialRegsRegClass = {
    &NVPTXMCRegisterClasses[Int32Regs_and_SpecialRegsRegClassID],
    Int32Regs_and_SpecialRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    Int32Regs_and_SpecialRegsSuperclasses,
    nullptr
  };

  extern const TargetRegisterClass Int64RegsRegClass = {
    &NVPTXMCRegisterClasses[Int64RegsRegClassID],
    Int64RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Float64ArgRegsRegClass = {
    &NVPTXMCRegisterClasses[Float64ArgRegsRegClassID],
    Float64ArgRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Float64RegsRegClass = {
    &NVPTXMCRegisterClasses[Float64RegsRegClassID],
    Float64RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Int64ArgRegsRegClass = {
    &NVPTXMCRegisterClasses[Int64ArgRegsRegClassID],
    Int64ArgRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

} // end namespace NVPTX

namespace {
  const TargetRegisterClass *const RegisterClasses[] = {
    &NVPTX::Int1RegsRegClass,
    &NVPTX::Float16RegsRegClass,
    &NVPTX::Int16RegsRegClass,
    &NVPTX::SpecialRegsRegClass,
    &NVPTX::Int32RegsRegClass,
    &NVPTX::Float16x2RegsRegClass,
    &NVPTX::Float32ArgRegsRegClass,
    &NVPTX::Float32RegsRegClass,
    &NVPTX::Int32ArgRegsRegClass,
    &NVPTX::Int32Regs_and_SpecialRegsRegClass,
    &NVPTX::Int64RegsRegClass,
    &NVPTX::Float64ArgRegsRegClass,
    &NVPTX::Float64RegsRegClass,
    &NVPTX::Int64ArgRegsRegClass,
  };
} // end anonymous namespace

static const uint8_t CostPerUseTable[] = { 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };


static const bool InAllocatableClassTable[] = { 
false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, };


static const TargetRegisterInfoDesc NVPTXRegInfoDesc = { // Extra Descriptors
CostPerUseTable, 1, InAllocatableClassTable};

/// Get the weight in units of pressure for this register class.
const RegClassWeight &NVPTXGenRegisterInfo::
getRegClassWeight(const TargetRegisterClass *RC) const {
  static const RegClassWeight RCWeightTable[] = {
    {1, 5},  	// Int1Regs
    {1, 5},  	// Float16Regs
    {1, 5},  	// Int16Regs
    {1, 35},  	// SpecialRegs
    {1, 7},  	// Int32Regs
    {1, 5},  	// Float16x2Regs
    {1, 5},  	// Float32ArgRegs
    {1, 5},  	// Float32Regs
    {1, 5},  	// Int32ArgRegs
    {1, 2},  	// Int32Regs_and_SpecialRegs
    {1, 7},  	// Int64Regs
    {1, 5},  	// Float64ArgRegs
    {1, 5},  	// Float64Regs
    {1, 5},  	// Int64ArgRegs
  };
  return RCWeightTable[RC->getID()];
}

/// Get the weight in units of pressure for this register unit.
unsigned NVPTXGenRegisterInfo::
getRegUnitWeight(unsigned RegUnit) const {
  assert(RegUnit < 97 && "invalid register unit");
  // All register units have unit weight.
  return 1;
}


// Get the number of dimensions of register pressure.
unsigned NVPTXGenRegisterInfo::getNumRegPressureSets() const {
  return 15;
}

// Get the name of this register unit pressure set.
const char *NVPTXGenRegisterInfo::
getRegPressureSetName(unsigned Idx) const {
  static const char *PressureNameTable[] = {
    "Int32Regs_and_SpecialRegs",
    "Int1Regs",
    "Float16Regs",
    "Int16Regs",
    "Float16x2Regs",
    "Float32ArgRegs",
    "Float32Regs",
    "Int32ArgRegs",
    "Float64ArgRegs",
    "Float64Regs",
    "Int64ArgRegs",
    "Int32Regs",
    "Int64Regs",
    "SpecialRegs",
    "SpecialRegs_with_Int32Regs",
  };
  return PressureNameTable[Idx];
}

// Get the register unit pressure limit for this dimension.
// This limit must be adjusted dynamically for reserved registers.
unsigned NVPTXGenRegisterInfo::
getRegPressureSetLimit(const MachineFunction &MF, unsigned Idx) const {
  static const uint8_t PressureLimitTable[] = {
    2,  	// 0: Int32Regs_and_SpecialRegs
    5,  	// 1: Int1Regs
    5,  	// 2: Float16Regs
    5,  	// 3: Int16Regs
    5,  	// 4: Float16x2Regs
    5,  	// 5: Float32ArgRegs
    5,  	// 6: Float32Regs
    5,  	// 7: Int32ArgRegs
    5,  	// 8: Float64ArgRegs
    5,  	// 9: Float64Regs
    5,  	// 10: Int64ArgRegs
    7,  	// 11: Int32Regs
    7,  	// 12: Int64Regs
    35,  	// 13: SpecialRegs
    40,  	// 14: SpecialRegs_with_Int32Regs
  };
  return PressureLimitTable[Idx];
}

/// Table of pressure sets per register class or unit.
static const int RCSetsTable[] = {
  /* 0 */ 1, -1,
  /* 2 */ 2, -1,
  /* 4 */ 3, -1,
  /* 6 */ 4, -1,
  /* 8 */ 5, -1,
  /* 10 */ 6, -1,
  /* 12 */ 7, -1,
  /* 14 */ 8, -1,
  /* 16 */ 9, -1,
  /* 18 */ 10, -1,
  /* 20 */ 12, -1,
  /* 22 */ 11, 14, -1,
  /* 25 */ 0, 11, 13, 14, -1,
};

/// Get the dimensions of register pressure impacted by this register class.
/// Returns a -1 terminated array of pressure set IDs
const int *NVPTXGenRegisterInfo::
getRegClassPressureSets(const TargetRegisterClass *RC) const {
  static const uint8_t RCSetStartTable[] = {
    0,2,4,27,22,6,8,10,12,25,20,14,16,18,};
  return &RCSetsTable[RCSetStartTable[RC->getID()]];
}

/// Get the dimensions of register pressure impacted by this register unit.
/// Returns a -1 terminated array of pressure set IDs
const int *NVPTXGenRegisterInfo::
getRegUnitPressureSets(unsigned RegUnit) const {
  assert(RegUnit < 97 && "invalid register unit");
  static const uint8_t RUSetStartTable[] = {
    27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,10,10,10,10,10,16,16,16,16,16,2,2,2,2,2,6,6,6,6,6,0,0,0,0,0,22,22,22,22,22,20,20,20,20,20,4,4,4,4,4,25,20,25,20,14,14,14,14,14,8,8,8,8,8,12,12,12,12,12,18,18,18,18,18,};
  return &RCSetsTable[RUSetStartTable[RegUnit]];
}

extern const MCRegisterDesc NVPTXRegDesc[];
extern const MCPhysReg NVPTXRegDiffLists[];
extern const LaneBitmask NVPTXLaneMaskLists[];
extern const char NVPTXRegStrings[];
extern const char NVPTXRegClassStrings[];
extern const MCPhysReg NVPTXRegUnitRoots[][2];
extern const uint16_t NVPTXSubRegIdxLists[];
extern const MCRegisterInfo::SubRegCoveredBits NVPTXSubRegIdxRanges[];
extern const uint16_t NVPTXRegEncodingTable[];
NVPTXGenRegisterInfo::
NVPTXGenRegisterInfo(unsigned RA, unsigned DwarfFlavour, unsigned EHFlavour,
      unsigned PC, unsigned HwMode)
  : TargetRegisterInfo(&NVPTXRegInfoDesc, RegisterClasses, RegisterClasses+14,
             SubRegIndexNameTable, SubRegIndexLaneMaskTable,
             LaneBitmask(0xFFFFFFFFFFFFFFFF), RegClassInfos, HwMode) {
  InitMCRegisterInfo(NVPTXRegDesc, 98, RA, PC,
                     NVPTXMCRegisterClasses, 14,
                     NVPTXRegUnitRoots,
                     97,
                     NVPTXRegDiffLists,
                     NVPTXLaneMaskLists,
                     NVPTXRegStrings,
                     NVPTXRegClassStrings,
                     NVPTXSubRegIdxLists,
                     1,
                     NVPTXSubRegIdxRanges,
                     NVPTXRegEncodingTable);

}



ArrayRef<const uint32_t *> NVPTXGenRegisterInfo::getRegMasks() const {
  return std::nullopt;
}

bool NVPTXGenRegisterInfo::
isGeneralPurposeRegister(const MachineFunction &MF, MCRegister PhysReg) const {
  return
      false;
}

bool NVPTXGenRegisterInfo::
isFixedRegister(const MachineFunction &MF, MCRegister PhysReg) const {
  return
      false;
}

bool NVPTXGenRegisterInfo::
isArgumentRegister(const MachineFunction &MF, MCRegister PhysReg) const {
  return
      false;
}

bool NVPTXGenRegisterInfo::
isConstantPhysReg(MCRegister PhysReg) const {
  return
      false;
}

ArrayRef<const char *> NVPTXGenRegisterInfo::getRegMaskNames() const {
  return std::nullopt;
}

const NVPTXFrameLowering *
NVPTXGenRegisterInfo::getFrameLowering(const MachineFunction &MF) {
  return static_cast<const NVPTXFrameLowering *>(
      MF.getSubtarget().getFrameLowering());
}

} // end namespace llvm

#endif // GET_REGINFO_TARGET_DESC

