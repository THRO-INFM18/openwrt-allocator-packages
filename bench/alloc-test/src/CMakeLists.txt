cmake_minimum_required(VERSION 3.0)
project(alloc-test CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(sources_files
    test_common.cpp
    allocator_tester.cpp
)

add_executable(alloc-test ${sources_files})
target_compile_definitions(alloc-test PRIVATE BENCH=4)
target_link_libraries(alloc-test pthread)

INSTALL(TARGETS alloc-test RUNTIME DESTINATION /usr/local/bin/)
