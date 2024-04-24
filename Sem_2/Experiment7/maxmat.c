#include<stdio.h>
#include<math.h>


int main(){
    float a[10][10], m, n;

    printf("Enter dimensions of matrix: ");
    scanf("%f %f", &m, &n);

    printf("Enter elements into the matrix: ");
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%f", &a[i][j]);

    float rowmax=a[0][0], colmax=a[0][0] ,rx=0, ry=0, cx=0, cy=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] > rowmax){
                rowmax = a[i][j];
                rx=i;
                ry=j;
            }
        }
        printf("Max value in Row %d is %f at (%.0f,%.0f) \n", i+1, rowmax, rx, ry);
        rowmax = a[i+1][0];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[j][i] > colmax){
                colmax = a[j][i];
                cx=j;
                cy=i;
            }
        }
        printf("Max value in Column %d is %f (%.0f,%.0f) \n", i+1, colmax, cx, cy);
        colmax = a[i+1][0];
    }
    

}