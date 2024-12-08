#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void createAdjMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
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
    adjMatrix[dest][src] = 1;
  }
}

void displayAdjMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
  int i, j;
  printf("Adjacency Matrix:\n");
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }
}

typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

typedef struct Graph {
  int numVertices;
  Node **adjLists;
} Graph;

Node *createNode(int vertex) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->vertex = vertex;
  newNode->next = NULL;
  return newNode;
}

Graph *createGraph(int vertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = vertices;
  graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
  }

  return graph;
}

void addEdge(Graph *graph, int src, int dest) {
  Node *newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void displayAdjList(Graph *graph) {
  int i;
  printf("Adjacency List:\n");
  for (i = 0; i < graph->numVertices; i++) {
    Node *temp = graph->adjLists[i];
    printf("Vertex %d: ", i);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main() {
  int vertices;
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  int adjMatrix[MAX_VERTICES][MAX_VERTICES];
  createAdjMatrix(adjMatrix, vertices);
  displayAdjMatrix(adjMatrix, vertices);

  Graph *graph = createGraph(vertices);
  int edges, src, dest;
  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  for (int i = 0; i < edges; i++) {
    printf("Enter edge (source destination): ");
    scanf("%d %d", &src, &dest);
    addEdge(graph, src, dest);
  }

  int choice;
  while (1) {
    printf("\nMenu:\n");
    printf("1. Display Adjacency Matrix\n");
    printf("2. Display Adjacency List\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      displayAdjMatrix(adjMatrix, vertices);
      break;
    case 2:
      displayAdjList(graph);
      break;
    case 3:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }
}
