#include <stdio.h>

void DebugArray(int array[9]){
    for(int j = 0; j < 9; j++){
        printf("%d", array[j]);
    }
    printf("\n");
    for(int j = 0; j < 9; j++){
        array[j] = 0;
    }
}

//Checks if the actual Column is valid
int CheckColumn(int array[9][9], int x, int y) {
    for (int k = 0; k < 9; k++) {
        if(array[x][k] == array[x][y] && k != y && 0 != y){
            return 0;
        }
    }
    return 1;
}

//Checks if the actual Row you are in is valid
int CheckRow(int array[9][9], int x, int y) {
    for (int k = 0; k < 9; k++) {
        if (array[k][y] == array[x][y] && k != x && 0 != x) {
            return 0;
        }
    }
    return 1;
}

//Checks if the actual Box is valid
int CheckBox( int array[9][9], int x, int y){

    int helpvarx = (x / 3) * 3;
    int helpvary = (y / 3) * 3;

    for (int k = 0; k < 3; k++){
        for (int l = 0; l < 3; l++){
            if (array[k+helpvarx][l+helpvary] == array[x][y] && (k+helpvarx) != x && (l+helpvary) != y) {
                return 0;
            }
        }
    }
    return 1;
}

//Checks if everything is valid and returns 1 if so, else 2
int IsValid(int array[9][9], int x, int y){
    if (1==CheckColumn(array,x, y) && 1==CheckRow(array,x,y) && 1==CheckBox(array, x, y)){
        return 1;
    }else{
        return 404;
    }
}
