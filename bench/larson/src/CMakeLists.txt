cmake_minimum_required(VERSION 3.0)
project(larson CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(sources_files
    larson.cpp
)

add_executable(larson ${sources_files})
target_compile_options(larson PRIVATE -Wno-unused-result)
target_compile_definitions(larson PRIVATE CPP=1)
target_link_libraries(larson pthread)

INSTALL(TARGETS larson RUNTIME DESTINATION /usr/bin/)
