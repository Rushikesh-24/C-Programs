#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *lchild;
  struct node *rchild;
  int info;
  int balance;
};
void inorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->lchild);
  printf("%d(%d) ", root->info, root->balance);
  inorder(root->rchild);
}
struct node *rightrotate(struct node *pptr) {
  struct node *aptr = pptr->lchild;
  pptr->lchild = aptr->rchild;
  aptr->rchild = pptr;
  return aptr;
}
struct node *leftrotate(struct node *pptr) {
  struct node *aptr = pptr->rchild;
  pptr->rchild = aptr->lchild;
  aptr->lchild = pptr;
  return aptr;
}
struct node *insert_lbal(struct node *ptr) {
  struct node *aptr = ptr->lchild;
  if (ptr->balance == 1) {
    printf("P%d: LC1\n", ptr->info);
    ptr->balance = 0;
    aptr->balance = 0;
    ptr = rightrotate(ptr);
  } else {
    struct node *bptr = aptr->rchild;
    switch (bptr->balance) {
    case 0:
      printf("P%d: LC2c\n", ptr->info);
      ptr->balance = 0;
      aptr->balance = 0;
      break;
    case -1:
      printf("P%d: LC2a\n", ptr->info);
      ptr->balance = 0;
      aptr->balance = 1;
      break;
    case 1:
      printf("P%d: LC2b\n", ptr->info);
      ptr->balance = -1;
      aptr->balance = 0;
      break;
    }
    bptr->balance = 0;
    ptr->lchild = rightrotate(aptr);
    ptr = rightrotate(ptr);
  }
  return ptr;
}

struct node *insert_lcheck(struct node *ptr, int *taller) {
  switch (ptr->balance) {
  case 0:
    printf("P%d: LA\n", ptr->info);
    ptr->balance = 1;
    break;
  case -1:
    printf("P%d: LB\n", ptr->info);
    ptr->balance = 0;
    *taller = false;
    break;
  case 1:
    ptr = insert_lbal(ptr);
    *taller = true;
    break;
  }
  return ptr;
}

struct node *insert_rbal(struct node *ptr) {
  struct node *aptr = ptr->rchild;
  if (ptr->balance == -1) {
    printf("P%d: RC1\n", ptr->info);
    ptr->balance = 0;
    aptr->balance = 0;
    ptr = leftrotate(ptr);
  } else {
    struct node *bptr = aptr->lchild;
    switch (bptr->balance) {
    case 0:
      printf("P%d: RC2c\n", ptr->info);
      ptr->balance = 0;
      aptr->balance = 0;
      break;
    case -1:
      printf("P%d: RC2a\n", ptr->info);
      ptr->balance = 1;
      aptr->balance = 0;
      break;
    case 1:
      printf("P%d: RC2b\n", ptr->info);
      ptr->balance = 0;
      aptr->balance = -1;
      break;
    }
    bptr->balance = 0;
    ptr->rchild = leftrotate(aptr);
    ptr = leftrotate(ptr);
  }
  return ptr;
}

struct node *insert_rcheck(struct node *ptr, int *taller) {
  switch (ptr->balance) {
  case 0:
    printf("P%d: RA\n", ptr->info);
    ptr->balance = -1;
    break;
  case 1:
    printf("P%d: RB\n", ptr->info);
    ptr->balance = 0;
    *taller = false;
    break;
  case -1:
    ptr = insert_rbal(ptr);
    *taller = true;
    break;
  }
  return ptr;
}

struct node *insert(struct node *pptr, int ikey) {
  static int taller;
  if (pptr == NULL) {
    pptr = (struct node *)malloc(sizeof(struct node));
    pptr->info = ikey;
    pptr->lchild = NULL;
    pptr->rchild = NULL;
    pptr->balance = 0;
    taller = true;
  } else if (ikey < pptr->info) {
    pptr->lchild = insert(pptr->lchild, ikey);
    if (taller) {
      pptr = insert_lcheck(pptr, &taller);
    }
  } else if (ikey > pptr->info) {
    pptr->rchild = insert(pptr->rchild, ikey);
    if (taller) {
      pptr = insert_rcheck(pptr, &taller);
    }
  } else {
    printf("DUPLICATES\n");
    taller = false;
  }
  return pptr;
}

