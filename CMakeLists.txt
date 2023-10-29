cmake_minimum_required(VERSION 3.10)
project(maze-IA)

include_directories(include/maze)
file(GLOB maze_source_files src/maze/*.cpp)
add_library(maze ${maze_source_files})
target_include_directories(maze PUBLIC ${PROJECT_SOURCE_DIR}/include)

include_directories(include/tree)
file(GLOB tree_source_files src/tree/*.cpp)  # Correção na definição de source_files
add_library(tree ${tree_source_files})  # Correção na definição do nome da biblioteca
target_include_directories(tree PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main maze)
target_link_libraries(main tree)
