cmake_minimum_required(VERSION 3.15)

project(tree CXX)

set(CMAKE_CXX_STANDARD 17)

list(APPEND _SOURCES
     src/include/Node.hpp
     src/Node.cpp
     src/include/BinarySearchTree.hpp
     src/BinarySearchTree.cpp)

add_executable(${PROJECT_NAME}
               src/main.cpp
               ${_SOURCES}
               )

set(_TARGET ${PROJECT_NAME}_lib)

add_library(${_TARGET} ${_SOURCES})

target_include_directories(${_TARGET} PUBLIC src/include)

add_subdirectory(test)
