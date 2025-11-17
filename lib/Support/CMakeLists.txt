RB_ADD_LIBRARY(RBSupport
  ErrorHandling.cxx
  MemoryManager.cxx
)
target_include_directories(RBSupport PUBLIC
  ${PROJECT_BINARY_DIR}/include
  ${PROJECT_SOURCE_DIR}/include
  ${GBENCHMARK_INCLUDE_DIR})
