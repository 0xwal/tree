project(${PROJECT_NAME}_demo C)

list(APPEND _DEMOS bst)

foreach (demo ${_DEMOS})
    add_executable(${PROJECT_NAME}_${demo} ${demo}.c)
    target_link_libraries(${PROJECT_NAME}_${demo} PRIVATE ${CMAKE_PROJECT_NAME})
endforeach ()
