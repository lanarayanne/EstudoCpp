#include <stdio.h>

int main(void) {

    char M[10][10];

    //Preenchendo cenário

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 5 && (j == 3 || j==4 || j==5 || j==6)) {
                M[i][j] = 'X';
            } else if(i==3 && j==8) {
                M[i][j] = 'X';
            } else if(i==8 && (j==6 || j==7)) {
                M[i][j] = 'X';
            } else if (i==2 && j==0) {
                M[i][j] = 'X';
            } else if(i==0 && j==5){
                M[i][j] = 'o';
            } else {
                M[i][j] = '.';
            }
        }
    }


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (M[i][j] != 'o') {
                continue;
            } else {
                if (M[i+1][j] == '.' && (i+1) < 10){
                    M[i+1][j] = 'o';
                }
                if (M[i+1][j] == 'X' && (i+1) < 10){
                    if (M[i][j+1] == '.' && (j+1) < 10){
                        M[i][j+1] = 'o';
                    }
                    if (M[i][j-1] == '.' && (j-1) > 0){
                        M[i][j-1] = 'o';
                        i=0;
                        j=0;
                    }


                }
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}