#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};
struct Node *addatEnd(struct Node *start, int data) {
  struct Node *tmp, *p = start;
  tmp = (struct Node *)malloc(sizeof(struct Node));
  tmp->data = data;
  if (start == NULL) {
    tmp->next = NULL;
    tmp->prev = NULL;
    start = tmp;
  } else {
    while (p->next != NULL) {
      p = p->next;
    }
    tmp->next = NULL;
    tmp->prev = p;
    p->next = tmp;
  }
  return start;
}
struct Node *create(struct Node *start) {
  int n, data;
  printf("Enter the number of node :");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Enter the element of %d node :", i + 1);
    scanf("%d", &data);
    start = addatEnd(start, data);
  }
  return start;
}
void display(struct Node *start) {
  struct Node *p;
  printf(" ____  ");
  for (p = start; p != NULL; p = p->next)
    printf("    ____ ___ ____ ");
  printf("\n|");
  printf("    |    ");
  for (p = start; p != NULL; p = p->next) {
    if (p->next == NULL) {
      printf("|    |   |    |");
      break;
    }
    printf("|    |   |    |-->");
  }
  printf("\n|");
  printf("%04hhX|--> |", start);
  for (p = start; p != NULL; p = p->next) {
    if (p->prev == NULL) {
      printf("NULL|%3d|%04hhX|   |", p->data, p->next);
      continue;
    }
    if (p->next == NULL) {
      printf("%04hhX|%3d|NULL| ", p->prev, p->data);
      break;
    }
    if (p->data >= 0 && p->data < 10)
      printf("%04hhX|%3d|%04hhX|   |", p->prev, p->data, p->next);
    else if (p->data >= 10 && p->data < 100)
      printf("%04hhX|%d|%04hhX|   |", p->prev, p->data, p->next);
    else
      printf("%02hhX|%d|%02hhX|   |", p->prev, p->data, p->next);
  }
  printf("\n|");
  printf("____|");
  for (p = start; p != NULL; p = p->next) {
    if (p->prev == NULL) {
      printf("    |____|___|____|");
      continue;
    }
    printf("<--|____|___|____|");
  }
  printf("\n");
  int i = 0;
  while (i < 9) {
    printf(" ");
    i++;
  }
  p = start;
  while (p != NULL) {
    printf("      ");
    printf("%04hhX", p);
    printf("      ");
    p = p->next;
  }
  printf("\n");
}

struct Node *changeAlternate(struct Node *start) {
  struct Node *p = start;
  struct Node *newStart = NULL;
  struct Node *prev = NULL;

  while (p != NULL && p->next != NULL) {
    struct Node *q = p->next;
    p->next = q->next;
    q->next = p;
    q->prev = prev;
    p->prev = q;
    if (prev != NULL) {
      prev->next = q;
    } else {
      newStart = q;
    }
    if (p->next != NULL) {
      p->next->prev = p;
    }

    prev = p;
    p = p->next;
  }
  if (newStart == NULL) {
    newStart = start;
  }

  return newStart;
}

int main() {
  struct Node *start = NULL;
  start = create(start);
  display(start);
  start = changeAlternate(start);
  display(start);
}