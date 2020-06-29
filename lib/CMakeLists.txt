RB_ADD_LIBRARY(RBSupport
  ErrorHandling.cxx
)
target_include_directories(RBSupport PUBLIC ${PROJECT_SOURCE_DIR}/include PRIVATE ${PROJECT_BINARY_DIR}/include)
