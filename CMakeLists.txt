cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(tdlpp LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(TDLPP_BUILD_SAMPLES "Build tdl++ samples" OFF)
# option(TDLPP_INSTALL "Create installation target for tdl++" ON)


include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

# ExternalProject_Add(td
    # GIT_REPOSITORY https://github.com/tdlib/td.git
    # CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
# )

set(CMAKE_THREAD_PREFER_PTHREAD ON)

find_package(Threads REQUIRED)
find_package(Td 1.8.2 REQUIRED)

add_compile_definitions(
    TDLPP_ENABLE_CONSOLE_LOGGING
    TDLPP_ENABLE_OBJECT_LOGGING
    TDLPP_FILE_LOGGING_LEVEL=5
)

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

