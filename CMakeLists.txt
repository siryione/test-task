cmake_minimum_required(VERSION 3.10)

project(test-task)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src/child)
add_subdirectory(src/parent)
