#include "solver.h"
#include <vector>
#include <iostream>

using namespace std;

// My LEETCODE SUDOKU SOLVER ALGORITHM
bool leetCodeSolver(vector<vector<char>>& board, int row, int col) {
    if (row == 9) return true;
     
    int nextrow = row, nextcol = col + 1;
    if (nextcol == 9) {
        nextrow = row + 1;
        nextcol = 0;
    }
    
    if (board[row][col] != '.') {
        return leetCodeSolver(board, nextrow, nextcol);
    }
    
    for (char dig = '1'; dig <= '9'; dig++) {
        bool safe = true;
        
        // horizontal
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig) safe = false;
        }
        // vertical
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) safe = false;
        }
        // grid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for (int i = srow; i <= srow + 2; i++) {
            for (int j = scol; j <= scol + 2; j++) {
                if (board[i][j] == dig) safe = false;
            }
        }
        
        if (safe) {
            board[row][col] = dig;
            if (leetCodeSolver(board, nextrow, nextcol)) {
                return true;
            }
            board[row][col] = '.';  // BACKTRACK
        }
    }
    return false;
}

bool Solver::solveSudoku(Sudoku& sudoku) {
    // Convert to LeetCode format
    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int val = sudoku.getCell(i, j);
            board[i][j] = (val == 0) ? '.' : static_cast<char>('0' + val);
        }
    }
    
    //using My LeetCode algorithm
    bool solved = leetCodeSolver(board, 0, 0);
    
    // Convert back
    if (solved) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sudoku.setCell(i, j, (board[i][j] == '.') ? 0 : board[i][j] - '0');
            }
        }
    }
    
    return solved;
}

bool Solver::backtrack(Sudoku& sudoku) {
    return solveSudoku(sudoku); // Use my LeetCode solver
}