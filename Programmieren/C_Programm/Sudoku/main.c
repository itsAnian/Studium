#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "userinput.h"
#include "generation.h"

//defines the Matrix + its copy
int matrix[9][9] = {0};
int copy [9][9] = {0};

//asks the User to put a
void AskName(char name[30]) {
    //asks for name
    printf("Who is playing right now?\n");
    scanf("%29s", name);
}

//generates the Sudoku field
//requests userinput for playing in a while loop
int main() {
    bool validation = true;
    double time_spent = 0.0;
    clock_t begin = clock();
    srand(time(NULL));
    char name [30];
    bool playing = true;
    AskName(name);
    GenerateField(matrix);
    DeleteNumbers(copy, matrix);
    while (playing){
        PrintSudokuField(name, matrix);
        Input(name, copy, matrix, &playing, &validation);
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);

}