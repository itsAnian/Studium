#ifndef SUDOKU_VALIDATION_H
#define SUDOKU_VALIDATION_H

void DebugArray(int array[9]);
int CheckColumn(int array[9][9], int x, int y);
int CheckRow(int array[9][9], int x, int y);
int CheckBox( int array[9][9], int x, int y);
int IsValid(int array[9][9], int x, int y);
#endif //SUDOKU_VALIDATION_H
