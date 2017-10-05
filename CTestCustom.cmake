#-------------------------------------------------------------------------------
#
# CTestCustom.cmake
#
# This file enables customization of CTest.
#
#-------------------------------------------------------------------------------

# Specify tests that will be ignored.

list(APPEND CTEST_CUSTOM_TESTS_IGNORE
	IOBenchmarks)