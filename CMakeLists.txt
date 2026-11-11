cmake_minimum_required(VERSION 3.16)

project(MatrixMultiplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cool
    src/matMul.cpp
    src/matrix_tool.cpp
    src/naive_matMul.cpp
)

target_include_directories(cool PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)