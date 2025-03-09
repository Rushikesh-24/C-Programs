#include <stdio.h>

#define INF 1e9
#define MAX_VERTICES 100   

int numVertices, numStages;
double costMatrix[MAX_VERTICES][MAX_VERTICES], minCost[MAX_VERTICES];
int prevVertex[MAX_VERTICES], path[MAX_VERTICES];
int vertexStage[MAX_VERTICES];  // Array to store stage of each vertex

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

void calculateStages() {
    // Initialize all stages to -1
    for(int i = 1; i <= numVertices; i++) {
        vertexStage[i] = -1;
    }
    
    // First vertex is always stage 1
    vertexStage[1] = 1;
    
    // Last vertex is always last stage
    vertexStage[numVertices] = numStages;
    
    // BFS-like approach to assign stages
    int changed;
    do {
        changed = 0;
        for(int i = 0; i < 32; i++) {  // Check all edges
            int start = edges[i].start;
            int end = edges[i].end;
            
            if(vertexStage[start] != -1 && vertexStage[end] == -1) {
                vertexStage[end] = vertexStage[start] + 1;
                changed = 1;
            }
        }
    } while(changed);
}

void findShortestPath() {
    minCost[1] = 0.0;
    printf("Cost(%d,%d) = %.2f\n", 1, vertexStage[1], minCost[1]);
    
    for (int j = 2; j <= numVertices; j++) {
        minCost[j] = INF;
        for (int r = 1; r < j; r++) {
            double totalCost = costMatrix[r][j] + minCost[r];
            if (costMatrix[r][j] < INF && totalCost < minCost[j]) {
                minCost[j] = totalCost;
                prevVertex[j] = r;
                printf("Cost(%d,%d) = %.2f  d(%d,%d) = %2d\n", 
                       j, vertexStage[j], minCost[j], j, vertexStage[j], prevVertex[j]);
            }
        }
    }

    path[1] = 1;  
    path[numStages] = numVertices;
    
    int current = numVertices;
    for (int i = numStages; i > 1; i--) {
        current = prevVertex[current];
        path[i-1] = current;
    }
}

void displayPath() {
    printf("Shortest Path: ");
    for (int i = numStages; i >0; i--) {
        printf("%d<-", path[i]);
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
        prevVertex[i] = 0;
    }
    
    for(int i = 0; i < 32; i++) {
        costMatrix[edges[i].start][edges[i].end] = edges[i].weight;
    }
    
    calculateStages();  // Calculate stages before finding shortest path
    findShortestPath();
    displayPath();
    
    return 0;
}