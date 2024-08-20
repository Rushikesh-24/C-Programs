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

struct listNode *convertToLinkedList(int *array, int size) {
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
void levelOrderArray(struct TreeNode *root) {
  if (root == NULL) {
    printf("Empty root\n");
    return;
  }

  insert_queue(root);
  int i = 1;
  int level = 1;
  int nodes_in_level = 1;
  int printed_in_level = 0;

  while (front <= rear && i <= 15) {
    struct TreeNode *current = delete_queue();
    if (current != NULL) {
      for(int i = 0; i < getHeight(current); i++) {
        printf("   ");
      }
      printf(" %c ", current->data);
      insert_queue(current->lchild);
      insert_queue(current->rchild);
    } else {
      printf("   ");
      insert_queue(NULL);
      insert_queue(NULL);
    }

    i++;
    printed_in_level++;

    if (printed_in_level == nodes_in_level) {
      printf("\n");
      level++;
      nodes_in_level = pow(2, level - 1);
      printed_in_level = 0;
    }
  }
  printf("\n");
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

     printf("Level Order traversal: \n");
    levelOrderArray(root);
    printf("\n");
}



int main() {

  int preorder[] = {'A', 'R', 'E', 'W', 'F','T','O','X','U'};
  int inorder[] = {'E', 'R', 'F', 'W', 'A','O','T','U','X'};
  struct listNode *preptr = convertToLinkedList(preorder, 9);
  struct listNode *inptr = convertToLinkedList(inorder, 9);
  struct TreeNode *tree = construct(preptr, inptr, 9);
  displayBinaryTree(tree);
  return 0;
}
