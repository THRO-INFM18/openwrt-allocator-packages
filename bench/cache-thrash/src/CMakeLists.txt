cmake_minimum_required(VERSION 3.0)
project(cache-thrash CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(sources_files
    cache-thrash.cpp
)

add_executable(cache-thrash ${sources_files})
target_link_libraries(cache-thrash pthread)

INSTALL(TARGETS cache-thrash RUNTIME DESTINATION /usr/bin/)
