#include <iostream>
#include <cassert>
#include "../src/sudoku.h"
#include "../src/solver.h"

using namespace std;

void testLeetCodeSolver() {
    cout << "Testing My LeetCode Solver..." << endl;
    
    // Test puzzle from LeetCode
    vector<vector<int>> puzzle = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    Sudoku sudoku(puzzle);
    bool solved = Solver::solveSudoku(sudoku);
    
    assert(solved);
    assert(sudoku.isValid());
    
    cout << "My LeetCode Solver test passed!" << endl;
    cout << "My Hard problem solution is working in the project!" << endl;
}

int main() {
    cout << "Testing Solver Implementations..." << endl;
    cout << "=====================================" << endl;
    
    testLeetCodeSolver();
    
    cout << "=====================================" << endl;
    cout << "All solver tests completed successfully!" << endl;
    return 0;
}