// Deletion
struct node *del_RightBalance(struct node *pptr, bool *pshorter);
struct node *del_LeftBalance(struct node *pptr, bool *pshorter);
struct node *del_left_check(struct node *pptr, bool *pshorter);
struct node *del_right_check(struct node *pptr, bool *pshorter);

struct node *del(struct node *pptr, int dkey) {
  static bool shorter;
  struct node *tmp, *succ;
  if (pptr == NULL) {
    printf("Node not found\n");
    shorter = false;
    return pptr;
  } else if (dkey < pptr->info) {
    pptr->lchild = del(pptr->lchild, dkey);
    if (shorter) {
      pptr = del_left_check(pptr, &shorter);
    }
  } else if (dkey > pptr->info) {
    pptr->rchild = del(pptr->rchild, dkey);
    if (shorter) {
      pptr = del_right_check(pptr, &shorter);
    }
  } else {
    if (pptr->lchild != NULL && pptr->rchild != NULL) {
      succ = pptr->rchild;
      while (succ->lchild != NULL) {
        succ = succ->lchild;
      }
      pptr->info = succ->info;
      pptr->rchild = del(pptr->rchild, succ->info);
      if (shorter) {
        pptr = del_right_check(pptr, &shorter);
      }
    } else {
      tmp = pptr;
      if (pptr->lchild != NULL) {
        pptr = pptr->lchild;
      } else if (pptr->rchild != NULL) {
        pptr = pptr->rchild;
      } else {
        pptr = NULL;
      }
      free(tmp);
      shorter = true;
    }
  }
  return pptr;
}

struct node *del_RightBalance(struct node *pptr, bool *pshorter) {
  struct node *aptr, *bptr;
  aptr = pptr->rchild;
  if (aptr->balance == 0) {
    printf("P%d: RC1\n", pptr->info);
    pptr->balance = -1;
    aptr->balance = 1;
    *pshorter = false;
    pptr = leftrotate(pptr);
  } else if (aptr->balance == -1) {
    printf("P%d: RC2\n", pptr->info);
    pptr->balance = 0;
    aptr->balance = 0;
    pptr = leftrotate(pptr);
  } else {
    bptr = aptr->lchild;
    switch (bptr->balance) {
    case 0:
      printf("P%d: RC3a\n", pptr->info);
      pptr->balance = 0;
      aptr->balance = 0;
      break;
    case 1:
      printf("P%d: RC3b\n", pptr->info);
      pptr->balance = 0;
      aptr->balance = -1;
      break;
    case -1:
      printf("P%d: RC3c\n", pptr->info);
      pptr->balance = 1;
      aptr->balance = 0;
      break;
    }
    bptr->balance = 0;
    pptr->rchild = rightrotate(aptr);
    pptr = leftrotate(pptr);
  }
  return pptr;
}

struct node *del_LeftBalance(struct node *pptr, bool *pshorter) {
  struct node *aptr, *bptr;
  aptr = pptr->lchild;
  if (aptr->balance == 0) {
    printf("P%d: LC1\n", pptr->info);
    pptr->balance = 1;
    aptr->balance = -1;
    *pshorter = false;
    pptr = rightrotate(pptr);
  } else if (aptr->balance == 1) {
    printf("P%d: LC2\n", pptr->info);
    pptr->balance = 0;
    aptr->balance = 0;
    pptr = rightrotate(pptr);
  } else {
    bptr = aptr->rchild;
    switch (bptr->balance) {
    case 0:
      printf("P%d: LC3a\n", pptr->info);
      pptr->balance = 0;
      aptr->balance = 0;
      break;
    case 1:
      printf("P%d: LC3b\n", pptr->info);
      pptr->balance = -1;
      aptr->balance = 0;
      break;
    case -1:
      printf("P%d: LC3c\n", pptr->info);
      pptr->balance = 0;
      aptr->balance = 1;
      break;
    }
    bptr->balance = 0;
    pptr->lchild = leftrotate(aptr);
    pptr = rightrotate(pptr);
  }
  return pptr;
}

