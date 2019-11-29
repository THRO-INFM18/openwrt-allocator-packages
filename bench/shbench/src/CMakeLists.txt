cmake_minimum_required(VERSION 3.0)
project(shbench CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(sh6bench sh6bench-new.c)
target_compile_definitions(sh6bench PRIVATE BENCH=1 SYS_MULTI_THREAD=1)
target_link_libraries(sh6bench pthread)

INSTALL(TARGETS sh6bench RUNTIME DESTINATION /usr/bin/)

add_executable(sh8bench sh8bench-new.c)
target_compile_definitions(sh8bench PRIVATE BENCH=1 SYS_MULTI_THREAD=1)
target_link_libraries(sh8bench pthread)

INSTALL(TARGETS sh8bench RUNTIME DESTINATION /usr/bin/)
