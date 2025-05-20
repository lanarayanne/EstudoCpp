#include <stdio.h>

int main(void) {

    int m, n;
    scanf("%d %d", &m, &n);
    char M[m][n];

    //Preenchendo cenário

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &M[i][j]);
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] != 'o') {
                continue;
            } else {
                if (M[i+1][j] == '.' && (i+1) < m){
                    M[i+1][j] = 'o';
                }
                if (M[i+1][j] == '#' && (i+1) < m){
                    if (M[i][j+1] == '.' && (j+1) < n){
                        M[i][j+1] = 'o';
                    }
                    if (M[i][j-1] == '.' && (j-1) >= 0){
                        M[i][j-1] = 'o';
                        i=0;
                        j=0;
                    }
                }
            }
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}