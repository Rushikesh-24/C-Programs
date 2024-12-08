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
void preorderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
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
                    root = insert(root, data);
                }
                break;
            case 2:
                printf("Enter the key to be searched: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("Key found in the BST\n");
                } else {
                    printf("Key not found in the BST\n");
                }
                break;
            case 3:
                printf("Inorder traversal of the binary search tree: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal of the binary search tree: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Level order traversal of the binary search tree: ");
                levelOrderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Preorder traversal of the binary search tree: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 7:
                printf("Enter the key to be deleted: ");
                scanf("%d", &data);
                root = delete(root, data);
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
