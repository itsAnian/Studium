#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "validation.h"
#include "userinput.h"
#include "generation.h"

int Matrix[9][9] = {0};
int copy [9][9] = {0};

void AskName(char Name[30]) {
    //asks for name
    printf("Who is playing right now?\n");
    scanf("%29s", Name);
}

int main() {
    double time_spent = 0.0;
    clock_t begin = clock();
    srand(time(NULL));
    char name [30];
    bool playing = true;
    //AskName(Name);
    GenerateField(Matrix);
    DeleteNumbers(copy, Matrix);
    while (playing){
        PrintSudokuField(name, Matrix);
        Input(name, copy, Matrix, &playing);
        //playing = false;
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);

}