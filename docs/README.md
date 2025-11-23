## 👨‍💻 Author

**Zainab**  *(Zainab Tariq)* 
- GitHub: [Zainab-7989](https://github.com/Zainab-7989)  
- LeetCode: [Zaini8899](https://leetcode.com/u/Zaini8899/)  
- Kaggle: [zaini789](https://www.kaggle.com/zaini789)  
- Project Dataset: [Sudoku Solver in C++ with LeetCode Solutions](https://www.kaggle.com/datasets/zaini789/sudoku-solver-in-c-with-leetcode-solutions)
- LinkedIn: *Coming Soon*

*Data Science Student | DSA Enthusiast | Problem Solver*

# 🎯 Sudoku Solver in C++ with My LeetCode Solutions

A high-performance Sudoku solver featuring **my actual LeetCode solutions** for both Sudoku problems!

## 🚀 Features

- **My LeetCode Sudoku Solver** (Hard Problem #37) - Integrated as main solver
- **My LeetCode Valid Sudoku** (Medium Problem #36) - Enhanced validation  
- 🎯 Two solving algorithms: Backtracking + My LeetCode implementation
- 📊 Performance comparison between solvers
- ✅ Comprehensive puzzle validation using my LeetCode solution
- 📁 File I/O support
- 🧪 Extensive test suite
- 🎨 Beautiful console display

## 🏆 My LeetCode Integration

This project incorporates **my actual solutions** to:
- **LeetCode 37 - Sudoku Solver (Hard)** - Complete backtracking implementation
- **LeetCode 36 - Valid Sudoku (Medium)** - Robust validation algorithm

The code includes my exact backtracking logic and validation algorithms that successfully passed all LeetCode test cases.

## 🛠️ Build & Run

```bash
# Compile
g++ -std=c++17 -I src src/main.cpp src/sudoku.cpp src/solver.cpp -o sudoku_solver

# Run
./sudoku_solver

# Run tests
g++ -std=c++17 -I src tests/test_sudoku.cpp src/sudoku.cpp src/solver.cpp -o test_sudoku && ./test_sudoku
g++ -std=c++17 -I src tests/test_solver.cpp src/sudoku.cpp src/solver.cpp -o test_solver && ./test_solver