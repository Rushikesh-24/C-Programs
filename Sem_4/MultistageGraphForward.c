#include <stdio.h>

#define INF 1e9
#define MAX_VERTICES 100   

int numVertices, numStages;
double costMatrix[MAX_VERTICES][MAX_VERTICES], minCost[MAX_VERTICES];
int nextVertex[MAX_VERTICES], path[MAX_VERTICES];

struct Edge {
    int start, end, weight;
};

struct Edge edges[] = {
    {1,2,9},{1,3,8},{1,4,6},{1,5,7},
    {2,6,10},{2,7,11},{2,8,12},
    {3,6,15},{3,8,14},{3,9,13},
    {4,7,10},{4,8,11},{4,9,12},
    {5,6,8},{5,8,9},{5,9,10},
    {6,10,5},{6,11,6},{6,12,7},
    {7,10,8},{7,11,9},{7,12,7},
    {8,11,6},{8,12,7},{8,13,8},
    {9,10,5},{9,12,8},{9,13,6},
    {10,14,8},{11,14,9},{12,14,8},{13,14,7}
};

void findShortestPath() {
    minCost[numVertices] = 0.0;
    printf("Cost(%d) = %.2f\n", numVertices, minCost[numVertices]);
    
    for (int j = numVertices - 1; j >= 1; j--) {
        minCost[j] = INF;
        for (int r = j + 1; r <= numVertices; r++) {
            double totalCost = costMatrix[j][r] + minCost[r];
            if (costMatrix[j][r] < INF && totalCost < minCost[j]) {
                minCost[j] = totalCost;
                nextVertex[j] = r;
            }
        }
        if (minCost[j] < INF) {
            printf("Cost(%d) = %.2f  d(%d) = %2d\n", j, minCost[j],j,nextVertex[j]);
        }
    }

    path[1] = 1;
    path[numStages] = numVertices;
    for (int j = 2; j < numStages; j++) {
        path[j] = nextVertex[path[j - 1]];
    }
}

void displayPath() {
    printf("Shortest Path: ");
    for (int i = 1; i <= numStages; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    numVertices = 14;
    numStages = 5;
    
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            costMatrix[i][j] = INF;
        }
    }
    
    for(int i = 0; i < 32; i++) {
        costMatrix[edges[i].start][edges[i].end] = edges[i].weight;
    }
    
    findShortestPath();
    displayPath();
    
    return 0;
}