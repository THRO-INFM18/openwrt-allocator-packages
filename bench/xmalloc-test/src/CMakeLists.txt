cmake_minimum_required(VERSION 3.0)
project(xmalloc-test CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(sources_files
    xmalloc-test.c
)

add_executable(xmalloc-test ${sources_files})
target_link_libraries(xmalloc-test pthread)

INSTALL(TARGETS xmalloc-test RUNTIME DESTINATION /usr/bin/)
