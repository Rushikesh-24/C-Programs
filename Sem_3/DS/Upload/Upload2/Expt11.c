#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
  int key;
  struct Node *next;
} Node;

int hash(int key) { return key % TABLE_SIZE; }

int linearProbing(int key, int i) { return (hash(key) + i) % TABLE_SIZE; }

int quadraticProbing(int key, int i) {
  return (hash(key) + i * i) % TABLE_SIZE;
}

int doubleHashing(int key, int i) {
  int h1 = hash(key);
  int h2 = 7 - (key % 7);
  return (h1 + i * h2) % TABLE_SIZE;
}

void insertLinearProbing(int table[], int key) {
  int i = 0;
  while (table[linearProbing(key, i)] != -1) {
    i++;
  }
  table[linearProbing(key, i)] = key;
}

void insertQuadraticProbing(int table[], int key) {
  int i = 0;
  while (table[quadraticProbing(key, i)] != -1) {
    i++;
  }
  table[quadraticProbing(key, i)] = key;
}

void insertDoubleHashing(int table[], int key) {
  int i = 0;
  while (table[doubleHashing(key, i)] != -1) {
    i++;
  }
  table[doubleHashing(key, i)] = key;
}

void insertChaining(Node *table[], int key) {
  int index = hash(key);
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = key;
  newNode->next = table[index];
  table[index] = newNode;
}

void printTable(int table[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table[i] != -1) {
      printf("%d ", table[i]);
    } else {
      printf("NULL ");
    }
  }
  printf("\n");
}

void printChainingTable(Node *table[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Node *temp = table[i];
    printf("[%d]: ", i);
    while (temp != NULL) {
      printf("%d -> ", temp->key);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main() {
  int linearTable[TABLE_SIZE];
  int quadraticTable[TABLE_SIZE];
  int doubleHashTable[TABLE_SIZE];
  Node *chainingTable[TABLE_SIZE];

  for (int i = 0; i < TABLE_SIZE; i++) {
    linearTable[i] = -1;
    quadraticTable[i] = -1;
    doubleHashTable[i] = -1;
    chainingTable[i] = NULL;
  }

  int n;
  printf("Enter the number of keys: ");
  scanf("%d", &n);

  int keys[n];
  printf("Enter the keys:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &keys[i]);
  }

  for (int i = 0; i < n; i++) {
    insertLinearProbing(linearTable, keys[i]);
    insertQuadraticProbing(quadraticTable, keys[i]);
    insertDoubleHashing(doubleHashTable, keys[i]);
    insertChaining(chainingTable, keys[i]);
  }
  int choice;
  do {
    printf("\nMenu:\n");
    printf("1. Insert a key\n");
    printf("2. Print tables\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int key;
      printf("Enter the key to insert: ");
      scanf("%d", &key);
      insertLinearProbing(linearTable, key);
      insertQuadraticProbing(quadraticTable, key);
      insertDoubleHashing(doubleHashTable, key);
      insertChaining(chainingTable, key);
      break;
    }
    case 2:
      printf("Linear Probing:\n");
      printTable(linearTable);

      printf("Quadratic Probing:\n");
      printTable(quadraticTable);

      printf("Double Hashing:\n");
      printTable(doubleHashTable);

      printf("Chaining:\n");
      printChainingTable(chainingTable);
      break;
    case 3:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 3);

  return 0;
}