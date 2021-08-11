cmake_minimum_required(VERSION 3.16)

project(fitness-application)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)


file(GLOB_RECURSE src_code src/*.cpp)
include_directories(src/headers)


add_executable(fitness_app ${src_code})