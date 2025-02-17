#include <stdio.h>
#define MAX 100

void createGraph(int adjMatrix[MAX][MAX], int vertices) {
  int i, j;
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      adjMatrix[i][j] = 0;
    }
  }
  int edges[][2] = {
    {0, 1}, {0, 2}, {0, 3},
    {1, 0}, {1, 2}, {1, 3},
    {2, 0}, {2, 1}, {2, 3},
    {3, 0}, {3, 1}, {3, 2}
  };
  int numEdges = sizeof(edges) / sizeof(edges[0]);

  for (i = 0; i < numEdges; i++) {
    int src = edges[i][0];
    int dest = edges[i][1];
    adjMatrix[src][dest] = 1;
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
}

void bfs(int adjMatrix[MAX][MAX], int vertices, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int traversal[MAX];
    int traversalCount = 0;
    
    printf("\nStarting BFS traversal from vertex %d\n", startVertex);
    printf("------------------------------------------------\n");
    
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    printf("Insert(%d)\n", startVertex);
    printf("Queue: ");
    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
    
    while (front < rear) {
        int currentVertex = queue[front++];
        traversal[traversalCount++] = currentVertex;
        
        printf("\nDelete(%d)\n", currentVertex);
        printf("Queue: ");
        if (front == rear) {
            printf("empty");
        } else {
            for (int i = front; i < rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
        printf("Traversal: ");
        for (int i = 0; i < traversalCount; i++) {
            printf("%d ", traversal[i]);
        }
        printf("\n");
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
                printf("\nInsert(%d)\n", i);
                printf("Queue: ");
                for (int j = front; j < rear; j++) {
                    printf("%d ", queue[j]);
                }
                printf("\n");
                printf("Traversal: ");
                for (int j = 0; j < traversalCount; j++) {
                    printf("%d ", traversal[j]);
                }
                printf("\n");
            }
        }
        printf("------------------------------------------------\n");
    }
    printf("\nFinal BFS Traversal: ");
    for (int i = 0; i < traversalCount; i++) {
        printf("%d ", traversal[i]);
    }
    printf("\n");
}

void dfs(int adjMatrix[MAX][MAX], int vertices, int startVertex) {
    int visited[MAX] = {0};
    int stack[MAX];
    int stackSize = 0;
    int traversal[MAX];
    int traversalCount = 0;
    int accessTime[MAX]; 
    int time = 0;   
    
    printf("\nStarting DFS traversal from vertex %d\n", startVertex);
    printf("------------------------------------------------\n");
    stack[stackSize++] = startVertex;
    accessTime[startVertex] = ++time;
    visited[startVertex] = 1;
    traversal[traversalCount++] = startVertex;
    
    printf("Visit(%d) at time %d\n", startVertex, time);
    printf("Stack: %d\n", startVertex);
    printf("Traversal: %d\n", startVertex);
    printf("------------------------------------------------\n");
    
    while (stackSize > 0) {
        int currentVertex = stack[stackSize - 1];  
        int foundNewVertex = 0;
        
       
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                stack[stackSize++] = i;
                visited[i] = 1;
                accessTime[i] = ++time;
                traversal[traversalCount++] = i;
                
                printf("\nExplore edge %d -> %d\n", currentVertex, i);
                printf("Visit(%d) at time %d\n", i, time);
                printf("Stack: ");
                for (int j = 0; j < stackSize; j++) {
                    printf("%d ", stack[j]);
                }
                printf("\nTraversal so far: ");
                for (int j = 0; j < traversalCount; j++) {
                    printf("%d ", traversal[j]);
                }
                printf("\nAccess times: ");
                for (int j = 0; j < vertices; j++) {
                    if (visited[j]) {
                        printf("%d(%d) ", j, accessTime[j]);
                    }
                }
                printf("\n------------------------------------------------\n");
                
                foundNewVertex = 1;
                break;
            }
        }
        
        if (!foundNewVertex) {
            printf("\nBacktrack from %d\n", currentVertex);
            stackSize--;
            printf("Stack after backtrack: ");
            if (stackSize == 0) {
                printf("empty");
            } else {
                for (int j = 0; j < stackSize; j++) {
                    printf("%d ", stack[j]);
                }
            }
            printf("\nTraversal so far: ");
            for (int j = 0; j < traversalCount; j++) {
                printf("%d ", traversal[j]);
            }
            printf("\nAccess times: ");
            for (int j = 0; j < vertices; j++) {
                if (visited[j]) {
                    printf("%d(%d) ", j, accessTime[j]);
                }
            }
            printf("\n------------------------------------------------\n");
        }
    }
    printf("\nFinal DFS Results:\n");
    printf("Complete traversal: ");
    for (int i = 0; i < traversalCount; i++) {
        printf("%d ", traversal[i]);
    }
    printf("\nAccess times for each vertex:\n");
    for (int i = 0; i < vertices; i++) {
        if (visited[i]) {
            printf("Vertex %d: time %d\n", i, accessTime[i]);
        }
    }
    printf("\n");
}


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

  printf("DFS Traversal starting from vertex %d: ", startVertex);
  dfs(adjMatrix, vertices, startVertex);
  printf("\n");
}
