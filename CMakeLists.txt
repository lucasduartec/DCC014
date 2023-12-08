cmake_minimum_required(VERSION 3.10)
project(maze)

include_directories(include/maze)
include_directories(include/tree)
include_directories(include/perf)

add_executable(main main.cpp)

target_include_directories(main PRIVATE include/maze include/tree)
