include(ExternalProject)

ExternalProject_Add(FlameGraph
	GIT_REPOSITORY "https://github.com/brendangregg/FlameGraph.git"
	UPDATE_COMMAND ""
	PATCH_COMMAND patch < ${CMAKE_SOURCE_DIR}/rootbench-scripts/stackcollapse-perf.patch
	CONFIGURE_COMMAND ""
	BUILD_COMMAND ""
	INSTALL_COMMAND ""
	EXCLUDE_FROM_ALL 1
)


