#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

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

void SetNumber(){
    char inputColumn;
    int inputRow;
    int inputNumber;
    printf("Switch a number [columnrow number]:\n");
    scanf(" %c%d%d",&inputColumn, &inputRow, &inputNumber);
    //printf("%c\n",inputColumn);
    //printf("%d\n",inputRow);
    //printf("%d",inputNumber);
    if (9 < inputRow || 9 < inputNumber){
        printf("\nplease only input Numbers between 1-9");
    }
    switch(inputColumn){
        case 'a': case 'A':
            Matrix[inputRow - 1][0] = inputNumber;
            printf("\n%d\n", inputRow);
            break;
        case 'b': case 'B':
            Matrix[inputRow - 1][1] = inputNumber;
            break;
        case 'c': case 'C':
            Matrix[inputRow - 1][2] = inputNumber;
            break;
        case 'd': case 'D':
            Matrix[inputRow - 1][3] = inputNumber;
            break;
        case 'e': case 'E':
            Matrix[inputRow - 1][4] = inputNumber;
            break;
        case 'f': case 'F':
            Matrix[inputRow - 1][5] = inputNumber;
            break;
        case 'g': case 'G':
            Matrix[inputRow - 1][6] = inputNumber;
            break;
        case 'h': case 'H':
            Matrix[inputRow - 1][7] = inputNumber;
            break;
        case 'i': case 'I':
            Matrix[inputRow - 1][8] = inputNumber;
            break;
        default:
            printf("\nno row found, there are only the rows a-i");
    }
}

int checkrow(){
    printf("");
    return 1;
}

void RandomNumbers(){
    //doesn't work with seed (I only get always the same number)
    //srand(time(0));
    int randomNum;
    for(int i = 0 ; i < 9; i++ ) {
        int rowStorage[9] = {1111,1111,1111,1111,1111,1111,1111,1111,1111};
        printf("\nreset\n");
        //sleep(5);
        for(int ii = 0; ii < 9; ii++){
            randomNum = rand() % 9 +1; // resets the rowStorage ... // I don't understand why
            for(int j = 0; j < 9; j++){
                printf("%d", rowStorage[j]);
            }
            printf("\n");
            for(int j = 0; j < 9; j++){
                rowStorage[j] = 0;
            }
            for (int j = 0; j < 9; j++) {
                //printf("NewRandomNum %d\n", randomNum);
                if (rowStorage[j] == randomNum) {
                    //printf("in row \n");
                    randomNum = rand() % 9 +1;
                }
                rowStorage[ii] = randomNum;
                //printf("Eingetragen: %d ", rowStorage[ii]);
                /*
                for(int j = 0; j < 9; j++){
                    printf("%d", rowStorage[j]);
                }
                printf("\n");
                for(int j = 0; j < 9; j++){
                    rowStorage[j] = 0;
                }
                 */
            }
            Matrix[i][ii] = randomNum;
            //printf("%d", Matrix[i][ii]);

        }
    }
}




void AskName(char Name[30]) {
    //asks for name
    printf("Who is playing right now?\n");
    scanf("%29s", Name);
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
    char Name [30];
    //AskName(Name);
    RandomNumbers();
    PrintSudokuField(Name);
    //for(int i = 0; i < 40; i++)
    //    printf("%d\n", RandomNumberGen());
    //while (true){
    //    PrintSudokuField(Name);
    //    SetNumber();
    //}
}