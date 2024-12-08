#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
  int dest;
  struct AdjListNode *next;
};

struct AdjList {
  struct AdjListNode *head;
};

struct Graph {
  int V;
  struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest) {
  struct AdjListNode *newNode =
      (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
  newNode->dest = dest;
  newNode->next = NULL;
  return newNode;
}

struct Graph *createGraph(int V) {
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
  for (int i = 0; i < V; ++i)
    graph->array[i].head = NULL;
  return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
  struct AdjListNode *newNode = newAdjListNode(dest);
  newNode->next = graph->array[src].head;
  graph->array[src].head = newNode;

  newNode = newAdjListNode(src);
  newNode->next = graph->array[dest].head;
  graph->array[dest].head = newNode;
}

void deleteEdge(struct Graph *graph, int src, int dest) {
  struct AdjListNode *temp = graph->array[src].head;
  struct AdjListNode *prev = NULL;

  while (temp != NULL && temp->dest != dest) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  if (prev != NULL)
    prev->next = temp->next;
  else
    graph->array[src].head = temp->next;

  free(temp);

  temp = graph->array[dest].head;
  prev = NULL;

  while (temp != NULL && temp->dest != src) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  if (prev != NULL)
    prev->next = temp->next;
  else
    graph->array[dest].head = temp->next;

  free(temp);
}

struct Graph *addVertex(struct Graph *graph) {
  graph->V++;
  graph->array = (struct AdjList *)realloc(graph->array,
                                           graph->V * sizeof(struct AdjList));
  graph->array[graph->V - 1].head = NULL;
  return graph;
}

struct Graph *deleteVertex(struct Graph *graph, int vertex) {
  for (int i = 0; i < graph->V; i++) {
    deleteEdge(graph, i, vertex);
  }

  for (int i = vertex; i < graph->V - 1; i++) {
    graph->array[i] = graph->array[i + 1];
  }

  graph->V--;
  graph->array = (struct AdjList *)realloc(graph->array,
                                           graph->V * sizeof(struct AdjList));
  return graph;
}

void printGraph(struct Graph *graph) {
  for (int v = 0; v < graph->V; ++v) {
    struct AdjListNode *pCrawl = graph->array[v].head;
    printf("\n Adjacency list of vertex %d\n head ", v);
    while (pCrawl) {
      printf("-> %d", pCrawl->dest);
      pCrawl = pCrawl->next;
    }
    printf("\n");
  }
}

int main() {
  int V = 5;
  struct Graph *graph = createGraph(V);
  int choice, src, dest, vertex;
  while (1) {
    printf("\nMenu:\n");
    printf("1. Add Edge\n");
    printf("2. Delete Edge\n");
    printf("3. Add Vertex\n");
    printf("4. Delete Vertex\n");
    printf("5. Print Graph\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter source and destination of the edge: ");
      scanf("%d %d", &src, &dest);
      addEdge(graph, src, dest);
      break;
    case 2:
      printf("Enter source and destination of the edge to delete: ");
      scanf("%d %d", &src, &dest);
      deleteEdge(graph, src, dest);
      break;
    case 3:
      graph = addVertex(graph);
      printf("Vertex added. New vertex number is %d\n", graph->V - 1);
      break;
    case 4:
      printf("Enter vertex to delete: ");
      scanf("%d", &vertex);
      graph = deleteVertex(graph, vertex);
      break;
    case 5:
      printGraph(graph);
      break;
    case 6:
      printf("Exiting...\n");
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }
}
