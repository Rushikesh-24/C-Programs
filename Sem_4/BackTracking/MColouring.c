#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int n = 6;        
int x[7];         
int m = 2;        

int G[7][7] = {   
    {0, 0, 0, 0, 0, 0, 0},   
    {0, 0, 1, 1, 0, 0, 0},  
    {0, 1, 0, 0, 1, 0, 1},   
    {0, 1, 0, 0, 1, 1, 0},   
    {0, 0, 1, 1, 0, 0, 0},  
    {0, 0, 0, 1, 0, 0, 0},   
    {0, 0, 1, 0, 0, 0, 0},   
};

char treeStates[1000]; 
int treeIndex = 0;  

void nextVertex(int k) {
    while (true) {
        x[k] = (x[k] + 1) % (m + 1); 
        if (x[k] == 0) return; 
        
        int j;
        for (j = 1; j <= n; j++) {
            if (G[k][j] == 1 && x[k] == x[j] && x[j] != 0) 
                break;
        }
        if (j > n) return;
    }
}

void recordState(int k) {
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) {
            treeStates[treeIndex++] = ' ';
        } else {
            treeStates[treeIndex++] = '0' + x[i];
        }
    }
}

void mcolouring(int k) {
    while (true) {
        nextVertex(k);
        recordState(k); 
        if (x[k] == 0) { 
            recordState(k);//bound
            printf("%d",k);
            return;
        }
        if (k == n) {
            printf("Solution: ");
            for (int i = 1; i <= n; i++) {
                printf("%d ", x[i]);
            }
            printf("\n");
        } else {
            mcolouring(k + 1);
        }
    }
}

void printTree(char arr[], int size, int levels) {
    int n = 0;
    for (int level = 0; level <= levels; level++) {
        int nodesInLevel = pow(2, level);
        int spaceBetweenNodes = pow(2, levels - level + 1) - 1;
        int initialSpace = pow(2, levels - level) - 1;
        for (int i = 0; i < initialSpace; i++)
            printf(" ");
        for (int i = 0; i < nodesInLevel && n < size; i++) {
            if (arr[n] != ' ') {
                printf("%c", arr[n]);
                if (i < nodesInLevel - 1) {
                    for (int j = 0; j < spaceBetweenNodes; j++)
                        printf(" ");
                }
            } else {
                printf(" ");
                if (i < nodesInLevel - 1) {
                    for (int j = 0; j < spaceBetweenNodes; j++)
                        printf(" ");
                }
            }
            n++;
        }
        printf("\n");
    }
}

int main() {
    x[1] = 0; 
    for (int i = 2; i <= n; i++) x[i] = 0; 
    
    printf("M-Coloring Solutions:\n");
    mcolouring(1);  
    
   // printTree(treeStates, treeIndex, 6); 
    return 0;
}