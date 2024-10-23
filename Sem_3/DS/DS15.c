#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void createGraph(int adjMatrix[MAX][MAX], int vertices);
void displayGraph(int adjMatrix[MAX][MAX], int vertices);
void bfs(int adjMatrix[MAX][MAX], int vertices, int startVertex);
void dfs(int adjMatrix[MAX][MAX], int vertices, int startVertex, int visited[MAX]);
void dfsNonRecursive(int adjMatrix[MAX][MAX], int vertices, int startVertex);

int main() {
  int vertices;
  int adjMatrix[MAX][MAX];

  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  createGraph(adjMatrix, vertices);
  displayGraph(adjMatrix, vertices);

  int startVertex;
  printf("Enter the starting vertex for BFS: ");
  scanf("%d", &startVertex);

  bfs(adjMatrix, vertices, startVertex);

  int visited[MAX] = {0};
  printf("DFS Traversal starting from vertex %d: ", startVertex);
  dfs(adjMatrix, vertices, startVertex, visited);
  printf("\n");

  printf("Enter the starting vertex for Non-Recursive DFS: ");
  scanf("%d", &startVertex);

  dfsNonRecursive(adjMatrix, vertices, startVertex);
  
}

void createGraph(int adjMatrix[MAX][MAX], int vertices) {
  int i, j;
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      adjMatrix[i][j] = 0;
    }
  }

  int edges, src, dest;
  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  for (i = 0; i < edges; i++) {
    printf("Enter edge (source destination): ");
    scanf("%d %d", &src, &dest);
    adjMatrix[src][dest] = 1;
    // adjMatrix[dest][src] = 1;
  }
}

void displayGraph(int adjMatrix[MAX][MAX], int vertices) {
  int i, j;
  printf("Adjacency Matrix:\n");
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }

  printf("\nGraph Connections:\n");
  for (i = 0; i < vertices; i++) {
    printf("Vertex %d: ", i);
    int hasConnections = 0;
    for (j = 0; j < vertices; j++) {
      if (adjMatrix[i][j] == 1) {
        printf("-> %d ", j);
        hasConnections = 1;
      }
    }
    if (!hasConnections) {
      printf("No connections");
    }
    printf("\n");
  }
}

void bfs(int adjMatrix[MAX][MAX], int vertices, int startVertex) {
  int visited[MAX] = {0};
  int queue[MAX], front = 0, rear = 0;

  visited[startVertex] = 1;
  queue[rear++] = startVertex;

  printf("BFS Traversal starting from vertex %d: ", startVertex);

  while (front < rear) {
    int currentVertex = queue[front++];
    printf("%d ", currentVertex);

    for (int i = 0; i < vertices; i++) {
      if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
        queue[rear++] = i;
        visited[i] = 1;
      }
    }
  }
  printf("\n");
}

void dfs(int adjMatrix[MAX][MAX], int vertices, int startVertex, int visited[MAX]) {
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    for (int i = 0; i < vertices; i++) {
      if (adjMatrix[startVertex][i] == 1 && !visited[i]) {
        dfs(adjMatrix, vertices, i, visited);
      }
    }
  }

  void dfsNonRecursive(int adjMatrix[MAX][MAX], int vertices, int startVertex) {
    int visited[MAX] = {0};
    int stack[MAX], top = -1;

    stack[++top] = startVertex;

    printf("DFS Non-Recursive Traversal starting from vertex %d: ", startVertex);

    while (top != -1) {
      int currentVertex = stack[top--];

      if (!visited[currentVertex]) {
        printf("%d ", currentVertex);
        visited[currentVertex] = 1;
      }

      for (int i = vertices - 1; i >= 0; i--) {
        if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
          stack[++top] = i;
        }
      }
    }
    printf("\n");
  }
  