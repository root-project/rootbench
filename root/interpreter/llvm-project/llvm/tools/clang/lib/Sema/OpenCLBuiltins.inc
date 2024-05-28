/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* OpenCL Builtin handling                                                    *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#include "llvm/ADT/StringRef.h"
using namespace clang;

enum OpenCLTypeID {
  OCLT_atomic_double,
  OCLT_atomic_flag,
  OCLT_atomic_float,
  OCLT_atomic_half,
  OCLT_atomic_int,
  OCLT_atomic_intptr_t,
  OCLT_atomic_long,
  OCLT_atomic_ptrdiff_t,
  OCLT_atomic_size_t,
  OCLT_atomic_uint,
  OCLT_atomic_uintptr_t,
  OCLT_atomic_ulong,
  OCLT_bool,
  OCLT_char,
  OCLT_clk_event_t,
  OCLT_clk_profiling_info,
  OCLT_double,
  OCLT_event_t,
  OCLT_float,
  OCLT_half,
  OCLT___half,
  OCLT_image1d_t,
  OCLT_image1d_array_t,
  OCLT_image1d_buffer_t,
  OCLT_image2d_t,
  OCLT_image2d_array_t,
  OCLT_image2d_array_depth_t,
  OCLT_image2d_array_msaa_t,
  OCLT_image2d_array_msaa_depth_t,
  OCLT_image2d_depth_t,
  OCLT_image2d_msaa_t,
  OCLT_image2d_msaa_depth_t,
  OCLT_image3d_t,
  OCLT_int,
  OCLT_intptr_t,
  OCLT_long,
  OCLT_cl_mem_fence_flags,
  OCLT_memory_order,
  OCLT_memory_scope,
  OCLT_ndrange_t,
  OCLT_ptrdiff_t,
  OCLT_queue_t,
  OCLT_reserve_id_t,
  OCLT_sampler_t,
  OCLT_short,
  OCLT_size_t,
  OCLT_uchar,
  OCLT_uint,
  OCLT_uintptr_t,
  OCLT_ulong,
  OCLT_ushort,
  OCLT_void,
  OCLT_AGenType1,
  OCLT_AGenTypeN,
  OCLT_AGenTypeNNoScalar,
  OCLT_AI2UGenTypeN,
  OCLT_AIGenType1,
  OCLT_AIGenTypeN,
  OCLT_AIGenTypeNNoScalar,
  OCLT_CharShortGenType1,
  OCLT_FGenTypeN,
  OCLT_GenTypeCharVecAndScalar,
  OCLT_GenTypeCharVecNoScalar,
  OCLT_GenTypeDoubleVec1234,
  OCLT_GenTypeDoubleVecAndScalar,
  OCLT_GenTypeDoubleVecNoScalar,
  OCLT_GenTypeFloatVec1234,
  OCLT_GenTypeFloatVecAndScalar,
  OCLT_GenTypeFloatVecNoScalar,
  OCLT_GenTypeHalfVec1234,
  OCLT_GenTypeHalfVecAndScalar,
  OCLT_GenTypeHalfVecNoScalar,
  OCLT_GenTypeIntVecAndScalar,
  OCLT_GenTypeIntVecNoScalar,
  OCLT_GenTypeLongVecAndScalar,
  OCLT_GenTypeLongVecNoScalar,
  OCLT_GenTypeShortVecAndScalar,
  OCLT_GenTypeShortVecNoScalar,
  OCLT_GenTypeUCharVecAndScalar,
  OCLT_GenTypeUCharVecNoScalar,
  OCLT_GenTypeUIntVecAndScalar,
  OCLT_GenTypeUIntVecNoScalar,
  OCLT_GenTypeULongVecAndScalar,
  OCLT_GenTypeULongVecNoScalar,
  OCLT_GenTypeUShortVecAndScalar,
  OCLT_GenTypeUShortVecNoScalar,
  OCLT_IntLongFloatGenType1,
  OCLT_SGenTypeN,
  OCLT_UGenTypeN,
};

// Image access qualifier.
enum OpenCLAccessQual : unsigned char {
  OCLAQ_None,
  OCLAQ_ReadOnly,
  OCLAQ_WriteOnly,
  OCLAQ_ReadWrite
};

// Represents a return type or argument type.
struct OpenCLTypeStruct {
  // A type (e.g. float, int, ...).
  const OpenCLTypeID ID;
  // Vector size (if applicable; 0 for scalars and generic types).
  const unsigned VectorWidth;
  // 0 if the type is not a pointer.
  const bool IsPointer : 1;
  // 0 if the type is not const.
  const bool IsConst : 1;
  // 0 if the type is not volatile.
  const bool IsVolatile : 1;
  // Access qualifier.
  const OpenCLAccessQual AccessQualifier;
  // Address space of the pointer (if applicable).
  const LangAS AS;
};

// One overload of an OpenCL builtin function.
struct OpenCLBuiltinStruct {
  // Index of the signature in the OpenCLTypeStruct table.
  const unsigned SigTableIndex;
  // Entries between index SigTableIndex and (SigTableIndex + NumTypes - 1) in
  // the SignatureTable represent the complete signature.  The first type at
  // index SigTableIndex is the return type.
  const unsigned NumTypes;
  // Function attribute __attribute__((pure))
  const bool IsPure : 1;
  // Function attribute __attribute__((const))
  const bool IsConst : 1;
  // Function attribute __attribute__((convergent))
  const bool IsConv : 1;
  // OpenCL extension(s) required for this overload.
  const unsigned short Extension;
  // OpenCL versions in which this overload is available.
  const unsigned short Versions;
};

static const char *FunctionExtensionTable[] = {
  // 0: ArmIntegerDotProductAccumulateInt16
  "cl_arm_integer_dot_product_accumulate_int16",
  // 1: ArmIntegerDotProductAccumulateInt8
  "cl_arm_integer_dot_product_accumulate_int8",
  // 2: ArmIntegerDotProductAccumulateSaturateInt8
  "cl_arm_integer_dot_product_accumulate_saturate_int8",
  // 3: ArmIntegerDotProductInt8
  "cl_arm_integer_dot_product_int8",
  // 4: FuncExtFloatAtomicsFp16GenericASAdd
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_add __opencl_c_ext_fp16_global_atomic_add",
  // 5: FuncExtFloatAtomicsFp16GenericASLoadStore
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_load_store __opencl_c_ext_fp16_local_atomic_load_store",
  // 6: FuncExtFloatAtomicsFp16GenericASMinMax
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_min_max __opencl_c_ext_fp16_global_atomic_min_max",
  // 7: FuncExtFloatAtomicsFp16GlobalASAdd
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_add",
  // 8: FuncExtFloatAtomicsFp16GlobalASLoadStore
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_load_store",
  // 9: FuncExtFloatAtomicsFp16GlobalASMinMax
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_min_max",
  // 10: FuncExtFloatAtomicsFp16LocalASAdd
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_add",
  // 11: FuncExtFloatAtomicsFp16LocalASLoadStore
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_load_store",
  // 12: FuncExtFloatAtomicsFp16LocalASMinMax
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_min_max",
  // 13: FuncExtFloatAtomicsFp32GenericASAdd
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_add __opencl_c_ext_fp32_global_atomic_add",
  // 14: FuncExtFloatAtomicsFp32GenericASMinMax
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_min_max __opencl_c_ext_fp32_global_atomic_min_max",
  // 15: FuncExtFloatAtomicsFp32GlobalASAdd
  "cl_ext_float_atomics __opencl_c_ext_fp32_global_atomic_add",
  // 16: FuncExtFloatAtomicsFp32GlobalASMinMax
  "cl_ext_float_atomics __opencl_c_ext_fp32_global_atomic_min_max",
  // 17: FuncExtFloatAtomicsFp32LocalASAdd
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_add",
  // 18: FuncExtFloatAtomicsFp32LocalASMinMax
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_min_max",
  // 19: FuncExtFloatAtomicsFp64GenericASAdd
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_add __opencl_c_ext_fp64_global_atomic_add",
  // 20: FuncExtFloatAtomicsFp64GenericASMinMax
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_min_max __opencl_c_ext_fp64_global_atomic_min_max",
  // 21: FuncExtFloatAtomicsFp64GlobalASAdd
  "cl_ext_float_atomics __opencl_c_ext_fp64_global_atomic_add",
  // 22: FuncExtFloatAtomicsFp64GlobalASMinMax
  "cl_ext_float_atomics __opencl_c_ext_fp64_global_atomic_min_max",
  // 23: FuncExtFloatAtomicsFp64LocalASAdd
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_add",
  // 24: FuncExtFloatAtomicsFp64LocalASMinMax
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_min_max",
  // 25: FuncExtKhrExtendedBitOps
  "cl_khr_extended_bit_ops",
  // 26: FuncExtKhrGlMsaaSharing
  "cl_khr_gl_msaa_sharing",
  // 27: FuncExtKhrGlobalInt32BaseAtomics
  "cl_khr_global_int32_base_atomics",
  // 28: FuncExtKhrGlobalInt32ExtendedAtomics
  "cl_khr_global_int32_extended_atomics",
  // 29: FuncExtKhrInt64BaseAtomics
  "cl_khr_int64_base_atomics",
  // 30: FuncExtKhrInt64ExtendedAtomics
  "cl_khr_int64_extended_atomics",
  // 31: FuncExtKhrLocalInt32BaseAtomics
  "cl_khr_local_int32_base_atomics",
  // 32: FuncExtKhrLocalInt32ExtendedAtomics
  "cl_khr_local_int32_extended_atomics",
  // 33: FuncExtKhrMipmapImage
  "cl_khr_mipmap_image",
  // 34: FuncExtKhrMipmapImageWrites
  "cl_khr_mipmap_image_writes",
  // 35: FuncExtKhrSubgroupBallot
  "cl_khr_subgroup_ballot",
  // 36: FuncExtKhrSubgroupClusteredReduce
  "cl_khr_subgroup_clustered_reduce",
  // 37: FuncExtKhrSubgroupExtendedTypes
  "cl_khr_subgroup_extended_types",
  // 38: FuncExtKhrSubgroupNonUniformArithmetic
  "cl_khr_subgroup_non_uniform_arithmetic",
  // 39: FuncExtKhrSubgroupNonUniformVote
  "cl_khr_subgroup_non_uniform_vote",
  // 40: FuncExtKhrSubgroupShuffle
  "cl_khr_subgroup_shuffle",
  // 41: FuncExtKhrSubgroupShuffleRelative
  "cl_khr_subgroup_shuffle_relative",
  // 42: FuncExtKhrSubgroups
  "__opencl_subgroup_builtins",
  // 43: FuncExtNone
  "",
  // 44: FuncExtOpenCLCDeviceEnqueue
  "__opencl_c_device_enqueue",
  // 45: FuncExtOpenCLCGenericAddressSpace
  "__opencl_c_generic_address_space",
  // 46: FuncExtOpenCLCNamedAddressSpaceBuiltins
  "__opencl_c_named_address_space_builtins",
  // 47: FuncExtOpenCLCPipes
  "__opencl_c_pipes",
  // 48: FuncExtOpenCLCReadWriteImages
  "__opencl_c_read_write_images",
  // 49: FuncExtOpenCLCWGCollectiveFunctions
  "__opencl_c_work_group_collective_functions",
  // 50: FuncExtOpenCLCxx
  "__cplusplus",
  // 51: anonymous_10046
  "__opencl_c_integer_dot_product_input_4x8bit",
  // 52: anonymous_10055
  "__opencl_c_integer_dot_product_input_4x8bit_packed",
  // 53: anonymous_10064
  "cl_khr_subgroup_rotate",
  // 54: anonymous_8060
  "__opencl_c_generic_address_space __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 55: anonymous_8062
  "__opencl_c_generic_address_space __opencl_c_atomic_scope_device",
  // 56: anonymous_8258
  "__opencl_c_named_address_space_builtins __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 57: anonymous_8260
  "__opencl_c_named_address_space_builtins __opencl_c_atomic_scope_device",
  // 58: anonymous_8817
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_load_store __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 59: anonymous_8820
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_load_store __opencl_c_atomic_scope_device",
  // 60: anonymous_8830
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_add __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 61: anonymous_8833
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_add __opencl_c_atomic_scope_device",
  // 62: anonymous_8837
  "cl_ext_float_atomics __opencl_c_ext_fp32_global_atomic_add __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 63: anonymous_8840
  "cl_ext_float_atomics __opencl_c_ext_fp32_global_atomic_add __opencl_c_atomic_scope_device",
  // 64: anonymous_8844
  "cl_ext_float_atomics __opencl_c_ext_fp64_global_atomic_add __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 65: anonymous_8847
  "cl_ext_float_atomics __opencl_c_ext_fp64_global_atomic_add __opencl_c_atomic_scope_device",
  // 66: anonymous_8860
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_min_max __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 67: anonymous_8863
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_min_max __opencl_c_atomic_scope_device",
  // 68: anonymous_8867
  "cl_ext_float_atomics __opencl_c_ext_fp32_global_atomic_min_max __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 69: anonymous_8870
  "cl_ext_float_atomics __opencl_c_ext_fp32_global_atomic_min_max __opencl_c_atomic_scope_device",
  // 70: anonymous_8874
  "cl_ext_float_atomics __opencl_c_ext_fp64_global_atomic_min_max __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 71: anonymous_8877
  "cl_ext_float_atomics __opencl_c_ext_fp64_global_atomic_min_max __opencl_c_atomic_scope_device",
  // 72: anonymous_8891
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_load_store __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 73: anonymous_8894
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_load_store __opencl_c_atomic_scope_device",
  // 74: anonymous_8904
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_add __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 75: anonymous_8907
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_add __opencl_c_atomic_scope_device",
  // 76: anonymous_8911
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_add __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 77: anonymous_8914
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_add __opencl_c_atomic_scope_device",
  // 78: anonymous_8918
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_add __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 79: anonymous_8921
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_add __opencl_c_atomic_scope_device",
  // 80: anonymous_8934
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_min_max __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 81: anonymous_8937
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_min_max __opencl_c_atomic_scope_device",
  // 82: anonymous_8941
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_min_max __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 83: anonymous_8944
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_min_max __opencl_c_atomic_scope_device",
  // 84: anonymous_8948
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_min_max __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 85: anonymous_8951
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_min_max __opencl_c_atomic_scope_device",
  // 86: anonymous_8965
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_load_store __opencl_c_ext_fp16_local_atomic_load_store __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 87: anonymous_8968
  "cl_ext_float_atomics __opencl_c_ext_fp16_global_atomic_load_store __opencl_c_ext_fp16_local_atomic_load_store __opencl_c_atomic_scope_device",
  // 88: anonymous_8978
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_add __opencl_c_ext_fp16_global_atomic_add __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 89: anonymous_8981
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_add __opencl_c_ext_fp16_global_atomic_add __opencl_c_atomic_scope_device",
  // 90: anonymous_8985
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_add __opencl_c_ext_fp32_global_atomic_add __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 91: anonymous_8988
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_add __opencl_c_ext_fp32_global_atomic_add __opencl_c_atomic_scope_device",
  // 92: anonymous_8992
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_add __opencl_c_ext_fp64_global_atomic_add __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 93: anonymous_8995
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_add __opencl_c_ext_fp64_global_atomic_add __opencl_c_atomic_scope_device",
  // 94: anonymous_9008
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_min_max __opencl_c_ext_fp16_global_atomic_min_max __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 95: anonymous_9011
  "cl_ext_float_atomics __opencl_c_ext_fp16_local_atomic_min_max __opencl_c_ext_fp16_global_atomic_min_max __opencl_c_atomic_scope_device",
  // 96: anonymous_9015
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_min_max __opencl_c_ext_fp32_global_atomic_min_max __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 97: anonymous_9018
  "cl_ext_float_atomics __opencl_c_ext_fp32_local_atomic_min_max __opencl_c_ext_fp32_global_atomic_min_max __opencl_c_atomic_scope_device",
  // 98: anonymous_9022
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_min_max __opencl_c_ext_fp64_global_atomic_min_max __opencl_c_atomic_order_seq_cst __opencl_c_atomic_scope_device",
  // 99: anonymous_9025
  "cl_ext_float_atomics __opencl_c_ext_fp64_local_atomic_min_max __opencl_c_ext_fp64_global_atomic_min_max __opencl_c_atomic_scope_device",
};

static const OpenCLTypeStruct TypeTable[] = {
  // 0
  {OCLT_AGenType1, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 1
  {OCLT_AGenTypeN, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 2
  {OCLT_AGenTypeNNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 3
  {OCLT_AI2UGenTypeN, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 4
  {OCLT_AIGenType1, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 5
  {OCLT_AIGenTypeN, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 6
  {OCLT_AIGenTypeNNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 7
  {OCLT_atomic_double, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 8
  {OCLT_atomic_flag, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 9
  {OCLT_atomic_float, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 10
  {OCLT_atomic_half, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 11
  {OCLT_atomic_int, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 12
  {OCLT_atomic_intptr_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 13
  {OCLT_atomic_long, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 14
  {OCLT_atomic_ptrdiff_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 15
  {OCLT_atomic_size_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 16
  {OCLT_atomic_uint, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 17
  {OCLT_atomic_uintptr_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 18
  {OCLT_atomic_ulong, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 19
  {OCLT_bool, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 20
  {OCLT_char, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 21
  {OCLT_CharShortGenType1, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 22
  {OCLT_clk_event_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 23
  {OCLT_clk_profiling_info, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 24
  {OCLT_double, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 25
  {OCLT_event_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 26
  {OCLT_FGenTypeN, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 27
  {OCLT_float, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 28
  {OCLT_GenTypeCharVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 29
  {OCLT_GenTypeCharVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 30
  {OCLT_GenTypeDoubleVec1234, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 31
  {OCLT_GenTypeDoubleVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 32
  {OCLT_GenTypeDoubleVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 33
  {OCLT_GenTypeFloatVec1234, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 34
  {OCLT_GenTypeFloatVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 35
  {OCLT_GenTypeFloatVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 36
  {OCLT_GenTypeHalfVec1234, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 37
  {OCLT_GenTypeHalfVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 38
  {OCLT_GenTypeHalfVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 39
  {OCLT_GenTypeIntVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 40
  {OCLT_GenTypeIntVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 41
  {OCLT_GenTypeLongVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 42
  {OCLT_GenTypeLongVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 43
  {OCLT_GenTypeShortVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 44
  {OCLT_GenTypeShortVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 45
  {OCLT_GenTypeUCharVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 46
  {OCLT_GenTypeUCharVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 47
  {OCLT_GenTypeUIntVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 48
  {OCLT_GenTypeUIntVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 49
  {OCLT_GenTypeULongVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 50
  {OCLT_GenTypeULongVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 51
  {OCLT_GenTypeUShortVecAndScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 52
  {OCLT_GenTypeUShortVecNoScalar, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 53
  {OCLT_half, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 54
  {OCLT___half, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 55
  {OCLT___half, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 56
  {OCLT___half, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 57
  {OCLT___half, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 58
  {OCLT___half, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 59
  {OCLT___half, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 60
  {OCLT___half, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 61
  {OCLT___half, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 62
  {OCLT___half, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 63
  {OCLT___half, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 64
  {OCLT_image1d_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 65
  {OCLT_image1d_array_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 66
  {OCLT_image1d_buffer_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 67
  {OCLT_image2d_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 68
  {OCLT_image2d_array_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 69
  {OCLT_image2d_array_depth_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 70
  {OCLT_image2d_array_msaa_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 71
  {OCLT_image2d_array_msaa_depth_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 72
  {OCLT_image2d_depth_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 73
  {OCLT_image2d_msaa_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 74
  {OCLT_image2d_msaa_depth_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 75
  {OCLT_image3d_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 76
  {OCLT_int, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 77
  {OCLT_IntLongFloatGenType1, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 78
  {OCLT_intptr_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 79
  {OCLT_long, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 80
  {OCLT_cl_mem_fence_flags, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 81
  {OCLT_memory_order, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 82
  {OCLT_memory_scope, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 83
  {OCLT_ndrange_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 84
  {OCLT_ptrdiff_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 85
  {OCLT_queue_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 86
  {OCLT_reserve_id_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 87
  {OCLT_SGenTypeN, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 88
  {OCLT_sampler_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 89
  {OCLT_short, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 90
  {OCLT_size_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 91
  {OCLT_uchar, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 92
  {OCLT_UGenTypeN, 0, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 93
  {OCLT_uint, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 94
  {OCLT_uintptr_t, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 95
  {OCLT_ulong, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 96
  {OCLT_ushort, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 97
  {OCLT_void, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 98
  {OCLT_double, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 99
  {OCLT_double, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 100
  {OCLT_double, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 101
  {OCLT_double, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 102
  {OCLT_double, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 103
  {OCLT_half, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 104
  {OCLT_half, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 105
  {OCLT_half, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 106
  {OCLT_half, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 107
  {OCLT_half, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 108
  {OCLT___half, 1, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 109
  {OCLT_char, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 110
  {OCLT_char, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 111
  {OCLT___half, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 112
  {OCLT_char, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 113
  {OCLT_char, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 114
  {OCLT_char, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 115
  {OCLT_uchar, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 116
  {OCLT_uchar, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 117
  {OCLT_uchar, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 118
  {OCLT_uchar, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 119
  {OCLT_uchar, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 120
  {OCLT_short, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 121
  {OCLT_short, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 122
  {OCLT_short, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 123
  {OCLT_short, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 124
  {OCLT_short, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 125
  {OCLT_ushort, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 126
  {OCLT_ushort, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 127
  {OCLT_ushort, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 128
  {OCLT_ushort, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 129
  {OCLT_ushort, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 130
  {OCLT_int, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 131
  {OCLT_int, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 132
  {OCLT_int, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 133
  {OCLT_int, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 134
  {OCLT_int, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 135
  {OCLT_uint, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 136
  {OCLT_uint, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 137
  {OCLT_uint, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 138
  {OCLT_uint, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 139
  {OCLT_uint, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 140
  {OCLT_long, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 141
  {OCLT_long, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 142
  {OCLT_long, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 143
  {OCLT_long, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 144
  {OCLT_long, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 145
  {OCLT_ulong, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 146
  {OCLT_ulong, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 147
  {OCLT_ulong, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 148
  {OCLT_ulong, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 149
  {OCLT_ulong, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 150
  {OCLT_FGenTypeN, 0, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 151
  {OCLT_GenTypeIntVecAndScalar, 0, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 152
  {OCLT_FGenTypeN, 0, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 153
  {OCLT_GenTypeIntVecAndScalar, 0, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 154
  {OCLT_FGenTypeN, 0, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 155
  {OCLT_GenTypeIntVecAndScalar, 0, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 156
  {OCLT_FGenTypeN, 0, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 157
  {OCLT_GenTypeIntVecAndScalar, 0, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 158
  {OCLT_char, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 159
  {OCLT_uchar, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 160
  {OCLT_short, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 161
  {OCLT_ushort, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 162
  {OCLT_int, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 163
  {OCLT_uint, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 164
  {OCLT_long, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 165
  {OCLT_ulong, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 166
  {OCLT_float, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 167
  {OCLT_double, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 168
  {OCLT_half, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 169
  {OCLT_char, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 170
  {OCLT_uchar, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 171
  {OCLT_short, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 172
  {OCLT_ushort, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 173
  {OCLT_int, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 174
  {OCLT_uint, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 175
  {OCLT_long, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 176
  {OCLT_ulong, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 177
  {OCLT_float, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 178
  {OCLT_double, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 179
  {OCLT_half, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 180
  {OCLT_char, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 181
  {OCLT_uchar, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 182
  {OCLT_short, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 183
  {OCLT_ushort, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 184
  {OCLT_int, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 185
  {OCLT_uint, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 186
  {OCLT_long, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 187
  {OCLT_ulong, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 188
  {OCLT_float, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 189
  {OCLT_double, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 190
  {OCLT_half, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 191
  {OCLT_char, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 192
  {OCLT_uchar, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 193
  {OCLT_short, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 194
  {OCLT_ushort, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 195
  {OCLT_int, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 196
  {OCLT_uint, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 197
  {OCLT_long, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 198
  {OCLT_ulong, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 199
  {OCLT_float, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 200
  {OCLT_double, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 201
  {OCLT_half, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 202
  {OCLT_char, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 203
  {OCLT_uchar, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 204
  {OCLT_short, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 205
  {OCLT_ushort, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 206
  {OCLT_int, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 207
  {OCLT_uint, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 208
  {OCLT_long, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 209
  {OCLT_ulong, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 210
  {OCLT_float, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 211
  {OCLT_double, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 212
  {OCLT_half, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 213
  {OCLT_char, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 214
  {OCLT_uchar, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 215
  {OCLT_short, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 216
  {OCLT_ushort, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 217
  {OCLT_int, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 218
  {OCLT_uint, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 219
  {OCLT_long, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 220
  {OCLT_ulong, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 221
  {OCLT_float, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 222
  {OCLT_double, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 223
  {OCLT_half, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 224
  {OCLT_char, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 225
  {OCLT_uchar, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 226
  {OCLT_short, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 227
  {OCLT_ushort, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 228
  {OCLT_int, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 229
  {OCLT_uint, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 230
  {OCLT_long, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 231
  {OCLT_ulong, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 232
  {OCLT_float, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 233
  {OCLT_double, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 234
  {OCLT_half, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 235
  {OCLT_char, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 236
  {OCLT_uchar, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 237
  {OCLT_short, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 238
  {OCLT_ushort, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 239
  {OCLT_int, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 240
  {OCLT_uint, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 241
  {OCLT_long, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 242
  {OCLT_ulong, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 243
  {OCLT_float, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 244
  {OCLT_double, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 245
  {OCLT_half, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 246
  {OCLT_char, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 247
  {OCLT_uchar, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 248
  {OCLT_short, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 249
  {OCLT_ushort, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 250
  {OCLT_int, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 251
  {OCLT_uint, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 252
  {OCLT_long, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 253
  {OCLT_ulong, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 254
  {OCLT_float, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 255
  {OCLT_double, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 256
  {OCLT_half, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 257
  {OCLT_float, 2, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 258
  {OCLT_char, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 259
  {OCLT_uchar, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 260
  {OCLT_short, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 261
  {OCLT_ushort, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 262
  {OCLT_int, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 263
  {OCLT_uint, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 264
  {OCLT_long, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 265
  {OCLT_ulong, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 266
  {OCLT_float, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 267
  {OCLT_double, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 268
  {OCLT_half, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_constant},
  // 269
  {OCLT_float, 3, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 270
  {OCLT_float, 4, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 271
  {OCLT_float, 8, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 272
  {OCLT_void, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 273
  {OCLT_void, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 274
  {OCLT_void, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 275
  {OCLT_AGenTypeN, 0, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 276
  {OCLT_AGenTypeN, 0, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 277
  {OCLT_AGenTypeN, 0, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 278
  {OCLT_AGenTypeN, 0, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 279
  {OCLT_AGenTypeN, 0, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_local},
  // 280
  {OCLT_event_t, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 281
  {OCLT_int, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 282
  {OCLT_int, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 283
  {OCLT_uint, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 284
  {OCLT_uint, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 285
  {OCLT_int, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 286
  {OCLT_uint, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 287
  {OCLT_long, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 288
  {OCLT_long, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 289
  {OCLT_ulong, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 290
  {OCLT_float, 16, 0, 0, 0, OCLAQ_None, clang::LangAS::Default},
  // 291
  {OCLT_ulong, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 292
  {OCLT_long, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 293
  {OCLT_ulong, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 294
  {OCLT_float, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 295
  {OCLT_float, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 296
  {OCLT_float, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 297
  {OCLT_int, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 298
  {OCLT_uint, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 299
  {OCLT_atomic_int, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 300
  {OCLT_atomic_uint, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 301
  {OCLT_atomic_long, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 302
  {OCLT_atomic_ulong, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 303
  {OCLT_atomic_float, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 304
  {OCLT_atomic_double, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 305
  {OCLT_atomic_uintptr_t, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 306
  {OCLT_atomic_flag, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 307
  {OCLT_atomic_int, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 308
  {OCLT_atomic_uint, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 309
  {OCLT_atomic_long, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 310
  {OCLT_atomic_ulong, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 311
  {OCLT_atomic_float, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 312
  {OCLT_atomic_double, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 313
  {OCLT_atomic_uintptr_t, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 314
  {OCLT_atomic_flag, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 315
  {OCLT_atomic_int, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 316
  {OCLT_atomic_uint, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 317
  {OCLT_atomic_long, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 318
  {OCLT_atomic_ulong, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 319
  {OCLT_atomic_float, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 320
  {OCLT_atomic_double, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 321
  {OCLT_atomic_uintptr_t, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 322
  {OCLT_atomic_flag, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 323
  {OCLT_atomic_int, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 324
  {OCLT_atomic_uint, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 325
  {OCLT_atomic_long, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 326
  {OCLT_atomic_ulong, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 327
  {OCLT_atomic_float, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 328
  {OCLT_atomic_double, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 329
  {OCLT_atomic_uintptr_t, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 330
  {OCLT_atomic_flag, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 331
  {OCLT_atomic_half, 1, 0, 0, 1, OCLAQ_None, clang::LangAS::Default},
  // 332
  {OCLT_atomic_half, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_global},
  // 333
  {OCLT_atomic_half, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_local},
  // 334
  {OCLT_atomic_half, 1, 1, 0, 1, OCLAQ_None, clang::LangAS::opencl_generic},
  // 335
  {OCLT_image1d_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 336
  {OCLT_image2d_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 337
  {OCLT_image1d_array_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 338
  {OCLT_image3d_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 339
  {OCLT_image2d_array_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 340
  {OCLT_image2d_depth_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 341
  {OCLT_image2d_array_depth_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 342
  {OCLT_image1d_buffer_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 343
  {OCLT_image2d_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 344
  {OCLT_image1d_array_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 345
  {OCLT_image3d_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 346
  {OCLT_image2d_array_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 347
  {OCLT_image1d_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 348
  {OCLT_image1d_buffer_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 349
  {OCLT_image2d_depth_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 350
  {OCLT_image2d_array_depth_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 351
  {OCLT_image2d_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 352
  {OCLT_image2d_array_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 353
  {OCLT_image1d_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 354
  {OCLT_image1d_buffer_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 355
  {OCLT_image1d_array_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 356
  {OCLT_image3d_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 357
  {OCLT_image2d_depth_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 358
  {OCLT_image2d_array_depth_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 359
  {OCLT_clk_event_t, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 360
  {OCLT_clk_event_t, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 361
  {OCLT_clk_event_t, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_generic},
  // 362
  {OCLT_void, 1, 1, 0, 0, OCLAQ_None, clang::LangAS::opencl_global},
  // 363
  {OCLT_size_t, 1, 0, 1, 0, OCLAQ_None, clang::LangAS::Default},
  // 364
  {OCLT_size_t, 1, 1, 1, 0, OCLAQ_None, clang::LangAS::opencl_private},
  // 365
  {OCLT_image2d_msaa_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 366
  {OCLT_image2d_array_msaa_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 367
  {OCLT_image2d_msaa_depth_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 368
  {OCLT_image2d_array_msaa_depth_t, 0, 0, 0, 0, OCLAQ_ReadOnly, clang::LangAS::Default},
  // 369
  {OCLT_image2d_msaa_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 370
  {OCLT_image2d_array_msaa_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 371
  {OCLT_image2d_msaa_depth_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 372
  {OCLT_image2d_array_msaa_depth_t, 0, 0, 0, 0, OCLAQ_WriteOnly, clang::LangAS::Default},
  // 373
  {OCLT_image2d_msaa_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 374
  {OCLT_image2d_array_msaa_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 375
  {OCLT_image2d_msaa_depth_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
  // 376
  {OCLT_image2d_array_msaa_depth_t, 0, 0, 0, 0, OCLAQ_ReadWrite, clang::LangAS::Default},
};

static const unsigned short SignatureTable[] = {
  // 0
  257, 257, 
  // 2
  107, 134, 
  // 4
  0, 0, 
  // 6
  4, 4, 
  // 8
  76, 76, 
  // 10
  53, 76, 
  // 12
  103, 130, 
  // 14
  0, 0, 93, 
  // 17
  104, 131, 
  // 19
  4, 4, 93, 
  // 22
  76, 76, 93, 
  // 25
  105, 132, 
  // 27
  5, 5, 5, 93, 93, 
  // 32
  87, 87, 93, 93, 
  // 36
  87, 92, 93, 93, 
  // 40
  92, 87, 93, 93, 
  // 44
  92, 92, 93, 93, 
  // 48
  5, 5, 
  // 50
  93, 117, 117, 
  // 53
  76, 112, 112, 
  // 56
  76, 117, 112, 
  // 59
  106, 133, 
  // 61
  76, 112, 117, 
  // 64
  93, 117, 117, 93, 
  // 68
  76, 112, 112, 76, 
  // 72
  76, 117, 112, 76, 
  // 76
  76, 112, 117, 76, 
  // 80
  93, 93, 93, 
  // 83
  76, 93, 93, 
  // 86
  93, 93, 93, 93, 
  // 90
  76, 93, 93, 76, 
  // 94
  0, 0, 76, 
  // 97
  0, 0, 76, 93, 
  // 101
  93, 125, 125, 93, 
  // 105
  76, 120, 120, 76, 
  // 109
  269, 269, 
  // 111
  270, 270, 
  // 113
  53, 93, 
  // 115
  103, 135, 
  // 117
  104, 136, 
  // 119
  105, 137, 
  // 121
  106, 138, 
  // 123
  271, 271, 
  // 125
  107, 139, 
  // 127
  290, 290, 
  // 129
  27, 24, 
  // 131
  53, 79, 
  // 133
  103, 140, 
  // 135
  104, 141, 
  // 137
  105, 142, 
  // 139
  106, 143, 
  // 141
  107, 144, 
  // 143
  257, 98, 
  // 145
  53, 95, 
  // 147
  103, 145, 
  // 149
  104, 146, 
  // 151
  105, 147, 
  // 153
  106, 148, 
  // 155
  269, 99, 
  // 157
  107, 149, 
  // 159
  270, 100, 
  // 161
  20, 27, 
  // 163
  109, 257, 
  // 165
  110, 269, 
  // 167
  112, 270, 
  // 169
  113, 271, 
  // 171
  114, 290, 
  // 173
  271, 101, 
  // 175
  290, 102, 
  // 177
  20, 24, 
  // 179
  109, 98, 
  // 181
  110, 99, 
  // 183
  112, 100, 
  // 185
  113, 101, 
  // 187
  114, 102, 
  // 189
  20, 53, 
  // 191
  109, 103, 
  // 193
  110, 104, 
  // 195
  112, 105, 
  // 197
  113, 106, 
  // 199
  114, 107, 
  // 201
  20, 20, 
  // 203
  109, 109, 
  // 205
  110, 110, 
  // 207
  112, 112, 
  // 209
  113, 113, 
  // 211
  114, 114, 
  // 213
  20, 91, 
  // 215
  109, 115, 
  // 217
  110, 116, 
  // 219
  112, 117, 
  // 221
  113, 118, 
  // 223
  114, 119, 
  // 225
  27, 53, 
  // 227
  20, 89, 
  // 229
  109, 120, 
  // 231
  110, 121, 
  // 233
  112, 122, 
  // 235
  113, 123, 
  // 237
  257, 103, 
  // 239
  114, 124, 
  // 241
  269, 104, 
  // 243
  270, 105, 
  // 245
  20, 96, 
  // 247
  109, 125, 
  // 249
  110, 126, 
  // 251
  112, 127, 
  // 253
  113, 128, 
  // 255
  271, 106, 
  // 257
  114, 129, 
  // 259
  290, 107, 
  // 261
  20, 76, 
  // 263
  109, 130, 
  // 265
  110, 131, 
  // 267
  112, 132, 
  // 269
  113, 133, 
  // 271
  114, 134, 
  // 273
  20, 93, 
  // 275
  109, 135, 
  // 277
  110, 136, 
  // 279
  112, 137, 
  // 281
  113, 138, 
  // 283
  114, 139, 
  // 285
  20, 79, 
  // 287
  109, 140, 
  // 289
  110, 141, 
  // 291
  112, 142, 
  // 293
  113, 143, 
  // 295
  114, 144, 
  // 297
  20, 95, 
  // 299
  109, 145, 
  // 301
  110, 146, 
  // 303
  112, 147, 
  // 305
  113, 148, 
  // 307
  114, 149, 
  // 309
  27, 20, 
  // 311
  257, 109, 
  // 313
  91, 27, 
  // 315
  115, 257, 
  // 317
  116, 269, 
  // 319
  117, 270, 
  // 321
  118, 271, 
  // 323
  119, 290, 
  // 325
  269, 110, 
  // 327
  270, 112, 
  // 329
  271, 113, 
  // 331
  91, 24, 
  // 333
  115, 98, 
  // 335
  116, 99, 
  // 337
  117, 100, 
  // 339
  118, 101, 
  // 341
  119, 102, 
  // 343
  290, 114, 
  // 345
  91, 53, 
  // 347
  115, 103, 
  // 349
  116, 104, 
  // 351
  117, 105, 
  // 353
  118, 106, 
  // 355
  119, 107, 
  // 357
  91, 20, 
  // 359
  115, 109, 
  // 361
  116, 110, 
  // 363
  117, 112, 
  // 365
  118, 113, 
  // 367
  119, 114, 
  // 369
  91, 91, 
  // 371
  115, 115, 
  // 373
  116, 116, 
  // 375
  117, 117, 
  // 377
  118, 118, 
  // 379
  119, 119, 
  // 381
  91, 89, 
  // 383
  115, 120, 
  // 385
  116, 121, 
  // 387
  117, 122, 
  // 389
  118, 123, 
  // 391
  119, 124, 
  // 393
  27, 91, 
  // 395
  257, 115, 
  // 397
  91, 96, 
  // 399
  115, 125, 
  // 401
  116, 126, 
  // 403
  117, 127, 
  // 405
  118, 128, 
  // 407
  269, 116, 
  // 409
  119, 129, 
  // 411
  270, 117, 
  // 413
  271, 118, 
  // 415
  91, 76, 
  // 417
  115, 130, 
  // 419
  116, 131, 
  // 421
  117, 132, 
  // 423
  118, 133, 
  // 425
  290, 119, 
  // 427
  119, 134, 
  // 429
  91, 93, 
  // 431
  115, 135, 
  // 433
  116, 136, 
  // 435
  117, 137, 
  // 437
  118, 138, 
  // 439
  119, 139, 
  // 441
  91, 79, 
  // 443
  115, 140, 
  // 445
  116, 141, 
  // 447
  117, 142, 
  // 449
  118, 143, 
  // 451
  119, 144, 
  // 453
  91, 95, 
  // 455
  115, 145, 
  // 457
  116, 146, 
  // 459
  117, 147, 
  // 461
  118, 148, 
  // 463
  119, 149, 
  // 465
  89, 27, 
  // 467
  120, 257, 
  // 469
  121, 269, 
  // 471
  122, 270, 
  // 473
  123, 271, 
  // 475
  124, 290, 
  // 477
  27, 89, 
  // 479
  257, 120, 
  // 481
  269, 121, 
  // 483
  89, 24, 
  // 485
  120, 98, 
  // 487
  121, 99, 
  // 489
  122, 100, 
  // 491
  123, 101, 
  // 493
  124, 102, 
  // 495
  270, 122, 
  // 497
  271, 123, 
  // 499
  290, 124, 
  // 501
  89, 53, 
  // 503
  120, 103, 
  // 505
  121, 104, 
  // 507
  122, 105, 
  // 509
  123, 106, 
  // 511
  124, 107, 
  // 513
  89, 20, 
  // 515
  120, 109, 
  // 517
  121, 110, 
  // 519
  122, 112, 
  // 521
  123, 113, 
  // 523
  124, 114, 
  // 525
  89, 91, 
  // 527
  120, 115, 
  // 529
  121, 116, 
  // 531
  122, 117, 
  // 533
  123, 118, 
  // 535
  124, 119, 
  // 537
  89, 89, 
  // 539
  120, 120, 
  // 541
  121, 121, 
  // 543
  122, 122, 
  // 545
  123, 123, 
  // 547
  124, 124, 
  // 549
  89, 96, 
  // 551
  120, 125, 
  // 553
  121, 126, 
  // 555
  122, 127, 
  // 557
  123, 128, 
  // 559
  27, 96, 
  // 561
  124, 129, 
  // 563
  257, 125, 
  // 565
  269, 126, 
  // 567
  89, 76, 
  // 569
  120, 130, 
  // 571
  121, 131, 
  // 573
  122, 132, 
  // 575
  123, 133, 
  // 577
  270, 127, 
  // 579
  124, 134, 
  // 581
  271, 128, 
  // 583
  290, 129, 
  // 585
  89, 93, 
  // 587
  120, 135, 
  // 589
  121, 136, 
  // 591
  122, 137, 
  // 593
  123, 138, 
  // 595
  124, 139, 
  // 597
  89, 79, 
  // 599
  120, 140, 
  // 601
  121, 141, 
  // 603
  122, 142, 
  // 605
  123, 143, 
  // 607
  124, 144, 
  // 609
  89, 95, 
  // 611
  120, 145, 
  // 613
  121, 146, 
  // 615
  122, 147, 
  // 617
  123, 148, 
  // 619
  124, 149, 
  // 621
  96, 27, 
  // 623
  125, 257, 
  // 625
  126, 269, 
  // 627
  127, 270, 
  // 629
  128, 271, 
  // 631
  129, 290, 
  // 633
  27, 76, 
  // 635
  96, 24, 
  // 637
  125, 98, 
  // 639
  126, 99, 
  // 641
  127, 100, 
  // 643
  128, 101, 
  // 645
  129, 102, 
  // 647
  257, 130, 
  // 649
  269, 131, 
  // 651
  270, 132, 
  // 653
  96, 53, 
  // 655
  125, 103, 
  // 657
  126, 104, 
  // 659
  127, 105, 
  // 661
  128, 106, 
  // 663
  129, 107, 
  // 665
  271, 133, 
  // 667
  290, 134, 
  // 669
  96, 20, 
  // 671
  125, 109, 
  // 673
  126, 110, 
  // 675
  127, 112, 
  // 677
  128, 113, 
  // 679
  129, 114, 
  // 681
  96, 91, 
  // 683
  125, 115, 
  // 685
  126, 116, 
  // 687
  127, 117, 
  // 689
  128, 118, 
  // 691
  129, 119, 
  // 693
  96, 89, 
  // 695
  125, 120, 
  // 697
  126, 121, 
  // 699
  127, 122, 
  // 701
  128, 123, 
  // 703
  129, 124, 
  // 705
  96, 96, 
  // 707
  125, 125, 
  // 709
  126, 126, 
  // 711
  127, 127, 
  // 713
  128, 128, 
  // 715
  129, 129, 
  // 717
  27, 93, 
  // 719
  96, 76, 
  // 721
  125, 130, 
  // 723
  126, 131, 
  // 725
  127, 132, 
  // 727
  128, 133, 
  // 729
  257, 135, 
  // 731
  129, 134, 
  // 733
  269, 136, 
  // 735
  270, 137, 
  // 737
  96, 93, 
  // 739
  125, 135, 
  // 741
  126, 136, 
  // 743
  127, 137, 
  // 745
  128, 138, 
  // 747
  271, 138, 
  // 749
  129, 139, 
  // 751
  290, 139, 
  // 753
  96, 79, 
  // 755
  125, 140, 
  // 757
  126, 141, 
  // 759
  127, 142, 
  // 761
  128, 143, 
  // 763
  129, 144, 
  // 765
  96, 95, 
  // 767
  125, 145, 
  // 769
  126, 146, 
  // 771
  127, 147, 
  // 773
  128, 148, 
  // 775
  129, 149, 
  // 777
  76, 27, 
  // 779
  130, 257, 
  // 781
  131, 269, 
  // 783
  132, 270, 
  // 785
  133, 271, 
  // 787
  134, 290, 
  // 789
  76, 24, 
  // 791
  130, 98, 
  // 793
  131, 99, 
  // 795
  132, 100, 
  // 797
  133, 101, 
  // 799
  134, 102, 
  // 801
  27, 79, 
  // 803
  257, 140, 
  // 805
  76, 53, 
  // 807
  130, 103, 
  // 809
  131, 104, 
  // 811
  132, 105, 
  // 813
  133, 106, 
  // 815
  134, 107, 
  // 817
  269, 141, 
  // 819
  270, 142, 
  // 821
  271, 143, 
  // 823
  76, 20, 
  // 825
  130, 109, 
  // 827
  131, 110, 
  // 829
  132, 112, 
  // 831
  133, 113, 
  // 833
  134, 114, 
  // 835
  290, 144, 
  // 837
  76, 91, 
  // 839
  130, 115, 
  // 841
  131, 116, 
  // 843
  132, 117, 
  // 845
  133, 118, 
  // 847
  134, 119, 
  // 849
  76, 89, 
  // 851
  130, 120, 
  // 853
  131, 121, 
  // 855
  132, 122, 
  // 857
  133, 123, 
  // 859
  134, 124, 
  // 861
  76, 96, 
  // 863
  130, 125, 
  // 865
  131, 126, 
  // 867
  132, 127, 
  // 869
  133, 128, 
  // 871
  134, 129, 
  // 873
  130, 130, 
  // 875
  131, 131, 
  // 877
  132, 132, 
  // 879
  133, 133, 
  // 881
  134, 134, 
  // 883
  27, 95, 
  // 885
  257, 145, 
  // 887
  76, 93, 
  // 889
  130, 135, 
  // 891
  131, 136, 
  // 893
  132, 137, 
  // 895
  133, 138, 
  // 897
  269, 146, 
  // 899
  134, 139, 
  // 901
  270, 147, 
  // 903
  271, 148, 
  // 905
  76, 79, 
  // 907
  130, 140, 
  // 909
  131, 141, 
  // 911
  132, 142, 
  // 913
  133, 143, 
  // 915
  290, 149, 
  // 917
  134, 144, 
  // 919
  76, 95, 
  // 921
  130, 145, 
  // 923
  131, 146, 
  // 925
  132, 147, 
  // 927
  133, 148, 
  // 929
  134, 149, 
  // 931
  93, 27, 
  // 933
  135, 257, 
  // 935
  136, 269, 
  // 937
  137, 270, 
  // 939
  138, 271, 
  // 941
  139, 290, 
  // 943
  93, 24, 
  // 945
  135, 98, 
  // 947
  136, 99, 
  // 949
  137, 100, 
  // 951
  138, 101, 
  // 953
  139, 102, 
  // 955
  93, 53, 
  // 957
  135, 103, 
  // 959
  136, 104, 
  // 961
  137, 105, 
  // 963
  138, 106, 
  // 965
  139, 107, 
  // 967
  24, 27, 
  // 969
  98, 257, 
  // 971
  99, 269, 
  // 973
  100, 270, 
  // 975
  101, 271, 
  // 977
  93, 20, 
  // 979
  135, 109, 
  // 981
  136, 110, 
  // 983
  137, 112, 
  // 985
  138, 113, 
  // 987
  102, 290, 
  // 989
  139, 114, 
  // 991
  93, 91, 
  // 993
  135, 115, 
  // 995
  136, 116, 
  // 997
  137, 117, 
  // 999
  138, 118, 
  // 1001
  139, 119, 
  // 1003
  93, 89, 
  // 1005
  135, 120, 
  // 1007
  136, 121, 
  // 1009
  137, 122, 
  // 1011
  138, 123, 
  // 1013
  139, 124, 
  // 1015
  93, 96, 
  // 1017
  135, 125, 
  // 1019
  136, 126, 
  // 1021
  137, 127, 
  // 1023
  138, 128, 
  // 1025
  139, 129, 
  // 1027
  93, 76, 
  // 1029
  135, 130, 
  // 1031
  136, 131, 
  // 1033
  137, 132, 
  // 1035
  138, 133, 
  // 1037
  139, 134, 
  // 1039
  24, 24, 
  // 1041
  98, 98, 
  // 1043
  99, 99, 
  // 1045
  100, 100, 
  // 1047
  101, 101, 
  // 1049
  93, 93, 
  // 1051
  135, 135, 
  // 1053
  136, 136, 
  // 1055
  137, 137, 
  // 1057
  138, 138, 
  // 1059
  102, 102, 
  // 1061
  139, 139, 
  // 1063
  93, 79, 
  // 1065
  135, 140, 
  // 1067
  136, 141, 
  // 1069
  137, 142, 
  // 1071
  138, 143, 
  // 1073
  139, 144, 
  // 1075
  93, 95, 
  // 1077
  135, 145, 
  // 1079
  136, 146, 
  // 1081
  137, 147, 
  // 1083
  138, 148, 
  // 1085
  139, 149, 
  // 1087
  79, 27, 
  // 1089
  140, 257, 
  // 1091
  141, 269, 
  // 1093
  142, 270, 
  // 1095
  143, 271, 
  // 1097
  144, 290, 
  // 1099
  79, 24, 
  // 1101
  140, 98, 
  // 1103
  141, 99, 
  // 1105
  142, 100, 
  // 1107
  143, 101, 
  // 1109
  144, 102, 
  // 1111
  24, 53, 
  // 1113
  98, 103, 
  // 1115
  99, 104, 
  // 1117
  100, 105, 
  // 1119
  101, 106, 
  // 1121
  79, 53, 
  // 1123
  140, 103, 
  // 1125
  141, 104, 
  // 1127
  142, 105, 
  // 1129
  143, 106, 
  // 1131
  102, 107, 
  // 1133
  144, 107, 
  // 1135
  79, 20, 
  // 1137
  140, 109, 
  // 1139
  141, 110, 
  // 1141
  142, 112, 
  // 1143
  143, 113, 
  // 1145
  144, 114, 
  // 1147
  79, 91, 
  // 1149
  140, 115, 
  // 1151
  141, 116, 
  // 1153
  142, 117, 
  // 1155
  143, 118, 
  // 1157
  144, 119, 
  // 1159
  79, 89, 
  // 1161
  140, 120, 
  // 1163
  141, 121, 
  // 1165
  142, 122, 
  // 1167
  143, 123, 
  // 1169
  144, 124, 
  // 1171
  79, 96, 
  // 1173
  140, 125, 
  // 1175
  141, 126, 
  // 1177
  142, 127, 
  // 1179
  143, 128, 
  // 1181
  144, 129, 
  // 1183
  24, 20, 
  // 1185
  98, 109, 
  // 1187
  99, 110, 
  // 1189
  100, 112, 
  // 1191
  101, 113, 
  // 1193
  79, 76, 
  // 1195
  140, 130, 
  // 1197
  141, 131, 
  // 1199
  142, 132, 
  // 1201
  143, 133, 
  // 1203
  102, 114, 
  // 1205
  144, 134, 
  // 1207
  79, 93, 
  // 1209
  140, 135, 
  // 1211
  141, 136, 
  // 1213
  142, 137, 
  // 1215
  143, 138, 
  // 1217
  144, 139, 
  // 1219
  79, 79, 
  // 1221
  140, 140, 
  // 1223
  141, 141, 
  // 1225
  142, 142, 
  // 1227
  143, 143, 
  // 1229
  144, 144, 
  // 1231
  79, 95, 
  // 1233
  140, 145, 
  // 1235
  141, 146, 
  // 1237
  142, 147, 
  // 1239
  143, 148, 
  // 1241
  144, 149, 
  // 1243
  95, 27, 
  // 1245
  145, 257, 
  // 1247
  146, 269, 
  // 1249
  147, 270, 
  // 1251
  148, 271, 
  // 1253
  149, 290, 
  // 1255
  24, 91, 
  // 1257
  98, 115, 
  // 1259
  99, 116, 
  // 1261
  100, 117, 
  // 1263
  101, 118, 
  // 1265
  95, 24, 
  // 1267
  145, 98, 
  // 1269
  146, 99, 
  // 1271
  147, 100, 
  // 1273
  148, 101, 
  // 1275
  102, 119, 
  // 1277
  149, 102, 
  // 1279
  95, 53, 
  // 1281
  145, 103, 
  // 1283
  146, 104, 
  // 1285
  147, 105, 
  // 1287
  148, 106, 
  // 1289
  149, 107, 
  // 1291
  95, 20, 
  // 1293
  145, 109, 
  // 1295
  146, 110, 
  // 1297
  147, 112, 
  // 1299
  148, 113, 
  // 1301
  149, 114, 
  // 1303
  95, 91, 
  // 1305
  145, 115, 
  // 1307
  146, 116, 
  // 1309
  147, 117, 
  // 1311
  148, 118, 
  // 1313
  149, 119, 
  // 1315
  95, 89, 
  // 1317
  145, 120, 
  // 1319
  146, 121, 
  // 1321
  147, 122, 
  // 1323
  148, 123, 
  // 1325
  149, 124, 
  // 1327
  24, 89, 
  // 1329
  98, 120, 
  // 1331
  99, 121, 
  // 1333
  100, 122, 
  // 1335
  101, 123, 
  // 1337
  95, 96, 
  // 1339
  145, 125, 
  // 1341
  146, 126, 
  // 1343
  147, 127, 
  // 1345
  148, 128, 
  // 1347
  102, 124, 
  // 1349
  149, 129, 
  // 1351
  95, 76, 
  // 1353
  145, 130, 
  // 1355
  146, 131, 
  // 1357
  147, 132, 
  // 1359
  148, 133, 
  // 1361
  149, 134, 
  // 1363
  95, 93, 
  // 1365
  145, 135, 
  // 1367
  146, 136, 
  // 1369
  147, 137, 
  // 1371
  148, 138, 
  // 1373
  149, 139, 
  // 1375
  95, 79, 
  // 1377
  145, 140, 
  // 1379
  146, 141, 
  // 1381
  147, 142, 
  // 1383
  148, 143, 
  // 1385
  149, 144, 
  // 1387
  95, 95, 
  // 1389
  145, 145, 
  // 1391
  146, 146, 
  // 1393
  147, 147, 
  // 1395
  148, 148, 
  // 1397
  149, 149, 
  // 1399
  24, 96, 
  // 1401
  98, 125, 
  // 1403
  99, 126, 
  // 1405
  100, 127, 
  // 1407
  101, 128, 
  // 1409
  93, 
  // 1410
  90, 93, 
  // 1412
  102, 129, 
  // 1414
  90, 
  // 1415
  26, 26, 
  // 1417
  34, 47, 
  // 1419
  31, 49, 
  // 1421
  37, 51, 
  // 1423
  26, 26, 26, 
  // 1426
  35, 35, 27, 
  // 1429
  32, 32, 24, 
  // 1432
  38, 38, 53, 
  // 1435
  39, 34, 
  // 1437
  39, 31, 
  // 1439
  39, 37, 
  // 1441
  34, 34, 39, 
  // 1444
  35, 35, 76, 
  // 1447
  31, 31, 39, 
  // 1450
  32, 32, 76, 
  // 1453
  37, 37, 39, 
  // 1456
  38, 38, 76, 
  // 1459
  26, 26, 26, 26, 
  // 1463
  26, 26, 150, 
  // 1466
  34, 34, 151, 
  // 1469
  34, 34, 34, 151, 
  // 1473
  31, 31, 151, 
  // 1476
  37, 37, 151, 
  // 1479
  31, 31, 31, 151, 
  // 1483
  37, 37, 37, 151, 
  // 1487
  26, 26, 152, 
  // 1490
  34, 34, 153, 
  // 1493
  31, 31, 153, 
  // 1496
  37, 37, 153, 
  // 1499
  34, 34, 34, 153, 
  // 1503
  31, 31, 31, 153, 
  // 1507
  37, 37, 37, 153, 
  // 1511
  26, 26, 154, 
  // 1514
  34, 34, 155, 
  // 1517
  31, 31, 155, 
  // 1520
  37, 37, 155, 
  // 1523
  34, 34, 34, 155, 
  // 1527
  31, 31, 31, 155, 
  // 1531
  37, 37, 37, 155, 
  // 1535
  26, 26, 156, 
  // 1538
  34, 34, 157, 
  // 1541
  31, 31, 157, 
  // 1544
  37, 37, 157, 
  // 1547
  34, 34, 34, 157, 
  // 1551
  31, 31, 31, 157, 
  // 1555
  37, 37, 37, 157, 
  // 1559
  34, 34, 
  // 1561
  34, 34, 34, 
  // 1564
  3, 5, 
  // 1566
  3, 5, 5, 
  // 1569
  5, 5, 5, 
  // 1572
  6, 6, 4, 
  // 1575
  43, 28, 45, 
  // 1578
  51, 45, 45, 
  // 1581
  39, 43, 51, 
  // 1584
  47, 51, 51, 
  // 1587
  41, 39, 47, 
  // 1590
  49, 47, 47, 
  // 1593
  5, 5, 5, 5, 
  // 1597
  6, 6, 4, 4, 
  // 1601
  39, 39, 39, 39, 
  // 1605
  47, 47, 47, 47, 
  // 1609
  39, 39, 39, 
  // 1612
  47, 47, 47, 
  // 1615
  35, 27, 35, 
  // 1618
  32, 24, 32, 
  // 1621
  38, 53, 38, 
  // 1624
  35, 35, 27, 27, 
  // 1628
  32, 32, 24, 24, 
  // 1632
  38, 38, 53, 53, 
  // 1636
  35, 35, 35, 27, 
  // 1640
  32, 32, 32, 24, 
  // 1644
  38, 38, 38, 53, 
  // 1648
  35, 27, 27, 35, 
  // 1652
  32, 24, 24, 32, 
  // 1656
  38, 53, 53, 38, 
  // 1660
  27, 33, 
  // 1662
  24, 30, 
  // 1664
  53, 36, 
  // 1666
  33, 33, 
  // 1668
  30, 30, 
  // 1670
  36, 36, 
  // 1672
  269, 269, 269, 
  // 1675
  99, 99, 99, 
  // 1678
  104, 104, 104, 
  // 1681
  270, 270, 270, 
  // 1684
  100, 100, 100, 
  // 1687
  105, 105, 105, 
  // 1690
  27, 33, 33, 
  // 1693
  24, 30, 30, 
  // 1696
  53, 36, 36, 
  // 1699
  24, 76, 
  // 1701
  42, 32, 
  // 1703
  44, 38, 
  // 1705
  98, 130, 
  // 1707
  99, 131, 
  // 1709
  76, 87, 
  // 1711
  39, 34, 34, 
  // 1714
  76, 24, 24, 
  // 1717
  42, 32, 32, 
  // 1720
  76, 53, 53, 
  // 1723
  100, 132, 
  // 1725
  44, 38, 38, 
  // 1728
  101, 133, 
  // 1730
  102, 134, 
  // 1732
  1, 1, 1, 1, 
  // 1736
  87, 87, 87, 87, 
  // 1740
  87, 87, 87, 92, 
  // 1744
  92, 92, 92, 92, 
  // 1748
  92, 92, 92, 87, 
  // 1752
  34, 34, 34, 39, 
  // 1756
  34, 34, 34, 47, 
  // 1760
  31, 31, 31, 41, 
  // 1764
  31, 31, 31, 49, 
  // 1768
  37, 37, 37, 43, 
  // 1772
  37, 37, 37, 51, 
  // 1776
  109, 90, 169, 
  // 1779
  115, 90, 170, 
  // 1782
  120, 90, 171, 
  // 1785
  125, 90, 172, 
  // 1788
  130, 90, 173, 
  // 1791
  135, 90, 174, 
  // 1794
  140, 90, 175, 
  // 1797
  145, 90, 176, 
  // 1800
  257, 90, 177, 
  // 1803
  98, 90, 178, 
  // 1806
  103, 90, 179, 
  // 1809
  97, 109, 90, 180, 
  // 1813
  97, 115, 90, 181, 
  // 1817
  97, 120, 90, 182, 
  // 1821
  97, 125, 90, 183, 
  // 1825
  97, 130, 90, 184, 
  // 1829
  97, 135, 90, 185, 
  // 1833
  97, 140, 90, 186, 
  // 1837
  97, 145, 90, 187, 
  // 1841
  97, 257, 90, 188, 
  // 1845
  97, 98, 90, 189, 
  // 1849
  97, 103, 90, 190, 
  // 1853
  110, 90, 169, 
  // 1856
  116, 90, 170, 
  // 1859
  121, 90, 171, 
  // 1862
  126, 90, 172, 
  // 1865
  131, 90, 173, 
  // 1868
  136, 90, 174, 
  // 1871
  141, 90, 175, 
  // 1874
  146, 90, 176, 
  // 1877
  269, 90, 177, 
  // 1880
  99, 90, 178, 
  // 1883
  104, 90, 179, 
  // 1886
  97, 110, 90, 180, 
  // 1890
  97, 116, 90, 181, 
  // 1894
  97, 121, 90, 182, 
  // 1898
  97, 126, 90, 183, 
  // 1902
  97, 131, 90, 184, 
  // 1906
  97, 136, 90, 185, 
  // 1910
  97, 141, 90, 186, 
  // 1914
  97, 146, 90, 187, 
  // 1918
  97, 269, 90, 188, 
  // 1922
  97, 99, 90, 189, 
  // 1926
  97, 104, 90, 190, 
  // 1930
  112, 90, 169, 
  // 1933
  117, 90, 170, 
  // 1936
  122, 90, 171, 
  // 1939
  127, 90, 172, 
  // 1942
  132, 90, 173, 
  // 1945
  137, 90, 174, 
  // 1948
  142, 90, 175, 
  // 1951
  147, 90, 176, 
  // 1954
  270, 90, 177, 
  // 1957
  100, 90, 178, 
  // 1960
  105, 90, 179, 
  // 1963
  97, 112, 90, 180, 
  // 1967
  97, 117, 90, 181, 
  // 1971
  97, 122, 90, 182, 
  // 1975
  97, 127, 90, 183, 
  // 1979
  97, 132, 90, 184, 
  // 1983
  97, 137, 90, 185, 
  // 1987
  97, 142, 90, 186, 
  // 1991
  97, 147, 90, 187, 
  // 1995
  97, 270, 90, 188, 
  // 1999
  97, 100, 90, 189, 
  // 2003
  97, 105, 90, 190, 
  // 2007
  113, 90, 169, 
  // 2010
  118, 90, 170, 
  // 2013
  123, 90, 171, 
  // 2016
  128, 90, 172, 
  // 2019
  133, 90, 173, 
  // 2022
  138, 90, 174, 
  // 2025
  143, 90, 175, 
  // 2028
  148, 90, 176, 
  // 2031
  271, 90, 177, 
  // 2034
  101, 90, 178, 
  // 2037
  106, 90, 179, 
  // 2040
  97, 113, 90, 180, 
  // 2044
  97, 118, 90, 181, 
  // 2048
  97, 123, 90, 182, 
  // 2052
  97, 128, 90, 183, 
  // 2056
  97, 133, 90, 184, 
  // 2060
  97, 138, 90, 185, 
  // 2064
  97, 143, 90, 186, 
  // 2068
  97, 148, 90, 187, 
  // 2072
  97, 271, 90, 188, 
  // 2076
  97, 101, 90, 189, 
  // 2080
  97, 106, 90, 190, 
  // 2084
  114, 90, 169, 
  // 2087
  119, 90, 170, 
  // 2090
  124, 90, 171, 
  // 2093
  129, 90, 172, 
  // 2096
  134, 90, 173, 
  // 2099
  139, 90, 174, 
  // 2102
  144, 90, 175, 
  // 2105
  149, 90, 176, 
  // 2108
  290, 90, 177, 
  // 2111
  102, 90, 178, 
  // 2114
  107, 90, 179, 
  // 2117
  97, 114, 90, 180, 
  // 2121
  97, 119, 90, 181, 
  // 2125
  97, 124, 90, 182, 
  // 2129
  97, 129, 90, 183, 
  // 2133
  97, 134, 90, 184, 
  // 2137
  97, 139, 90, 185, 
  // 2141
  97, 144, 90, 186, 
  // 2145
  97, 149, 90, 187, 
  // 2149
  97, 290, 90, 188, 
  // 2153
  97, 102, 90, 189, 
  // 2157
  97, 107, 90, 190, 
  // 2161
  109, 90, 191, 
  // 2164
  115, 90, 192, 
  // 2167
  120, 90, 193, 
  // 2170
  125, 90, 194, 
  // 2173
  130, 90, 195, 
  // 2176
  135, 90, 196, 
  // 2179
  140, 90, 197, 
  // 2182
  145, 90, 198, 
  // 2185
  257, 90, 199, 
  // 2188
  98, 90, 200, 
  // 2191
  103, 90, 201, 
  // 2194
  97, 109, 90, 202, 
  // 2198
  97, 115, 90, 203, 
  // 2202
  97, 120, 90, 204, 
  // 2206
  97, 125, 90, 205, 
  // 2210
  97, 130, 90, 206, 
  // 2214
  97, 135, 90, 207, 
  // 2218
  97, 140, 90, 208, 
  // 2222
  97, 145, 90, 209, 
  // 2226
  97, 257, 90, 210, 
  // 2230
  97, 98, 90, 211, 
  // 2234
  97, 103, 90, 212, 
  // 2238
  110, 90, 191, 
  // 2241
  116, 90, 192, 
  // 2244
  121, 90, 193, 
  // 2247
  126, 90, 194, 
  // 2250
  131, 90, 195, 
  // 2253
  136, 90, 196, 
  // 2256
  141, 90, 197, 
  // 2259
  146, 90, 198, 
  // 2262
  24, 93, 
  // 2264
  269, 90, 199, 
  // 2267
  99, 90, 200, 
  // 2270
  104, 90, 201, 
  // 2273
  97, 110, 90, 202, 
  // 2277
  97, 116, 90, 203, 
  // 2281
  97, 121, 90, 204, 
  // 2285
  97, 126, 90, 205, 
  // 2289
  97, 131, 90, 206, 
  // 2293
  97, 136, 90, 207, 
  // 2297
  97, 141, 90, 208, 
  // 2301
  98, 135, 
  // 2303
  97, 146, 90, 209, 
  // 2307
  97, 269, 90, 210, 
  // 2311
  97, 99, 90, 211, 
  // 2315
  97, 104, 90, 212, 
  // 2319
  112, 90, 191, 
  // 2322
  117, 90, 192, 
  // 2325
  122, 90, 193, 
  // 2328
  127, 90, 194, 
  // 2331
  132, 90, 195, 
  // 2334
  137, 90, 196, 
  // 2337
  99, 136, 
  // 2339
  142, 90, 197, 
  // 2342
  147, 90, 198, 
  // 2345
  270, 90, 199, 
  // 2348
  100, 90, 200, 
  // 2351
  105, 90, 201, 
  // 2354
  97, 112, 90, 202, 
  // 2358
  97, 117, 90, 203, 
  // 2362
  97, 122, 90, 204, 
  // 2366
  97, 127, 90, 205, 
  // 2370
  97, 132, 90, 206, 
  // 2374
  100, 137, 
  // 2376
  97, 137, 90, 207, 
  // 2380
  97, 142, 90, 208, 
  // 2384
  97, 147, 90, 209, 
  // 2388
  97, 270, 90, 210, 
  // 2392
  97, 100, 90, 211, 
  // 2396
  97, 105, 90, 212, 
  // 2400
  113, 90, 191, 
  // 2403
  118, 90, 192, 
  // 2406
  123, 90, 193, 
  // 2409
  128, 90, 194, 
  // 2412
  101, 138, 
  // 2414
  133, 90, 195, 
  // 2417
  138, 90, 196, 
  // 2420
  143, 90, 197, 
  // 2423
  148, 90, 198, 
  // 2426
  271, 90, 199, 
  // 2429
  101, 90, 200, 
  // 2432
  106, 90, 201, 
  // 2435
  97, 113, 90, 202, 
  // 2439
  97, 118, 90, 203, 
  // 2443
  97, 123, 90, 204, 
  // 2447
  27, 27, 
  // 2449
  102, 139, 
  // 2451
  97, 128, 90, 205, 
  // 2455
  97, 133, 90, 206, 
  // 2459
  97, 138, 90, 207, 
  // 2463
  97, 143, 90, 208, 
  // 2467
  97, 148, 90, 209, 
  // 2471
  97, 271, 90, 210, 
  // 2475
  97, 101, 90, 211, 
  // 2479
  97, 106, 90, 212, 
  // 2483
  114, 90, 191, 
  // 2486
  119, 90, 192, 
  // 2489
  124, 90, 193, 
  // 2492
  129, 90, 194, 
  // 2495
  134, 90, 195, 
  // 2498
  139, 90, 196, 
  // 2501
  144, 90, 197, 
  // 2504
  149, 90, 198, 
  // 2507
  290, 90, 199, 
  // 2510
  102, 90, 200, 
  // 2513
  107, 90, 201, 
  // 2516
  97, 114, 90, 202, 
  // 2520
  97, 119, 90, 203, 
  // 2524
  97, 124, 90, 204, 
  // 2528
  97, 129, 90, 205, 
  // 2532
  97, 134, 90, 206, 
  // 2536
  97, 139, 90, 207, 
  // 2540
  97, 144, 90, 208, 
  // 2544
  97, 149, 90, 209, 
  // 2548
  97, 290, 90, 210, 
  // 2552
  97, 102, 90, 211, 
  // 2556
  97, 107, 90, 212, 
  // 2560
  109, 90, 213, 
  // 2563
  115, 90, 214, 
  // 2566
  120, 90, 215, 
  // 2569
  125, 90, 216, 
  // 2572
  130, 90, 217, 
  // 2575
  135, 90, 218, 
  // 2578
  140, 90, 219, 
  // 2581
  145, 90, 220, 
  // 2584
  257, 90, 221, 
  // 2587
  98, 90, 222, 
  // 2590
  103, 90, 223, 
  // 2593
  97, 109, 90, 224, 
  // 2597
  97, 115, 90, 225, 
  // 2601
  97, 120, 90, 226, 
  // 2605
  97, 125, 90, 227, 
  // 2609
  97, 130, 90, 228, 
  // 2613
  97, 135, 90, 229, 
  // 2617
  97, 140, 90, 230, 
  // 2621
  97, 145, 90, 231, 
  // 2625
  97, 257, 90, 232, 
  // 2629
  97, 98, 90, 233, 
  // 2633
  97, 103, 90, 234, 
  // 2637
  110, 90, 213, 
  // 2640
  116, 90, 214, 
  // 2643
  121, 90, 215, 
  // 2646
  126, 90, 216, 
  // 2649
  131, 90, 217, 
  // 2652
  136, 90, 218, 
  // 2655
  141, 90, 219, 
  // 2658
  146, 90, 220, 
  // 2661
  269, 90, 221, 
  // 2664
  99, 90, 222, 
  // 2667
  104, 90, 223, 
  // 2670
  97, 110, 90, 224, 
  // 2674
  97, 116, 90, 225, 
  // 2678
  97, 121, 90, 226, 
  // 2682
  97, 126, 90, 227, 
  // 2686
  97, 131, 90, 228, 
  // 2690
  97, 136, 90, 229, 
  // 2694
  97, 141, 90, 230, 
  // 2698
  97, 146, 90, 231, 
  // 2702
  97, 269, 90, 232, 
  // 2706
  97, 99, 90, 233, 
  // 2710
  97, 104, 90, 234, 
  // 2714
  112, 90, 213, 
  // 2717
  117, 90, 214, 
  // 2720
  122, 90, 215, 
  // 2723
  127, 90, 216, 
  // 2726
  132, 90, 217, 
  // 2729
  137, 90, 218, 
  // 2732
  142, 90, 219, 
  // 2735
  147, 90, 220, 
  // 2738
  270, 90, 221, 
  // 2741
  100, 90, 222, 
  // 2744
  105, 90, 223, 
  // 2747
  97, 112, 90, 224, 
  // 2751
  97, 117, 90, 225, 
  // 2755
  97, 122, 90, 226, 
  // 2759
  97, 127, 90, 227, 
  // 2763
  97, 132, 90, 228, 
  // 2767
  97, 137, 90, 229, 
  // 2771
  97, 142, 90, 230, 
  // 2775
  97, 147, 90, 231, 
  // 2779
  97, 270, 90, 232, 
  // 2783
  97, 100, 90, 233, 
  // 2787
  97, 105, 90, 234, 
  // 2791
  113, 90, 213, 
  // 2794
  118, 90, 214, 
  // 2797
  123, 90, 215, 
  // 2800
  128, 90, 216, 
  // 2803
  133, 90, 217, 
  // 2806
  138, 90, 218, 
  // 2809
  143, 90, 219, 
  // 2812
  148, 90, 220, 
  // 2815
  271, 90, 221, 
  // 2818
  101, 90, 222, 
  // 2821
  106, 90, 223, 
  // 2824
  97, 113, 90, 224, 
  // 2828
  97, 118, 90, 225, 
  // 2832
  97, 123, 90, 226, 
  // 2836
  97, 128, 90, 227, 
  // 2840
  97, 133, 90, 228, 
  // 2844
  97, 138, 90, 229, 
  // 2848
  97, 143, 90, 230, 
  // 2852
  97, 148, 90, 231, 
  // 2856
  97, 271, 90, 232, 
  // 2860
  97, 101, 90, 233, 
  // 2864
  97, 106, 90, 234, 
  // 2868
  114, 90, 213, 
  // 2871
  119, 90, 214, 
  // 2874
  124, 90, 215, 
  // 2877
  129, 90, 216, 
  // 2880
  134, 90, 217, 
  // 2883
  139, 90, 218, 
  // 2886
  144, 90, 219, 
  // 2889
  149, 90, 220, 
  // 2892
  290, 90, 221, 
  // 2895
  102, 90, 222, 
  // 2898
  107, 90, 223, 
  // 2901
  97, 114, 90, 224, 
  // 2905
  97, 119, 90, 225, 
  // 2909
  97, 124, 90, 226, 
  // 2913
  97, 129, 90, 227, 
  // 2917
  97, 134, 90, 228, 
  // 2921
  97, 139, 90, 229, 
  // 2925
  97, 144, 90, 230, 
  // 2929
  97, 149, 90, 231, 
  // 2933
  97, 290, 90, 232, 
  // 2937
  97, 102, 90, 233, 
  // 2941
  97, 107, 90, 234, 
  // 2945
  109, 90, 235, 
  // 2948
  115, 90, 236, 
  // 2951
  120, 90, 237, 
  // 2954
  125, 90, 238, 
  // 2957
  130, 90, 239, 
  // 2960
  135, 90, 240, 
  // 2963
  140, 90, 241, 
  // 2966
  145, 90, 242, 
  // 2969
  257, 90, 243, 
  // 2972
  98, 90, 244, 
  // 2975
  103, 90, 245, 
  // 2978
  97, 109, 90, 246, 
  // 2982
  97, 115, 90, 247, 
  // 2986
  97, 120, 90, 248, 
  // 2990
  97, 125, 90, 249, 
  // 2994
  97, 130, 90, 250, 
  // 2998
  97, 135, 90, 251, 
  // 3002
  97, 140, 90, 252, 
  // 3006
  97, 145, 90, 253, 
  // 3010
  97, 257, 90, 254, 
  // 3014
  97, 98, 90, 255, 
  // 3018
  97, 103, 90, 256, 
  // 3022
  110, 90, 235, 
  // 3025
  116, 90, 236, 
  // 3028
  121, 90, 237, 
  // 3031
  126, 90, 238, 
  // 3034
  131, 90, 239, 
  // 3037
  136, 90, 240, 
  // 3040
  141, 90, 241, 
  // 3043
  146, 90, 242, 
  // 3046
  269, 90, 243, 
  // 3049
  99, 90, 244, 
  // 3052
  104, 90, 245, 
  // 3055
  97, 110, 90, 246, 
  // 3059
  97, 116, 90, 247, 
  // 3063
  97, 121, 90, 248, 
  // 3067
  97, 126, 90, 249, 
  // 3071
  97, 131, 90, 250, 
  // 3075
  97, 136, 90, 251, 
  // 3079
  97, 141, 90, 252, 
  // 3083
  97, 146, 90, 253, 
  // 3087
  97, 269, 90, 254, 
  // 3091
  97, 99, 90, 255, 
  // 3095
  97, 104, 90, 256, 
  // 3099
  112, 90, 235, 
  // 3102
  117, 90, 236, 
  // 3105
  122, 90, 237, 
  // 3108
  127, 90, 238, 
  // 3111
  132, 90, 239, 
  // 3114
  137, 90, 240, 
  // 3117
  142, 90, 241, 
  // 3120
  147, 90, 242, 
  // 3123
  270, 90, 243, 
  // 3126
  100, 90, 244, 
  // 3129
  105, 90, 245, 
  // 3132
  97, 112, 90, 246, 
  // 3136
  97, 117, 90, 247, 
  // 3140
  97, 122, 90, 248, 
  // 3144
  97, 127, 90, 249, 
  // 3148
  97, 132, 90, 250, 
  // 3152
  97, 137, 90, 251, 
  // 3156
  97, 142, 90, 252, 
  // 3160
  97, 147, 90, 253, 
  // 3164
  97, 270, 90, 254, 
  // 3168
  97, 100, 90, 255, 
  // 3172
  97, 105, 90, 256, 
  // 3176
  113, 90, 235, 
  // 3179
  118, 90, 236, 
  // 3182
  123, 90, 237, 
  // 3185
  128, 90, 238, 
  // 3188
  133, 90, 239, 
  // 3191
  138, 90, 240, 
  // 3194
  143, 90, 241, 
  // 3197
  148, 90, 242, 
  // 3200
  271, 90, 243, 
  // 3203
  101, 90, 244, 
  // 3206
  106, 90, 245, 
  // 3209
  97, 113, 90, 246, 
  // 3213
  97, 118, 90, 247, 
  // 3217
  97, 123, 90, 248, 
  // 3221
  97, 128, 90, 249, 
  // 3225
  97, 133, 90, 250, 
  // 3229
  97, 138, 90, 251, 
  // 3233
  97, 143, 90, 252, 
  // 3237
  97, 148, 90, 253, 
  // 3241
  97, 271, 90, 254, 
  // 3245
  97, 101, 90, 255, 
  // 3249
  24, 79, 
  // 3251
  97, 106, 90, 256, 
  // 3255
  114, 90, 235, 
  // 3258
  119, 90, 236, 
  // 3261
  124, 90, 237, 
  // 3264
  129, 90, 238, 
  // 3267
  134, 90, 239, 
  // 3270
  139, 90, 240, 
  // 3273
  144, 90, 241, 
  // 3276
  149, 90, 242, 
  // 3279
  290, 90, 243, 
  // 3282
  98, 140, 
  // 3284
  102, 90, 244, 
  // 3287
  107, 90, 245, 
  // 3290
  97, 114, 90, 246, 
  // 3294
  97, 119, 90, 247, 
  // 3298
  97, 124, 90, 248, 
  // 3302
  97, 129, 90, 249, 
  // 3306
  97, 134, 90, 250, 
  // 3310
  97, 139, 90, 251, 
  // 3314
  97, 144, 90, 252, 
  // 3318
  97, 149, 90, 253, 
  // 3322
  99, 141, 
  // 3324
  97, 290, 90, 254, 
  // 3328
  97, 102, 90, 255, 
  // 3332
  97, 107, 90, 256, 
  // 3336
  100, 142, 
  // 3338
  109, 90, 258, 
  // 3341
  115, 90, 259, 
  // 3344
  120, 90, 260, 
  // 3347
  125, 90, 261, 
  // 3350
  130, 90, 262, 
  // 3353
  101, 143, 
  // 3355
  135, 90, 263, 
  // 3358
  140, 90, 264, 
  // 3361
  145, 90, 265, 
  // 3364
  257, 90, 266, 
  // 3367
  98, 90, 267, 
  // 3370
  103, 90, 268, 
  // 3373
  110, 90, 258, 
  // 3376
  116, 90, 259, 
  // 3379
  121, 90, 260, 
  // 3382
  126, 90, 261, 
  // 3385
  102, 144, 
  // 3387
  131, 90, 262, 
  // 3390
  136, 90, 263, 
  // 3393
  141, 90, 264, 
  // 3396
  146, 90, 265, 
  // 3399
  269, 90, 266, 
  // 3402
  99, 90, 267, 
  // 3405
  104, 90, 268, 
  // 3408
  112, 90, 258, 
  // 3411
  117, 90, 259, 
  // 3414
  122, 90, 260, 
  // 3417
  127, 90, 261, 
  // 3420
  132, 90, 262, 
  // 3423
  137, 90, 263, 
  // 3426
  142, 90, 264, 
  // 3429
  147, 90, 265, 
  // 3432
  270, 90, 266, 
  // 3435
  100, 90, 267, 
  // 3438
  105, 90, 268, 
  // 3441
  113, 90, 258, 
  // 3444
  118, 90, 259, 
  // 3447
  123, 90, 260, 
  // 3450
  128, 90, 261, 
  // 3453
  133, 90, 262, 
  // 3456
  138, 90, 263, 
  // 3459
  143, 90, 264, 
  // 3462
  148, 90, 265, 
  // 3465
  271, 90, 266, 
  // 3468
  101, 90, 267, 
  // 3471
  106, 90, 268, 
  // 3474
  114, 90, 258, 
  // 3477
  119, 90, 259, 
  // 3480
  124, 90, 260, 
  // 3483
  129, 90, 261, 
  // 3486
  134, 90, 262, 
  // 3489
  139, 90, 263, 
  // 3492
  144, 90, 264, 
  // 3495
  149, 90, 265, 
  // 3498
  290, 90, 266, 
  // 3501
  102, 90, 267, 
  // 3504
  107, 90, 268, 
  // 3507
  27, 90, 56, 
  // 3510
  257, 90, 56, 
  // 3513
  97, 27, 90, 61, 
  // 3517
  97, 24, 90, 61, 
  // 3521
  97, 257, 90, 61, 
  // 3525
  97, 98, 90, 61, 
  // 3529
  269, 90, 56, 
  // 3532
  270, 90, 56, 
  // 3535
  271, 90, 56, 
  // 3538
  290, 90, 56, 
  // 3541
  97, 269, 90, 61, 
  // 3545
  97, 99, 90, 61, 
  // 3549
  97, 270, 90, 61, 
  // 3553
  97, 100, 90, 61, 
  // 3557
  97, 271, 90, 61, 
  // 3561
  97, 101, 90, 61, 
  // 3565
  97, 290, 90, 61, 
  // 3569
  97, 102, 90, 61, 
  // 3573
  27, 90, 57, 
  // 3576
  257, 90, 57, 
  // 3579
  269, 90, 57, 
  // 3582
  270, 90, 57, 
  // 3585
  271, 90, 57, 
  // 3588
  290, 90, 57, 
  // 3591
  97, 27, 90, 62, 
  // 3595
  97, 24, 90, 62, 
  // 3599
  97, 257, 90, 62, 
  // 3603
  97, 98, 90, 62, 
  // 3607
  97, 269, 90, 62, 
  // 3611
  97, 99, 90, 62, 
  // 3615
  97, 270, 90, 62, 
  // 3619
  97, 100, 90, 62, 
  // 3623
  97, 271, 90, 62, 
  // 3627
  97, 101, 90, 62, 
  // 3631
  97, 290, 90, 62, 
  // 3635
  97, 102, 90, 62, 
  // 3639
  24, 95, 
  // 3641
  98, 145, 
  // 3643
  99, 146, 
  // 3645
  100, 147, 
  // 3647
  27, 90, 58, 
  // 3650
  257, 90, 58, 
  // 3653
  269, 90, 58, 
  // 3656
  270, 90, 58, 
  // 3659
  101, 148, 
  // 3661
  271, 90, 58, 
  // 3664
  290, 90, 58, 
  // 3667
  97, 27, 90, 63, 
  // 3671
  97, 24, 90, 63, 
  // 3675
  97, 257, 90, 63, 
  // 3679
  97, 98, 90, 63, 
  // 3683
  102, 149, 
  // 3685
  97, 269, 90, 63, 
  // 3689
  97, 99, 90, 63, 
  // 3693
  97, 270, 90, 63, 
  // 3697
  97, 100, 90, 63, 
  // 3701
  97, 271, 90, 63, 
  // 3705
  97, 101, 90, 63, 
  // 3709
  97, 290, 90, 63, 
  // 3713
  97, 102, 90, 63, 
  // 3717
  27, 90, 55, 
  // 3720
  257, 90, 55, 
  // 3723
  269, 90, 55, 
  // 3726
  270, 90, 55, 
  // 3729
  271, 90, 55, 
  // 3732
  290, 90, 55, 
  // 3735
  97, 27, 90, 60, 
  // 3739
  97, 24, 90, 60, 
  // 3743
  97, 257, 90, 60, 
  // 3747
  97, 98, 90, 60, 
  // 3751
  97, 269, 90, 60, 
  // 3755
  97, 99, 90, 60, 
  // 3759
  97, 270, 90, 60, 
  // 3763
  97, 100, 90, 60, 
  // 3767
  97, 271, 90, 60, 
  // 3771
  97, 101, 90, 60, 
  // 3775
  97, 290, 90, 60, 
  // 3779
  97, 102, 90, 60, 
  // 3783
  27, 90, 54, 
  // 3786
  257, 90, 54, 
  // 3789
  269, 90, 54, 
  // 3792
  270, 90, 54, 
  // 3795
  271, 90, 54, 
  // 3798
  290, 90, 54, 
  // 3801
  97, 80, 
  // 3803
  97, 80, 82, 
  // 3806
  80, 272, 
  // 3808
  80, 274, 
  // 3810
  25, 275, 277, 90, 25, 
  // 3815
  53, 27, 
  // 3817
  25, 278, 279, 90, 25, 
  // 3822
  25, 275, 277, 90, 90, 25, 
  // 3828
  25, 278, 279, 90, 90, 25, 
  // 3834
  97, 76, 280, 
  // 3837
  103, 257, 
  // 3839
  97, 277, 90, 
  // 3842
  76, 282, 76, 
  // 3845
  76, 282, 
  // 3847
  76, 282, 76, 76, 
  // 3851
  104, 269, 
  // 3853
  93, 284, 93, 
  // 3856
  93, 284, 
  // 3858
  93, 284, 93, 93, 
  // 3862
  76, 285, 76, 
  // 3865
  76, 285, 
  // 3867
  76, 285, 76, 76, 
  // 3871
  105, 270, 
  // 3873
  93, 286, 93, 
  // 3876
  93, 286, 
  // 3878
  106, 271, 
  // 3880
  93, 286, 93, 93, 
  // 3884
  79, 288, 79, 
  // 3887
  79, 288, 
  // 3889
  79, 288, 79, 79, 
  // 3893
  107, 290, 
  // 3895
  95, 291, 95, 
  // 3898
  95, 291, 
  // 3900
  95, 291, 95, 95, 
  // 3904
  79, 292, 79, 
  // 3907
  79, 292, 
  // 3909
  79, 292, 79, 79, 
  // 3913
  95, 293, 95, 
  // 3916
  95, 293, 
  // 3918
  95, 293, 95, 95, 
  // 3922
  27, 295, 27, 
  // 3925
  27, 296, 27, 
  // 3928
  76, 297, 76, 
  // 3931
  76, 297, 
  // 3933
  76, 297, 76, 76, 
  // 3937
  93, 298, 93, 
  // 3940
  93, 298, 
  // 3942
  93, 298, 93, 93, 
  // 3946
  97, 307, 76, 
  // 3949
  97, 307, 76, 81, 
  // 3953
  97, 307, 76, 81, 82, 
  // 3958
  19, 307, 250, 76, 
  // 3962
  19, 307, 250, 76, 81, 81, 
  // 3968
  19, 307, 250, 76, 81, 81, 82, 
  // 3975
  97, 80, 81, 82, 
  // 3979
  76, 307, 
  // 3981
  76, 307, 81, 
  // 3984
  76, 307, 81, 82, 
  // 3988
  76, 307, 76, 
  // 3991
  76, 307, 76, 81, 
  // 3995
  76, 307, 76, 81, 82, 
  // 4000
  97, 308, 93, 
  // 4003
  97, 308, 93, 81, 
  // 4007
  97, 308, 93, 81, 82, 
  // 4012
  93, 308, 
  // 4014
  93, 308, 81, 
  // 4017
  93, 308, 81, 82, 
  // 4021
  93, 308, 93, 
  // 4024
  93, 308, 93, 81, 
  // 4028
  93, 308, 93, 81, 82, 
  // 4033
  19, 308, 251, 93, 
  // 4037
  19, 308, 251, 93, 81, 81, 
  // 4043
  19, 308, 251, 93, 81, 81, 82, 
  // 4050
  97, 309, 79, 
  // 4053
  97, 309, 79, 81, 
  // 4057
  97, 309, 79, 81, 82, 
  // 4062
  79, 309, 
  // 4064
  79, 309, 81, 
  // 4067
  79, 309, 81, 82, 
  // 4071
  79, 309, 79, 
  // 4074
  79, 309, 79, 81, 
  // 4078
  79, 309, 79, 81, 82, 
  // 4083
  19, 309, 252, 79, 
  // 4087
  19, 309, 252, 79, 81, 81, 
  // 4093
  19, 309, 252, 79, 81, 81, 82, 
  // 4100
  97, 310, 95, 
  // 4103
  97, 310, 95, 81, 
  // 4107
  97, 310, 95, 81, 82, 
  // 4112
  95, 310, 
  // 4114
  95, 310, 81, 
  // 4117
  95, 310, 81, 82, 
  // 4121
  95, 310, 95, 
  // 4124
  95, 310, 95, 81, 
  // 4128
  95, 310, 95, 81, 82, 
  // 4133
  19, 310, 253, 95, 
  // 4137
  19, 310, 253, 95, 81, 81, 
  // 4143
  19, 310, 253, 95, 81, 81, 82, 
  // 4150
  97, 311, 27, 
  // 4153
  97, 311, 27, 81, 
  // 4157
  97, 311, 27, 81, 82, 
  // 4162
  27, 311, 
  // 4164
  27, 311, 81, 
  // 4167
  27, 311, 81, 82, 
  // 4171
  27, 311, 27, 
  // 4174
  27, 311, 27, 81, 
  // 4178
  27, 311, 27, 81, 82, 
  // 4183
  19, 311, 254, 27, 
  // 4187
  19, 311, 254, 27, 81, 81, 
  // 4193
  19, 311, 254, 27, 81, 81, 82, 
  // 4200
  97, 312, 24, 
  // 4203
  97, 312, 24, 81, 
  // 4207
  97, 312, 24, 81, 82, 
  // 4212
  24, 312, 
  // 4214
  24, 312, 81, 
  // 4217
  24, 312, 81, 82, 
  // 4221
  53, 24, 
  // 4223
  24, 312, 24, 
  // 4226
  24, 312, 24, 81, 
  // 4230
  24, 312, 24, 81, 82, 
  // 4235
  19, 312, 255, 24, 
  // 4239
  19, 312, 255, 24, 81, 81, 
  // 4245
  19, 312, 255, 24, 81, 81, 82, 
  // 4252
  103, 98, 
  // 4254
  104, 99, 
  // 4256
  105, 100, 
  // 4258
  94, 313, 84, 
  // 4261
  94, 313, 84, 81, 
  // 4265
  94, 313, 84, 81, 82, 
  // 4270
  106, 101, 
  // 4272
  107, 102, 
  // 4274
  97, 314, 
  // 4276
  97, 314, 81, 
  // 4279
  97, 314, 81, 82, 
  // 4283
  19, 314, 
  // 4285
  19, 314, 81, 
  // 4288
  19, 314, 81, 82, 
  // 4292
  97, 315, 76, 
  // 4295
  97, 315, 76, 81, 
  // 4299
  97, 315, 76, 81, 82, 
  // 4304
  76, 315, 
  // 4306
  76, 315, 81, 
  // 4309
  76, 315, 81, 82, 
  // 4313
  76, 315, 76, 
  // 4316
  76, 315, 76, 81, 
  // 4320
  76, 315, 76, 81, 82, 
  // 4325
  19, 315, 184, 76, 
  // 4329
  19, 315, 184, 76, 81, 81, 
  // 4335
  19, 315, 184, 76, 81, 81, 82, 
  // 4342
  19, 315, 206, 76, 
  // 4346
  19, 315, 206, 76, 81, 81, 
  // 4352
  19, 315, 206, 76, 81, 81, 82, 
  // 4359
  19, 315, 228, 76, 
  // 4363
  19, 315, 228, 76, 81, 81, 
  // 4369
  19, 315, 228, 76, 81, 81, 82, 
  // 4376
  97, 316, 93, 
  // 4379
  97, 316, 93, 81, 
  // 4383
  97, 316, 93, 81, 82, 
  // 4388
  93, 316, 
  // 4390
  93, 316, 81, 
  // 4393
  93, 316, 81, 82, 
  // 4397
  93, 316, 93, 
  // 4400
  93, 316, 93, 81, 
  // 4404
  93, 316, 93, 81, 82, 
  // 4409
  19, 316, 185, 93, 
  // 4413
  19, 316, 185, 93, 81, 81, 
  // 4419
  19, 316, 185, 93, 81, 81, 82, 
  // 4426
  19, 316, 207, 93, 
  // 4430
  19, 316, 207, 93, 81, 81, 
  // 4436
  19, 316, 207, 93, 81, 81, 82, 
  // 4443
  19, 316, 229, 93, 
  // 4447
  19, 316, 229, 93, 81, 81, 
  // 4453
  19, 316, 229, 93, 81, 81, 82, 
  // 4460
  97, 317, 79, 
  // 4463
  97, 317, 79, 81, 
  // 4467
  97, 317, 79, 81, 82, 
  // 4472
  79, 317, 
  // 4474
  79, 317, 81, 
  // 4477
  79, 317, 81, 82, 
  // 4481
  79, 317, 79, 
  // 4484
  79, 317, 79, 81, 
  // 4488
  79, 317, 79, 81, 82, 
  // 4493
  19, 317, 186, 79, 
  // 4497
  19, 317, 186, 79, 81, 81, 
  // 4503
  19, 317, 186, 79, 81, 81, 82, 
  // 4510
  19, 317, 208, 79, 
  // 4514
  19, 317, 208, 79, 81, 81, 
  // 4520
  19, 317, 208, 79, 81, 81, 82, 
  // 4527
  19, 317, 230, 79, 
  // 4531
  19, 317, 230, 79, 81, 81, 
  // 4537
  19, 317, 230, 79, 81, 81, 82, 
  // 4544
  97, 318, 95, 
  // 4547
  97, 318, 95, 81, 
  // 4551
  97, 318, 95, 81, 82, 
  // 4556
  95, 318, 
  // 4558
  95, 318, 81, 
  // 4561
  95, 318, 81, 82, 
  // 4565
  95, 318, 95, 
  // 4568
  95, 318, 95, 81, 
  // 4572
  95, 318, 95, 81, 82, 
  // 4577
  19, 318, 187, 95, 
  // 4581
  19, 318, 187, 95, 81, 81, 
  // 4587
  19, 318, 187, 95, 81, 81, 82, 
  // 4594
  19, 318, 209, 95, 
  // 4598
  19, 318, 209, 95, 81, 81, 
  // 4604
  19, 318, 209, 95, 81, 81, 82, 
  // 4611
  19, 318, 231, 95, 
  // 4615
  19, 318, 231, 95, 81, 81, 
  // 4621
  19, 318, 231, 95, 81, 81, 82, 
  // 4628
  97, 319, 27, 
  // 4631
  97, 319, 27, 81, 
  // 4635
  97, 319, 27, 81, 82, 
  // 4640
  27, 319, 
  // 4642
  27, 319, 81, 
  // 4645
  27, 319, 81, 82, 
  // 4649
  27, 319, 27, 
  // 4652
  27, 319, 27, 81, 
  // 4656
  27, 319, 27, 81, 82, 
  // 4661
  19, 319, 188, 27, 
  // 4665
  19, 319, 188, 27, 81, 81, 
  // 4671
  19, 319, 188, 27, 81, 81, 82, 
  // 4678
  19, 319, 210, 27, 
  // 4682
  19, 319, 210, 27, 81, 81, 
  // 4688
  19, 319, 210, 27, 81, 81, 82, 
  // 4695
  19, 319, 232, 27, 
  // 4699
  19, 319, 232, 27, 81, 81, 
  // 4705
  19, 319, 232, 27, 81, 81, 82, 
  // 4712
  97, 320, 24, 
  // 4715
  97, 320, 24, 81, 
  // 4719
  97, 320, 24, 81, 82, 
  // 4724
  24, 320, 
  // 4726
  24, 320, 81, 
  // 4729
  24, 320, 81, 82, 
  // 4733
  24, 320, 24, 
  // 4736
  24, 320, 24, 81, 
  // 4740
  24, 320, 24, 81, 82, 
  // 4745
  19, 320, 189, 24, 
  // 4749
  19, 320, 189, 24, 81, 81, 
  // 4755
  19, 320, 189, 24, 81, 81, 82, 
  // 4762
  19, 320, 211, 24, 
  // 4766
  19, 320, 211, 24, 81, 81, 
  // 4772
  19, 320, 211, 24, 81, 81, 82, 
  // 4779
  19, 320, 233, 24, 
  // 4783
  19, 320, 233, 24, 81, 81, 
  // 4789
  19, 320, 233, 24, 81, 81, 82, 
  // 4796
  53, 53, 
  // 4798
  103, 103, 
  // 4800
  94, 321, 84, 
  // 4803
  94, 321, 84, 81, 
  // 4807
  94, 321, 84, 81, 82, 
  // 4812
  104, 104, 
  // 4814
  105, 105, 
  // 4816
  106, 106, 
  // 4818
  107, 107, 
  // 4820
  97, 322, 
  // 4822
  97, 322, 81, 
  // 4825
  97, 322, 81, 82, 
  // 4829
  19, 322, 
  // 4831
  19, 322, 81, 
  // 4834
  19, 322, 81, 82, 
  // 4838
  97, 323, 76, 
  // 4841
  97, 323, 76, 81, 
  // 4845
  97, 323, 76, 81, 82, 
  // 4850
  76, 323, 
  // 4852
  76, 323, 81, 
  // 4855
  76, 323, 81, 82, 
  // 4859
  76, 323, 76, 
  // 4862
  76, 323, 76, 81, 
  // 4866
  76, 323, 76, 81, 82, 
  // 4871
  19, 323, 184, 76, 
  // 4875
  19, 323, 184, 76, 81, 81, 
  // 4881
  19, 323, 184, 76, 81, 81, 82, 
  // 4888
  19, 323, 206, 76, 
  // 4892
  19, 323, 206, 76, 81, 81, 
  // 4898
  19, 323, 206, 76, 81, 81, 82, 
  // 4905
  19, 323, 228, 76, 
  // 4909
  19, 323, 228, 76, 81, 81, 
  // 4915
  19, 323, 228, 76, 81, 81, 82, 
  // 4922
  97, 324, 93, 
  // 4925
  97, 324, 93, 81, 
  // 4929
  97, 324, 93, 81, 82, 
  // 4934
  93, 324, 
  // 4936
  93, 324, 81, 
  // 4939
  93, 324, 81, 82, 
  // 4943
  93, 324, 93, 
  // 4946
  93, 324, 93, 81, 
  // 4950
  93, 324, 93, 81, 82, 
  // 4955
  19, 324, 185, 93, 
  // 4959
  19, 324, 185, 93, 81, 81, 
  // 4965
  19, 324, 185, 93, 81, 81, 82, 
  // 4972
  19, 324, 207, 93, 
  // 4976
  19, 324, 207, 93, 81, 81, 
  // 4982
  19, 324, 207, 93, 81, 81, 82, 
  // 4989
  19, 324, 229, 93, 
  // 4993
  19, 324, 229, 93, 81, 81, 
  // 4999
  19, 324, 229, 93, 81, 81, 82, 
  // 5006
  97, 325, 79, 
  // 5009
  97, 325, 79, 81, 
  // 5013
  97, 325, 79, 81, 82, 
  // 5018
  79, 325, 
  // 5020
  79, 325, 81, 
  // 5023
  79, 325, 81, 82, 
  // 5027
  79, 325, 79, 
  // 5030
  79, 325, 79, 81, 
  // 5034
  79, 325, 79, 81, 82, 
  // 5039
  19, 325, 186, 79, 
  // 5043
  19, 325, 186, 79, 81, 81, 
  // 5049
  19, 325, 186, 79, 81, 81, 82, 
  // 5056
  19, 325, 208, 79, 
  // 5060
  19, 325, 208, 79, 81, 81, 
  // 5066
  19, 325, 208, 79, 81, 81, 82, 
  // 5073
  19, 325, 230, 79, 
  // 5077
  19, 325, 230, 79, 81, 81, 
  // 5083
  19, 325, 230, 79, 81, 81, 82, 
  // 5090
  97, 326, 95, 
  // 5093
  97, 326, 95, 81, 
  // 5097
  97, 326, 95, 81, 82, 
  // 5102
  95, 326, 
  // 5104
  95, 326, 81, 
  // 5107
  95, 326, 81, 82, 
  // 5111
  95, 326, 95, 
  // 5114
  95, 326, 95, 81, 
  // 5118
  95, 326, 95, 81, 82, 
  // 5123
  19, 326, 187, 95, 
  // 5127
  19, 326, 187, 95, 81, 81, 
  // 5133
  19, 326, 187, 95, 81, 81, 82, 
  // 5140
  19, 326, 209, 95, 
  // 5144
  19, 326, 209, 95, 81, 81, 
  // 5150
  19, 326, 209, 95, 81, 81, 82, 
  // 5157
  19, 326, 231, 95, 
  // 5161
  19, 326, 231, 95, 81, 81, 
  // 5167
  19, 326, 231, 95, 81, 81, 82, 
  // 5174
  97, 327, 27, 
  // 5177
  97, 327, 27, 81, 
  // 5181
  97, 327, 27, 81, 82, 
  // 5186
  27, 327, 
  // 5188
  27, 327, 81, 
  // 5191
  27, 327, 81, 82, 
  // 5195
  27, 327, 27, 
  // 5198
  27, 327, 27, 81, 
  // 5202
  27, 327, 27, 81, 82, 
  // 5207
  19, 327, 188, 27, 
  // 5211
  19, 327, 188, 27, 81, 81, 
  // 5217
  19, 327, 188, 27, 81, 81, 82, 
  // 5224
  19, 327, 210, 27, 
  // 5228
  19, 327, 210, 27, 81, 81, 
  // 5234
  19, 327, 210, 27, 81, 81, 82, 
  // 5241
  19, 327, 232, 27, 
  // 5245
  19, 327, 232, 27, 81, 81, 
  // 5251
  19, 327, 232, 27, 81, 81, 82, 
  // 5258
  97, 328, 24, 
  // 5261
  97, 328, 24, 81, 
  // 5265
  97, 328, 24, 81, 82, 
  // 5270
  24, 328, 
  // 5272
  24, 328, 81, 
  // 5275
  24, 328, 81, 82, 
  // 5279
  24, 328, 24, 
  // 5282
  24, 328, 24, 81, 
  // 5286
  24, 328, 24, 81, 82, 
  // 5291
  19, 328, 189, 24, 
  // 5295
  19, 328, 189, 24, 81, 81, 
  // 5301
  19, 328, 189, 24, 81, 81, 82, 
  // 5308
  19, 328, 211, 24, 
  // 5312
  19, 328, 211, 24, 81, 81, 
  // 5318
  19, 328, 211, 24, 81, 81, 82, 
  // 5325
  19, 328, 233, 24, 
  // 5329
  19, 328, 233, 24, 81, 81, 
  // 5335
  19, 328, 233, 24, 81, 81, 82, 
  // 5342
  94, 329, 84, 
  // 5345
  94, 329, 84, 81, 
  // 5349
  94, 329, 84, 81, 82, 
  // 5354
  53, 20, 
  // 5356
  103, 109, 
  // 5358
  104, 110, 
  // 5360
  105, 112, 
  // 5362
  106, 113, 
  // 5364
  97, 330, 
  // 5366
  107, 114, 
  // 5368
  97, 330, 81, 
  // 5371
  97, 330, 81, 82, 
  // 5375
  19, 330, 
  // 5377
  19, 330, 81, 
  // 5380
  19, 330, 81, 82, 
  // 5384
  97, 332, 10, 
  // 5387
  97, 332, 10, 81, 
  // 5391
  97, 332, 10, 81, 82, 
  // 5396
  53, 332, 
  // 5398
  53, 332, 81, 
  // 5401
  53, 332, 81, 82, 
  // 5405
  53, 332, 53, 
  // 5408
  53, 332, 53, 81, 
  // 5412
  53, 332, 53, 81, 82, 
  // 5417
  97, 333, 10, 
  // 5420
  97, 333, 10, 81, 
  // 5424
  97, 333, 10, 81, 82, 
  // 5429
  53, 333, 
  // 5431
  53, 333, 81, 
  // 5434
  53, 333, 81, 82, 
  // 5438
  53, 333, 53, 
  // 5441
  53, 333, 53, 81, 
  // 5445
  53, 333, 53, 81, 82, 
  // 5450
  97, 334, 10, 
  // 5453
  97, 334, 10, 81, 
  // 5457
  97, 334, 10, 81, 82, 
  // 5462
  53, 334, 
  // 5464
  53, 334, 81, 
  // 5467
  53, 334, 81, 82, 
  // 5471
  53, 334, 53, 
  // 5474
  53, 334, 53, 81, 
  // 5478
  53, 334, 53, 81, 82, 
  // 5483
  109, 109, 115, 
  // 5486
  115, 115, 115, 
  // 5489
  120, 120, 125, 
  // 5492
  125, 125, 125, 
  // 5495
  130, 130, 135, 
  // 5498
  135, 135, 135, 
  // 5501
  140, 140, 145, 
  // 5504
  145, 145, 145, 
  // 5507
  257, 257, 135, 
  // 5510
  98, 98, 145, 
  // 5513
  103, 103, 125, 
  // 5516
  109, 112, 115, 
  // 5519
  115, 117, 115, 
  // 5522
  53, 91, 
  // 5524
  120, 122, 125, 
  // 5527
  125, 127, 125, 
  // 5530
  130, 132, 135, 
  // 5533
  135, 137, 135, 
  // 5536
  140, 142, 145, 
  // 5539
  145, 147, 145, 
  // 5542
  257, 270, 135, 
  // 5545
  98, 100, 145, 
  // 5548
  103, 105, 125, 
  // 5551
  109, 113, 115, 
  // 5554
  103, 115, 
  // 5556
  115, 118, 115, 
  // 5559
  120, 123, 125, 
  // 5562
  125, 128, 125, 
  // 5565
  130, 133, 135, 
  // 5568
  135, 138, 135, 
  // 5571
  140, 143, 145, 
  // 5574
  145, 148, 145, 
  // 5577
  257, 271, 135, 
  // 5580
  98, 101, 145, 
  // 5583
  103, 106, 125, 
  // 5586
  104, 116, 
  // 5588
  109, 114, 115, 
  // 5591
  115, 119, 115, 
  // 5594
  120, 124, 125, 
  // 5597
  125, 129, 125, 
  // 5600
  130, 134, 135, 
  // 5603
  135, 139, 135, 
  // 5606
  140, 144, 145, 
  // 5609
  145, 149, 145, 
  // 5612
  257, 290, 135, 
  // 5615
  98, 102, 145, 
  // 5618
  105, 117, 
  // 5620
  103, 107, 125, 
  // 5623
  112, 109, 117, 
  // 5626
  117, 115, 117, 
  // 5629
  122, 120, 127, 
  // 5632
  127, 125, 127, 
  // 5635
  132, 130, 137, 
  // 5638
  137, 135, 137, 
  // 5641
  142, 140, 147, 
  // 5644
  147, 145, 147, 
  // 5647
  270, 257, 137, 
  // 5650
  106, 118, 
  // 5652
  100, 98, 147, 
  // 5655
  105, 103, 127, 
  // 5658
  112, 112, 117, 
  // 5661
  117, 117, 117, 
  // 5664
  122, 122, 127, 
  // 5667
  127, 127, 127, 
  // 5670
  132, 132, 137, 
  // 5673
  137, 137, 137, 
  // 5676
  142, 142, 147, 
  // 5679
  147, 147, 147, 
  // 5682
  107, 119, 
  // 5684
  270, 270, 137, 
  // 5687
  100, 100, 147, 
  // 5690
  105, 105, 127, 
  // 5693
  112, 113, 117, 
  // 5696
  117, 118, 117, 
  // 5699
  122, 123, 127, 
  // 5702
  127, 128, 127, 
  // 5705
  132, 133, 137, 
  // 5708
  137, 138, 137, 
  // 5711
  142, 143, 147, 
  // 5714
  147, 148, 147, 
  // 5717
  270, 271, 137, 
  // 5720
  100, 101, 147, 
  // 5723
  105, 106, 127, 
  // 5726
  112, 114, 117, 
  // 5729
  117, 119, 117, 
  // 5732
  122, 124, 127, 
  // 5735
  127, 129, 127, 
  // 5738
  132, 134, 137, 
  // 5741
  137, 139, 137, 
  // 5744
  142, 144, 147, 
  // 5747
  147, 149, 147, 
  // 5750
  270, 290, 137, 
  // 5753
  100, 102, 147, 
  // 5756
  105, 107, 127, 
  // 5759
  113, 109, 118, 
  // 5762
  118, 115, 118, 
  // 5765
  123, 120, 128, 
  // 5768
  128, 125, 128, 
  // 5771
  133, 130, 138, 
  // 5774
  138, 135, 138, 
  // 5777
  143, 140, 148, 
  // 5780
  148, 145, 148, 
  // 5783
  271, 257, 138, 
  // 5786
  101, 98, 148, 
  // 5789
  106, 103, 128, 
  // 5792
  113, 112, 118, 
  // 5795
  118, 117, 118, 
  // 5798
  123, 122, 128, 
  // 5801
  128, 127, 128, 
  // 5804
  133, 132, 138, 
  // 5807
  138, 137, 138, 
  // 5810
  143, 142, 148, 
  // 5813
  148, 147, 148, 
  // 5816
  271, 270, 138, 
  // 5819
  101, 100, 148, 
  // 5822
  106, 105, 128, 
  // 5825
  113, 113, 118, 
  // 5828
  118, 118, 118, 
  // 5831
  123, 123, 128, 
  // 5834
  128, 128, 128, 
  // 5837
  133, 133, 138, 
  // 5840
  138, 138, 138, 
  // 5843
  143, 143, 148, 
  // 5846
  148, 148, 148, 
  // 5849
  271, 271, 138, 
  // 5852
  101, 101, 148, 
  // 5855
  106, 106, 128, 
  // 5858
  113, 114, 118, 
  // 5861
  118, 119, 118, 
  // 5864
  123, 124, 128, 
  // 5867
  128, 129, 128, 
  // 5870
  133, 134, 138, 
  // 5873
  138, 139, 138, 
  // 5876
  143, 144, 148, 
  // 5879
  148, 149, 148, 
  // 5882
  271, 290, 138, 
  // 5885
  101, 102, 148, 
  // 5888
  106, 107, 128, 
  // 5891
  114, 109, 119, 
  // 5894
  119, 115, 119, 
  // 5897
  124, 120, 129, 
  // 5900
  129, 125, 129, 
  // 5903
  134, 130, 139, 
  // 5906
  139, 135, 139, 
  // 5909
  144, 140, 149, 
  // 5912
  149, 145, 149, 
  // 5915
  290, 257, 139, 
  // 5918
  102, 98, 149, 
  // 5921
  107, 103, 129, 
  // 5924
  114, 112, 119, 
  // 5927
  119, 117, 119, 
  // 5930
  124, 122, 129, 
  // 5933
  129, 127, 129, 
  // 5936
  134, 132, 139, 
  // 5939
  139, 137, 139, 
  // 5942
  144, 142, 149, 
  // 5945
  149, 147, 149, 
  // 5948
  290, 270, 139, 
  // 5951
  102, 100, 149, 
  // 5954
  107, 105, 129, 
  // 5957
  114, 113, 119, 
  // 5960
  119, 118, 119, 
  // 5963
  124, 123, 129, 
  // 5966
  129, 128, 129, 
  // 5969
  134, 133, 139, 
  // 5972
  139, 138, 139, 
  // 5975
  144, 143, 149, 
  // 5978
  149, 148, 149, 
  // 5981
  290, 271, 139, 
  // 5984
  102, 101, 149, 
  // 5987
  107, 106, 129, 
  // 5990
  114, 114, 119, 
  // 5993
  119, 119, 119, 
  // 5996
  124, 124, 129, 
  // 5999
  129, 129, 129, 
  // 6002
  134, 134, 139, 
  // 6005
  139, 139, 139, 
  // 6008
  144, 144, 149, 
  // 6011
  149, 149, 149, 
  // 6014
  290, 290, 139, 
  // 6017
  102, 102, 149, 
  // 6020
  107, 107, 129, 
  // 6023
  109, 109, 109, 115, 
  // 6027
  115, 115, 115, 115, 
  // 6031
  120, 120, 120, 125, 
  // 6035
  125, 125, 125, 125, 
  // 6039
  130, 130, 130, 135, 
  // 6043
  135, 135, 135, 135, 
  // 6047
  140, 140, 140, 145, 
  // 6051
  145, 145, 145, 145, 
  // 6055
  257, 257, 257, 135, 
  // 6059
  98, 98, 98, 145, 
  // 6063
  103, 103, 103, 125, 
  // 6067
  109, 112, 112, 115, 
  // 6071
  115, 117, 117, 115, 
  // 6075
  120, 122, 122, 125, 
  // 6079
  125, 127, 127, 125, 
  // 6083
  130, 132, 132, 135, 
  // 6087
  135, 137, 137, 135, 
  // 6091
  140, 142, 142, 145, 
  // 6095
  145, 147, 147, 145, 
  // 6099
  257, 270, 270, 135, 
  // 6103
  98, 100, 100, 145, 
  // 6107
  103, 105, 105, 125, 
  // 6111
  109, 113, 113, 115, 
  // 6115
  115, 118, 118, 115, 
  // 6119
  120, 123, 123, 125, 
  // 6123
  125, 128, 128, 125, 
  // 6127
  130, 133, 133, 135, 
  // 6131
  135, 138, 138, 135, 
  // 6135
  140, 143, 143, 145, 
  // 6139
  145, 148, 148, 145, 
  // 6143
  257, 271, 271, 135, 
  // 6147
  98, 101, 101, 145, 
  // 6151
  103, 106, 106, 125, 
  // 6155
  109, 114, 114, 115, 
  // 6159
  115, 119, 119, 115, 
  // 6163
  120, 124, 124, 125, 
  // 6167
  125, 129, 129, 125, 
  // 6171
  130, 134, 134, 135, 
  // 6175
  135, 139, 139, 135, 
  // 6179
  140, 144, 144, 145, 
  // 6183
  145, 149, 149, 145, 
  // 6187
  257, 290, 290, 135, 
  // 6191
  98, 102, 102, 145, 
  // 6195
  103, 107, 107, 125, 
  // 6199
  112, 109, 109, 117, 
  // 6203
  117, 115, 115, 117, 
  // 6207
  122, 120, 120, 127, 
  // 6211
  127, 125, 125, 127, 
  // 6215
  132, 130, 130, 137, 
  // 6219
  137, 135, 135, 137, 
  // 6223
  142, 140, 140, 147, 
  // 6227
  147, 145, 145, 147, 
  // 6231
  270, 257, 257, 137, 
  // 6235
  100, 98, 98, 147, 
  // 6239
  105, 103, 103, 127, 
  // 6243
  112, 112, 112, 117, 
  // 6247
  117, 117, 117, 117, 
  // 6251
  122, 122, 122, 127, 
  // 6255
  127, 127, 127, 127, 
  // 6259
  132, 132, 132, 137, 
  // 6263
  137, 137, 137, 137, 
  // 6267
  142, 142, 142, 147, 
  // 6271
  147, 147, 147, 147, 
  // 6275
  270, 270, 270, 137, 
  // 6279
  100, 100, 100, 147, 
  // 6283
  105, 105, 105, 127, 
  // 6287
  112, 113, 113, 117, 
  // 6291
  117, 118, 118, 117, 
  // 6295
  122, 123, 123, 127, 
  // 6299
  127, 128, 128, 127, 
  // 6303
  132, 133, 133, 137, 
  // 6307
  137, 138, 138, 137, 
  // 6311
  142, 143, 143, 147, 
  // 6315
  147, 148, 148, 147, 
  // 6319
  270, 271, 271, 137, 
  // 6323
  100, 101, 101, 147, 
  // 6327
  105, 106, 106, 127, 
  // 6331
  112, 114, 114, 117, 
  // 6335
  117, 119, 119, 117, 
  // 6339
  122, 124, 124, 127, 
  // 6343
  127, 129, 129, 127, 
  // 6347
  132, 134, 134, 137, 
  // 6351
  137, 139, 139, 137, 
  // 6355
  142, 144, 144, 147, 
  // 6359
  147, 149, 149, 147, 
  // 6363
  270, 290, 290, 137, 
  // 6367
  100, 102, 102, 147, 
  // 6371
  105, 107, 107, 127, 
  // 6375
  113, 109, 109, 118, 
  // 6379
  118, 115, 115, 118, 
  // 6383
  123, 120, 120, 128, 
  // 6387
  128, 125, 125, 128, 
  // 6391
  133, 130, 130, 138, 
  // 6395
  138, 135, 135, 138, 
  // 6399
  143, 140, 140, 148, 
  // 6403
  148, 145, 145, 148, 
  // 6407
  271, 257, 257, 138, 
  // 6411
  101, 98, 98, 148, 
  // 6415
  106, 103, 103, 128, 
  // 6419
  113, 112, 112, 118, 
  // 6423
  118, 117, 117, 118, 
  // 6427
  123, 122, 122, 128, 
  // 6431
  128, 127, 127, 128, 
  // 6435
  133, 132, 132, 138, 
  // 6439
  138, 137, 137, 138, 
  // 6443
  143, 142, 142, 148, 
  // 6447
  148, 147, 147, 148, 
  // 6451
  271, 270, 270, 138, 
  // 6455
  101, 100, 100, 148, 
  // 6459
  106, 105, 105, 128, 
  // 6463
  113, 113, 113, 118, 
  // 6467
  118, 118, 118, 118, 
  // 6471
  123, 123, 123, 128, 
  // 6475
  128, 128, 128, 128, 
  // 6479
  133, 133, 133, 138, 
  // 6483
  138, 138, 138, 138, 
  // 6487
  143, 143, 143, 148, 
  // 6491
  148, 148, 148, 148, 
  // 6495
  271, 271, 271, 138, 
  // 6499
  101, 101, 101, 148, 
  // 6503
  106, 106, 106, 128, 
  // 6507
  113, 114, 114, 118, 
  // 6511
  118, 119, 119, 118, 
  // 6515
  123, 124, 124, 128, 
  // 6519
  128, 129, 129, 128, 
  // 6523
  133, 134, 134, 138, 
  // 6527
  138, 139, 139, 138, 
  // 6531
  143, 144, 144, 148, 
  // 6535
  148, 149, 149, 148, 
  // 6539
  271, 290, 290, 138, 
  // 6543
  101, 102, 102, 148, 
  // 6547
  106, 107, 107, 128, 
  // 6551
  114, 109, 109, 119, 
  // 6555
  119, 115, 115, 119, 
  // 6559
  124, 120, 120, 129, 
  // 6563
  129, 125, 125, 129, 
  // 6567
  134, 130, 130, 139, 
  // 6571
  53, 89, 
  // 6573
  139, 135, 135, 139, 
  // 6577
  144, 140, 140, 149, 
  // 6581
  149, 145, 145, 149, 
  // 6585
  290, 257, 257, 139, 
  // 6589
  102, 98, 98, 149, 
  // 6593
  107, 103, 103, 129, 
  // 6597
  114, 112, 112, 119, 
  // 6601
  119, 117, 117, 119, 
  // 6605
  124, 122, 122, 129, 
  // 6609
  129, 127, 127, 129, 
  // 6613
  103, 120, 
  // 6615
  134, 132, 132, 139, 
  // 6619
  139, 137, 137, 139, 
  // 6623
  144, 142, 142, 149, 
  // 6627
  149, 147, 147, 149, 
  // 6631
  290, 270, 270, 139, 
  // 6635
  102, 100, 100, 149, 
  // 6639
  107, 105, 105, 129, 
  // 6643
  114, 113, 113, 119, 
  // 6647
  119, 118, 118, 119, 
  // 6651
  124, 123, 123, 129, 
  // 6655
  104, 121, 
  // 6657
  129, 128, 128, 129, 
  // 6661
  134, 133, 133, 139, 
  // 6665
  139, 138, 138, 139, 
  // 6669
  144, 143, 143, 149, 
  // 6673
  149, 148, 148, 149, 
  // 6677
  290, 271, 271, 139, 
  // 6681
  102, 101, 101, 149, 
  // 6685
  107, 106, 106, 129, 
  // 6689
  114, 114, 114, 119, 
  // 6693
  119, 119, 119, 119, 
  // 6697
  105, 122, 
  // 6699
  124, 124, 124, 129, 
  // 6703
  129, 129, 129, 129, 
  // 6707
  134, 134, 134, 139, 
  // 6711
  139, 139, 139, 139, 
  // 6715
  144, 144, 144, 149, 
  // 6719
  149, 149, 149, 149, 
  // 6723
  290, 290, 290, 139, 
  // 6727
  102, 102, 102, 149, 
  // 6731
  107, 107, 107, 129, 
  // 6735
  270, 335, 88, 76, 
  // 6739
  106, 123, 
  // 6741
  132, 335, 88, 76, 
  // 6745
  137, 335, 88, 76, 
  // 6749
  270, 335, 88, 27, 
  // 6753
  132, 335, 88, 27, 
  // 6757
  137, 335, 88, 27, 
  // 6761
  270, 336, 88, 130, 
  // 6765
  132, 336, 88, 130, 
  // 6769
  137, 336, 88, 130, 
  // 6773
  107, 124, 
  // 6775
  270, 336, 88, 257, 
  // 6779
  132, 336, 88, 257, 
  // 6783
  137, 336, 88, 257, 
  // 6787
  270, 337, 88, 130, 
  // 6791
  132, 337, 88, 130, 
  // 6795
  137, 337, 88, 130, 
  // 6799
  270, 337, 88, 257, 
  // 6803
  132, 337, 88, 257, 
  // 6807
  137, 337, 88, 257, 
  // 6811
  270, 338, 88, 132, 
  // 6815
  132, 338, 88, 132, 
  // 6819
  137, 338, 88, 132, 
  // 6823
  270, 338, 88, 270, 
  // 6827
  132, 338, 88, 270, 
  // 6831
  137, 338, 88, 270, 
  // 6835
  270, 339, 88, 132, 
  // 6839
  132, 339, 88, 132, 
  // 6843
  137, 339, 88, 132, 
  // 6847
  270, 339, 88, 270, 
  // 6851
  132, 339, 88, 270, 
  // 6855
  137, 339, 88, 270, 
  // 6859
  27, 340, 88, 130, 
  // 6863
  27, 341, 88, 132, 
  // 6867
  27, 340, 88, 257, 
  // 6871
  27, 341, 88, 270, 
  // 6875
  270, 336, 130, 
  // 6878
  132, 336, 130, 
  // 6881
  137, 336, 130, 
  // 6884
  270, 338, 132, 
  // 6887
  132, 338, 132, 
  // 6890
  137, 338, 132, 
  // 6893
  270, 335, 76, 
  // 6896
  132, 335, 76, 
  // 6899
  137, 335, 76, 
  // 6902
  27, 340, 130, 
  // 6905
  27, 341, 132, 
  // 6908
  270, 337, 130, 
  // 6911
  132, 337, 130, 
  // 6914
  137, 337, 130, 
  // 6917
  270, 339, 132, 
  // 6920
  132, 339, 132, 
  // 6923
  137, 339, 132, 
  // 6926
  270, 342, 76, 
  // 6929
  132, 342, 76, 
  // 6932
  137, 342, 76, 
  // 6935
  270, 343, 130, 
  // 6938
  132, 343, 130, 
  // 6941
  137, 343, 130, 
  // 6944
  270, 344, 130, 
  // 6947
  132, 344, 130, 
  // 6950
  137, 344, 130, 
  // 6953
  270, 345, 132, 
  // 6956
  132, 345, 132, 
  // 6959
  137, 345, 132, 
  // 6962
  270, 346, 132, 
  // 6965
  132, 346, 132, 
  // 6968
  137, 346, 132, 
  // 6971
  270, 347, 76, 
  // 6974
  132, 347, 76, 
  // 6977
  137, 347, 76, 
  // 6980
  270, 348, 76, 
  // 6983
  132, 348, 76, 
  // 6986
  137, 348, 76, 
  // 6989
  27, 349, 130, 
  // 6992
  27, 350, 132, 
  // 6995
  97, 351, 130, 270, 
  // 6999
  97, 351, 130, 132, 
  // 7003
  97, 351, 130, 137, 
  // 7007
  97, 352, 132, 270, 
  // 7011
  97, 352, 132, 132, 
  // 7015
  97, 352, 132, 137, 
  // 7019
  97, 353, 76, 270, 
  // 7023
  97, 353, 76, 132, 
  // 7027
  97, 353, 76, 137, 
  // 7031
  97, 355, 130, 270, 
  // 7035
  97, 355, 130, 132, 
  // 7039
  97, 355, 130, 137, 
  // 7043
  97, 356, 132, 270, 
  // 7047
  97, 356, 132, 132, 
  // 7051
  97, 356, 132, 137, 
  // 7055
  97, 357, 130, 27, 
  // 7059
  97, 358, 132, 27, 
  // 7063
  97, 354, 76, 270, 
  // 7067
  97, 354, 76, 132, 
  // 7071
  97, 354, 76, 137, 
  // 7075
  97, 343, 130, 270, 
  // 7079
  97, 343, 130, 132, 
  // 7083
  97, 343, 130, 137, 
  // 7087
  97, 346, 132, 270, 
  // 7091
  97, 346, 132, 132, 
  // 7095
  97, 346, 132, 137, 
  // 7099
  97, 347, 76, 270, 
  // 7103
  97, 347, 76, 132, 
  // 7107
  97, 347, 76, 137, 
  // 7111
  97, 348, 76, 270, 
  // 7115
  97, 348, 76, 132, 
  // 7119
  97, 348, 76, 137, 
  // 7123
  97, 344, 130, 270, 
  // 7127
  97, 344, 130, 132, 
  // 7131
  97, 344, 130, 137, 
  // 7135
  97, 345, 132, 270, 
  // 7139
  97, 345, 132, 132, 
  // 7143
  97, 345, 132, 137, 
  // 7147
  97, 349, 130, 27, 
  // 7151
  97, 350, 132, 27, 
  // 7155
  76, 335, 
  // 7157
  76, 336, 
  // 7159
  76, 338, 
  // 7161
  130, 336, 
  // 7163
  132, 338, 
  // 7165
  90, 337, 
  // 7167
  76, 342, 
  // 7169
  76, 337, 
  // 7171
  76, 339, 
  // 7173
  76, 340, 
  // 7175
  76, 341, 
  // 7177
  130, 339, 
  // 7179
  130, 340, 
  // 7181
  130, 341, 
  // 7183
  90, 339, 
  // 7185
  90, 341, 
  // 7187
  76, 353, 
  // 7189
  76, 354, 
  // 7191
  76, 351, 
  // 7193
  76, 356, 
  // 7195
  76, 355, 
  // 7197
  76, 352, 
  // 7199
  76, 357, 
  // 7201
  76, 358, 
  // 7203
  130, 351, 
  // 7205
  130, 352, 
  // 7207
  130, 357, 
  // 7209
  130, 358, 
  // 7211
  132, 356, 
  // 7213
  90, 355, 
  // 7215
  90, 352, 
  // 7217
  90, 358, 
  // 7219
  76, 347, 
  // 7221
  76, 348, 
  // 7223
  76, 343, 
  // 7225
  76, 345, 
  // 7227
  76, 344, 
  // 7229
  76, 346, 
  // 7231
  53, 96, 
  // 7233
  76, 349, 
  // 7235
  76, 350, 
  // 7237
  103, 125, 
  // 7239
  130, 343, 
  // 7241
  130, 346, 
  // 7243
  130, 349, 
  // 7245
  130, 350, 
  // 7247
  132, 345, 
  // 7249
  90, 344, 
  // 7251
  104, 126, 
  // 7253
  90, 346, 
  // 7255
  90, 350, 
  // 7257
  105, 336, 88, 130, 
  // 7261
  105, 338, 88, 132, 
  // 7265
  105, 335, 88, 76, 
  // 7269
  105, 337, 88, 130, 
  // 7273
  105, 339, 88, 132, 
  // 7277
  105, 336, 88, 257, 
  // 7281
  105, 337, 88, 257, 
  // 7285
  105, 338, 88, 270, 
  // 7289
  105, 127, 
  // 7291
  105, 339, 88, 270, 
  // 7295
  105, 335, 88, 27, 
  // 7299
  105, 336, 130, 
  // 7302
  105, 338, 132, 
  // 7305
  105, 335, 76, 
  // 7308
  105, 337, 130, 
  // 7311
  105, 339, 132, 
  // 7314
  105, 342, 76, 
  // 7317
  106, 128, 
  // 7319
  105, 343, 130, 
  // 7322
  105, 344, 130, 
  // 7325
  105, 345, 132, 
  // 7328
  105, 346, 132, 
  // 7331
  105, 347, 76, 
  // 7334
  105, 348, 76, 
  // 7337
  97, 351, 130, 105, 
  // 7341
  97, 352, 132, 105, 
  // 7345
  97, 353, 76, 105, 
  // 7349
  97, 354, 76, 105, 
  // 7353
  107, 129, 
  // 7355
  97, 355, 130, 105, 
  // 7359
  97, 356, 132, 105, 
  // 7363
  97, 343, 130, 105, 
  // 7367
  97, 346, 132, 105, 
  // 7371
  97, 347, 76, 105, 
  // 7375
  97, 348, 76, 105, 
  // 7379
  97, 344, 130, 105, 
  // 7383
  97, 345, 132, 105, 
  // 7387
  77, 77, 90, 
  // 7390
  77, 77, 90, 90, 
  // 7394
  77, 77, 90, 90, 90, 
  // 7399
  77, 77, 
  // 7401
  19, 86, 
  // 7403
  76, 85, 93, 360, 361, 
  // 7408
  97, 22, 
  // 7410
  22, 
  // 7411
  19, 22, 
  // 7413
  97, 22, 76, 
  // 7416
  97, 22, 23, 362, 
  // 7420
  85, 
  // 7421
  83, 90, 
  // 7423
  83, 90, 90, 
  // 7426
  83, 90, 90, 90, 
  // 7430
  83, 364, 
  // 7432
  83, 364, 364, 
  // 7435
  83, 364, 364, 364, 
  // 7439
  270, 336, 88, 257, 27, 
  // 7444
  270, 336, 88, 257, 257, 257, 
  // 7450
  132, 336, 88, 257, 27, 
  // 7455
  132, 336, 88, 257, 257, 257, 
  // 7461
  137, 336, 88, 257, 27, 
  // 7466
  137, 336, 88, 257, 257, 257, 
  // 7472
  27, 340, 88, 257, 27, 
  // 7477
  27, 340, 88, 257, 257, 257, 
  // 7483
  270, 335, 88, 27, 27, 
  // 7488
  270, 335, 88, 27, 27, 27, 
  // 7494
  132, 335, 88, 27, 27, 
  // 7499
  132, 335, 88, 27, 27, 27, 
  // 7505
  137, 335, 88, 27, 27, 
  // 7510
  137, 335, 88, 27, 27, 27, 
  // 7516
  270, 338, 88, 270, 270, 270, 
  // 7522
  270, 338, 88, 270, 27, 
  // 7527
  132, 338, 88, 270, 270, 270, 
  // 7533
  132, 338, 88, 270, 27, 
  // 7538
  137, 338, 88, 270, 270, 270, 
  // 7544
  137, 338, 88, 270, 27, 
  // 7549
  270, 337, 88, 257, 27, 
  // 7554
  270, 337, 88, 257, 27, 27, 
  // 7560
  132, 337, 88, 257, 27, 
  // 7565
  132, 337, 88, 257, 27, 27, 
  // 7571
  137, 337, 88, 257, 27, 
  // 7576
  137, 337, 88, 257, 27, 27, 
  // 7582
  270, 339, 88, 270, 27, 
  // 7587
  270, 339, 88, 270, 257, 257, 
  // 7593
  132, 339, 88, 270, 27, 
  // 7598
  132, 339, 88, 270, 257, 257, 
  // 7604
  137, 339, 88, 270, 27, 
  // 7609
  137, 339, 88, 270, 257, 257, 
  // 7615
  27, 341, 88, 270, 27, 
  // 7620
  27, 341, 88, 270, 257, 257, 
  // 7626
  97, 351, 130, 76, 270, 
  // 7631
  97, 351, 130, 76, 132, 
  // 7636
  97, 351, 130, 76, 137, 
  // 7641
  97, 357, 130, 76, 27, 
  // 7646
  97, 353, 76, 76, 270, 
  // 7651
  97, 353, 76, 76, 132, 
  // 7656
  97, 353, 76, 76, 137, 
  // 7661
  97, 355, 130, 76, 270, 
  // 7666
  97, 355, 130, 76, 132, 
  // 7671
  97, 355, 130, 76, 137, 
  // 7676
  97, 352, 132, 76, 270, 
  // 7681
  97, 352, 132, 76, 132, 
  // 7686
  97, 352, 132, 76, 137, 
  // 7691
  97, 358, 132, 76, 27, 
  // 7696
  97, 356, 132, 76, 270, 
  // 7701
  97, 356, 132, 76, 132, 
  // 7706
  97, 356, 132, 76, 137, 
  // 7711
  270, 365, 130, 76, 
  // 7715
  132, 365, 130, 76, 
  // 7719
  137, 365, 130, 76, 
  // 7723
  270, 366, 132, 76, 
  // 7727
  132, 366, 132, 76, 
  // 7731
  137, 366, 132, 76, 
  // 7735
  27, 367, 130, 76, 
  // 7739
  27, 368, 132, 76, 
  // 7743
  76, 365, 
  // 7745
  130, 365, 
  // 7747
  90, 366, 
  // 7749
  76, 366, 
  // 7751
  130, 366, 
  // 7753
  76, 367, 
  // 7755
  130, 367, 
  // 7757
  76, 368, 
  // 7759
  130, 368, 
  // 7761
  90, 368, 
  // 7763
  76, 369, 
  // 7765
  130, 369, 
  // 7767
  76, 370, 
  // 7769
  130, 370, 
  // 7771
  76, 371, 
  // 7773
  130, 371, 
  // 7775
  76, 372, 
  // 7777
  130, 372, 
  // 7779
  90, 370, 
  // 7781
  90, 372, 
  // 7783
  270, 373, 130, 76, 
  // 7787
  132, 373, 130, 76, 
  // 7791
  137, 373, 130, 76, 
  // 7795
  270, 374, 132, 76, 
  // 7799
  132, 374, 132, 76, 
  // 7803
  137, 374, 132, 76, 
  // 7807
  27, 375, 130, 76, 
  // 7811
  27, 376, 132, 76, 
  // 7815
  76, 373, 
  // 7817
  130, 373, 
  // 7819
  76, 374, 
  // 7821
  130, 374, 
  // 7823
  76, 375, 
  // 7825
  130, 375, 
  // 7827
  76, 376, 
  // 7829
  130, 376, 
  // 7831
  90, 374, 
  // 7833
  90, 376, 
  // 7835
  77, 77, 93, 
  // 7838
  21, 21, 93, 
  // 7841
  2, 2, 93, 
  // 7844
  21, 21, 
  // 7846
  76, 
  // 7847
  76, 0, 
  // 7849
  1, 1, 93, 
  // 7852
  137, 76, 
  // 7854
  76, 137, 
  // 7856
  76, 137, 93, 
  // 7859
  93, 137, 
  // 7861
  137, 
};

static const OpenCLBuiltinStruct BuiltinTable[] = {
  // 1: convert_float2_rtz, convert_float2, convert_float2_rte, convert_float2_rtn, convert_float2_rtp, 
  { 0, 2, 0, 1, 0, 43, 31 },
  { 143, 2, 0, 1, 0, 43, 31 },
  { 237, 2, 0, 1, 0, 43, 31 },
  { 311, 2, 0, 1, 0, 43, 31 },
  { 395, 2, 0, 1, 0, 43, 31 },
  { 479, 2, 0, 1, 0, 43, 31 },
  { 563, 2, 0, 1, 0, 43, 31 },
  { 647, 2, 0, 1, 0, 43, 31 },
  { 729, 2, 0, 1, 0, 43, 31 },
  { 803, 2, 0, 1, 0, 43, 31 },
  { 885, 2, 0, 1, 0, 43, 31 },
  // 12: convert_half16, convert_half16_rte, convert_half16_rtn, convert_half16_rtp, convert_half16_rtz, 
  { 2, 2, 0, 1, 0, 43, 31 },
  { 125, 2, 0, 1, 0, 43, 31 },
  { 141, 2, 0, 1, 0, 43, 31 },
  { 157, 2, 0, 1, 0, 43, 31 },
  { 3893, 2, 0, 1, 0, 43, 31 },
  { 4272, 2, 0, 1, 0, 43, 31 },
  { 4818, 2, 0, 1, 0, 43, 31 },
  { 5366, 2, 0, 1, 0, 43, 31 },
  { 5682, 2, 0, 1, 0, 43, 31 },
  { 6773, 2, 0, 1, 0, 43, 31 },
  { 7353, 2, 0, 1, 0, 43, 31 },
  // 23: sub_group_non_uniform_reduce_max, sub_group_non_uniform_reduce_mul, sub_group_non_uniform_scan_exclusive_add, sub_group_non_uniform_scan_exclusive_min, sub_group_non_uniform_scan_exclusive_max, sub_group_non_uniform_scan_exclusive_mul, sub_group_non_uniform_scan_inclusive_add, sub_group_non_uniform_scan_inclusive_min, sub_group_non_uniform_scan_inclusive_max, sub_group_non_uniform_scan_inclusive_mul, sub_group_non_uniform_reduce_add, sub_group_non_uniform_reduce_min, 
  { 4, 2, 0, 0, 0, 38, 31 },
  // 24: sub_group_non_uniform_reduce_or, sub_group_non_uniform_reduce_xor, sub_group_non_uniform_scan_exclusive_and, sub_group_non_uniform_scan_exclusive_or, sub_group_non_uniform_scan_exclusive_xor, sub_group_non_uniform_scan_inclusive_and, sub_group_non_uniform_scan_inclusive_or, sub_group_non_uniform_scan_inclusive_xor, sub_group_non_uniform_reduce_and, 
  { 6, 2, 0, 0, 0, 38, 31 },
  // 25: sub_group_non_uniform_reduce_logical_or, sub_group_non_uniform_reduce_logical_xor, sub_group_non_uniform_scan_exclusive_logical_and, sub_group_non_uniform_scan_exclusive_logical_or, sub_group_non_uniform_scan_exclusive_logical_xor, sub_group_non_uniform_scan_inclusive_logical_and, sub_group_non_uniform_scan_inclusive_logical_or, sub_group_non_uniform_scan_inclusive_logical_xor, sub_group_non_uniform_reduce_logical_and, 
  { 8, 2, 0, 0, 0, 38, 31 },
  // 26: convert_half_rte, convert_half_rtn, convert_half_rtp, convert_half_rtz, convert_half, 
  { 10, 2, 0, 1, 0, 43, 31 },
  { 113, 2, 0, 1, 0, 43, 31 },
  { 131, 2, 0, 1, 0, 43, 31 },
  { 145, 2, 0, 1, 0, 43, 31 },
  { 3815, 2, 0, 1, 0, 43, 31 },
  { 4221, 2, 0, 1, 0, 43, 31 },
  { 4796, 2, 0, 1, 0, 43, 31 },
  { 5354, 2, 0, 1, 0, 43, 31 },
  { 5522, 2, 0, 1, 0, 43, 31 },
  { 6571, 2, 0, 1, 0, 43, 31 },
  { 7231, 2, 0, 1, 0, 43, 31 },
  // 37: convert_half2_rte, convert_half2_rtn, convert_half2_rtp, convert_half2_rtz, convert_half2, 
  { 12, 2, 0, 1, 0, 43, 31 },
  { 115, 2, 0, 1, 0, 43, 31 },
  { 133, 2, 0, 1, 0, 43, 31 },
  { 147, 2, 0, 1, 0, 43, 31 },
  { 3837, 2, 0, 1, 0, 43, 31 },
  { 4252, 2, 0, 1, 0, 43, 31 },
  { 4798, 2, 0, 1, 0, 43, 31 },
  { 5356, 2, 0, 1, 0, 43, 31 },
  { 5554, 2, 0, 1, 0, 43, 31 },
  { 6613, 2, 0, 1, 0, 43, 31 },
  { 7237, 2, 0, 1, 0, 43, 31 },
  // 48: sub_group_shuffle, sub_group_shuffle_xor, 
  { 14, 3, 0, 0, 0, 40, 31 },
  // 49: sub_group_shuffle_up, sub_group_shuffle_down, 
  { 14, 3, 0, 0, 0, 41, 31 },
  // 50: convert_half3_rte, convert_half3_rtn, convert_half3_rtp, convert_half3_rtz, convert_half3, 
  { 17, 2, 0, 1, 0, 43, 31 },
  { 117, 2, 0, 1, 0, 43, 31 },
  { 135, 2, 0, 1, 0, 43, 31 },
  { 149, 2, 0, 1, 0, 43, 31 },
  { 3851, 2, 0, 1, 0, 43, 31 },
  { 4254, 2, 0, 1, 0, 43, 31 },
  { 4812, 2, 0, 1, 0, 43, 31 },
  { 5358, 2, 0, 1, 0, 43, 31 },
  { 5586, 2, 0, 1, 0, 43, 31 },
  { 6655, 2, 0, 1, 0, 43, 31 },
  { 7251, 2, 0, 1, 0, 43, 31 },
  // 61: sub_group_clustered_reduce_add, sub_group_clustered_reduce_min, sub_group_clustered_reduce_max, sub_group_clustered_reduce_mul, 
  { 14, 3, 0, 0, 0, 36, 31 },
  // 62: sub_group_clustered_reduce_and, sub_group_clustered_reduce_or, sub_group_clustered_reduce_xor, 
  { 19, 3, 0, 0, 0, 36, 31 },
  // 63: sub_group_clustered_reduce_logical_and, sub_group_clustered_reduce_logical_or, sub_group_clustered_reduce_logical_xor, 
  { 22, 3, 0, 0, 0, 36, 31 },
  // 64: convert_half4_rte, convert_half4_rtn, convert_half4_rtp, convert_half4_rtz, convert_half4, 
  { 25, 2, 0, 1, 0, 43, 31 },
  { 119, 2, 0, 1, 0, 43, 31 },
  { 137, 2, 0, 1, 0, 43, 31 },
  { 151, 2, 0, 1, 0, 43, 31 },
  { 3871, 2, 0, 1, 0, 43, 31 },
  { 4256, 2, 0, 1, 0, 43, 31 },
  { 4814, 2, 0, 1, 0, 43, 31 },
  { 5360, 2, 0, 1, 0, 43, 31 },
  { 5618, 2, 0, 1, 0, 43, 31 },
  { 6697, 2, 0, 1, 0, 43, 31 },
  { 7289, 2, 0, 1, 0, 43, 31 },
  // 75: bitfield_insert, 
  { 27, 5, 0, 1, 0, 25, 31 },
  // 76: bitfield_extract_signed, 
  { 32, 4, 0, 1, 0, 25, 31 },
  { 36, 4, 0, 1, 0, 25, 31 },
  // 78: bitfield_extract_unsigned, 
  { 40, 4, 0, 1, 0, 25, 31 },
  { 44, 4, 0, 1, 0, 25, 31 },
  // 80: bit_reverse, 
  { 48, 2, 0, 1, 0, 25, 31 },
  // 81: dot, 
  { 50, 3, 0, 1, 0, 51, 31 },
  { 53, 3, 0, 1, 0, 51, 31 },
  { 56, 3, 0, 1, 0, 51, 31 },
  { 61, 3, 0, 1, 0, 51, 31 },
  { 1690, 3, 0, 1, 0, 43, 31 },
  { 1693, 3, 0, 1, 0, 43, 31 },
  { 1696, 3, 0, 1, 0, 43, 31 },
  // 88: convert_half8_rte, convert_half8_rtn, convert_half8_rtp, convert_half8_rtz, convert_half8, 
  { 59, 2, 0, 1, 0, 43, 31 },
  { 121, 2, 0, 1, 0, 43, 31 },
  { 139, 2, 0, 1, 0, 43, 31 },
  { 153, 2, 0, 1, 0, 43, 31 },
  { 3878, 2, 0, 1, 0, 43, 31 },
  { 4270, 2, 0, 1, 0, 43, 31 },
  { 4816, 2, 0, 1, 0, 43, 31 },
  { 5362, 2, 0, 1, 0, 43, 31 },
  { 5650, 2, 0, 1, 0, 43, 31 },
  { 6739, 2, 0, 1, 0, 43, 31 },
  { 7317, 2, 0, 1, 0, 43, 31 },
  // 99: dot_acc_sat, 
  { 64, 4, 0, 1, 0, 51, 31 },
  { 68, 4, 0, 1, 0, 51, 31 },
  { 72, 4, 0, 1, 0, 51, 31 },
  { 76, 4, 0, 1, 0, 51, 31 },
  // 103: dot_4x8packed_uu_uint, 
  { 80, 3, 0, 1, 0, 52, 31 },
  // 104: dot_4x8packed_ss_int, dot_4x8packed_us_int, dot_4x8packed_su_int, 
  { 83, 3, 0, 1, 0, 52, 31 },
  // 105: dot_acc_sat_4x8packed_uu_uint, 
  { 86, 4, 0, 1, 0, 52, 31 },
  // 106: dot_acc_sat_4x8packed_ss_int, dot_acc_sat_4x8packed_us_int, dot_acc_sat_4x8packed_su_int, 
  { 90, 4, 0, 1, 0, 52, 31 },
  // 107: sub_group_rotate, 
  { 94, 3, 0, 0, 1, 53, 31 },
  // 108: sub_group_clustered_rotate, 
  { 97, 4, 0, 0, 1, 53, 31 },
  // 109: arm_dot, 
  { 50, 3, 0, 0, 0, 3, 31 },
  { 53, 3, 0, 0, 0, 3, 31 },
  // 111: arm_dot_acc, 
  { 64, 4, 0, 0, 0, 1, 31 },
  { 68, 4, 0, 0, 0, 1, 31 },
  { 101, 4, 0, 0, 0, 0, 31 },
  { 105, 4, 0, 0, 0, 0, 31 },
  // 115: arm_dot_acc_sat, 
  { 64, 4, 0, 0, 0, 2, 31 },
  { 68, 4, 0, 0, 0, 2, 31 },
  // 117: convert_float3_rtz, convert_float3, convert_float3_rte, convert_float3_rtn, convert_float3_rtp, 
  { 109, 2, 0, 1, 0, 43, 31 },
  { 155, 2, 0, 1, 0, 43, 31 },
  { 241, 2, 0, 1, 0, 43, 31 },
  { 325, 2, 0, 1, 0, 43, 31 },
  { 407, 2, 0, 1, 0, 43, 31 },
  { 481, 2, 0, 1, 0, 43, 31 },
  { 565, 2, 0, 1, 0, 43, 31 },
  { 649, 2, 0, 1, 0, 43, 31 },
  { 733, 2, 0, 1, 0, 43, 31 },
  { 817, 2, 0, 1, 0, 43, 31 },
  { 897, 2, 0, 1, 0, 43, 31 },
  // 128: convert_float4_rtz, convert_float4, convert_float4_rte, convert_float4_rtn, convert_float4_rtp, 
  { 111, 2, 0, 1, 0, 43, 31 },
  { 159, 2, 0, 1, 0, 43, 31 },
  { 243, 2, 0, 1, 0, 43, 31 },
  { 327, 2, 0, 1, 0, 43, 31 },
  { 411, 2, 0, 1, 0, 43, 31 },
  { 495, 2, 0, 1, 0, 43, 31 },
  { 577, 2, 0, 1, 0, 43, 31 },
  { 651, 2, 0, 1, 0, 43, 31 },
  { 735, 2, 0, 1, 0, 43, 31 },
  { 819, 2, 0, 1, 0, 43, 31 },
  { 901, 2, 0, 1, 0, 43, 31 },
  // 139: convert_float8_rtz, convert_float8, convert_float8_rte, convert_float8_rtn, convert_float8_rtp, 
  { 123, 2, 0, 1, 0, 43, 31 },
  { 173, 2, 0, 1, 0, 43, 31 },
  { 255, 2, 0, 1, 0, 43, 31 },
  { 329, 2, 0, 1, 0, 43, 31 },
  { 413, 2, 0, 1, 0, 43, 31 },
  { 497, 2, 0, 1, 0, 43, 31 },
  { 581, 2, 0, 1, 0, 43, 31 },
  { 665, 2, 0, 1, 0, 43, 31 },
  { 747, 2, 0, 1, 0, 43, 31 },
  { 821, 2, 0, 1, 0, 43, 31 },
  { 903, 2, 0, 1, 0, 43, 31 },
  // 150: convert_float16_rtz, convert_float16, convert_float16_rte, convert_float16_rtn, convert_float16_rtp, 
  { 127, 2, 0, 1, 0, 43, 31 },
  { 175, 2, 0, 1, 0, 43, 31 },
  { 259, 2, 0, 1, 0, 43, 31 },
  { 343, 2, 0, 1, 0, 43, 31 },
  { 425, 2, 0, 1, 0, 43, 31 },
  { 499, 2, 0, 1, 0, 43, 31 },
  { 583, 2, 0, 1, 0, 43, 31 },
  { 667, 2, 0, 1, 0, 43, 31 },
  { 751, 2, 0, 1, 0, 43, 31 },
  { 835, 2, 0, 1, 0, 43, 31 },
  { 915, 2, 0, 1, 0, 43, 31 },
  // 161: convert_float, convert_float_rte, convert_float_rtn, convert_float_rtp, convert_float_rtz, 
  { 129, 2, 0, 1, 0, 43, 31 },
  { 225, 2, 0, 1, 0, 43, 31 },
  { 309, 2, 0, 1, 0, 43, 31 },
  { 393, 2, 0, 1, 0, 43, 31 },
  { 477, 2, 0, 1, 0, 43, 31 },
  { 559, 2, 0, 1, 0, 43, 31 },
  { 633, 2, 0, 1, 0, 43, 31 },
  { 717, 2, 0, 1, 0, 43, 31 },
  { 801, 2, 0, 1, 0, 43, 31 },
  { 883, 2, 0, 1, 0, 43, 31 },
  { 2447, 2, 0, 1, 0, 43, 31 },
  // 172: convert_char, convert_char_rte, convert_char_rtn, convert_char_rtp, convert_char_rtz, convert_char_sat, convert_char_sat_rte, convert_char_sat_rtn, convert_char_sat_rtp, convert_char_sat_rtz, 
  { 161, 2, 0, 1, 0, 43, 31 },
  { 177, 2, 0, 1, 0, 43, 31 },
  { 189, 2, 0, 1, 0, 43, 31 },
  { 201, 2, 0, 1, 0, 43, 31 },
  { 213, 2, 0, 1, 0, 43, 31 },
  { 227, 2, 0, 1, 0, 43, 31 },
  { 245, 2, 0, 1, 0, 43, 31 },
  { 261, 2, 0, 1, 0, 43, 31 },
  { 273, 2, 0, 1, 0, 43, 31 },
  { 285, 2, 0, 1, 0, 43, 31 },
  { 297, 2, 0, 1, 0, 43, 31 },
  // 183: convert_char2, convert_char2_rte, convert_char2_rtn, convert_char2_rtp, convert_char2_rtz, convert_char2_sat, convert_char2_sat_rte, convert_char2_sat_rtn, convert_char2_sat_rtp, convert_char2_sat_rtz, 
  { 163, 2, 0, 1, 0, 43, 31 },
  { 179, 2, 0, 1, 0, 43, 31 },
  { 191, 2, 0, 1, 0, 43, 31 },
  { 203, 2, 0, 1, 0, 43, 31 },
  { 215, 2, 0, 1, 0, 43, 31 },
  { 229, 2, 0, 1, 0, 43, 31 },
  { 247, 2, 0, 1, 0, 43, 31 },
  { 263, 2, 0, 1, 0, 43, 31 },
  { 275, 2, 0, 1, 0, 43, 31 },
  { 287, 2, 0, 1, 0, 43, 31 },
  { 299, 2, 0, 1, 0, 43, 31 },
  // 194: convert_char3, convert_char3_rte, convert_char3_rtn, convert_char3_rtp, convert_char3_rtz, convert_char3_sat, convert_char3_sat_rte, convert_char3_sat_rtn, convert_char3_sat_rtp, convert_char3_sat_rtz, 
  { 165, 2, 0, 1, 0, 43, 31 },
  { 181, 2, 0, 1, 0, 43, 31 },
  { 193, 2, 0, 1, 0, 43, 31 },
  { 205, 2, 0, 1, 0, 43, 31 },
  { 217, 2, 0, 1, 0, 43, 31 },
  { 231, 2, 0, 1, 0, 43, 31 },
  { 249, 2, 0, 1, 0, 43, 31 },
  { 265, 2, 0, 1, 0, 43, 31 },
  { 277, 2, 0, 1, 0, 43, 31 },
  { 289, 2, 0, 1, 0, 43, 31 },
  { 301, 2, 0, 1, 0, 43, 31 },
  // 205: convert_char4, convert_char4_rte, convert_char4_rtn, convert_char4_rtp, convert_char4_rtz, convert_char4_sat, convert_char4_sat_rte, convert_char4_sat_rtn, convert_char4_sat_rtp, convert_char4_sat_rtz, 
  { 167, 2, 0, 1, 0, 43, 31 },
  { 183, 2, 0, 1, 0, 43, 31 },
  { 195, 2, 0, 1, 0, 43, 31 },
  { 207, 2, 0, 1, 0, 43, 31 },
  { 219, 2, 0, 1, 0, 43, 31 },
  { 233, 2, 0, 1, 0, 43, 31 },
  { 251, 2, 0, 1, 0, 43, 31 },
  { 267, 2, 0, 1, 0, 43, 31 },
  { 279, 2, 0, 1, 0, 43, 31 },
  { 291, 2, 0, 1, 0, 43, 31 },
  { 303, 2, 0, 1, 0, 43, 31 },
  // 216: convert_char8, convert_char8_rte, convert_char8_rtn, convert_char8_rtp, convert_char8_rtz, convert_char8_sat, convert_char8_sat_rte, convert_char8_sat_rtn, convert_char8_sat_rtp, convert_char8_sat_rtz, 
  { 169, 2, 0, 1, 0, 43, 31 },
  { 185, 2, 0, 1, 0, 43, 31 },
  { 197, 2, 0, 1, 0, 43, 31 },
  { 209, 2, 0, 1, 0, 43, 31 },
  { 221, 2, 0, 1, 0, 43, 31 },
  { 235, 2, 0, 1, 0, 43, 31 },
  { 253, 2, 0, 1, 0, 43, 31 },
  { 269, 2, 0, 1, 0, 43, 31 },
  { 281, 2, 0, 1, 0, 43, 31 },
  { 293, 2, 0, 1, 0, 43, 31 },
  { 305, 2, 0, 1, 0, 43, 31 },
  // 227: convert_char16, convert_char16_rte, convert_char16_rtn, convert_char16_rtp, convert_char16_rtz, convert_char16_sat, convert_char16_sat_rte, convert_char16_sat_rtn, convert_char16_sat_rtp, convert_char16_sat_rtz, 
  { 171, 2, 0, 1, 0, 43, 31 },
  { 187, 2, 0, 1, 0, 43, 31 },
  { 199, 2, 0, 1, 0, 43, 31 },
  { 211, 2, 0, 1, 0, 43, 31 },
  { 223, 2, 0, 1, 0, 43, 31 },
  { 239, 2, 0, 1, 0, 43, 31 },
  { 257, 2, 0, 1, 0, 43, 31 },
  { 271, 2, 0, 1, 0, 43, 31 },
  { 283, 2, 0, 1, 0, 43, 31 },
  { 295, 2, 0, 1, 0, 43, 31 },
  { 307, 2, 0, 1, 0, 43, 31 },
  // 238: convert_uchar, convert_uchar_rte, convert_uchar_rtn, convert_uchar_rtp, convert_uchar_rtz, convert_uchar_sat, convert_uchar_sat_rte, convert_uchar_sat_rtn, convert_uchar_sat_rtp, convert_uchar_sat_rtz, 
  { 313, 2, 0, 1, 0, 43, 31 },
  { 331, 2, 0, 1, 0, 43, 31 },
  { 345, 2, 0, 1, 0, 43, 31 },
  { 357, 2, 0, 1, 0, 43, 31 },
  { 369, 2, 0, 1, 0, 43, 31 },
  { 381, 2, 0, 1, 0, 43, 31 },
  { 397, 2, 0, 1, 0, 43, 31 },
  { 415, 2, 0, 1, 0, 43, 31 },
  { 429, 2, 0, 1, 0, 43, 31 },
  { 441, 2, 0, 1, 0, 43, 31 },
  { 453, 2, 0, 1, 0, 43, 31 },
  // 249: convert_uchar2, convert_uchar2_rte, convert_uchar2_rtn, convert_uchar2_rtp, convert_uchar2_rtz, convert_uchar2_sat, convert_uchar2_sat_rte, convert_uchar2_sat_rtn, convert_uchar2_sat_rtp, convert_uchar2_sat_rtz, 
  { 315, 2, 0, 1, 0, 43, 31 },
  { 333, 2, 0, 1, 0, 43, 31 },
  { 347, 2, 0, 1, 0, 43, 31 },
  { 359, 2, 0, 1, 0, 43, 31 },
  { 371, 2, 0, 1, 0, 43, 31 },
  { 383, 2, 0, 1, 0, 43, 31 },
  { 399, 2, 0, 1, 0, 43, 31 },
  { 417, 2, 0, 1, 0, 43, 31 },
  { 431, 2, 0, 1, 0, 43, 31 },
  { 443, 2, 0, 1, 0, 43, 31 },
  { 455, 2, 0, 1, 0, 43, 31 },
  // 260: convert_uchar3, convert_uchar3_rte, convert_uchar3_rtn, convert_uchar3_rtp, convert_uchar3_rtz, convert_uchar3_sat, convert_uchar3_sat_rte, convert_uchar3_sat_rtn, convert_uchar3_sat_rtp, convert_uchar3_sat_rtz, 
  { 317, 2, 0, 1, 0, 43, 31 },
  { 335, 2, 0, 1, 0, 43, 31 },
  { 349, 2, 0, 1, 0, 43, 31 },
  { 361, 2, 0, 1, 0, 43, 31 },
  { 373, 2, 0, 1, 0, 43, 31 },
  { 385, 2, 0, 1, 0, 43, 31 },
  { 401, 2, 0, 1, 0, 43, 31 },
  { 419, 2, 0, 1, 0, 43, 31 },
  { 433, 2, 0, 1, 0, 43, 31 },
  { 445, 2, 0, 1, 0, 43, 31 },
  { 457, 2, 0, 1, 0, 43, 31 },
  // 271: convert_uchar4, convert_uchar4_rte, convert_uchar4_rtn, convert_uchar4_rtp, convert_uchar4_rtz, convert_uchar4_sat, convert_uchar4_sat_rte, convert_uchar4_sat_rtn, convert_uchar4_sat_rtp, convert_uchar4_sat_rtz, 
  { 319, 2, 0, 1, 0, 43, 31 },
  { 337, 2, 0, 1, 0, 43, 31 },
  { 351, 2, 0, 1, 0, 43, 31 },
  { 363, 2, 0, 1, 0, 43, 31 },
  { 375, 2, 0, 1, 0, 43, 31 },
  { 387, 2, 0, 1, 0, 43, 31 },
  { 403, 2, 0, 1, 0, 43, 31 },
  { 421, 2, 0, 1, 0, 43, 31 },
  { 435, 2, 0, 1, 0, 43, 31 },
  { 447, 2, 0, 1, 0, 43, 31 },
  { 459, 2, 0, 1, 0, 43, 31 },
  // 282: convert_uchar8, convert_uchar8_rte, convert_uchar8_rtn, convert_uchar8_rtp, convert_uchar8_rtz, convert_uchar8_sat, convert_uchar8_sat_rte, convert_uchar8_sat_rtn, convert_uchar8_sat_rtp, convert_uchar8_sat_rtz, 
  { 321, 2, 0, 1, 0, 43, 31 },
  { 339, 2, 0, 1, 0, 43, 31 },
  { 353, 2, 0, 1, 0, 43, 31 },
  { 365, 2, 0, 1, 0, 43, 31 },
  { 377, 2, 0, 1, 0, 43, 31 },
  { 389, 2, 0, 1, 0, 43, 31 },
  { 405, 2, 0, 1, 0, 43, 31 },
  { 423, 2, 0, 1, 0, 43, 31 },
  { 437, 2, 0, 1, 0, 43, 31 },
  { 449, 2, 0, 1, 0, 43, 31 },
  { 461, 2, 0, 1, 0, 43, 31 },
  // 293: convert_uchar16, convert_uchar16_rte, convert_uchar16_rtn, convert_uchar16_rtp, convert_uchar16_rtz, convert_uchar16_sat, convert_uchar16_sat_rte, convert_uchar16_sat_rtn, convert_uchar16_sat_rtp, convert_uchar16_sat_rtz, 
  { 323, 2, 0, 1, 0, 43, 31 },
  { 341, 2, 0, 1, 0, 43, 31 },
  { 355, 2, 0, 1, 0, 43, 31 },
  { 367, 2, 0, 1, 0, 43, 31 },
  { 379, 2, 0, 1, 0, 43, 31 },
  { 391, 2, 0, 1, 0, 43, 31 },
  { 409, 2, 0, 1, 0, 43, 31 },
  { 427, 2, 0, 1, 0, 43, 31 },
  { 439, 2, 0, 1, 0, 43, 31 },
  { 451, 2, 0, 1, 0, 43, 31 },
  { 463, 2, 0, 1, 0, 43, 31 },
  // 304: convert_short, convert_short_rte, convert_short_rtn, convert_short_rtp, convert_short_rtz, convert_short_sat, convert_short_sat_rte, convert_short_sat_rtn, convert_short_sat_rtp, convert_short_sat_rtz, 
  { 465, 2, 0, 1, 0, 43, 31 },
  { 483, 2, 0, 1, 0, 43, 31 },
  { 501, 2, 0, 1, 0, 43, 31 },
  { 513, 2, 0, 1, 0, 43, 31 },
  { 525, 2, 0, 1, 0, 43, 31 },
  { 537, 2, 0, 1, 0, 43, 31 },
  { 549, 2, 0, 1, 0, 43, 31 },
  { 567, 2, 0, 1, 0, 43, 31 },
  { 585, 2, 0, 1, 0, 43, 31 },
  { 597, 2, 0, 1, 0, 43, 31 },
  { 609, 2, 0, 1, 0, 43, 31 },
  // 315: convert_short2, convert_short2_rte, convert_short2_rtn, convert_short2_rtp, convert_short2_rtz, convert_short2_sat, convert_short2_sat_rte, convert_short2_sat_rtn, convert_short2_sat_rtp, convert_short2_sat_rtz, 
  { 467, 2, 0, 1, 0, 43, 31 },
  { 485, 2, 0, 1, 0, 43, 31 },
  { 503, 2, 0, 1, 0, 43, 31 },
  { 515, 2, 0, 1, 0, 43, 31 },
  { 527, 2, 0, 1, 0, 43, 31 },
  { 539, 2, 0, 1, 0, 43, 31 },
  { 551, 2, 0, 1, 0, 43, 31 },
  { 569, 2, 0, 1, 0, 43, 31 },
  { 587, 2, 0, 1, 0, 43, 31 },
  { 599, 2, 0, 1, 0, 43, 31 },
  { 611, 2, 0, 1, 0, 43, 31 },
  // 326: convert_short3, convert_short3_rte, convert_short3_rtn, convert_short3_rtp, convert_short3_rtz, convert_short3_sat, convert_short3_sat_rte, convert_short3_sat_rtn, convert_short3_sat_rtp, convert_short3_sat_rtz, 
  { 469, 2, 0, 1, 0, 43, 31 },
  { 487, 2, 0, 1, 0, 43, 31 },
  { 505, 2, 0, 1, 0, 43, 31 },
  { 517, 2, 0, 1, 0, 43, 31 },
  { 529, 2, 0, 1, 0, 43, 31 },
  { 541, 2, 0, 1, 0, 43, 31 },
  { 553, 2, 0, 1, 0, 43, 31 },
  { 571, 2, 0, 1, 0, 43, 31 },
  { 589, 2, 0, 1, 0, 43, 31 },
  { 601, 2, 0, 1, 0, 43, 31 },
  { 613, 2, 0, 1, 0, 43, 31 },
  // 337: convert_short4, convert_short4_rte, convert_short4_rtn, convert_short4_rtp, convert_short4_rtz, convert_short4_sat, convert_short4_sat_rte, convert_short4_sat_rtn, convert_short4_sat_rtp, convert_short4_sat_rtz, 
  { 471, 2, 0, 1, 0, 43, 31 },
  { 489, 2, 0, 1, 0, 43, 31 },
  { 507, 2, 0, 1, 0, 43, 31 },
  { 519, 2, 0, 1, 0, 43, 31 },
  { 531, 2, 0, 1, 0, 43, 31 },
  { 543, 2, 0, 1, 0, 43, 31 },
  { 555, 2, 0, 1, 0, 43, 31 },
  { 573, 2, 0, 1, 0, 43, 31 },
  { 591, 2, 0, 1, 0, 43, 31 },
  { 603, 2, 0, 1, 0, 43, 31 },
  { 615, 2, 0, 1, 0, 43, 31 },
  // 348: convert_short8, convert_short8_rte, convert_short8_rtn, convert_short8_rtp, convert_short8_rtz, convert_short8_sat, convert_short8_sat_rte, convert_short8_sat_rtn, convert_short8_sat_rtp, convert_short8_sat_rtz, 
  { 473, 2, 0, 1, 0, 43, 31 },
  { 491, 2, 0, 1, 0, 43, 31 },
  { 509, 2, 0, 1, 0, 43, 31 },
  { 521, 2, 0, 1, 0, 43, 31 },
  { 533, 2, 0, 1, 0, 43, 31 },
  { 545, 2, 0, 1, 0, 43, 31 },
  { 557, 2, 0, 1, 0, 43, 31 },
  { 575, 2, 0, 1, 0, 43, 31 },
  { 593, 2, 0, 1, 0, 43, 31 },
  { 605, 2, 0, 1, 0, 43, 31 },
  { 617, 2, 0, 1, 0, 43, 31 },
  // 359: convert_short16, convert_short16_rte, convert_short16_rtn, convert_short16_rtp, convert_short16_rtz, convert_short16_sat, convert_short16_sat_rte, convert_short16_sat_rtn, convert_short16_sat_rtp, convert_short16_sat_rtz, 
  { 475, 2, 0, 1, 0, 43, 31 },
  { 493, 2, 0, 1, 0, 43, 31 },
  { 511, 2, 0, 1, 0, 43, 31 },
  { 523, 2, 0, 1, 0, 43, 31 },
  { 535, 2, 0, 1, 0, 43, 31 },
  { 547, 2, 0, 1, 0, 43, 31 },
  { 561, 2, 0, 1, 0, 43, 31 },
  { 579, 2, 0, 1, 0, 43, 31 },
  { 595, 2, 0, 1, 0, 43, 31 },
  { 607, 2, 0, 1, 0, 43, 31 },
  { 619, 2, 0, 1, 0, 43, 31 },
  // 370: convert_ushort, convert_ushort_rte, convert_ushort_rtn, convert_ushort_rtp, convert_ushort_rtz, convert_ushort_sat, convert_ushort_sat_rte, convert_ushort_sat_rtn, convert_ushort_sat_rtp, convert_ushort_sat_rtz, 
  { 621, 2, 0, 1, 0, 43, 31 },
  { 635, 2, 0, 1, 0, 43, 31 },
  { 653, 2, 0, 1, 0, 43, 31 },
  { 669, 2, 0, 1, 0, 43, 31 },
  { 681, 2, 0, 1, 0, 43, 31 },
  { 693, 2, 0, 1, 0, 43, 31 },
  { 705, 2, 0, 1, 0, 43, 31 },
  { 719, 2, 0, 1, 0, 43, 31 },
  { 737, 2, 0, 1, 0, 43, 31 },
  { 753, 2, 0, 1, 0, 43, 31 },
  { 765, 2, 0, 1, 0, 43, 31 },
  // 381: convert_ushort2, convert_ushort2_rte, convert_ushort2_rtn, convert_ushort2_rtp, convert_ushort2_rtz, convert_ushort2_sat, convert_ushort2_sat_rte, convert_ushort2_sat_rtn, convert_ushort2_sat_rtp, convert_ushort2_sat_rtz, 
  { 623, 2, 0, 1, 0, 43, 31 },
  { 637, 2, 0, 1, 0, 43, 31 },
  { 655, 2, 0, 1, 0, 43, 31 },
  { 671, 2, 0, 1, 0, 43, 31 },
  { 683, 2, 0, 1, 0, 43, 31 },
  { 695, 2, 0, 1, 0, 43, 31 },
  { 707, 2, 0, 1, 0, 43, 31 },
  { 721, 2, 0, 1, 0, 43, 31 },
  { 739, 2, 0, 1, 0, 43, 31 },
  { 755, 2, 0, 1, 0, 43, 31 },
  { 767, 2, 0, 1, 0, 43, 31 },
  // 392: convert_ushort3, convert_ushort3_rte, convert_ushort3_rtn, convert_ushort3_rtp, convert_ushort3_rtz, convert_ushort3_sat, convert_ushort3_sat_rte, convert_ushort3_sat_rtn, convert_ushort3_sat_rtp, convert_ushort3_sat_rtz, 
  { 625, 2, 0, 1, 0, 43, 31 },
  { 639, 2, 0, 1, 0, 43, 31 },
  { 657, 2, 0, 1, 0, 43, 31 },
  { 673, 2, 0, 1, 0, 43, 31 },
  { 685, 2, 0, 1, 0, 43, 31 },
  { 697, 2, 0, 1, 0, 43, 31 },
  { 709, 2, 0, 1, 0, 43, 31 },
  { 723, 2, 0, 1, 0, 43, 31 },
  { 741, 2, 0, 1, 0, 43, 31 },
  { 757, 2, 0, 1, 0, 43, 31 },
  { 769, 2, 0, 1, 0, 43, 31 },
  // 403: convert_ushort4, convert_ushort4_rte, convert_ushort4_rtn, convert_ushort4_rtp, convert_ushort4_rtz, convert_ushort4_sat, convert_ushort4_sat_rte, convert_ushort4_sat_rtn, convert_ushort4_sat_rtp, convert_ushort4_sat_rtz, 
  { 627, 2, 0, 1, 0, 43, 31 },
  { 641, 2, 0, 1, 0, 43, 31 },
  { 659, 2, 0, 1, 0, 43, 31 },
  { 675, 2, 0, 1, 0, 43, 31 },
  { 687, 2, 0, 1, 0, 43, 31 },
  { 699, 2, 0, 1, 0, 43, 31 },
  { 711, 2, 0, 1, 0, 43, 31 },
  { 725, 2, 0, 1, 0, 43, 31 },
  { 743, 2, 0, 1, 0, 43, 31 },
  { 759, 2, 0, 1, 0, 43, 31 },
  { 771, 2, 0, 1, 0, 43, 31 },
  // 414: convert_ushort8, convert_ushort8_rte, convert_ushort8_rtn, convert_ushort8_rtp, convert_ushort8_rtz, convert_ushort8_sat, convert_ushort8_sat_rte, convert_ushort8_sat_rtn, convert_ushort8_sat_rtp, convert_ushort8_sat_rtz, 
  { 629, 2, 0, 1, 0, 43, 31 },
  { 643, 2, 0, 1, 0, 43, 31 },
  { 661, 2, 0, 1, 0, 43, 31 },
  { 677, 2, 0, 1, 0, 43, 31 },
  { 689, 2, 0, 1, 0, 43, 31 },
  { 701, 2, 0, 1, 0, 43, 31 },
  { 713, 2, 0, 1, 0, 43, 31 },
  { 727, 2, 0, 1, 0, 43, 31 },
  { 745, 2, 0, 1, 0, 43, 31 },
  { 761, 2, 0, 1, 0, 43, 31 },
  { 773, 2, 0, 1, 0, 43, 31 },
  // 425: convert_ushort16, convert_ushort16_rte, convert_ushort16_rtn, convert_ushort16_rtp, convert_ushort16_rtz, convert_ushort16_sat, convert_ushort16_sat_rte, convert_ushort16_sat_rtn, convert_ushort16_sat_rtp, convert_ushort16_sat_rtz, 
  { 631, 2, 0, 1, 0, 43, 31 },
  { 645, 2, 0, 1, 0, 43, 31 },
  { 663, 2, 0, 1, 0, 43, 31 },
  { 679, 2, 0, 1, 0, 43, 31 },
  { 691, 2, 0, 1, 0, 43, 31 },
  { 703, 2, 0, 1, 0, 43, 31 },
  { 715, 2, 0, 1, 0, 43, 31 },
  { 731, 2, 0, 1, 0, 43, 31 },
  { 749, 2, 0, 1, 0, 43, 31 },
  { 763, 2, 0, 1, 0, 43, 31 },
  { 775, 2, 0, 1, 0, 43, 31 },
  // 436: convert_int, convert_int_rte, convert_int_rtn, convert_int_rtp, convert_int_rtz, convert_int_sat, convert_int_sat_rte, convert_int_sat_rtn, convert_int_sat_rtp, convert_int_sat_rtz, 
  { 777, 2, 0, 1, 0, 43, 31 },
  { 789, 2, 0, 1, 0, 43, 31 },
  { 805, 2, 0, 1, 0, 43, 31 },
  { 823, 2, 0, 1, 0, 43, 31 },
  { 837, 2, 0, 1, 0, 43, 31 },
  { 849, 2, 0, 1, 0, 43, 31 },
  { 861, 2, 0, 1, 0, 43, 31 },
  { 8, 2, 0, 1, 0, 43, 31 },
  { 887, 2, 0, 1, 0, 43, 31 },
  { 905, 2, 0, 1, 0, 43, 31 },
  { 919, 2, 0, 1, 0, 43, 31 },
  // 447: convert_int2, convert_int2_rte, convert_int2_rtn, convert_int2_rtp, convert_int2_rtz, convert_int2_sat, convert_int2_sat_rte, convert_int2_sat_rtn, convert_int2_sat_rtp, convert_int2_sat_rtz, 
  { 779, 2, 0, 1, 0, 43, 31 },
  { 791, 2, 0, 1, 0, 43, 31 },
  { 807, 2, 0, 1, 0, 43, 31 },
  { 825, 2, 0, 1, 0, 43, 31 },
  { 839, 2, 0, 1, 0, 43, 31 },
  { 851, 2, 0, 1, 0, 43, 31 },
  { 863, 2, 0, 1, 0, 43, 31 },
  { 873, 2, 0, 1, 0, 43, 31 },
  { 889, 2, 0, 1, 0, 43, 31 },
  { 907, 2, 0, 1, 0, 43, 31 },
  { 921, 2, 0, 1, 0, 43, 31 },
  // 458: convert_int3, convert_int3_rte, convert_int3_rtn, convert_int3_rtp, convert_int3_rtz, convert_int3_sat, convert_int3_sat_rte, convert_int3_sat_rtn, convert_int3_sat_rtp, convert_int3_sat_rtz, 
  { 781, 2, 0, 1, 0, 43, 31 },
  { 793, 2, 0, 1, 0, 43, 31 },
  { 809, 2, 0, 1, 0, 43, 31 },
  { 827, 2, 0, 1, 0, 43, 31 },
  { 841, 2, 0, 1, 0, 43, 31 },
  { 853, 2, 0, 1, 0, 43, 31 },
  { 865, 2, 0, 1, 0, 43, 31 },
  { 875, 2, 0, 1, 0, 43, 31 },
  { 891, 2, 0, 1, 0, 43, 31 },
  { 909, 2, 0, 1, 0, 43, 31 },
  { 923, 2, 0, 1, 0, 43, 31 },
  // 469: convert_int4, convert_int4_rte, convert_int4_rtn, convert_int4_rtp, convert_int4_rtz, convert_int4_sat, convert_int4_sat_rte, convert_int4_sat_rtn, convert_int4_sat_rtp, convert_int4_sat_rtz, 
  { 783, 2, 0, 1, 0, 43, 31 },
  { 795, 2, 0, 1, 0, 43, 31 },
  { 811, 2, 0, 1, 0, 43, 31 },
  { 829, 2, 0, 1, 0, 43, 31 },
  { 843, 2, 0, 1, 0, 43, 31 },
  { 855, 2, 0, 1, 0, 43, 31 },
  { 867, 2, 0, 1, 0, 43, 31 },
  { 877, 2, 0, 1, 0, 43, 31 },
  { 893, 2, 0, 1, 0, 43, 31 },
  { 911, 2, 0, 1, 0, 43, 31 },
  { 925, 2, 0, 1, 0, 43, 31 },
  // 480: convert_int8, convert_int8_rte, convert_int8_rtn, convert_int8_rtp, convert_int8_rtz, convert_int8_sat, convert_int8_sat_rte, convert_int8_sat_rtn, convert_int8_sat_rtp, convert_int8_sat_rtz, 
  { 785, 2, 0, 1, 0, 43, 31 },
  { 797, 2, 0, 1, 0, 43, 31 },
  { 813, 2, 0, 1, 0, 43, 31 },
  { 831, 2, 0, 1, 0, 43, 31 },
  { 845, 2, 0, 1, 0, 43, 31 },
  { 857, 2, 0, 1, 0, 43, 31 },
  { 869, 2, 0, 1, 0, 43, 31 },
  { 879, 2, 0, 1, 0, 43, 31 },
  { 895, 2, 0, 1, 0, 43, 31 },
  { 913, 2, 0, 1, 0, 43, 31 },
  { 927, 2, 0, 1, 0, 43, 31 },
  // 491: convert_int16, convert_int16_rte, convert_int16_rtn, convert_int16_rtp, convert_int16_rtz, convert_int16_sat, convert_int16_sat_rte, convert_int16_sat_rtn, convert_int16_sat_rtp, convert_int16_sat_rtz, 
  { 787, 2, 0, 1, 0, 43, 31 },
  { 799, 2, 0, 1, 0, 43, 31 },
  { 815, 2, 0, 1, 0, 43, 31 },
  { 833, 2, 0, 1, 0, 43, 31 },
  { 847, 2, 0, 1, 0, 43, 31 },
  { 859, 2, 0, 1, 0, 43, 31 },
  { 871, 2, 0, 1, 0, 43, 31 },
  { 881, 2, 0, 1, 0, 43, 31 },
  { 899, 2, 0, 1, 0, 43, 31 },
  { 917, 2, 0, 1, 0, 43, 31 },
  { 929, 2, 0, 1, 0, 43, 31 },
  // 502: convert_uint, convert_uint_rte, convert_uint_rtn, convert_uint_rtp, convert_uint_rtz, convert_uint_sat, convert_uint_sat_rte, convert_uint_sat_rtn, convert_uint_sat_rtp, convert_uint_sat_rtz, 
  { 931, 2, 0, 1, 0, 43, 31 },
  { 943, 2, 0, 1, 0, 43, 31 },
  { 955, 2, 0, 1, 0, 43, 31 },
  { 977, 2, 0, 1, 0, 43, 31 },
  { 991, 2, 0, 1, 0, 43, 31 },
  { 1003, 2, 0, 1, 0, 43, 31 },
  { 1015, 2, 0, 1, 0, 43, 31 },
  { 1027, 2, 0, 1, 0, 43, 31 },
  { 1049, 2, 0, 1, 0, 43, 31 },
  { 1063, 2, 0, 1, 0, 43, 31 },
  { 1075, 2, 0, 1, 0, 43, 31 },
  // 513: convert_uint2, convert_uint2_rte, convert_uint2_rtn, convert_uint2_rtp, convert_uint2_rtz, convert_uint2_sat, convert_uint2_sat_rte, convert_uint2_sat_rtn, convert_uint2_sat_rtp, convert_uint2_sat_rtz, 
  { 933, 2, 0, 1, 0, 43, 31 },
  { 945, 2, 0, 1, 0, 43, 31 },
  { 957, 2, 0, 1, 0, 43, 31 },
  { 979, 2, 0, 1, 0, 43, 31 },
  { 993, 2, 0, 1, 0, 43, 31 },
  { 1005, 2, 0, 1, 0, 43, 31 },
  { 1017, 2, 0, 1, 0, 43, 31 },
  { 1029, 2, 0, 1, 0, 43, 31 },
  { 1051, 2, 0, 1, 0, 43, 31 },
  { 1065, 2, 0, 1, 0, 43, 31 },
  { 1077, 2, 0, 1, 0, 43, 31 },
  // 524: convert_uint3, convert_uint3_rte, convert_uint3_rtn, convert_uint3_rtp, convert_uint3_rtz, convert_uint3_sat, convert_uint3_sat_rte, convert_uint3_sat_rtn, convert_uint3_sat_rtp, convert_uint3_sat_rtz, 
  { 935, 2, 0, 1, 0, 43, 31 },
  { 947, 2, 0, 1, 0, 43, 31 },
  { 959, 2, 0, 1, 0, 43, 31 },
  { 981, 2, 0, 1, 0, 43, 31 },
  { 995, 2, 0, 1, 0, 43, 31 },
  { 1007, 2, 0, 1, 0, 43, 31 },
  { 1019, 2, 0, 1, 0, 43, 31 },
  { 1031, 2, 0, 1, 0, 43, 31 },
  { 1053, 2, 0, 1, 0, 43, 31 },
  { 1067, 2, 0, 1, 0, 43, 31 },
  { 1079, 2, 0, 1, 0, 43, 31 },
  // 535: convert_uint4, convert_uint4_rte, convert_uint4_rtn, convert_uint4_rtp, convert_uint4_rtz, convert_uint4_sat, convert_uint4_sat_rte, convert_uint4_sat_rtn, convert_uint4_sat_rtp, convert_uint4_sat_rtz, 
  { 937, 2, 0, 1, 0, 43, 31 },
  { 949, 2, 0, 1, 0, 43, 31 },
  { 961, 2, 0, 1, 0, 43, 31 },
  { 983, 2, 0, 1, 0, 43, 31 },
  { 997, 2, 0, 1, 0, 43, 31 },
  { 1009, 2, 0, 1, 0, 43, 31 },
  { 1021, 2, 0, 1, 0, 43, 31 },
  { 1033, 2, 0, 1, 0, 43, 31 },
  { 1055, 2, 0, 1, 0, 43, 31 },
  { 1069, 2, 0, 1, 0, 43, 31 },
  { 1081, 2, 0, 1, 0, 43, 31 },
  // 546: convert_uint8, convert_uint8_rte, convert_uint8_rtn, convert_uint8_rtp, convert_uint8_rtz, convert_uint8_sat, convert_uint8_sat_rte, convert_uint8_sat_rtn, convert_uint8_sat_rtp, convert_uint8_sat_rtz, 
  { 939, 2, 0, 1, 0, 43, 31 },
  { 951, 2, 0, 1, 0, 43, 31 },
  { 963, 2, 0, 1, 0, 43, 31 },
  { 985, 2, 0, 1, 0, 43, 31 },
  { 999, 2, 0, 1, 0, 43, 31 },
  { 1011, 2, 0, 1, 0, 43, 31 },
  { 1023, 2, 0, 1, 0, 43, 31 },
  { 1035, 2, 0, 1, 0, 43, 31 },
  { 1057, 2, 0, 1, 0, 43, 31 },
  { 1071, 2, 0, 1, 0, 43, 31 },
  { 1083, 2, 0, 1, 0, 43, 31 },
  // 557: convert_uint16, convert_uint16_rte, convert_uint16_rtn, convert_uint16_rtp, convert_uint16_rtz, convert_uint16_sat, convert_uint16_sat_rte, convert_uint16_sat_rtn, convert_uint16_sat_rtp, convert_uint16_sat_rtz, 
  { 941, 2, 0, 1, 0, 43, 31 },
  { 953, 2, 0, 1, 0, 43, 31 },
  { 965, 2, 0, 1, 0, 43, 31 },
  { 989, 2, 0, 1, 0, 43, 31 },
  { 1001, 2, 0, 1, 0, 43, 31 },
  { 1013, 2, 0, 1, 0, 43, 31 },
  { 1025, 2, 0, 1, 0, 43, 31 },
  { 1037, 2, 0, 1, 0, 43, 31 },
  { 1061, 2, 0, 1, 0, 43, 31 },
  { 1073, 2, 0, 1, 0, 43, 31 },
  { 1085, 2, 0, 1, 0, 43, 31 },
  // 568: convert_double, convert_double_rte, convert_double_rtn, convert_double_rtp, convert_double_rtz, 
  { 967, 2, 0, 1, 0, 43, 31 },
  { 1039, 2, 0, 1, 0, 43, 31 },
  { 1111, 2, 0, 1, 0, 43, 31 },
  { 1183, 2, 0, 1, 0, 43, 31 },
  { 1255, 2, 0, 1, 0, 43, 31 },
  { 1327, 2, 0, 1, 0, 43, 31 },
  { 1399, 2, 0, 1, 0, 43, 31 },
  { 1699, 2, 0, 1, 0, 43, 31 },
  { 2262, 2, 0, 1, 0, 43, 31 },
  { 3249, 2, 0, 1, 0, 43, 31 },
  { 3639, 2, 0, 1, 0, 43, 31 },
  // 579: convert_double2, convert_double2_rte, convert_double2_rtn, convert_double2_rtp, convert_double2_rtz, 
  { 969, 2, 0, 1, 0, 43, 31 },
  { 1041, 2, 0, 1, 0, 43, 31 },
  { 1113, 2, 0, 1, 0, 43, 31 },
  { 1185, 2, 0, 1, 0, 43, 31 },
  { 1257, 2, 0, 1, 0, 43, 31 },
  { 1329, 2, 0, 1, 0, 43, 31 },
  { 1401, 2, 0, 1, 0, 43, 31 },
  { 1705, 2, 0, 1, 0, 43, 31 },
  { 2301, 2, 0, 1, 0, 43, 31 },
  { 3282, 2, 0, 1, 0, 43, 31 },
  { 3641, 2, 0, 1, 0, 43, 31 },
  // 590: convert_double3, convert_double3_rte, convert_double3_rtn, convert_double3_rtp, convert_double3_rtz, 
  { 971, 2, 0, 1, 0, 43, 31 },
  { 1043, 2, 0, 1, 0, 43, 31 },
  { 1115, 2, 0, 1, 0, 43, 31 },
  { 1187, 2, 0, 1, 0, 43, 31 },
  { 1259, 2, 0, 1, 0, 43, 31 },
  { 1331, 2, 0, 1, 0, 43, 31 },
  { 1403, 2, 0, 1, 0, 43, 31 },
  { 1707, 2, 0, 1, 0, 43, 31 },
  { 2337, 2, 0, 1, 0, 43, 31 },
  { 3322, 2, 0, 1, 0, 43, 31 },
  { 3643, 2, 0, 1, 0, 43, 31 },
  // 601: convert_double4, convert_double4_rte, convert_double4_rtn, convert_double4_rtp, convert_double4_rtz, 
  { 973, 2, 0, 1, 0, 43, 31 },
  { 1045, 2, 0, 1, 0, 43, 31 },
  { 1117, 2, 0, 1, 0, 43, 31 },
  { 1189, 2, 0, 1, 0, 43, 31 },
  { 1261, 2, 0, 1, 0, 43, 31 },
  { 1333, 2, 0, 1, 0, 43, 31 },
  { 1405, 2, 0, 1, 0, 43, 31 },
  { 1723, 2, 0, 1, 0, 43, 31 },
  { 2374, 2, 0, 1, 0, 43, 31 },
  { 3336, 2, 0, 1, 0, 43, 31 },
  { 3645, 2, 0, 1, 0, 43, 31 },
  // 612: convert_double8, convert_double8_rte, convert_double8_rtn, convert_double8_rtp, convert_double8_rtz, 
  { 975, 2, 0, 1, 0, 43, 31 },
  { 1047, 2, 0, 1, 0, 43, 31 },
  { 1119, 2, 0, 1, 0, 43, 31 },
  { 1191, 2, 0, 1, 0, 43, 31 },
  { 1263, 2, 0, 1, 0, 43, 31 },
  { 1335, 2, 0, 1, 0, 43, 31 },
  { 1407, 2, 0, 1, 0, 43, 31 },
  { 1728, 2, 0, 1, 0, 43, 31 },
  { 2412, 2, 0, 1, 0, 43, 31 },
  { 3353, 2, 0, 1, 0, 43, 31 },
  { 3659, 2, 0, 1, 0, 43, 31 },
  // 623: convert_double16, convert_double16_rte, convert_double16_rtn, convert_double16_rtp, convert_double16_rtz, 
  { 987, 2, 0, 1, 0, 43, 31 },
  { 1059, 2, 0, 1, 0, 43, 31 },
  { 1131, 2, 0, 1, 0, 43, 31 },
  { 1203, 2, 0, 1, 0, 43, 31 },
  { 1275, 2, 0, 1, 0, 43, 31 },
  { 1347, 2, 0, 1, 0, 43, 31 },
  { 1412, 2, 0, 1, 0, 43, 31 },
  { 1730, 2, 0, 1, 0, 43, 31 },
  { 2449, 2, 0, 1, 0, 43, 31 },
  { 3385, 2, 0, 1, 0, 43, 31 },
  { 3683, 2, 0, 1, 0, 43, 31 },
  // 634: convert_long, convert_long_rte, convert_long_rtn, convert_long_rtp, convert_long_rtz, convert_long_sat, convert_long_sat_rte, convert_long_sat_rtn, convert_long_sat_rtp, convert_long_sat_rtz, 
  { 1087, 2, 0, 1, 0, 43, 31 },
  { 1099, 2, 0, 1, 0, 43, 31 },
  { 1121, 2, 0, 1, 0, 43, 31 },
  { 1135, 2, 0, 1, 0, 43, 31 },
  { 1147, 2, 0, 1, 0, 43, 31 },
  { 1159, 2, 0, 1, 0, 43, 31 },
  { 1171, 2, 0, 1, 0, 43, 31 },
  { 1193, 2, 0, 1, 0, 43, 31 },
  { 1207, 2, 0, 1, 0, 43, 31 },
  { 1219, 2, 0, 1, 0, 43, 31 },
  { 1231, 2, 0, 1, 0, 43, 31 },
  // 645: convert_long2, convert_long2_rte, convert_long2_rtn, convert_long2_rtp, convert_long2_rtz, convert_long2_sat, convert_long2_sat_rte, convert_long2_sat_rtn, convert_long2_sat_rtp, convert_long2_sat_rtz, 
  { 1089, 2, 0, 1, 0, 43, 31 },
  { 1101, 2, 0, 1, 0, 43, 31 },
  { 1123, 2, 0, 1, 0, 43, 31 },
  { 1137, 2, 0, 1, 0, 43, 31 },
  { 1149, 2, 0, 1, 0, 43, 31 },
  { 1161, 2, 0, 1, 0, 43, 31 },
  { 1173, 2, 0, 1, 0, 43, 31 },
  { 1195, 2, 0, 1, 0, 43, 31 },
  { 1209, 2, 0, 1, 0, 43, 31 },
  { 1221, 2, 0, 1, 0, 43, 31 },
  { 1233, 2, 0, 1, 0, 43, 31 },
  // 656: convert_long3, convert_long3_rte, convert_long3_rtn, convert_long3_rtp, convert_long3_rtz, convert_long3_sat, convert_long3_sat_rte, convert_long3_sat_rtn, convert_long3_sat_rtp, convert_long3_sat_rtz, 
  { 1091, 2, 0, 1, 0, 43, 31 },
  { 1103, 2, 0, 1, 0, 43, 31 },
  { 1125, 2, 0, 1, 0, 43, 31 },
  { 1139, 2, 0, 1, 0, 43, 31 },
  { 1151, 2, 0, 1, 0, 43, 31 },
  { 1163, 2, 0, 1, 0, 43, 31 },
  { 1175, 2, 0, 1, 0, 43, 31 },
  { 1197, 2, 0, 1, 0, 43, 31 },
  { 1211, 2, 0, 1, 0, 43, 31 },
  { 1223, 2, 0, 1, 0, 43, 31 },
  { 1235, 2, 0, 1, 0, 43, 31 },
  // 667: convert_long4, convert_long4_rte, convert_long4_rtn, convert_long4_rtp, convert_long4_rtz, convert_long4_sat, convert_long4_sat_rte, convert_long4_sat_rtn, convert_long4_sat_rtp, convert_long4_sat_rtz, 
  { 1093, 2, 0, 1, 0, 43, 31 },
  { 1105, 2, 0, 1, 0, 43, 31 },
  { 1127, 2, 0, 1, 0, 43, 31 },
  { 1141, 2, 0, 1, 0, 43, 31 },
  { 1153, 2, 0, 1, 0, 43, 31 },
  { 1165, 2, 0, 1, 0, 43, 31 },
  { 1177, 2, 0, 1, 0, 43, 31 },
  { 1199, 2, 0, 1, 0, 43, 31 },
  { 1213, 2, 0, 1, 0, 43, 31 },
  { 1225, 2, 0, 1, 0, 43, 31 },
  { 1237, 2, 0, 1, 0, 43, 31 },
  // 678: convert_long8, convert_long8_rte, convert_long8_rtn, convert_long8_rtp, convert_long8_rtz, convert_long8_sat, convert_long8_sat_rte, convert_long8_sat_rtn, convert_long8_sat_rtp, convert_long8_sat_rtz, 
  { 1095, 2, 0, 1, 0, 43, 31 },
  { 1107, 2, 0, 1, 0, 43, 31 },
  { 1129, 2, 0, 1, 0, 43, 31 },
  { 1143, 2, 0, 1, 0, 43, 31 },
  { 1155, 2, 0, 1, 0, 43, 31 },
  { 1167, 2, 0, 1, 0, 43, 31 },
  { 1179, 2, 0, 1, 0, 43, 31 },
  { 1201, 2, 0, 1, 0, 43, 31 },
  { 1215, 2, 0, 1, 0, 43, 31 },
  { 1227, 2, 0, 1, 0, 43, 31 },
  { 1239, 2, 0, 1, 0, 43, 31 },
  // 689: convert_long16, convert_long16_rte, convert_long16_rtn, convert_long16_rtp, convert_long16_rtz, convert_long16_sat, convert_long16_sat_rte, convert_long16_sat_rtn, convert_long16_sat_rtp, convert_long16_sat_rtz, 
  { 1097, 2, 0, 1, 0, 43, 31 },
  { 1109, 2, 0, 1, 0, 43, 31 },
  { 1133, 2, 0, 1, 0, 43, 31 },
  { 1145, 2, 0, 1, 0, 43, 31 },
  { 1157, 2, 0, 1, 0, 43, 31 },
  { 1169, 2, 0, 1, 0, 43, 31 },
  { 1181, 2, 0, 1, 0, 43, 31 },
  { 1205, 2, 0, 1, 0, 43, 31 },
  { 1217, 2, 0, 1, 0, 43, 31 },
  { 1229, 2, 0, 1, 0, 43, 31 },
  { 1241, 2, 0, 1, 0, 43, 31 },
  // 700: convert_ulong, convert_ulong_rte, convert_ulong_rtn, convert_ulong_rtp, convert_ulong_rtz, convert_ulong_sat, convert_ulong_sat_rte, convert_ulong_sat_rtn, convert_ulong_sat_rtp, convert_ulong_sat_rtz, 
  { 1243, 2, 0, 1, 0, 43, 31 },
  { 1265, 2, 0, 1, 0, 43, 31 },
  { 1279, 2, 0, 1, 0, 43, 31 },
  { 1291, 2, 0, 1, 0, 43, 31 },
  { 1303, 2, 0, 1, 0, 43, 31 },
  { 1315, 2, 0, 1, 0, 43, 31 },
  { 1337, 2, 0, 1, 0, 43, 31 },
  { 1351, 2, 0, 1, 0, 43, 31 },
  { 1363, 2, 0, 1, 0, 43, 31 },
  { 1375, 2, 0, 1, 0, 43, 31 },
  { 1387, 2, 0, 1, 0, 43, 31 },
  // 711: convert_ulong2, convert_ulong2_rte, convert_ulong2_rtn, convert_ulong2_rtp, convert_ulong2_rtz, convert_ulong2_sat, convert_ulong2_sat_rte, convert_ulong2_sat_rtn, convert_ulong2_sat_rtp, convert_ulong2_sat_rtz, 
  { 1245, 2, 0, 1, 0, 43, 31 },
  { 1267, 2, 0, 1, 0, 43, 31 },
  { 1281, 2, 0, 1, 0, 43, 31 },
  { 1293, 2, 0, 1, 0, 43, 31 },
  { 1305, 2, 0, 1, 0, 43, 31 },
  { 1317, 2, 0, 1, 0, 43, 31 },
  { 1339, 2, 0, 1, 0, 43, 31 },
  { 1353, 2, 0, 1, 0, 43, 31 },
  { 1365, 2, 0, 1, 0, 43, 31 },
  { 1377, 2, 0, 1, 0, 43, 31 },
  { 1389, 2, 0, 1, 0, 43, 31 },
  // 722: convert_ulong3, convert_ulong3_rte, convert_ulong3_rtn, convert_ulong3_rtp, convert_ulong3_rtz, convert_ulong3_sat, convert_ulong3_sat_rte, convert_ulong3_sat_rtn, convert_ulong3_sat_rtp, convert_ulong3_sat_rtz, 
  { 1247, 2, 0, 1, 0, 43, 31 },
  { 1269, 2, 0, 1, 0, 43, 31 },
  { 1283, 2, 0, 1, 0, 43, 31 },
  { 1295, 2, 0, 1, 0, 43, 31 },
  { 1307, 2, 0, 1, 0, 43, 31 },
  { 1319, 2, 0, 1, 0, 43, 31 },
  { 1341, 2, 0, 1, 0, 43, 31 },
  { 1355, 2, 0, 1, 0, 43, 31 },
  { 1367, 2, 0, 1, 0, 43, 31 },
  { 1379, 2, 0, 1, 0, 43, 31 },
  { 1391, 2, 0, 1, 0, 43, 31 },
  // 733: convert_ulong4, convert_ulong4_rte, convert_ulong4_rtn, convert_ulong4_rtp, convert_ulong4_rtz, convert_ulong4_sat, convert_ulong4_sat_rte, convert_ulong4_sat_rtn, convert_ulong4_sat_rtp, convert_ulong4_sat_rtz, 
  { 1249, 2, 0, 1, 0, 43, 31 },
  { 1271, 2, 0, 1, 0, 43, 31 },
  { 1285, 2, 0, 1, 0, 43, 31 },
  { 1297, 2, 0, 1, 0, 43, 31 },
  { 1309, 2, 0, 1, 0, 43, 31 },
  { 1321, 2, 0, 1, 0, 43, 31 },
  { 1343, 2, 0, 1, 0, 43, 31 },
  { 1357, 2, 0, 1, 0, 43, 31 },
  { 1369, 2, 0, 1, 0, 43, 31 },
  { 1381, 2, 0, 1, 0, 43, 31 },
  { 1393, 2, 0, 1, 0, 43, 31 },
  // 744: convert_ulong8, convert_ulong8_rte, convert_ulong8_rtn, convert_ulong8_rtp, convert_ulong8_rtz, convert_ulong8_sat, convert_ulong8_sat_rte, convert_ulong8_sat_rtn, convert_ulong8_sat_rtp, convert_ulong8_sat_rtz, 
  { 1251, 2, 0, 1, 0, 43, 31 },
  { 1273, 2, 0, 1, 0, 43, 31 },
  { 1287, 2, 0, 1, 0, 43, 31 },
  { 1299, 2, 0, 1, 0, 43, 31 },
  { 1311, 2, 0, 1, 0, 43, 31 },
  { 1323, 2, 0, 1, 0, 43, 31 },
  { 1345, 2, 0, 1, 0, 43, 31 },
  { 1359, 2, 0, 1, 0, 43, 31 },
  { 1371, 2, 0, 1, 0, 43, 31 },
  { 1383, 2, 0, 1, 0, 43, 31 },
  { 1395, 2, 0, 1, 0, 43, 31 },
  // 755: convert_ulong16, convert_ulong16_rte, convert_ulong16_rtn, convert_ulong16_rtp, convert_ulong16_rtz, convert_ulong16_sat, convert_ulong16_sat_rte, convert_ulong16_sat_rtn, convert_ulong16_sat_rtp, convert_ulong16_sat_rtz, 
  { 1253, 2, 0, 1, 0, 43, 31 },
  { 1277, 2, 0, 1, 0, 43, 31 },
  { 1289, 2, 0, 1, 0, 43, 31 },
  { 1301, 2, 0, 1, 0, 43, 31 },
  { 1313, 2, 0, 1, 0, 43, 31 },
  { 1325, 2, 0, 1, 0, 43, 31 },
  { 1349, 2, 0, 1, 0, 43, 31 },
  { 1361, 2, 0, 1, 0, 43, 31 },
  { 1373, 2, 0, 1, 0, 43, 31 },
  { 1385, 2, 0, 1, 0, 43, 31 },
  { 1397, 2, 0, 1, 0, 43, 31 },
  // 766: get_work_dim, 
  { 1409, 1, 0, 1, 0, 43, 31 },
  // 767: get_global_size, get_global_id, get_local_size, get_local_id, get_num_groups, get_group_id, get_global_offset, 
  { 1410, 2, 0, 1, 0, 43, 31 },
  // 768: get_enqueued_local_size, 
  { 1410, 2, 0, 0, 0, 43, 24 },
  // 769: get_global_linear_id, get_local_linear_id, 
  { 1414, 1, 0, 0, 0, 43, 24 },
  // 770: acos, acosh, acospi, asin, asinh, asinpi, atan, atanh, atanpi, cbrt, ceil, cos, cosh, cospi, erfc, erf, exp, exp2, exp10, expm1, fabs, floor, log, log2, log10, log1p, logb, rint, round, rsqrt, sin, sinh, sinpi, sqrt, tan, tanh, tanpi, tgamma, trunc, lgamma, degrees, radians, sign, 
  { 1415, 2, 0, 1, 0, 43, 31 },
  // 771: nan, 
  { 1417, 2, 0, 1, 0, 43, 31 },
  { 1419, 2, 0, 1, 0, 43, 31 },
  { 1421, 2, 0, 1, 0, 43, 31 },
  // 774: atan2, atan2pi, copysign, fdim, fmod, hypot, maxmag, minmag, nextafter, pow, powr, remainder, 
  { 1423, 3, 0, 1, 0, 43, 31 },
  // 775: fmax, fmin, 
  { 1423, 3, 0, 1, 0, 43, 31 },
  { 1426, 3, 0, 1, 0, 43, 31 },
  { 1429, 3, 0, 1, 0, 43, 31 },
  { 1432, 3, 0, 1, 0, 43, 31 },
  // 779: ilogb, 
  { 1435, 2, 0, 1, 0, 43, 31 },
  { 1437, 2, 0, 1, 0, 43, 31 },
  { 1439, 2, 0, 1, 0, 43, 31 },
  // 782: ldexp, 
  { 1441, 3, 0, 1, 0, 43, 31 },
  { 1444, 3, 0, 1, 0, 43, 31 },
  { 1447, 3, 0, 1, 0, 43, 31 },
  { 1450, 3, 0, 1, 0, 43, 31 },
  { 1453, 3, 0, 1, 0, 43, 31 },
  { 1456, 3, 0, 1, 0, 43, 31 },
  // 788: pown, rootn, 
  { 1441, 3, 0, 1, 0, 43, 31 },
  { 1447, 3, 0, 1, 0, 43, 31 },
  { 1453, 3, 0, 1, 0, 43, 31 },
  // 791: fma, mad, 
  { 1459, 4, 0, 1, 0, 43, 31 },
  // 792: fract, modf, sincos, 
  { 1463, 3, 0, 0, 0, 46, 31 },
  { 1487, 3, 0, 0, 0, 46, 31 },
  { 1511, 3, 0, 0, 0, 46, 31 },
  { 1535, 3, 0, 0, 0, 45, 31 },
  // 796: frexp, lgamma_r, 
  { 1466, 3, 0, 0, 0, 46, 31 },
  { 1473, 3, 0, 0, 0, 46, 31 },
  { 1476, 3, 0, 0, 0, 46, 31 },
  { 1490, 3, 0, 0, 0, 46, 31 },
  { 1493, 3, 0, 0, 0, 46, 31 },
  { 1496, 3, 0, 0, 0, 46, 31 },
  { 1514, 3, 0, 0, 0, 46, 31 },
  { 1517, 3, 0, 0, 0, 46, 31 },
  { 1520, 3, 0, 0, 0, 46, 31 },
  { 1538, 3, 0, 0, 0, 45, 31 },
  { 1541, 3, 0, 0, 0, 45, 31 },
  { 1544, 3, 0, 0, 0, 45, 31 },
  // 808: remquo, 
  { 1469, 4, 0, 0, 0, 46, 31 },
  { 1479, 4, 0, 0, 0, 46, 31 },
  { 1483, 4, 0, 0, 0, 46, 31 },
  { 1499, 4, 0, 0, 0, 46, 31 },
  { 1503, 4, 0, 0, 0, 46, 31 },
  { 1507, 4, 0, 0, 0, 46, 31 },
  { 1523, 4, 0, 0, 0, 46, 31 },
  { 1527, 4, 0, 0, 0, 46, 31 },
  { 1531, 4, 0, 0, 0, 46, 31 },
  { 1547, 4, 0, 0, 0, 45, 31 },
  { 1551, 4, 0, 0, 0, 45, 31 },
  { 1555, 4, 0, 0, 0, 45, 31 },
  // 820: half_cos, half_exp, half_exp2, half_exp10, half_log, half_log2, half_log10, half_recip, half_rsqrt, half_sin, half_sqrt, half_tan, native_cos, native_exp, native_exp2, native_exp10, native_log, native_log2, native_log10, native_recip, native_rsqrt, native_sin, native_sqrt, native_tan, 
  { 1559, 2, 0, 1, 0, 43, 31 },
  // 821: half_divide, half_powr, native_divide, native_powr, 
  { 1561, 3, 0, 1, 0, 43, 31 },
  // 822: abs, 
  { 1564, 2, 0, 1, 0, 43, 31 },
  // 823: clz, 
  { 48, 2, 0, 1, 0, 43, 31 },
  // 824: popcount, 
  { 48, 2, 0, 1, 0, 43, 28 },
  // 825: ctz, 
  { 48, 2, 0, 1, 0, 43, 24 },
  // 826: abs_diff, 
  { 1566, 3, 0, 1, 0, 43, 31 },
  // 827: add_sat, hadd, rhadd, mul_hi, rotate, sub_sat, 
  { 1569, 3, 0, 1, 0, 43, 31 },
  // 828: max, min, 
  { 1569, 3, 0, 1, 0, 43, 31 },
  { 1572, 3, 0, 1, 0, 43, 31 },
  { 1423, 3, 0, 1, 0, 43, 31 },
  { 1426, 3, 0, 1, 0, 43, 31 },
  { 1429, 3, 0, 1, 0, 43, 31 },
  { 1432, 3, 0, 1, 0, 43, 31 },
  // 834: upsample, 
  { 1575, 3, 0, 1, 0, 43, 31 },
  { 1578, 3, 0, 1, 0, 43, 31 },
  { 1581, 3, 0, 1, 0, 43, 31 },
  { 1584, 3, 0, 1, 0, 43, 31 },
  { 1587, 3, 0, 1, 0, 43, 31 },
  { 1590, 3, 0, 1, 0, 43, 31 },
  // 840: clamp, 
  { 1593, 4, 0, 1, 0, 43, 31 },
  { 1597, 4, 0, 1, 0, 43, 31 },
  { 1459, 4, 0, 1, 0, 43, 31 },
  { 1624, 4, 0, 1, 0, 43, 31 },
  { 1628, 4, 0, 1, 0, 43, 31 },
  { 1632, 4, 0, 1, 0, 43, 31 },
  // 846: mad_hi, mad_sat, 
  { 1593, 4, 0, 1, 0, 43, 31 },
  // 847: mad24, 
  { 1601, 4, 0, 1, 0, 43, 31 },
  { 1605, 4, 0, 1, 0, 43, 31 },
  // 849: mul24, 
  { 1609, 3, 0, 1, 0, 43, 31 },
  { 1612, 3, 0, 1, 0, 43, 31 },
  // 851: step, 
  { 1423, 3, 0, 1, 0, 43, 31 },
  { 1615, 3, 0, 1, 0, 43, 31 },
  { 1618, 3, 0, 1, 0, 43, 31 },
  { 1621, 3, 0, 1, 0, 43, 31 },
  // 855: mix, 
  { 1459, 4, 0, 1, 0, 43, 31 },
  { 1636, 4, 0, 1, 0, 43, 31 },
  { 1640, 4, 0, 1, 0, 43, 31 },
  { 1644, 4, 0, 1, 0, 43, 31 },
  // 859: smoothstep, 
  { 1459, 4, 0, 1, 0, 43, 31 },
  { 1648, 4, 0, 1, 0, 43, 31 },
  { 1652, 4, 0, 1, 0, 43, 31 },
  { 1656, 4, 0, 1, 0, 43, 31 },
  // 863: length, 
  { 1660, 2, 0, 1, 0, 43, 31 },
  { 1662, 2, 0, 1, 0, 43, 31 },
  { 1664, 2, 0, 1, 0, 43, 31 },
  // 866: normalize, 
  { 1666, 2, 0, 1, 0, 43, 31 },
  { 1668, 2, 0, 1, 0, 43, 31 },
  { 1670, 2, 0, 1, 0, 43, 31 },
  // 869: fast_length, 
  { 1660, 2, 0, 1, 0, 43, 31 },
  // 870: fast_normalize, 
  { 1666, 2, 0, 1, 0, 43, 31 },
  // 871: cross, 
  { 1672, 3, 0, 1, 0, 43, 31 },
  { 1675, 3, 0, 1, 0, 43, 31 },
  { 1678, 3, 0, 1, 0, 43, 31 },
  { 1681, 3, 0, 1, 0, 43, 31 },
  { 1684, 3, 0, 1, 0, 43, 31 },
  { 1687, 3, 0, 1, 0, 43, 31 },
  // 877: distance, 
  { 1690, 3, 0, 1, 0, 43, 31 },
  { 1693, 3, 0, 1, 0, 43, 31 },
  { 1696, 3, 0, 1, 0, 43, 31 },
  // 880: fast_distance, 
  { 1690, 3, 0, 1, 0, 43, 31 },
  // 881: isfinite, isinf, isnan, isnormal, signbit, 
  { 1435, 2, 0, 1, 0, 43, 31 },
  { 789, 2, 0, 1, 0, 43, 31 },
  { 1701, 2, 0, 1, 0, 43, 31 },
  { 805, 2, 0, 1, 0, 43, 31 },
  { 1703, 2, 0, 1, 0, 43, 31 },
  // 886: any, all, 
  { 1709, 2, 0, 1, 0, 43, 31 },
  // 887: isequal, isnotequal, isgreater, isgreaterequal, isless, islessequal, islessgreater, isordered, isunordered, 
  { 1711, 3, 0, 1, 0, 43, 31 },
  { 1714, 3, 0, 1, 0, 43, 31 },
  { 1717, 3, 0, 1, 0, 43, 31 },
  { 1720, 3, 0, 1, 0, 43, 31 },
  { 1725, 3, 0, 1, 0, 43, 31 },
  // 892: bitselect, 
  { 1732, 4, 0, 1, 0, 43, 31 },
  // 893: select, 
  { 1736, 4, 0, 1, 0, 43, 31 },
  { 1740, 4, 0, 1, 0, 43, 31 },
  { 1744, 4, 0, 1, 0, 43, 31 },
  { 1748, 4, 0, 1, 0, 43, 31 },
  { 1752, 4, 0, 1, 0, 43, 31 },
  { 1756, 4, 0, 1, 0, 43, 31 },
  { 1760, 4, 0, 1, 0, 43, 31 },
  { 1764, 4, 0, 1, 0, 43, 31 },
  { 1768, 4, 0, 1, 0, 43, 31 },
  { 1772, 4, 0, 1, 0, 43, 31 },
  // 903: vload2, 
  { 1776, 3, 1, 0, 0, 46, 31 },
  { 1779, 3, 1, 0, 0, 46, 31 },
  { 1782, 3, 1, 0, 0, 46, 31 },
  { 1785, 3, 1, 0, 0, 46, 31 },
  { 1788, 3, 1, 0, 0, 46, 31 },
  { 1791, 3, 1, 0, 0, 46, 31 },
  { 1794, 3, 1, 0, 0, 46, 31 },
  { 1797, 3, 1, 0, 0, 46, 31 },
  { 1800, 3, 1, 0, 0, 46, 31 },
  { 1803, 3, 1, 0, 0, 46, 31 },
  { 1806, 3, 1, 0, 0, 46, 31 },
  { 2161, 3, 1, 0, 0, 46, 31 },
  { 2164, 3, 1, 0, 0, 46, 31 },
  { 2167, 3, 1, 0, 0, 46, 31 },
  { 2170, 3, 1, 0, 0, 46, 31 },
  { 2173, 3, 1, 0, 0, 46, 31 },
  { 2176, 3, 1, 0, 0, 46, 31 },
  { 2179, 3, 1, 0, 0, 46, 31 },
  { 2182, 3, 1, 0, 0, 46, 31 },
  { 2185, 3, 1, 0, 0, 46, 31 },
  { 2188, 3, 1, 0, 0, 46, 31 },
  { 2191, 3, 1, 0, 0, 46, 31 },
  { 2560, 3, 1, 0, 0, 46, 31 },
  { 2563, 3, 1, 0, 0, 46, 31 },
  { 2566, 3, 1, 0, 0, 46, 31 },
  { 2569, 3, 1, 0, 0, 46, 31 },
  { 2572, 3, 1, 0, 0, 46, 31 },
  { 2575, 3, 1, 0, 0, 46, 31 },
  { 2578, 3, 1, 0, 0, 46, 31 },
  { 2581, 3, 1, 0, 0, 46, 31 },
  { 2584, 3, 1, 0, 0, 46, 31 },
  { 2587, 3, 1, 0, 0, 46, 31 },
  { 2590, 3, 1, 0, 0, 46, 31 },
  { 2945, 3, 1, 0, 0, 45, 31 },
  { 2948, 3, 1, 0, 0, 45, 31 },
  { 2951, 3, 1, 0, 0, 45, 31 },
  { 2954, 3, 1, 0, 0, 45, 31 },
  { 2957, 3, 1, 0, 0, 45, 31 },
  { 2960, 3, 1, 0, 0, 45, 31 },
  { 2963, 3, 1, 0, 0, 45, 31 },
  { 2966, 3, 1, 0, 0, 45, 31 },
  { 2969, 3, 1, 0, 0, 45, 31 },
  { 2972, 3, 1, 0, 0, 45, 31 },
  { 2975, 3, 1, 0, 0, 45, 31 },
  { 3338, 3, 1, 0, 0, 43, 31 },
  { 3341, 3, 1, 0, 0, 43, 31 },
  { 3344, 3, 1, 0, 0, 43, 31 },
  { 3347, 3, 1, 0, 0, 43, 31 },
  { 3350, 3, 1, 0, 0, 43, 31 },
  { 3355, 3, 1, 0, 0, 43, 31 },
  { 3358, 3, 1, 0, 0, 43, 31 },
  { 3361, 3, 1, 0, 0, 43, 31 },
  { 3364, 3, 1, 0, 0, 43, 31 },
  { 3367, 3, 1, 0, 0, 43, 31 },
  { 3370, 3, 1, 0, 0, 43, 31 },
  // 958: vstore2, 
  { 1809, 4, 0, 0, 0, 46, 31 },
  { 1813, 4, 0, 0, 0, 46, 31 },
  { 1817, 4, 0, 0, 0, 46, 31 },
  { 1821, 4, 0, 0, 0, 46, 31 },
  { 1825, 4, 0, 0, 0, 46, 31 },
  { 1829, 4, 0, 0, 0, 46, 31 },
  { 1833, 4, 0, 0, 0, 46, 31 },
  { 1837, 4, 0, 0, 0, 46, 31 },
  { 1841, 4, 0, 0, 0, 46, 31 },
  { 1845, 4, 0, 0, 0, 46, 31 },
  { 1849, 4, 0, 0, 0, 46, 31 },
  { 2194, 4, 0, 0, 0, 46, 31 },
  { 2198, 4, 0, 0, 0, 46, 31 },
  { 2202, 4, 0, 0, 0, 46, 31 },
  { 2206, 4, 0, 0, 0, 46, 31 },
  { 2210, 4, 0, 0, 0, 46, 31 },
  { 2214, 4, 0, 0, 0, 46, 31 },
  { 2218, 4, 0, 0, 0, 46, 31 },
  { 2222, 4, 0, 0, 0, 46, 31 },
  { 2226, 4, 0, 0, 0, 46, 31 },
  { 2230, 4, 0, 0, 0, 46, 31 },
  { 2234, 4, 0, 0, 0, 46, 31 },
  { 2593, 4, 0, 0, 0, 46, 31 },
  { 2597, 4, 0, 0, 0, 46, 31 },
  { 2601, 4, 0, 0, 0, 46, 31 },
  { 2605, 4, 0, 0, 0, 46, 31 },
  { 2609, 4, 0, 0, 0, 46, 31 },
  { 2613, 4, 0, 0, 0, 46, 31 },
  { 2617, 4, 0, 0, 0, 46, 31 },
  { 2621, 4, 0, 0, 0, 46, 31 },
  { 2625, 4, 0, 0, 0, 46, 31 },
  { 2629, 4, 0, 0, 0, 46, 31 },
  { 2633, 4, 0, 0, 0, 46, 31 },
  { 2978, 4, 0, 0, 0, 45, 31 },
  { 2982, 4, 0, 0, 0, 45, 31 },
  { 2986, 4, 0, 0, 0, 45, 31 },
  { 2990, 4, 0, 0, 0, 45, 31 },
  { 2994, 4, 0, 0, 0, 45, 31 },
  { 2998, 4, 0, 0, 0, 45, 31 },
  { 3002, 4, 0, 0, 0, 45, 31 },
  { 3006, 4, 0, 0, 0, 45, 31 },
  { 3010, 4, 0, 0, 0, 45, 31 },
  { 3014, 4, 0, 0, 0, 45, 31 },
  { 3018, 4, 0, 0, 0, 45, 31 },
  // 1002: vload3, 
  { 1853, 3, 1, 0, 0, 46, 31 },
  { 1856, 3, 1, 0, 0, 46, 31 },
  { 1859, 3, 1, 0, 0, 46, 31 },
  { 1862, 3, 1, 0, 0, 46, 31 },
  { 1865, 3, 1, 0, 0, 46, 31 },
  { 1868, 3, 1, 0, 0, 46, 31 },
  { 1871, 3, 1, 0, 0, 46, 31 },
  { 1874, 3, 1, 0, 0, 46, 31 },
  { 1877, 3, 1, 0, 0, 46, 31 },
  { 1880, 3, 1, 0, 0, 46, 31 },
  { 1883, 3, 1, 0, 0, 46, 31 },
  { 2238, 3, 1, 0, 0, 46, 31 },
  { 2241, 3, 1, 0, 0, 46, 31 },
  { 2244, 3, 1, 0, 0, 46, 31 },
  { 2247, 3, 1, 0, 0, 46, 31 },
  { 2250, 3, 1, 0, 0, 46, 31 },
  { 2253, 3, 1, 0, 0, 46, 31 },
  { 2256, 3, 1, 0, 0, 46, 31 },
  { 2259, 3, 1, 0, 0, 46, 31 },
  { 2264, 3, 1, 0, 0, 46, 31 },
  { 2267, 3, 1, 0, 0, 46, 31 },
  { 2270, 3, 1, 0, 0, 46, 31 },
  { 2637, 3, 1, 0, 0, 46, 31 },
  { 2640, 3, 1, 0, 0, 46, 31 },
  { 2643, 3, 1, 0, 0, 46, 31 },
  { 2646, 3, 1, 0, 0, 46, 31 },
  { 2649, 3, 1, 0, 0, 46, 31 },
  { 2652, 3, 1, 0, 0, 46, 31 },
  { 2655, 3, 1, 0, 0, 46, 31 },
  { 2658, 3, 1, 0, 0, 46, 31 },
  { 2661, 3, 1, 0, 0, 46, 31 },
  { 2664, 3, 1, 0, 0, 46, 31 },
  { 2667, 3, 1, 0, 0, 46, 31 },
  { 3022, 3, 1, 0, 0, 45, 31 },
  { 3025, 3, 1, 0, 0, 45, 31 },
  { 3028, 3, 1, 0, 0, 45, 31 },
  { 3031, 3, 1, 0, 0, 45, 31 },
  { 3034, 3, 1, 0, 0, 45, 31 },
  { 3037, 3, 1, 0, 0, 45, 31 },
  { 3040, 3, 1, 0, 0, 45, 31 },
  { 3043, 3, 1, 0, 0, 45, 31 },
  { 3046, 3, 1, 0, 0, 45, 31 },
  { 3049, 3, 1, 0, 0, 45, 31 },
  { 3052, 3, 1, 0, 0, 45, 31 },
  { 3373, 3, 1, 0, 0, 43, 31 },
  { 3376, 3, 1, 0, 0, 43, 31 },
  { 3379, 3, 1, 0, 0, 43, 31 },
  { 3382, 3, 1, 0, 0, 43, 31 },
  { 3387, 3, 1, 0, 0, 43, 31 },
  { 3390, 3, 1, 0, 0, 43, 31 },
  { 3393, 3, 1, 0, 0, 43, 31 },
  { 3396, 3, 1, 0, 0, 43, 31 },
  { 3399, 3, 1, 0, 0, 43, 31 },
  { 3402, 3, 1, 0, 0, 43, 31 },
  { 3405, 3, 1, 0, 0, 43, 31 },
  // 1057: vstore3, 
  { 1886, 4, 0, 0, 0, 46, 31 },
  { 1890, 4, 0, 0, 0, 46, 31 },
  { 1894, 4, 0, 0, 0, 46, 31 },
  { 1898, 4, 0, 0, 0, 46, 31 },
  { 1902, 4, 0, 0, 0, 46, 31 },
  { 1906, 4, 0, 0, 0, 46, 31 },
  { 1910, 4, 0, 0, 0, 46, 31 },
  { 1914, 4, 0, 0, 0, 46, 31 },
  { 1918, 4, 0, 0, 0, 46, 31 },
  { 1922, 4, 0, 0, 0, 46, 31 },
  { 1926, 4, 0, 0, 0, 46, 31 },
  { 2273, 4, 0, 0, 0, 46, 31 },
  { 2277, 4, 0, 0, 0, 46, 31 },
  { 2281, 4, 0, 0, 0, 46, 31 },
  { 2285, 4, 0, 0, 0, 46, 31 },
  { 2289, 4, 0, 0, 0, 46, 31 },
  { 2293, 4, 0, 0, 0, 46, 31 },
  { 2297, 4, 0, 0, 0, 46, 31 },
  { 2303, 4, 0, 0, 0, 46, 31 },
  { 2307, 4, 0, 0, 0, 46, 31 },
  { 2311, 4, 0, 0, 0, 46, 31 },
  { 2315, 4, 0, 0, 0, 46, 31 },
  { 2670, 4, 0, 0, 0, 46, 31 },
  { 2674, 4, 0, 0, 0, 46, 31 },
  { 2678, 4, 0, 0, 0, 46, 31 },
  { 2682, 4, 0, 0, 0, 46, 31 },
  { 2686, 4, 0, 0, 0, 46, 31 },
  { 2690, 4, 0, 0, 0, 46, 31 },
  { 2694, 4, 0, 0, 0, 46, 31 },
  { 2698, 4, 0, 0, 0, 46, 31 },
  { 2702, 4, 0, 0, 0, 46, 31 },
  { 2706, 4, 0, 0, 0, 46, 31 },
  { 2710, 4, 0, 0, 0, 46, 31 },
  { 3055, 4, 0, 0, 0, 45, 31 },
  { 3059, 4, 0, 0, 0, 45, 31 },
  { 3063, 4, 0, 0, 0, 45, 31 },
  { 3067, 4, 0, 0, 0, 45, 31 },
  { 3071, 4, 0, 0, 0, 45, 31 },
  { 3075, 4, 0, 0, 0, 45, 31 },
  { 3079, 4, 0, 0, 0, 45, 31 },
  { 3083, 4, 0, 0, 0, 45, 31 },
  { 3087, 4, 0, 0, 0, 45, 31 },
  { 3091, 4, 0, 0, 0, 45, 31 },
  { 3095, 4, 0, 0, 0, 45, 31 },
  // 1101: vload4, 
  { 1930, 3, 1, 0, 0, 46, 31 },
  { 1933, 3, 1, 0, 0, 46, 31 },
  { 1936, 3, 1, 0, 0, 46, 31 },
  { 1939, 3, 1, 0, 0, 46, 31 },
  { 1942, 3, 1, 0, 0, 46, 31 },
  { 1945, 3, 1, 0, 0, 46, 31 },
  { 1948, 3, 1, 0, 0, 46, 31 },
  { 1951, 3, 1, 0, 0, 46, 31 },
  { 1954, 3, 1, 0, 0, 46, 31 },
  { 1957, 3, 1, 0, 0, 46, 31 },
  { 1960, 3, 1, 0, 0, 46, 31 },
  { 2319, 3, 1, 0, 0, 46, 31 },
  { 2322, 3, 1, 0, 0, 46, 31 },
  { 2325, 3, 1, 0, 0, 46, 31 },
  { 2328, 3, 1, 0, 0, 46, 31 },
  { 2331, 3, 1, 0, 0, 46, 31 },
  { 2334, 3, 1, 0, 0, 46, 31 },
  { 2339, 3, 1, 0, 0, 46, 31 },
  { 2342, 3, 1, 0, 0, 46, 31 },
  { 2345, 3, 1, 0, 0, 46, 31 },
  { 2348, 3, 1, 0, 0, 46, 31 },
  { 2351, 3, 1, 0, 0, 46, 31 },
  { 2714, 3, 1, 0, 0, 46, 31 },
  { 2717, 3, 1, 0, 0, 46, 31 },
  { 2720, 3, 1, 0, 0, 46, 31 },
  { 2723, 3, 1, 0, 0, 46, 31 },
  { 2726, 3, 1, 0, 0, 46, 31 },
  { 2729, 3, 1, 0, 0, 46, 31 },
  { 2732, 3, 1, 0, 0, 46, 31 },
  { 2735, 3, 1, 0, 0, 46, 31 },
  { 2738, 3, 1, 0, 0, 46, 31 },
  { 2741, 3, 1, 0, 0, 46, 31 },
  { 2744, 3, 1, 0, 0, 46, 31 },
  { 3099, 3, 1, 0, 0, 45, 31 },
  { 3102, 3, 1, 0, 0, 45, 31 },
  { 3105, 3, 1, 0, 0, 45, 31 },
  { 3108, 3, 1, 0, 0, 45, 31 },
  { 3111, 3, 1, 0, 0, 45, 31 },
  { 3114, 3, 1, 0, 0, 45, 31 },
  { 3117, 3, 1, 0, 0, 45, 31 },
  { 3120, 3, 1, 0, 0, 45, 31 },
  { 3123, 3, 1, 0, 0, 45, 31 },
  { 3126, 3, 1, 0, 0, 45, 31 },
  { 3129, 3, 1, 0, 0, 45, 31 },
  { 3408, 3, 1, 0, 0, 43, 31 },
  { 3411, 3, 1, 0, 0, 43, 31 },
  { 3414, 3, 1, 0, 0, 43, 31 },
  { 3417, 3, 1, 0, 0, 43, 31 },
  { 3420, 3, 1, 0, 0, 43, 31 },
  { 3423, 3, 1, 0, 0, 43, 31 },
  { 3426, 3, 1, 0, 0, 43, 31 },
  { 3429, 3, 1, 0, 0, 43, 31 },
  { 3432, 3, 1, 0, 0, 43, 31 },
  { 3435, 3, 1, 0, 0, 43, 31 },
  { 3438, 3, 1, 0, 0, 43, 31 },
  // 1156: vstore4, 
  { 1963, 4, 0, 0, 0, 46, 31 },
  { 1967, 4, 0, 0, 0, 46, 31 },
  { 1971, 4, 0, 0, 0, 46, 31 },
  { 1975, 4, 0, 0, 0, 46, 31 },
  { 1979, 4, 0, 0, 0, 46, 31 },
  { 1983, 4, 0, 0, 0, 46, 31 },
  { 1987, 4, 0, 0, 0, 46, 31 },
  { 1991, 4, 0, 0, 0, 46, 31 },
  { 1995, 4, 0, 0, 0, 46, 31 },
  { 1999, 4, 0, 0, 0, 46, 31 },
  { 2003, 4, 0, 0, 0, 46, 31 },
  { 2354, 4, 0, 0, 0, 46, 31 },
  { 2358, 4, 0, 0, 0, 46, 31 },
  { 2362, 4, 0, 0, 0, 46, 31 },
  { 2366, 4, 0, 0, 0, 46, 31 },
  { 2370, 4, 0, 0, 0, 46, 31 },
  { 2376, 4, 0, 0, 0, 46, 31 },
  { 2380, 4, 0, 0, 0, 46, 31 },
  { 2384, 4, 0, 0, 0, 46, 31 },
  { 2388, 4, 0, 0, 0, 46, 31 },
  { 2392, 4, 0, 0, 0, 46, 31 },
  { 2396, 4, 0, 0, 0, 46, 31 },
  { 2747, 4, 0, 0, 0, 46, 31 },
  { 2751, 4, 0, 0, 0, 46, 31 },
  { 2755, 4, 0, 0, 0, 46, 31 },
  { 2759, 4, 0, 0, 0, 46, 31 },
  { 2763, 4, 0, 0, 0, 46, 31 },
  { 2767, 4, 0, 0, 0, 46, 31 },
  { 2771, 4, 0, 0, 0, 46, 31 },
  { 2775, 4, 0, 0, 0, 46, 31 },
  { 2779, 4, 0, 0, 0, 46, 31 },
  { 2783, 4, 0, 0, 0, 46, 31 },
  { 2787, 4, 0, 0, 0, 46, 31 },
  { 3132, 4, 0, 0, 0, 45, 31 },
  { 3136, 4, 0, 0, 0, 45, 31 },
  { 3140, 4, 0, 0, 0, 45, 31 },
  { 3144, 4, 0, 0, 0, 45, 31 },
  { 3148, 4, 0, 0, 0, 45, 31 },
  { 3152, 4, 0, 0, 0, 45, 31 },
  { 3156, 4, 0, 0, 0, 45, 31 },
  { 3160, 4, 0, 0, 0, 45, 31 },
  { 3164, 4, 0, 0, 0, 45, 31 },
  { 3168, 4, 0, 0, 0, 45, 31 },
  { 3172, 4, 0, 0, 0, 45, 31 },
  // 1200: vload8, 
  { 2007, 3, 1, 0, 0, 46, 31 },
  { 2010, 3, 1, 0, 0, 46, 31 },
  { 2013, 3, 1, 0, 0, 46, 31 },
  { 2016, 3, 1, 0, 0, 46, 31 },
  { 2019, 3, 1, 0, 0, 46, 31 },
  { 2022, 3, 1, 0, 0, 46, 31 },
  { 2025, 3, 1, 0, 0, 46, 31 },
  { 2028, 3, 1, 0, 0, 46, 31 },
  { 2031, 3, 1, 0, 0, 46, 31 },
  { 2034, 3, 1, 0, 0, 46, 31 },
  { 2037, 3, 1, 0, 0, 46, 31 },
  { 2400, 3, 1, 0, 0, 46, 31 },
  { 2403, 3, 1, 0, 0, 46, 31 },
  { 2406, 3, 1, 0, 0, 46, 31 },
  { 2409, 3, 1, 0, 0, 46, 31 },
  { 2414, 3, 1, 0, 0, 46, 31 },
  { 2417, 3, 1, 0, 0, 46, 31 },
  { 2420, 3, 1, 0, 0, 46, 31 },
  { 2423, 3, 1, 0, 0, 46, 31 },
  { 2426, 3, 1, 0, 0, 46, 31 },
  { 2429, 3, 1, 0, 0, 46, 31 },
  { 2432, 3, 1, 0, 0, 46, 31 },
  { 2791, 3, 1, 0, 0, 46, 31 },
  { 2794, 3, 1, 0, 0, 46, 31 },
  { 2797, 3, 1, 0, 0, 46, 31 },
  { 2800, 3, 1, 0, 0, 46, 31 },
  { 2803, 3, 1, 0, 0, 46, 31 },
  { 2806, 3, 1, 0, 0, 46, 31 },
  { 2809, 3, 1, 0, 0, 46, 31 },
  { 2812, 3, 1, 0, 0, 46, 31 },
  { 2815, 3, 1, 0, 0, 46, 31 },
  { 2818, 3, 1, 0, 0, 46, 31 },
  { 2821, 3, 1, 0, 0, 46, 31 },
  { 3176, 3, 1, 0, 0, 45, 31 },
  { 3179, 3, 1, 0, 0, 45, 31 },
  { 3182, 3, 1, 0, 0, 45, 31 },
  { 3185, 3, 1, 0, 0, 45, 31 },
  { 3188, 3, 1, 0, 0, 45, 31 },
  { 3191, 3, 1, 0, 0, 45, 31 },
  { 3194, 3, 1, 0, 0, 45, 31 },
  { 3197, 3, 1, 0, 0, 45, 31 },
  { 3200, 3, 1, 0, 0, 45, 31 },
  { 3203, 3, 1, 0, 0, 45, 31 },
  { 3206, 3, 1, 0, 0, 45, 31 },
  { 3441, 3, 1, 0, 0, 43, 31 },
  { 3444, 3, 1, 0, 0, 43, 31 },
  { 3447, 3, 1, 0, 0, 43, 31 },
  { 3450, 3, 1, 0, 0, 43, 31 },
  { 3453, 3, 1, 0, 0, 43, 31 },
  { 3456, 3, 1, 0, 0, 43, 31 },
  { 3459, 3, 1, 0, 0, 43, 31 },
  { 3462, 3, 1, 0, 0, 43, 31 },
  { 3465, 3, 1, 0, 0, 43, 31 },
  { 3468, 3, 1, 0, 0, 43, 31 },
  { 3471, 3, 1, 0, 0, 43, 31 },
  // 1255: vstore8, 
  { 2040, 4, 0, 0, 0, 46, 31 },
  { 2044, 4, 0, 0, 0, 46, 31 },
  { 2048, 4, 0, 0, 0, 46, 31 },
  { 2052, 4, 0, 0, 0, 46, 31 },
  { 2056, 4, 0, 0, 0, 46, 31 },
  { 2060, 4, 0, 0, 0, 46, 31 },
  { 2064, 4, 0, 0, 0, 46, 31 },
  { 2068, 4, 0, 0, 0, 46, 31 },
  { 2072, 4, 0, 0, 0, 46, 31 },
  { 2076, 4, 0, 0, 0, 46, 31 },
  { 2080, 4, 0, 0, 0, 46, 31 },
  { 2435, 4, 0, 0, 0, 46, 31 },
  { 2439, 4, 0, 0, 0, 46, 31 },
  { 2443, 4, 0, 0, 0, 46, 31 },
  { 2451, 4, 0, 0, 0, 46, 31 },
  { 2455, 4, 0, 0, 0, 46, 31 },
  { 2459, 4, 0, 0, 0, 46, 31 },
  { 2463, 4, 0, 0, 0, 46, 31 },
  { 2467, 4, 0, 0, 0, 46, 31 },
  { 2471, 4, 0, 0, 0, 46, 31 },
  { 2475, 4, 0, 0, 0, 46, 31 },
  { 2479, 4, 0, 0, 0, 46, 31 },
  { 2824, 4, 0, 0, 0, 46, 31 },
  { 2828, 4, 0, 0, 0, 46, 31 },
  { 2832, 4, 0, 0, 0, 46, 31 },
  { 2836, 4, 0, 0, 0, 46, 31 },
  { 2840, 4, 0, 0, 0, 46, 31 },
  { 2844, 4, 0, 0, 0, 46, 31 },
  { 2848, 4, 0, 0, 0, 46, 31 },
  { 2852, 4, 0, 0, 0, 46, 31 },
  { 2856, 4, 0, 0, 0, 46, 31 },
  { 2860, 4, 0, 0, 0, 46, 31 },
  { 2864, 4, 0, 0, 0, 46, 31 },
  { 3209, 4, 0, 0, 0, 45, 31 },
  { 3213, 4, 0, 0, 0, 45, 31 },
  { 3217, 4, 0, 0, 0, 45, 31 },
  { 3221, 4, 0, 0, 0, 45, 31 },
  { 3225, 4, 0, 0, 0, 45, 31 },
  { 3229, 4, 0, 0, 0, 45, 31 },
  { 3233, 4, 0, 0, 0, 45, 31 },
  { 3237, 4, 0, 0, 0, 45, 31 },
  { 3241, 4, 0, 0, 0, 45, 31 },
  { 3245, 4, 0, 0, 0, 45, 31 },
  { 3251, 4, 0, 0, 0, 45, 31 },
  // 1299: vload16, 
  { 2084, 3, 1, 0, 0, 46, 31 },
  { 2087, 3, 1, 0, 0, 46, 31 },
  { 2090, 3, 1, 0, 0, 46, 31 },
  { 2093, 3, 1, 0, 0, 46, 31 },
  { 2096, 3, 1, 0, 0, 46, 31 },
  { 2099, 3, 1, 0, 0, 46, 31 },
  { 2102, 3, 1, 0, 0, 46, 31 },
  { 2105, 3, 1, 0, 0, 46, 31 },
  { 2108, 3, 1, 0, 0, 46, 31 },
  { 2111, 3, 1, 0, 0, 46, 31 },
  { 2114, 3, 1, 0, 0, 46, 31 },
  { 2483, 3, 1, 0, 0, 46, 31 },
  { 2486, 3, 1, 0, 0, 46, 31 },
  { 2489, 3, 1, 0, 0, 46, 31 },
  { 2492, 3, 1, 0, 0, 46, 31 },
  { 2495, 3, 1, 0, 0, 46, 31 },
  { 2498, 3, 1, 0, 0, 46, 31 },
  { 2501, 3, 1, 0, 0, 46, 31 },
  { 2504, 3, 1, 0, 0, 46, 31 },
  { 2507, 3, 1, 0, 0, 46, 31 },
  { 2510, 3, 1, 0, 0, 46, 31 },
  { 2513, 3, 1, 0, 0, 46, 31 },
  { 2868, 3, 1, 0, 0, 46, 31 },
  { 2871, 3, 1, 0, 0, 46, 31 },
  { 2874, 3, 1, 0, 0, 46, 31 },
  { 2877, 3, 1, 0, 0, 46, 31 },
  { 2880, 3, 1, 0, 0, 46, 31 },
  { 2883, 3, 1, 0, 0, 46, 31 },
  { 2886, 3, 1, 0, 0, 46, 31 },
  { 2889, 3, 1, 0, 0, 46, 31 },
  { 2892, 3, 1, 0, 0, 46, 31 },
  { 2895, 3, 1, 0, 0, 46, 31 },
  { 2898, 3, 1, 0, 0, 46, 31 },
  { 3255, 3, 1, 0, 0, 45, 31 },
  { 3258, 3, 1, 0, 0, 45, 31 },
  { 3261, 3, 1, 0, 0, 45, 31 },
  { 3264, 3, 1, 0, 0, 45, 31 },
  { 3267, 3, 1, 0, 0, 45, 31 },
  { 3270, 3, 1, 0, 0, 45, 31 },
  { 3273, 3, 1, 0, 0, 45, 31 },
  { 3276, 3, 1, 0, 0, 45, 31 },
  { 3279, 3, 1, 0, 0, 45, 31 },
  { 3284, 3, 1, 0, 0, 45, 31 },
  { 3287, 3, 1, 0, 0, 45, 31 },
  { 3474, 3, 1, 0, 0, 43, 31 },
  { 3477, 3, 1, 0, 0, 43, 31 },
  { 3480, 3, 1, 0, 0, 43, 31 },
  { 3483, 3, 1, 0, 0, 43, 31 },
  { 3486, 3, 1, 0, 0, 43, 31 },
  { 3489, 3, 1, 0, 0, 43, 31 },
  { 3492, 3, 1, 0, 0, 43, 31 },
  { 3495, 3, 1, 0, 0, 43, 31 },
  { 3498, 3, 1, 0, 0, 43, 31 },
  { 3501, 3, 1, 0, 0, 43, 31 },
  { 3504, 3, 1, 0, 0, 43, 31 },
  // 1354: vstore16, 
  { 2117, 4, 0, 0, 0, 46, 31 },
  { 2121, 4, 0, 0, 0, 46, 31 },
  { 2125, 4, 0, 0, 0, 46, 31 },
  { 2129, 4, 0, 0, 0, 46, 31 },
  { 2133, 4, 0, 0, 0, 46, 31 },
  { 2137, 4, 0, 0, 0, 46, 31 },
  { 2141, 4, 0, 0, 0, 46, 31 },
  { 2145, 4, 0, 0, 0, 46, 31 },
  { 2149, 4, 0, 0, 0, 46, 31 },
  { 2153, 4, 0, 0, 0, 46, 31 },
  { 2157, 4, 0, 0, 0, 46, 31 },
  { 2516, 4, 0, 0, 0, 46, 31 },
  { 2520, 4, 0, 0, 0, 46, 31 },
  { 2524, 4, 0, 0, 0, 46, 31 },
  { 2528, 4, 0, 0, 0, 46, 31 },
  { 2532, 4, 0, 0, 0, 46, 31 },
  { 2536, 4, 0, 0, 0, 46, 31 },
  { 2540, 4, 0, 0, 0, 46, 31 },
  { 2544, 4, 0, 0, 0, 46, 31 },
  { 2548, 4, 0, 0, 0, 46, 31 },
  { 2552, 4, 0, 0, 0, 46, 31 },
  { 2556, 4, 0, 0, 0, 46, 31 },
  { 2901, 4, 0, 0, 0, 46, 31 },
  { 2905, 4, 0, 0, 0, 46, 31 },
  { 2909, 4, 0, 0, 0, 46, 31 },
  { 2913, 4, 0, 0, 0, 46, 31 },
  { 2917, 4, 0, 0, 0, 46, 31 },
  { 2921, 4, 0, 0, 0, 46, 31 },
  { 2925, 4, 0, 0, 0, 46, 31 },
  { 2929, 4, 0, 0, 0, 46, 31 },
  { 2933, 4, 0, 0, 0, 46, 31 },
  { 2937, 4, 0, 0, 0, 46, 31 },
  { 2941, 4, 0, 0, 0, 46, 31 },
  { 3290, 4, 0, 0, 0, 45, 31 },
  { 3294, 4, 0, 0, 0, 45, 31 },
  { 3298, 4, 0, 0, 0, 45, 31 },
  { 3302, 4, 0, 0, 0, 45, 31 },
  { 3306, 4, 0, 0, 0, 45, 31 },
  { 3310, 4, 0, 0, 0, 45, 31 },
  { 3314, 4, 0, 0, 0, 45, 31 },
  { 3318, 4, 0, 0, 0, 45, 31 },
  { 3324, 4, 0, 0, 0, 45, 31 },
  { 3328, 4, 0, 0, 0, 45, 31 },
  { 3332, 4, 0, 0, 0, 45, 31 },
  // 1398: vload_half, 
  { 3507, 3, 1, 0, 0, 46, 31 },
  { 3573, 3, 1, 0, 0, 46, 31 },
  { 3647, 3, 1, 0, 0, 46, 31 },
  { 3717, 3, 1, 0, 0, 45, 31 },
  { 3783, 3, 1, 0, 0, 43, 31 },
  // 1403: vload_half2, vloada_half2, 
  { 3510, 3, 1, 0, 0, 46, 31 },
  { 3576, 3, 1, 0, 0, 46, 31 },
  { 3650, 3, 1, 0, 0, 46, 31 },
  { 3720, 3, 1, 0, 0, 45, 31 },
  { 3786, 3, 1, 0, 0, 43, 31 },
  // 1408: vstore_half, vstore_half_rte, vstore_half_rtz, vstore_half_rtp, vstore_half_rtn, 
  { 3513, 4, 0, 0, 0, 46, 31 },
  { 3517, 4, 0, 0, 0, 46, 31 },
  { 3591, 4, 0, 0, 0, 46, 31 },
  { 3595, 4, 0, 0, 0, 46, 31 },
  { 3667, 4, 0, 0, 0, 46, 31 },
  { 3671, 4, 0, 0, 0, 46, 31 },
  { 3735, 4, 0, 0, 0, 45, 31 },
  { 3739, 4, 0, 0, 0, 45, 31 },
  // 1416: vstore_half2, vstorea_half2, vstore_half2_rte, vstorea_half2_rte, vstore_half2_rtz, vstorea_half2_rtz, vstore_half2_rtp, vstorea_half2_rtp, vstore_half2_rtn, vstorea_half2_rtn, 
  { 3521, 4, 0, 0, 0, 46, 31 },
  { 3525, 4, 0, 0, 0, 46, 31 },
  { 3599, 4, 0, 0, 0, 46, 31 },
  { 3603, 4, 0, 0, 0, 46, 31 },
  { 3675, 4, 0, 0, 0, 46, 31 },
  { 3679, 4, 0, 0, 0, 46, 31 },
  { 3743, 4, 0, 0, 0, 45, 31 },
  { 3747, 4, 0, 0, 0, 45, 31 },
  // 1424: vload_half3, vloada_half3, 
  { 3529, 3, 1, 0, 0, 46, 31 },
  { 3579, 3, 1, 0, 0, 46, 31 },
  { 3653, 3, 1, 0, 0, 46, 31 },
  { 3723, 3, 1, 0, 0, 45, 31 },
  { 3789, 3, 1, 0, 0, 43, 31 },
  // 1429: vload_half4, vloada_half4, 
  { 3532, 3, 1, 0, 0, 46, 31 },
  { 3582, 3, 1, 0, 0, 46, 31 },
  { 3656, 3, 1, 0, 0, 46, 31 },
  { 3726, 3, 1, 0, 0, 45, 31 },
  { 3792, 3, 1, 0, 0, 43, 31 },
  // 1434: vload_half8, vloada_half8, 
  { 3535, 3, 1, 0, 0, 46, 31 },
  { 3585, 3, 1, 0, 0, 46, 31 },
  { 3661, 3, 1, 0, 0, 46, 31 },
  { 3729, 3, 1, 0, 0, 45, 31 },
  { 3795, 3, 1, 0, 0, 43, 31 },
  // 1439: vload_half16, vloada_half16, 
  { 3538, 3, 1, 0, 0, 46, 31 },
  { 3588, 3, 1, 0, 0, 46, 31 },
  { 3664, 3, 1, 0, 0, 46, 31 },
  { 3732, 3, 1, 0, 0, 45, 31 },
  { 3798, 3, 1, 0, 0, 43, 31 },
  // 1444: vstore_half3, vstorea_half3, vstore_half3_rte, vstorea_half3_rte, vstore_half3_rtz, vstorea_half3_rtz, vstore_half3_rtp, vstorea_half3_rtp, vstore_half3_rtn, vstorea_half3_rtn, 
  { 3541, 4, 0, 0, 0, 46, 31 },
  { 3545, 4, 0, 0, 0, 46, 31 },
  { 3607, 4, 0, 0, 0, 46, 31 },
  { 3611, 4, 0, 0, 0, 46, 31 },
  { 3685, 4, 0, 0, 0, 46, 31 },
  { 3689, 4, 0, 0, 0, 46, 31 },
  { 3751, 4, 0, 0, 0, 45, 31 },
  { 3755, 4, 0, 0, 0, 45, 31 },
  // 1452: vstore_half4, vstorea_half4, vstore_half4_rte, vstorea_half4_rte, vstore_half4_rtz, vstorea_half4_rtz, vstore_half4_rtp, vstorea_half4_rtp, vstore_half4_rtn, vstorea_half4_rtn, 
  { 3549, 4, 0, 0, 0, 46, 31 },
  { 3553, 4, 0, 0, 0, 46, 31 },
  { 3615, 4, 0, 0, 0, 46, 31 },
  { 3619, 4, 0, 0, 0, 46, 31 },
  { 3693, 4, 0, 0, 0, 46, 31 },
  { 3697, 4, 0, 0, 0, 46, 31 },
  { 3759, 4, 0, 0, 0, 45, 31 },
  { 3763, 4, 0, 0, 0, 45, 31 },
  // 1460: vstore_half8, vstorea_half8, vstore_half8_rte, vstorea_half8_rte, vstore_half8_rtz, vstorea_half8_rtz, vstore_half8_rtp, vstorea_half8_rtp, vstore_half8_rtn, vstorea_half8_rtn, 
  { 3557, 4, 0, 0, 0, 46, 31 },
  { 3561, 4, 0, 0, 0, 46, 31 },
  { 3623, 4, 0, 0, 0, 46, 31 },
  { 3627, 4, 0, 0, 0, 46, 31 },
  { 3701, 4, 0, 0, 0, 46, 31 },
  { 3705, 4, 0, 0, 0, 46, 31 },
  { 3767, 4, 0, 0, 0, 45, 31 },
  { 3771, 4, 0, 0, 0, 45, 31 },
  // 1468: vstore_half16, vstorea_half16, vstore_half16_rte, vstorea_half16_rte, vstore_half16_rtz, vstorea_half16_rtz, vstore_half16_rtp, vstorea_half16_rtp, vstore_half16_rtn, vstorea_half16_rtn, 
  { 3565, 4, 0, 0, 0, 46, 31 },
  { 3569, 4, 0, 0, 0, 46, 31 },
  { 3631, 4, 0, 0, 0, 46, 31 },
  { 3635, 4, 0, 0, 0, 46, 31 },
  { 3709, 4, 0, 0, 0, 46, 31 },
  { 3713, 4, 0, 0, 0, 46, 31 },
  { 3775, 4, 0, 0, 0, 45, 31 },
  { 3779, 4, 0, 0, 0, 45, 31 },
  // 1476: barrier, 
  { 3801, 2, 0, 0, 1, 43, 31 },
  // 1477: work_group_barrier, 
  { 3801, 2, 0, 0, 1, 43, 24 },
  { 3803, 3, 0, 0, 1, 43, 24 },
  // 1479: mem_fence, read_mem_fence, write_mem_fence, 
  { 3801, 2, 0, 0, 0, 43, 31 },
  // 1480: get_fence, 
  { 3806, 2, 0, 0, 0, 45, 31 },
  { 3808, 2, 0, 0, 0, 45, 31 },
  // 1482: async_work_group_copy, 
  { 3810, 5, 0, 0, 0, 43, 31 },
  { 3817, 5, 0, 0, 0, 43, 31 },
  // 1484: async_work_group_strided_copy, 
  { 3822, 6, 0, 0, 0, 43, 31 },
  { 3828, 6, 0, 0, 0, 43, 31 },
  // 1486: wait_group_events, 
  { 3834, 3, 0, 0, 0, 43, 31 },
  // 1487: prefetch, 
  { 3839, 3, 0, 0, 0, 43, 31 },
  // 1488: atom_add, atom_sub, atom_xchg, 
  { 3842, 3, 0, 0, 0, 27, 31 },
  { 3853, 3, 0, 0, 0, 27, 31 },
  { 3862, 3, 0, 0, 0, 31, 31 },
  { 3873, 3, 0, 0, 0, 31, 31 },
  { 3884, 3, 0, 0, 0, 29, 31 },
  { 3895, 3, 0, 0, 0, 29, 31 },
  { 3904, 3, 0, 0, 0, 29, 31 },
  { 3913, 3, 0, 0, 0, 29, 31 },
  // 1496: atom_inc, atom_dec, 
  { 3845, 2, 0, 0, 0, 27, 31 },
  { 3856, 2, 0, 0, 0, 27, 31 },
  { 3865, 2, 0, 0, 0, 31, 31 },
  { 3876, 2, 0, 0, 0, 31, 31 },
  { 3887, 2, 0, 0, 0, 29, 31 },
  { 3898, 2, 0, 0, 0, 29, 31 },
  { 3907, 2, 0, 0, 0, 29, 31 },
  { 3916, 2, 0, 0, 0, 29, 31 },
  // 1504: atom_cmpxchg, 
  { 3847, 4, 0, 0, 0, 27, 31 },
  { 3858, 4, 0, 0, 0, 27, 31 },
  { 3867, 4, 0, 0, 0, 31, 31 },
  { 3880, 4, 0, 0, 0, 31, 31 },
  { 3889, 4, 0, 0, 0, 29, 31 },
  { 3900, 4, 0, 0, 0, 29, 31 },
  { 3909, 4, 0, 0, 0, 29, 31 },
  { 3918, 4, 0, 0, 0, 29, 31 },
  // 1512: atom_min, atom_max, atom_and, atom_or, atom_xor, 
  { 3842, 3, 0, 0, 0, 28, 31 },
  { 3853, 3, 0, 0, 0, 28, 31 },
  { 3862, 3, 0, 0, 0, 32, 31 },
  { 3873, 3, 0, 0, 0, 32, 31 },
  { 3884, 3, 0, 0, 0, 30, 31 },
  { 3895, 3, 0, 0, 0, 30, 31 },
  { 3904, 3, 0, 0, 0, 30, 31 },
  { 3913, 3, 0, 0, 0, 30, 31 },
  // 1520: atomic_xchg, 
  { 3922, 3, 0, 0, 0, 43, 31 },
  { 3842, 3, 0, 0, 0, 43, 31 },
  { 3853, 3, 0, 0, 0, 43, 31 },
  { 3925, 3, 0, 0, 0, 43, 31 },
  { 3862, 3, 0, 0, 0, 43, 31 },
  { 3873, 3, 0, 0, 0, 43, 31 },
  { 3928, 3, 0, 0, 0, 50, 31 },
  { 3937, 3, 0, 0, 0, 50, 31 },
  // 1528: atomic_add, atomic_sub, atomic_min, atomic_max, atomic_and, atomic_or, atomic_xor, 
  { 3842, 3, 0, 0, 0, 43, 31 },
  { 3853, 3, 0, 0, 0, 43, 31 },
  { 3862, 3, 0, 0, 0, 43, 31 },
  { 3873, 3, 0, 0, 0, 43, 31 },
  { 3928, 3, 0, 0, 0, 50, 31 },
  { 3937, 3, 0, 0, 0, 50, 31 },
  // 1534: atomic_inc, atomic_dec, 
  { 3845, 2, 0, 0, 0, 43, 31 },
  { 3856, 2, 0, 0, 0, 43, 31 },
  { 3865, 2, 0, 0, 0, 43, 31 },
  { 3876, 2, 0, 0, 0, 43, 31 },
  { 3931, 2, 0, 0, 0, 50, 31 },
  { 3940, 2, 0, 0, 0, 50, 31 },
  // 1540: atomic_cmpxchg, 
  { 3847, 4, 0, 0, 0, 43, 31 },
  { 3858, 4, 0, 0, 0, 43, 31 },
  { 3867, 4, 0, 0, 0, 43, 31 },
  { 3880, 4, 0, 0, 0, 43, 31 },
  { 3933, 4, 0, 0, 0, 50, 31 },
  { 3942, 4, 0, 0, 0, 50, 31 },
  // 1546: atomic_store, 
  { 3946, 3, 0, 0, 0, 54, 24 },
  { 4000, 3, 0, 0, 0, 54, 24 },
  { 4050, 3, 0, 0, 0, 54, 24 },
  { 4100, 3, 0, 0, 0, 54, 24 },
  { 4150, 3, 0, 0, 0, 54, 24 },
  { 4200, 3, 0, 0, 0, 54, 24 },
  { 4292, 3, 0, 0, 0, 56, 24 },
  { 4376, 3, 0, 0, 0, 56, 24 },
  { 4460, 3, 0, 0, 0, 56, 24 },
  { 4544, 3, 0, 0, 0, 56, 24 },
  { 4628, 3, 0, 0, 0, 56, 24 },
  { 4712, 3, 0, 0, 0, 56, 24 },
  { 4838, 3, 0, 0, 0, 56, 24 },
  { 4922, 3, 0, 0, 0, 56, 24 },
  { 5006, 3, 0, 0, 0, 56, 24 },
  { 5090, 3, 0, 0, 0, 56, 24 },
  { 5174, 3, 0, 0, 0, 56, 24 },
  { 5258, 3, 0, 0, 0, 56, 24 },
  { 5384, 3, 0, 0, 0, 58, 24 },
  { 5417, 3, 0, 0, 0, 72, 24 },
  { 5450, 3, 0, 0, 0, 86, 24 },
  // 1567: atomic_store_explicit, 
  { 3949, 4, 0, 0, 0, 55, 24 },
  { 3953, 5, 0, 0, 0, 45, 24 },
  { 4003, 4, 0, 0, 0, 55, 24 },
  { 4007, 5, 0, 0, 0, 45, 24 },
  { 4053, 4, 0, 0, 0, 55, 24 },
  { 4057, 5, 0, 0, 0, 45, 24 },
  { 4103, 4, 0, 0, 0, 55, 24 },
  { 4107, 5, 0, 0, 0, 45, 24 },
  { 4153, 4, 0, 0, 0, 55, 24 },
  { 4157, 5, 0, 0, 0, 45, 24 },
  { 4203, 4, 0, 0, 0, 55, 24 },
  { 4207, 5, 0, 0, 0, 45, 24 },
  { 4295, 4, 0, 0, 0, 57, 24 },
  { 4299, 5, 0, 0, 0, 46, 24 },
  { 4379, 4, 0, 0, 0, 57, 24 },
  { 4383, 5, 0, 0, 0, 46, 24 },
  { 4463, 4, 0, 0, 0, 57, 24 },
  { 4467, 5, 0, 0, 0, 46, 24 },
  { 4547, 4, 0, 0, 0, 57, 24 },
  { 4551, 5, 0, 0, 0, 46, 24 },
  { 4631, 4, 0, 0, 0, 57, 24 },
  { 4635, 5, 0, 0, 0, 46, 24 },
  { 4715, 4, 0, 0, 0, 57, 24 },
  { 4719, 5, 0, 0, 0, 46, 24 },
  { 4841, 4, 0, 0, 0, 57, 24 },
  { 4845, 5, 0, 0, 0, 46, 24 },
  { 4925, 4, 0, 0, 0, 57, 24 },
  { 4929, 5, 0, 0, 0, 46, 24 },
  { 5009, 4, 0, 0, 0, 57, 24 },
  { 5013, 5, 0, 0, 0, 46, 24 },
  { 5093, 4, 0, 0, 0, 57, 24 },
  { 5097, 5, 0, 0, 0, 46, 24 },
  { 5177, 4, 0, 0, 0, 57, 24 },
  { 5181, 5, 0, 0, 0, 46, 24 },
  { 5261, 4, 0, 0, 0, 57, 24 },
  { 5265, 5, 0, 0, 0, 46, 24 },
  { 5387, 4, 0, 0, 0, 59, 24 },
  { 5391, 5, 0, 0, 0, 8, 24 },
  { 5420, 4, 0, 0, 0, 73, 24 },
  { 5424, 5, 0, 0, 0, 11, 24 },
  { 5453, 4, 0, 0, 0, 87, 24 },
  { 5457, 5, 0, 0, 0, 5, 24 },
  // 1609: atomic_init, 
  { 3946, 3, 0, 0, 0, 45, 24 },
  { 4000, 3, 0, 0, 0, 45, 24 },
  { 4050, 3, 0, 0, 0, 45, 24 },
  { 4100, 3, 0, 0, 0, 45, 24 },
  { 4150, 3, 0, 0, 0, 45, 24 },
  { 4200, 3, 0, 0, 0, 45, 24 },
  { 4292, 3, 0, 0, 0, 46, 24 },
  { 4376, 3, 0, 0, 0, 46, 24 },
  { 4460, 3, 0, 0, 0, 46, 24 },
  { 4544, 3, 0, 0, 0, 46, 24 },
  { 4628, 3, 0, 0, 0, 46, 24 },
  { 4712, 3, 0, 0, 0, 46, 24 },
  { 4838, 3, 0, 0, 0, 46, 24 },
  { 4922, 3, 0, 0, 0, 46, 24 },
  { 5006, 3, 0, 0, 0, 46, 24 },
  { 5090, 3, 0, 0, 0, 46, 24 },
  { 5174, 3, 0, 0, 0, 46, 24 },
  { 5258, 3, 0, 0, 0, 46, 24 },
  // 1627: atomic_compare_exchange_weak, atomic_compare_exchange_strong, 
  { 3958, 4, 0, 0, 0, 54, 24 },
  { 4033, 4, 0, 0, 0, 54, 24 },
  { 4083, 4, 0, 0, 0, 54, 24 },
  { 4133, 4, 0, 0, 0, 54, 24 },
  { 4183, 4, 0, 0, 0, 54, 24 },
  { 4235, 4, 0, 0, 0, 54, 24 },
  { 4325, 4, 0, 0, 0, 56, 24 },
  { 4342, 4, 0, 0, 0, 56, 24 },
  { 4359, 4, 0, 0, 0, 56, 24 },
  { 4409, 4, 0, 0, 0, 56, 24 },
  { 4426, 4, 0, 0, 0, 56, 24 },
  { 4443, 4, 0, 0, 0, 56, 24 },
  { 4493, 4, 0, 0, 0, 56, 24 },
  { 4510, 4, 0, 0, 0, 56, 24 },
  { 4527, 4, 0, 0, 0, 56, 24 },
  { 4577, 4, 0, 0, 0, 56, 24 },
  { 4594, 4, 0, 0, 0, 56, 24 },
  { 4611, 4, 0, 0, 0, 56, 24 },
  { 4661, 4, 0, 0, 0, 56, 24 },
  { 4678, 4, 0, 0, 0, 56, 24 },
  { 4695, 4, 0, 0, 0, 56, 24 },
  { 4745, 4, 0, 0, 0, 56, 24 },
  { 4762, 4, 0, 0, 0, 56, 24 },
  { 4779, 4, 0, 0, 0, 56, 24 },
  { 4871, 4, 0, 0, 0, 56, 24 },
  { 4888, 4, 0, 0, 0, 56, 24 },
  { 4905, 4, 0, 0, 0, 56, 24 },
  { 4955, 4, 0, 0, 0, 56, 24 },
  { 4972, 4, 0, 0, 0, 56, 24 },
  { 4989, 4, 0, 0, 0, 56, 24 },
  { 5039, 4, 0, 0, 0, 56, 24 },
  { 5056, 4, 0, 0, 0, 56, 24 },
  { 5073, 4, 0, 0, 0, 56, 24 },
  { 5123, 4, 0, 0, 0, 56, 24 },
  { 5140, 4, 0, 0, 0, 56, 24 },
  { 5157, 4, 0, 0, 0, 56, 24 },
  { 5207, 4, 0, 0, 0, 56, 24 },
  { 5224, 4, 0, 0, 0, 56, 24 },
  { 5241, 4, 0, 0, 0, 56, 24 },
  { 5291, 4, 0, 0, 0, 56, 24 },
  { 5308, 4, 0, 0, 0, 56, 24 },
  { 5325, 4, 0, 0, 0, 56, 24 },
  // 1669: atomic_compare_exchange_weak_explicit, atomic_compare_exchange_strong_explicit, 
  { 3962, 6, 0, 0, 0, 55, 24 },
  { 3968, 7, 0, 0, 0, 45, 24 },
  { 4037, 6, 0, 0, 0, 55, 24 },
  { 4043, 7, 0, 0, 0, 45, 24 },
  { 4087, 6, 0, 0, 0, 55, 24 },
  { 4093, 7, 0, 0, 0, 45, 24 },
  { 4137, 6, 0, 0, 0, 55, 24 },
  { 4143, 7, 0, 0, 0, 45, 24 },
  { 4187, 6, 0, 0, 0, 55, 24 },
  { 4193, 7, 0, 0, 0, 45, 24 },
  { 4239, 6, 0, 0, 0, 55, 24 },
  { 4245, 7, 0, 0, 0, 45, 24 },
  { 4329, 6, 0, 0, 0, 57, 24 },
  { 4335, 7, 0, 0, 0, 46, 24 },
  { 4346, 6, 0, 0, 0, 57, 24 },
  { 4352, 7, 0, 0, 0, 46, 24 },
  { 4363, 6, 0, 0, 0, 57, 24 },
  { 4369, 7, 0, 0, 0, 46, 24 },
  { 4413, 6, 0, 0, 0, 57, 24 },
  { 4419, 7, 0, 0, 0, 46, 24 },
  { 4430, 6, 0, 0, 0, 57, 24 },
  { 4436, 7, 0, 0, 0, 46, 24 },
  { 4447, 6, 0, 0, 0, 57, 24 },
  { 4453, 7, 0, 0, 0, 46, 24 },
  { 4497, 6, 0, 0, 0, 57, 24 },
  { 4503, 7, 0, 0, 0, 46, 24 },
  { 4514, 6, 0, 0, 0, 57, 24 },
  { 4520, 7, 0, 0, 0, 46, 24 },
  { 4531, 6, 0, 0, 0, 57, 24 },
  { 4537, 7, 0, 0, 0, 46, 24 },
  { 4581, 6, 0, 0, 0, 57, 24 },
  { 4587, 7, 0, 0, 0, 46, 24 },
  { 4598, 6, 0, 0, 0, 57, 24 },
  { 4604, 7, 0, 0, 0, 46, 24 },
  { 4615, 6, 0, 0, 0, 57, 24 },
  { 4621, 7, 0, 0, 0, 46, 24 },
  { 4665, 6, 0, 0, 0, 57, 24 },
  { 4671, 7, 0, 0, 0, 46, 24 },
  { 4682, 6, 0, 0, 0, 57, 24 },
  { 4688, 7, 0, 0, 0, 46, 24 },
  { 4699, 6, 0, 0, 0, 57, 24 },
  { 4705, 7, 0, 0, 0, 46, 24 },
  { 4749, 6, 0, 0, 0, 57, 24 },
  { 4755, 7, 0, 0, 0, 46, 24 },
  { 4766, 6, 0, 0, 0, 57, 24 },
  { 4772, 7, 0, 0, 0, 46, 24 },
  { 4783, 6, 0, 0, 0, 57, 24 },
  { 4789, 7, 0, 0, 0, 46, 24 },
  { 4875, 6, 0, 0, 0, 57, 24 },
  { 4881, 7, 0, 0, 0, 46, 24 },
  { 4892, 6, 0, 0, 0, 57, 24 },
  { 4898, 7, 0, 0, 0, 46, 24 },
  { 4909, 6, 0, 0, 0, 57, 24 },
  { 4915, 7, 0, 0, 0, 46, 24 },
  { 4959, 6, 0, 0, 0, 57, 24 },
  { 4965, 7, 0, 0, 0, 46, 24 },
  { 4976, 6, 0, 0, 0, 57, 24 },
  { 4982, 7, 0, 0, 0, 46, 24 },
  { 4993, 6, 0, 0, 0, 57, 24 },
  { 4999, 7, 0, 0, 0, 46, 24 },
  { 5043, 6, 0, 0, 0, 57, 24 },
  { 5049, 7, 0, 0, 0, 46, 24 },
  { 5060, 6, 0, 0, 0, 57, 24 },
  { 5066, 7, 0, 0, 0, 46, 24 },
  { 5077, 6, 0, 0, 0, 57, 24 },
  { 5083, 7, 0, 0, 0, 46, 24 },
  { 5127, 6, 0, 0, 0, 57, 24 },
  { 5133, 7, 0, 0, 0, 46, 24 },
  { 5144, 6, 0, 0, 0, 57, 24 },
  { 5150, 7, 0, 0, 0, 46, 24 },
  { 5161, 6, 0, 0, 0, 57, 24 },
  { 5167, 7, 0, 0, 0, 46, 24 },
  { 5211, 6, 0, 0, 0, 57, 24 },
  { 5217, 7, 0, 0, 0, 46, 24 },
  { 5228, 6, 0, 0, 0, 57, 24 },
  { 5234, 7, 0, 0, 0, 46, 24 },
  { 5245, 6, 0, 0, 0, 57, 24 },
  { 5251, 7, 0, 0, 0, 46, 24 },
  { 5295, 6, 0, 0, 0, 57, 24 },
  { 5301, 7, 0, 0, 0, 46, 24 },
  { 5312, 6, 0, 0, 0, 57, 24 },
  { 5318, 7, 0, 0, 0, 46, 24 },
  { 5329, 6, 0, 0, 0, 57, 24 },
  { 5335, 7, 0, 0, 0, 46, 24 },
  // 1753: atomic_work_item_fence, 
  { 3975, 4, 0, 0, 0, 43, 24 },
  // 1754: atomic_load, 
  { 3979, 2, 0, 0, 0, 54, 24 },
  { 4012, 2, 0, 0, 0, 54, 24 },
  { 4062, 2, 0, 0, 0, 54, 24 },
  { 4112, 2, 0, 0, 0, 54, 24 },
  { 4162, 2, 0, 0, 0, 54, 24 },
  { 4212, 2, 0, 0, 0, 54, 24 },
  { 4304, 2, 0, 0, 0, 56, 24 },
  { 4388, 2, 0, 0, 0, 56, 24 },
  { 4472, 2, 0, 0, 0, 56, 24 },
  { 4556, 2, 0, 0, 0, 56, 24 },
  { 4640, 2, 0, 0, 0, 56, 24 },
  { 4724, 2, 0, 0, 0, 56, 24 },
  { 4850, 2, 0, 0, 0, 56, 24 },
  { 4934, 2, 0, 0, 0, 56, 24 },
  { 5018, 2, 0, 0, 0, 56, 24 },
  { 5102, 2, 0, 0, 0, 56, 24 },
  { 5186, 2, 0, 0, 0, 56, 24 },
  { 5270, 2, 0, 0, 0, 56, 24 },
  { 5396, 2, 0, 0, 0, 58, 24 },
  { 5429, 2, 0, 0, 0, 72, 24 },
  { 5462, 2, 0, 0, 0, 86, 24 },
  // 1775: atomic_load_explicit, 
  { 3981, 3, 0, 0, 0, 55, 24 },
  { 3984, 4, 0, 0, 0, 45, 24 },
  { 4014, 3, 0, 0, 0, 55, 24 },
  { 4017, 4, 0, 0, 0, 45, 24 },
  { 4064, 3, 0, 0, 0, 55, 24 },
  { 4067, 4, 0, 0, 0, 45, 24 },
  { 4114, 3, 0, 0, 0, 55, 24 },
  { 4117, 4, 0, 0, 0, 45, 24 },
  { 4164, 3, 0, 0, 0, 55, 24 },
  { 4167, 4, 0, 0, 0, 45, 24 },
  { 4214, 3, 0, 0, 0, 55, 24 },
  { 4217, 4, 0, 0, 0, 45, 24 },
  { 4306, 3, 0, 0, 0, 57, 24 },
  { 4309, 4, 0, 0, 0, 46, 24 },
  { 4390, 3, 0, 0, 0, 57, 24 },
  { 4393, 4, 0, 0, 0, 46, 24 },
  { 4474, 3, 0, 0, 0, 57, 24 },
  { 4477, 4, 0, 0, 0, 46, 24 },
  { 4558, 3, 0, 0, 0, 57, 24 },
  { 4561, 4, 0, 0, 0, 46, 24 },
  { 4642, 3, 0, 0, 0, 57, 24 },
  { 4645, 4, 0, 0, 0, 46, 24 },
  { 4726, 3, 0, 0, 0, 57, 24 },
  { 4729, 4, 0, 0, 0, 46, 24 },
  { 4852, 3, 0, 0, 0, 57, 24 },
  { 4855, 4, 0, 0, 0, 46, 24 },
  { 4936, 3, 0, 0, 0, 57, 24 },
  { 4939, 4, 0, 0, 0, 46, 24 },
  { 5020, 3, 0, 0, 0, 57, 24 },
  { 5023, 4, 0, 0, 0, 46, 24 },
  { 5104, 3, 0, 0, 0, 57, 24 },
  { 5107, 4, 0, 0, 0, 46, 24 },
  { 5188, 3, 0, 0, 0, 57, 24 },
  { 5191, 4, 0, 0, 0, 46, 24 },
  { 5272, 3, 0, 0, 0, 57, 24 },
  { 5275, 4, 0, 0, 0, 46, 24 },
  { 5398, 3, 0, 0, 0, 59, 24 },
  { 5401, 4, 0, 0, 0, 8, 24 },
  { 5431, 3, 0, 0, 0, 73, 24 },
  { 5434, 4, 0, 0, 0, 11, 24 },
  { 5464, 3, 0, 0, 0, 87, 24 },
  { 5467, 4, 0, 0, 0, 5, 24 },
  // 1817: atomic_exchange, atomic_fetch_min, atomic_fetch_max, 
  { 3988, 3, 0, 0, 0, 54, 24 },
  { 4021, 3, 0, 0, 0, 54, 24 },
  { 4071, 3, 0, 0, 0, 54, 24 },
  { 4121, 3, 0, 0, 0, 54, 24 },
  { 4171, 3, 0, 0, 0, 54, 24 },
  { 4223, 3, 0, 0, 0, 54, 24 },
  { 4313, 3, 0, 0, 0, 56, 24 },
  { 4397, 3, 0, 0, 0, 56, 24 },
  { 4481, 3, 0, 0, 0, 56, 24 },
  { 4565, 3, 0, 0, 0, 56, 24 },
  { 4649, 3, 0, 0, 0, 56, 24 },
  { 4733, 3, 0, 0, 0, 56, 24 },
  { 4859, 3, 0, 0, 0, 56, 24 },
  { 4943, 3, 0, 0, 0, 56, 24 },
  { 5027, 3, 0, 0, 0, 56, 24 },
  { 5111, 3, 0, 0, 0, 56, 24 },
  { 5195, 3, 0, 0, 0, 56, 24 },
  { 5279, 3, 0, 0, 0, 56, 24 },
  { 5405, 3, 0, 0, 0, 58, 24 },
  { 5438, 3, 0, 0, 0, 72, 24 },
  { 5471, 3, 0, 0, 0, 86, 24 },
  // 1838: atomic_exchange_explicit, atomic_fetch_min_explicit, atomic_fetch_max_explicit, 
  { 3991, 4, 0, 0, 0, 55, 24 },
  { 3995, 5, 0, 0, 0, 45, 24 },
  { 4024, 4, 0, 0, 0, 55, 24 },
  { 4028, 5, 0, 0, 0, 45, 24 },
  { 4074, 4, 0, 0, 0, 55, 24 },
  { 4078, 5, 0, 0, 0, 45, 24 },
  { 4124, 4, 0, 0, 0, 55, 24 },
  { 4128, 5, 0, 0, 0, 45, 24 },
  { 4174, 4, 0, 0, 0, 55, 24 },
  { 4178, 5, 0, 0, 0, 45, 24 },
  { 4226, 4, 0, 0, 0, 55, 24 },
  { 4230, 5, 0, 0, 0, 45, 24 },
  { 4316, 4, 0, 0, 0, 57, 24 },
  { 4320, 5, 0, 0, 0, 46, 24 },
  { 4400, 4, 0, 0, 0, 57, 24 },
  { 4404, 5, 0, 0, 0, 46, 24 },
  { 4484, 4, 0, 0, 0, 57, 24 },
  { 4488, 5, 0, 0, 0, 46, 24 },
  { 4568, 4, 0, 0, 0, 57, 24 },
  { 4572, 5, 0, 0, 0, 46, 24 },
  { 4652, 4, 0, 0, 0, 57, 24 },
  { 4656, 5, 0, 0, 0, 46, 24 },
  { 4736, 4, 0, 0, 0, 57, 24 },
  { 4740, 5, 0, 0, 0, 46, 24 },
  { 4862, 4, 0, 0, 0, 57, 24 },
  { 4866, 5, 0, 0, 0, 46, 24 },
  { 4946, 4, 0, 0, 0, 57, 24 },
  { 4950, 5, 0, 0, 0, 46, 24 },
  { 5030, 4, 0, 0, 0, 57, 24 },
  { 5034, 5, 0, 0, 0, 46, 24 },
  { 5114, 4, 0, 0, 0, 57, 24 },
  { 5118, 5, 0, 0, 0, 46, 24 },
  { 5198, 4, 0, 0, 0, 57, 24 },
  { 5202, 5, 0, 0, 0, 46, 24 },
  { 5282, 4, 0, 0, 0, 57, 24 },
  { 5286, 5, 0, 0, 0, 46, 24 },
  { 5408, 4, 0, 0, 0, 59, 24 },
  { 5412, 5, 0, 0, 0, 8, 24 },
  { 5441, 4, 0, 0, 0, 73, 24 },
  { 5445, 5, 0, 0, 0, 11, 24 },
  { 5474, 4, 0, 0, 0, 87, 24 },
  { 5478, 5, 0, 0, 0, 5, 24 },
  // 1880: atomic_fetch_add, atomic_fetch_sub, 
  { 3988, 3, 0, 0, 0, 54, 24 },
  { 4021, 3, 0, 0, 0, 54, 24 },
  { 4071, 3, 0, 0, 0, 54, 24 },
  { 4121, 3, 0, 0, 0, 54, 24 },
  { 4258, 3, 0, 0, 0, 54, 24 },
  { 4313, 3, 0, 0, 0, 56, 24 },
  { 4397, 3, 0, 0, 0, 56, 24 },
  { 4481, 3, 0, 0, 0, 56, 24 },
  { 4565, 3, 0, 0, 0, 56, 24 },
  { 4800, 3, 0, 0, 0, 56, 24 },
  { 4859, 3, 0, 0, 0, 56, 24 },
  { 4943, 3, 0, 0, 0, 56, 24 },
  { 5027, 3, 0, 0, 0, 56, 24 },
  { 5111, 3, 0, 0, 0, 56, 24 },
  { 5342, 3, 0, 0, 0, 56, 24 },
  { 5405, 3, 0, 0, 0, 60, 24 },
  { 4649, 3, 0, 0, 0, 62, 24 },
  { 4733, 3, 0, 0, 0, 64, 24 },
  { 5438, 3, 0, 0, 0, 74, 24 },
  { 5195, 3, 0, 0, 0, 76, 24 },
  { 5279, 3, 0, 0, 0, 78, 24 },
  { 5471, 3, 0, 0, 0, 88, 24 },
  { 4171, 3, 0, 0, 0, 90, 24 },
  { 4223, 3, 0, 0, 0, 92, 24 },
  // 1904: atomic_fetch_add_explicit, atomic_fetch_sub_explicit, 
  { 3991, 4, 0, 0, 0, 55, 24 },
  { 3995, 5, 0, 0, 0, 45, 24 },
  { 4024, 4, 0, 0, 0, 55, 24 },
  { 4028, 5, 0, 0, 0, 45, 24 },
  { 4074, 4, 0, 0, 0, 55, 24 },
  { 4078, 5, 0, 0, 0, 45, 24 },
  { 4124, 4, 0, 0, 0, 55, 24 },
  { 4128, 5, 0, 0, 0, 45, 24 },
  { 4261, 4, 0, 0, 0, 55, 24 },
  { 4265, 5, 0, 0, 0, 45, 24 },
  { 4316, 4, 0, 0, 0, 57, 24 },
  { 4320, 5, 0, 0, 0, 46, 24 },
  { 4400, 4, 0, 0, 0, 57, 24 },
  { 4404, 5, 0, 0, 0, 46, 24 },
  { 4484, 4, 0, 0, 0, 57, 24 },
  { 4488, 5, 0, 0, 0, 46, 24 },
  { 4568, 4, 0, 0, 0, 57, 24 },
  { 4572, 5, 0, 0, 0, 46, 24 },
  { 4803, 4, 0, 0, 0, 57, 24 },
  { 4807, 5, 0, 0, 0, 46, 24 },
  { 4862, 4, 0, 0, 0, 57, 24 },
  { 4866, 5, 0, 0, 0, 46, 24 },
  { 4946, 4, 0, 0, 0, 57, 24 },
  { 4950, 5, 0, 0, 0, 46, 24 },
  { 5030, 4, 0, 0, 0, 57, 24 },
  { 5034, 5, 0, 0, 0, 46, 24 },
  { 5114, 4, 0, 0, 0, 57, 24 },
  { 5118, 5, 0, 0, 0, 46, 24 },
  { 5345, 4, 0, 0, 0, 57, 24 },
  { 5349, 5, 0, 0, 0, 46, 24 },
  { 5408, 4, 0, 0, 0, 61, 24 },
  { 5412, 5, 0, 0, 0, 7, 24 },
  { 4652, 4, 0, 0, 0, 63, 24 },
  { 4656, 5, 0, 0, 0, 15, 24 },
  { 4736, 4, 0, 0, 0, 65, 24 },
  { 4740, 5, 0, 0, 0, 21, 24 },
  { 5441, 4, 0, 0, 0, 75, 24 },
  { 5445, 5, 0, 0, 0, 10, 24 },
  { 5198, 4, 0, 0, 0, 77, 24 },
  { 5202, 5, 0, 0, 0, 17, 24 },
  { 5282, 4, 0, 0, 0, 79, 24 },
  { 5286, 5, 0, 0, 0, 23, 24 },
  { 5474, 4, 0, 0, 0, 89, 24 },
  { 5478, 5, 0, 0, 0, 4, 24 },
  { 4174, 4, 0, 0, 0, 91, 24 },
  { 4178, 5, 0, 0, 0, 13, 24 },
  { 4226, 4, 0, 0, 0, 93, 24 },
  { 4230, 5, 0, 0, 0, 19, 24 },
  // 1952: atomic_fetch_or, atomic_fetch_xor, atomic_fetch_and, 
  { 3988, 3, 0, 0, 0, 54, 24 },
  { 4021, 3, 0, 0, 0, 54, 24 },
  { 4071, 3, 0, 0, 0, 54, 24 },
  { 4121, 3, 0, 0, 0, 54, 24 },
  { 4313, 3, 0, 0, 0, 56, 24 },
  { 4397, 3, 0, 0, 0, 56, 24 },
  { 4481, 3, 0, 0, 0, 56, 24 },
  { 4565, 3, 0, 0, 0, 56, 24 },
  { 4859, 3, 0, 0, 0, 56, 24 },
  { 4943, 3, 0, 0, 0, 56, 24 },
  { 5027, 3, 0, 0, 0, 56, 24 },
  { 5111, 3, 0, 0, 0, 56, 24 },
  // 1964: atomic_fetch_or_explicit, atomic_fetch_xor_explicit, atomic_fetch_and_explicit, 
  { 3991, 4, 0, 0, 0, 55, 24 },
  { 3995, 5, 0, 0, 0, 45, 24 },
  { 4024, 4, 0, 0, 0, 55, 24 },
  { 4028, 5, 0, 0, 0, 45, 24 },
  { 4074, 4, 0, 0, 0, 55, 24 },
  { 4078, 5, 0, 0, 0, 45, 24 },
  { 4124, 4, 0, 0, 0, 55, 24 },
  { 4128, 5, 0, 0, 0, 45, 24 },
  { 4316, 4, 0, 0, 0, 57, 24 },
  { 4320, 5, 0, 0, 0, 46, 24 },
  { 4400, 4, 0, 0, 0, 57, 24 },
  { 4404, 5, 0, 0, 0, 46, 24 },
  { 4484, 4, 0, 0, 0, 57, 24 },
  { 4488, 5, 0, 0, 0, 46, 24 },
  { 4568, 4, 0, 0, 0, 57, 24 },
  { 4572, 5, 0, 0, 0, 46, 24 },
  { 4862, 4, 0, 0, 0, 57, 24 },
  { 4866, 5, 0, 0, 0, 46, 24 },
  { 4946, 4, 0, 0, 0, 57, 24 },
  { 4950, 5, 0, 0, 0, 46, 24 },
  { 5030, 4, 0, 0, 0, 57, 24 },
  { 5034, 5, 0, 0, 0, 46, 24 },
  { 5114, 4, 0, 0, 0, 57, 24 },
  { 5118, 5, 0, 0, 0, 46, 24 },
  // 1988: atomic_flag_clear, 
  { 4274, 2, 0, 0, 0, 54, 24 },
  { 4820, 2, 0, 0, 0, 56, 24 },
  { 5364, 2, 0, 0, 0, 56, 24 },
  // 1991: atomic_flag_clear_explicit, 
  { 4276, 3, 0, 0, 0, 55, 24 },
  { 4279, 4, 0, 0, 0, 45, 24 },
  { 4822, 3, 0, 0, 0, 57, 24 },
  { 4825, 4, 0, 0, 0, 46, 24 },
  { 5368, 3, 0, 0, 0, 57, 24 },
  { 5371, 4, 0, 0, 0, 46, 24 },
  // 1997: atomic_flag_test_and_set, 
  { 4283, 2, 0, 0, 0, 54, 24 },
  { 4829, 2, 0, 0, 0, 56, 24 },
  { 5375, 2, 0, 0, 0, 56, 24 },
  // 2000: atomic_flag_test_and_set_explicit, 
  { 4285, 3, 0, 0, 0, 55, 24 },
  { 4288, 4, 0, 0, 0, 45, 24 },
  { 4831, 3, 0, 0, 0, 57, 24 },
  { 4834, 4, 0, 0, 0, 46, 24 },
  { 5377, 3, 0, 0, 0, 57, 24 },
  { 5380, 4, 0, 0, 0, 46, 24 },
  // 2006: shuffle, 
  { 5483, 3, 0, 1, 0, 43, 31 },
  { 5486, 3, 0, 1, 0, 43, 31 },
  { 5489, 3, 0, 1, 0, 43, 31 },
  { 5492, 3, 0, 1, 0, 43, 31 },
  { 5495, 3, 0, 1, 0, 43, 31 },
  { 5498, 3, 0, 1, 0, 43, 31 },
  { 5501, 3, 0, 1, 0, 43, 31 },
  { 5504, 3, 0, 1, 0, 43, 31 },
  { 5507, 3, 0, 1, 0, 43, 31 },
  { 5510, 3, 0, 1, 0, 43, 31 },
  { 5513, 3, 0, 1, 0, 43, 31 },
  { 5516, 3, 0, 1, 0, 43, 31 },
  { 5519, 3, 0, 1, 0, 43, 31 },
  { 5524, 3, 0, 1, 0, 43, 31 },
  { 5527, 3, 0, 1, 0, 43, 31 },
  { 5530, 3, 0, 1, 0, 43, 31 },
  { 5533, 3, 0, 1, 0, 43, 31 },
  { 5536, 3, 0, 1, 0, 43, 31 },
  { 5539, 3, 0, 1, 0, 43, 31 },
  { 5542, 3, 0, 1, 0, 43, 31 },
  { 5545, 3, 0, 1, 0, 43, 31 },
  { 5548, 3, 0, 1, 0, 43, 31 },
  { 5551, 3, 0, 1, 0, 43, 31 },
  { 5556, 3, 0, 1, 0, 43, 31 },
  { 5559, 3, 0, 1, 0, 43, 31 },
  { 5562, 3, 0, 1, 0, 43, 31 },
  { 5565, 3, 0, 1, 0, 43, 31 },
  { 5568, 3, 0, 1, 0, 43, 31 },
  { 5571, 3, 0, 1, 0, 43, 31 },
  { 5574, 3, 0, 1, 0, 43, 31 },
  { 5577, 3, 0, 1, 0, 43, 31 },
  { 5580, 3, 0, 1, 0, 43, 31 },
  { 5583, 3, 0, 1, 0, 43, 31 },
  { 5588, 3, 0, 1, 0, 43, 31 },
  { 5591, 3, 0, 1, 0, 43, 31 },
  { 5594, 3, 0, 1, 0, 43, 31 },
  { 5597, 3, 0, 1, 0, 43, 31 },
  { 5600, 3, 0, 1, 0, 43, 31 },
  { 5603, 3, 0, 1, 0, 43, 31 },
  { 5606, 3, 0, 1, 0, 43, 31 },
  { 5609, 3, 0, 1, 0, 43, 31 },
  { 5612, 3, 0, 1, 0, 43, 31 },
  { 5615, 3, 0, 1, 0, 43, 31 },
  { 5620, 3, 0, 1, 0, 43, 31 },
  { 5623, 3, 0, 1, 0, 43, 31 },
  { 5626, 3, 0, 1, 0, 43, 31 },
  { 5629, 3, 0, 1, 0, 43, 31 },
  { 5632, 3, 0, 1, 0, 43, 31 },
  { 5635, 3, 0, 1, 0, 43, 31 },
  { 5638, 3, 0, 1, 0, 43, 31 },
  { 5641, 3, 0, 1, 0, 43, 31 },
  { 5644, 3, 0, 1, 0, 43, 31 },
  { 5647, 3, 0, 1, 0, 43, 31 },
  { 5652, 3, 0, 1, 0, 43, 31 },
  { 5655, 3, 0, 1, 0, 43, 31 },
  { 5658, 3, 0, 1, 0, 43, 31 },
  { 5661, 3, 0, 1, 0, 43, 31 },
  { 5664, 3, 0, 1, 0, 43, 31 },
  { 5667, 3, 0, 1, 0, 43, 31 },
  { 5670, 3, 0, 1, 0, 43, 31 },
  { 5673, 3, 0, 1, 0, 43, 31 },
  { 5676, 3, 0, 1, 0, 43, 31 },
  { 5679, 3, 0, 1, 0, 43, 31 },
  { 5684, 3, 0, 1, 0, 43, 31 },
  { 5687, 3, 0, 1, 0, 43, 31 },
  { 5690, 3, 0, 1, 0, 43, 31 },
  { 5693, 3, 0, 1, 0, 43, 31 },
  { 5696, 3, 0, 1, 0, 43, 31 },
  { 5699, 3, 0, 1, 0, 43, 31 },
  { 5702, 3, 0, 1, 0, 43, 31 },
  { 5705, 3, 0, 1, 0, 43, 31 },
  { 5708, 3, 0, 1, 0, 43, 31 },
  { 5711, 3, 0, 1, 0, 43, 31 },
  { 5714, 3, 0, 1, 0, 43, 31 },
  { 5717, 3, 0, 1, 0, 43, 31 },
  { 5720, 3, 0, 1, 0, 43, 31 },
  { 5723, 3, 0, 1, 0, 43, 31 },
  { 5726, 3, 0, 1, 0, 43, 31 },
  { 5729, 3, 0, 1, 0, 43, 31 },
  { 5732, 3, 0, 1, 0, 43, 31 },
  { 5735, 3, 0, 1, 0, 43, 31 },
  { 5738, 3, 0, 1, 0, 43, 31 },
  { 5741, 3, 0, 1, 0, 43, 31 },
  { 5744, 3, 0, 1, 0, 43, 31 },
  { 5747, 3, 0, 1, 0, 43, 31 },
  { 5750, 3, 0, 1, 0, 43, 31 },
  { 5753, 3, 0, 1, 0, 43, 31 },
  { 5756, 3, 0, 1, 0, 43, 31 },
  { 5759, 3, 0, 1, 0, 43, 31 },
  { 5762, 3, 0, 1, 0, 43, 31 },
  { 5765, 3, 0, 1, 0, 43, 31 },
  { 5768, 3, 0, 1, 0, 43, 31 },
  { 5771, 3, 0, 1, 0, 43, 31 },
  { 5774, 3, 0, 1, 0, 43, 31 },
  { 5777, 3, 0, 1, 0, 43, 31 },
  { 5780, 3, 0, 1, 0, 43, 31 },
  { 5783, 3, 0, 1, 0, 43, 31 },
  { 5786, 3, 0, 1, 0, 43, 31 },
  { 5789, 3, 0, 1, 0, 43, 31 },
  { 5792, 3, 0, 1, 0, 43, 31 },
  { 5795, 3, 0, 1, 0, 43, 31 },
  { 5798, 3, 0, 1, 0, 43, 31 },
  { 5801, 3, 0, 1, 0, 43, 31 },
  { 5804, 3, 0, 1, 0, 43, 31 },
  { 5807, 3, 0, 1, 0, 43, 31 },
  { 5810, 3, 0, 1, 0, 43, 31 },
  { 5813, 3, 0, 1, 0, 43, 31 },
  { 5816, 3, 0, 1, 0, 43, 31 },
  { 5819, 3, 0, 1, 0, 43, 31 },
  { 5822, 3, 0, 1, 0, 43, 31 },
  { 5825, 3, 0, 1, 0, 43, 31 },
  { 5828, 3, 0, 1, 0, 43, 31 },
  { 5831, 3, 0, 1, 0, 43, 31 },
  { 5834, 3, 0, 1, 0, 43, 31 },
  { 5837, 3, 0, 1, 0, 43, 31 },
  { 5840, 3, 0, 1, 0, 43, 31 },
  { 5843, 3, 0, 1, 0, 43, 31 },
  { 5846, 3, 0, 1, 0, 43, 31 },
  { 5849, 3, 0, 1, 0, 43, 31 },
  { 5852, 3, 0, 1, 0, 43, 31 },
  { 5855, 3, 0, 1, 0, 43, 31 },
  { 5858, 3, 0, 1, 0, 43, 31 },
  { 5861, 3, 0, 1, 0, 43, 31 },
  { 5864, 3, 0, 1, 0, 43, 31 },
  { 5867, 3, 0, 1, 0, 43, 31 },
  { 5870, 3, 0, 1, 0, 43, 31 },
  { 5873, 3, 0, 1, 0, 43, 31 },
  { 5876, 3, 0, 1, 0, 43, 31 },
  { 5879, 3, 0, 1, 0, 43, 31 },
  { 5882, 3, 0, 1, 0, 43, 31 },
  { 5885, 3, 0, 1, 0, 43, 31 },
  { 5888, 3, 0, 1, 0, 43, 31 },
  { 5891, 3, 0, 1, 0, 43, 31 },
  { 5894, 3, 0, 1, 0, 43, 31 },
  { 5897, 3, 0, 1, 0, 43, 31 },
  { 5900, 3, 0, 1, 0, 43, 31 },
  { 5903, 3, 0, 1, 0, 43, 31 },
  { 5906, 3, 0, 1, 0, 43, 31 },
  { 5909, 3, 0, 1, 0, 43, 31 },
  { 5912, 3, 0, 1, 0, 43, 31 },
  { 5915, 3, 0, 1, 0, 43, 31 },
  { 5918, 3, 0, 1, 0, 43, 31 },
  { 5921, 3, 0, 1, 0, 43, 31 },
  { 5924, 3, 0, 1, 0, 43, 31 },
  { 5927, 3, 0, 1, 0, 43, 31 },
  { 5930, 3, 0, 1, 0, 43, 31 },
  { 5933, 3, 0, 1, 0, 43, 31 },
  { 5936, 3, 0, 1, 0, 43, 31 },
  { 5939, 3, 0, 1, 0, 43, 31 },
  { 5942, 3, 0, 1, 0, 43, 31 },
  { 5945, 3, 0, 1, 0, 43, 31 },
  { 5948, 3, 0, 1, 0, 43, 31 },
  { 5951, 3, 0, 1, 0, 43, 31 },
  { 5954, 3, 0, 1, 0, 43, 31 },
  { 5957, 3, 0, 1, 0, 43, 31 },
  { 5960, 3, 0, 1, 0, 43, 31 },
  { 5963, 3, 0, 1, 0, 43, 31 },
  { 5966, 3, 0, 1, 0, 43, 31 },
  { 5969, 3, 0, 1, 0, 43, 31 },
  { 5972, 3, 0, 1, 0, 43, 31 },
  { 5975, 3, 0, 1, 0, 43, 31 },
  { 5978, 3, 0, 1, 0, 43, 31 },
  { 5981, 3, 0, 1, 0, 43, 31 },
  { 5984, 3, 0, 1, 0, 43, 31 },
  { 5987, 3, 0, 1, 0, 43, 31 },
  { 5990, 3, 0, 1, 0, 43, 31 },
  { 5993, 3, 0, 1, 0, 43, 31 },
  { 5996, 3, 0, 1, 0, 43, 31 },
  { 5999, 3, 0, 1, 0, 43, 31 },
  { 6002, 3, 0, 1, 0, 43, 31 },
  { 6005, 3, 0, 1, 0, 43, 31 },
  { 6008, 3, 0, 1, 0, 43, 31 },
  { 6011, 3, 0, 1, 0, 43, 31 },
  { 6014, 3, 0, 1, 0, 43, 31 },
  { 6017, 3, 0, 1, 0, 43, 31 },
  { 6020, 3, 0, 1, 0, 43, 31 },
  // 2182: shuffle2, 
  { 6023, 4, 0, 1, 0, 43, 31 },
  { 6027, 4, 0, 1, 0, 43, 31 },
  { 6031, 4, 0, 1, 0, 43, 31 },
  { 6035, 4, 0, 1, 0, 43, 31 },
  { 6039, 4, 0, 1, 0, 43, 31 },
  { 6043, 4, 0, 1, 0, 43, 31 },
  { 6047, 4, 0, 1, 0, 43, 31 },
  { 6051, 4, 0, 1, 0, 43, 31 },
  { 6055, 4, 0, 1, 0, 43, 31 },
  { 6059, 4, 0, 1, 0, 43, 31 },
  { 6063, 4, 0, 1, 0, 43, 31 },
  { 6067, 4, 0, 1, 0, 43, 31 },
  { 6071, 4, 0, 1, 0, 43, 31 },
  { 6075, 4, 0, 1, 0, 43, 31 },
  { 6079, 4, 0, 1, 0, 43, 31 },
  { 6083, 4, 0, 1, 0, 43, 31 },
  { 6087, 4, 0, 1, 0, 43, 31 },
  { 6091, 4, 0, 1, 0, 43, 31 },
  { 6095, 4, 0, 1, 0, 43, 31 },
  { 6099, 4, 0, 1, 0, 43, 31 },
  { 6103, 4, 0, 1, 0, 43, 31 },
  { 6107, 4, 0, 1, 0, 43, 31 },
  { 6111, 4, 0, 1, 0, 43, 31 },
  { 6115, 4, 0, 1, 0, 43, 31 },
  { 6119, 4, 0, 1, 0, 43, 31 },
  { 6123, 4, 0, 1, 0, 43, 31 },
  { 6127, 4, 0, 1, 0, 43, 31 },
  { 6131, 4, 0, 1, 0, 43, 31 },
  { 6135, 4, 0, 1, 0, 43, 31 },
  { 6139, 4, 0, 1, 0, 43, 31 },
  { 6143, 4, 0, 1, 0, 43, 31 },
  { 6147, 4, 0, 1, 0, 43, 31 },
  { 6151, 4, 0, 1, 0, 43, 31 },
  { 6155, 4, 0, 1, 0, 43, 31 },
  { 6159, 4, 0, 1, 0, 43, 31 },
  { 6163, 4, 0, 1, 0, 43, 31 },
  { 6167, 4, 0, 1, 0, 43, 31 },
  { 6171, 4, 0, 1, 0, 43, 31 },
  { 6175, 4, 0, 1, 0, 43, 31 },
  { 6179, 4, 0, 1, 0, 43, 31 },
  { 6183, 4, 0, 1, 0, 43, 31 },
  { 6187, 4, 0, 1, 0, 43, 31 },
  { 6191, 4, 0, 1, 0, 43, 31 },
  { 6195, 4, 0, 1, 0, 43, 31 },
  { 6199, 4, 0, 1, 0, 43, 31 },
  { 6203, 4, 0, 1, 0, 43, 31 },
  { 6207, 4, 0, 1, 0, 43, 31 },
  { 6211, 4, 0, 1, 0, 43, 31 },
  { 6215, 4, 0, 1, 0, 43, 31 },
  { 6219, 4, 0, 1, 0, 43, 31 },
  { 6223, 4, 0, 1, 0, 43, 31 },
  { 6227, 4, 0, 1, 0, 43, 31 },
  { 6231, 4, 0, 1, 0, 43, 31 },
  { 6235, 4, 0, 1, 0, 43, 31 },
  { 6239, 4, 0, 1, 0, 43, 31 },
  { 6243, 4, 0, 1, 0, 43, 31 },
  { 6247, 4, 0, 1, 0, 43, 31 },
  { 6251, 4, 0, 1, 0, 43, 31 },
  { 6255, 4, 0, 1, 0, 43, 31 },
  { 6259, 4, 0, 1, 0, 43, 31 },
  { 6263, 4, 0, 1, 0, 43, 31 },
  { 6267, 4, 0, 1, 0, 43, 31 },
  { 6271, 4, 0, 1, 0, 43, 31 },
  { 6275, 4, 0, 1, 0, 43, 31 },
  { 6279, 4, 0, 1, 0, 43, 31 },
  { 6283, 4, 0, 1, 0, 43, 31 },
  { 6287, 4, 0, 1, 0, 43, 31 },
  { 6291, 4, 0, 1, 0, 43, 31 },
  { 6295, 4, 0, 1, 0, 43, 31 },
  { 6299, 4, 0, 1, 0, 43, 31 },
  { 6303, 4, 0, 1, 0, 43, 31 },
  { 6307, 4, 0, 1, 0, 43, 31 },
  { 6311, 4, 0, 1, 0, 43, 31 },
  { 6315, 4, 0, 1, 0, 43, 31 },
  { 6319, 4, 0, 1, 0, 43, 31 },
  { 6323, 4, 0, 1, 0, 43, 31 },
  { 6327, 4, 0, 1, 0, 43, 31 },
  { 6331, 4, 0, 1, 0, 43, 31 },
  { 6335, 4, 0, 1, 0, 43, 31 },
  { 6339, 4, 0, 1, 0, 43, 31 },
  { 6343, 4, 0, 1, 0, 43, 31 },
  { 6347, 4, 0, 1, 0, 43, 31 },
  { 6351, 4, 0, 1, 0, 43, 31 },
  { 6355, 4, 0, 1, 0, 43, 31 },
  { 6359, 4, 0, 1, 0, 43, 31 },
  { 6363, 4, 0, 1, 0, 43, 31 },
  { 6367, 4, 0, 1, 0, 43, 31 },
  { 6371, 4, 0, 1, 0, 43, 31 },
  { 6375, 4, 0, 1, 0, 43, 31 },
  { 6379, 4, 0, 1, 0, 43, 31 },
  { 6383, 4, 0, 1, 0, 43, 31 },
  { 6387, 4, 0, 1, 0, 43, 31 },
  { 6391, 4, 0, 1, 0, 43, 31 },
  { 6395, 4, 0, 1, 0, 43, 31 },
  { 6399, 4, 0, 1, 0, 43, 31 },
  { 6403, 4, 0, 1, 0, 43, 31 },
  { 6407, 4, 0, 1, 0, 43, 31 },
  { 6411, 4, 0, 1, 0, 43, 31 },
  { 6415, 4, 0, 1, 0, 43, 31 },
  { 6419, 4, 0, 1, 0, 43, 31 },
  { 6423, 4, 0, 1, 0, 43, 31 },
  { 6427, 4, 0, 1, 0, 43, 31 },
  { 6431, 4, 0, 1, 0, 43, 31 },
  { 6435, 4, 0, 1, 0, 43, 31 },
  { 6439, 4, 0, 1, 0, 43, 31 },
  { 6443, 4, 0, 1, 0, 43, 31 },
  { 6447, 4, 0, 1, 0, 43, 31 },
  { 6451, 4, 0, 1, 0, 43, 31 },
  { 6455, 4, 0, 1, 0, 43, 31 },
  { 6459, 4, 0, 1, 0, 43, 31 },
  { 6463, 4, 0, 1, 0, 43, 31 },
  { 6467, 4, 0, 1, 0, 43, 31 },
  { 6471, 4, 0, 1, 0, 43, 31 },
  { 6475, 4, 0, 1, 0, 43, 31 },
  { 6479, 4, 0, 1, 0, 43, 31 },
  { 6483, 4, 0, 1, 0, 43, 31 },
  { 6487, 4, 0, 1, 0, 43, 31 },
  { 6491, 4, 0, 1, 0, 43, 31 },
  { 6495, 4, 0, 1, 0, 43, 31 },
  { 6499, 4, 0, 1, 0, 43, 31 },
  { 6503, 4, 0, 1, 0, 43, 31 },
  { 6507, 4, 0, 1, 0, 43, 31 },
  { 6511, 4, 0, 1, 0, 43, 31 },
  { 6515, 4, 0, 1, 0, 43, 31 },
  { 6519, 4, 0, 1, 0, 43, 31 },
  { 6523, 4, 0, 1, 0, 43, 31 },
  { 6527, 4, 0, 1, 0, 43, 31 },
  { 6531, 4, 0, 1, 0, 43, 31 },
  { 6535, 4, 0, 1, 0, 43, 31 },
  { 6539, 4, 0, 1, 0, 43, 31 },
  { 6543, 4, 0, 1, 0, 43, 31 },
  { 6547, 4, 0, 1, 0, 43, 31 },
  { 6551, 4, 0, 1, 0, 43, 31 },
  { 6555, 4, 0, 1, 0, 43, 31 },
  { 6559, 4, 0, 1, 0, 43, 31 },
  { 6563, 4, 0, 1, 0, 43, 31 },
  { 6567, 4, 0, 1, 0, 43, 31 },
  { 6573, 4, 0, 1, 0, 43, 31 },
  { 6577, 4, 0, 1, 0, 43, 31 },
  { 6581, 4, 0, 1, 0, 43, 31 },
  { 6585, 4, 0, 1, 0, 43, 31 },
  { 6589, 4, 0, 1, 0, 43, 31 },
  { 6593, 4, 0, 1, 0, 43, 31 },
  { 6597, 4, 0, 1, 0, 43, 31 },
  { 6601, 4, 0, 1, 0, 43, 31 },
  { 6605, 4, 0, 1, 0, 43, 31 },
  { 6609, 4, 0, 1, 0, 43, 31 },
  { 6615, 4, 0, 1, 0, 43, 31 },
  { 6619, 4, 0, 1, 0, 43, 31 },
  { 6623, 4, 0, 1, 0, 43, 31 },
  { 6627, 4, 0, 1, 0, 43, 31 },
  { 6631, 4, 0, 1, 0, 43, 31 },
  { 6635, 4, 0, 1, 0, 43, 31 },
  { 6639, 4, 0, 1, 0, 43, 31 },
  { 6643, 4, 0, 1, 0, 43, 31 },
  { 6647, 4, 0, 1, 0, 43, 31 },
  { 6651, 4, 0, 1, 0, 43, 31 },
  { 6657, 4, 0, 1, 0, 43, 31 },
  { 6661, 4, 0, 1, 0, 43, 31 },
  { 6665, 4, 0, 1, 0, 43, 31 },
  { 6669, 4, 0, 1, 0, 43, 31 },
  { 6673, 4, 0, 1, 0, 43, 31 },
  { 6677, 4, 0, 1, 0, 43, 31 },
  { 6681, 4, 0, 1, 0, 43, 31 },
  { 6685, 4, 0, 1, 0, 43, 31 },
  { 6689, 4, 0, 1, 0, 43, 31 },
  { 6693, 4, 0, 1, 0, 43, 31 },
  { 6699, 4, 0, 1, 0, 43, 31 },
  { 6703, 4, 0, 1, 0, 43, 31 },
  { 6707, 4, 0, 1, 0, 43, 31 },
  { 6711, 4, 0, 1, 0, 43, 31 },
  { 6715, 4, 0, 1, 0, 43, 31 },
  { 6719, 4, 0, 1, 0, 43, 31 },
  { 6723, 4, 0, 1, 0, 43, 31 },
  { 6727, 4, 0, 1, 0, 43, 31 },
  { 6731, 4, 0, 1, 0, 43, 31 },
  // 2358: read_imagef, 
  { 6735, 4, 1, 0, 0, 43, 31 },
  { 6749, 4, 1, 0, 0, 43, 31 },
  { 6761, 4, 1, 0, 0, 43, 31 },
  { 6775, 4, 1, 0, 0, 43, 31 },
  { 6787, 4, 1, 0, 0, 43, 31 },
  { 6799, 4, 1, 0, 0, 43, 31 },
  { 6811, 4, 1, 0, 0, 43, 31 },
  { 6823, 4, 1, 0, 0, 43, 31 },
  { 6835, 4, 1, 0, 0, 43, 31 },
  { 6847, 4, 1, 0, 0, 43, 31 },
  { 6859, 4, 1, 0, 0, 43, 31 },
  { 6863, 4, 1, 0, 0, 43, 31 },
  { 6867, 4, 1, 0, 0, 43, 31 },
  { 6871, 4, 1, 0, 0, 43, 31 },
  { 6875, 3, 1, 0, 0, 43, 28 },
  { 6884, 3, 1, 0, 0, 43, 28 },
  { 6893, 3, 1, 0, 0, 43, 28 },
  { 6902, 3, 1, 0, 0, 43, 28 },
  { 6905, 3, 1, 0, 0, 43, 28 },
  { 6908, 3, 1, 0, 0, 43, 28 },
  { 6917, 3, 1, 0, 0, 43, 28 },
  { 6926, 3, 1, 0, 0, 43, 28 },
  { 6935, 3, 1, 0, 0, 48, 28 },
  { 6944, 3, 1, 0, 0, 48, 28 },
  { 6953, 3, 1, 0, 0, 48, 28 },
  { 6962, 3, 1, 0, 0, 48, 28 },
  { 6971, 3, 1, 0, 0, 48, 28 },
  { 6980, 3, 1, 0, 0, 48, 28 },
  { 6989, 3, 1, 0, 0, 48, 28 },
  { 6992, 3, 1, 0, 0, 48, 28 },
  { 7439, 5, 1, 0, 0, 33, 31 },
  { 7444, 6, 1, 0, 0, 33, 31 },
  { 7472, 5, 1, 0, 0, 33, 31 },
  { 7477, 6, 1, 0, 0, 33, 31 },
  { 7483, 5, 1, 0, 0, 33, 31 },
  { 7488, 6, 1, 0, 0, 33, 31 },
  { 7516, 6, 1, 0, 0, 33, 31 },
  { 7522, 5, 1, 0, 0, 33, 31 },
  { 7549, 5, 1, 0, 0, 33, 31 },
  { 7554, 6, 1, 0, 0, 33, 31 },
  { 7582, 5, 1, 0, 0, 33, 31 },
  { 7587, 6, 1, 0, 0, 33, 31 },
  { 7615, 5, 1, 0, 0, 33, 31 },
  { 7620, 6, 1, 0, 0, 33, 31 },
  { 7711, 4, 1, 0, 0, 26, 31 },
  { 7723, 4, 1, 0, 0, 26, 31 },
  { 7735, 4, 1, 0, 0, 26, 31 },
  { 7739, 4, 1, 0, 0, 26, 31 },
  { 7783, 4, 1, 0, 0, 26, 31 },
  { 7795, 4, 1, 0, 0, 26, 31 },
  { 7807, 4, 1, 0, 0, 26, 31 },
  { 7811, 4, 1, 0, 0, 26, 31 },
  // 2410: read_imagei, 
  { 6741, 4, 1, 0, 0, 43, 31 },
  { 6753, 4, 1, 0, 0, 43, 31 },
  { 6765, 4, 1, 0, 0, 43, 31 },
  { 6779, 4, 1, 0, 0, 43, 31 },
  { 6791, 4, 1, 0, 0, 43, 31 },
  { 6803, 4, 1, 0, 0, 43, 31 },
  { 6815, 4, 1, 0, 0, 43, 31 },
  { 6827, 4, 1, 0, 0, 43, 31 },
  { 6839, 4, 1, 0, 0, 43, 31 },
  { 6851, 4, 1, 0, 0, 43, 31 },
  { 6878, 3, 1, 0, 0, 43, 28 },
  { 6887, 3, 1, 0, 0, 43, 28 },
  { 6896, 3, 1, 0, 0, 43, 28 },
  { 6911, 3, 1, 0, 0, 43, 28 },
  { 6920, 3, 1, 0, 0, 43, 28 },
  { 6929, 3, 1, 0, 0, 43, 28 },
  { 6938, 3, 1, 0, 0, 48, 28 },
  { 6947, 3, 1, 0, 0, 48, 28 },
  { 6956, 3, 1, 0, 0, 48, 28 },
  { 6965, 3, 1, 0, 0, 48, 28 },
  { 6974, 3, 1, 0, 0, 48, 28 },
  { 6983, 3, 1, 0, 0, 48, 28 },
  { 7450, 5, 1, 0, 0, 33, 31 },
  { 7455, 6, 1, 0, 0, 33, 31 },
  { 7494, 5, 1, 0, 0, 33, 31 },
  { 7499, 6, 1, 0, 0, 33, 31 },
  { 7527, 6, 1, 0, 0, 33, 31 },
  { 7533, 5, 1, 0, 0, 33, 31 },
  { 7560, 5, 1, 0, 0, 33, 31 },
  { 7565, 6, 1, 0, 0, 33, 31 },
  { 7593, 5, 1, 0, 0, 33, 31 },
  { 7598, 6, 1, 0, 0, 33, 31 },
  { 7715, 4, 1, 0, 0, 26, 31 },
  { 7727, 4, 1, 0, 0, 26, 31 },
  { 7787, 4, 1, 0, 0, 26, 31 },
  { 7799, 4, 1, 0, 0, 26, 31 },
  // 2446: read_imageui, 
  { 6745, 4, 1, 0, 0, 43, 31 },
  { 6757, 4, 1, 0, 0, 43, 31 },
  { 6769, 4, 1, 0, 0, 43, 31 },
  { 6783, 4, 1, 0, 0, 43, 31 },
  { 6795, 4, 1, 0, 0, 43, 31 },
  { 6807, 4, 1, 0, 0, 43, 31 },
  { 6819, 4, 1, 0, 0, 43, 31 },
  { 6831, 4, 1, 0, 0, 43, 31 },
  { 6843, 4, 1, 0, 0, 43, 31 },
  { 6855, 4, 1, 0, 0, 43, 31 },
  { 6881, 3, 1, 0, 0, 43, 28 },
  { 6890, 3, 1, 0, 0, 43, 28 },
  { 6899, 3, 1, 0, 0, 43, 28 },
  { 6914, 3, 1, 0, 0, 43, 28 },
  { 6923, 3, 1, 0, 0, 43, 28 },
  { 6932, 3, 1, 0, 0, 43, 28 },
  { 6941, 3, 1, 0, 0, 48, 28 },
  { 6950, 3, 1, 0, 0, 48, 28 },
  { 6959, 3, 1, 0, 0, 48, 28 },
  { 6968, 3, 1, 0, 0, 48, 28 },
  { 6977, 3, 1, 0, 0, 48, 28 },
  { 6986, 3, 1, 0, 0, 48, 28 },
  { 7461, 5, 1, 0, 0, 33, 31 },
  { 7466, 6, 1, 0, 0, 33, 31 },
  { 7505, 5, 1, 0, 0, 33, 31 },
  { 7510, 6, 1, 0, 0, 33, 31 },
  { 7538, 6, 1, 0, 0, 33, 31 },
  { 7544, 5, 1, 0, 0, 33, 31 },
  { 7571, 5, 1, 0, 0, 33, 31 },
  { 7576, 6, 1, 0, 0, 33, 31 },
  { 7604, 5, 1, 0, 0, 33, 31 },
  { 7609, 6, 1, 0, 0, 33, 31 },
  { 7719, 4, 1, 0, 0, 26, 31 },
  { 7731, 4, 1, 0, 0, 26, 31 },
  { 7791, 4, 1, 0, 0, 26, 31 },
  { 7803, 4, 1, 0, 0, 26, 31 },
  // 2482: write_imagef, 
  { 6995, 4, 0, 0, 0, 43, 31 },
  { 7007, 4, 0, 0, 0, 43, 31 },
  { 7019, 4, 0, 0, 0, 43, 31 },
  { 7031, 4, 0, 0, 0, 43, 31 },
  { 7043, 4, 0, 0, 0, 43, 31 },
  { 7055, 4, 0, 0, 0, 43, 31 },
  { 7059, 4, 0, 0, 0, 43, 31 },
  { 7063, 4, 0, 0, 0, 43, 31 },
  { 7075, 4, 0, 0, 0, 48, 31 },
  { 7087, 4, 0, 0, 0, 48, 31 },
  { 7099, 4, 0, 0, 0, 48, 31 },
  { 7111, 4, 0, 0, 0, 48, 31 },
  { 7123, 4, 0, 0, 0, 48, 31 },
  { 7135, 4, 0, 0, 0, 48, 31 },
  { 7147, 4, 0, 0, 0, 48, 31 },
  { 7151, 4, 0, 0, 0, 48, 31 },
  { 7626, 5, 0, 0, 0, 34, 31 },
  { 7641, 5, 0, 0, 0, 34, 31 },
  { 7646, 5, 0, 0, 0, 34, 31 },
  { 7661, 5, 0, 0, 0, 34, 31 },
  { 7676, 5, 0, 0, 0, 34, 31 },
  { 7691, 5, 0, 0, 0, 34, 31 },
  { 7696, 5, 0, 0, 0, 34, 31 },
  // 2505: write_imagei, 
  { 6999, 4, 0, 0, 0, 43, 31 },
  { 7011, 4, 0, 0, 0, 43, 31 },
  { 7023, 4, 0, 0, 0, 43, 31 },
  { 7035, 4, 0, 0, 0, 43, 31 },
  { 7047, 4, 0, 0, 0, 43, 31 },
  { 7067, 4, 0, 0, 0, 43, 31 },
  { 7079, 4, 0, 0, 0, 48, 31 },
  { 7091, 4, 0, 0, 0, 48, 31 },
  { 7103, 4, 0, 0, 0, 48, 31 },
  { 7115, 4, 0, 0, 0, 48, 31 },
  { 7127, 4, 0, 0, 0, 48, 31 },
  { 7139, 4, 0, 0, 0, 48, 31 },
  { 7631, 5, 0, 0, 0, 34, 31 },
  { 7651, 5, 0, 0, 0, 34, 31 },
  { 7666, 5, 0, 0, 0, 34, 31 },
  { 7681, 5, 0, 0, 0, 34, 31 },
  { 7701, 5, 0, 0, 0, 34, 31 },
  // 2522: write_imageui, 
  { 7003, 4, 0, 0, 0, 43, 31 },
  { 7015, 4, 0, 0, 0, 43, 31 },
  { 7027, 4, 0, 0, 0, 43, 31 },
  { 7039, 4, 0, 0, 0, 43, 31 },
  { 7051, 4, 0, 0, 0, 43, 31 },
  { 7071, 4, 0, 0, 0, 43, 31 },
  { 7083, 4, 0, 0, 0, 48, 31 },
  { 7095, 4, 0, 0, 0, 48, 31 },
  { 7107, 4, 0, 0, 0, 48, 31 },
  { 7119, 4, 0, 0, 0, 48, 31 },
  { 7131, 4, 0, 0, 0, 48, 31 },
  { 7143, 4, 0, 0, 0, 48, 31 },
  { 7636, 5, 0, 0, 0, 34, 31 },
  { 7656, 5, 0, 0, 0, 34, 31 },
  { 7671, 5, 0, 0, 0, 34, 31 },
  { 7686, 5, 0, 0, 0, 34, 31 },
  { 7706, 5, 0, 0, 0, 34, 31 },
  // 2539: get_image_width, get_image_channel_data_type, get_image_channel_order, 
  { 7155, 2, 0, 1, 0, 43, 31 },
  { 7167, 2, 0, 1, 0, 43, 31 },
  { 7157, 2, 0, 1, 0, 43, 31 },
  { 7159, 2, 0, 1, 0, 43, 31 },
  { 7169, 2, 0, 1, 0, 43, 31 },
  { 7171, 2, 0, 1, 0, 43, 31 },
  { 7173, 2, 0, 1, 0, 43, 31 },
  { 7175, 2, 0, 1, 0, 43, 31 },
  { 7187, 2, 0, 1, 0, 43, 31 },
  { 7189, 2, 0, 1, 0, 43, 31 },
  { 7191, 2, 0, 1, 0, 43, 31 },
  { 7193, 2, 0, 1, 0, 43, 31 },
  { 7195, 2, 0, 1, 0, 43, 31 },
  { 7197, 2, 0, 1, 0, 43, 31 },
  { 7199, 2, 0, 1, 0, 43, 31 },
  { 7201, 2, 0, 1, 0, 43, 31 },
  { 7219, 2, 0, 1, 0, 48, 31 },
  { 7221, 2, 0, 1, 0, 48, 31 },
  { 7223, 2, 0, 1, 0, 48, 31 },
  { 7225, 2, 0, 1, 0, 48, 31 },
  { 7227, 2, 0, 1, 0, 48, 31 },
  { 7229, 2, 0, 1, 0, 48, 31 },
  { 7233, 2, 0, 1, 0, 48, 31 },
  { 7235, 2, 0, 1, 0, 48, 31 },
  { 7743, 2, 0, 1, 0, 26, 31 },
  { 7749, 2, 0, 1, 0, 26, 31 },
  { 7753, 2, 0, 1, 0, 26, 31 },
  { 7757, 2, 0, 1, 0, 26, 31 },
  { 7763, 2, 0, 1, 0, 26, 31 },
  { 7767, 2, 0, 1, 0, 26, 31 },
  { 7771, 2, 0, 1, 0, 26, 31 },
  { 7775, 2, 0, 1, 0, 26, 31 },
  { 7815, 2, 0, 1, 0, 26, 31 },
  { 7819, 2, 0, 1, 0, 26, 31 },
  { 7823, 2, 0, 1, 0, 26, 31 },
  { 7827, 2, 0, 1, 0, 26, 31 },
  // 2575: get_image_height, 
  { 7157, 2, 0, 1, 0, 43, 31 },
  { 7159, 2, 0, 1, 0, 43, 31 },
  { 7171, 2, 0, 1, 0, 43, 31 },
  { 7173, 2, 0, 1, 0, 43, 31 },
  { 7175, 2, 0, 1, 0, 43, 31 },
  { 7191, 2, 0, 1, 0, 43, 31 },
  { 7193, 2, 0, 1, 0, 43, 31 },
  { 7197, 2, 0, 1, 0, 43, 31 },
  { 7199, 2, 0, 1, 0, 43, 31 },
  { 7201, 2, 0, 1, 0, 43, 31 },
  { 7223, 2, 0, 1, 0, 48, 31 },
  { 7225, 2, 0, 1, 0, 48, 31 },
  { 7229, 2, 0, 1, 0, 48, 31 },
  { 7233, 2, 0, 1, 0, 48, 31 },
  { 7235, 2, 0, 1, 0, 48, 31 },
  { 7743, 2, 0, 1, 0, 26, 31 },
  { 7749, 2, 0, 1, 0, 26, 31 },
  { 7753, 2, 0, 1, 0, 26, 31 },
  { 7757, 2, 0, 1, 0, 26, 31 },
  { 7763, 2, 0, 1, 0, 26, 31 },
  { 7767, 2, 0, 1, 0, 26, 31 },
  { 7771, 2, 0, 1, 0, 26, 31 },
  { 7775, 2, 0, 1, 0, 26, 31 },
  { 7815, 2, 0, 1, 0, 26, 31 },
  { 7819, 2, 0, 1, 0, 26, 31 },
  { 7823, 2, 0, 1, 0, 26, 31 },
  { 7827, 2, 0, 1, 0, 26, 31 },
  // 2602: get_image_depth, 
  { 7159, 2, 0, 1, 0, 43, 31 },
  { 7193, 2, 0, 1, 0, 43, 31 },
  { 7225, 2, 0, 1, 0, 48, 31 },
  // 2605: get_image_dim, 
  { 7161, 2, 0, 1, 0, 43, 31 },
  { 7163, 2, 0, 1, 0, 43, 31 },
  { 7177, 2, 0, 1, 0, 43, 31 },
  { 7179, 2, 0, 1, 0, 43, 31 },
  { 7181, 2, 0, 1, 0, 43, 31 },
  { 7203, 2, 0, 1, 0, 43, 31 },
  { 7205, 2, 0, 1, 0, 43, 31 },
  { 7207, 2, 0, 1, 0, 43, 31 },
  { 7209, 2, 0, 1, 0, 43, 31 },
  { 7211, 2, 0, 1, 0, 43, 31 },
  { 7239, 2, 0, 1, 0, 48, 31 },
  { 7241, 2, 0, 1, 0, 48, 31 },
  { 7243, 2, 0, 1, 0, 48, 31 },
  { 7245, 2, 0, 1, 0, 48, 31 },
  { 7247, 2, 0, 1, 0, 48, 31 },
  { 7745, 2, 0, 1, 0, 26, 31 },
  { 7751, 2, 0, 1, 0, 26, 31 },
  { 7755, 2, 0, 1, 0, 26, 31 },
  { 7759, 2, 0, 1, 0, 26, 31 },
  { 7765, 2, 0, 1, 0, 26, 31 },
  { 7769, 2, 0, 1, 0, 26, 31 },
  { 7773, 2, 0, 1, 0, 26, 31 },
  { 7777, 2, 0, 1, 0, 26, 31 },
  { 7817, 2, 0, 1, 0, 26, 31 },
  { 7821, 2, 0, 1, 0, 26, 31 },
  { 7825, 2, 0, 1, 0, 26, 31 },
  { 7829, 2, 0, 1, 0, 26, 31 },
  // 2632: get_image_array_size, 
  { 7165, 2, 0, 1, 0, 43, 31 },
  { 7183, 2, 0, 1, 0, 43, 31 },
  { 7185, 2, 0, 1, 0, 43, 31 },
  { 7213, 2, 0, 1, 0, 43, 31 },
  { 7215, 2, 0, 1, 0, 43, 31 },
  { 7217, 2, 0, 1, 0, 43, 31 },
  { 7249, 2, 0, 1, 0, 48, 31 },
  { 7253, 2, 0, 1, 0, 48, 31 },
  { 7255, 2, 0, 1, 0, 48, 31 },
  { 7747, 2, 0, 1, 0, 26, 31 },
  { 7761, 2, 0, 1, 0, 26, 31 },
  { 7779, 2, 0, 1, 0, 26, 31 },
  { 7781, 2, 0, 1, 0, 26, 31 },
  { 7831, 2, 0, 1, 0, 26, 31 },
  { 7833, 2, 0, 1, 0, 26, 31 },
  // 2647: read_imageh, 
  { 7257, 4, 1, 0, 0, 43, 31 },
  { 7261, 4, 1, 0, 0, 43, 31 },
  { 7265, 4, 1, 0, 0, 43, 31 },
  { 7269, 4, 1, 0, 0, 43, 31 },
  { 7273, 4, 1, 0, 0, 43, 31 },
  { 7277, 4, 1, 0, 0, 43, 31 },
  { 7281, 4, 1, 0, 0, 43, 31 },
  { 7285, 4, 1, 0, 0, 43, 31 },
  { 7291, 4, 1, 0, 0, 43, 31 },
  { 7295, 4, 1, 0, 0, 43, 31 },
  { 7299, 3, 1, 0, 0, 43, 28 },
  { 7302, 3, 1, 0, 0, 43, 28 },
  { 7305, 3, 1, 0, 0, 43, 28 },
  { 7308, 3, 1, 0, 0, 43, 28 },
  { 7311, 3, 1, 0, 0, 43, 28 },
  { 7314, 3, 1, 0, 0, 43, 28 },
  { 7319, 3, 1, 0, 0, 48, 28 },
  { 7322, 3, 1, 0, 0, 48, 28 },
  { 7325, 3, 1, 0, 0, 48, 28 },
  { 7328, 3, 1, 0, 0, 48, 28 },
  { 7331, 3, 1, 0, 0, 48, 28 },
  { 7334, 3, 1, 0, 0, 48, 28 },
  // 2669: write_imageh, 
  { 7337, 4, 0, 0, 0, 43, 31 },
  { 7341, 4, 0, 0, 0, 43, 31 },
  { 7345, 4, 0, 0, 0, 43, 31 },
  { 7349, 4, 0, 0, 0, 43, 31 },
  { 7355, 4, 0, 0, 0, 43, 31 },
  { 7359, 4, 0, 0, 0, 43, 31 },
  { 7363, 4, 0, 0, 0, 48, 31 },
  { 7367, 4, 0, 0, 0, 48, 31 },
  { 7371, 4, 0, 0, 0, 48, 31 },
  { 7375, 4, 0, 0, 0, 48, 31 },
  { 7379, 4, 0, 0, 0, 48, 31 },
  { 7383, 4, 0, 0, 0, 48, 31 },
  // 2681: work_group_all, work_group_any, 
  { 8, 2, 0, 0, 1, 49, 31 },
  // 2682: work_group_broadcast, 
  { 7387, 3, 0, 0, 1, 49, 31 },
  { 7390, 4, 0, 0, 1, 49, 31 },
  { 7394, 5, 0, 0, 1, 49, 31 },
  // 2685: work_group_reduce_add, work_group_scan_exclusive_add, work_group_scan_inclusive_add, work_group_reduce_min, work_group_scan_exclusive_min, work_group_scan_inclusive_min, work_group_reduce_max, work_group_scan_exclusive_max, work_group_scan_inclusive_max, 
  { 7399, 2, 0, 0, 1, 49, 31 },
  // 2686: is_valid_reserve_id, 
  { 7401, 2, 0, 0, 0, 47, 31 },
  // 2687: enqueue_marker, 
  { 7403, 5, 0, 0, 0, 44, 31 },
  // 2688: retain_event, release_event, 
  { 7408, 2, 0, 0, 0, 44, 31 },
  // 2689: create_user_event, 
  { 7410, 1, 0, 0, 0, 44, 31 },
  // 2690: is_valid_event, 
  { 7411, 2, 0, 0, 0, 44, 31 },
  // 2691: set_user_event_status, 
  { 7413, 3, 0, 0, 0, 44, 31 },
  // 2692: capture_event_profiling_info, 
  { 7416, 4, 0, 0, 0, 44, 31 },
  // 2693: get_default_queue, 
  { 7420, 1, 0, 0, 0, 44, 31 },
  // 2694: ndrange_1D, 
  { 7421, 2, 0, 0, 0, 44, 31 },
  { 7423, 3, 0, 0, 0, 44, 31 },
  { 7426, 4, 0, 0, 0, 44, 31 },
  // 2697: ndrange_2D, ndrange_3D, 
  { 7430, 2, 0, 0, 0, 44, 31 },
  { 7432, 3, 0, 0, 0, 44, 31 },
  { 7435, 4, 0, 0, 0, 44, 31 },
  // 2700: get_image_num_mip_levels, 
  { 7155, 2, 0, 0, 0, 33, 31 },
  { 7157, 2, 0, 0, 0, 33, 31 },
  { 7159, 2, 0, 0, 0, 33, 31 },
  { 7169, 2, 0, 0, 0, 33, 31 },
  { 7171, 2, 0, 0, 0, 33, 31 },
  { 7173, 2, 0, 0, 0, 33, 31 },
  { 7175, 2, 0, 0, 0, 33, 31 },
  { 7187, 2, 0, 0, 0, 33, 31 },
  { 7191, 2, 0, 0, 0, 33, 31 },
  { 7193, 2, 0, 0, 0, 33, 31 },
  { 7195, 2, 0, 0, 0, 33, 31 },
  { 7197, 2, 0, 0, 0, 33, 31 },
  { 7199, 2, 0, 0, 0, 33, 31 },
  { 7201, 2, 0, 0, 0, 33, 31 },
  { 7219, 2, 0, 0, 0, 33, 31 },
  { 7223, 2, 0, 0, 0, 33, 31 },
  { 7225, 2, 0, 0, 0, 33, 31 },
  { 7227, 2, 0, 0, 0, 33, 31 },
  { 7229, 2, 0, 0, 0, 33, 31 },
  { 7233, 2, 0, 0, 0, 33, 31 },
  { 7235, 2, 0, 0, 0, 33, 31 },
  // 2721: get_image_num_samples, 
  { 7743, 2, 0, 1, 0, 26, 31 },
  { 7749, 2, 0, 1, 0, 26, 31 },
  { 7753, 2, 0, 1, 0, 26, 31 },
  { 7757, 2, 0, 1, 0, 26, 31 },
  { 7763, 2, 0, 1, 0, 26, 31 },
  { 7767, 2, 0, 1, 0, 26, 31 },
  { 7771, 2, 0, 1, 0, 26, 31 },
  { 7775, 2, 0, 1, 0, 26, 31 },
  { 7815, 2, 0, 1, 0, 26, 31 },
  { 7819, 2, 0, 1, 0, 26, 31 },
  { 7823, 2, 0, 1, 0, 26, 31 },
  { 7827, 2, 0, 1, 0, 26, 31 },
  // 2733: get_sub_group_size, get_max_sub_group_size, get_num_sub_groups, get_sub_group_id, get_sub_group_local_id, 
  { 1409, 1, 0, 0, 0, 42, 31 },
  // 2734: get_enqueued_num_sub_groups, 
  { 1409, 1, 0, 0, 0, 42, 24 },
  // 2735: sub_group_barrier, 
  { 3801, 2, 0, 0, 1, 42, 31 },
  { 3803, 3, 0, 0, 1, 42, 24 },
  // 2737: sub_group_all, sub_group_any, 
  { 8, 2, 0, 0, 1, 42, 31 },
  // 2738: sub_group_broadcast, 
  { 7835, 3, 0, 0, 1, 42, 31 },
  { 7838, 3, 0, 0, 1, 37, 31 },
  { 7841, 3, 0, 0, 1, 37, 31 },
  // 2741: sub_group_reduce_add, sub_group_reduce_min, sub_group_reduce_max, sub_group_scan_exclusive_add, sub_group_scan_exclusive_min, sub_group_scan_exclusive_max, sub_group_scan_inclusive_add, sub_group_scan_inclusive_min, sub_group_scan_inclusive_max, 
  { 7399, 2, 0, 0, 1, 42, 31 },
  { 7844, 2, 0, 0, 1, 37, 31 },
  // 2743: sub_group_elect, 
  { 7846, 1, 0, 0, 0, 39, 31 },
  // 2744: sub_group_non_uniform_all, sub_group_non_uniform_any, 
  { 8, 2, 0, 0, 0, 39, 31 },
  // 2745: sub_group_non_uniform_all_equal, 
  { 7847, 2, 0, 0, 0, 39, 31 },
  // 2746: sub_group_non_uniform_broadcast, 
  { 7849, 3, 0, 0, 0, 35, 31 },
  // 2747: sub_group_broadcast_first, 
  { 4, 2, 0, 0, 0, 35, 31 },
  // 2748: sub_group_ballot, 
  { 7852, 2, 0, 0, 0, 35, 31 },
  // 2749: sub_group_inverse_ballot, 
  { 7854, 2, 0, 1, 0, 35, 31 },
  // 2750: sub_group_ballot_bit_extract, 
  { 7856, 3, 0, 1, 0, 35, 31 },
  // 2751: sub_group_ballot_bit_count, 
  { 7859, 2, 0, 1, 0, 35, 31 },
  // 2752: sub_group_ballot_inclusive_scan, sub_group_ballot_exclusive_scan, sub_group_ballot_find_lsb, sub_group_ballot_find_msb, 
  { 7859, 2, 0, 0, 0, 35, 31 },
  // 2753: get_sub_group_eq_mask, get_sub_group_ge_mask, get_sub_group_gt_mask, get_sub_group_le_mask, get_sub_group_lt_mask, 
  { 7861, 1, 0, 1, 0, 35, 31 },
};


// Find out whether a string matches an existing OpenCL builtin function name.
// Returns: A pair <0, 0> if no name matches.
//          A pair <Index, Len> indexing the BuiltinTable if the name is
//          matching an OpenCL builtin function.
static std::pair<unsigned, unsigned> isOpenCLBuiltin(llvm::StringRef Name) {

  switch (Name.size()) {
  default: break;
  case 3:	 // 19 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (Name[2] != 's')
          break;
        return std::make_pair(822, 1);	 // "abs"
      case 'l':	 // 1 string to match.
        if (Name[2] != 'l')
          break;
        return std::make_pair(886, 1);	 // "all"
      case 'n':	 // 1 string to match.
        if (Name[2] != 'y')
          break;
        return std::make_pair(886, 1);	 // "any"
      }
      break;
    case 'c':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (Name[2] != 'z')
          break;
        return std::make_pair(823, 1);	 // "clz"
      case 'o':	 // 1 string to match.
        if (Name[2] != 's')
          break;
        return std::make_pair(770, 1);	 // "cos"
      case 't':	 // 1 string to match.
        if (Name[2] != 'z')
          break;
        return std::make_pair(825, 1);	 // "ctz"
      }
      break;
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ot", 2) != 0)
        break;
      return std::make_pair(81, 7);	 // "dot"
    case 'e':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'r':	 // 1 string to match.
        if (Name[2] != 'f')
          break;
        return std::make_pair(770, 1);	 // "erf"
      case 'x':	 // 1 string to match.
        if (Name[2] != 'p')
          break;
        return std::make_pair(770, 1);	 // "exp"
      }
      break;
    case 'f':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ma", 2) != 0)
        break;
      return std::make_pair(791, 1);	 // "fma"
    case 'l':	 // 1 string to match.
      if (memcmp(Name.data()+1, "og", 2) != 0)
        break;
      return std::make_pair(770, 1);	 // "log"
    case 'm':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 1 string to match.
          return std::make_pair(791, 1);	 // "mad"
        case 'x':	 // 1 string to match.
          return std::make_pair(828, 6);	 // "max"
        }
        break;
      case 'i':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'n':	 // 1 string to match.
          return std::make_pair(828, 6);	 // "min"
        case 'x':	 // 1 string to match.
          return std::make_pair(855, 4);	 // "mix"
        }
        break;
      }
      break;
    case 'n':	 // 1 string to match.
      if (memcmp(Name.data()+1, "an", 2) != 0)
        break;
      return std::make_pair(771, 3);	 // "nan"
    case 'p':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ow", 2) != 0)
        break;
      return std::make_pair(774, 1);	 // "pow"
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "in", 2) != 0)
        break;
      return std::make_pair(770, 1);	 // "sin"
    case 't':	 // 1 string to match.
      if (memcmp(Name.data()+1, "an", 2) != 0)
        break;
      return std::make_pair(770, 1);	 // "tan"
    }
    break;
  case 4:	 // 25 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+2, "os", 2) != 0)
          break;
        return std::make_pair(770, 1);	 // "acos"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "in", 2) != 0)
          break;
        return std::make_pair(770, 1);	 // "asin"
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+2, "an", 2) != 0)
          break;
        return std::make_pair(770, 1);	 // "atan"
      }
      break;
    case 'c':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+2, "rt", 2) != 0)
          break;
        return std::make_pair(770, 1);	 // "cbrt"
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "il", 2) != 0)
          break;
        return std::make_pair(770, 1);	 // "ceil"
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+2, "sh", 2) != 0)
          break;
        return std::make_pair(770, 1);	 // "cosh"
      }
      break;
    case 'e':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "fc", 2) != 0)
          break;
        return std::make_pair(770, 1);	 // "erfc"
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+2, "p2", 2) != 0)
          break;
        return std::make_pair(770, 1);	 // "exp2"
      }
      break;
    case 'f':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "bs", 2) != 0)
          break;
        return std::make_pair(770, 1);	 // "fabs"
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "im", 2) != 0)
          break;
        return std::make_pair(774, 1);	 // "fdim"
      case 'm':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (Name[3] != 'x')
            break;
          return std::make_pair(775, 4);	 // "fmax"
        case 'i':	 // 1 string to match.
          if (Name[3] != 'n')
            break;
          return std::make_pair(775, 4);	 // "fmin"
        case 'o':	 // 1 string to match.
          if (Name[3] != 'd')
            break;
          return std::make_pair(774, 1);	 // "fmod"
        }
        break;
      }
      break;
    case 'h':	 // 1 string to match.
      if (memcmp(Name.data()+1, "add", 3) != 0)
        break;
      return std::make_pair(827, 1);	 // "hadd"
    case 'l':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "og", 2) != 0)
        break;
      switch (Name[3]) {
      default: break;
      case '2':	 // 1 string to match.
        return std::make_pair(770, 1);	 // "log2"
      case 'b':	 // 1 string to match.
        return std::make_pair(770, 1);	 // "logb"
      }
      break;
    case 'm':	 // 1 string to match.
      if (memcmp(Name.data()+1, "odf", 3) != 0)
        break;
      return std::make_pair(792, 4);	 // "modf"
    case 'p':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "ow", 2) != 0)
        break;
      switch (Name[3]) {
      default: break;
      case 'n':	 // 1 string to match.
        return std::make_pair(788, 3);	 // "pown"
      case 'r':	 // 1 string to match.
        return std::make_pair(774, 1);	 // "powr"
      }
      break;
    case 'r':	 // 1 string to match.
      if (memcmp(Name.data()+1, "int", 3) != 0)
        break;
      return std::make_pair(770, 1);	 // "rint"
    case 's':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'i':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'g':	 // 1 string to match.
          if (Name[3] != 'n')
            break;
          return std::make_pair(770, 1);	 // "sign"
        case 'n':	 // 1 string to match.
          if (Name[3] != 'h')
            break;
          return std::make_pair(770, 1);	 // "sinh"
        }
        break;
      case 'q':	 // 1 string to match.
        if (memcmp(Name.data()+2, "rt", 2) != 0)
          break;
        return std::make_pair(770, 1);	 // "sqrt"
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ep", 2) != 0)
          break;
        return std::make_pair(851, 4);	 // "step"
      }
      break;
    case 't':	 // 1 string to match.
      if (memcmp(Name.data()+1, "anh", 3) != 0)
        break;
      return std::make_pair(770, 1);	 // "tanh"
    }
    break;
  case 5:	 // 28 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+2, "osh", 3) != 0)
          break;
        return std::make_pair(770, 1);	 // "acosh"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "inh", 3) != 0)
          break;
        return std::make_pair(770, 1);	 // "asinh"
      case 't':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "an", 2) != 0)
          break;
        switch (Name[4]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(774, 1);	 // "atan2"
        case 'h':	 // 1 string to match.
          return std::make_pair(770, 1);	 // "atanh"
        }
        break;
      }
      break;
    case 'c':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "amp", 3) != 0)
          break;
        return std::make_pair(840, 6);	 // "clamp"
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+2, "spi", 3) != 0)
          break;
        return std::make_pair(770, 1);	 // "cospi"
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "oss", 3) != 0)
          break;
        return std::make_pair(871, 6);	 // "cross"
      }
      break;
    case 'e':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "xp", 2) != 0)
        break;
      switch (Name[3]) {
      default: break;
      case '1':	 // 1 string to match.
        if (Name[4] != '0')
          break;
        return std::make_pair(770, 1);	 // "exp10"
      case 'm':	 // 1 string to match.
        if (Name[4] != '1')
          break;
        return std::make_pair(770, 1);	 // "expm1"
      }
      break;
    case 'f':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "oor", 3) != 0)
          break;
        return std::make_pair(770, 1);	 // "floor"
      case 'r':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ct", 2) != 0)
            break;
          return std::make_pair(792, 4);	 // "fract"
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "xp", 2) != 0)
            break;
          return std::make_pair(796, 12);	 // "frexp"
        }
        break;
      }
      break;
    case 'h':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ypot", 4) != 0)
        break;
      return std::make_pair(774, 1);	 // "hypot"
    case 'i':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ogb", 3) != 0)
          break;
        return std::make_pair(779, 3);	 // "ilogb"
      case 's':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+3, "nf", 2) != 0)
            break;
          return std::make_pair(881, 5);	 // "isinf"
        case 'n':	 // 1 string to match.
          if (memcmp(Name.data()+3, "an", 2) != 0)
            break;
          return std::make_pair(881, 5);	 // "isnan"
        }
        break;
      }
      break;
    case 'l':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "exp", 3) != 0)
          break;
        return std::make_pair(782, 6);	 // "ldexp"
      case 'o':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "g1", 2) != 0)
          break;
        switch (Name[4]) {
        default: break;
        case '0':	 // 1 string to match.
          return std::make_pair(770, 1);	 // "log10"
        case 'p':	 // 1 string to match.
          return std::make_pair(770, 1);	 // "log1p"
        }
        break;
      }
      break;
    case 'm':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "d24", 3) != 0)
          break;
        return std::make_pair(847, 2);	 // "mad24"
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+2, "l24", 3) != 0)
          break;
        return std::make_pair(849, 2);	 // "mul24"
      }
      break;
    case 'r':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'h':	 // 1 string to match.
        if (memcmp(Name.data()+2, "add", 3) != 0)
          break;
        return std::make_pair(827, 1);	 // "rhadd"
      case 'o':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'o':	 // 1 string to match.
          if (memcmp(Name.data()+3, "tn", 2) != 0)
            break;
          return std::make_pair(788, 3);	 // "rootn"
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+3, "nd", 2) != 0)
            break;
          return std::make_pair(770, 1);	 // "round"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "qrt", 3) != 0)
          break;
        return std::make_pair(770, 1);	 // "rsqrt"
      }
      break;
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "inpi", 4) != 0)
        break;
      return std::make_pair(770, 1);	 // "sinpi"
    case 't':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "npi", 3) != 0)
          break;
        return std::make_pair(770, 1);	 // "tanpi"
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "unc", 3) != 0)
          break;
        return std::make_pair(770, 1);	 // "trunc"
      }
      break;
    }
    break;
  case 6:	 // 19 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ospi", 4) != 0)
          break;
        return std::make_pair(770, 1);	 // "acospi"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "inpi", 4) != 0)
          break;
        return std::make_pair(770, 1);	 // "asinpi"
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+2, "anpi", 4) != 0)
          break;
        return std::make_pair(770, 1);	 // "atanpi"
      }
      break;
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+1, "sless", 5) != 0)
        break;
      return std::make_pair(887, 5);	 // "isless"
    case 'l':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ngth", 4) != 0)
          break;
        return std::make_pair(863, 3);	 // "length"
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+2, "amma", 4) != 0)
          break;
        return std::make_pair(770, 1);	 // "lgamma"
      }
      break;
    case 'm':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+3, "_hi", 3) != 0)
            break;
          return std::make_pair(846, 1);	 // "mad_hi"
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+3, "mag", 3) != 0)
            break;
          return std::make_pair(774, 1);	 // "maxmag"
        }
        break;
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+2, "nmag", 4) != 0)
          break;
        return std::make_pair(774, 1);	 // "minmag"
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+2, "l_hi", 4) != 0)
          break;
        return std::make_pair(827, 1);	 // "mul_hi"
      }
      break;
    case 'r':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "mquo", 4) != 0)
          break;
        return std::make_pair(808, 12);	 // "remquo"
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+2, "tate", 4) != 0)
          break;
        return std::make_pair(827, 1);	 // "rotate"
      }
      break;
    case 's':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "lect", 4) != 0)
          break;
        return std::make_pair(893, 10);	 // "select"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ncos", 4) != 0)
          break;
        return std::make_pair(792, 4);	 // "sincos"
      }
      break;
    case 't':	 // 1 string to match.
      if (memcmp(Name.data()+1, "gamma", 5) != 0)
        break;
      return std::make_pair(770, 1);	 // "tgamma"
    case 'v':	 // 4 strings to match.
      if (memcmp(Name.data()+1, "load", 4) != 0)
        break;
      switch (Name[5]) {
      default: break;
      case '2':	 // 1 string to match.
        return std::make_pair(903, 55);	 // "vload2"
      case '3':	 // 1 string to match.
        return std::make_pair(1002, 55);	 // "vload3"
      case '4':	 // 1 string to match.
        return std::make_pair(1101, 55);	 // "vload4"
      case '8':	 // 1 string to match.
        return std::make_pair(1200, 55);	 // "vload8"
      }
      break;
    }
    break;
  case 7:	 // 17 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "d_sat", 5) != 0)
          break;
        return std::make_pair(827, 1);	 // "add_sat"
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "m_dot", 5) != 0)
          break;
        return std::make_pair(109, 2);	 // "arm_dot"
      case 't':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+3, "n2pi", 4) != 0)
            break;
          return std::make_pair(774, 1);	 // "atan2pi"
        case 'o':	 // 1 string to match.
          if (memcmp(Name.data()+3, "m_or", 4) != 0)
            break;
          return std::make_pair(1512, 8);	 // "atom_or"
        }
        break;
      }
      break;
    case 'b':	 // 1 string to match.
      if (memcmp(Name.data()+1, "arrier", 6) != 0)
        break;
      return std::make_pair(1476, 1);	 // "barrier"
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "egrees", 6) != 0)
        break;
      return std::make_pair(770, 1);	 // "degrees"
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+1, "sequal", 6) != 0)
        break;
      return std::make_pair(887, 5);	 // "isequal"
    case 'm':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ad_sat", 6) != 0)
        break;
      return std::make_pair(846, 1);	 // "mad_sat"
    case 'r':	 // 1 string to match.
      if (memcmp(Name.data()+1, "adians", 6) != 0)
        break;
      return std::make_pair(770, 1);	 // "radians"
    case 's':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'h':	 // 1 string to match.
        if (memcmp(Name.data()+2, "uffle", 5) != 0)
          break;
        return std::make_pair(2006, 176);	 // "shuffle"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+2, "gnbit", 5) != 0)
          break;
        return std::make_pair(881, 5);	 // "signbit"
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+2, "b_sat", 5) != 0)
          break;
        return std::make_pair(827, 1);	 // "sub_sat"
      }
      break;
    case 'v':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "oad16", 5) != 0)
          break;
        return std::make_pair(1299, 55);	 // "vload16"
      case 's':	 // 4 strings to match.
        if (memcmp(Name.data()+2, "tore", 4) != 0)
          break;
        switch (Name[6]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(958, 44);	 // "vstore2"
        case '3':	 // 1 string to match.
          return std::make_pair(1057, 44);	 // "vstore3"
        case '4':	 // 1 string to match.
          return std::make_pair(1156, 44);	 // "vstore4"
        case '8':	 // 1 string to match.
          return std::make_pair(1255, 44);	 // "vstore8"
        }
        break;
      }
      break;
    }
    break;
  case 8:	 // 24 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 9 strings to match.
      switch (Name[1]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+2, "s_diff", 6) != 0)
          break;
        return std::make_pair(826, 1);	 // "abs_diff"
      case 't':	 // 8 strings to match.
        if (memcmp(Name.data()+2, "om_", 3) != 0)
          break;
        switch (Name[5]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[6]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[7] != 'd')
              break;
            return std::make_pair(1488, 8);	 // "atom_add"
          case 'n':	 // 1 string to match.
            if (Name[7] != 'd')
              break;
            return std::make_pair(1512, 8);	 // "atom_and"
          }
          break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+6, "ec", 2) != 0)
            break;
          return std::make_pair(1496, 8);	 // "atom_dec"
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+6, "nc", 2) != 0)
            break;
          return std::make_pair(1496, 8);	 // "atom_inc"
        case 'm':	 // 2 strings to match.
          switch (Name[6]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (Name[7] != 'x')
              break;
            return std::make_pair(1512, 8);	 // "atom_max"
          case 'i':	 // 1 string to match.
            if (Name[7] != 'n')
              break;
            return std::make_pair(1512, 8);	 // "atom_min"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+6, "ub", 2) != 0)
            break;
          return std::make_pair(1488, 8);	 // "atom_sub"
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+6, "or", 2) != 0)
            break;
          return std::make_pair(1512, 8);	 // "atom_xor"
        }
        break;
      }
      break;
    case 'c':	 // 1 string to match.
      if (memcmp(Name.data()+1, "opysign", 7) != 0)
        break;
      return std::make_pair(774, 1);	 // "copysign"
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "istance", 7) != 0)
        break;
      return std::make_pair(877, 3);	 // "distance"
    case 'h':	 // 5 strings to match.
      if (memcmp(Name.data()+1, "alf_", 4) != 0)
        break;
      switch (Name[5]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+6, "os", 2) != 0)
          break;
        return std::make_pair(820, 1);	 // "half_cos"
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+6, "xp", 2) != 0)
          break;
        return std::make_pair(820, 1);	 // "half_exp"
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+6, "og", 2) != 0)
          break;
        return std::make_pair(820, 1);	 // "half_log"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+6, "in", 2) != 0)
          break;
        return std::make_pair(820, 1);	 // "half_sin"
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+6, "an", 2) != 0)
          break;
        return std::make_pair(820, 1);	 // "half_tan"
      }
      break;
    case 'i':	 // 2 strings to match.
      if (Name[1] != 's')
        break;
      switch (Name[2]) {
      default: break;
      case 'f':	 // 1 string to match.
        if (memcmp(Name.data()+3, "inite", 5) != 0)
          break;
        return std::make_pair(881, 5);	 // "isfinite"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+3, "ormal", 5) != 0)
          break;
        return std::make_pair(881, 5);	 // "isnormal"
      }
      break;
    case 'l':	 // 1 string to match.
      if (memcmp(Name.data()+1, "gamma_r", 7) != 0)
        break;
      return std::make_pair(796, 12);	 // "lgamma_r"
    case 'p':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+2, "pcount", 6) != 0)
          break;
        return std::make_pair(824, 1);	 // "popcount"
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "efetch", 6) != 0)
          break;
        return std::make_pair(1487, 1);	 // "prefetch"
      }
      break;
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "huffle2", 7) != 0)
        break;
      return std::make_pair(2182, 176);	 // "shuffle2"
    case 'u':	 // 1 string to match.
      if (memcmp(Name.data()+1, "psample", 7) != 0)
        break;
      return std::make_pair(834, 6);	 // "upsample"
    case 'v':	 // 1 string to match.
      if (memcmp(Name.data()+1, "store16", 7) != 0)
        break;
      return std::make_pair(1354, 44);	 // "vstore16"
    }
    break;
  case 9:	 // 14 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "tom", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case '_':	 // 1 string to match.
        if (memcmp(Name.data()+5, "xchg", 4) != 0)
          break;
        return std::make_pair(1488, 8);	 // "atom_xchg"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+5, "c_or", 4) != 0)
          break;
        return std::make_pair(1528, 6);	 // "atomic_or"
      }
      break;
    case 'b':	 // 1 string to match.
      if (memcmp(Name.data()+1, "itselect", 8) != 0)
        break;
      return std::make_pair(892, 1);	 // "bitselect"
    case 'g':	 // 1 string to match.
      if (memcmp(Name.data()+1, "et_fence", 8) != 0)
        break;
      return std::make_pair(1480, 2);	 // "get_fence"
    case 'h':	 // 4 strings to match.
      if (memcmp(Name.data()+1, "alf_", 4) != 0)
        break;
      switch (Name[5]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+6, "xp2", 3) != 0)
          break;
        return std::make_pair(820, 1);	 // "half_exp2"
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+6, "og2", 3) != 0)
          break;
        return std::make_pair(820, 1);	 // "half_log2"
      case 'p':	 // 1 string to match.
        if (memcmp(Name.data()+6, "owr", 3) != 0)
          break;
        return std::make_pair(821, 1);	 // "half_powr"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+6, "qrt", 3) != 0)
          break;
        return std::make_pair(820, 1);	 // "half_sqrt"
      }
      break;
    case 'i':	 // 2 strings to match.
      if (Name[1] != 's')
        break;
      switch (Name[2]) {
      default: break;
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+3, "reater", 6) != 0)
          break;
        return std::make_pair(887, 5);	 // "isgreater"
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+3, "rdered", 6) != 0)
          break;
        return std::make_pair(887, 5);	 // "isordered"
      }
      break;
    case 'm':	 // 1 string to match.
      if (memcmp(Name.data()+1, "em_fence", 8) != 0)
        break;
      return std::make_pair(1479, 1);	 // "mem_fence"
    case 'n':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "xtafter", 7) != 0)
          break;
        return std::make_pair(774, 1);	 // "nextafter"
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+2, "rmalize", 7) != 0)
          break;
        return std::make_pair(866, 3);	 // "normalize"
      }
      break;
    case 'r':	 // 1 string to match.
      if (memcmp(Name.data()+1, "emainder", 8) != 0)
        break;
      return std::make_pair(774, 1);	 // "remainder"
    }
    break;
  case 10:	 // 23 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 8 strings to match.
      if (memcmp(Name.data()+1, "tomic_", 6) != 0)
        break;
      switch (Name[7]) {
      default: break;
      case 'a':	 // 2 strings to match.
        switch (Name[8]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[9] != 'd')
            break;
          return std::make_pair(1528, 6);	 // "atomic_add"
        case 'n':	 // 1 string to match.
          if (Name[9] != 'd')
            break;
          return std::make_pair(1528, 6);	 // "atomic_and"
        }
        break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+8, "ec", 2) != 0)
          break;
        return std::make_pair(1534, 6);	 // "atomic_dec"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+8, "nc", 2) != 0)
          break;
        return std::make_pair(1534, 6);	 // "atomic_inc"
      case 'm':	 // 2 strings to match.
        switch (Name[8]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (Name[9] != 'x')
            break;
          return std::make_pair(1528, 6);	 // "atomic_max"
        case 'i':	 // 1 string to match.
          if (Name[9] != 'n')
            break;
          return std::make_pair(1528, 6);	 // "atomic_min"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+8, "ub", 2) != 0)
          break;
        return std::make_pair(1528, 6);	 // "atomic_sub"
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+8, "or", 2) != 0)
          break;
        return std::make_pair(1528, 6);	 // "atomic_xor"
      }
      break;
    case 'h':	 // 4 strings to match.
      if (memcmp(Name.data()+1, "alf_", 4) != 0)
        break;
      switch (Name[5]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+6, "xp10", 4) != 0)
          break;
        return std::make_pair(820, 1);	 // "half_exp10"
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+6, "og10", 4) != 0)
          break;
        return std::make_pair(820, 1);	 // "half_log10"
      case 'r':	 // 2 strings to match.
        switch (Name[6]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+7, "cip", 3) != 0)
            break;
          return std::make_pair(820, 1);	 // "half_recip"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+7, "qrt", 3) != 0)
            break;
          return std::make_pair(820, 1);	 // "half_rsqrt"
        }
        break;
      }
      break;
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+1, "snotequal", 9) != 0)
        break;
      return std::make_pair(887, 5);	 // "isnotequal"
    case 'n':	 // 8 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 5 strings to match.
        if (memcmp(Name.data()+2, "tive_", 5) != 0)
          break;
        switch (Name[7]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+8, "os", 2) != 0)
            break;
          return std::make_pair(820, 1);	 // "native_cos"
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+8, "xp", 2) != 0)
            break;
          return std::make_pair(820, 1);	 // "native_exp"
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+8, "og", 2) != 0)
            break;
          return std::make_pair(820, 1);	 // "native_log"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+8, "in", 2) != 0)
            break;
          return std::make_pair(820, 1);	 // "native_sin"
        case 't':	 // 1 string to match.
          if (memcmp(Name.data()+8, "an", 2) != 0)
            break;
          return std::make_pair(820, 1);	 // "native_tan"
        }
        break;
      case 'd':	 // 3 strings to match.
        if (memcmp(Name.data()+2, "range_", 6) != 0)
          break;
        switch (Name[8]) {
        default: break;
        case '1':	 // 1 string to match.
          if (Name[9] != 'D')
            break;
          return std::make_pair(2694, 3);	 // "ndrange_1D"
        case '2':	 // 1 string to match.
          if (Name[9] != 'D')
            break;
          return std::make_pair(2697, 3);	 // "ndrange_2D"
        case '3':	 // 1 string to match.
          if (Name[9] != 'D')
            break;
          return std::make_pair(2697, 3);	 // "ndrange_3D"
        }
        break;
      }
      break;
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "moothstep", 9) != 0)
        break;
      return std::make_pair(859, 4);	 // "smoothstep"
    case 'v':	 // 1 string to match.
      if (memcmp(Name.data()+1, "load_half", 9) != 0)
        break;
      return std::make_pair(1398, 5);	 // "vload_half"
    }
    break;
  case 11:	 // 23 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "m_dot_acc", 9) != 0)
          break;
        return std::make_pair(111, 4);	 // "arm_dot_acc"
      case 't':	 // 3 strings to match.
        if (memcmp(Name.data()+2, "omic_", 5) != 0)
          break;
        switch (Name[7]) {
        default: break;
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+8, "nit", 3) != 0)
            break;
          return std::make_pair(1609, 18);	 // "atomic_init"
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+8, "oad", 3) != 0)
            break;
          return std::make_pair(1754, 21);	 // "atomic_load"
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+8, "chg", 3) != 0)
            break;
          return std::make_pair(1520, 8);	 // "atomic_xchg"
        }
        break;
      }
      break;
    case 'b':	 // 1 string to match.
      if (memcmp(Name.data()+1, "it_reverse", 10) != 0)
        break;
      return std::make_pair(80, 1);	 // "bit_reverse"
    case 'c':	 // 1 string to match.
      if (memcmp(Name.data()+1, "onvert_int", 10) != 0)
        break;
      return std::make_pair(436, 11);	 // "convert_int"
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ot_acc_sat", 10) != 0)
        break;
      return std::make_pair(99, 4);	 // "dot_acc_sat"
    case 'f':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ast_length", 10) != 0)
        break;
      return std::make_pair(869, 1);	 // "fast_length"
    case 'h':	 // 1 string to match.
      if (memcmp(Name.data()+1, "alf_divide", 10) != 0)
        break;
      return std::make_pair(821, 1);	 // "half_divide"
    case 'i':	 // 2 strings to match.
      if (Name[1] != 's')
        break;
      switch (Name[2]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+3, "essequal", 8) != 0)
          break;
        return std::make_pair(887, 5);	 // "islessequal"
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+3, "nordered", 8) != 0)
          break;
        return std::make_pair(887, 5);	 // "isunordered"
      }
      break;
    case 'n':	 // 4 strings to match.
      if (memcmp(Name.data()+1, "ative_", 6) != 0)
        break;
      switch (Name[7]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+8, "xp2", 3) != 0)
          break;
        return std::make_pair(820, 1);	 // "native_exp2"
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+8, "og2", 3) != 0)
          break;
        return std::make_pair(820, 1);	 // "native_log2"
      case 'p':	 // 1 string to match.
        if (memcmp(Name.data()+8, "owr", 3) != 0)
          break;
        return std::make_pair(821, 1);	 // "native_powr"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+8, "qrt", 3) != 0)
          break;
        return std::make_pair(820, 1);	 // "native_sqrt"
      }
      break;
    case 'r':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "ead_image", 9) != 0)
        break;
      switch (Name[10]) {
      default: break;
      case 'f':	 // 1 string to match.
        return std::make_pair(2358, 52);	 // "read_imagef"
      case 'h':	 // 1 string to match.
        return std::make_pair(2647, 22);	 // "read_imageh"
      case 'i':	 // 1 string to match.
        return std::make_pair(2410, 36);	 // "read_imagei"
      }
      break;
    case 'v':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 4 strings to match.
        if (memcmp(Name.data()+2, "oad_half", 8) != 0)
          break;
        switch (Name[10]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(1403, 5);	 // "vload_half2"
        case '3':	 // 1 string to match.
          return std::make_pair(1424, 5);	 // "vload_half3"
        case '4':	 // 1 string to match.
          return std::make_pair(1429, 5);	 // "vload_half4"
        case '8':	 // 1 string to match.
          return std::make_pair(1434, 5);	 // "vload_half8"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "tore_half", 9) != 0)
          break;
        return std::make_pair(1408, 8);	 // "vstore_half"
      }
      break;
    }
    break;
  case 12:	 // 31 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "tom", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case '_':	 // 1 string to match.
        if (memcmp(Name.data()+5, "cmpxchg", 7) != 0)
          break;
        return std::make_pair(1504, 8);	 // "atom_cmpxchg"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+5, "c_store", 7) != 0)
          break;
        return std::make_pair(1546, 21);	 // "atomic_store"
      }
      break;
    case 'c':	 // 8 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+9, "har", 3) != 0)
          break;
        return std::make_pair(172, 11);	 // "convert_char"
      case 'h':	 // 1 string to match.
        if (memcmp(Name.data()+9, "alf", 3) != 0)
          break;
        return std::make_pair(26, 11);	 // "convert_half"
      case 'i':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "nt", 2) != 0)
          break;
        switch (Name[11]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(447, 11);	 // "convert_int2"
        case '3':	 // 1 string to match.
          return std::make_pair(458, 11);	 // "convert_int3"
        case '4':	 // 1 string to match.
          return std::make_pair(469, 11);	 // "convert_int4"
        case '8':	 // 1 string to match.
          return std::make_pair(480, 11);	 // "convert_int8"
        }
        break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+9, "ong", 3) != 0)
          break;
        return std::make_pair(634, 11);	 // "convert_long"
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+9, "int", 3) != 0)
          break;
        return std::make_pair(502, 11);	 // "convert_uint"
      }
      break;
    case 'g':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+5, "roup_id", 7) != 0)
          break;
        return std::make_pair(767, 1);	 // "get_group_id"
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+5, "ocal_id", 7) != 0)
          break;
        return std::make_pair(767, 1);	 // "get_local_id"
      case 'w':	 // 1 string to match.
        if (memcmp(Name.data()+5, "ork_dim", 7) != 0)
          break;
        return std::make_pair(766, 1);	 // "get_work_dim"
      }
      break;
    case 'n':	 // 4 strings to match.
      if (memcmp(Name.data()+1, "ative_", 6) != 0)
        break;
      switch (Name[7]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+8, "xp10", 4) != 0)
          break;
        return std::make_pair(820, 1);	 // "native_exp10"
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+8, "og10", 4) != 0)
          break;
        return std::make_pair(820, 1);	 // "native_log10"
      case 'r':	 // 2 strings to match.
        switch (Name[8]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+9, "cip", 3) != 0)
            break;
          return std::make_pair(820, 1);	 // "native_recip"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+9, "qrt", 3) != 0)
            break;
          return std::make_pair(820, 1);	 // "native_rsqrt"
        }
        break;
      }
      break;
    case 'r':	 // 2 strings to match.
      if (Name[1] != 'e')
        break;
      switch (Name[2]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+3, "d_imageui", 9) != 0)
          break;
        return std::make_pair(2446, 36);	 // "read_imageui"
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+3, "ain_event", 9) != 0)
          break;
        return std::make_pair(2688, 1);	 // "retain_event"
      }
      break;
    case 'v':	 // 9 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 5 strings to match.
        if (memcmp(Name.data()+2, "oad", 3) != 0)
          break;
        switch (Name[5]) {
        default: break;
        case '_':	 // 1 string to match.
          if (memcmp(Name.data()+6, "half16", 6) != 0)
            break;
          return std::make_pair(1439, 5);	 // "vload_half16"
        case 'a':	 // 4 strings to match.
          if (memcmp(Name.data()+6, "_half", 5) != 0)
            break;
          switch (Name[11]) {
          default: break;
          case '2':	 // 1 string to match.
            return std::make_pair(1403, 5);	 // "vloada_half2"
          case '3':	 // 1 string to match.
            return std::make_pair(1424, 5);	 // "vloada_half3"
          case '4':	 // 1 string to match.
            return std::make_pair(1429, 5);	 // "vloada_half4"
          case '8':	 // 1 string to match.
            return std::make_pair(1434, 5);	 // "vloada_half8"
          }
          break;
        }
        break;
      case 's':	 // 4 strings to match.
        if (memcmp(Name.data()+2, "tore_half", 9) != 0)
          break;
        switch (Name[11]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(1416, 8);	 // "vstore_half2"
        case '3':	 // 1 string to match.
          return std::make_pair(1444, 8);	 // "vstore_half3"
        case '4':	 // 1 string to match.
          return std::make_pair(1452, 8);	 // "vstore_half4"
        case '8':	 // 1 string to match.
          return std::make_pair(1460, 8);	 // "vstore_half8"
        }
        break;
      }
      break;
    case 'w':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "rite_image", 10) != 0)
        break;
      switch (Name[11]) {
      default: break;
      case 'f':	 // 1 string to match.
        return std::make_pair(2482, 23);	 // "write_imagef"
      case 'h':	 // 1 string to match.
        return std::make_pair(2669, 12);	 // "write_imageh"
      case 'i':	 // 1 string to match.
        return std::make_pair(2505, 17);	 // "write_imagei"
      }
      break;
    }
    break;
  case 13:	 // 36 strings to match.
    switch (Name[0]) {
    default: break;
    case 'c':	 // 21 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 'c':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "har", 3) != 0)
          break;
        switch (Name[12]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(183, 11);	 // "convert_char2"
        case '3':	 // 1 string to match.
          return std::make_pair(194, 11);	 // "convert_char3"
        case '4':	 // 1 string to match.
          return std::make_pair(205, 11);	 // "convert_char4"
        case '8':	 // 1 string to match.
          return std::make_pair(216, 11);	 // "convert_char8"
        }
        break;
      case 'f':	 // 1 string to match.
        if (memcmp(Name.data()+9, "loat", 4) != 0)
          break;
        return std::make_pair(161, 11);	 // "convert_float"
      case 'h':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "alf", 3) != 0)
          break;
        switch (Name[12]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(37, 11);	 // "convert_half2"
        case '3':	 // 1 string to match.
          return std::make_pair(50, 11);	 // "convert_half3"
        case '4':	 // 1 string to match.
          return std::make_pair(64, 11);	 // "convert_half4"
        case '8':	 // 1 string to match.
          return std::make_pair(88, 11);	 // "convert_half8"
        }
        break;
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+9, "nt16", 4) != 0)
          break;
        return std::make_pair(491, 11);	 // "convert_int16"
      case 'l':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "ong", 3) != 0)
          break;
        switch (Name[12]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(645, 11);	 // "convert_long2"
        case '3':	 // 1 string to match.
          return std::make_pair(656, 11);	 // "convert_long3"
        case '4':	 // 1 string to match.
          return std::make_pair(667, 11);	 // "convert_long4"
        case '8':	 // 1 string to match.
          return std::make_pair(678, 11);	 // "convert_long8"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+9, "hort", 4) != 0)
          break;
        return std::make_pair(304, 11);	 // "convert_short"
      case 'u':	 // 6 strings to match.
        switch (Name[9]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+10, "har", 3) != 0)
            break;
          return std::make_pair(238, 11);	 // "convert_uchar"
        case 'i':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "nt", 2) != 0)
            break;
          switch (Name[12]) {
          default: break;
          case '2':	 // 1 string to match.
            return std::make_pair(513, 11);	 // "convert_uint2"
          case '3':	 // 1 string to match.
            return std::make_pair(524, 11);	 // "convert_uint3"
          case '4':	 // 1 string to match.
            return std::make_pair(535, 11);	 // "convert_uint4"
          case '8':	 // 1 string to match.
            return std::make_pair(546, 11);	 // "convert_uint8"
          }
          break;
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+10, "ong", 3) != 0)
            break;
          return std::make_pair(700, 11);	 // "convert_ulong"
        }
        break;
      }
      break;
    case 'f':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ast_distance", 12) != 0)
        break;
      return std::make_pair(880, 1);	 // "fast_distance"
    case 'g':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+5, "lobal_id", 8) != 0)
          break;
        return std::make_pair(767, 1);	 // "get_global_id"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+5, "mage_dim", 8) != 0)
          break;
        return std::make_pair(2605, 27);	 // "get_image_dim"
      }
      break;
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+1, "slessgreater", 12) != 0)
        break;
      return std::make_pair(887, 5);	 // "islessgreater"
    case 'n':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ative_divide", 12) != 0)
        break;
      return std::make_pair(821, 1);	 // "native_divide"
    case 'r':	 // 1 string to match.
      if (memcmp(Name.data()+1, "elease_event", 12) != 0)
        break;
      return std::make_pair(2688, 1);	 // "release_event"
    case 's':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "ub_group_a", 10) != 0)
        break;
      switch (Name[11]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (Name[12] != 'l')
          break;
        return std::make_pair(2737, 1);	 // "sub_group_all"
      case 'n':	 // 1 string to match.
        if (Name[12] != 'y')
          break;
        return std::make_pair(2737, 1);	 // "sub_group_any"
      }
      break;
    case 'v':	 // 6 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "oada_half16", 11) != 0)
          break;
        return std::make_pair(1439, 5);	 // "vloada_half16"
      case 's':	 // 5 strings to match.
        if (memcmp(Name.data()+2, "tore", 4) != 0)
          break;
        switch (Name[6]) {
        default: break;
        case '_':	 // 1 string to match.
          if (memcmp(Name.data()+7, "half16", 6) != 0)
            break;
          return std::make_pair(1468, 8);	 // "vstore_half16"
        case 'a':	 // 4 strings to match.
          if (memcmp(Name.data()+7, "_half", 5) != 0)
            break;
          switch (Name[12]) {
          default: break;
          case '2':	 // 1 string to match.
            return std::make_pair(1416, 8);	 // "vstorea_half2"
          case '3':	 // 1 string to match.
            return std::make_pair(1444, 8);	 // "vstorea_half3"
          case '4':	 // 1 string to match.
            return std::make_pair(1452, 8);	 // "vstorea_half4"
          case '8':	 // 1 string to match.
            return std::make_pair(1460, 8);	 // "vstorea_half8"
          }
          break;
        }
        break;
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "rite_imageui", 12) != 0)
        break;
      return std::make_pair(2522, 17);	 // "write_imageui"
    }
    break;
  case 14:	 // 33 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "tomic_cmpxchg", 13) != 0)
        break;
      return std::make_pair(1540, 6);	 // "atomic_cmpxchg"
    case 'c':	 // 22 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+9, "har16", 5) != 0)
          break;
        return std::make_pair(227, 11);	 // "convert_char16"
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+9, "ouble", 5) != 0)
          break;
        return std::make_pair(568, 11);	 // "convert_double"
      case 'f':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "loat", 4) != 0)
          break;
        switch (Name[13]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(1, 11);	 // "convert_float2"
        case '3':	 // 1 string to match.
          return std::make_pair(117, 11);	 // "convert_float3"
        case '4':	 // 1 string to match.
          return std::make_pair(128, 11);	 // "convert_float4"
        case '8':	 // 1 string to match.
          return std::make_pair(139, 11);	 // "convert_float8"
        }
        break;
      case 'h':	 // 1 string to match.
        if (memcmp(Name.data()+9, "alf16", 5) != 0)
          break;
        return std::make_pair(12, 11);	 // "convert_half16"
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+9, "ong16", 5) != 0)
          break;
        return std::make_pair(689, 11);	 // "convert_long16"
      case 's':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "hort", 4) != 0)
          break;
        switch (Name[13]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(315, 11);	 // "convert_short2"
        case '3':	 // 1 string to match.
          return std::make_pair(326, 11);	 // "convert_short3"
        case '4':	 // 1 string to match.
          return std::make_pair(337, 11);	 // "convert_short4"
        case '8':	 // 1 string to match.
          return std::make_pair(348, 11);	 // "convert_short8"
        }
        break;
      case 'u':	 // 10 strings to match.
        switch (Name[9]) {
        default: break;
        case 'c':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "har", 3) != 0)
            break;
          switch (Name[13]) {
          default: break;
          case '2':	 // 1 string to match.
            return std::make_pair(249, 11);	 // "convert_uchar2"
          case '3':	 // 1 string to match.
            return std::make_pair(260, 11);	 // "convert_uchar3"
          case '4':	 // 1 string to match.
            return std::make_pair(271, 11);	 // "convert_uchar4"
          case '8':	 // 1 string to match.
            return std::make_pair(282, 11);	 // "convert_uchar8"
          }
          break;
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+10, "nt16", 4) != 0)
            break;
          return std::make_pair(557, 11);	 // "convert_uint16"
        case 'l':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "ong", 3) != 0)
            break;
          switch (Name[13]) {
          default: break;
          case '2':	 // 1 string to match.
            return std::make_pair(711, 11);	 // "convert_ulong2"
          case '3':	 // 1 string to match.
            return std::make_pair(722, 11);	 // "convert_ulong3"
          case '4':	 // 1 string to match.
            return std::make_pair(733, 11);	 // "convert_ulong4"
          case '8':	 // 1 string to match.
            return std::make_pair(744, 11);	 // "convert_ulong8"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+10, "hort", 4) != 0)
            break;
          return std::make_pair(370, 11);	 // "convert_ushort"
        }
        break;
      }
      break;
    case 'e':	 // 1 string to match.
      if (memcmp(Name.data()+1, "nqueue_marker", 13) != 0)
        break;
      return std::make_pair(2687, 1);	 // "enqueue_marker"
    case 'f':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ast_normalize", 13) != 0)
        break;
      return std::make_pair(870, 1);	 // "fast_normalize"
    case 'g':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+5, "ocal_size", 9) != 0)
          break;
        return std::make_pair(767, 1);	 // "get_local_size"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+5, "um_groups", 9) != 0)
          break;
        return std::make_pair(767, 1);	 // "get_num_groups"
      }
      break;
    case 'i':	 // 2 strings to match.
      if (Name[1] != 's')
        break;
      switch (Name[2]) {
      default: break;
      case '_':	 // 1 string to match.
        if (memcmp(Name.data()+3, "valid_event", 11) != 0)
          break;
        return std::make_pair(2690, 1);	 // "is_valid_event"
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+3, "reaterequal", 11) != 0)
          break;
        return std::make_pair(887, 5);	 // "isgreaterequal"
      }
      break;
    case 'r':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ead_mem_fence", 13) != 0)
        break;
      return std::make_pair(1479, 1);	 // "read_mem_fence"
    case 'v':	 // 1 string to match.
      if (memcmp(Name.data()+1, "storea_half16", 13) != 0)
        break;
      return std::make_pair(1468, 8);	 // "vstorea_half16"
    case 'w':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "ork_group_a", 11) != 0)
        break;
      switch (Name[12]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (Name[13] != 'l')
          break;
        return std::make_pair(2681, 1);	 // "work_group_all"
      case 'n':	 // 1 string to match.
        if (Name[13] != 'y')
          break;
        return std::make_pair(2681, 1);	 // "work_group_any"
      }
      break;
    }
    break;
  case 15:	 // 30 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "m_dot_acc_sat", 13) != 0)
          break;
        return std::make_pair(115, 2);	 // "arm_dot_acc_sat"
      case 't':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "omic_", 5) != 0)
          break;
        switch (Name[7]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+8, "xchange", 7) != 0)
            break;
          return std::make_pair(1817, 21);	 // "atomic_exchange"
        case 'f':	 // 1 string to match.
          if (memcmp(Name.data()+8, "etch_or", 7) != 0)
            break;
          return std::make_pair(1952, 12);	 // "atomic_fetch_or"
        }
        break;
      }
      break;
    case 'b':	 // 1 string to match.
      if (memcmp(Name.data()+1, "itfield_insert", 14) != 0)
        break;
      return std::make_pair(75, 1);	 // "bitfield_insert"
    case 'c':	 // 17 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 'd':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "ouble", 5) != 0)
          break;
        switch (Name[14]) {
        default: break;
        case '2':	 // 1 string to match.
          return std::make_pair(579, 11);	 // "convert_double2"
        case '3':	 // 1 string to match.
          return std::make_pair(590, 11);	 // "convert_double3"
        case '4':	 // 1 string to match.
          return std::make_pair(601, 11);	 // "convert_double4"
        case '8':	 // 1 string to match.
          return std::make_pair(612, 11);	 // "convert_double8"
        }
        break;
      case 'f':	 // 1 string to match.
        if (memcmp(Name.data()+9, "loat16", 6) != 0)
          break;
        return std::make_pair(150, 11);	 // "convert_float16"
      case 'i':	 // 5 strings to match.
        if (memcmp(Name.data()+9, "nt_", 3) != 0)
          break;
        switch (Name[12]) {
        default: break;
        case 'r':	 // 4 strings to match.
          if (Name[13] != 't')
            break;
          switch (Name[14]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(436, 11);	 // "convert_int_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(436, 11);	 // "convert_int_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(436, 11);	 // "convert_int_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(436, 11);	 // "convert_int_rtz"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+13, "at", 2) != 0)
            break;
          return std::make_pair(436, 11);	 // "convert_int_sat"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+9, "hort16", 6) != 0)
          break;
        return std::make_pair(359, 11);	 // "convert_short16"
      case 'u':	 // 6 strings to match.
        switch (Name[9]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+10, "har16", 5) != 0)
            break;
          return std::make_pair(293, 11);	 // "convert_uchar16"
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+10, "ong16", 5) != 0)
            break;
          return std::make_pair(755, 11);	 // "convert_ulong16"
        case 's':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "hort", 4) != 0)
            break;
          switch (Name[14]) {
          default: break;
          case '2':	 // 1 string to match.
            return std::make_pair(381, 11);	 // "convert_ushort2"
          case '3':	 // 1 string to match.
            return std::make_pair(392, 11);	 // "convert_ushort3"
          case '4':	 // 1 string to match.
            return std::make_pair(403, 11);	 // "convert_ushort4"
          case '8':	 // 1 string to match.
            return std::make_pair(414, 11);	 // "convert_ushort8"
          }
          break;
        }
        break;
      }
      break;
    case 'g':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+5, "lobal_size", 10) != 0)
          break;
        return std::make_pair(767, 1);	 // "get_global_size"
      case 'i':	 // 2 strings to match.
        if (memcmp(Name.data()+5, "mage_", 5) != 0)
          break;
        switch (Name[10]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+11, "epth", 4) != 0)
            break;
          return std::make_pair(2602, 3);	 // "get_image_depth"
        case 'w':	 // 1 string to match.
          if (memcmp(Name.data()+11, "idth", 4) != 0)
            break;
          return std::make_pair(2539, 36);	 // "get_image_width"
        }
        break;
      }
      break;
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ub_group_elect", 14) != 0)
        break;
      return std::make_pair(2743, 1);	 // "sub_group_elect"
    case 'v':	 // 4 strings to match.
      if (memcmp(Name.data()+1, "store_half_rt", 13) != 0)
        break;
      switch (Name[14]) {
      default: break;
      case 'e':	 // 1 string to match.
        return std::make_pair(1408, 8);	 // "vstore_half_rte"
      case 'n':	 // 1 string to match.
        return std::make_pair(1408, 8);	 // "vstore_half_rtn"
      case 'p':	 // 1 string to match.
        return std::make_pair(1408, 8);	 // "vstore_half_rtp"
      case 'z':	 // 1 string to match.
        return std::make_pair(1408, 8);	 // "vstore_half_rtz"
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "rite_mem_fence", 14) != 0)
        break;
      return std::make_pair(1479, 1);	 // "write_mem_fence"
    }
    break;
  case 16:	 // 67 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 6 strings to match.
      if (memcmp(Name.data()+1, "tomic_fetch_", 12) != 0)
        break;
      switch (Name[13]) {
      default: break;
      case 'a':	 // 2 strings to match.
        switch (Name[14]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[15] != 'd')
            break;
          return std::make_pair(1880, 24);	 // "atomic_fetch_add"
        case 'n':	 // 1 string to match.
          if (Name[15] != 'd')
            break;
          return std::make_pair(1952, 12);	 // "atomic_fetch_and"
        }
        break;
      case 'm':	 // 2 strings to match.
        switch (Name[14]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (Name[15] != 'x')
            break;
          return std::make_pair(1817, 21);	 // "atomic_fetch_max"
        case 'i':	 // 1 string to match.
          if (Name[15] != 'n')
            break;
          return std::make_pair(1817, 21);	 // "atomic_fetch_min"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+14, "ub", 2) != 0)
          break;
        return std::make_pair(1880, 24);	 // "atomic_fetch_sub"
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+14, "or", 2) != 0)
          break;
        return std::make_pair(1952, 12);	 // "atomic_fetch_xor"
      }
      break;
    case 'c':	 // 41 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 'c':	 // 5 strings to match.
        if (memcmp(Name.data()+9, "har_", 4) != 0)
          break;
        switch (Name[13]) {
        default: break;
        case 'r':	 // 4 strings to match.
          if (Name[14] != 't')
            break;
          switch (Name[15]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(172, 11);	 // "convert_char_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(172, 11);	 // "convert_char_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(172, 11);	 // "convert_char_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(172, 11);	 // "convert_char_rtz"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+14, "at", 2) != 0)
            break;
          return std::make_pair(172, 11);	 // "convert_char_sat"
        }
        break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+9, "ouble16", 7) != 0)
          break;
        return std::make_pair(623, 11);	 // "convert_double16"
      case 'h':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "alf_rt", 6) != 0)
          break;
        switch (Name[15]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(26, 11);	 // "convert_half_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(26, 11);	 // "convert_half_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(26, 11);	 // "convert_half_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(26, 11);	 // "convert_half_rtz"
        }
        break;
      case 'i':	 // 20 strings to match.
        if (memcmp(Name.data()+9, "nt", 2) != 0)
          break;
        switch (Name[11]) {
        default: break;
        case '2':	 // 5 strings to match.
          if (Name[12] != '_')
            break;
          switch (Name[13]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[14] != 't')
              break;
            switch (Name[15]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(447, 11);	 // "convert_int2_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(447, 11);	 // "convert_int2_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(447, 11);	 // "convert_int2_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(447, 11);	 // "convert_int2_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+14, "at", 2) != 0)
              break;
            return std::make_pair(447, 11);	 // "convert_int2_sat"
          }
          break;
        case '3':	 // 5 strings to match.
          if (Name[12] != '_')
            break;
          switch (Name[13]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[14] != 't')
              break;
            switch (Name[15]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(458, 11);	 // "convert_int3_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(458, 11);	 // "convert_int3_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(458, 11);	 // "convert_int3_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(458, 11);	 // "convert_int3_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+14, "at", 2) != 0)
              break;
            return std::make_pair(458, 11);	 // "convert_int3_sat"
          }
          break;
        case '4':	 // 5 strings to match.
          if (Name[12] != '_')
            break;
          switch (Name[13]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[14] != 't')
              break;
            switch (Name[15]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(469, 11);	 // "convert_int4_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(469, 11);	 // "convert_int4_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(469, 11);	 // "convert_int4_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(469, 11);	 // "convert_int4_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+14, "at", 2) != 0)
              break;
            return std::make_pair(469, 11);	 // "convert_int4_sat"
          }
          break;
        case '8':	 // 5 strings to match.
          if (Name[12] != '_')
            break;
          switch (Name[13]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[14] != 't')
              break;
            switch (Name[15]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(480, 11);	 // "convert_int8_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(480, 11);	 // "convert_int8_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(480, 11);	 // "convert_int8_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(480, 11);	 // "convert_int8_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+14, "at", 2) != 0)
              break;
            return std::make_pair(480, 11);	 // "convert_int8_sat"
          }
          break;
        }
        break;
      case 'l':	 // 5 strings to match.
        if (memcmp(Name.data()+9, "ong_", 4) != 0)
          break;
        switch (Name[13]) {
        default: break;
        case 'r':	 // 4 strings to match.
          if (Name[14] != 't')
            break;
          switch (Name[15]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(634, 11);	 // "convert_long_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(634, 11);	 // "convert_long_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(634, 11);	 // "convert_long_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(634, 11);	 // "convert_long_rtz"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+14, "at", 2) != 0)
            break;
          return std::make_pair(634, 11);	 // "convert_long_sat"
        }
        break;
      case 'u':	 // 6 strings to match.
        switch (Name[9]) {
        default: break;
        case 'i':	 // 5 strings to match.
          if (memcmp(Name.data()+10, "nt_", 3) != 0)
            break;
          switch (Name[13]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[14] != 't')
              break;
            switch (Name[15]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(502, 11);	 // "convert_uint_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(502, 11);	 // "convert_uint_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(502, 11);	 // "convert_uint_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(502, 11);	 // "convert_uint_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+14, "at", 2) != 0)
              break;
            return std::make_pair(502, 11);	 // "convert_uint_sat"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+10, "hort16", 6) != 0)
            break;
          return std::make_pair(425, 11);	 // "convert_ushort16"
        }
        break;
      }
      break;
    case 'g':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+5, "mage_height", 11) != 0)
          break;
        return std::make_pair(2575, 27);	 // "get_image_height"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+5, "ub_group_id", 11) != 0)
          break;
        return std::make_pair(2733, 1);	 // "get_sub_group_id"
      }
      break;
    case 's':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "ub_group_", 9) != 0)
        break;
      switch (Name[10]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+11, "allot", 5) != 0)
          break;
        return std::make_pair(2748, 1);	 // "sub_group_ballot"
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+11, "otate", 5) != 0)
          break;
        return std::make_pair(107, 1);	 // "sub_group_rotate"
      }
      break;
    case 'v':	 // 16 strings to match.
      if (memcmp(Name.data()+1, "store_half", 10) != 0)
        break;
      switch (Name[11]) {
      default: break;
      case '2':	 // 4 strings to match.
        if (memcmp(Name.data()+12, "_rt", 3) != 0)
          break;
        switch (Name[15]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(1416, 8);	 // "vstore_half2_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(1416, 8);	 // "vstore_half2_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(1416, 8);	 // "vstore_half2_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(1416, 8);	 // "vstore_half2_rtz"
        }
        break;
      case '3':	 // 4 strings to match.
        if (memcmp(Name.data()+12, "_rt", 3) != 0)
          break;
        switch (Name[15]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(1444, 8);	 // "vstore_half3_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(1444, 8);	 // "vstore_half3_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(1444, 8);	 // "vstore_half3_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(1444, 8);	 // "vstore_half3_rtz"
        }
        break;
      case '4':	 // 4 strings to match.
        if (memcmp(Name.data()+12, "_rt", 3) != 0)
          break;
        switch (Name[15]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(1452, 8);	 // "vstore_half4_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(1452, 8);	 // "vstore_half4_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(1452, 8);	 // "vstore_half4_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(1452, 8);	 // "vstore_half4_rtz"
        }
        break;
      case '8':	 // 4 strings to match.
        if (memcmp(Name.data()+12, "_rt", 3) != 0)
          break;
        switch (Name[15]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(1460, 8);	 // "vstore_half8_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(1460, 8);	 // "vstore_half8_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(1460, 8);	 // "vstore_half8_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(1460, 8);	 // "vstore_half8_rtz"
        }
        break;
      }
      break;
    }
    break;
  case 17:	 // 127 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "tomic_flag_clear", 16) != 0)
        break;
      return std::make_pair(1988, 3);	 // "atomic_flag_clear"
    case 'c':	 // 101 strings to match.
      switch (Name[1]) {
      default: break;
      case 'o':	 // 100 strings to match.
        if (memcmp(Name.data()+2, "nvert_", 6) != 0)
          break;
        switch (Name[8]) {
        default: break;
        case 'c':	 // 20 strings to match.
          if (memcmp(Name.data()+9, "har", 3) != 0)
            break;
          switch (Name[12]) {
          default: break;
          case '2':	 // 5 strings to match.
            if (Name[13] != '_')
              break;
            switch (Name[14]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[15] != 't')
                break;
              switch (Name[16]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(183, 11);	 // "convert_char2_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(183, 11);	 // "convert_char2_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(183, 11);	 // "convert_char2_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(183, 11);	 // "convert_char2_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+15, "at", 2) != 0)
                break;
              return std::make_pair(183, 11);	 // "convert_char2_sat"
            }
            break;
          case '3':	 // 5 strings to match.
            if (Name[13] != '_')
              break;
            switch (Name[14]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[15] != 't')
                break;
              switch (Name[16]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(194, 11);	 // "convert_char3_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(194, 11);	 // "convert_char3_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(194, 11);	 // "convert_char3_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(194, 11);	 // "convert_char3_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+15, "at", 2) != 0)
                break;
              return std::make_pair(194, 11);	 // "convert_char3_sat"
            }
            break;
          case '4':	 // 5 strings to match.
            if (Name[13] != '_')
              break;
            switch (Name[14]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[15] != 't')
                break;
              switch (Name[16]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(205, 11);	 // "convert_char4_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(205, 11);	 // "convert_char4_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(205, 11);	 // "convert_char4_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(205, 11);	 // "convert_char4_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+15, "at", 2) != 0)
                break;
              return std::make_pair(205, 11);	 // "convert_char4_sat"
            }
            break;
          case '8':	 // 5 strings to match.
            if (Name[13] != '_')
              break;
            switch (Name[14]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[15] != 't')
                break;
              switch (Name[16]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(216, 11);	 // "convert_char8_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(216, 11);	 // "convert_char8_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(216, 11);	 // "convert_char8_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(216, 11);	 // "convert_char8_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+15, "at", 2) != 0)
                break;
              return std::make_pair(216, 11);	 // "convert_char8_sat"
            }
            break;
          }
          break;
        case 'f':	 // 4 strings to match.
          if (memcmp(Name.data()+9, "loat_rt", 7) != 0)
            break;
          switch (Name[16]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(161, 11);	 // "convert_float_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(161, 11);	 // "convert_float_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(161, 11);	 // "convert_float_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(161, 11);	 // "convert_float_rtz"
          }
          break;
        case 'h':	 // 16 strings to match.
          if (memcmp(Name.data()+9, "alf", 3) != 0)
            break;
          switch (Name[12]) {
          default: break;
          case '2':	 // 4 strings to match.
            if (memcmp(Name.data()+13, "_rt", 3) != 0)
              break;
            switch (Name[16]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(37, 11);	 // "convert_half2_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(37, 11);	 // "convert_half2_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(37, 11);	 // "convert_half2_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(37, 11);	 // "convert_half2_rtz"
            }
            break;
          case '3':	 // 4 strings to match.
            if (memcmp(Name.data()+13, "_rt", 3) != 0)
              break;
            switch (Name[16]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(50, 11);	 // "convert_half3_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(50, 11);	 // "convert_half3_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(50, 11);	 // "convert_half3_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(50, 11);	 // "convert_half3_rtz"
            }
            break;
          case '4':	 // 4 strings to match.
            if (memcmp(Name.data()+13, "_rt", 3) != 0)
              break;
            switch (Name[16]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(64, 11);	 // "convert_half4_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(64, 11);	 // "convert_half4_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(64, 11);	 // "convert_half4_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(64, 11);	 // "convert_half4_rtz"
            }
            break;
          case '8':	 // 4 strings to match.
            if (memcmp(Name.data()+13, "_rt", 3) != 0)
              break;
            switch (Name[16]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(88, 11);	 // "convert_half8_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(88, 11);	 // "convert_half8_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(88, 11);	 // "convert_half8_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(88, 11);	 // "convert_half8_rtz"
            }
            break;
          }
          break;
        case 'i':	 // 5 strings to match.
          if (memcmp(Name.data()+9, "nt16_", 5) != 0)
            break;
          switch (Name[14]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[15] != 't')
              break;
            switch (Name[16]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(491, 11);	 // "convert_int16_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(491, 11);	 // "convert_int16_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(491, 11);	 // "convert_int16_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(491, 11);	 // "convert_int16_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+15, "at", 2) != 0)
              break;
            return std::make_pair(491, 11);	 // "convert_int16_sat"
          }
          break;
        case 'l':	 // 20 strings to match.
          if (memcmp(Name.data()+9, "ong", 3) != 0)
            break;
          switch (Name[12]) {
          default: break;
          case '2':	 // 5 strings to match.
            if (Name[13] != '_')
              break;
            switch (Name[14]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[15] != 't')
                break;
              switch (Name[16]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(645, 11);	 // "convert_long2_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(645, 11);	 // "convert_long2_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(645, 11);	 // "convert_long2_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(645, 11);	 // "convert_long2_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+15, "at", 2) != 0)
                break;
              return std::make_pair(645, 11);	 // "convert_long2_sat"
            }
            break;
          case '3':	 // 5 strings to match.
            if (Name[13] != '_')
              break;
            switch (Name[14]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[15] != 't')
                break;
              switch (Name[16]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(656, 11);	 // "convert_long3_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(656, 11);	 // "convert_long3_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(656, 11);	 // "convert_long3_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(656, 11);	 // "convert_long3_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+15, "at", 2) != 0)
                break;
              return std::make_pair(656, 11);	 // "convert_long3_sat"
            }
            break;
          case '4':	 // 5 strings to match.
            if (Name[13] != '_')
              break;
            switch (Name[14]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[15] != 't')
                break;
              switch (Name[16]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(667, 11);	 // "convert_long4_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(667, 11);	 // "convert_long4_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(667, 11);	 // "convert_long4_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(667, 11);	 // "convert_long4_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+15, "at", 2) != 0)
                break;
              return std::make_pair(667, 11);	 // "convert_long4_sat"
            }
            break;
          case '8':	 // 5 strings to match.
            if (Name[13] != '_')
              break;
            switch (Name[14]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[15] != 't')
                break;
              switch (Name[16]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(678, 11);	 // "convert_long8_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(678, 11);	 // "convert_long8_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(678, 11);	 // "convert_long8_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(678, 11);	 // "convert_long8_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+15, "at", 2) != 0)
                break;
              return std::make_pair(678, 11);	 // "convert_long8_sat"
            }
            break;
          }
          break;
        case 's':	 // 5 strings to match.
          if (memcmp(Name.data()+9, "hort_", 5) != 0)
            break;
          switch (Name[14]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[15] != 't')
              break;
            switch (Name[16]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(304, 11);	 // "convert_short_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(304, 11);	 // "convert_short_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(304, 11);	 // "convert_short_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(304, 11);	 // "convert_short_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+15, "at", 2) != 0)
              break;
            return std::make_pair(304, 11);	 // "convert_short_sat"
          }
          break;
        case 'u':	 // 30 strings to match.
          switch (Name[9]) {
          default: break;
          case 'c':	 // 5 strings to match.
            if (memcmp(Name.data()+10, "har_", 4) != 0)
              break;
            switch (Name[14]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[15] != 't')
                break;
              switch (Name[16]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(238, 11);	 // "convert_uchar_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(238, 11);	 // "convert_uchar_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(238, 11);	 // "convert_uchar_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(238, 11);	 // "convert_uchar_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+15, "at", 2) != 0)
                break;
              return std::make_pair(238, 11);	 // "convert_uchar_sat"
            }
            break;
          case 'i':	 // 20 strings to match.
            if (memcmp(Name.data()+10, "nt", 2) != 0)
              break;
            switch (Name[12]) {
            default: break;
            case '2':	 // 5 strings to match.
              if (Name[13] != '_')
                break;
              switch (Name[14]) {
              default: break;
              case 'r':	 // 4 strings to match.
                if (Name[15] != 't')
                  break;
                switch (Name[16]) {
                default: break;
                case 'e':	 // 1 string to match.
                  return std::make_pair(513, 11);	 // "convert_uint2_rte"
                case 'n':	 // 1 string to match.
                  return std::make_pair(513, 11);	 // "convert_uint2_rtn"
                case 'p':	 // 1 string to match.
                  return std::make_pair(513, 11);	 // "convert_uint2_rtp"
                case 'z':	 // 1 string to match.
                  return std::make_pair(513, 11);	 // "convert_uint2_rtz"
                }
                break;
              case 's':	 // 1 string to match.
                if (memcmp(Name.data()+15, "at", 2) != 0)
                  break;
                return std::make_pair(513, 11);	 // "convert_uint2_sat"
              }
              break;
            case '3':	 // 5 strings to match.
              if (Name[13] != '_')
                break;
              switch (Name[14]) {
              default: break;
              case 'r':	 // 4 strings to match.
                if (Name[15] != 't')
                  break;
                switch (Name[16]) {
                default: break;
                case 'e':	 // 1 string to match.
                  return std::make_pair(524, 11);	 // "convert_uint3_rte"
                case 'n':	 // 1 string to match.
                  return std::make_pair(524, 11);	 // "convert_uint3_rtn"
                case 'p':	 // 1 string to match.
                  return std::make_pair(524, 11);	 // "convert_uint3_rtp"
                case 'z':	 // 1 string to match.
                  return std::make_pair(524, 11);	 // "convert_uint3_rtz"
                }
                break;
              case 's':	 // 1 string to match.
                if (memcmp(Name.data()+15, "at", 2) != 0)
                  break;
                return std::make_pair(524, 11);	 // "convert_uint3_sat"
              }
              break;
            case '4':	 // 5 strings to match.
              if (Name[13] != '_')
                break;
              switch (Name[14]) {
              default: break;
              case 'r':	 // 4 strings to match.
                if (Name[15] != 't')
                  break;
                switch (Name[16]) {
                default: break;
                case 'e':	 // 1 string to match.
                  return std::make_pair(535, 11);	 // "convert_uint4_rte"
                case 'n':	 // 1 string to match.
                  return std::make_pair(535, 11);	 // "convert_uint4_rtn"
                case 'p':	 // 1 string to match.
                  return std::make_pair(535, 11);	 // "convert_uint4_rtp"
                case 'z':	 // 1 string to match.
                  return std::make_pair(535, 11);	 // "convert_uint4_rtz"
                }
                break;
              case 's':	 // 1 string to match.
                if (memcmp(Name.data()+15, "at", 2) != 0)
                  break;
                return std::make_pair(535, 11);	 // "convert_uint4_sat"
              }
              break;
            case '8':	 // 5 strings to match.
              if (Name[13] != '_')
                break;
              switch (Name[14]) {
              default: break;
              case 'r':	 // 4 strings to match.
                if (Name[15] != 't')
                  break;
                switch (Name[16]) {
                default: break;
                case 'e':	 // 1 string to match.
                  return std::make_pair(546, 11);	 // "convert_uint8_rte"
                case 'n':	 // 1 string to match.
                  return std::make_pair(546, 11);	 // "convert_uint8_rtn"
                case 'p':	 // 1 string to match.
                  return std::make_pair(546, 11);	 // "convert_uint8_rtp"
                case 'z':	 // 1 string to match.
                  return std::make_pair(546, 11);	 // "convert_uint8_rtz"
                }
                break;
              case 's':	 // 1 string to match.
                if (memcmp(Name.data()+15, "at", 2) != 0)
                  break;
                return std::make_pair(546, 11);	 // "convert_uint8_sat"
              }
              break;
            }
            break;
          case 'l':	 // 5 strings to match.
            if (memcmp(Name.data()+10, "ong_", 4) != 0)
              break;
            switch (Name[14]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[15] != 't')
                break;
              switch (Name[16]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(700, 11);	 // "convert_ulong_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(700, 11);	 // "convert_ulong_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(700, 11);	 // "convert_ulong_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(700, 11);	 // "convert_ulong_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+15, "at", 2) != 0)
                break;
              return std::make_pair(700, 11);	 // "convert_ulong_sat"
            }
            break;
          }
          break;
        }
        break;
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "eate_user_event", 15) != 0)
          break;
        return std::make_pair(2689, 1);	 // "create_user_event"
      }
      break;
    case 'g':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+5, "efault_queue", 12) != 0)
          break;
        return std::make_pair(2693, 1);	 // "get_default_queue"
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+5, "lobal_offset", 12) != 0)
          break;
        return std::make_pair(767, 1);	 // "get_global_offset"
      }
      break;
    case 's':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "ub_group_", 9) != 0)
        break;
      switch (Name[10]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+11, "arrier", 6) != 0)
          break;
        return std::make_pair(2735, 2);	 // "sub_group_barrier"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+11, "huffle", 6) != 0)
          break;
        return std::make_pair(48, 1);	 // "sub_group_shuffle"
      }
      break;
    case 'v':	 // 20 strings to match.
      if (memcmp(Name.data()+1, "store", 5) != 0)
        break;
      switch (Name[6]) {
      default: break;
      case '_':	 // 4 strings to match.
        if (memcmp(Name.data()+7, "half16_rt", 9) != 0)
          break;
        switch (Name[16]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(1468, 8);	 // "vstore_half16_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(1468, 8);	 // "vstore_half16_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(1468, 8);	 // "vstore_half16_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(1468, 8);	 // "vstore_half16_rtz"
        }
        break;
      case 'a':	 // 16 strings to match.
        if (memcmp(Name.data()+7, "_half", 5) != 0)
          break;
        switch (Name[12]) {
        default: break;
        case '2':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_rt", 3) != 0)
            break;
          switch (Name[16]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(1416, 8);	 // "vstorea_half2_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(1416, 8);	 // "vstorea_half2_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(1416, 8);	 // "vstorea_half2_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(1416, 8);	 // "vstorea_half2_rtz"
          }
          break;
        case '3':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_rt", 3) != 0)
            break;
          switch (Name[16]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(1444, 8);	 // "vstorea_half3_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(1444, 8);	 // "vstorea_half3_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(1444, 8);	 // "vstorea_half3_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(1444, 8);	 // "vstorea_half3_rtz"
          }
          break;
        case '4':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_rt", 3) != 0)
            break;
          switch (Name[16]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(1452, 8);	 // "vstorea_half4_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(1452, 8);	 // "vstorea_half4_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(1452, 8);	 // "vstorea_half4_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(1452, 8);	 // "vstorea_half4_rtz"
          }
          break;
        case '8':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_rt", 3) != 0)
            break;
          switch (Name[16]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(1460, 8);	 // "vstorea_half8_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(1460, 8);	 // "vstorea_half8_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(1460, 8);	 // "vstorea_half8_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(1460, 8);	 // "vstorea_half8_rtz"
          }
          break;
        }
        break;
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ait_group_events", 16) != 0)
        break;
      return std::make_pair(1486, 1);	 // "wait_group_events"
    }
    break;
  case 18:	 // 111 strings to match.
    switch (Name[0]) {
    default: break;
    case 'c':	 // 104 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 'c':	 // 5 strings to match.
        if (memcmp(Name.data()+9, "har16_", 6) != 0)
          break;
        switch (Name[15]) {
        default: break;
        case 'r':	 // 4 strings to match.
          if (Name[16] != 't')
            break;
          switch (Name[17]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(227, 11);	 // "convert_char16_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(227, 11);	 // "convert_char16_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(227, 11);	 // "convert_char16_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(227, 11);	 // "convert_char16_rtz"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+16, "at", 2) != 0)
            break;
          return std::make_pair(227, 11);	 // "convert_char16_sat"
        }
        break;
      case 'd':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "ouble_rt", 8) != 0)
          break;
        switch (Name[17]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(568, 11);	 // "convert_double_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(568, 11);	 // "convert_double_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(568, 11);	 // "convert_double_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(568, 11);	 // "convert_double_rtz"
        }
        break;
      case 'f':	 // 16 strings to match.
        if (memcmp(Name.data()+9, "loat", 4) != 0)
          break;
        switch (Name[13]) {
        default: break;
        case '2':	 // 4 strings to match.
          if (memcmp(Name.data()+14, "_rt", 3) != 0)
            break;
          switch (Name[17]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(1, 11);	 // "convert_float2_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(1, 11);	 // "convert_float2_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(1, 11);	 // "convert_float2_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(1, 11);	 // "convert_float2_rtz"
          }
          break;
        case '3':	 // 4 strings to match.
          if (memcmp(Name.data()+14, "_rt", 3) != 0)
            break;
          switch (Name[17]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(117, 11);	 // "convert_float3_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(117, 11);	 // "convert_float3_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(117, 11);	 // "convert_float3_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(117, 11);	 // "convert_float3_rtz"
          }
          break;
        case '4':	 // 4 strings to match.
          if (memcmp(Name.data()+14, "_rt", 3) != 0)
            break;
          switch (Name[17]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(128, 11);	 // "convert_float4_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(128, 11);	 // "convert_float4_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(128, 11);	 // "convert_float4_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(128, 11);	 // "convert_float4_rtz"
          }
          break;
        case '8':	 // 4 strings to match.
          if (memcmp(Name.data()+14, "_rt", 3) != 0)
            break;
          switch (Name[17]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(139, 11);	 // "convert_float8_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(139, 11);	 // "convert_float8_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(139, 11);	 // "convert_float8_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(139, 11);	 // "convert_float8_rtz"
          }
          break;
        }
        break;
      case 'h':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "alf16_rt", 8) != 0)
          break;
        switch (Name[17]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(12, 11);	 // "convert_half16_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(12, 11);	 // "convert_half16_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(12, 11);	 // "convert_half16_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(12, 11);	 // "convert_half16_rtz"
        }
        break;
      case 'l':	 // 5 strings to match.
        if (memcmp(Name.data()+9, "ong16_", 6) != 0)
          break;
        switch (Name[15]) {
        default: break;
        case 'r':	 // 4 strings to match.
          if (Name[16] != 't')
            break;
          switch (Name[17]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(689, 11);	 // "convert_long16_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(689, 11);	 // "convert_long16_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(689, 11);	 // "convert_long16_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(689, 11);	 // "convert_long16_rtz"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+16, "at", 2) != 0)
            break;
          return std::make_pair(689, 11);	 // "convert_long16_sat"
        }
        break;
      case 's':	 // 20 strings to match.
        if (memcmp(Name.data()+9, "hort", 4) != 0)
          break;
        switch (Name[13]) {
        default: break;
        case '2':	 // 5 strings to match.
          if (Name[14] != '_')
            break;
          switch (Name[15]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[16] != 't')
              break;
            switch (Name[17]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(315, 11);	 // "convert_short2_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(315, 11);	 // "convert_short2_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(315, 11);	 // "convert_short2_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(315, 11);	 // "convert_short2_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+16, "at", 2) != 0)
              break;
            return std::make_pair(315, 11);	 // "convert_short2_sat"
          }
          break;
        case '3':	 // 5 strings to match.
          if (Name[14] != '_')
            break;
          switch (Name[15]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[16] != 't')
              break;
            switch (Name[17]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(326, 11);	 // "convert_short3_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(326, 11);	 // "convert_short3_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(326, 11);	 // "convert_short3_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(326, 11);	 // "convert_short3_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+16, "at", 2) != 0)
              break;
            return std::make_pair(326, 11);	 // "convert_short3_sat"
          }
          break;
        case '4':	 // 5 strings to match.
          if (Name[14] != '_')
            break;
          switch (Name[15]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[16] != 't')
              break;
            switch (Name[17]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(337, 11);	 // "convert_short4_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(337, 11);	 // "convert_short4_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(337, 11);	 // "convert_short4_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(337, 11);	 // "convert_short4_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+16, "at", 2) != 0)
              break;
            return std::make_pair(337, 11);	 // "convert_short4_sat"
          }
          break;
        case '8':	 // 5 strings to match.
          if (Name[14] != '_')
            break;
          switch (Name[15]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[16] != 't')
              break;
            switch (Name[17]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(348, 11);	 // "convert_short8_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(348, 11);	 // "convert_short8_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(348, 11);	 // "convert_short8_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(348, 11);	 // "convert_short8_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+16, "at", 2) != 0)
              break;
            return std::make_pair(348, 11);	 // "convert_short8_sat"
          }
          break;
        }
        break;
      case 'u':	 // 50 strings to match.
        switch (Name[9]) {
        default: break;
        case 'c':	 // 20 strings to match.
          if (memcmp(Name.data()+10, "har", 3) != 0)
            break;
          switch (Name[13]) {
          default: break;
          case '2':	 // 5 strings to match.
            if (Name[14] != '_')
              break;
            switch (Name[15]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[16] != 't')
                break;
              switch (Name[17]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(249, 11);	 // "convert_uchar2_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(249, 11);	 // "convert_uchar2_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(249, 11);	 // "convert_uchar2_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(249, 11);	 // "convert_uchar2_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+16, "at", 2) != 0)
                break;
              return std::make_pair(249, 11);	 // "convert_uchar2_sat"
            }
            break;
          case '3':	 // 5 strings to match.
            if (Name[14] != '_')
              break;
            switch (Name[15]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[16] != 't')
                break;
              switch (Name[17]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(260, 11);	 // "convert_uchar3_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(260, 11);	 // "convert_uchar3_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(260, 11);	 // "convert_uchar3_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(260, 11);	 // "convert_uchar3_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+16, "at", 2) != 0)
                break;
              return std::make_pair(260, 11);	 // "convert_uchar3_sat"
            }
            break;
          case '4':	 // 5 strings to match.
            if (Name[14] != '_')
              break;
            switch (Name[15]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[16] != 't')
                break;
              switch (Name[17]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(271, 11);	 // "convert_uchar4_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(271, 11);	 // "convert_uchar4_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(271, 11);	 // "convert_uchar4_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(271, 11);	 // "convert_uchar4_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+16, "at", 2) != 0)
                break;
              return std::make_pair(271, 11);	 // "convert_uchar4_sat"
            }
            break;
          case '8':	 // 5 strings to match.
            if (Name[14] != '_')
              break;
            switch (Name[15]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[16] != 't')
                break;
              switch (Name[17]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(282, 11);	 // "convert_uchar8_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(282, 11);	 // "convert_uchar8_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(282, 11);	 // "convert_uchar8_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(282, 11);	 // "convert_uchar8_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+16, "at", 2) != 0)
                break;
              return std::make_pair(282, 11);	 // "convert_uchar8_sat"
            }
            break;
          }
          break;
        case 'i':	 // 5 strings to match.
          if (memcmp(Name.data()+10, "nt16_", 5) != 0)
            break;
          switch (Name[15]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[16] != 't')
              break;
            switch (Name[17]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(557, 11);	 // "convert_uint16_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(557, 11);	 // "convert_uint16_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(557, 11);	 // "convert_uint16_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(557, 11);	 // "convert_uint16_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+16, "at", 2) != 0)
              break;
            return std::make_pair(557, 11);	 // "convert_uint16_sat"
          }
          break;
        case 'l':	 // 20 strings to match.
          if (memcmp(Name.data()+10, "ong", 3) != 0)
            break;
          switch (Name[13]) {
          default: break;
          case '2':	 // 5 strings to match.
            if (Name[14] != '_')
              break;
            switch (Name[15]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[16] != 't')
                break;
              switch (Name[17]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(711, 11);	 // "convert_ulong2_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(711, 11);	 // "convert_ulong2_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(711, 11);	 // "convert_ulong2_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(711, 11);	 // "convert_ulong2_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+16, "at", 2) != 0)
                break;
              return std::make_pair(711, 11);	 // "convert_ulong2_sat"
            }
            break;
          case '3':	 // 5 strings to match.
            if (Name[14] != '_')
              break;
            switch (Name[15]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[16] != 't')
                break;
              switch (Name[17]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(722, 11);	 // "convert_ulong3_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(722, 11);	 // "convert_ulong3_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(722, 11);	 // "convert_ulong3_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(722, 11);	 // "convert_ulong3_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+16, "at", 2) != 0)
                break;
              return std::make_pair(722, 11);	 // "convert_ulong3_sat"
            }
            break;
          case '4':	 // 5 strings to match.
            if (Name[14] != '_')
              break;
            switch (Name[15]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[16] != 't')
                break;
              switch (Name[17]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(733, 11);	 // "convert_ulong4_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(733, 11);	 // "convert_ulong4_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(733, 11);	 // "convert_ulong4_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(733, 11);	 // "convert_ulong4_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+16, "at", 2) != 0)
                break;
              return std::make_pair(733, 11);	 // "convert_ulong4_sat"
            }
            break;
          case '8':	 // 5 strings to match.
            if (Name[14] != '_')
              break;
            switch (Name[15]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[16] != 't')
                break;
              switch (Name[17]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(744, 11);	 // "convert_ulong8_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(744, 11);	 // "convert_ulong8_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(744, 11);	 // "convert_ulong8_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(744, 11);	 // "convert_ulong8_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+16, "at", 2) != 0)
                break;
              return std::make_pair(744, 11);	 // "convert_ulong8_sat"
            }
            break;
          }
          break;
        case 's':	 // 5 strings to match.
          if (memcmp(Name.data()+10, "hort_", 5) != 0)
            break;
          switch (Name[15]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[16] != 't')
              break;
            switch (Name[17]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(370, 11);	 // "convert_ushort_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(370, 11);	 // "convert_ushort_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(370, 11);	 // "convert_ushort_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(370, 11);	 // "convert_ushort_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+16, "at", 2) != 0)
              break;
            return std::make_pair(370, 11);	 // "convert_ushort_sat"
          }
          break;
        }
        break;
      }
      break;
    case 'g':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+5, "um_sub_groups", 13) != 0)
          break;
        return std::make_pair(2733, 1);	 // "get_num_sub_groups"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+5, "ub_group_size", 13) != 0)
          break;
        return std::make_pair(2733, 1);	 // "get_sub_group_size"
      }
      break;
    case 'v':	 // 4 strings to match.
      if (memcmp(Name.data()+1, "storea_half16_rt", 16) != 0)
        break;
      switch (Name[17]) {
      default: break;
      case 'e':	 // 1 string to match.
        return std::make_pair(1468, 8);	 // "vstorea_half16_rte"
      case 'n':	 // 1 string to match.
        return std::make_pair(1468, 8);	 // "vstorea_half16_rtn"
      case 'p':	 // 1 string to match.
        return std::make_pair(1468, 8);	 // "vstorea_half16_rtp"
      case 'z':	 // 1 string to match.
        return std::make_pair(1468, 8);	 // "vstorea_half16_rtz"
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ork_group_barrier", 17) != 0)
        break;
      return std::make_pair(1477, 2);	 // "work_group_barrier"
    }
    break;
  case 19:	 // 62 strings to match.
    switch (Name[0]) {
    default: break;
    case 'c':	 // 59 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 'd':	 // 16 strings to match.
        if (memcmp(Name.data()+9, "ouble", 5) != 0)
          break;
        switch (Name[14]) {
        default: break;
        case '2':	 // 4 strings to match.
          if (memcmp(Name.data()+15, "_rt", 3) != 0)
            break;
          switch (Name[18]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(579, 11);	 // "convert_double2_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(579, 11);	 // "convert_double2_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(579, 11);	 // "convert_double2_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(579, 11);	 // "convert_double2_rtz"
          }
          break;
        case '3':	 // 4 strings to match.
          if (memcmp(Name.data()+15, "_rt", 3) != 0)
            break;
          switch (Name[18]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(590, 11);	 // "convert_double3_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(590, 11);	 // "convert_double3_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(590, 11);	 // "convert_double3_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(590, 11);	 // "convert_double3_rtz"
          }
          break;
        case '4':	 // 4 strings to match.
          if (memcmp(Name.data()+15, "_rt", 3) != 0)
            break;
          switch (Name[18]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(601, 11);	 // "convert_double4_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(601, 11);	 // "convert_double4_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(601, 11);	 // "convert_double4_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(601, 11);	 // "convert_double4_rtz"
          }
          break;
        case '8':	 // 4 strings to match.
          if (memcmp(Name.data()+15, "_rt", 3) != 0)
            break;
          switch (Name[18]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(612, 11);	 // "convert_double8_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(612, 11);	 // "convert_double8_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(612, 11);	 // "convert_double8_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(612, 11);	 // "convert_double8_rtz"
          }
          break;
        }
        break;
      case 'f':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "loat16_rt", 9) != 0)
          break;
        switch (Name[18]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(150, 11);	 // "convert_float16_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(150, 11);	 // "convert_float16_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(150, 11);	 // "convert_float16_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(150, 11);	 // "convert_float16_rtz"
        }
        break;
      case 'i':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "nt_sat_rt", 9) != 0)
          break;
        switch (Name[18]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(436, 11);	 // "convert_int_sat_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(436, 11);	 // "convert_int_sat_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(436, 11);	 // "convert_int_sat_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(436, 11);	 // "convert_int_sat_rtz"
        }
        break;
      case 's':	 // 5 strings to match.
        if (memcmp(Name.data()+9, "hort16_", 7) != 0)
          break;
        switch (Name[16]) {
        default: break;
        case 'r':	 // 4 strings to match.
          if (Name[17] != 't')
            break;
          switch (Name[18]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(359, 11);	 // "convert_short16_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(359, 11);	 // "convert_short16_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(359, 11);	 // "convert_short16_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(359, 11);	 // "convert_short16_rtz"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+17, "at", 2) != 0)
            break;
          return std::make_pair(359, 11);	 // "convert_short16_sat"
        }
        break;
      case 'u':	 // 30 strings to match.
        switch (Name[9]) {
        default: break;
        case 'c':	 // 5 strings to match.
          if (memcmp(Name.data()+10, "har16_", 6) != 0)
            break;
          switch (Name[16]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[17] != 't')
              break;
            switch (Name[18]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(293, 11);	 // "convert_uchar16_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(293, 11);	 // "convert_uchar16_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(293, 11);	 // "convert_uchar16_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(293, 11);	 // "convert_uchar16_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+17, "at", 2) != 0)
              break;
            return std::make_pair(293, 11);	 // "convert_uchar16_sat"
          }
          break;
        case 'l':	 // 5 strings to match.
          if (memcmp(Name.data()+10, "ong16_", 6) != 0)
            break;
          switch (Name[16]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[17] != 't')
              break;
            switch (Name[18]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(755, 11);	 // "convert_ulong16_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(755, 11);	 // "convert_ulong16_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(755, 11);	 // "convert_ulong16_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(755, 11);	 // "convert_ulong16_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+17, "at", 2) != 0)
              break;
            return std::make_pair(755, 11);	 // "convert_ulong16_sat"
          }
          break;
        case 's':	 // 20 strings to match.
          if (memcmp(Name.data()+10, "hort", 4) != 0)
            break;
          switch (Name[14]) {
          default: break;
          case '2':	 // 5 strings to match.
            if (Name[15] != '_')
              break;
            switch (Name[16]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[17] != 't')
                break;
              switch (Name[18]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(381, 11);	 // "convert_ushort2_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(381, 11);	 // "convert_ushort2_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(381, 11);	 // "convert_ushort2_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(381, 11);	 // "convert_ushort2_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+17, "at", 2) != 0)
                break;
              return std::make_pair(381, 11);	 // "convert_ushort2_sat"
            }
            break;
          case '3':	 // 5 strings to match.
            if (Name[15] != '_')
              break;
            switch (Name[16]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[17] != 't')
                break;
              switch (Name[18]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(392, 11);	 // "convert_ushort3_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(392, 11);	 // "convert_ushort3_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(392, 11);	 // "convert_ushort3_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(392, 11);	 // "convert_ushort3_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+17, "at", 2) != 0)
                break;
              return std::make_pair(392, 11);	 // "convert_ushort3_sat"
            }
            break;
          case '4':	 // 5 strings to match.
            if (Name[15] != '_')
              break;
            switch (Name[16]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[17] != 't')
                break;
              switch (Name[18]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(403, 11);	 // "convert_ushort4_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(403, 11);	 // "convert_ushort4_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(403, 11);	 // "convert_ushort4_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(403, 11);	 // "convert_ushort4_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+17, "at", 2) != 0)
                break;
              return std::make_pair(403, 11);	 // "convert_ushort4_sat"
            }
            break;
          case '8':	 // 5 strings to match.
            if (Name[15] != '_')
              break;
            switch (Name[16]) {
            default: break;
            case 'r':	 // 4 strings to match.
              if (Name[17] != 't')
                break;
              switch (Name[18]) {
              default: break;
              case 'e':	 // 1 string to match.
                return std::make_pair(414, 11);	 // "convert_ushort8_rte"
              case 'n':	 // 1 string to match.
                return std::make_pair(414, 11);	 // "convert_ushort8_rtn"
              case 'p':	 // 1 string to match.
                return std::make_pair(414, 11);	 // "convert_ushort8_rtp"
              case 'z':	 // 1 string to match.
                return std::make_pair(414, 11);	 // "convert_ushort8_rtz"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+17, "at", 2) != 0)
                break;
              return std::make_pair(414, 11);	 // "convert_ushort8_sat"
            }
            break;
          }
          break;
        }
        break;
      }
      break;
    case 'g':	 // 1 string to match.
      if (memcmp(Name.data()+1, "et_local_linear_id", 18) != 0)
        break;
      return std::make_pair(769, 1);	 // "get_local_linear_id"
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+1, "s_valid_reserve_id", 18) != 0)
        break;
      return std::make_pair(2686, 1);	 // "is_valid_reserve_id"
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ub_group_broadcast", 18) != 0)
        break;
      return std::make_pair(2738, 3);	 // "sub_group_broadcast"
    }
    break;
  case 20:	 // 48 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "tomic_load_explicit", 19) != 0)
        break;
      return std::make_pair(1775, 42);	 // "atomic_load_explicit"
    case 'c':	 // 37 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 'c':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "har_sat_rt", 10) != 0)
          break;
        switch (Name[19]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(172, 11);	 // "convert_char_sat_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(172, 11);	 // "convert_char_sat_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(172, 11);	 // "convert_char_sat_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(172, 11);	 // "convert_char_sat_rtz"
        }
        break;
      case 'd':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "ouble16_rt", 10) != 0)
          break;
        switch (Name[19]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(623, 11);	 // "convert_double16_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(623, 11);	 // "convert_double16_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(623, 11);	 // "convert_double16_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(623, 11);	 // "convert_double16_rtz"
        }
        break;
      case 'i':	 // 16 strings to match.
        if (memcmp(Name.data()+9, "nt", 2) != 0)
          break;
        switch (Name[11]) {
        default: break;
        case '2':	 // 4 strings to match.
          if (memcmp(Name.data()+12, "_sat_rt", 7) != 0)
            break;
          switch (Name[19]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(447, 11);	 // "convert_int2_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(447, 11);	 // "convert_int2_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(447, 11);	 // "convert_int2_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(447, 11);	 // "convert_int2_sat_rtz"
          }
          break;
        case '3':	 // 4 strings to match.
          if (memcmp(Name.data()+12, "_sat_rt", 7) != 0)
            break;
          switch (Name[19]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(458, 11);	 // "convert_int3_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(458, 11);	 // "convert_int3_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(458, 11);	 // "convert_int3_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(458, 11);	 // "convert_int3_sat_rtz"
          }
          break;
        case '4':	 // 4 strings to match.
          if (memcmp(Name.data()+12, "_sat_rt", 7) != 0)
            break;
          switch (Name[19]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(469, 11);	 // "convert_int4_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(469, 11);	 // "convert_int4_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(469, 11);	 // "convert_int4_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(469, 11);	 // "convert_int4_sat_rtz"
          }
          break;
        case '8':	 // 4 strings to match.
          if (memcmp(Name.data()+12, "_sat_rt", 7) != 0)
            break;
          switch (Name[19]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(480, 11);	 // "convert_int8_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(480, 11);	 // "convert_int8_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(480, 11);	 // "convert_int8_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(480, 11);	 // "convert_int8_sat_rtz"
          }
          break;
        }
        break;
      case 'l':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "ong_sat_rt", 10) != 0)
          break;
        switch (Name[19]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(634, 11);	 // "convert_long_sat_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(634, 11);	 // "convert_long_sat_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(634, 11);	 // "convert_long_sat_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(634, 11);	 // "convert_long_sat_rtz"
        }
        break;
      case 'u':	 // 9 strings to match.
        switch (Name[9]) {
        default: break;
        case 'i':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "nt_sat_rt", 9) != 0)
            break;
          switch (Name[19]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(502, 11);	 // "convert_uint_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(502, 11);	 // "convert_uint_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(502, 11);	 // "convert_uint_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(502, 11);	 // "convert_uint_sat_rtz"
          }
          break;
        case 's':	 // 5 strings to match.
          if (memcmp(Name.data()+10, "hort16_", 7) != 0)
            break;
          switch (Name[17]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Name[18] != 't')
              break;
            switch (Name[19]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(425, 11);	 // "convert_ushort16_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(425, 11);	 // "convert_ushort16_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(425, 11);	 // "convert_ushort16_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(425, 11);	 // "convert_ushort16_rtz"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+18, "at", 2) != 0)
              break;
            return std::make_pair(425, 11);	 // "convert_ushort16_sat"
          }
          break;
        }
        break;
      }
      break;
    case 'd':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "ot_4x8packed_", 13) != 0)
        break;
      switch (Name[14]) {
      default: break;
      case 's':	 // 2 strings to match.
        switch (Name[15]) {
        default: break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+16, "_int", 4) != 0)
            break;
          return std::make_pair(104, 1);	 // "dot_4x8packed_ss_int"
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+16, "_int", 4) != 0)
            break;
          return std::make_pair(104, 1);	 // "dot_4x8packed_su_int"
        }
        break;
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+15, "s_int", 5) != 0)
          break;
        return std::make_pair(104, 1);	 // "dot_4x8packed_us_int"
      }
      break;
    case 'g':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+5, "lobal_linear_id", 15) != 0)
          break;
        return std::make_pair(769, 1);	 // "get_global_linear_id"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+5, "mage_array_size", 15) != 0)
          break;
        return std::make_pair(2632, 15);	 // "get_image_array_size"
      }
      break;
    case 's':	 // 4 strings to match.
      if (memcmp(Name.data()+1, "ub_group_", 9) != 0)
        break;
      switch (Name[10]) {
      default: break;
      case 'r':	 // 3 strings to match.
        if (memcmp(Name.data()+11, "educe_", 6) != 0)
          break;
        switch (Name[17]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+18, "dd", 2) != 0)
            break;
          return std::make_pair(2741, 2);	 // "sub_group_reduce_add"
        case 'm':	 // 2 strings to match.
          switch (Name[18]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (Name[19] != 'x')
              break;
            return std::make_pair(2741, 2);	 // "sub_group_reduce_max"
          case 'i':	 // 1 string to match.
            if (Name[19] != 'n')
              break;
            return std::make_pair(2741, 2);	 // "sub_group_reduce_min"
          }
          break;
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+11, "huffle_up", 9) != 0)
          break;
        return std::make_pair(49, 1);	 // "sub_group_shuffle_up"
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ork_group_broadcast", 19) != 0)
        break;
      return std::make_pair(2682, 3);	 // "work_group_broadcast"
    }
    break;
  case 21:	 // 78 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ync_work_group_copy", 19) != 0)
          break;
        return std::make_pair(1482, 2);	 // "async_work_group_copy"
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+2, "omic_store_explicit", 19) != 0)
          break;
        return std::make_pair(1567, 42);	 // "atomic_store_explicit"
      }
      break;
    case 'c':	 // 64 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 'c':	 // 16 strings to match.
        if (memcmp(Name.data()+9, "har", 3) != 0)
          break;
        switch (Name[12]) {
        default: break;
        case '2':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
            break;
          switch (Name[20]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(183, 11);	 // "convert_char2_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(183, 11);	 // "convert_char2_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(183, 11);	 // "convert_char2_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(183, 11);	 // "convert_char2_sat_rtz"
          }
          break;
        case '3':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
            break;
          switch (Name[20]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(194, 11);	 // "convert_char3_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(194, 11);	 // "convert_char3_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(194, 11);	 // "convert_char3_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(194, 11);	 // "convert_char3_sat_rtz"
          }
          break;
        case '4':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
            break;
          switch (Name[20]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(205, 11);	 // "convert_char4_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(205, 11);	 // "convert_char4_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(205, 11);	 // "convert_char4_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(205, 11);	 // "convert_char4_sat_rtz"
          }
          break;
        case '8':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
            break;
          switch (Name[20]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(216, 11);	 // "convert_char8_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(216, 11);	 // "convert_char8_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(216, 11);	 // "convert_char8_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(216, 11);	 // "convert_char8_sat_rtz"
          }
          break;
        }
        break;
      case 'i':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "nt16_sat_rt", 11) != 0)
          break;
        switch (Name[20]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(491, 11);	 // "convert_int16_sat_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(491, 11);	 // "convert_int16_sat_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(491, 11);	 // "convert_int16_sat_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(491, 11);	 // "convert_int16_sat_rtz"
        }
        break;
      case 'l':	 // 16 strings to match.
        if (memcmp(Name.data()+9, "ong", 3) != 0)
          break;
        switch (Name[12]) {
        default: break;
        case '2':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
            break;
          switch (Name[20]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(645, 11);	 // "convert_long2_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(645, 11);	 // "convert_long2_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(645, 11);	 // "convert_long2_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(645, 11);	 // "convert_long2_sat_rtz"
          }
          break;
        case '3':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
            break;
          switch (Name[20]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(656, 11);	 // "convert_long3_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(656, 11);	 // "convert_long3_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(656, 11);	 // "convert_long3_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(656, 11);	 // "convert_long3_sat_rtz"
          }
          break;
        case '4':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
            break;
          switch (Name[20]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(667, 11);	 // "convert_long4_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(667, 11);	 // "convert_long4_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(667, 11);	 // "convert_long4_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(667, 11);	 // "convert_long4_sat_rtz"
          }
          break;
        case '8':	 // 4 strings to match.
          if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
            break;
          switch (Name[20]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(678, 11);	 // "convert_long8_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(678, 11);	 // "convert_long8_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(678, 11);	 // "convert_long8_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(678, 11);	 // "convert_long8_sat_rtz"
          }
          break;
        }
        break;
      case 's':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "hort_sat_rt", 11) != 0)
          break;
        switch (Name[20]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(304, 11);	 // "convert_short_sat_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(304, 11);	 // "convert_short_sat_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(304, 11);	 // "convert_short_sat_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(304, 11);	 // "convert_short_sat_rtz"
        }
        break;
      case 'u':	 // 24 strings to match.
        switch (Name[9]) {
        default: break;
        case 'c':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "har_sat_rt", 10) != 0)
            break;
          switch (Name[20]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(238, 11);	 // "convert_uchar_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(238, 11);	 // "convert_uchar_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(238, 11);	 // "convert_uchar_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(238, 11);	 // "convert_uchar_sat_rtz"
          }
          break;
        case 'i':	 // 16 strings to match.
          if (memcmp(Name.data()+10, "nt", 2) != 0)
            break;
          switch (Name[12]) {
          default: break;
          case '2':	 // 4 strings to match.
            if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
              break;
            switch (Name[20]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(513, 11);	 // "convert_uint2_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(513, 11);	 // "convert_uint2_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(513, 11);	 // "convert_uint2_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(513, 11);	 // "convert_uint2_sat_rtz"
            }
            break;
          case '3':	 // 4 strings to match.
            if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
              break;
            switch (Name[20]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(524, 11);	 // "convert_uint3_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(524, 11);	 // "convert_uint3_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(524, 11);	 // "convert_uint3_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(524, 11);	 // "convert_uint3_sat_rtz"
            }
            break;
          case '4':	 // 4 strings to match.
            if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
              break;
            switch (Name[20]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(535, 11);	 // "convert_uint4_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(535, 11);	 // "convert_uint4_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(535, 11);	 // "convert_uint4_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(535, 11);	 // "convert_uint4_sat_rtz"
            }
            break;
          case '8':	 // 4 strings to match.
            if (memcmp(Name.data()+13, "_sat_rt", 7) != 0)
              break;
            switch (Name[20]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(546, 11);	 // "convert_uint8_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(546, 11);	 // "convert_uint8_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(546, 11);	 // "convert_uint8_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(546, 11);	 // "convert_uint8_sat_rtz"
            }
            break;
          }
          break;
        case 'l':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "ong_sat_rt", 10) != 0)
            break;
          switch (Name[20]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(700, 11);	 // "convert_ulong_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(700, 11);	 // "convert_ulong_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(700, 11);	 // "convert_ulong_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(700, 11);	 // "convert_ulong_sat_rtz"
          }
          break;
        }
        break;
      }
      break;
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ot_4x8packed_uu_uint", 20) != 0)
        break;
      return std::make_pair(103, 1);	 // "dot_4x8packed_uu_uint"
    case 'g':	 // 6 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+5, "mage_num_samples", 16) != 0)
          break;
        return std::make_pair(2721, 12);	 // "get_image_num_samples"
      case 's':	 // 5 strings to match.
        if (memcmp(Name.data()+5, "ub_group_", 9) != 0)
          break;
        switch (Name[14]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+15, "q_mask", 6) != 0)
            break;
          return std::make_pair(2753, 1);	 // "get_sub_group_eq_mask"
        case 'g':	 // 2 strings to match.
          switch (Name[15]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (memcmp(Name.data()+16, "_mask", 5) != 0)
              break;
            return std::make_pair(2753, 1);	 // "get_sub_group_ge_mask"
          case 't':	 // 1 string to match.
            if (memcmp(Name.data()+16, "_mask", 5) != 0)
              break;
            return std::make_pair(2753, 1);	 // "get_sub_group_gt_mask"
          }
          break;
        case 'l':	 // 2 strings to match.
          switch (Name[15]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (memcmp(Name.data()+16, "_mask", 5) != 0)
              break;
            return std::make_pair(2753, 1);	 // "get_sub_group_le_mask"
          case 't':	 // 1 string to match.
            if (memcmp(Name.data()+16, "_mask", 5) != 0)
              break;
            return std::make_pair(2753, 1);	 // "get_sub_group_lt_mask"
          }
          break;
        }
        break;
      }
      break;
    case 's':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "t_user_event_status", 19) != 0)
          break;
        return std::make_pair(2691, 1);	 // "set_user_event_status"
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+2, "b_group_shuffle_xor", 19) != 0)
          break;
        return std::make_pair(48, 1);	 // "sub_group_shuffle_xor"
      }
      break;
    case 'w':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "ork_group_reduce_", 17) != 0)
        break;
      switch (Name[18]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+19, "dd", 2) != 0)
          break;
        return std::make_pair(2685, 1);	 // "work_group_reduce_add"
      case 'm':	 // 2 strings to match.
        switch (Name[19]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (Name[20] != 'x')
            break;
          return std::make_pair(2685, 1);	 // "work_group_reduce_max"
        case 'i':	 // 1 string to match.
          if (Name[20] != 'n')
            break;
          return std::make_pair(2685, 1);	 // "work_group_reduce_min"
        }
        break;
      }
      break;
    }
    break;
  case 22:	 // 68 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "tomic_work_item_fence", 21) != 0)
        break;
      return std::make_pair(1753, 1);	 // "atomic_work_item_fence"
    case 'c':	 // 64 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 'c':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "har16_sat_rt", 12) != 0)
          break;
        switch (Name[21]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(227, 11);	 // "convert_char16_sat_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(227, 11);	 // "convert_char16_sat_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(227, 11);	 // "convert_char16_sat_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(227, 11);	 // "convert_char16_sat_rtz"
        }
        break;
      case 'l':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "ong16_sat_rt", 12) != 0)
          break;
        switch (Name[21]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(689, 11);	 // "convert_long16_sat_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(689, 11);	 // "convert_long16_sat_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(689, 11);	 // "convert_long16_sat_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(689, 11);	 // "convert_long16_sat_rtz"
        }
        break;
      case 's':	 // 16 strings to match.
        if (memcmp(Name.data()+9, "hort", 4) != 0)
          break;
        switch (Name[13]) {
        default: break;
        case '2':	 // 4 strings to match.
          if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
            break;
          switch (Name[21]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(315, 11);	 // "convert_short2_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(315, 11);	 // "convert_short2_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(315, 11);	 // "convert_short2_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(315, 11);	 // "convert_short2_sat_rtz"
          }
          break;
        case '3':	 // 4 strings to match.
          if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
            break;
          switch (Name[21]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(326, 11);	 // "convert_short3_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(326, 11);	 // "convert_short3_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(326, 11);	 // "convert_short3_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(326, 11);	 // "convert_short3_sat_rtz"
          }
          break;
        case '4':	 // 4 strings to match.
          if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
            break;
          switch (Name[21]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(337, 11);	 // "convert_short4_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(337, 11);	 // "convert_short4_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(337, 11);	 // "convert_short4_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(337, 11);	 // "convert_short4_sat_rtz"
          }
          break;
        case '8':	 // 4 strings to match.
          if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
            break;
          switch (Name[21]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(348, 11);	 // "convert_short8_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(348, 11);	 // "convert_short8_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(348, 11);	 // "convert_short8_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(348, 11);	 // "convert_short8_sat_rtz"
          }
          break;
        }
        break;
      case 'u':	 // 40 strings to match.
        switch (Name[9]) {
        default: break;
        case 'c':	 // 16 strings to match.
          if (memcmp(Name.data()+10, "har", 3) != 0)
            break;
          switch (Name[13]) {
          default: break;
          case '2':	 // 4 strings to match.
            if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
              break;
            switch (Name[21]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(249, 11);	 // "convert_uchar2_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(249, 11);	 // "convert_uchar2_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(249, 11);	 // "convert_uchar2_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(249, 11);	 // "convert_uchar2_sat_rtz"
            }
            break;
          case '3':	 // 4 strings to match.
            if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
              break;
            switch (Name[21]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(260, 11);	 // "convert_uchar3_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(260, 11);	 // "convert_uchar3_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(260, 11);	 // "convert_uchar3_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(260, 11);	 // "convert_uchar3_sat_rtz"
            }
            break;
          case '4':	 // 4 strings to match.
            if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
              break;
            switch (Name[21]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(271, 11);	 // "convert_uchar4_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(271, 11);	 // "convert_uchar4_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(271, 11);	 // "convert_uchar4_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(271, 11);	 // "convert_uchar4_sat_rtz"
            }
            break;
          case '8':	 // 4 strings to match.
            if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
              break;
            switch (Name[21]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(282, 11);	 // "convert_uchar8_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(282, 11);	 // "convert_uchar8_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(282, 11);	 // "convert_uchar8_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(282, 11);	 // "convert_uchar8_sat_rtz"
            }
            break;
          }
          break;
        case 'i':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "nt16_sat_rt", 11) != 0)
            break;
          switch (Name[21]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(557, 11);	 // "convert_uint16_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(557, 11);	 // "convert_uint16_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(557, 11);	 // "convert_uint16_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(557, 11);	 // "convert_uint16_sat_rtz"
          }
          break;
        case 'l':	 // 16 strings to match.
          if (memcmp(Name.data()+10, "ong", 3) != 0)
            break;
          switch (Name[13]) {
          default: break;
          case '2':	 // 4 strings to match.
            if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
              break;
            switch (Name[21]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(711, 11);	 // "convert_ulong2_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(711, 11);	 // "convert_ulong2_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(711, 11);	 // "convert_ulong2_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(711, 11);	 // "convert_ulong2_sat_rtz"
            }
            break;
          case '3':	 // 4 strings to match.
            if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
              break;
            switch (Name[21]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(722, 11);	 // "convert_ulong3_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(722, 11);	 // "convert_ulong3_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(722, 11);	 // "convert_ulong3_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(722, 11);	 // "convert_ulong3_sat_rtz"
            }
            break;
          case '4':	 // 4 strings to match.
            if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
              break;
            switch (Name[21]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(733, 11);	 // "convert_ulong4_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(733, 11);	 // "convert_ulong4_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(733, 11);	 // "convert_ulong4_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(733, 11);	 // "convert_ulong4_sat_rtz"
            }
            break;
          case '8':	 // 4 strings to match.
            if (memcmp(Name.data()+14, "_sat_rt", 7) != 0)
              break;
            switch (Name[21]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(744, 11);	 // "convert_ulong8_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(744, 11);	 // "convert_ulong8_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(744, 11);	 // "convert_ulong8_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(744, 11);	 // "convert_ulong8_sat_rtz"
            }
            break;
          }
          break;
        case 's':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "hort_sat_rt", 11) != 0)
            break;
          switch (Name[21]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(370, 11);	 // "convert_ushort_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(370, 11);	 // "convert_ushort_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(370, 11);	 // "convert_ushort_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(370, 11);	 // "convert_ushort_sat_rtz"
          }
          break;
        }
        break;
      }
      break;
    case 'g':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'm':	 // 1 string to match.
        if (memcmp(Name.data()+5, "ax_sub_group_size", 17) != 0)
          break;
        return std::make_pair(2733, 1);	 // "get_max_sub_group_size"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+5, "ub_group_local_id", 17) != 0)
          break;
        return std::make_pair(2733, 1);	 // "get_sub_group_local_id"
      }
      break;
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ub_group_shuffle_down", 21) != 0)
        break;
      return std::make_pair(49, 1);	 // "sub_group_shuffle_down"
    }
    break;
  case 23:	 // 31 strings to match.
    switch (Name[0]) {
    default: break;
    case 'b':	 // 1 string to match.
      if (memcmp(Name.data()+1, "itfield_extract_signed", 22) != 0)
        break;
      return std::make_pair(76, 2);	 // "bitfield_extract_signed"
    case 'c':	 // 28 strings to match.
      if (memcmp(Name.data()+1, "onvert_", 7) != 0)
        break;
      switch (Name[8]) {
      default: break;
      case 's':	 // 4 strings to match.
        if (memcmp(Name.data()+9, "hort16_sat_rt", 13) != 0)
          break;
        switch (Name[22]) {
        default: break;
        case 'e':	 // 1 string to match.
          return std::make_pair(359, 11);	 // "convert_short16_sat_rte"
        case 'n':	 // 1 string to match.
          return std::make_pair(359, 11);	 // "convert_short16_sat_rtn"
        case 'p':	 // 1 string to match.
          return std::make_pair(359, 11);	 // "convert_short16_sat_rtp"
        case 'z':	 // 1 string to match.
          return std::make_pair(359, 11);	 // "convert_short16_sat_rtz"
        }
        break;
      case 'u':	 // 24 strings to match.
        switch (Name[9]) {
        default: break;
        case 'c':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "har16_sat_rt", 12) != 0)
            break;
          switch (Name[22]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(293, 11);	 // "convert_uchar16_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(293, 11);	 // "convert_uchar16_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(293, 11);	 // "convert_uchar16_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(293, 11);	 // "convert_uchar16_sat_rtz"
          }
          break;
        case 'l':	 // 4 strings to match.
          if (memcmp(Name.data()+10, "ong16_sat_rt", 12) != 0)
            break;
          switch (Name[22]) {
          default: break;
          case 'e':	 // 1 string to match.
            return std::make_pair(755, 11);	 // "convert_ulong16_sat_rte"
          case 'n':	 // 1 string to match.
            return std::make_pair(755, 11);	 // "convert_ulong16_sat_rtn"
          case 'p':	 // 1 string to match.
            return std::make_pair(755, 11);	 // "convert_ulong16_sat_rtp"
          case 'z':	 // 1 string to match.
            return std::make_pair(755, 11);	 // "convert_ulong16_sat_rtz"
          }
          break;
        case 's':	 // 16 strings to match.
          if (memcmp(Name.data()+10, "hort", 4) != 0)
            break;
          switch (Name[14]) {
          default: break;
          case '2':	 // 4 strings to match.
            if (memcmp(Name.data()+15, "_sat_rt", 7) != 0)
              break;
            switch (Name[22]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(381, 11);	 // "convert_ushort2_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(381, 11);	 // "convert_ushort2_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(381, 11);	 // "convert_ushort2_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(381, 11);	 // "convert_ushort2_sat_rtz"
            }
            break;
          case '3':	 // 4 strings to match.
            if (memcmp(Name.data()+15, "_sat_rt", 7) != 0)
              break;
            switch (Name[22]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(392, 11);	 // "convert_ushort3_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(392, 11);	 // "convert_ushort3_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(392, 11);	 // "convert_ushort3_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(392, 11);	 // "convert_ushort3_sat_rtz"
            }
            break;
          case '4':	 // 4 strings to match.
            if (memcmp(Name.data()+15, "_sat_rt", 7) != 0)
              break;
            switch (Name[22]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(403, 11);	 // "convert_ushort4_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(403, 11);	 // "convert_ushort4_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(403, 11);	 // "convert_ushort4_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(403, 11);	 // "convert_ushort4_sat_rtz"
            }
            break;
          case '8':	 // 4 strings to match.
            if (memcmp(Name.data()+15, "_sat_rt", 7) != 0)
              break;
            switch (Name[22]) {
            default: break;
            case 'e':	 // 1 string to match.
              return std::make_pair(414, 11);	 // "convert_ushort8_sat_rte"
            case 'n':	 // 1 string to match.
              return std::make_pair(414, 11);	 // "convert_ushort8_sat_rtn"
            case 'p':	 // 1 string to match.
              return std::make_pair(414, 11);	 // "convert_ushort8_sat_rtp"
            case 'z':	 // 1 string to match.
              return std::make_pair(414, 11);	 // "convert_ushort8_sat_rtz"
            }
            break;
          }
          break;
        }
        break;
      }
      break;
    case 'g':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "et_", 3) != 0)
        break;
      switch (Name[4]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+5, "nqueued_local_size", 18) != 0)
          break;
        return std::make_pair(768, 1);	 // "get_enqueued_local_size"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+5, "mage_channel_order", 18) != 0)
          break;
        return std::make_pair(2539, 36);	 // "get_image_channel_order"
      }
      break;
    }
    break;
  case 24:	 // 9 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "tomic_", 6) != 0)
        break;
      switch (Name[7]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+8, "xchange_explicit", 16) != 0)
          break;
        return std::make_pair(1838, 42);	 // "atomic_exchange_explicit"
      case 'f':	 // 2 strings to match.
        switch (Name[8]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+9, "tch_or_explicit", 15) != 0)
            break;
          return std::make_pair(1964, 24);	 // "atomic_fetch_or_explicit"
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+9, "ag_test_and_set", 15) != 0)
            break;
          return std::make_pair(1997, 3);	 // "atomic_flag_test_and_set"
        }
        break;
      }
      break;
    case 'c':	 // 4 strings to match.
      if (memcmp(Name.data()+1, "onvert_ushort16_sat_rt", 22) != 0)
        break;
      switch (Name[23]) {
      default: break;
      case 'e':	 // 1 string to match.
        return std::make_pair(425, 11);	 // "convert_ushort16_sat_rte"
      case 'n':	 // 1 string to match.
        return std::make_pair(425, 11);	 // "convert_ushort16_sat_rtn"
      case 'p':	 // 1 string to match.
        return std::make_pair(425, 11);	 // "convert_ushort16_sat_rtp"
      case 'z':	 // 1 string to match.
        return std::make_pair(425, 11);	 // "convert_ushort16_sat_rtz"
      }
      break;
    case 'g':	 // 1 string to match.
      if (memcmp(Name.data()+1, "et_image_num_mip_levels", 23) != 0)
        break;
      return std::make_pair(2700, 21);	 // "get_image_num_mip_levels"
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ub_group_inverse_ballot", 23) != 0)
        break;
      return std::make_pair(2749, 1);	 // "sub_group_inverse_ballot"
    }
    break;
  case 25:	 // 12 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 6 strings to match.
      if (memcmp(Name.data()+1, "tomic_fetch_", 12) != 0)
        break;
      switch (Name[13]) {
      default: break;
      case 'a':	 // 2 strings to match.
        switch (Name[14]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+15, "d_explicit", 10) != 0)
            break;
          return std::make_pair(1904, 48);	 // "atomic_fetch_add_explicit"
        case 'n':	 // 1 string to match.
          if (memcmp(Name.data()+15, "d_explicit", 10) != 0)
            break;
          return std::make_pair(1964, 24);	 // "atomic_fetch_and_explicit"
        }
        break;
      case 'm':	 // 2 strings to match.
        switch (Name[14]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+15, "x_explicit", 10) != 0)
            break;
          return std::make_pair(1838, 42);	 // "atomic_fetch_max_explicit"
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+15, "n_explicit", 10) != 0)
            break;
          return std::make_pair(1838, 42);	 // "atomic_fetch_min_explicit"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+14, "ub_explicit", 11) != 0)
          break;
        return std::make_pair(1904, 48);	 // "atomic_fetch_sub_explicit"
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+14, "or_explicit", 11) != 0)
          break;
        return std::make_pair(1964, 24);	 // "atomic_fetch_xor_explicit"
      }
      break;
    case 'b':	 // 1 string to match.
      if (memcmp(Name.data()+1, "itfield_extract_unsigned", 24) != 0)
        break;
      return std::make_pair(78, 2);	 // "bitfield_extract_unsigned"
    case 's':	 // 5 strings to match.
      if (memcmp(Name.data()+1, "ub_group_", 9) != 0)
        break;
      switch (Name[10]) {
      default: break;
      case 'b':	 // 3 strings to match.
        switch (Name[11]) {
        default: break;
        case 'a':	 // 2 strings to match.
          if (memcmp(Name.data()+12, "llot_find_", 10) != 0)
            break;
          switch (Name[22]) {
          default: break;
          case 'l':	 // 1 string to match.
            if (memcmp(Name.data()+23, "sb", 2) != 0)
              break;
            return std::make_pair(2752, 1);	 // "sub_group_ballot_find_lsb"
          case 'm':	 // 1 string to match.
            if (memcmp(Name.data()+23, "sb", 2) != 0)
              break;
            return std::make_pair(2752, 1);	 // "sub_group_ballot_find_msb"
          }
          break;
        case 'r':	 // 1 string to match.
          if (memcmp(Name.data()+12, "oadcast_first", 13) != 0)
            break;
          return std::make_pair(2747, 1);	 // "sub_group_broadcast_first"
        }
        break;
      case 'n':	 // 2 strings to match.
        if (memcmp(Name.data()+11, "on_uniform_a", 12) != 0)
          break;
        switch (Name[23]) {
        default: break;
        case 'l':	 // 1 string to match.
          if (Name[24] != 'l')
            break;
          return std::make_pair(2744, 1);	 // "sub_group_non_uniform_all"
        case 'n':	 // 1 string to match.
          if (Name[24] != 'y')
            break;
          return std::make_pair(2744, 1);	 // "sub_group_non_uniform_any"
        }
        break;
      }
      break;
    }
    break;
  case 26:	 // 3 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "tomic_flag_clear_explicit", 25) != 0)
        break;
      return std::make_pair(1991, 6);	 // "atomic_flag_clear_explicit"
    case 's':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "ub_group_", 9) != 0)
        break;
      switch (Name[10]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+11, "allot_bit_count", 15) != 0)
          break;
        return std::make_pair(2751, 1);	 // "sub_group_ballot_bit_count"
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+11, "lustered_rotate", 15) != 0)
          break;
        return std::make_pair(108, 1);	 // "sub_group_clustered_rotate"
      }
      break;
    }
    break;
  case 27:	 // 2 strings to match.
    if (memcmp(Name.data()+0, "get_", 4) != 0)
      break;
    switch (Name[4]) {
    default: break;
    case 'e':	 // 1 string to match.
      if (memcmp(Name.data()+5, "nqueued_num_sub_groups", 22) != 0)
        break;
      return std::make_pair(2734, 1);	 // "get_enqueued_num_sub_groups"
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+5, "mage_channel_data_type", 22) != 0)
        break;
      return std::make_pair(2539, 36);	 // "get_image_channel_data_type"
    }
    break;
  case 28:	 // 12 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "tomic_compare_exchange_weak", 27) != 0)
        break;
      return std::make_pair(1627, 42);	 // "atomic_compare_exchange_weak"
    case 'c':	 // 1 string to match.
      if (memcmp(Name.data()+1, "apture_event_profiling_info", 27) != 0)
        break;
      return std::make_pair(2692, 1);	 // "capture_event_profiling_info"
    case 'd':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "ot_acc_sat_4x8packed_", 21) != 0)
        break;
      switch (Name[22]) {
      default: break;
      case 's':	 // 2 strings to match.
        switch (Name[23]) {
        default: break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+24, "_int", 4) != 0)
            break;
          return std::make_pair(106, 1);	 // "dot_acc_sat_4x8packed_ss_int"
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+24, "_int", 4) != 0)
            break;
          return std::make_pair(106, 1);	 // "dot_acc_sat_4x8packed_su_int"
        }
        break;
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+23, "s_int", 5) != 0)
          break;
        return std::make_pair(106, 1);	 // "dot_acc_sat_4x8packed_us_int"
      }
      break;
    case 's':	 // 7 strings to match.
      if (memcmp(Name.data()+1, "ub_group_", 9) != 0)
        break;
      switch (Name[10]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+11, "allot_bit_extract", 17) != 0)
          break;
        return std::make_pair(2750, 1);	 // "sub_group_ballot_bit_extract"
      case 's':	 // 6 strings to match.
        if (memcmp(Name.data()+11, "can_", 4) != 0)
          break;
        switch (Name[15]) {
        default: break;
        case 'e':	 // 3 strings to match.
          if (memcmp(Name.data()+16, "xclusive_", 9) != 0)
            break;
          switch (Name[25]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Name.data()+26, "dd", 2) != 0)
              break;
            return std::make_pair(2741, 2);	 // "sub_group_scan_exclusive_add"
          case 'm':	 // 2 strings to match.
            switch (Name[26]) {
            default: break;
            case 'a':	 // 1 string to match.
              if (Name[27] != 'x')
                break;
              return std::make_pair(2741, 2);	 // "sub_group_scan_exclusive_max"
            case 'i':	 // 1 string to match.
              if (Name[27] != 'n')
                break;
              return std::make_pair(2741, 2);	 // "sub_group_scan_exclusive_min"
            }
            break;
          }
          break;
        case 'i':	 // 3 strings to match.
          if (memcmp(Name.data()+16, "nclusive_", 9) != 0)
            break;
          switch (Name[25]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Name.data()+26, "dd", 2) != 0)
              break;
            return std::make_pair(2741, 2);	 // "sub_group_scan_inclusive_add"
          case 'm':	 // 2 strings to match.
            switch (Name[26]) {
            default: break;
            case 'a':	 // 1 string to match.
              if (Name[27] != 'x')
                break;
              return std::make_pair(2741, 2);	 // "sub_group_scan_inclusive_max"
            case 'i':	 // 1 string to match.
              if (Name[27] != 'n')
                break;
              return std::make_pair(2741, 2);	 // "sub_group_scan_inclusive_min"
            }
            break;
          }
          break;
        }
        break;
      }
      break;
    }
    break;
  case 29:	 // 9 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "sync_work_group_strided_copy", 28) != 0)
        break;
      return std::make_pair(1484, 2);	 // "async_work_group_strided_copy"
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ot_acc_sat_4x8packed_uu_uint", 28) != 0)
        break;
      return std::make_pair(105, 1);	 // "dot_acc_sat_4x8packed_uu_uint"
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ub_group_clustered_reduce_or", 28) != 0)
        break;
      return std::make_pair(62, 1);	 // "sub_group_clustered_reduce_or"
    case 'w':	 // 6 strings to match.
      if (memcmp(Name.data()+1, "ork_group_scan_", 15) != 0)
        break;
      switch (Name[16]) {
      default: break;
      case 'e':	 // 3 strings to match.
        if (memcmp(Name.data()+17, "xclusive_", 9) != 0)
          break;
        switch (Name[26]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+27, "dd", 2) != 0)
            break;
          return std::make_pair(2685, 1);	 // "work_group_scan_exclusive_add"
        case 'm':	 // 2 strings to match.
          switch (Name[27]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (Name[28] != 'x')
              break;
            return std::make_pair(2685, 1);	 // "work_group_scan_exclusive_max"
          case 'i':	 // 1 string to match.
            if (Name[28] != 'n')
              break;
            return std::make_pair(2685, 1);	 // "work_group_scan_exclusive_min"
          }
          break;
        }
        break;
      case 'i':	 // 3 strings to match.
        if (memcmp(Name.data()+17, "nclusive_", 9) != 0)
          break;
        switch (Name[26]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+27, "dd", 2) != 0)
            break;
          return std::make_pair(2685, 1);	 // "work_group_scan_inclusive_add"
        case 'm':	 // 2 strings to match.
          switch (Name[27]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (Name[28] != 'x')
              break;
            return std::make_pair(2685, 1);	 // "work_group_scan_inclusive_max"
          case 'i':	 // 1 string to match.
            if (Name[28] != 'n')
              break;
            return std::make_pair(2685, 1);	 // "work_group_scan_inclusive_min"
          }
          break;
        }
        break;
      }
      break;
    }
    break;
  case 30:	 // 7 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "tomic_compare_exchange_strong", 29) != 0)
        break;
      return std::make_pair(1627, 42);	 // "atomic_compare_exchange_strong"
    case 's':	 // 6 strings to match.
      if (memcmp(Name.data()+1, "ub_group_clustered_reduce_", 26) != 0)
        break;
      switch (Name[27]) {
      default: break;
      case 'a':	 // 2 strings to match.
        switch (Name[28]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[29] != 'd')
            break;
          return std::make_pair(61, 1);	 // "sub_group_clustered_reduce_add"
        case 'n':	 // 1 string to match.
          if (Name[29] != 'd')
            break;
          return std::make_pair(62, 1);	 // "sub_group_clustered_reduce_and"
        }
        break;
      case 'm':	 // 3 strings to match.
        switch (Name[28]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (Name[29] != 'x')
            break;
          return std::make_pair(61, 1);	 // "sub_group_clustered_reduce_max"
        case 'i':	 // 1 string to match.
          if (Name[29] != 'n')
            break;
          return std::make_pair(61, 1);	 // "sub_group_clustered_reduce_min"
        case 'u':	 // 1 string to match.
          if (Name[29] != 'l')
            break;
          return std::make_pair(61, 1);	 // "sub_group_clustered_reduce_mul"
        }
        break;
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+28, "or", 2) != 0)
          break;
        return std::make_pair(62, 1);	 // "sub_group_clustered_reduce_xor"
      }
      break;
    }
    break;
  case 31:	 // 5 strings to match.
    if (memcmp(Name.data()+0, "sub_group_", 10) != 0)
      break;
    switch (Name[10]) {
    default: break;
    case 'b':	 // 2 strings to match.
      if (memcmp(Name.data()+11, "allot_", 6) != 0)
        break;
      switch (Name[17]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+18, "xclusive_scan", 13) != 0)
          break;
        return std::make_pair(2752, 1);	 // "sub_group_ballot_exclusive_scan"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+18, "nclusive_scan", 13) != 0)
          break;
        return std::make_pair(2752, 1);	 // "sub_group_ballot_inclusive_scan"
      }
      break;
    case 'n':	 // 3 strings to match.
      if (memcmp(Name.data()+11, "on_uniform_", 11) != 0)
        break;
      switch (Name[22]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+23, "ll_equal", 8) != 0)
          break;
        return std::make_pair(2745, 1);	 // "sub_group_non_uniform_all_equal"
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+23, "roadcast", 8) != 0)
          break;
        return std::make_pair(2746, 1);	 // "sub_group_non_uniform_broadcast"
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+23, "educe_or", 8) != 0)
          break;
        return std::make_pair(24, 1);	 // "sub_group_non_uniform_reduce_or"
      }
      break;
    }
    break;
  case 32:	 // 6 strings to match.
    if (memcmp(Name.data()+0, "sub_group_non_uniform_reduce_", 29) != 0)
      break;
    switch (Name[29]) {
    default: break;
    case 'a':	 // 2 strings to match.
      switch (Name[30]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (Name[31] != 'd')
          break;
        return std::make_pair(23, 1);	 // "sub_group_non_uniform_reduce_add"
      case 'n':	 // 1 string to match.
        if (Name[31] != 'd')
          break;
        return std::make_pair(24, 1);	 // "sub_group_non_uniform_reduce_and"
      }
      break;
    case 'm':	 // 3 strings to match.
      switch (Name[30]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (Name[31] != 'x')
          break;
        return std::make_pair(23, 1);	 // "sub_group_non_uniform_reduce_max"
      case 'i':	 // 1 string to match.
        if (Name[31] != 'n')
          break;
        return std::make_pair(23, 1);	 // "sub_group_non_uniform_reduce_min"
      case 'u':	 // 1 string to match.
        if (Name[31] != 'l')
          break;
        return std::make_pair(23, 1);	 // "sub_group_non_uniform_reduce_mul"
      }
      break;
    case 'x':	 // 1 string to match.
      if (memcmp(Name.data()+30, "or", 2) != 0)
        break;
      return std::make_pair(24, 1);	 // "sub_group_non_uniform_reduce_xor"
    }
    break;
  case 33:	 // 1 string to match.
    if (memcmp(Name.data()+0, "atomic_flag_test_and_set_explicit", 33) != 0)
      break;
    return std::make_pair(2000, 6);	 // "atomic_flag_test_and_set_explicit"
  case 37:	 // 2 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "tomic_compare_exchange_weak_explicit", 36) != 0)
        break;
      return std::make_pair(1669, 84);	 // "atomic_compare_exchange_weak_explicit"
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ub_group_clustered_reduce_logical_or", 36) != 0)
        break;
      return std::make_pair(63, 1);	 // "sub_group_clustered_reduce_logical_or"
    }
    break;
  case 38:	 // 2 strings to match.
    if (memcmp(Name.data()+0, "sub_group_clustered_reduce_logical_", 35) != 0)
      break;
    switch (Name[35]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+36, "nd", 2) != 0)
        break;
      return std::make_pair(63, 1);	 // "sub_group_clustered_reduce_logical_and"
    case 'x':	 // 1 string to match.
      if (memcmp(Name.data()+36, "or", 2) != 0)
        break;
      return std::make_pair(63, 1);	 // "sub_group_clustered_reduce_logical_xor"
    }
    break;
  case 39:	 // 4 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "tomic_compare_exchange_strong_explicit", 38) != 0)
        break;
      return std::make_pair(1669, 84);	 // "atomic_compare_exchange_strong_explicit"
    case 's':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "ub_group_non_uniform_", 21) != 0)
        break;
      switch (Name[22]) {
      default: break;
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+23, "educe_logical_or", 16) != 0)
          break;
        return std::make_pair(25, 1);	 // "sub_group_non_uniform_reduce_logical_or"
      case 's':	 // 2 strings to match.
        if (memcmp(Name.data()+23, "can_", 4) != 0)
          break;
        switch (Name[27]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+28, "xclusive_or", 11) != 0)
            break;
          return std::make_pair(24, 1);	 // "sub_group_non_uniform_scan_exclusive_or"
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+28, "nclusive_or", 11) != 0)
            break;
          return std::make_pair(24, 1);	 // "sub_group_non_uniform_scan_inclusive_or"
        }
        break;
      }
      break;
    }
    break;
  case 40:	 // 14 strings to match.
    if (memcmp(Name.data()+0, "sub_group_non_uniform_", 22) != 0)
      break;
    switch (Name[22]) {
    default: break;
    case 'r':	 // 2 strings to match.
      if (memcmp(Name.data()+23, "educe_logical_", 14) != 0)
        break;
      switch (Name[37]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+38, "nd", 2) != 0)
          break;
        return std::make_pair(25, 1);	 // "sub_group_non_uniform_reduce_logical_and"
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+38, "or", 2) != 0)
          break;
        return std::make_pair(25, 1);	 // "sub_group_non_uniform_reduce_logical_xor"
      }
      break;
    case 's':	 // 12 strings to match.
      if (memcmp(Name.data()+23, "can_", 4) != 0)
        break;
      switch (Name[27]) {
      default: break;
      case 'e':	 // 6 strings to match.
        if (memcmp(Name.data()+28, "xclusive_", 9) != 0)
          break;
        switch (Name[37]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[38]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[39] != 'd')
              break;
            return std::make_pair(23, 1);	 // "sub_group_non_uniform_scan_exclusive_add"
          case 'n':	 // 1 string to match.
            if (Name[39] != 'd')
              break;
            return std::make_pair(24, 1);	 // "sub_group_non_uniform_scan_exclusive_and"
          }
          break;
        case 'm':	 // 3 strings to match.
          switch (Name[38]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (Name[39] != 'x')
              break;
            return std::make_pair(23, 1);	 // "sub_group_non_uniform_scan_exclusive_max"
          case 'i':	 // 1 string to match.
            if (Name[39] != 'n')
              break;
            return std::make_pair(23, 1);	 // "sub_group_non_uniform_scan_exclusive_min"
          case 'u':	 // 1 string to match.
            if (Name[39] != 'l')
              break;
            return std::make_pair(23, 1);	 // "sub_group_non_uniform_scan_exclusive_mul"
          }
          break;
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+38, "or", 2) != 0)
            break;
          return std::make_pair(24, 1);	 // "sub_group_non_uniform_scan_exclusive_xor"
        }
        break;
      case 'i':	 // 6 strings to match.
        if (memcmp(Name.data()+28, "nclusive_", 9) != 0)
          break;
        switch (Name[37]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[38]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[39] != 'd')
              break;
            return std::make_pair(23, 1);	 // "sub_group_non_uniform_scan_inclusive_add"
          case 'n':	 // 1 string to match.
            if (Name[39] != 'd')
              break;
            return std::make_pair(24, 1);	 // "sub_group_non_uniform_scan_inclusive_and"
          }
          break;
        case 'm':	 // 3 strings to match.
          switch (Name[38]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (Name[39] != 'x')
              break;
            return std::make_pair(23, 1);	 // "sub_group_non_uniform_scan_inclusive_max"
          case 'i':	 // 1 string to match.
            if (Name[39] != 'n')
              break;
            return std::make_pair(23, 1);	 // "sub_group_non_uniform_scan_inclusive_min"
          case 'u':	 // 1 string to match.
            if (Name[39] != 'l')
              break;
            return std::make_pair(23, 1);	 // "sub_group_non_uniform_scan_inclusive_mul"
          }
          break;
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+38, "or", 2) != 0)
            break;
          return std::make_pair(24, 1);	 // "sub_group_non_uniform_scan_inclusive_xor"
        }
        break;
      }
      break;
    }
    break;
  case 47:	 // 2 strings to match.
    if (memcmp(Name.data()+0, "sub_group_non_uniform_scan_", 27) != 0)
      break;
    switch (Name[27]) {
    default: break;
    case 'e':	 // 1 string to match.
      if (memcmp(Name.data()+28, "xclusive_logical_or", 19) != 0)
        break;
      return std::make_pair(25, 1);	 // "sub_group_non_uniform_scan_exclusive_logical_or"
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+28, "nclusive_logical_or", 19) != 0)
        break;
      return std::make_pair(25, 1);	 // "sub_group_non_uniform_scan_inclusive_logical_or"
    }
    break;
  case 48:	 // 4 strings to match.
    if (memcmp(Name.data()+0, "sub_group_non_uniform_scan_", 27) != 0)
      break;
    switch (Name[27]) {
    default: break;
    case 'e':	 // 2 strings to match.
      if (memcmp(Name.data()+28, "xclusive_logical_", 17) != 0)
        break;
      switch (Name[45]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+46, "nd", 2) != 0)
          break;
        return std::make_pair(25, 1);	 // "sub_group_non_uniform_scan_exclusive_logical_and"
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+46, "or", 2) != 0)
          break;
        return std::make_pair(25, 1);	 // "sub_group_non_uniform_scan_exclusive_logical_xor"
      }
      break;
    case 'i':	 // 2 strings to match.
      if (memcmp(Name.data()+28, "nclusive_logical_", 17) != 0)
        break;
      switch (Name[45]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+46, "nd", 2) != 0)
          break;
        return std::make_pair(25, 1);	 // "sub_group_non_uniform_scan_inclusive_logical_and"
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+46, "or", 2) != 0)
          break;
        return std::make_pair(25, 1);	 // "sub_group_non_uniform_scan_inclusive_logical_xor"
      }
      break;
    }
    break;
  }
  return std::make_pair(0, 0);
} // isOpenCLBuiltin


static QualType getOpenCLEnumType(Sema &S, llvm::StringRef Name);
static QualType getOpenCLTypedefType(Sema &S, llvm::StringRef Name);

// Convert an OpenCLTypeStruct type to a list of QualTypes.
// Generic types represent multiple types and vector sizes, thus a vector
// is returned. The conversion is done in two steps:
// Step 1: A switch statement fills a vector with scalar base types for the
//         Cartesian product of (vector sizes) x (types) for generic types,
//         or a single scalar type for non generic types.
// Step 2: Qualifiers and other type properties such as vector size are
//         applied.
static void OCL2Qual(Sema &S, const OpenCLTypeStruct &Ty,
                     llvm::SmallVectorImpl<QualType> &QT) {
  ASTContext &Context = S.Context;
  // Number of scalar types in the GenType.
  unsigned GenTypeNumTypes;
  // Pointer to the list of vector sizes for the GenType.
  llvm::ArrayRef<unsigned> GenVectorSizes;
  constexpr unsigned ListVec1[] = {1, };
  constexpr unsigned ListVec1234[] = {1, 2, 3, 4, };
  constexpr unsigned ListVecAndScalar[] = {1, 2, 3, 4, 8, 16, };
  constexpr unsigned ListVecNoScalar[] = {2, 3, 4, 8, 16, };

  switch (Ty.ID) {
    case OCLT_image2d_depth_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          if (S.getPreprocessor().isMacroDefined("cl_khr_depth_images")) {
            QT.push_back(Context.OCLImage2dDepthROTy);
          }
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("cl_khr_depth_images")) {
            QT.push_back(Context.OCLImage2dDepthRWTy);
          }
          break;
        case OCLAQ_WriteOnly:
          if (S.getPreprocessor().isMacroDefined("cl_khr_depth_images")) {
            QT.push_back(Context.OCLImage2dDepthWOTy);
          }
          break;
      }
      break;
    case OCLT_image2d_array_msaa_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          QT.push_back(Context.OCLImage2dArrayMSAAROTy);
          break;
        case OCLAQ_WriteOnly:
          QT.push_back(Context.OCLImage2dArrayMSAAWOTy);
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("__opencl_c_read_write_images")) {
            QT.push_back(Context.OCLImage2dArrayMSAARWTy);
          }
          break;
      }
      break;
    case OCLT_image2d_msaa_depth_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          QT.push_back(Context.OCLImage2dMSAADepthROTy);
          break;
        case OCLAQ_WriteOnly:
          QT.push_back(Context.OCLImage2dMSAADepthWOTy);
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("__opencl_c_read_write_images")) {
            QT.push_back(Context.OCLImage2dMSAADepthRWTy);
          }
          break;
      }
      break;
    case OCLT_image2d_msaa_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          QT.push_back(Context.OCLImage2dMSAAROTy);
          break;
        case OCLAQ_WriteOnly:
          QT.push_back(Context.OCLImage2dMSAAWOTy);
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("__opencl_c_read_write_images")) {
            QT.push_back(Context.OCLImage2dMSAARWTy);
          }
          break;
      }
      break;
    case OCLT_image1d_buffer_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          QT.push_back(Context.OCLImage1dBufferROTy);
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("__opencl_c_read_write_images")) {
            QT.push_back(Context.OCLImage1dBufferRWTy);
          }
          break;
        case OCLAQ_WriteOnly:
          QT.push_back(Context.OCLImage1dBufferWOTy);
          break;
      }
      break;
    case OCLT_image1d_array_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          QT.push_back(Context.OCLImage1dArrayROTy);
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("__opencl_c_read_write_images")) {
            QT.push_back(Context.OCLImage1dArrayRWTy);
          }
          break;
        case OCLAQ_WriteOnly:
          QT.push_back(Context.OCLImage1dArrayWOTy);
          break;
      }
      break;
    case OCLT_image2d_array_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          QT.push_back(Context.OCLImage2dArrayROTy);
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("__opencl_c_read_write_images")) {
            QT.push_back(Context.OCLImage2dArrayRWTy);
          }
          break;
        case OCLAQ_WriteOnly:
          QT.push_back(Context.OCLImage2dArrayWOTy);
          break;
      }
      break;
    case OCLT_image1d_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          QT.push_back(Context.OCLImage1dROTy);
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("__opencl_c_read_write_images")) {
            QT.push_back(Context.OCLImage1dRWTy);
          }
          break;
        case OCLAQ_WriteOnly:
          QT.push_back(Context.OCLImage1dWOTy);
          break;
      }
      break;
    case OCLT_image2d_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          QT.push_back(Context.OCLImage2dROTy);
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("__opencl_c_read_write_images")) {
            QT.push_back(Context.OCLImage2dRWTy);
          }
          break;
        case OCLAQ_WriteOnly:
          QT.push_back(Context.OCLImage2dWOTy);
          break;
      }
      break;
    case OCLT_image3d_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          QT.push_back(Context.OCLImage3dROTy);
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("cl_khr_3d_image_writes") && S.getPreprocessor().isMacroDefined("__opencl_c_read_write_images")) {
            QT.push_back(Context.OCLImage3dRWTy);
          }
          break;
        case OCLAQ_WriteOnly:
          if (S.getPreprocessor().isMacroDefined("cl_khr_3d_image_writes")) {
            QT.push_back(Context.OCLImage3dWOTy);
          }
          break;
      }
      break;
    case OCLT_image2d_array_depth_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          if (S.getPreprocessor().isMacroDefined("cl_khr_depth_images")) {
            QT.push_back(Context.OCLImage2dArrayDepthROTy);
          }
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("cl_khr_depth_images")) {
            QT.push_back(Context.OCLImage2dArrayDepthRWTy);
          }
          break;
        case OCLAQ_WriteOnly:
          if (S.getPreprocessor().isMacroDefined("cl_khr_depth_images")) {
            QT.push_back(Context.OCLImage2dArrayDepthWOTy);
          }
          break;
      }
      break;
    case OCLT_image2d_array_msaa_depth_t:
      switch (Ty.AccessQualifier) {
        case OCLAQ_None:
          llvm_unreachable("Image without access qualifier");
        case OCLAQ_ReadOnly:
          QT.push_back(Context.OCLImage2dArrayMSAADepthROTy);
          break;
        case OCLAQ_WriteOnly:
          QT.push_back(Context.OCLImage2dArrayMSAADepthWOTy);
          break;
        case OCLAQ_ReadWrite:
          if (S.getPreprocessor().isMacroDefined("__opencl_c_read_write_images")) {
            QT.push_back(Context.OCLImage2dArrayMSAADepthRWTy);
          }
          break;
      }
      break;
    case OCLT_AGenType1: {
      SmallVector<QualType, 11> TypeList;
      TypeList.push_back(Context.CharTy);
      TypeList.push_back(Context.UnsignedCharTy);
      TypeList.push_back(Context.ShortTy);
      TypeList.push_back(Context.UnsignedShortTy);
      TypeList.push_back(Context.IntTy);
      TypeList.push_back(Context.UnsignedIntTy);
      TypeList.push_back(Context.LongTy);
      TypeList.push_back(Context.UnsignedLongTy);
      TypeList.push_back(Context.FloatTy);
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp64")) {
        TypeList.push_back(Context.DoubleTy);
      }
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp16")) {
        TypeList.push_back(Context.HalfTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(11);
      for (unsigned I = 0; I < 1; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVec1;
      break;
    }
    case OCLT_AGenTypeN: {
      SmallVector<QualType, 11> TypeList;
      TypeList.push_back(Context.CharTy);
      TypeList.push_back(Context.UnsignedCharTy);
      TypeList.push_back(Context.ShortTy);
      TypeList.push_back(Context.UnsignedShortTy);
      TypeList.push_back(Context.IntTy);
      TypeList.push_back(Context.UnsignedIntTy);
      TypeList.push_back(Context.LongTy);
      TypeList.push_back(Context.UnsignedLongTy);
      TypeList.push_back(Context.FloatTy);
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp64")) {
        TypeList.push_back(Context.DoubleTy);
      }
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp16")) {
        TypeList.push_back(Context.HalfTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(66);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_AGenTypeNNoScalar: {
      SmallVector<QualType, 11> TypeList;
      TypeList.push_back(Context.CharTy);
      TypeList.push_back(Context.UnsignedCharTy);
      TypeList.push_back(Context.ShortTy);
      TypeList.push_back(Context.UnsignedShortTy);
      TypeList.push_back(Context.IntTy);
      TypeList.push_back(Context.UnsignedIntTy);
      TypeList.push_back(Context.LongTy);
      TypeList.push_back(Context.UnsignedLongTy);
      TypeList.push_back(Context.FloatTy);
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp64")) {
        TypeList.push_back(Context.DoubleTy);
      }
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp16")) {
        TypeList.push_back(Context.HalfTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(55);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_AI2UGenTypeN: {
      SmallVector<QualType, 8> TypeList;
      TypeList.push_back(Context.UnsignedCharTy);
      TypeList.push_back(Context.UnsignedCharTy);
      TypeList.push_back(Context.UnsignedShortTy);
      TypeList.push_back(Context.UnsignedShortTy);
      TypeList.push_back(Context.UnsignedIntTy);
      TypeList.push_back(Context.UnsignedIntTy);
      TypeList.push_back(Context.UnsignedLongTy);
      TypeList.push_back(Context.UnsignedLongTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(48);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_AIGenType1: {
      SmallVector<QualType, 8> TypeList;
      TypeList.push_back(Context.CharTy);
      TypeList.push_back(Context.UnsignedCharTy);
      TypeList.push_back(Context.ShortTy);
      TypeList.push_back(Context.UnsignedShortTy);
      TypeList.push_back(Context.IntTy);
      TypeList.push_back(Context.UnsignedIntTy);
      TypeList.push_back(Context.LongTy);
      TypeList.push_back(Context.UnsignedLongTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(8);
      for (unsigned I = 0; I < 1; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVec1;
      break;
    }
    case OCLT_AIGenTypeN: {
      SmallVector<QualType, 8> TypeList;
      TypeList.push_back(Context.CharTy);
      TypeList.push_back(Context.UnsignedCharTy);
      TypeList.push_back(Context.ShortTy);
      TypeList.push_back(Context.UnsignedShortTy);
      TypeList.push_back(Context.IntTy);
      TypeList.push_back(Context.UnsignedIntTy);
      TypeList.push_back(Context.LongTy);
      TypeList.push_back(Context.UnsignedLongTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(48);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_AIGenTypeNNoScalar: {
      SmallVector<QualType, 8> TypeList;
      TypeList.push_back(Context.CharTy);
      TypeList.push_back(Context.UnsignedCharTy);
      TypeList.push_back(Context.ShortTy);
      TypeList.push_back(Context.UnsignedShortTy);
      TypeList.push_back(Context.IntTy);
      TypeList.push_back(Context.UnsignedIntTy);
      TypeList.push_back(Context.LongTy);
      TypeList.push_back(Context.UnsignedLongTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(40);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_CharShortGenType1: {
      SmallVector<QualType, 4> TypeList;
      TypeList.push_back(Context.CharTy);
      TypeList.push_back(Context.UnsignedCharTy);
      TypeList.push_back(Context.ShortTy);
      TypeList.push_back(Context.UnsignedShortTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(4);
      for (unsigned I = 0; I < 1; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVec1;
      break;
    }
    case OCLT_FGenTypeN: {
      SmallVector<QualType, 3> TypeList;
      TypeList.push_back(Context.FloatTy);
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp64")) {
        TypeList.push_back(Context.DoubleTy);
      }
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp16")) {
        TypeList.push_back(Context.HalfTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(18);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeCharVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.CharTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeCharVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.CharTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_GenTypeDoubleVec1234: {
      SmallVector<QualType, 1> TypeList;
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp64")) {
        TypeList.push_back(Context.DoubleTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(4);
      for (unsigned I = 0; I < 4; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVec1234;
      break;
    }
    case OCLT_GenTypeDoubleVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp64")) {
        TypeList.push_back(Context.DoubleTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeDoubleVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp64")) {
        TypeList.push_back(Context.DoubleTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_GenTypeFloatVec1234: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.FloatTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(4);
      for (unsigned I = 0; I < 4; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVec1234;
      break;
    }
    case OCLT_GenTypeFloatVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.FloatTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeFloatVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.FloatTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_GenTypeHalfVec1234: {
      SmallVector<QualType, 1> TypeList;
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp16")) {
        TypeList.push_back(Context.HalfTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(4);
      for (unsigned I = 0; I < 4; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVec1234;
      break;
    }
    case OCLT_GenTypeHalfVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp16")) {
        TypeList.push_back(Context.HalfTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeHalfVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp16")) {
        TypeList.push_back(Context.HalfTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_GenTypeIntVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.IntTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeIntVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.IntTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_GenTypeLongVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.LongTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeLongVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.LongTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_GenTypeShortVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.ShortTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeShortVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.ShortTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_GenTypeUCharVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.UnsignedCharTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeUCharVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.UnsignedCharTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_GenTypeUIntVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.UnsignedIntTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeUIntVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.UnsignedIntTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_GenTypeULongVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.UnsignedLongTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeULongVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.UnsignedLongTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_GenTypeUShortVecAndScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.UnsignedShortTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(6);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_GenTypeUShortVecNoScalar: {
      SmallVector<QualType, 1> TypeList;
      TypeList.push_back(Context.UnsignedShortTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(5);
      for (unsigned I = 0; I < 5; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecNoScalar;
      break;
    }
    case OCLT_IntLongFloatGenType1: {
      SmallVector<QualType, 7> TypeList;
      TypeList.push_back(Context.IntTy);
      TypeList.push_back(Context.UnsignedIntTy);
      TypeList.push_back(Context.LongTy);
      TypeList.push_back(Context.UnsignedLongTy);
      TypeList.push_back(Context.FloatTy);
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp64")) {
        TypeList.push_back(Context.DoubleTy);
      }
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp16")) {
        TypeList.push_back(Context.HalfTy);
      }
      GenTypeNumTypes = TypeList.size();
      QT.reserve(7);
      for (unsigned I = 0; I < 1; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVec1;
      break;
    }
    case OCLT_SGenTypeN: {
      SmallVector<QualType, 4> TypeList;
      TypeList.push_back(Context.CharTy);
      TypeList.push_back(Context.ShortTy);
      TypeList.push_back(Context.IntTy);
      TypeList.push_back(Context.LongTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(24);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_UGenTypeN: {
      SmallVector<QualType, 4> TypeList;
      TypeList.push_back(Context.UnsignedCharTy);
      TypeList.push_back(Context.UnsignedShortTy);
      TypeList.push_back(Context.UnsignedIntTy);
      TypeList.push_back(Context.UnsignedLongTy);
      GenTypeNumTypes = TypeList.size();
      QT.reserve(24);
      for (unsigned I = 0; I < 6; I++) {
        QT.append(TypeList);
      }
      GenVectorSizes = ListVecAndScalar;
      break;
    }
    case OCLT_atomic_double:
      if (S.getPreprocessor().isMacroDefined("cl_khr_int64_base_atomics") && S.getPreprocessor().isMacroDefined("cl_khr_int64_extended_atomics") && S.getPreprocessor().isMacroDefined("cl_khr_fp64")) {
        QT.push_back(Context.getAtomicType(Context.DoubleTy));
      }
      break;
    case OCLT_atomic_flag:
      QT.push_back(getOpenCLTypedefType(S, "atomic_flag"));
      break;
    case OCLT_atomic_float:
      QT.push_back(Context.getAtomicType(Context.FloatTy));
      break;
    case OCLT_atomic_half:
      QT.push_back(Context.getAtomicType(Context.HalfTy));
      break;
    case OCLT_atomic_int:
      QT.push_back(Context.getAtomicType(Context.IntTy));
      break;
    case OCLT_atomic_intptr_t:
      QT.push_back(Context.getAtomicType(Context.getIntPtrType()));
      break;
    case OCLT_atomic_long:
      if (S.getPreprocessor().isMacroDefined("cl_khr_int64_base_atomics") && S.getPreprocessor().isMacroDefined("cl_khr_int64_extended_atomics")) {
        QT.push_back(Context.getAtomicType(Context.LongTy));
      }
      break;
    case OCLT_atomic_ptrdiff_t:
      QT.push_back(Context.getAtomicType(Context.getPointerDiffType()));
      break;
    case OCLT_atomic_size_t:
      QT.push_back(Context.getAtomicType(Context.getSizeType()));
      break;
    case OCLT_atomic_uint:
      QT.push_back(Context.getAtomicType(Context.UnsignedIntTy));
      break;
    case OCLT_atomic_uintptr_t:
      QT.push_back(Context.getAtomicType(Context.getUIntPtrType()));
      break;
    case OCLT_atomic_ulong:
      if (S.getPreprocessor().isMacroDefined("cl_khr_int64_base_atomics") && S.getPreprocessor().isMacroDefined("cl_khr_int64_extended_atomics")) {
        QT.push_back(Context.getAtomicType(Context.UnsignedLongTy));
      }
      break;
    case OCLT_bool:
      QT.push_back(Context.BoolTy);
      break;
    case OCLT_char:
      QT.push_back(Context.CharTy);
      break;
    case OCLT_clk_event_t:
      QT.push_back(Context.OCLClkEventTy);
      break;
    case OCLT_clk_profiling_info:
      QT.push_back(getOpenCLTypedefType(S, "clk_profiling_info"));
      break;
    case OCLT_double:
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp64")) {
        QT.push_back(Context.DoubleTy);
      }
      break;
    case OCLT_event_t:
      QT.push_back(Context.OCLEventTy);
      break;
    case OCLT_float:
      QT.push_back(Context.FloatTy);
      break;
    case OCLT_half:
      if (S.getPreprocessor().isMacroDefined("cl_khr_fp16")) {
        QT.push_back(Context.HalfTy);
      }
      break;
    case OCLT___half:
      QT.push_back(Context.HalfTy);
      break;
    case OCLT_int:
      QT.push_back(Context.IntTy);
      break;
    case OCLT_intptr_t:
      QT.push_back(Context.getIntPtrType());
      break;
    case OCLT_long:
      QT.push_back(Context.LongTy);
      break;
    case OCLT_cl_mem_fence_flags:
      QT.push_back(getOpenCLTypedefType(S, "cl_mem_fence_flags"));
      break;
    case OCLT_memory_order:
      QT.push_back(getOpenCLEnumType(S, "memory_order"));
      break;
    case OCLT_memory_scope:
      QT.push_back(getOpenCLEnumType(S, "memory_scope"));
      break;
    case OCLT_ndrange_t:
      QT.push_back(getOpenCLTypedefType(S, "ndrange_t"));
      break;
    case OCLT_ptrdiff_t:
      QT.push_back(Context.getPointerDiffType());
      break;
    case OCLT_queue_t:
      QT.push_back(Context.OCLQueueTy);
      break;
    case OCLT_reserve_id_t:
      QT.push_back(Context.OCLReserveIDTy);
      break;
    case OCLT_sampler_t:
      QT.push_back(Context.OCLSamplerTy);
      break;
    case OCLT_short:
      QT.push_back(Context.ShortTy);
      break;
    case OCLT_size_t:
      QT.push_back(Context.getSizeType());
      break;
    case OCLT_uchar:
      QT.push_back(Context.UnsignedCharTy);
      break;
    case OCLT_uint:
      QT.push_back(Context.UnsignedIntTy);
      break;
    case OCLT_uintptr_t:
      QT.push_back(Context.getUIntPtrType());
      break;
    case OCLT_ulong:
      QT.push_back(Context.UnsignedLongTy);
      break;
    case OCLT_ushort:
      QT.push_back(Context.UnsignedShortTy);
      break;
    case OCLT_void:
      QT.push_back(Context.VoidTy);
      break;
  } // end of switch (Ty.ID)

  // Construct the different vector types for each generic type.
  if (Ty.ID >= 52) {
    for (unsigned I = 0; I < QT.size(); I++) {
      // For scalars, size is 1.
      if (GenVectorSizes[I / GenTypeNumTypes] != 1) {
        QT[I] = Context.getExtVectorType(QT[I],
                          GenVectorSizes[I / GenTypeNumTypes]);
      }
    }
  }

  // Set vector size for non-generic vector types.
  if (Ty.VectorWidth > 1) {
    for (unsigned Index = 0; Index < QT.size(); Index++) {
      QT[Index] = Context.getExtVectorType(QT[Index], Ty.VectorWidth);
    }
  }

  if (Ty.IsVolatile != 0) {
    for (unsigned Index = 0; Index < QT.size(); Index++) {
      QT[Index] = Context.getVolatileType(QT[Index]);
    }
  }

  if (Ty.IsConst != 0) {
    for (unsigned Index = 0; Index < QT.size(); Index++) {
      QT[Index] = Context.getConstType(QT[Index]);
    }
  }

  // Transform the type to a pointer as the last step, if necessary.
  // Builtin functions only have pointers on [const|volatile], no
  // [const|volatile] pointers, so this is ok to do it as a last step.
  if (Ty.IsPointer != 0) {
    for (unsigned Index = 0; Index < QT.size(); Index++) {
      QT[Index] = Context.getAddrSpaceQualType(QT[Index], Ty.AS);
      QT[Index] = Context.getPointerType(QT[Index]);
    }
  }

} // OCL2Qual
