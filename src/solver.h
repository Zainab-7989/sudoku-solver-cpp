#ifndef SOLVER_H
#define SOLVER_H

#include "sudoku.h"
#include <vector>

class Solver {
public:
    static bool solveSudoku(Sudoku& sudoku);
    
private:
    static bool backtrack(Sudoku& sudoku);
};

#endif