#include<stdio.h>
#include<math.h>


int main(){
    float a[10][10], m, n, val;

    printf("Enter dimensions of matrix: ");
    scanf("%f %f", &m, &n);

    printf("Enter elements into the matrix: ");
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            scanf("%f", &a[i][j]);
        }

    printf("Enter value to multiply the matrix with: ");
    scanf("%f", &val);

     for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            a[i][j] = a[i][j]*val;

    printf("Matrix after multiplying with %.1f: \n", val);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            printf("%.1f ", a[i][j]);
        printf("\n");
    }
    

}