#include <stdio.h>
#include <limits.h>

#define INF 1e9  // A large value representing infinity
#define N 100     // Maximum number of vertices

int n, k;
double C[N][N], cost[N];
int d[N], p[N];

struct Edge {
    int u, v, w;
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


void shortest_path() {
    cost[n] = 0.0;
    
    for (int j = n - 1; j >= 1; j--) {
        cost[j] = INF;
        for (int r = j + 1; r <= n; r++) {
            if (C[j][r] < INF && C[j][r] + cost[r] < cost[j]) {
                cost[j] = C[j][r] + cost[r];
                d[j] = r;
            }
        }
    }
    
    p[1] = 1;
    p[k] = n;
    for (int j = 2; j < k; j++) {
        p[j] = d[p[j - 1]];
    }
}

void print_path() {
    printf("Shortest Path: ");
    for (int i = 1; i <= k; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

int main() {
    
    n = 14;
    k = 5; 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            C[i][j] = INF;
        }
    }
    
    for(int i=0; i < 32; i++){
        C[edges[i].u][edges[i].v] = edges[i].w;
    }
   
    
    shortest_path();
    print_path();
    
    return 0;
}