
project(${PROJECT_NAME}_demo )

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${CMAKE_PROJECT_NAME})
