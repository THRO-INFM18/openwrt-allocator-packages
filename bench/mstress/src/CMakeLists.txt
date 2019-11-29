cmake_minimum_required(VERSION 3.0)
project(mstress CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(sources_files
    mstress.c
)

add_executable(mstress ${sources_files})
target_link_libraries(mstress pthread)

INSTALL(TARGETS mstress RUNTIME DESTINATION /usr/bin/)
