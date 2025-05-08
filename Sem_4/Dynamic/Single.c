#include <limits.h>
#include <stdio.h>
#include <time.h>
#define MAX 8
#define INF INT_MAX
int spaces = 0;
void printPath(int parent[], int j) {
  if (parent[j] == -1)
    return;
  printPath(parent, parent[j]);
  printf(" -> %d", j);
  spaces = spaces + 5;
}
void ShortestPath(int v, int cost[MAX + 1][MAX + 1], int dist[MAX + 1],
                  int parent[MAX + 1], int n) {
  int s[MAX + 1];
  for (int i = 1; i <= n; i++) {
    s[i] = 0;
    dist[i] = cost[v][i];
    parent[i] = dist[i] == INF ? -1 : v;
  }
  dist[v] = 0;
  s[v] = 1;
  parent[v] = -1;
  printf("Iteration 1 v=%d\n", v);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 1)
      printf("s[%d]=", i);
  }
  printf("true\n");
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 0) {
      printf("s[%d]=", i);
      flag = 1;
    }
  }
  flag == 1 && printf("false\n");
  for (int i = 1; i <= n; i++) {
    if (dist[i] == INF)
      printf("dist %d: infinity\n", i);
    else {
      if (dist[i] == 0) {
        printf("\033[1m\033[4mdist %d: %d\033[0m\n", i, dist[i]);
      } else
        printf("dist %d: %d\n", i, dist[i]);
    }
  }
  printf("\n");
  for (int i = 2; i <= n; i++) {
    int u = -1, minDist = INF;
    for (int j = 1; j <= n; j++) {
      if (!s[j] && dist[j] < minDist) {
        minDist = dist[j];
        u = j;
      }
    }
    if (u == -1)
      break;
    s[u] = 1;
    for (int w = 1; w <= n; w++) {
      if (!s[w] && cost[u][w] != INF) {
        if (dist[w] > dist[u] + cost[u][w]) {
          dist[w] = dist[u] + cost[u][w];
          parent[w] = u;
        }
      }
    }
    printf("Iteration %d u=%d\n", i, u);
    for (int i = 1; i <= n; i++) {
      if (s[i] == 1)
        printf("s[%d]=", i);
    }
    printf("true\n");
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 0) {
        printf("s[%d]=", i);
        flag = 1;
      }
    }
    flag == 1 && printf("false\n");
    for (int i = 1; i <= n; i++) {
      if (dist[i] == INF)
        printf("dist %d: infinity\n", i);
      else {
        if (dist[i] == minDist) {
          printf("\033[1m\033[4mdist %d: %d\033[0m\n", i, dist[i]);
        } else
          printf("dist %d: %d\n", i, dist[i]);
      }
    }
    printf("\n");
  }
}
int main() {
  int n, v, e;
  int cost[MAX + 1][MAX + 1];
  int dist[MAX + 1];
  int parent[MAX + 1];
  printf("Enter number of vertices: ");
  scanf("%d", &n);
  printf("Enter number of edges: ");
  scanf("%d", &e);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cost[i][j] = (i == j) ? 0 : INF;
    }
  }
  int edges[e][3];
  printf("Enter edges (format: u v weight):\n");
  for (int i = 0; i < e; i++) {
    int u, w, weight;
    scanf("%d %d %d", &u, &w, &weight);
    cost[u][w] = weight;
  }
  printf("Enter source vertex: ");
  scanf("%d", &v);
  clock_t start = clock();
  ShortestPath(v, cost, dist, parent, n);
  clock_t end = clock();
  double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("\n%5s %5s %-20s %18s\n", "Source", "Dest", "Path", "Length");
  for (int i = 1; i <= n; i++) {
    spaces = 0;
    if (dist[i] == INF)
      printf("Vertex %d: infinity\n", i);
    else {
      printf("%5d %5d ", 1, i);
      printf(" 1");
      printPath(parent, i);
      for (int m = 0; m < 26 - spaces; m++) {
        printf(" ");
      }
      printf("%10d", dist[i]);
      printf("\n");
    }
  }
  printf("\nExecution time of ShortestPath function was %f seconds \n",
         time_taken);
  return 0;
}