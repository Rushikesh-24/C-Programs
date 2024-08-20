#include <stdio.h>
#include <stdlib.h>
struct node {
  int info;
  struct node *link;
};

// 11 functions
struct node *addToBeg(struct node *start, int data);
struct node *addToEnd(struct node *start, int data);
void display(struct node *start);
void counting(struct node *start);
void searching(struct node *start, int item);
struct node *Create(struct node *start);
struct node *addAtPost(struct node *start, int data, int pos);
struct node *addAfter(struct node *start, int data, int item);
struct node *addBefore(struct node *start, int data, int item);
struct node *delete(struct node *start, int data);
struct node *reverse(struct node *start);

struct node *reverse(struct node *start) {
  struct node *prev = NULL;
  struct node *current = start;
  struct node *next = NULL;

  while (current != NULL) {
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }

  start = prev;
  return start;
}

struct node *addBefore(struct node *start, int data, int item) {
  struct node *temp, *p = start;
  if (start == NULL) {
    printf("List is empty\n");
    return start;
  }
  if (start->info == item) {
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = start;
    start = temp;
    return start;
  }
  while (p->link != NULL) {
    if (p->link->info == item) {
      temp = (struct node *)malloc(sizeof(struct node));
      temp->info = data;
      temp->link = p->link;
      p->link = temp;
      return start;
    }
    p = p->link;
  }
  printf("Item %d not found\n", item);
  return start;
}
struct node *delete(struct node *start, int data) {
  struct node *temp, *p = start;
  if (start == NULL) {
    printf("List is empty\n");
    return start;
  }
  if (start->info == data) {
    temp = start;
    start = start->link;
    free(temp);
    return start;
  }
  while (p->link != start) {
    if (p->link->info == data) {
      temp = p->link;
      p->link = temp->link;
      free(temp);
      return start;
    }
    p = p->link;
  }
  printf("Element not found\n");
  return start;
}

struct node *addAfter(struct node *start, int data, int item) {
  struct node *temp, *p = start;
  while (p != NULL) {
    if (p->info == item) {
      temp = (struct node *)malloc(sizeof(struct node));
      temp->info = data;
      temp->link = p->link;
      p->link = temp;
      return start;
    }
    p = p->link;
  }
  printf("Item %d not found\n", item);
  return start;
}

struct node *addToBeg(struct node *start, int data) {
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->info = data;
  temp->link = start;
  start = temp;
  return start;
}
struct node *addToEnd(struct node *start, int data) {
  struct node *temp, *p = start;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->info = data;
  temp->link = NULL;
  if (start == NULL) {
    return temp;
  }
  while (p->link != NULL) {
    p = p->link;
  }
  p->link = temp;
  return start;
}
struct node *Create(struct node *start) {
  int data, n, i;
  printf("Enter the number of nodes you want to input: ");
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    printf("Enter the data to be entered: ");
    scanf("%d", &data);
    start = addToEnd(start, data);
  }
  return start;
}
void display(struct node *start) {
  struct node *temp = start;
  while (temp != NULL) {
    if (temp->link == NULL) {
      printf(" |%d|NULL|\n", temp->info);
    } else
      printf(" |%d|%x| -> ", temp->info, temp->link);
    temp = temp->link;
  }
}
void counting(struct node *start) {
  struct node *p;
  int cnt = 0;
  if (start == NULL) {
    printf("\nList is empty");
    return;
  }
  p = start;
  while (p != NULL) {
    cnt++;
    p = p->link;
  }
  printf("Number of nodes are: %d\n", cnt);
}
void searching(struct node *start, int item) {
  struct node *p;
  int pos = 1;
  if (start == NULL) {
    printf("\nList is empty");
    return;
  }
  p = start;
  while (p != NULL) {
    if (p->info == item) {
      printf("Item %d found at position %d\n", item, pos);
      return;
    }
    p = p->link;
    pos++;
  }
  printf("Item %d not found\n", item);
}
struct node *addAtPost(struct node *start, int data, int pos) {
  struct node *temp, *p = start;
  int i;
  if (pos == 1) {
    start = addToBeg(start, data);
    return start;
  }
  for (i = 1; i < pos - 1 && p != NULL; i++) {
    p = p->link;
  }
  if (p == NULL) {
    printf("Less item than position %d\n", i);
    return start;
  } else {
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = p->link;
    p->link = temp;
    return start;
  }
  return start;
}
int main() {
  struct node *start = NULL;
  int choice, data, item, pos;

  do {
    printf("\n\n\n");
    printf("1. Create\n");
    printf("2. Add to Beginning\n");
    printf("3. Add to End\n");
    printf("4. Add After\n");
    printf("5. Add Before\n");
    printf("6. Delete\n");
    printf("7. Reverse\n");
    printf("8. Display\n");
    printf("9. Count\n");
    printf("10. Search\n");
    printf("11. Add at Position\n");
    printf("12. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      start = Create(start);
      display(start);
      break;
    case 2:
      printf("Enter the element to be inserted: ");
      scanf("%d", &data);
      start = addToBeg(start, data);
      display(start);
      break;
    case 3:
      printf("Enter the element to be inserted: ");
      scanf("%d", &data);
      start = addToEnd(start, data);
      display(start);
      break;
    case 4:
      printf("Enter the element to be inserted: ");
      scanf("%d", &data);
      printf("Enter the element after which to insert: ");
      scanf("%d", &item);
      start = addAfter(start, data, item);
      display(start);
      break;
    case 5:
      printf("Enter the element to be inserted: ");
      scanf("%d", &data);
      printf("Enter the element before which to insert: ");
      scanf("%d", &item);
      start = addBefore(start, data, item);
      display(start);
      break;
    case 6:
      printf("Enter the element to be deleted: ");
      scanf("%d", &data);
      start = delete (start, data);
      display(start);
      break;
    case 7:
      start = reverse(start);
      display(start);
      break;
    case 8:
      display(start);
      break;
    case 9:
      counting(start);
      break;
    case 10:
      printf("Enter the element to be searched: ");
      scanf("%d", &data);
      searching(start, data);
      break;
    case 11:
      printf("Enter the element to be inserted: ");
      scanf("%d", &data);
      printf("Enter the position at which to insert: ");
      scanf("%d", &pos);
      start = addAtPost(start, data, pos);
      display(start);
      break;
    case 12:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice! Please enter a valid option.\n");
    }
  } while (choice != 12);

  return 0;
}