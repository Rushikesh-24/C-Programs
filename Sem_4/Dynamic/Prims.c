#include <stdio.h>
#include <time.h>
#define MAX 20
int *getSmallestEdge(int E[14][3]) {
  int min = 99999;
  int minIndex = -1;
  for (int i = 0; i < 14; i++) {
    if (E[i][2] < min && E[i][2] != -1) {
      min = E[i][2];
      minIndex = i;
    }
  }
  return E[minIndex];
}
void printT(int t[MAX][2], int currentSize) {
  printf("\nT matrix status (edges in MST):\n");
  printf("Index\t1\t2\n");
  for (int i = 1; i <= currentSize; i++) {
    printf("%d\t%d\t%d\n", i, t[i][0], t[i][1]);
  }
}
void printFinalT(int t[MAX][2], int cost[MAX][MAX]) {
  printf("\nFinal Minimum Spanning Tree Edges:\n");
  printf("Edge\tVertex 1\tVertex 2\tCost\n");
  printf("----------------------------------------\n");
  for (int i = 1; i <= 7; i++) {
    printf("%d\t%d\t%d\t%d\n", i, t[i][0], t[i][1], cost[t[i][0]][t[i][1]]);
  }
}
void createGraph(int E[14][3], int cost[MAX][MAX], int n) {
  int maxEdges;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cost[i][j] = 99999;
    }
  }
  for (int i = 1; i <= n; i++) {
    cost[i][i] = 0;
  }
  maxEdges = 14;
  for (int i = 1; i <= maxEdges; i++) {
    int origin = E[i - 1][0];
    int destination = E[i - 1][1];
    int weight = E[i - 1][2];
    cost[origin][destination] = weight;
    cost[destination][origin] = weight;
  }
  printf("The cost matrix is:\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (cost[i][j] == 99999)
        printf("%5s", "inf");
      else
        printf("%5d", cost[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
void printPrims(int near[], int cost[MAX][MAX]) {
  printf(" %10s %10s\n", "near[j]", "cost[j][near[j]]");
  for (int i = 1; i <= 8; i++) {
    printf("near[%d]: %5d %9d\n", i, near[i],
           near[i] == 0 ? 0 : cost[i][near[i]]);
  }
  printf("\n");
}
int prims(int E[14][3], int cost[MAX][MAX], int n, int t[MAX][2]) {
  int near[MAX];
  int mincost = 0;
  createGraph(E, cost, n);
  int *minEdge = getSmallestEdge(E);
  t[1][0] = minEdge[0];
  t[1][1] = minEdge[1];
  mincost = cost[minEdge[0]][minEdge[1]];
  for (int i = 1; i <= n; i++) {
    if (cost[i][minEdge[0]] < cost[i][minEdge[1]])
      near[i] = minEdge[0];
    else
      near[i] = minEdge[1];
  }
  near[minEdge[0]] = near[minEdge[1]] = 0;
  printPrims(near, cost);
  printT(t, 1);
  for (int i = 2; i <= n - 1; i++) {
    int min = 99999;
    int j = 0;
    for (int k = 1; k <= n; k++) {
      if (near[k] != 0 && cost[k][near[k]] < min) {
        min = cost[k][near[k]];
        j = k;
      }
    }
    t[i][0] = j;
    t[i][1] = near[j];
    mincost += cost[j][near[j]];
    printf("Mincost: %d\n\n", mincost);
    near[j] = 0;
    for (int k = 1; k <= n; k++) {
      if (near[k] != 0 && cost[k][j] < cost[k][near[k]]) {
        near[k] = j;
      }
    }
    printPrims(near, cost);
    printT(t, i);
  }
  return mincost;
}
int main() {
  int E[14][3];
  int cost[MAX][MAX];
  int n, edges;
  int t[MAX][2];
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the number of edges: ");
  scanf("%d", &edges);
  printf("Enter the edges (vertex1 vertex2 weight):\n");
  for (int i = 0; i < edges; i++) {
    scanf("%d %d %d", &E[i][0], &E[i][1], &E[i][2]);
  }
  clock_t start = clock();
  int result = prims(E, cost, n, t);
  clock_t end = clock();
  double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("\nFinal minimum spanning tree cost: %d\n", result);
  printf("\nExecution time of prims function was %f seconds \n", time_taken);
}