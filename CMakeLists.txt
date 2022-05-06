cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(Tdlpp VERSION 0.1 LANGUAGES CXX)

if (NOT DEFINED CMAKE_INSTALL_LIBDIR)
  set(CMAKE_INSTALL_LIBDIR "lib")
endif()
if (NOT DEFINED CMAKE_INSTALL_BINDIR)
  set(CMAKE_INSTALL_BINDIR "bin")
endif()
if (NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
  set(CMAKE_INSTALL_INCLUDEDIR "include")
endif()

option(TDLPP_BUILD_SAMPLES "Build tdl++ samples" OFF)

include(ExternalProject)

if (NOT OPENSSL_FOUND)
  find_package(OpenSSL)
  message(STATUS "Found OpenSSL: ${OPENSSL_INCLUDE_DIR} ${OPENSSL_LIBRARIES}")
endif()
if (NOT OPENSSL_FOUND AND MSVC)
  ExternalProject_Add(openssl
    GIT_REPOSITORY https://github.com/janbar/openssl-cmake.git
    GIT_PROGRESS On
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/openssl
  )
  set(OPENSSL_FOUND True)
  set(OPENSSL_INCLUDE_DIR "${CMAKE_BINARY_DIR}/openssl/include")
  set(OPENSSL_CRYPTO_LIBRARY "${CMAKE_BINARY_DIR}/openssl/lib/libcrypto.a")
  set(OPENSSL_LIBRARIES "${CMAKE_BINARY_DIR}/openssl/lib/libssl.a" )
elseif(NOT OPENSSL_FOUND)
  message(FATAL_ERROR "Could not find openssl library: stop building")
endif()

if (NOT Td_FOUND)
  find_package(Td 1.8.2 REQUIRED)
endif()
if (NOT Td_FOUND)
  message(STATUS "Could NOT find Tdlib (this is NOT an error)")

  ExternalProject_Add(td
    GIT_REPOSITORY https://github.com/tdlib/td.git
    GIT_PROGRESS On
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/td
  )
  find_package(Td 1.8.2 REQUIRED PATH ${CMAKE_BINARY_DIR}/td/lib/cmake/Td NO_DEFAULT_PATH)
else()
  message(STATUS "Found Tdlib version ${Td_VERSION}")
endif()


set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)

add_library(${CMAKE_PROJECT_NAME}
  src/DefaultAuth.cpp
  src/Router.cpp
  src/Poll.cpp
  src/Handler.cpp
  src/UpdateCalbacksHandler.cpp
  src/BindingHandler.cpp
)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src include)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC Td::TdStatic)


set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
  CXX_STANDARD 14
  CXX_EXTENSIONS OFF
  CXX_STANDARD_REQUIRED ON
)


if (TDLPP_BUILD_SAMPLES)
  add_executable(get-me-sample samples/get-me/get-me.cpp)
  target_link_libraries(get-me-sample PRIVATE ${CMAKE_PROJECT_NAME} PRIVATE Td::TdStatic)
  add_dependencies(get-me-sample ${CMAKE_PROJECT_NAME})

  add_executable(top-chats-sample samples/top-chats/top-chats.cpp)
  target_link_libraries(top-chats-sample PRIVATE ${CMAKE_PROJECT_NAME} PRIVATE Td::TdStatic)
  add_dependencies(top-chats-sample ${CMAKE_PROJECT_NAME})
endif()