#include<stdio.h>
#include<math.h>


int main(){
    float a[10][10], m, n;

    printf("Enter dimensions of matrix: ");
    scanf("%f %f", &m, &n);

    printf("Enter elements into the matrix: ");
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            float b;
            scanf("%f", &b);
            a[i][j] = sqrt(b);
        }

    printf("Matrix after square rooting each element: \n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            printf("%.1f ", a[i][j]);
        printf("\n");
    }
    

}