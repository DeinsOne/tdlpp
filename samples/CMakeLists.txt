
add_executable(get-me-sample get-me/get-me.cpp)
target_link_libraries(get-me-sample PRIVATE ${CMAKE_PROJECT_NAME})
add_dependencies(get-me-sample ${CMAKE_PROJECT_NAME})


add_executable(top-chats-sample top-chats/top-chats.cpp)
target_link_libraries(top-chats-sample PRIVATE ${CMAKE_PROJECT_NAME})
add_dependencies(top-chats-sample ${CMAKE_PROJECT_NAME})
