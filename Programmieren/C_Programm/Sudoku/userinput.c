#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "generation.h"
#include "validation.h"
#include "userinput.h"

void Input(char name[30], int copy[9][9], int array[9][9], bool* playing, bool* validation){
    int instruction = 0;
    printf("Type [1: numinput] [2: check] [3: solution] [4: undo] [5: whole validation] [9:quit]\n");
    scanf("%d", &instruction);
    bool validationparameter = *validation;

    switch(instruction){
        case 1:
            SetNumber(array, &validationparameter);
            break;
        case 2:
            if (*validation == true){
                *validation = false;
            }else{
                *validation = true;
            }
            break;
        case 3:
            printf("This is one possible solution:\n");
            PrintSudokuField(name, copy);
            break;
        case 4:
            printf("undo");
            break;
        case 5:
            for (int i = 0; i < 9; ++i) {
                for (int ii = 0; ii < 9; ++ii) {
                    if (404 == IsValid(array, i, ii)){
                        if (array[i][ii] != 0){
                            printf("Invalid: Matrix[%d][%d] = %d\n", i, ii, array[i][ii]);
                            //work in progress (a1=6 i1=6), when you set a1 it says i1 cause its the one checked later
                        }
                    }
                }
            }
            break;
        case 9:
            *playing = false;
            break;
        default:
            printf("You inserted a num/char that does not do something.");
    }
}

void SetNumber(int array[9][9], bool*validation){
    char inputColumn;
    int inputRow;
    int inputNumber;

    printf("Switch a number in [column]:\n");
    scanf(" %c",&inputColumn);
    printf("Switch a number in [row]:\n");
    scanf(" %d", &inputRow);
    printf("Number you want to set [number]:\n");
    scanf(" %d", &inputNumber);
    /*
    printf("Switch a number [columnrow number]:\n");
    scanf(" %c%d%d",&inputColumn, &inputRow, &inputNumber);
     */
    if (9 < inputRow || 9 < inputNumber){
        printf("\nplease only input Numbers between 1-9");
    }
    switch(inputColumn){
        case 'a': case 'A':
            if (*validation == true){
                array[inputRow - 1][0] = inputNumber;
                if (404 == IsValid(array, inputRow-1, 0)){
                    printf("its not valid to put this number in here\n");
                    array[inputRow - 1][0] = 0;
                }
            }else{
                array[inputRow - 1][0] = inputNumber;
            }
            break;
        case 'b': case 'B':
            if (*validation == true){
                array[inputRow - 1][1] = inputNumber;
                if (404 == IsValid(array, inputRow-1, 1)){
                    printf("its not valid to put this number in here\n");
                    array[inputRow - 1][1] = 0;
                }
            }else{
                array[inputRow - 1][1] = inputNumber;
            }
            break;
        case 'c': case 'C':
            if (*validation == true){
                array[inputRow - 1][2] = inputNumber;
                if (404 == IsValid(array, inputRow-1, 2)){
                    printf("its not valid to put this number in here\n");
                    array[inputRow - 1][2] = 0;
                }
            }else{
                array[inputRow - 1][2] = inputNumber;
            }
            break;
        case 'd': case 'D':
            if (*validation == true){
                array[inputRow - 1][3] = inputNumber;
                if (404 == IsValid(array, inputRow-1, 3)){
                    printf("its not valid to put this number in here\n");
                    array[inputRow - 1][3] = 0;
                }
            }else{
                array[inputRow - 1][3] = inputNumber;
            }
            break;
        case 'e': case 'E':
            if (*validation == true){
                array[inputRow - 1][4] = inputNumber;
                if (404 == IsValid(array, inputRow-1, 4)){
                    printf("its not valid to put this number in here\n");
                    array[inputRow - 1][4] = 0;
                }
            }else{
                array[inputRow - 1][4] = inputNumber;
            }
            break;
        case 'f': case 'F':
            if (*validation == true){
                array[inputRow - 1][5] = inputNumber;
                if (404 == IsValid(array, inputRow-1, 5)){
                    printf("its not valid to put this number in here\n");
                    array[inputRow - 1][5] = 0;
                }
            }else{
                array[inputRow - 1][5] = inputNumber;
            }
            break;
        case 'g': case 'G':
            if (*validation == true){
                array[inputRow - 1][6] = inputNumber;
                if (404 == IsValid(array, inputRow-1, 6)){
                    printf("its not valid to put this number in here\n");
                    array[inputRow - 1][6] = 0;
                }
            }else{
                array[inputRow - 1][6] = inputNumber;
            }
            break;
        case 'h': case 'H':
            if (*validation == true){
                array[inputRow - 1][7] = inputNumber;
                if (404 == IsValid(array, inputRow-1, 7)){
                    printf("its not valid to put this number in here\n");
                    array[inputRow - 1][7] = 0;
                }
            }else{
                array[inputRow - 1][7] = inputNumber;
            }
            break;
        case 'i': case 'I':
            if (*validation == true){
                array[inputRow - 1][8] = inputNumber;
                if (404 == IsValid(array, inputRow-1, 8)){
                    printf("its not valid to put this number in here\n");
                    array[inputRow - 1][8] = 0;
                }
            }else{
                array[inputRow - 1][8] = inputNumber;
            }
            break;
        case 'q':
            printf("quit");
        default:
            printf("\nno row found, there are only the rows a-i");
    }
}