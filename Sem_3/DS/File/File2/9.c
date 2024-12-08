#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
struct node *queue[SIZE];
struct node {
  struct node *lchild;
  struct node *rchild;
  int info;
  int balance;
};
struct node *insert_left_balance(struct node *ptr) {
  struct node *a, *b;

  a = ptr->lchild;
  if (a->balance == 1) {
    printf("LL at %d\n", ptr->info);
    ptr->lchild = a->rchild; // LL
    a->rchild = ptr;
    ptr->balance = 0;
    a->balance = 0;
    ptr = a;
  } else {
    printf("LR at %d\n", ptr->info);
    b = a->rchild; // LR
    a->rchild = b->lchild;
    b->lchild = a;
    ptr->lchild = b->rchild;
    b->rchild = ptr;

    switch (b->balance) {
    case 1:
      ptr->balance = -1;
      a->balance = 0;
      break;
    case 0:
      ptr->balance = 0;
      a->balance = 0;
      break;
    case -1:
      ptr->balance = 0;
      a->balance = 1;
      break;
    }
    b->balance = 0;
    ptr = b;
  }
  return ptr;
}

struct node *insert_right_balance(struct node *ptr) {
  struct node *a, *b;

  a = ptr->rchild;
  if (a->balance == -1) {
    printf("RR at %d\n", ptr->info);
    ptr->rchild = a->lchild; // RR
    a->lchild = ptr;
    ptr->balance = 0;
    a->balance = 0;
    ptr = a;
  } else {
    printf("RL at %d\n", ptr->info);
    b = a->lchild; // RL
    a->lchild = b->rchild;
    b->rchild = a;
    ptr->rchild = b->lchild;
    b->lchild = ptr;

    switch (b->balance) {
    case -1:
      ptr->balance = 1;
      a->balance = 0;
      break;
    case 0:
      ptr->balance = 0;
      a->balance = 0;
      break;
    case 1:
      ptr->balance = 0;
      a->balance = -1;
      break;
    }
    b->balance = 0;
    ptr = b;
  }
  return ptr;
}

struct node *insert_right_child(struct node *ptr, bool *Taller) {
  switch (ptr->balance) {
  case 0:
    ptr->balance = -1;
    *Taller = true;
    break;
  case -1:
    ptr = insert_right_balance(ptr);
    *Taller = true;
    break;
  case 1:
    ptr->balance = 0;
    *Taller = false;
  }
  return ptr;
}
struct node *insert_left_child(struct node *ptr, bool *Taller) {
  switch (ptr->balance) {
  case 0:
    ptr->balance = 1;
    *Taller = true;
    break;
  case -1:
    ptr->balance = 0;
    *Taller = false;
    break;
  case 1:
    ptr = insert_left_balance(ptr);
    *Taller = false;
  }
  return ptr;
}
struct node *insert(struct node *ptr, int ikey) {
  static bool Taller = false;
  if (ptr == NULL) {
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->info = ikey;
    ptr->rchild = ptr->lchild = NULL;
    ptr->balance = 0;
    Taller = true;
  } else if (ikey < ptr->info) {
    ptr->lchild = insert(ptr->lchild, ikey);
    if (Taller) {
      ptr = insert_left_child(ptr, &Taller);
    }
  } else if (ikey > ptr->info) {
    ptr->rchild = insert(ptr->rchild, ikey);
    if (Taller) {
      ptr = insert_right_child(ptr, &Taller);
    }
  } else {
    printf("Dublicate\n");
    Taller = false;
  }
  return ptr;
}
int height(struct node *root) {
  if (root == NULL)
    return 0;
  int left_height = height(root->lchild);
  int right_height = height(root->rchild);
  return 1 + (left_height > right_height ? left_height : right_height);
}

struct node *delete_left_balance(struct node *ptr, bool *Shorter) {
    struct node *a, *b;

    if (ptr == NULL) return NULL; 

    switch (ptr->balance) {
    case 1:
        ptr->balance = 0;
        break;
    case 0:
        ptr->balance = -1;
        *Shorter = false;
        break;
    case -1:
        a = ptr->rchild;
        if (a == NULL) return ptr; 
        
        if (a->balance <= 0) {
            printf("RR at %d\n", ptr->info);
            ptr->rchild = a->lchild;
            a->lchild = ptr;
            if (a->balance == 0) {
                ptr->balance = -1;
                a->balance = 1;
                *Shorter = false;
            } else {
                ptr->balance = 0;
                a->balance = 0;
            }
            ptr = a;
        } else {
            printf("RL at %d\n", ptr->info);
            b = a->lchild;
            if (b == NULL) return ptr; 
            
            a->lchild = b->rchild;
            b->rchild = a;
            ptr->rchild = b->lchild;
            b->lchild = ptr;
            
            switch (b->balance) {
            case 1:
                ptr->balance = 0;
                a->balance = -1;
                break;
            case 0:
                ptr->balance = 0;
                a->balance = 0;
                break;
            case -1:
                ptr->balance = 1;
                a->balance = 0;
                break;
            }
            b->balance = 0;
            ptr = b;
        }
    }
    return ptr;
}
struct node *delete_right_balance(struct node *ptr, bool *Shorter) {
    struct node *a, *b;

