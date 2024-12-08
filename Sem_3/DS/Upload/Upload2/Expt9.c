#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1; // For undirected graph
}

void bfs(int startVertex, int numVertices) {
    int i;
    front = rear = 0;
    queue[rear] = startVertex;
    visited[startVertex] = 1;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int startVertex, int numVertices) {
    int stack[MAX];
    int top = -1;
    int i;

    stack[++top] = startVertex;
    visited[startVertex] = 1;

    while (top != -1) {
        int currentVertex = stack[top--];
        printf("%d ", currentVertex);

        for (i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfsRecursive(int vertex, int numVertices) {
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsRecursive(i, numVertices);
        }
    }
}

void resetVisited(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
}

int main() {
    int numVertices, numEdges;
    int startVertex, endVertex;
    int i;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (i = 0; i < numEdges; i++) {
        printf("Enter edge (start end): ");
        scanf("%d %d", &startVertex, &endVertex);
        addEdge(startVertex, endVertex);
    }
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. BFS Traversal\n");
        printf("2. DFS Traversal\n");
        printf("3. Recursive DFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("BFS Traversal: ");
                resetVisited(numVertices);
                bfs(0, numVertices);
                printf("\n");
                break;
            case 2:
                printf("DFS Traversal: ");
                resetVisited(numVertices);
                dfs(0, numVertices);
                printf("\n");
                break;
            case 3:
                printf("Recursive DFS Traversal: ");
                resetVisited(numVertices);
                dfsRecursive(0, numVertices);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}