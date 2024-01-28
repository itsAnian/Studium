#include <stdio.h>
#include <string.h>

void PrintSudokuField(){
    //defines everything
    int whichRow = 0;
    char column [] = "  abc def ghi";
    char *borderBottomTop ="  ––– ––– –––\n";
    int rowNumber[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char *row = "|***|***|***|\n";
    int i;
    int k;
    char name [30];
    //asks for name
    printf("Who is playing right now?\n");
    scanf("%s", name);
    //prints everything out
    printf("%s is playing\n", name);
    printf("%s", column);

    printf("\n");
    for (i=0; i < 3; i++){
        printf("%s", borderBottomTop);
        for (k=0; k < 3; k++) {
            printf("%d" "%s", rowNumber[whichRow], row);
            whichRow += 1;
        }
    }
    printf("%s", borderBottomTop);
}


int main(){
    PrintSudokuField();
}