
find_package(Threads REQUIRED)


if (NOT OPENSSL_FOUND)
  find_package(OpenSSL REQUIRED)
endif()
message(STATUS "Found OpenSSL: ${OPENSSL_INCLUDE_DIR} ${OPENSSL_LIBRARIES}")


if (NOT Td_FOUND)
  find_package(Td REQUIRED)
endif()
message(STATUS "Found Tdlib version ${Td_VERSION}")


if (NOT plog_FOUND)
  find_package(plog REQUIRED)
endif()
