#include <stdio.h>
#include <stdlib.h>
#define MAX 10

enum type_of_record { EMPTY, DELETED, OCCUPIED };

struct Record {
  int info;
  enum type_of_record status;
};

int hash(int key) { return (key % MAX); }

int search(int key, struct Record table[]) {
  int i, h, location;
  h = hash(key);
  location = h;
  for (i = 1; i != MAX - 1; i++) {

    if (table[location].status == EMPTY)

      return -1;

    if (table[location].info == key)
      return location;
    location = (h + i) % MAX;
  }
  return -1;
}

void insert(int emprec, struct Record table[]) {
  int i, location, h;
  int key = emprec;
  h = hash(key);
  location = h;
  for (i = 1; i != MAX - 1; i++) {
    if (table[location].status == EMPTY || table[location].status == DELETED) {
      table[location].info = emprec;
      table[location].status = OCCUPIED;
      printf("Record inserted\n\n");
      return;
    }
    if (table[location].info == key) {
      printf("Duplicate key\n\n");
      return;
    }
    location = (h + i) % MAX;
  }
  printf("Record can't be inserted : Table overFlow\n\n");
}

void del(int key, struct Record table[]) {
  int location = search(key, table);
  if (location == -1)
    printf("Key not found\n");
  else
    table[location].status = DELETED;
}

void display(struct Record table[]) {
  int i;
  for (i = 0; i < MAX; i++) {
    if (i < 10)
      printf("[0%d] : ", i);
    else
      printf("[%d] : ", i);
    if (table[i].status == OCCUPIED) {
      printf("Occupied : %d\n", 
             table[i].info);
    } else if (table[i].status == DELETED) {
      printf("Deleted\n");
    } else {
      printf("Empty\n");
    }
  }
}

int main() {
  struct Record table[MAX];
  int i, key, choice ,info;
  for (i = 0; i <= MAX - 1; i++)
    table[i].status = EMPTY;
  while (1) {
    printf("1. Insert a record\n");
    printf("2. Search a record\n");
    printf("3. Delete a record\n");
    printf("4. Display table\n");
    printf("5. Exit\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter empid ");
      scanf("%d", &info);
      insert(info, table);
      break;
    case 2:
      printf("Enter a key to be searched : ");
      scanf("%d", &key);
      i = search(key, table);
      if (i == -1)
        printf("Key not found\n");
      else
        printf("Key found at index %d\n", i);
      break;
    case 3:
      printf("Enter a key to be deleted\n");
      scanf("%d", &key);
      del(key, table);
      break;
    case 4:
      display(table);
      break;
    case 5:
      exit(1);
    }
  }
}


