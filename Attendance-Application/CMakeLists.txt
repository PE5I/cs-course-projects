cmake_minimum_required(VERSION 3.16)

project(cpts_223_assignment_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

add_executable(attendance_app main.cpp List.cpp ListNode.cpp menu.cpp pa7.cpp)