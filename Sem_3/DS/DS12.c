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

void inorderTraversal(struct Node *root) {
  if (root != NULL) {
    inorderTraversal(root->lchild);
    printf("%d ", root->data);
    inorderTraversal(root->rchild);
  }
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
void postorderTraversal(struct Node *root) {
  if (root != NULL) {
    postorderTraversal(root->lchild);
    postorderTraversal(root->rchild);
    printf("%d ", root->data);
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
struct Node *search(struct Node *root, int key) {
  if (root == NULL || root->data == key) {
    return root;
  }
  if (key < root->data) {
    return search(root->lchild, key);
  }
  return search(root->rchild, key);
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
int main() {
  struct Node *root = NULL;
  int choice, data;
  while (1) {
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Level Order Traversal\n");
    printf("6. Delete\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the number of elements to be inserted: ");
        int numElements;
        scanf("%d", &numElements);
        int insertChoice;
        printf("Choose insert method:\n");
        printf("1. Recursive\n");
        printf("2. Non-Recursive\n");
        printf("Enter your choice: ");
        scanf("%d", &insertChoice);
        switch (insertChoice) {
          case 1:
            for (int i = 0; i < numElements; i++) {
              printf("Enter element %d: ", i + 1);
              scanf("%d", &data);
              root = insert(root, data);
            }
            break;
          case 2:
            for (int i = 0; i < numElements; i++) {
              printf("Enter element %d: ", i + 1);
              scanf("%d", &data);
              root = insertNonRecursive(root, data);
            }
            break;
          default:
            printf("Invalid choice\n");
        }
        break;
      case 2:
        printf("Enter the key to be searched: ");
        scanf("%d", &data);
        int searchChoice;
        printf("Choose search method:\n");
        printf("1. Recursive\n");
        printf("2. Non-Recursive\n");
        printf("Enter your choice: ");
        scanf("%d", &searchChoice);
        switch (searchChoice) {
          case 1:
            if (search(root, data) != NULL) {
              printf("Key found in the BST\n");
            } else {
              printf("Key not found in the BST\n");
            }
            break;
          case 2:
            if (searchNonRecursive(root, data) != NULL) {
              printf("Key found in the BST\n");
            } else {
              printf("Key not found in the BST\n");
            }
            break;
          default:
            printf("Invalid choice\n");
        }
        break;
      case 3:
        printf("Choose traversal method:\n");
        printf("1. Recursive\n");
        printf("2. Non-Recursive\n");
        printf("Enter your choice: ");
        int traversalChoice;
        scanf("%d", &traversalChoice);
        switch (traversalChoice) {
          case 1:
            printf("Inorder traversal of the binary search tree: ");
            inorderTraversal(root);
            printf("\n");
            break;
          case 2:
            printf("Inorder traversal of the binary search tree: ");
            inorderTraversalNonRecursive(root);
            printf("\n");
            break;
          default:
            printf("Invalid choice\n");
        }
        break;
      case 4:
        printf("Choose traversal method:\n");
        printf("1. Recursive\n");
        printf("2. Non-Recursive\n");
        printf("Enter your choice: ");
        int postorderChoice;
        scanf("%d", &postorderChoice);
        switch (postorderChoice) {
          case 1:
            printf("Postorder traversal of the binary search tree: ");
            postorderTraversal(root);
            printf("\n");
            break;
          case 2:
            printf("Postorder traversal of the binary search tree: ");
            postorderTraversalNonRecursive(root);
            printf("\n");
            break;
          default:
            printf("Invalid choice\n");
        }
        break;
      case 5:
            printf("Level order traversal of the binary search tree: ");
            levelOrderTraversal(root);
            printf("\n");
            break;
      case 6:
        printf("Enter the key to be deleted: ");
        scanf("%d", &data);
        int deleteChoice;
        printf("Choose delete method:\n");
        printf("1. Recursive\n");
        printf("2. Non-Recursive\n");
        printf("Enter your choice: ");
        scanf("%d", &deleteChoice);
        switch (deleteChoice) {
          case 1:
            root = delete (root, data);
            break;
          case 2:
            root = deleteNonRecursive(root, data);
            break;
          default:
            printf("Invalid choice\n");
        }
        break;
      case 7:
        printf("Exiting the program\n");
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}