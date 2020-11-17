project(${PROJECT_NAME}_traversal)

list(APPEND _SOURCES src/main.cpp
     src/Traversal.cpp
     src/include/Traversal.hpp
     src/include/Node.hpp)

add_executable(${PROJECT_NAME}
               ${_SOURCES}
               )

set(_TARGET ${PROJECT_NAME}_lib)

add_library(${_TARGET} ${_SOURCES})
target_include_directories(${_TARGET} INTERFACE ./src/include)

add_subdirectory(test)
