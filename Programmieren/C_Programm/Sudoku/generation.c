#include "generation.h"
#include <stdlib.h>
#include <stdio.h>
#include "validation.h"

int operationCounter = 0;

int RandomNumbers(int array[9][9]) {
    int f = 0;
    for (int i = 0; i < 9; i++) {
        for (int ii = 0; ii < 9; ii++) {
            array[i][ii] = rand() % 9 + 1;
            operationCounter += 1;
            while (404 == IsValid(array, i, ii)) {
                f = f+1;
                operationCounter += 1;
                array[i][ii] = rand() % 9 + 1;
                if (f > 100){
                    f = 0;
                    for (int j = 0; j <= i; j++) {
                        for (int jj = 0; jj < 9; jj++) {
                            operationCounter += 1;
                            array[j][jj] = 0;
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

void GenerateField(int array[9][9]){
    int f = 0;
    while (0 == RandomNumbers(array)) {
        f +=1;
        RandomNumbers(array);
    }
    printf("Operationcounter: %d\n", operationCounter);
    printf("try: %d\n", f);
}

void PrintSudokuField(char name[30], int array[9][9]){
    //defines everything
    int whichRow = 0;
    char column [] = "  abc def ghi";
    char *borderBottomTop ="  ––– ––– –––\n";
    int rowNumber[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char *row = "|";

    //prints everything out
    printf("%s is playing\n\n", name);
    printf("%s", column);

    printf("\n");
    for (int i=0; i < 3; i++){
        printf("%s", borderBottomTop);
        for (int k=0; k < 3; k++) {
            printf("%d%s",rowNumber[whichRow], row);
            for (int j = 0; j < 9; j++){
                printf("%d", array[whichRow][j]);
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

void DeleteNumbers(int copy[9][9], int array[9][9]){
    for (int i = 0; i < 9; ++i) {
        for (int ii = 0; ii < 9; ++ii) {
            copy[i][ii] = array[i][ii];
        }
    }
    int numbersToDelete = 81-(17+(rand()%19)+1);
    printf("Visible Nums: %d", 81-numbersToDelete);
    int row;
    int col;
    while(numbersToDelete != 0){
        row = rand()%9;
        col = rand()%9;
        if (array[row][col] != 0){
            array[row][col] = 0;
            numbersToDelete--;
        }else{
            continue;
        }
    }
}
