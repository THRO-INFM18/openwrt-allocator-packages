cmake_minimum_required(VERSION 3.0)
project(malloc-large CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(sources_files
    malloc-large.cpp
)

add_executable(malloc-large ${sources_files})
target_link_libraries(malloc-large pthread)

INSTALL(TARGETS malloc-large RUNTIME DESTINATION /usr/local/bin/)
