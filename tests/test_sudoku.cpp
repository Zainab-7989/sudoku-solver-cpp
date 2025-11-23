#include <iostream>
#include <cassert>
#include "../src/sudoku.h"
#include "../src/solver.h"

using namespace std;

void testBasicFunctionality() {
    cout << "Testing basic functionality..." << endl;
    
    Sudoku sudoku;
    assert(sudoku.getCell(0, 0) == 0);
    
    sudoku.setCell(0, 0, 5);
    assert(sudoku.getCell(0, 0) == 5);
    
    cout << "Basic functionality tests passed!" << endl;
}

void testValidation() {
    cout << "Testing validation..." << endl;
    
    vector<vector<int>> validPuzzle = {
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
    
    Sudoku sudoku(validPuzzle);
    assert(sudoku.isValid());
    
    cout << "Validation tests passed!" << endl;
}

void testSolving() {
    cout << "Testing solving..." << endl;
    
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
    assert(sudoku.solve());
    assert(sudoku.isValid());
    
    cout << "Solving tests passed!" << endl;
}

int main() {
    cout << "Starting Sudoku Solver Tests..." << endl;
    cout << "=====================================" << endl;
    
    testBasicFunctionality();
    testValidation();
    testSolving();
    
    cout << "=====================================" << endl;
    cout << "ALL TESTS PASSED! My LeetCode integration works perfectly!" << endl;
    return 0;
}