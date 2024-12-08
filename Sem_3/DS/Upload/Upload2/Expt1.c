#include <math.h>
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
  int data;
  struct TreeNode *lchild;
  struct TreeNode *rchild;
};

struct listNode {
  int data;
  struct listNode *link;
};

struct TreeNode *createNode(int data) {
  struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  if (newNode == NULL) {
    printf("Memory allocation failed!");
    exit(1);
  }
  newNode->data = data;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  return newNode;
}

void preorder(struct TreeNode *root) {
  if (root == NULL) {
    return;
  }
  printf("%c ", root->data);
  preorder(root->lchild);
  preorder(root->rchild);
}

void inorder(struct TreeNode *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->lchild);
  printf("%c ", root->data);
  inorder(root->rchild);
}

void postorder(struct TreeNode *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->lchild);
  postorder(root->rchild);
  printf("%c ", root->data);
}

struct listNode *convertToLinkedList(char *array, int size) {
  if (array == NULL || size == 0) {
    return NULL;
  }

  struct listNode *head = NULL;

  struct listNode *prevNode = NULL;
  for (int i = 0; i < size; i++) {
    struct listNode *newNode =
        (struct listNode *)malloc(sizeof(struct listNode));
    if (newNode == NULL) {
      printf("Memory allocation failed!");
      exit(1);
    }
    newNode->data = array[i];
    newNode->link = NULL;
    if (head == NULL) {
      head = newNode;
    } else {
      prevNode->link = newNode;
    }
    prevNode = newNode;
  }

  return head;
}
struct TreeNode *construct(struct listNode *preptr, struct listNode *inptr,
                           int num) {
  if (num == 0 || preptr == NULL || inptr == NULL) {
    return NULL;
  }

  struct TreeNode *temp = createNode(preptr->data);

  if (num == 1) {
    return temp;
  }

  struct listNode *q = inptr;
  int i = 0;
  while (q != NULL && q->data != preptr->data) {
    i++;
    q = q->link;
  }
  temp->lchild = construct(preptr->link, inptr, i);

  struct listNode *preptrRight = preptr;
  for (int j = 0; j <= i; j++) {
    preptrRight = preptrRight->link;
  }

  temp->rchild = construct(preptrRight, q->link, num - i - 1);

  return temp;
}

struct TreeNode *queue[50];
int front = -1;
int rear = -1;
void insert_queue(struct TreeNode *item) {
  if (rear == 49) {
    printf("Queue Overflow: ");
    return;
  }
  if (front == -1) {
    front = 0;
  }
  rear += 1;
  queue[rear] = item;
}
struct TreeNode *delete_queue() {
  if (front == -1 || front > rear) {
    printf("Queue underflow");
    exit(1);
  }
  struct TreeNode *item = queue[front];
  front += 1;
  return item;
}
void levelOrder(struct TreeNode *root) {
  if (root == NULL) {
    printf("Empty root\n");
    return;
  }

  front = rear = -1; // Reset queue
  insert_queue(root);

  while (front <= rear) {
    struct TreeNode *ptr = delete_queue();
    printf("%c ", ptr->data);
    if (ptr->lchild != NULL) {
      insert_queue(ptr->lchild);
    }
    if (ptr->rchild != NULL) {
      insert_queue(ptr->rchild);
    }
  }
  printf("\n");
}

int getHeight(struct TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  int leftHeight = getHeight(root->lchild);
  int rightHeight = getHeight(root->rchild);
  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int getHeightNonRecursive(struct TreeNode *root) {
  if (root == NULL) {
    return 0;
  }

  int height = 0;
  struct TreeNode *queue[50];
  int front = -1;
  int rear = -1;

  insert_queue(root);
  insert_queue(NULL);

  while (front != rear) {
    struct TreeNode *current = delete_queue();

    if (current == NULL) {
      height++;
      insert_queue(NULL);
      continue;
    }

    if (current->lchild != NULL) {
      insert_queue(current->lchild);
    }

    if (current->rchild != NULL) {
      insert_queue(current->rchild);
    }
  }

  return height;
}

void displayBinaryTree(struct TreeNode *root) {
  if (root == NULL) {
    return;
  }

  printf("Preorder traversal: ");
  preorder(root);
  printf("\n");

  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");

  printf("Postorder traversal: ");
  postorder(root);
  printf("\n");

  printf("Level Order traversal: ");
  levelOrder(root);
  printf("\n");

  printf("\n");
}
void printTree(char arr[], int size, int levels) {
  int n = 0;
  for (int level = 0; level <= levels; level++) {
    int nodesInLevel = pow(2, level);
    int spaceBetweenNodes = pow(2, levels - level + 1) - 1;
    int initialSpace = pow(2, levels - level) - 1;
    for (int i = 0; i < initialSpace; i++)
      printf(" ");
    for (int i = 0; i < nodesInLevel && n < size; i++) {
      if (arr[n] != ' ') {
        printf("%c", arr[n]);
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
char *createArray(struct TreeNode *root, char *ptr, int i) {
  if (root == NULL) {
    *(ptr + i) = ' ';
    return ptr;
  }
  *(ptr + i) = root->data;
  ptr = createArray(root->lchild, ptr, i * 2 + 1);
  ptr = createArray(root->rchild, ptr, i * 2 + 2);
  return ptr;
}

int main() {
  int size;
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  char preorder[size], inorder[size];
  printf("Enter %d elements for preorder traversal \n", size);
  for (int i = 0; i < size; i++) {
    printf("Enter %d element :", i + 1);
    scanf(" %c", &preorder[i]);
  }

  printf("Enter %d elements for inorder traversal \n", size);
  for (int i = 0; i < size; i++) {
    printf("Enter %d element :", i + 1);
    scanf(" %c", &inorder[i]);
  }
  struct listNode *preptr = convertToLinkedList(preorder, size);
  struct listNode *inptr = convertToLinkedList(inorder, size);
  struct TreeNode *tree = construct(preptr, inptr, size);
  printf("Height of the tree: %d\n", getHeight(tree));

  char *arr = (char *)malloc(size * sizeof(char));
  createArray(tree, arr, 0);
  displayBinaryTree(tree);
  int maxNodes = pow(2, getHeight(tree) + 1) - 1;
  printTree(arr, maxNodes, getHeight(tree));
  return 0;
}
