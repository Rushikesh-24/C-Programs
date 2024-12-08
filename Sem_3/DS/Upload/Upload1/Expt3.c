#include <stdio.h>
#include <stdlib.h>
struct node {
  int info;
  struct node *link;
};
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
struct node *unionList(struct node *start1, struct node *start2) {
  struct node *result = NULL;
  struct node *temp1 = start1, *temp2 = start2;

  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->info < temp2->info) {
      result = addToEnd(result, temp1->info);
      temp1 = temp1->link;
    } else if (temp1->info > temp2->info) {
      result = addToEnd(result, temp2->info);
      temp2 = temp2->link;
    } else {
      result = addToEnd(result, temp1->info);
      temp1 = temp1->link;
      temp2 = temp2->link;
    }
  }

  while (temp1 != NULL) {
    result = addToEnd(result, temp1->info);
    temp1 = temp1->link;
  }

  while (temp2 != NULL) {
    result = addToEnd(result, temp2->info);
    temp2 = temp2->link;
  }

  return result;
}
struct node *intersection(struct node *start1, struct node *start2) {
  struct node *result = NULL;
  struct node *temp1 = start1, *temp2 = start2;

  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->info < temp2->info) {
      temp1 = temp1->link;
    } else if (temp1->info > temp2->info) {
      temp2 = temp2->link;
    } else {
      result = addToEnd(result, temp1->info);
      temp1 = temp1->link;
      temp2 = temp2->link;
    }
  }

  return result;
}
struct node *difference(struct node *start1, struct node *start2) {
  struct node *result = NULL;
  struct node *temp1 = start1, *temp2 = start2;

  while (temp1 != NULL) {
    while (temp2 != NULL && temp2->info < temp1->info) {
      temp2 = temp2->link;
    }
    if (temp2 == NULL || temp2->info != temp1->info) {
      result = addToEnd(result, temp1->info);
    }

    temp1 = temp1->link;
  }

  return result;
}
void printList(struct node *start) {
  struct node *temp = start;
  while (temp != NULL) {
    if(temp->link == NULL){
        printf(" |%d|NULL|\n", temp->info);
    }
    else
        printf(" |%d|%x| -> ", temp->info, temp->link);
    temp = temp->link;
  }
}
int main() {
  struct node *start1 = NULL, *start2 = NULL;
  int choice;
  printf("List 1\n");
  start1 = Create(start1);
  printf("List 2\n");
  start2 = Create(start2);
  do {
    printf("\n\n1. Union");
    printf("\n2. Intersection");
    printf("\n3. Subtraction (L1-L2)");
    printf("\n4. Subtraction (L2-L1)");
    printf("\n5. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("\nList 1: ");
      printList(start1);
      printf("\nList 2: ");
      printList(start2);
      printf("\nUnion: ");
      printList(unionList(start1, start2));
      break;
    case 2:
      printf("\nList 1: ");
      printList(start1);
      printf("\nList 2: ");
      printList(start2);
      printf("\nIntersection: ");
      printList(intersection(start1, start2));
      break;
    case 3:
      printf("\nList 1: ");
      printList(start1);
      printf("\nList 2: ");
      printList(start2);
      printf("\nSubtraction (L1-L2): ");
      printList(difference(start1, start2));
      break;
    case 4:
      printf("\nList 1: ");
      printList(start1);
      printf("\nList 2: ");
      printList(start2);
      printf("\nSubtraction (L2-L1): ");
      printList(difference(start2, start1));
      break;
    case 5:
      exit(0);
      break;
    default:
      printf("Invalid choice");
      break;
    }
  } while (choice != 5);
  return 0;
}