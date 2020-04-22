include (FindPythonModule)

# Check which Python version ROOT was build against  
find_program(ROOT_CONFIG_EXECUTABLE root-config)
exec_program(${ROOT_CONFIG_EXECUTABLE} ARGS "--python-version" OUTPUT_VARIABLE ROOT_PYTHON_VERSION RETURN_VALUE RETVAR)
set(ROOT_PYTHON_VERSION ${ROOT_PYTHON_VERSION} CACHE INTERNAL "")
string(REGEX REPLACE "^([0-9]+)\\.[0-9]+.*" "\\1" PYTHON_VERSION_MAJOR "${ROOT_PYTHON_VERSION}")

# FindPython we used to build ROOT against
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.14)
    find_package(Python${PYTHON_VERSION_MAJOR} COMPONENTS Interpreter NumPy)
else()
    find_package(PythonInterp ${PYTHON_VERSION_MAJOR})
    find_python_module(numpy QUIET)
endif()

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.14)
    set(PYTHON_EXECUTABLE "${Python${PYTHON_VERSION_MAJOR}_EXECUTABLE}" CACHE INTERNAL "" FORCE)
    set(PYTHON_INCLUDE_DIRS "${Python${PYTHON_VERSION_MAJOR}_INCLUDE_DIRS}" CACHE INTERNAL "" FORCE)
    set(PYTHON_LIBRARIES "${Python${PYTHON_VERSION_MAJOR}_LIBRARIES}" CACHE INTERNAL "" FORCE)
    set(PYTHON_VERSION_MAJOR "${PYTHON_VERSION_MAJOR}" CACHE INTERNAL "" FORCE)
    set(PYTHON_VERSION_MINOR "${Python${PYTHON_VERSION_MAJOR}_VERSION_MINOR}" CACHE INTERNAL "" FORCE)
    set(NUMPY_FOUND ${Python${PYTHON_VERSION_MAJOR}_NumPy_FOUND} CACHE INTERNAL "" FORCE)
endif()

# Find mandatory dependency (for Python benchmarks), but quietly :)
find_python_module(pytest QUIET)

if(NOT PYTEST_FOUND)
message(STATUS "Be aware that pytest benchmarks are not enabled (missing pytest & pytest-benchmark dependency). 
                Please install them using pip and provided requirements.txt")
endif()
