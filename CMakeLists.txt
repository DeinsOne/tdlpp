
## Tdlpp cmake global project ##
cmake_minimum_required(VERSION 3.18.4 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

if(NOT CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX
    "${CMAKE_BINARY_DIR}/install"
    CACHE STRING "Final install location"
  )
endif()

###################################################################################################
## Specifieng the project ##

project(tdlpp VERSION 0.1.13 LANGUAGES CXX)

option(TDLPP_BUILD_SAMPLES      "Build tdl++ samples" ON)

##################################################################################################################
## Set up build threads

include(ProcessorCount)
ProcessorCount(PROCESSOR_COUNT)
set(CMAKE_NUM_BUILD_JOBS ${PROCESSOR_COUNT} CACHE STRING "Number of build jobs '-j <n>'")
set(DEFAULT_BUILD_COMMAND cmake --build . --config release -j ${CMAKE_NUM_BUILD_JOBS})

##################################################################################################################
## Building and installing modules

if (NOT TDLPP_DEPS_SOURCE_PATH)
  set(TDLPP_DEPS_SOURCE_PATH
    ${CMAKE_CURRENT_LIST_DIR}/external
    CACHE STRING "Where to locate source of downloaded dependencies"
  )
endif()

if (NOT TDLPP_DEPS_BUILD_PATH)
  set(TDLPP_DEPS_BUILD_PATH
    ${CMAKE_BINARY_DIR}/external
    CACHE STRING "Where to build downloaded dependencies"
  )
endif()

if (NOT TDLPP_DEPS_INSTALL_PATH)
  set(TDLPP_DEPS_INSTALL_PATH 
    ${CMAKE_BINARY_DIR}/external/install
    CACHE STRING "Where to install downloaded dependencies"
  )
endif()

execute_process(COMMAND
  ${CMAKE_COMMAND}
    -G ${CMAKE_GENERATOR}
    -S ${CMAKE_CURRENT_LIST_DIR}/external
    -B ${TDLPP_DEPS_BUILD_PATH}
      -DTDLPP_DEPS_SOURCE_PATH=${TDLPP_DEPS_SOURCE_PATH}
      -DTDLPP_DEPS_BUILD_PATH=${TDLPP_DEPS_BUILD_PATH}
      -DTDLPP_DEPS_INSTALL_PATH=${TDLPP_DEPS_INSTALL_PATH}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
)

execute_process(COMMAND
  ${CMAKE_COMMAND} --build . --config Release --parallel ${CMAKE_NUM_BUILD_JOBS} -j ${CMAKE_NUM_BUILD_JOBS}
  WORKING_DIRECTORY ${TDLPP_DEPS_BUILD_PATH}
)


###################################################################################################
## Tdlpp

set(Td_DIR ${TDLPP_DEPS_INSTALL_PATH}/td/lib/cmake/Td)
find_package(Td CONFIG REQUIRED NO_DEFAULT_PATH)


set(TDLPP_SOURCES
  src/BindingHandler.cpp
  src/DefaultAuth.cpp
  src/Handler.cpp
  src/Poll.cpp
  src/Router.cpp
  src/UpdateCalbacksHandler.cpp
)

add_library(${PROJECT_NAME} SHARED ${TDLPP_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include PUBLIC ${TDLPP_DEPS_INSTALL_PATH}/plog/include)
target_link_libraries(${PROJECT_NAME} PUBLIC Td::TdStatic)

if (MSVC)
  target_compile_definitions(${PROJECT_NAME} PRIVATE /bigobj)
else ()
  target_compile_definitions(${PROJECT_NAME} PRIVATE -Wa,-mbig-obj)
endif ()

###################################################################################################
## Samples

if (TDLPP_BUILD_SAMPLES)
  add_subdirectory(samples)
endif()

