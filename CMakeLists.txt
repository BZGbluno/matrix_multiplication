
cmake_minimum_required(VERSION 3.16)

project(MatrixMultiplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Shared matrix multiplication implementation
add_library(matrix_lib
    src/matrix_tool.cpp
    src/naive_matMul.cpp
    src/loopReordering.cpp
    src/flattenedMatMul.cpp
)

target_include_directories(matrix_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Main benchmark executable
add_executable(cool
    src/main.cpp
)

target_link_libraries(cool PRIVATE matrix_lib)

# GoogleTest executable
add_executable(matMulTests
    tests/test_matmul.cpp
    tests/test_loop_reordering.cpp
    tests/test_tool.cpp
)

target_link_libraries(matMulTests PRIVATE
    matrix_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(matMulTests)
