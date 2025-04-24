#include <limits.h>
#include <stdio.h>

int A[5][5] = {{0, 8, 3, INT_MAX, -4},
               {2, 0, -2, 4, 7},
               {INT_MAX, 2, 0, 6, INT_MAX},
               {-2, INT_MAX, -5, 0, -2},
               {6, INT_MAX, INT_MAX, 6, 0}};

void display(int Array[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (Array[i][j] != INT_MAX)
                printf(" %d  ", Array[i][j]);
            else
                printf(" ∞  ");
        }
        printf("\n");
    }
    printf("\n");
}

void displayP(int Array[5][5]) {
    printf("   ");
    for (int j = 0; j < 5; j++) {
        printf(" %d  ", j + 1);
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf(" %d ", i + 1);
        for (int j = 0; j < 5; j++) {
            if (i != j)
                printf(" %d  ", Array[i][j] + 1);
            else
                printf(" _  ");
        }
        printf("\n");
    }
    printf("\n");
}

void line() {
    printf("\n");
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
    printf("\n");
}

void all_pair(int n, int A[n][n], int P[n][n]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][k] != INT_MAX && A[k][j] != INT_MAX) {
                    if (A[i][j] > (A[i][k] + A[k][j])) {
                        A[i][j] = A[i][k] + A[k][j];
                        P[i][j] = P[k][j]; 
                    }
                }
            }
        }
        printf("A^%d\n", k+1);
        display(A);
        printf("P^%d\n", k+1);
        displayP(P);
        line();
    }
}
void displayPath(int A[5][5],int P[5][5]){
    printf("Source      Destination     Length      Path\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i!=j)
            {printf("%d            %d             %2d",i+1,j+1,A[i][j]);
            int path[5];
            int count = 0;
            int temp = j;
            while (temp != i) {
                path[count++] = temp;
                temp = P[i][temp];
            }
            path[count] = i;
            printf("            ");
            for (int k = count; k >= 0; k--) {
                printf("%d", path[k] + 1);
                if(k!=0)
                    printf("->");
            }
            printf("\n");
        }
        }
    }
}

int main() {
    int P[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j)
                P[i][j] = -1;  
            else
                P[i][j] = i;  
        }
    }
    printf("A^0\n");
    display(A);
    printf("P^0\n");
    displayP(P);
    line();
    all_pair(5, A, P);
    displayPath(A,P);
    return 0; 
}