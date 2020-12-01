cmake_minimum_required(VERSION 3.17)
project(tree C)

set(CMAKE_C_STANDARD 11)

list(APPEND _SOURCES
     src/include/node.h
     src/node.c
     src/include/binary-search-tree.h
     src/binary-search-tree.c)


Include(FetchContent)

FetchContent_Declare(
        clist
        GIT_REPOSITORY https://github.com/BISOON/clist.git
)

FetchContent_MakeAvailable(clist)

add_executable(${PROJECT_NAME}_traversal src/main.c ${_SOURCES})
target_include_directories(${PROJECT_NAME}_traversal PRIVATE src/include)

set(_TARGET_LIB ${PROJECT_NAME}_lib)

add_library(${_TARGET_LIB} ${_SOURCES})

target_include_directories(${_TARGET_LIB} PUBLIC src/include)

target_link_libraries(${_TARGET_LIB} PUBLIC clist)

add_subdirectory(tests)
