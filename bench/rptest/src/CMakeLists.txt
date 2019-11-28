cmake_minimum_required(VERSION 3.0)
project(rptest CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(sources_files
    rptest.c
    thread.c
    timer.c
)

add_executable(rptest ${sources_files})
target_compile_options(rptest PRIVATE -fpermissive)
target_link_libraries(rptest pthread m)

INSTALL(TARGETS rptest RUNTIME DESTINATION /usr/local/bin/)
