#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
#define finished 2
int adj[MAX][MAX];
int state[MAX];
int n;
int m = 0;
int d[MAX], f[MAX];
struct Vertex {
  int info;
  struct Vertex *nextVertex;
  struct Edge *firstEdge;
};

struct Edge {
  struct Vertex *destVertex;
  struct Edge *nextEdge;
};

struct Vertex *start = NULL;
void disp() {
  char c[8];
  for (int i = 0; i <= 7; i++) {
    printf("%d\t", i);
  }
  printf("\n");
  for (int i = 0; i <= 7; i++) {
    if (state[i] == initial)
      c[i] = 'i';
    else if (state[i] == waiting)
      c[i] = 'w';
    else
      c[i] = 'f';
  }
  for (int i = 0; i <= 7; i++) {
    printf("%c\t", c[i]);
  }
}
void create_graph() {
  int i, max_edges, origin, destin;
  printf("Enter number of vertices: ");
  scanf("%d", &n);
  max_edges = n * (n - 1);
  for (i = 1; i <= max_edges; i++) {
    printf("Enter edge %d (0 0 to quit): ", i);
    scanf("%d %d", &origin, &destin);
    origin--;
    destin--;
    if ((origin == -1) && (destin == -1))
      break;
    if (origin >= n || destin >= n || origin < 0 || destin < 0) {
      printf("Invalid edge!\n");
      i--;
    } else {
      adj[origin][destin] = 1;
    }
  }
}
int BFStrav[MAX];
int front1 = -1, rear1 = -1;
void insert_queue1(int vertex) {
  if (rear1 == MAX - 1) {
    printf("Queue Overflow\n");
    return;
  }
  if (front1 == -1)
    front1 = 0;
  rear1++;
  BFStrav[rear1] = vertex;
}
void display1() {
  int i;
  printf("\nTraversal: ");
  if (front1 == -1 || front1 == rear1 + 1) {
    printf("\nEMPTPY");
    return;
  }
  for (int i = front1; i <= rear1; i++) {
    printf("%d ", BFStrav[i]);
  }
}
int queue[MAX];
int front = -1, rear = -1;
void insert_queue(int vertex) {
  if (rear == MAX - 1) {
    printf("Queue Overflow\n");
    return;
  }
  if (front == -1)
    front = 0;
  rear++;
  queue[rear] = vertex;
}
int delete_queue() {
  int item;
  if (front == -1 || front > rear) {
    printf("Queue Underflow\n");
    exit(1);
  }
  item = queue[front];
  printf("\n");
  disp();
  printf("\nDelete(%d) : Visit(%d)", item, item);
  front = front + 1;
  return item;
}
void display() {
  int i;

  printf("\nQueue: ");

  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}
void BFS(int v) {
  int i;
  printf("\n");
  disp();
  printf("\n");
  printf("Insert(%d) ", v);
  insert_queue(v);
  display();
  state[v] = waiting;
  while (front != -1 && front <= rear) {
    v = delete_queue();
    insert_queue1(v);
    display1();
    printf("\n");
    state[v] = visited;
    for (i = 0; i < n; i++) {
      if (adj[v][i] == 1 && state[i] == initial) {
        printf("Insert(%d): ", i);
        insert_queue(i);
        state[i] = waiting;
      }
    }
    display();
  }
  printf("\n");
}
void BFS_Traversal() {
  int v;
  for (v = 0; v < n; v++)
    state[v] = initial;
  v = 0;
  BFS(v);
}
int d[MAX];
int time;
int f[MAX];
void DFS(int v) {
  int i, x;
  time++;
  d[v] = time;
  insert_queue1(v);
  state[v] = visited;

  for (int i = 0; i < n; i++) {
    if (adj[v][i] == 1 && state[i] == initial) {
      m = m + 4;

      printf("%d is AD to %d and IN. Call DFS(%d) : Visit(%d)\n", i, v, i, i);
      for (int j = 0; j < m; j++)
        printf(" ");
      DFS(i);
    }
  }
  for (int j = 0; j < m; j++)
    printf(" ");
  printf("Vertex %d Finished\n", v);
  m -= 4;

  state[v] = finished;
  f[v] = ++time;
}
void DFS_traversal(int n) {
  int v = 0, x, m = 0;
  for (v = 0; v < n; v++)
    state[v] = initial;
  v = 0;
  printf("Call DFS(%d) : Visit(%d)\n", n, n);
  for (int j = 0; j < m; j++)
    printf(" ");
  DFS(n);

  for (v = 0; v < n; v++) {

    if (state[v] == initial) {

      printf("%d is AD and IN. Call DFS(%d) : Visit(%d)\n", v, v, v);
      for (int j = 0; j < m; j++)
        printf(" ");
      DFS(v);
      m += 4;
    }
    x = v;
  }

  printf("\n");
}
int top = -1;
int stack[MAX];
void push(int v) {
  if (top == MAX - 1) {
    printf("Stack Overflow\n");
    return;
  }
  top++;
  stack[top] = v;
}
int isEmpty_stack() { return top == -1; }
int pop() {
  if (top == -1) {
    printf("Queue Underflow\n");
    exit(1);
  }
  int item = stack[top];
  top--;
  return item;
}
void res() {
  for (int i = 0; i < n; i++) {
    state[i] = initial;
  }
}
void display3() {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%4d", adj[i][j]);
    printf("\n");
  }
}
void display_stack() {
  printf("Current Stack: ");
  for (int i = 0; i <= top; i++) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}
void DFSnrec(int v) {
  int i, k = 0, t[n];
  printf("Push %d\n", v);
  push(v);
  display_stack();

  while (!isEmpty_stack()) {
    v = pop();
    if (state[v] == initial) {
      printf("Pop %d, Visit %d\n", v, v);
      t[k++] = v;
      state[v] = visited;
    }
    printf("Traversal: ");
    for (i = 0; i < k; i++) {
      if (state[i] == visited)
        printf("%d ", t[i]);
    }
    printf("\n");

    for (i = n - 1; i >= 0; i--) {
      if (adj[v][i] == 1 && state[i] == initial) {
        printf("Push %d\n", i);
        push(i);
      }
    }
    display_stack();
  }
  printf("\n");
}
void DF_Traversal_nrec() {
  int v;
  res();

  printf("Enter starting vertex for Depth First Search : \n");
  scanf("%d", &v);
  DFS(v);
  for (v = 0; v < n; v++)

    if (state[v] == initial)
      DFSnrec(v);
}

int main() {
  int v;
  int choice;
  while (1) {
    printf("1. Create Graph\n2. Display Adjacency Matrix\n3. BFS Traversal\n4. "
           "Non-rec DFS Traversal\n5. Recursive DFS Traversal\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      create_graph();
      break;
    case 2:
      printf("Adjacency Matrix:\n");
      display3();
      break;
    case 3:
      printf("BFS Traversal:\n");
      BFS_Traversal();
      break;
    case 4:
      printf("Enter starting vertex for Non-rec DFS: ");
      scanf("%d", &v);
      res();
      DFSnrec(v);
      break;
    case 5:
      printf("Enter starting vertex for rec DFS: ");
      scanf("%d", &v);
      res();
      DFS_traversal(v);
      printf("\n");
      break;
    case 6:
      exit(0);
    }
  }
  return 0;
}