#include "sudoku.h"
#include "solver.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

using namespace std;

//static constants
const int Sudoku::SIZE;
const int Sudoku::EMPTY;

Sudoku::Sudoku() : grid(SIZE, vector<int>(SIZE, EMPTY)) {}

Sudoku::Sudoku(const vector<vector<int>>& initialGrid) {
    if (initialGrid.size() != SIZE || initialGrid[0].size() != SIZE) {
        throw invalid_argument("Invalid grid size");
    }
    grid = initialGrid;
}

bool Sudoku::solve() {
    return Solver::solveSudoku(*this);
}

void Sudoku::display() const {
    cout << "┌─────────┬─────────┬─────────┐" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (i == 3 || i == 6) {
            cout << "├─────────┼─────────┼─────────┤" << endl;
        }
        cout << "│ ";
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == EMPTY) {
                cout << ". ";
            } else {
                cout << grid[i][j] << " ";
            }
            if (j == 2 || j == 5) {
                cout << "│ ";
            }
        }
        cout << "│" << endl;
    }
    cout << "└─────────┴─────────┴─────────┘" << endl;
}

bool Sudoku::isValid() const {
    // MY LEETCODE ALGORITHM
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] != EMPTY) {
                // Horizontal
                for (int col = 0; col < SIZE; col++) {
                    if (col != j && grid[i][col] == grid[i][j]) return false;
                }
                // Vertical
                for (int row = 0; row < SIZE; row++) {
                    if (row != i && grid[row][j] == grid[i][j]) return false;
                }
                // Grid
                int srow = (i / 3) * 3;
                int scol = (j / 3) * 3;
                for (int r = srow; r <= srow + 2; r++) {
                    for (int c = scol; c <= scol + 2; c++) {
                        if ((r != i || c != j) && grid[r][c] == grid[i][j]) return false;
                    }
                }
            }
        }
    }
    return true;
}

bool Sudoku::isEmpty(int row, int col) const {
    return grid[row][col] == EMPTY;
}

vector<int> Sudoku::getPossibleNumbers(int row, int col) const {
    vector<int> possible;
    for (int num = 1; num <= 9; num++) {
        if (isValidPlacement(row, col, num)) {
            possible.push_back(num);
        }
    }
    return possible;
}

void Sudoku::setCell(int row, int col, int value) {
    grid[row][col] = value;
}

int Sudoku::getCell(int row, int col) const {
    return grid[row][col];
}

bool Sudoku::findEmptyCell(int& row, int& col) const {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == EMPTY) return true;
        }
    }
    return false;
}

bool Sudoku::isValidPlacement(int row, int col, int num) const {
    return !usedInRow(row, num) && !usedInCol(col, num) && !usedInBox(row - row % 3, col - col % 3, num);
}

bool Sudoku::usedInRow(int row, int num) const {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num) return true;
    }
    return false;
}

bool Sudoku::usedInCol(int col, int num) const {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num) return true;
    }
    return false;
}

bool Sudoku::usedInBox(int boxStartRow, int boxStartCol, int num) const {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) return true;
        }
    }
    return false;
}

bool Sudoku::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return false;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!(file >> grid[i][j])) return false;
        }
    }
    return true;
}

bool Sudoku::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) return false;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            file << grid[i][j] << " ";
        }
        file << endl;
    }
    return true;
}