#include <stdio.h>
#include <stdlib.h>
#include<math.h>
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
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
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
struct TreeNode *construct(struct listNode *preptr, struct listNode *inptr, int num) {
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
int front =-1;
int rear =-1;
void insert_queue(struct TreeNode *item){
  if(rear==49){
    printf("Queue Overflow: ");
    return;
  }
  if(front==-1){
    front = 0;
  }
  rear+=1;
  queue[rear] = item;
}
struct TreeNode *delete_queue(){
  if(front==-1 || front>rear){
    printf("Queue underflow");
    exit(1);
  }
  struct TreeNode *item = queue[front];
    front += 1;
    return item;
}

void levelOrder(struct TreeNode *root){
  struct TreeNode *ptr = root;
  if(root==NULL){
    printf("Empty root");
    return;
  }
  insert_queue(ptr);
  while(front <= rear){
    ptr = delete_queue();
    printf("%c ",ptr->data);
    if(ptr->lchild!=NULL)
      insert_queue(ptr->lchild);
    if(ptr->rchild!=NULL)
      insert_queue(ptr->rchild);
  }
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

struct TreeNode *constructPost(struct listNode *postptr, struct listNode *inptr, int num) {
  if (num == 0 || postptr == NULL || inptr == NULL) {
    return NULL;
  }

  struct listNode *p = postptr;
  for (int i = 1; i < num; i++) {
    p = p->link;
  }

  struct TreeNode *tmp = createNode(p->data);

  if (num == 1) {
    return tmp;
  }

  struct listNode *q = inptr;
  int i = 0;
  while (q != NULL && q->data != p->data) {
    i++;
    q = q->link;
  }

  tmp->lchild = constructPost(postptr, inptr, i);

  struct listNode *postptrRight = postptr;
  for (int j = 0; j < i; j++) {
    postptrRight = postptrRight->link;
  }

  tmp->rchild = constructPost(postptrRight, q->link, num - i - 1);

  return tmp;
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

int main() {
  // char preorder[] = {'A', 'R', 'E', 'W', 'F','T','O','X','U'};
  // char inorder[] = {'E', 'R', 'F', 'W', 'A','O','T','U','X'};
  // char postorder[] = {'E', 'F', 'W', 'R', 'O', 'U', 'X', 'T', 'A'};
  int size;
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  char preorder[size], inorder[size], postorder[size];
  printf("Enter %d elements for preorder traversal \n", size);
  for (int i = 0; i < size; i++) {
    printf("Enter %d element :",i+1);
    scanf(" %c", &preorder[i]);
  }

  printf("Enter %d elements for inorder traversal \n", size);
  for (int i = 0; i < size; i++) {
    printf("Enter %d element :",i+1);
    scanf(" %c", &inorder[i]);
  }

  printf("Enter %d elements for postorder traversal \n", size);
  for (int i = 0; i < size; i++) {
    printf("Enter %d element :",i+1);
    scanf(" %c", &postorder[i]);
  }
  struct listNode *preptr = convertToLinkedList(preorder, 9);
  struct listNode *inptr = convertToLinkedList(inorder, 9);
  struct listNode *postptr = convertToLinkedList(postorder,9);
  struct TreeNode *tree = construct(preptr, inptr, 9);
  struct TreeNode *root = constructPost(postptr, inptr, 9);
  displayBinaryTree(tree);
  return 0;
}
