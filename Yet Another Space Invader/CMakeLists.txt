cmake_minimum_required(VERSION 3.16)

project(space-invaders)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)


file(GLOB_RECURSE src_code src/*.cpp)
include_directories(src/headers)



#find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

find_package(SFML 2.5.1 REQUIRED network audio graphics window system)

add_executable(yasi ${src_code})

target_link_libraries(yasi sfml-network sfml-audio sfml-graphics sfml-window sfml-system)

#target_link_libraries(yasi ${SFML_LIBRARIES})