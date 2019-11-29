cmake_minimum_required(VERSION 3.0)
project(cache-scratch CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(sources_files
    cache-scratch.cpp
)

add_executable(cache-scratch ${sources_files})
target_link_libraries(cache-scratch pthread)

INSTALL(TARGETS cache-scratch RUNTIME DESTINATION /usr/bin/)
