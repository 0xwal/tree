project(${PROJECT_NAME}_test)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

add_executable(${PROJECT_NAME}
               main.cpp
               Node.test.cpp
               BinarySearchTree.test.cpp
               )

target_link_libraries(${PROJECT_NAME} Catch2::Catch2)
target_link_libraries(${PROJECT_NAME} ${_TARGET})
