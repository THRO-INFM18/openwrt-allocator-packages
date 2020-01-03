cmake_minimum_required(VERSION 3.0)
project(malloc-test CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(sources_files
    malloc-test.c
)

add_executable(malloc-test ${sources_files})
target_link_libraries(malloc-test pthread)

INSTALL(TARGETS malloc-test RUNTIME DESTINATION /usr/bin/)
