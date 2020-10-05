RB_ADD_LIBRARY(RBSupport
  ErrorHandling.cxx
  MemoryMeasurement.cxx
  )
target_include_directories(RBSupport PUBLIC ${PROJECT_BINARY_DIR}/include ${PROJECT_SOURCE_DIR}/include)
