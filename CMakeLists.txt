cmake_minimum_required(VERSION 3.10)
project(maze-IA)

include_directories(include/maze)
file(GLOB source_files src/maze/*.cpp)
add_library(maze ${source_files})
target_include_directories(maze PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main maze)
