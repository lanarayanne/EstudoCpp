#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    int mat[n+1][n+1];
    int sum[n][n];

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=0;i <=n ; i++) {
        for(int j=0;j<=n;j++) {
            if (i+1<=n && j+1<=n) {
                sum[i][j] = mat[i][j] + mat[i][j+1] + mat[i+1][j] + mat[i+1][j+1];
            }
        }

    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (sum[i][j]>=2) {
                printf("S");
            } else {
                printf("U");
            }
        }
        printf("\n");
    }

    return 0;
}