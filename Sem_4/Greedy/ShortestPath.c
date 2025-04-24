#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 8
#define INF INT_MAX

int cost[MAX][MAX];

void setup(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = INF;
        }
        cost[i][i] = 0;
    }
    
    cost[0][1] = 20;
    cost[0][2] = 40;
    cost[0][4] = 50;
    cost[0][5] = 40;
    cost[1][2] = 15;
    cost[1][3] = 10;
    cost[1][4] = 5;
    cost[2][7] = 5;
    cost[3][2] = 2;
    cost[3][5] = 8;
    cost[4][3] = 3;
    cost[4][6] = 8;
    cost[5][2] = 3;
    cost[5][4] = 6;
    cost[5][7] = 4;
    cost[6][1] = 2;
    cost[6][5] = 2;
    cost[6][7] = 2;
    cost[7][1] = 3;
}

void printS(int n, bool s[]) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (s[i]) {
            printf("s[%d] = ", i + 1);
        }
    }

    printf("true\n");
    for (int i = 0; i < n; i++) {
        if (!s[i]) {
            printf("s[%d] =", i + 1);
        }
    }
    printf("false\n");
}
int findMin(int n, int dist[],bool s[]) {
    int min = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == false && (min == -1 || dist[i] < dist[min])) {
            min = i;
        }
    }
    return min;
}
void printDist(int n, int dist[], int path[],bool s[]) {
    printf("\nShortest paths from source:");
    printf("\nVertex\tDistance\tPath");
    int min = findMin(n, dist,s);
    for (int i = 0; i < n; i++) {
        printf("\n%d\t", i + 1);
        if (dist[i] != INF) {
            if (dist[i] != 0 && min == i) {
                printf("\033[1;4m%d\033[0m\t\t", dist[i]);
            } else {
                printf("%d\t\t", dist[i]);
            }
        } else {
            printf("Infinity\t");
        }
        
        if (dist[i] != INF) {
            int current = i;
            int pathArr[MAX];
            int pathLen = 0;
            while (current != -1) {
                pathArr[pathLen++] = current;
                current = path[current];
            }
            
            for (int j = pathLen - 1; j >= 0; j--) {
                printf("%d", pathArr[j] + 1);
                if (j > 0) printf(" → ");
            }
        } else {
            printf("No path");
        }
    }
    printf("\n");
}

void ShortestPath(int n, int dist[], int cost[MAX][MAX], int v) {
    bool s[n];  
    int path[n];
    
    for (int i = 0; i < n; i++) {
        s[i] = false;
        dist[i] = cost[v][i];
        if (dist[i] != INF && i != v) {
            path[i] = v;  
        } else {
            path[i] = -1;    
        }
    }
    
    dist[v] = 0;
    s[v] = true;
    path[v] = -1;
    printf("v = %d",v+1);
    printS(n, s);
    printDist(n, dist,path,s);
    
    for (int i = 1; i < n; i++) {
        int min = INF;
        int minIndex = -1;
        
        for (int u = 0; u < n; u++) {
            if (!s[u] && dist[u] != INF && dist[u] < min) {
                min = dist[u];
                minIndex = u;
            }
        }
        
        if (minIndex == -1) break;
        
        s[minIndex] = true;
        
        for (int w = 0; w < n; w++) {
            if (!s[w] && cost[minIndex][w] != INF && 
                dist[minIndex] != INF && 
                dist[minIndex] + cost[minIndex][w] < dist[w]) {
                dist[w] = dist[minIndex] + cost[minIndex][w];
                path[w] = minIndex;
            }
        }
        printf("\nu = %d",minIndex+1);
        printS(n, s);
        printDist(n, dist,path,s);
    }
}
int main() {
    setup(MAX);
    int dist[MAX];
    
    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
    }
    
    ShortestPath(MAX, dist, cost, 0);
    return 0;
}