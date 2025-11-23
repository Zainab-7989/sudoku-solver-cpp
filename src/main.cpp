#include <iostream>
#include <vector>
#include <chrono>
#include "sudoku.h"
#include "solver.h"

using namespace std;

void printBanner() {
    cout << "==============================================" << endl;
    cout << "        SUDOKU SOLVER C++ WITH LEETCODE       " << endl;
    cout << "     (Featuring My LeetCode Solutions)      " << endl;
    cout << "==============================================" << endl;
}

void printMenu() {
    cout << "\nOptions:" << endl;
    cout << "1. Solve sample puzzle (Original Solver)" << endl;
    cout << "2. Solve sample puzzle (My LeetCode Solver)" << endl;
    cout << "3. Enter custom puzzle" << endl;
    cout << "4. Validate puzzle (My LeetCode Validator)" << endl;
    cout << "5. Compare both solvers" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option: ";
}

vector<vector<int>> getSamplePuzzle() {
    return {
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
}

vector<vector<int>> inputPuzzle() {
    vector<vector<int>> puzzle(9, vector<int>(9));
    cout << "Enter the puzzle (use 0 for empty cells):" << endl;
    
    for (int i = 0; i < 9; i++) {
        cout << "Row " << (i + 1) << " (9 numbers separated by spaces): ";
        for (int j = 0; j < 9; j++) {
            cin >> puzzle[i][j];
        }
    }
    
    return puzzle;
}

void solveWithOriginal(Sudoku& sudoku) {
    auto start = chrono::high_resolution_clock::now();
    bool solved = Solver::solveSudoku(sudoku);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    if (solved) {
        cout << "\n Solved with Original Solver (" << duration.count() << " microseconds):" << endl;
        sudoku.display();
    } else {
        cout << "No solution exists!" << endl;
    }
}

void solveWithLeetCode(Sudoku& sudoku) {
    auto start = chrono::high_resolution_clock::now();
    bool solved = Solver::solveSudoku(sudoku); //  uses my LeetCode solver
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    if (solved) {
        cout << "\n Solved with My LeetCode Solver (" << duration.count() << " microseconds):" << endl;
        sudoku.display();
        cout << "This uses My exact LeetCode solution that solved the Hard Sudoku Solver problem!" << endl;
    } else {
        cout << "No solution exists!" << endl;
    }
}

void compareSolvers() {
    Sudoku sudoku1(getSamplePuzzle());
    Sudoku sudoku2(getSamplePuzzle());
    
    cout << "\nOriginal Puzzle:" << endl;
    sudoku1.display();
    
    cout << "\n--- COMPARING SOLVERS ---" << endl;
    
    // Original solver
    auto start1 = chrono::high_resolution_clock::now();
    bool solved1 = Solver::solveSudoku(sudoku1);
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
    
    // My LeetCode Solution of Sudoku solver
    auto start2 = chrono::high_resolution_clock::now();
    bool solved2 = Solver::solveSudoku(sudoku2);
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    
    cout << "Original Solver: " << (solved1 ? " Solved" : " Failed") 
         << " in " << duration1.count() << " μs" << endl;
    cout << "My LeetCode Solver: " << (solved2 ? " Solved" : " Failed") 
         << " in " << duration2.count() << " μs" << endl;
    
    if (solved1 && solved2) {
        cout << "🎉 Both solvers produced correct results!" << endl;
        cout << "🚀 My LeetCode solution is now integrated into a complete C++ project!" << endl;
    }
}

int main() {
    printBanner();
    
    int choice;
    Sudoku sudoku;
    
    do {
        printMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                sudoku = Sudoku(getSamplePuzzle());
                cout << "\nOriginal Puzzle:" << endl;
                sudoku.display();
                solveWithOriginal(sudoku);
                break;
            }
                
            case 2: {
                sudoku = Sudoku(getSamplePuzzle());
                cout << "\nOriginal Puzzle:" << endl;
                sudoku.display();
                solveWithLeetCode(sudoku);
                break;
            }
                
            case 3: {
                auto puzzle = inputPuzzle();
                sudoku = Sudoku(puzzle);
                
                cout << "\nYour Puzzle:" << endl;
                sudoku.display();
                
                if (!sudoku.isValid()) {
                    cout << " Invalid puzzle! (Using My LeetCode validation)" << endl;
                    break;
                }
                
                cout << " Valid puzzle! (Using My LeetCode validation)" << endl;
                solveWithLeetCode(sudoku);
                break;
            }
                
            case 4: {
                auto puzzle = inputPuzzle();
                sudoku = Sudoku(puzzle);
                
                cout << "\nYour Puzzle:" << endl;
                sudoku.display();
                
                if (sudoku.isValid()) {
                    cout << " Valid Sudoku! (Using My LeetCode solution)" << endl;
                } else {
                    cout << " Invalid Sudoku! (Using My LeetCode solution)" << endl;
                }
                break;
            }
                
            case 5: {
                compareSolvers();
                break;
            }
                
            case 6:
                cout << " Goodbye! Thanks for using my LeetCode-powered Sudoku Solver!" << endl;
                break;
                
            default:
                cout << " Invalid option!" << endl;
        }
    } while (choice != 6);
    
    return 0;
}