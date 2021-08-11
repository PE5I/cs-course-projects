cmake_minimum_required(VERSION 3.16)

project(connect_four)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)


file(GLOB_RECURSE src_code src/*.c)
include_directories(src/headers)

add_executable(connect-4 ${src_code})