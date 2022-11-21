cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(tdlpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_THREAD_PREFER_PTHREAD ON)

option(TDLPP_BUILD_SAMPLES "Build tdl++ samples" ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/find
)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

##################################################################################################################
## Resolve dependencies 

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/dependencies.cmake)
message(${CMAKE_CURRENT_SOURCE_DIR}/cmake/dependencies.cmake)


# Generate bindings header
add_subdirectory(binding)


##################################################################################################################
## Build library

add_library(${CMAKE_PROJECT_NAME}
  tdlpp/tdlpp.hpp
  tdlpp/auth/DefaultAuth.cpp
  tdlpp/router/Router.cpp
  tdlpp/poll/LongPoll.cpp
  tdlpp/base/Handler.cpp
  tdlpp/base/UpdateCalbacksHandler.cpp
  ${TDLPP_BINDING_HEADER}
)

add_dependencies(${CMAKE_PROJECT_NAME} binding_generator binding_generator_header)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR} ./)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC Td::TdStatic plog::plog)


##################################################################################################################
## Build samples

if (TDLPP_BUILD_SAMPLES)
  add_subdirectory(samples)
endif()
