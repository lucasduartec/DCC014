cmake_minimum_required(VERSION 3.10)
project(maze-IA)
include_directories(src)

add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main maze)
