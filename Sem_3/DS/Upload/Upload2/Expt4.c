// Binary Search tree
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
struct Node *insertNonRecursive(struct Node *root, int data) {
  struct Node *newNode = createNode(data);
  if (root == NULL) {
    root = newNode;
    return root;
  }
  struct Node *current = root;
  struct Node *parent = NULL;
  while (current != NULL) {
    parent = current;
    if (data < current->data) {
      current = current->lchild;
    } else {
      current = current->rchild;
    }
  }
  if (data < parent->data) {
    parent->lchild = newNode;
  } else {
    parent->rchild = newNode;
  }
  return root;
}
void inorderTraversalNonRecursive(struct Node *root) {
  if (root == NULL) {
    return;
  }
  struct Node *stack[100];
  int top = -1;
  struct Node *current = root;
  while (current != NULL || top != -1) {
    while (current != NULL) {
      stack[++top] = current;
      current = current->lchild;
    }
    current = stack[top--];
    printf("%d ", current->data);
    current = current->rchild;
  }
}
void postorderTraversalNonRecursive(struct Node *root) {
  if (root == NULL) {
    return;
  }
  struct Node *stack[100];
  int top = -1;
  struct Node *current = root;
  struct Node *prev = NULL;
  do {
    while (current != NULL) {
      stack[++top] = current;
      current = current->lchild;
    }
    while (current == NULL && top != -1) {
      current = stack[top];
      if (current->rchild == NULL || current->rchild == prev) {
        printf("%d ", current->data);
        top--;
        prev = current;
        current = NULL;
      } else {
        current = current->rchild;
      }
    }
  } while (top != -1);
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

struct Node *searchNonRecursive(struct Node *root, int key) {
  while (root != NULL && root->data != key) {
    if (key < root->data) {
      root = root->lchild;
    } else {
      root = root->rchild;
    }
  }
  return root;
}
struct Node *deleteNonRecursive(struct Node *root, int key) {
  struct Node *parent = NULL;
  struct Node *current = root;
  while (current != NULL && current->data != key) {
    parent = current;
    if (key < current->data) {
      current = current->lchild;
    } else {
      current = current->rchild;
    }
  }
  if (current == NULL) {
    return root;
  }
  if (current->lchild == NULL && current->rchild == NULL) {
    if (current == root) {
      root = NULL;
    } else if (current == parent->lchild) {
      parent->lchild = NULL;
    } else {
      parent->rchild = NULL;
    }
    free(current);
  } else if (current->lchild == NULL) {
    if (current == root) {
      root = current->rchild;
    } else if (current == parent->lchild) {
      parent->lchild = current->rchild;
    } else {
      parent->rchild = current->rchild;
    }
    free(current);
  } else if (current->rchild == NULL) {
    if (current == root) {
      root = current->lchild;
    } else if (current == parent->lchild) {
      parent->lchild = current->lchild;
    } else {
      parent->rchild = current->lchild;
    }
    free(current);
  } else {
    struct Node *successor = current->rchild;
    struct Node *successorParent = current;
    while (successor->lchild != NULL) {
      successorParent = successor;
      successor = successor->lchild;
    }
    current->data = successor->data;
    if (successor == successorParent->lchild) {
      successorParent->lchild = successor->rchild;
    } else {
      successorParent->rchild = successor->rchild;
    }
    free(successor);
  }
  return root;
}
void preorderTraversalNonRecursive(struct Node *root) {
    if (root == NULL) {
        return;
    }
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct Node *current = stack[top--];
        printf("%d ", current->data);
        if (current->rchild != NULL) {
            stack[++top] = current->rchild;
        }
        if (current->lchild != NULL) {
            stack[++top] = current->lchild;
        }
    }
}
int main() {
  struct Node *root = NULL;
  int choice, data;
while (1) {
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Level Order Traversal\n");
    printf("6. Preorder Traversal\n");
    printf("7. Delete\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the number of elements to be inserted: ");
            int numElements;
            scanf("%d", &numElements);
            for (int i = 0; i < numElements; i++) {
                printf("Enter element %d: ", i + 1);
                scanf("%d", &data);
                root = insertNonRecursive(root, data);
            }
            break;
        case 2:
            printf("Enter the key to be searched: ");
            scanf("%d", &data);
            if (searchNonRecursive(root, data) != NULL) {
                printf("Key found in the BST\n");
            } else {
                printf("Key not found in the BST\n");
            }
            break;
        case 3:
            printf("Inorder traversal of the binary search tree: ");
            inorderTraversalNonRecursive(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder traversal of the binary search tree: ");
            postorderTraversalNonRecursive(root);
            printf("\n");
            break;
        case 5:
            printf("Level order traversal of the binary search tree: ");
            levelOrderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("Preorder traversal of the binary search tree: ");
            preorderTraversalNonRecursive(root);
            printf("\n");
            break;
        case 7:
            printf("Enter the key to be deleted: ");
            scanf("%d", &data);
            root = deleteNonRecursive(root, data);
            break;
        case 8:
            printf("Exiting the program\n");
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}
  return 0;
}