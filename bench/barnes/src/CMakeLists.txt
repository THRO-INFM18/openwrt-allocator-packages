cmake_minimum_required(VERSION 3.0)
project(barnes CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(sources_files
    code.c
    code_io.c
    load.c
    grav.c
    getparam.c
    util.c
)

add_executable(barnes ${sources_files})
target_link_libraries(barnes m)

INSTALL(TARGETS barnes RUNTIME DESTINATION /usr/local/bin/)
