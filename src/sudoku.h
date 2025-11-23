#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Sudoku {
private:
    vector<vector<int>>grid;
    static const int SIZE = 9;

public:
    static const int EMPTY = 0;  // MOVE TO PUBLIC and make it static const

    Sudoku();
    Sudoku(const vector<vector<int>>& initialGrid);
    
    bool solve();
    void display() const;
    bool isValid() const;
    
    bool isEmpty(int row, int col) const;
    vector<int> getPossibleNumbers(int row, int col) const;
    void setCell(int row, int col, int value);
    int getCell(int row, int col) const;
    int getSize() const { return SIZE; }
    
    bool loadFromFile(const string& filename);
    bool saveToFile(const string& filename) const;

    bool findEmptyCell(int& row, int& col) const;
    bool isValidPlacement(int row, int col, int num) const;

private:
    bool usedInRow(int row, int num) const;
    bool usedInCol(int col, int num) const;
    bool usedInBox(int boxStartRow, int boxStartCol, int num) const;
};

#endif