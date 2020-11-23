
list(APPEND _SOURCES
     include/Node.hpp
     Node.cpp
     include/BinarySearchTree.hpp
     BinarySearchTree.cpp)


add_library(${PROJECT_NAME} ${_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
