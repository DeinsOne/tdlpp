
cmake_minimum_required(VERSION 3.18.4 FATAL_ERROR)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(TdlppDependencies LANGUAGES CXX C)

## Set up build threads
include(ProcessorCount)

ProcessorCount(PROCESSOR_COUNT)
set(CMAKE_NUM_BUILD_JOBS ${PROCESSOR_COUNT} CACHE STRING "Number of build jobs '-j <n>'")
set(DEFAULT_BUILD_COMMAND cmake --build . --config release -j ${CMAKE_NUM_BUILD_JOBS})

include(ExternalProject)
include(install-module.cmake)

##################################################################################################################

set(TDLPP_TD_DEFINES)

if (TDLPP_BUILD_OPENSSL)
  build_subproject(
    NAME openssl
    URL "https://github.com/janbar/openssl-cmake.git"
    TAG d4634362820f874e1f1461c7f5d766b3ef968c67
    BUILD_ARGS
      -DWITH_APPS=OFF
      -DBUILD_SHARED_LIBS=ON
  )

  set(OPENSSL_ROOT_DIR ${TDLPP_DEPS_INSTALL_PATH}/openssl CACHE STRING "OpenSSL root directory")
  list(APPEND TDLPP_TD_DEFINES -DOPENSSL_ROOT_DIR=${OPENSSL_ROOT_DIR})
endif()

##################################################################################################################

if (TDLPP_BUILD_ZLIB)
  build_subproject(
    NAME zlib
    URL "https://github.com/madler/zlib.git"
    TAG cacf7f1d4e3d44d871b605da3b647f07d718623f
  )

  set(ZLIB_ROOT ${TDLPP_DEPS_INSTALL_PATH}/zlib CACHE STRING "Zlib root directory")
  list(APPEND TDLPP_TD_DEFINES -DZLIB_ROOT=${ZLIB_ROOT})
endif()

##################################################################################################################

if (TDLPP_BUILD_GPERF AND TDLPP_BUILD_TDLIB)
  build_subproject(
    NAME gperf
    URL "https://github.com/jwinarske/gperf.git"
    TAG 49da03c6ff2515be730bf39cb989379793b6dd6e
  )

  if (WIN32)
    set(GPERF_EXECUTABLE ${TDLPP_DEPS_INSTALL_PATH}/gperf/bin/gperf.exe CACHE STRING "Gperf executable")
  else()
    set(GPERF_EXECUTABLE ${TDLPP_DEPS_INSTALL_PATH}/gperf/bin/gperf CACHE STRING "Gperf executable")
  endif()

  list(APPEND TDLPP_TD_DEFINES -DGPERF_EXECUTABLE=${GPERF_EXECUTABLE})
endif()

##################################################################################################################

build_subproject(
  NAME plog
  URL "https://github.com/SergiusTheBest/plog.git"
  TAG origin/master
  BUILD_ARGS
    -DPLOG_BUILD_SAMPLES=OFF
)

##################################################################################################################

if (TDLPP_BUILD_TDLIB)
  build_subproject(
    NAME td
    URL "https://github.com/tdlib/td.git"
    TAG origin/master
    BUILD_ARGS ${TDLPP_TD_DEFINES}
    DEPENDS_ON openssl zlib gperf
  )
endif()
