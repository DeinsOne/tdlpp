
add_executable(get-me-sample get-me/get-me.cpp)
target_link_libraries(get-me-sample PRIVATE ${CMAKE_PROJECT_NAME} PRIVATE Td::TdStatic)
add_dependencies(get-me-sample ${CMAKE_PROJECT_NAME})


add_executable(top-chats-sample top-chats/top-chats.cpp)
target_link_libraries(top-chats-sample PRIVATE ${CMAKE_PROJECT_NAME} PRIVATE Td::TdStatic)
add_dependencies(top-chats-sample ${CMAKE_PROJECT_NAME})


add_executable(infinite-sample infinite/infinite.cpp)
target_link_libraries(infinite-sample PRIVATE ${CMAKE_PROJECT_NAME} PRIVATE Td::TdStatic)
add_dependencies(infinite-sample ${CMAKE_PROJECT_NAME})
