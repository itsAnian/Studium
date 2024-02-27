#include <stdio.h>
#include <string.h>

static void Input(){
    char instruction [8];
    printf("[undo] [check] [quit] [solution] [numinput]\n");
    scanf("%7s\n", instruction);
    if (strcmp ("undo", instruction) == 0){
        printf("undo");
    }
    if (strcmp ("check", instruction) == 0){
        printf("validation");
    }
    if (strcmp ("quit", instruction) == 0){
        printf("quit");
    }
    if (strcmp ("solution", instruction) == 0){
        printf("solution");
    }
    if (strcmp ("numinput", instruction) == 0){
        printf("numberinput");
    }
}

static void SetNumber(int array[9][9]){
    char inputColumn;
    int inputRow;
    int inputNumber;
    printf("Switch a number [columnrow number]:\n");
    scanf(" %c%d%d",&inputColumn, &inputRow, &inputNumber);
    if (9 < inputRow || 9 < inputNumber){
        printf("\nplease only input Numbers between 1-9");
    }
    switch(inputColumn){
        case 'a': case 'A':
            array[inputRow - 1][0] = inputNumber;
            break;
        case 'b': case 'B':
            array[inputRow - 1][1] = inputNumber;
            break;
        case 'c': case 'C':
            array[inputRow - 1][2] = inputNumber;
            break;
        case 'd': case 'D':
            array[inputRow - 1][3] = inputNumber;
            break;
        case 'e': case 'E':
            array[inputRow - 1][4] = inputNumber;
            break;
        case 'f': case 'F':
            array[inputRow - 1][5] = inputNumber;
            break;
        case 'g': case 'G':
            array[inputRow - 1][6] = inputNumber;
            break;
        case 'h': case 'H':
            array[inputRow - 1][7] = inputNumber;
            break;
        case 'i': case 'I':
            array[inputRow - 1][8] = inputNumber;
            break;
        case 'q':
            printf("quit");
        default:
            printf("\nno row found, there are only the rows a-i");
    }
}