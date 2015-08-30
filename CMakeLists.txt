cmake_minimum_required( VERSION 2.8.12 )
project ( "metanet" )

# configurable options
option(WITH_SPAM "enable spammy printf debugging" OFF)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/cmake_modules")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


# enable debug spam
if(USE_SPAM)
  add_definitions("-DDEBUG_SPAM")
  message(STATUS "spammy printf debugging enabled")
  message(STATUS "AWWWWWE YEEEEEEEHHHHHH!!! :D")
endif()

# default build is debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Check for c++11 support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" CXX11_SUPPORTED)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" CXX0X_SUPPORTED)
if(CXX11_SUPPORTED)
    add_definitions("-std=c++11")
elseif(CXX0X_SUPPORTED) # gcc 4.6
    add_definitions("-std=c++0x")
elseif(NOT MSVC)
    message(SEND_ERROR "C++11 standard not supported by compiler. Version too old?")
endif()

# use pthreads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package (Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG) # compile time flag
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()
# Load includes
include_directories(
    ${CMAKE_SOURCE_DIR} ${SODIUM_INCLUDE_DIR}
    ${META_CORE_SRC}
)

# this is nice
include(GNUInstallDirs)

add_subdirectory(meta)
add_subdirectory(tests)
