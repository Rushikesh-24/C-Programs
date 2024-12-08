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
        ptr->lchild = a->rchild; //LL 
        a->rchild = ptr;
        ptr->balance = 0;
        a->balance = 0;
        ptr = a;
    } else {
        b = a->rchild;  //LR
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
        ptr->rchild = a->lchild; // RR
        a->lchild = ptr;
        ptr->balance = 0;
        a->balance = 0;
        ptr = a;
    } else {
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

struct node *insert_right_child(struct node *ptr,bool *Taller){
    switch(ptr->balance){
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
struct node *insert_left_child(struct node *ptr,bool *Taller){
    switch(ptr->balance){
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
    if(Taller){
        ptr = insert_left_child(ptr,&Taller);
    }
  } else if (ikey > ptr->info) {
    ptr->rchild = insert(ptr->rchild, ikey);
    if(Taller){
        ptr = insert_right_child(ptr,&Taller);
    }
  }
  else{
    printf("Dublicate\n");
    Taller = false;
  }
  return ptr;
}
int front =-1;
int rear =-1;

void insert_queue(struct node *node) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct node* delete_queue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}



void levelOrder(struct node *root){
  struct node *ptr = root;
  if(root==NULL){
    printf("Empty root");
    return;
  }
  insert_queue(ptr);
  while(front <= rear){
    ptr = delete_queue();
    printf("%d (%d), ",ptr->info,ptr->balance);
    if(ptr->lchild!=NULL)
      insert_queue(ptr->lchild);
    if(ptr->rchild!=NULL)
      insert_queue(ptr->rchild);
  }
  printf("\n");
}



int height(struct node *root) {
    if (root == NULL) return 0;
    int left_height = height(root->lchild);
    int right_height = height(root->rchild);
    return 1 + (left_height > right_height ? left_height : right_height);
}


struct node *delete_left_balance(struct node *ptr, bool *Shorter) {
    struct node *a, *b;

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
            if (a->balance <= 0) {
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
                b = a->lchild;
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
            if (a->balance >= 0) {
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
                b = a->rchild;
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
    struct node *dptr, *succ;

    if (ptr == NULL) {
        *Shorter = false;
        *Success = false;
        return NULL;
    }

    if (dkey < ptr->info) {
        ptr->lchild = delete(ptr->lchild, dkey, Shorter, Success);
        if (*Shorter) ptr = delete_right_balance(ptr, Shorter);
    } else if (dkey > ptr->info) {
        ptr->rchild = delete(ptr->rchild, dkey, Shorter, Success);
        if (*Shorter) ptr = delete_left_balance(ptr, Shorter);
    } else {
        dptr = ptr;
        if (ptr->rchild == NULL) {
            ptr = ptr->lchild;
            *Shorter = true;
            *Success = true;
            free(dptr);
        } else if (ptr->lchild == NULL) {
            ptr = ptr->rchild;
            *Shorter = true;
            *Success = true;
            free(dptr);
        } else {
            succ = ptr->rchild;
            while (succ->lchild != NULL) succ = succ->lchild;
            ptr->info = succ->info;
            ptr->rchild = delete(ptr->rchild, succ->info, Shorter, Success);
            if (*Shorter) ptr = delete_left_balance(ptr, Shorter);
        }
    }
    return ptr;
}
struct node* search(struct node* root, int key) {
    if (root == NULL || root->info == key) {
        return root;
    }
    if (key < root->info) {
        return search(root->lchild, key);
    } else {
        return search(root->rchild, key);
    }
}
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d (%d), ", root->info, root->balance);
        inorder(root->rchild);
    }
}
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d (%d), ", root->info, root->balance);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d (%d), ", root->info, root->balance);
    }
}
int main(){
    struct node *root = NULL;
    int choice, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Level Order Traversal\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes you want to insert: ");
                int num_nodes;
                scanf("%d", &num_nodes);
                for (int i = 0; i < num_nodes; i++) {
                    printf("Enter the key to insert: ");
                    scanf("%d", &key);
                    root = insert(root, key);
                    levelOrder(root);
                }
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                bool Shorter = false, Success = false;
                root = delete(root, key, &Shorter, &Success);
                if (Success) {
                    printf("Node deleted successfully.\n");
                } else {
                    printf("Node not found.\n");
                }
                levelOrder(root);
                break;
            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                struct node *result = search(root, key);
                if (result != NULL) {
                    printf("Node found with key %d.\n", key);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Level Order Traversal: ");
                levelOrder(root);
                printf("\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
