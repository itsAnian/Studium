#ifndef SUDOKU_GENERATION_H
#define SUDOKU_GENERATION_H

int RandomNumbers(int array[9][9]);
void GenerateField(int array[9][9]);
void PrintSudokuField(char name[30], int array[9][9]);
void DeleteNumbers(int copy[9][9], int array[9][9]);

#endif //SUDOKU_GENERATION_H
