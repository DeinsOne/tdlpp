
add_executable(binding_generator src/generator.cpp)

find_package(Filesystem REQUIRED)
find_package(Td REQUIRED)

target_link_libraries(binding_generator PRIVATE std::filesystem)
target_compile_definitions(binding_generator
  PRIVATE -DCXX_FILESYSTEM_IS_EXPERIMENTAL=${CXX_FILESYSTEM_IS_EXPERIMENTAL}
)

## Generate bindings header here
set(TDLPP_BINDING_HEADER ${CMAKE_BINARY_DIR}/TdlppIdNameBinding.hpp)
set(TD_API_HEADER ${Td_DIR}/../../../include/td/telegram/td_api.h)

add_custom_command(
  OUTPUT ${TDLPP_BINDING_HEADER}
  COMMAND $<TARGET_FILE:binding_generator> ${TD_API_HEADER} ${TDLPP_BINDING_HEADER}
  VERBATIM
)

add_custom_target(
  binding_generator_header ALL
  DEPENDS ${TDLPP_BINDING_HEADER}
)
