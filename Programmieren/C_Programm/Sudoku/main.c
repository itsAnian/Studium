#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "validation.c"
#include "userinput.c"

int Matrix[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0},
};


int operationCounter = 0;

int RandomNumbers() {
    int f = 0;
    for (int i = 0; i < 9; i++) {
        for (int ii = 0; ii < 9; ii++) {
            Matrix[i][ii] = rand() % 9 + 1;
            operationCounter += 1;
            while (404 == IsValid(Matrix, i, ii)) {
                f = f+1;
                operationCounter += 1;
                Matrix[i][ii] = rand() % 9 + 1;
                if (f > 100){
                    f = 0;
                    for (int j = 0; j <= i; j++) {
                        for (int jj = 0; jj < 9; jj++) {
                            operationCounter += 1;
                            Matrix[j][jj] = 0;
                        }
                    }
                    return 0;
                }
            }
            f = 0;
        }
    }
    return 1;
}

void AskName(char Name[30]) {
    //asks for name
    printf("Who is playing right now?\n");
    scanf("%29s", Name);
}

void GenerateField(){
    int f = 0;
    while (0 == RandomNumbers()) {
        f +=1;
        RandomNumbers();
    }
    printf("Operationcounter: %d\n", operationCounter);
    printf("try: %d\n", f);
}

void PrintSudokuField(char Name[30]){
    //defines everything
    int whichRow = 0;
    char column [] = "  abc def ghi";
    char *borderBottomTop ="  ––– ––– –––\n";
    int rowNumber[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char *row = "|";

    //prints everything out
    printf("%s is playing\n\n", Name);
    printf("%s", column);

    printf("\n");
    for (int i=0; i < 3; i++){
        printf("%s", borderBottomTop);
        for (int k=0; k < 3; k++) {
            printf("%d%s",rowNumber[whichRow], row);
            for (int j = 0; j < 9; j++){
                printf("%d", Matrix[whichRow][j]);
                if(2 == j || 5 == j || 8 == j){
                    printf("%s", row);
                }
            }
            printf("\n");
            whichRow += 1;
        }
    }
    printf("%s", borderBottomTop);
}

int main() {
    double time_spent = 0.0;
    clock_t begin = clock();
    srand(time(NULL));
    char Name [30];
    bool playing = true;
    //AskName(Name);
    GenerateField();
    while (playing){
        PrintSudokuField(Name);
        //Input();
        playing = false;
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);

}