struct node *del_left_check(struct node *pptr, bool *pshorter) {
  switch (pptr->balance) {
  case 0:
    printf("P%d: LA\n", pptr->info);
    pptr->balance = -1;
    *pshorter = false;
    break;
  case 1:
    printf("P%d: LB\n", pptr->info);
    pptr->balance = 0;
    break;
  case -1:
    pptr = del_RightBalance(pptr, pshorter);
    break;
  }
  return pptr;
}

struct node *del_right_check(struct node *pptr, bool *pshorter) {
  switch (pptr->balance) {
  case 0:
    printf("P%d: RA\n", pptr->info);
    pptr->balance = 1;
    *pshorter = false;
    break;
  case -1:
    printf("P%d: RB\n", pptr->info);
    pptr->balance = 0;
    break;
  case 1:
    pptr = del_LeftBalance(pptr, pshorter);
    break;
  }
  return pptr;
}
void levelOrder(struct node *root, int arr[], int size) {
  if (root == NULL)
    return;
  struct node **queue = (struct node **)malloc(size * sizeof(struct node *));
  int front = 0, rear = 0;
  queue[rear++] = root;
  int n = 0;
  while (front < rear && n < size) {
    struct node *current = queue[front++];
    arr[n++] = current ? current->info : -1;
    if (current) {
      queue[rear++] = current->lchild;
      queue[rear++] = current->rchild;
    }
  }
  while (n < size) {
    arr[n++] = -1;
  }
  free(queue);
}
int height(struct node *ptr) {
  if (ptr == NULL)
    return 0;
  int h_left = height(ptr->lchild);
  int h_right = height(ptr->rchild);
  return (h_left > h_right ? h_left : h_right) + 1;
}
int *createArray(struct node *root, int *ptr, int i) {
  if (root == NULL) {
    *(ptr + i * 2) = -1;
    *(ptr + i * 2 + 1) = 0;
    return ptr;
  }
  *(ptr + i * 2) = root->info;
  *(ptr + i * 2 + 1) = root->balance;
  ptr = createArray(root->lchild, ptr, i * 2 + 1);
  ptr = createArray(root->rchild, ptr, i * 2 + 2);
  return ptr;
}

void printStructuredTree(struct node *root) {
  if (root == NULL)
    return;

  int heightOfTree = height(root);
  int maxNodes = pow(2, heightOfTree + 1) - 1;
  int *arr = (int *)malloc(maxNodes * 2 * sizeof(int));
  for (int i = 0; i < maxNodes * 2; i++) {
    arr[i] = -1;
  }
  createArray(root, arr, 0);

  int n = 0;
  for (int level = 0; level <= heightOfTree; level++) {
    int nodesInLevel = pow(2, level);
    int spaceBetweenNodes = pow(2, heightOfTree - level + 1) - 1;
    int initialSpace = pow(2, heightOfTree - level) - 1;

    for (int i = 0; i < initialSpace; i++)
      printf(" ");
    for (int i = 0; i < nodesInLevel && n < maxNodes; i++) {
      if (arr[n * 2] != -1) {
        printf("%d(%d)", arr[n * 2], arr[n * 2 + 1]);
        if (i < nodesInLevel - 1) {
          for (int j = 0; j < spaceBetweenNodes; j++)
            printf(" ");
        }
      } else {
        printf(" ");
        if (i < nodesInLevel - 1) {
          for (int j = 0; j < spaceBetweenNodes; j++)
            printf(" ");
        }
      }
      n++;
    }
    printf("\n");
  }
  free(arr);
}

int main() {
  struct node *root = NULL;
  int keys[] = {75, 59, 29, 33, 68, 65, 50, 47, 88, 20, 72, 35, 99, 51, 62, 49};
  int numKeys = sizeof(keys) / sizeof(keys[0]);
printf("Insertion\n");
  for (int i = 0; i < numKeys; i++) {
    root = insert(root, keys[i]);
    printf("\nStructured Tree Representation after inserting %d:\n", keys[i]);
    printStructuredTree(root);
  }
  printf("Deletion\n");
  for (int i = 0; i < numKeys; i++) {
    root = del(root, keys[i]);
    printf("\nStructured Tree Representation after deleting %d:\n", keys[i]);
    printStructuredTree(root);
  }
printf("NULL\n");
  return 0;
}
