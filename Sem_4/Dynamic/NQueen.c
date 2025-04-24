#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x[20];
int solutionCount = 0;
char treeSpace[10000][100];
int treeDepth = 0;

int Place(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return 0;
        }
    }
    return 1;
}

void PrintBoard(int n) {
    printf("┌");
    for (int i = 0; i < n; i++) {
        printf("───");
    }
    printf("┐\n");
    for (int i = 1; i <= n; i++) {
        printf("│");
        for (int j = 0; j < n; j++) {
            if (x[i] == j) {
                printf(" Q ");
            } else {
                printf(" · ");
            }
        }
        printf("│\n");
    }
    printf("└");
    for (int i = 0; i < n; i++) {
        printf("───");
    }
    printf("┘\n\n");
}
void AddTreeNode(int k, int i, int valid) {
    char node[100] = "";
    for (int j = 0; j < k-1; j++) {
        strcat(node, "    ");
    }
    if (k > 1) {
        int len = strlen(node);
        if (len >= 2) {
            node[len - 2] = '|';
            node[len - 1] = '-';
        }
    }
    char label[20];
    sprintf(label, "Q%d at col %d", k, i);
    if (valid) {
        strcat(node, "✓ ");
    } else {
        strcat(node, "✗ ");
    }
    strcat(node, label);
    strcpy(treeSpace[treeDepth++], node);
}
void PrintStateSpaceTree() {
    printf("\n===== STATE SPACE TREE =====\n\n");
    for (int i = 0; i < treeDepth; i++) {
        printf("%s\n", treeSpace[i]);
    }
    printf("\n===========================\n\n");
}
void NQueen(int n, int k) {
    for (int i = 0; i < n; i++) {
        int valid = Place(k, i);
        AddTreeNode(k, i, valid);
        
        if (valid) {
            x[k] = i;
            if (k == n) {
                printf("Solution %d:\n", ++solutionCount);
                PrintBoard(n);
            } else {
                NQueen(n, k + 1);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    for (int i = 0; i < 10000; i++) {
        strcpy(treeSpace[i], "");
    }
    solutionCount = 0;
    treeDepth = 0;
    NQueen(n, 1);
    if (solutionCount == 0) {
        printf("No solutions found for %d-Queens problem.\n", n);
    } else {
        printf("Total solutions found: %d\n", solutionCount);
    }
    PrintStateSpaceTree();
    return 0;
}