#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct public public;

int column_a [] = {1,2,3,4,5,6,7,8,9,};
int column_b [] = {1,2,3,4,5,6,7,8,9,};
int column_c [] = {1,2,3,4,5,6,7,8,9,};
int column_d [] = {1,2,3,4,5,6,7,8,9,};
int column_e [] = {1,2,3,4,5,6,7,8,9,};
int column_f [] = {1,2,3,4,5,6,7,8,9,};
int column_g [] = {1,2,3,4,5,6,7,8,9,};
int column_h [] = {1,2,3,4,5,6,7,8,9,};
int column_i [] = {1,2,3,4,5,6,7,8,9,};

struct NameStorage{
    char name[30];
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
            column_a[inputRow - 1] = inputNumber;
            printf("%d", column_a[inputRow]);
            break;
        case 'b': case 'B':
            column_b[inputRow - 1] = inputNumber;
            break;
        case 'c': case 'C':
            column_c[inputRow - 1] = inputNumber;
            break;
        case 'd': case 'D':
            column_d[inputRow - 1] = inputNumber;
            break;
        case 'e': case 'E':
            column_e[inputRow - 1] = inputNumber;
            break;
        case 'f': case 'F':
            column_f[inputRow - 1] = inputNumber;
            break;
        case 'g': case 'G':
            column_g[inputRow - 1] = inputNumber;
            break;
        case 'h': case 'H':
            column_h[inputRow - 1] = inputNumber;
            break;
        case 'i': case 'I':
            column_i[inputRow - 1] = inputNumber;
            break;
        default:
            printf("\nno row found, there are only the rows a-i");
    }
}
void AskName(struct NameStorage *NameS) {
    //asks for name
    printf("Who is playing right now?\n");
    scanf("%29s", NameS -> name);
}

void PrintSudokuField(struct NameStorage *NameS){
    //defines everything
    int whichRow = 0;
    char column [] = "  abc def ghi";
    char *borderBottomTop ="  ––– ––– –––\n";
    int rowNumber[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char *row = "|";
    int i;
    int k;
    //prints everything out
    printf("%s is playing\n\n", NameS -> name);
    printf("%s", column);

    printf("\n");
    for (i=0; i < 3; i++){
        printf("%s", borderBottomTop);
        for (k=0; k < 3; k++) {
            printf("%d%s%d%d%d%s%d%d%d%s%d%d%d%s\n", rowNumber[whichRow], row, column_a[whichRow],column_b[whichRow],column_c[whichRow], row, column_d[whichRow],column_e[whichRow],column_f[whichRow], row, column_g[whichRow],column_h[whichRow],column_i[whichRow], row);
            whichRow += 1;
        }
    }
    printf("%s", borderBottomTop);
}




int main() {
    struct NameStorage NameS;
    AskName(&NameS);
    while (true){
        PrintSudokuField(&NameS);
        SetNumber(&NameS);
    }
}