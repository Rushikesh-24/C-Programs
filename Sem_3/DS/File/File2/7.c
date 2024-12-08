// Binary Search tree
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *lchild;
  struct Node *rchild;
};
struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  return newNode;
}
int height(struct Node *root) {
  if (root == NULL) {
    return 0;
  } else {
    int leftHeight = height(root->lchild);
    int rightHeight = height(root->rchild);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
  }
}

struct Node *insert(struct Node *root, int data) {
  if (root == NULL) {
    root = createNode(data);
  } else if (data < root->data) {
    root->lchild = insert(root->lchild, data);
  } else if (data > root->data) {
    root->rchild = insert(root->rchild, data);
  }
  return root;
}
void inorderTraversal(struct Node *root) {
  if (root != NULL) {
    inorderTraversal(root->lchild);
    printf("%d ", root->data);
    inorderTraversal(root->rchild);
  }
}
void postorderTraversal(struct Node *root) {
  if (root != NULL) {
    postorderTraversal(root->lchild);
    postorderTraversal(root->rchild);
    printf("%d ", root->data);
  }
}
void preorderTraversal(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorderTraversal(root->lchild);
    preorderTraversal(root->rchild);
  }
}

void levelOrderTraversal(struct Node *root) {
  if (root == NULL) {
    return;
  }

  struct Node *queue[100];
  int front = 0;
  int rear = 0;

  queue[rear++] = root;

  while (front < rear) {
    struct Node *current = queue[front++];
    printf("%d ", current->data);

    if (current->lchild != NULL) {
      queue[rear++] = current->lchild;
    }

    if (current->rchild != NULL) {
      queue[rear++] = current->rchild;
    }
  }
}
struct Node *search(struct Node *root, int key) {
  if (root == NULL || root->data == key) {
    return root;
  }
  if (key < root->data) {
    return search(root->lchild, key);
  }
  return search(root->rchild, key);
}

struct Node *delete(struct Node *root, int key) {
  if (root == NULL) {
    return root;
  }
  if (key < root->data) {
    root->lchild = delete (root->lchild, key);
  } else if (key > root->data) {
    root->rchild = delete (root->rchild, key);
  } else {
    if (root->lchild == NULL) {
      struct Node *temp = root->rchild;
      free(root);
      return temp;
    } else if (root->rchild == NULL) {
      struct Node *temp = root->lchild;
      free(root);
      return temp;
    }
    struct Node *successor = root->rchild;
    while (successor->lchild != NULL) {
      successor = successor->lchild;
    }
    root->data = successor->data;
    root->rchild = delete (root->rchild, successor->data);
  }
  return root;
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
      if (arr[n] != -1) {
        printf("%d", arr[n]);
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
}
int *createArray(struct Node *root, int *ptr, int i) {
  if (root == NULL) {
    *(ptr + i) = -1;
    return ptr;
  }
  *(ptr + i) = root->data;
  ptr = createArray(root->lchild, ptr, i * 2 + 1);
  ptr = createArray(root->rchild, ptr, i * 2 + 2);
  return ptr;
}
struct Node *findMin(struct Node *root) {
  while (root != NULL && root->lchild != NULL) {
    root = root->lchild;
  }
  return root;
}
struct Node *findMax(struct Node *root) {
  while (root != NULL && root->rchild != NULL) {
    root = root->rchild;
  }
  return root;
}
int main() {
  struct Node *root = NULL;
  int n[] = {41, 70, 58, 49, 25, 12, 44, 20, 68, 91, 57, 42, 37, 28, 27};
  for (int i = 0; i < 15; i++) {
    printf("Insert( %d )\n", n[i]);
    root = insert(root, n[i]);
    int maxNodes = pow(2, height(root) + 1) - 1;
    int *arr = (int *)malloc(maxNodes * sizeof(int));
    for (int i = 0; i < maxNodes; i++)
      arr[i] = -1;
    createArray(root, arr, 0);
    printTree(arr, maxNodes, height(root));
    printf("\n");
  }
  printf("\n Height of the tree is %d", height(root));
  printf("\nInorder Traversal: ");
  inorderTraversal(root);
  printf("\nPostorder Traversal: ");
  postorderTraversal(root);
  printf("\nPreorder Traversal: ");
  preorderTraversal(root);
  printf("\nLevel Order :");
  levelOrderTraversal(root);
  printf("\n");
    for(int i = 0;i<15;i++){
        printf("Delete ( %d )\n", n[i]);
        root = delete(root, n[i]);
        int maxNodes = pow(2, height(root) + 1) - 1;
        int *arr = (int *)malloc(maxNodes * sizeof(int));
        for (int i = 0; i < maxNodes; i++)
          arr[i] = -1;
        createArray(root, arr, 0);
        printTree(arr, maxNodes, height(root));
        printf("\n");
    }
    printf("NULL\n");
  return 0;
}