    if (ptr == NULL) return NULL;

    switch (ptr->balance) {
    case -1:
        ptr->balance = 0;
        break;
    case 0:
        ptr->balance = 1;
        *Shorter = false;
        break;
    case 1:
        a = ptr->lchild;
        if (a == NULL) return ptr; 
        
        if (a->balance >= 0) {
            printf("LL at %d\n", ptr->info);
            ptr->lchild = a->rchild;
            a->rchild = ptr;
            if (a->balance == 0) {
                ptr->balance = 1;
                a->balance = -1;
                *Shorter = false;
            } else {
                ptr->balance = 0;
                a->balance = 0;
            }
            ptr = a;
        } else {
            printf("LR at %d\n", ptr->info);
            b = a->rchild;
            if (b == NULL) return ptr; 
            
            a->rchild = b->lchild;
            b->lchild = a;
            ptr->lchild = b->rchild;
            b->rchild = ptr;
            
            switch (b->balance) {
            case -1:
                ptr->balance = 0;
                a->balance = 1;
                break;
            case 0:
                ptr->balance = 0;
                a->balance = 0;
                break;
            case 1:
                ptr->balance = -1;
                a->balance = 0;
                break;
            }
            b->balance = 0;
            ptr = b;
        }
    }
    return ptr;
}
struct node *delete(struct node *ptr, int dkey, bool *Shorter, bool *Success) {
    struct node *dptr, *succ, *parent_succ;

    if (ptr == NULL) {
        *Shorter = false;
        *Success = false;
        return NULL;
    }

    if (dkey < ptr->info) {
        ptr->lchild = delete(ptr->lchild, dkey, Shorter, Success);
        if (*Shorter)
            ptr = delete_right_balance(ptr, Shorter);
    } else if (dkey > ptr->info) {
        ptr->rchild = delete(ptr->rchild, dkey, Shorter, Success);
        if (*Shorter)
            ptr = delete_left_balance(ptr, Shorter);
    } else {
        *Success = true;
        dptr = ptr;
        
        if (ptr->rchild == NULL) {
            ptr = ptr->lchild;
            *Shorter = true;
            free(dptr);
        } else if (ptr->lchild == NULL) {
            ptr = ptr->rchild;
            *Shorter = true;
            free(dptr);
        } else {
            parent_succ = ptr;
            succ = ptr->rchild;
            while (succ->lchild != NULL) {
                parent_succ = succ;
                succ = succ->lchild;
            }
            ptr->info = succ->info;
            if (parent_succ == ptr) {
                parent_succ->rchild = succ->rchild;
                *Shorter = true;
                ptr = delete_left_balance(ptr, Shorter);
            } else {
                parent_succ->lchild = succ->rchild;
                *Shorter = true;
                ptr = delete(ptr, dkey, Shorter, Success);
            }
            free(succ);
        }
    }
    return ptr;
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

void printTree(int arr[], int size, int levels) {
    int n = 0;
    for (int level = 0; level <= levels; level++) {
        int nodesInLevel = pow(2, level);
        int spaceBetweenNodes = pow(2, levels - level + 1) - 1;
        int initialSpace = pow(2, levels - level) - 1;
        for (int i = 0; i < initialSpace; i++)
            printf(" ");
        for (int i = 0; i < nodesInLevel && n < size; i++) {
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
        printf("\n\n");
    }
}

int main() { 
    struct node *root = NULL; 
    int values[] = {21, 26, 30, 9, 4, 14, 28, 18, 15, 10};
    int size = sizeof(values) / sizeof(values[0]);
    for(int i = 0; i < size; i++) {
        printf("Insert (%d)\n", values[i]);
        root = insert(root, values[i]);
        int maxNodes = pow(2, height(root) + 1) - 1;
        int *treeArray = (int *)malloc(maxNodes * 2 * sizeof(int));
        for (int j = 0; j < maxNodes * 2; j++)
             treeArray[j] = -1;
        createArray(root, treeArray, 0);
        printTree(treeArray, maxNodes, height(root));
        free(treeArray);
    }
    for(int i = 0; i < size; i++) {
        printf("Delete (%d)\n", values[i]);
        bool Shorter = false, Success = false;
        root = delete(root, values[i], &Shorter, &Success);
        int maxNodes = pow(2, height(root) + 1) - 1;
        int *treeArray = (int *)malloc(maxNodes * 2 * sizeof(int));
        for (int j = 0; j < maxNodes * 2; j++)
             treeArray[j] = -1;
        createArray(root, treeArray, 0);
        printTree(treeArray, maxNodes, height(root));
        free(treeArray);
    }
    printf("NULL\n");
}
