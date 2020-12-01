set(CMAKE_C_STANDARD 11)

list(APPEND _SOURCES
     include/node.h
     node.c
     include/binary-search-tree.h
     binary-search-tree.c)


Include(FetchContent)

FetchContent_Declare(
        clist
        GIT_REPOSITORY https://github.com/BISOON/clist.git
)

FetchContent_MakeAvailable(clist)

add_library(${PROJECT_NAME} ${_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PUBLIC clist)
