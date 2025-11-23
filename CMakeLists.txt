cmake_minimum_required(VERSION 3.10)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add main executable
add_executable(sudoku_solver 
    src/main.cpp 
    src/sudoku.cpp 
    src/solver.cpp
)

# Include directories
target_include_directories(sudoku_solver PRIVATE src)

# Compiler options
if(MSVC)
    target_compile_options(sudoku_solver PRIVATE /W4)
else()
    target_compile_options(sudoku_solver PRIVATE -Wall -Wextra -pedantic)
endif()

# Add tests if needed
add_executable(test_sudoku tests/test_sudoku.cpp src/sudoku.cpp src/solver.cpp)
target_include_directories(test_sudoku PRIVATE src)