#include<stdio.h>
#include<math.h>


int main(){
    float a[10][10], m, n;
    int r1, r2;

    printf("Enter dimensions of matrix: ");
    scanf("%f %f", &m, &n);

    printf("Enter elements into the matrix: ");
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%f", &a[i][j]);

    printf("Enter rows to interchange: ");
    scanf("%d %d", &r1, &r2);

    for(int i=0; i<n; i++){
        a[r1-1][i] += a[r2-1][i];
        a[r2-1][i] = a[r1-1][i] - a[r2-1][i];
        a[r1-1][i] = a[r1-1][i] - a[r2-1][i];  
    }
    
    printf("Matrix after interchanging Row %d and Row %d: \n", r1, r2);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            printf("%.1f ", a[i][j]);
        printf("\n");
    }
}