cmake_minimum_required(VERSION 3.17)
project(tree C)

set(CMAKE_C_STANDARD 11)

list(APPEND _SOURCES
     src/include/node.h
     src/node.c
     src/include/traversal.h
     src/traversal.c
     src/include/binary-search-tree.h
     src/binary-search-tree.c
     src/include/clist.h
     src/clist.c)


add_executable(${PROJECT_NAME}_traversal src/main.c ${_SOURCES})

set(_TARGET_LIB ${PROJECT_NAME}_lib)

add_library(${_TARGET_LIB} ${_SOURCES})

target_include_directories(${_TARGET_LIB} PUBLIC src/include)

add_subdirectory(tests)
