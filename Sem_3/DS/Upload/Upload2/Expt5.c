#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    bool lthreaded;
    bool rthreaded;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthreaded = true;
    newNode->rthreaded = true;
    return newNode;
}

struct Node* inorderSuccessor(struct Node* node) {
    if (node->rthreaded) {
        return node->right;
    }
    
    struct Node* temp = node->right;
    while (temp->lthreaded == false) {
        temp = temp->left;
    }
    return temp;
}

struct Node* inorderPredecessor(struct Node* node) {
    if (node->lthreaded) {
        return node->left;
    }
    
    struct Node* temp = node->left;
    while (temp->rthreaded == false) {
        temp = temp->right;
    }
    return temp;
}

struct Node* Insert(struct Node* root,int ikey){
    struct Node * par = NULL,*ptr = root, *tmp ;
    int found = 0;
    while(ptr!=NULL){
        if(ptr->data == ikey){
            found  = 1;
            break;
        }
        par = ptr;
        if(ikey<ptr->data){
            if(!ptr->lthreaded){
                ptr = ptr->left;
            }
            else break;
        }
        else if(ikey>ptr->data){
            if(!ptr->rthreaded){
                ptr = ptr ->right;
            }
            else break;
        }
    }
    if(found){
        printf("Duplicate key\n");
        return root;
    }
    else {
        tmp = createNode(ikey);
        if(par == NULL){
            root = tmp;
            tmp->left = tmp->right = NULL;
        }
        else if(ikey<par->data){
            tmp->left = par->left;
            tmp->right = par;
            par->lthreaded = false;
            par->left = tmp;
        }
        else {
            tmp->right = par->right;
            tmp->left = par;
            par->rthreaded = false;
            par->right = tmp;
        }
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* current = root;
    while (current->lthreaded == false) {
        current = current->left;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = inorderSuccessor(current);
    }
}

struct Node* create(struct Node *root){
    int n;
    printf("Enter the number of nodes you want to insert : ");
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int data;
        printf("Enter the element %d : ",i+1);
        scanf("%d",&data);
        root = Insert(root, data);
    }
    return root;
}
struct Node* deleteNode(struct Node* root, int key) {
    struct Node *par = NULL, *ptr = root, *child = NULL;
    int found = 0;
    
    while (ptr != NULL) {
        if (ptr->data == key) {
            found = 1;
            break;
        }
        par = ptr;
        if (key < ptr->data) {
            if (!ptr->lthreaded) {
                ptr = ptr->left;
            } else {
                break;
            }
        } else if (key > ptr->data) {
            if (!ptr->rthreaded) {
                ptr = ptr->right;
            } else {
                break;
            }
        }
    }
    if (!found) {
        printf("Key not found\n");
        return root;
    }
    if (ptr->lthreaded && ptr->rthreaded) {
        if (par == NULL) {
            root = NULL;
        } else if (ptr == par->left) {
            par->left = NULL;
            par->lthreaded = true;
        } else {
            par->right = NULL;
            par->rthreaded = true;
        }
        free(ptr);
    }
    else if (ptr->lthreaded) {
        if (par == NULL) {
            root = ptr->right;
        } else if (ptr == par->left) {
            par->left = ptr->right;
        } else {
            par->right = ptr->right;
        }
        child = inorderSuccessor(ptr);
        child->left = ptr->left;
        free(ptr);
    } else if (ptr->rthreaded) {
        if (par == NULL) {
            root = ptr->left;
        } else if (ptr == par->left) {
            par->left = ptr->left;
        } else {
            par->right = ptr->left;
        }
        child = inorderPredecessor(ptr);
        child->right = ptr->right;
        free(ptr);
    }
    else {
        struct Node* successor = inorderSuccessor(ptr);
        int successorData = successor->data;
        root = deleteNode(root, successorData);
        ptr->data = successorData;
    }
    return root;
}
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        printf("%d ", current->data);

        if (!current->lthreaded && current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (!current->rthreaded && current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* current = root;

    while (current != NULL) {
        printf("%d ", current->data);

        if (!current->lthreaded) {
            current = current->left;
        } else if (!current->rthreaded) {
            current = current->right;
        } else {
            while (current != NULL && current->rthreaded) {
                current = current->right;
            }
            if (current != NULL) {
                current = current->right;
            }
        }
    }
}
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* stack[100];
    struct Node* outStack[100];
    int top = -1, outTop = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct Node* current = stack[top--];
        outStack[++outTop] = current;

        if (!current->lthreaded && current->left != NULL) {
            stack[++top] = current->left;
        }

        if (!current->rthreaded && current->right != NULL) {
            stack[++top] = current->right;
        }
    }

    while (outTop >= 0) {
        printf("%d ", outStack[outTop--]->data);
    }
}
struct Node* search(struct Node* root, int key) {
    struct Node* current = root;
    while (current != NULL) {
        if (key == current->data) {
            return current;
        } else if (key < current->data) {
            if (!current->lthreaded) {
                current = current->left;
            } else {
                break;
            }
        } else {
            if (!current->rthreaded) {
                current = current->right;
            } else {
                break;
            }
        }
    }
    return NULL;
}

int main() {
    struct Node* root = NULL;
    int key;
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Level Order Traversal\n");
        printf("7. Search\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                int data;
                scanf("%d", &data);
                root = Insert(root, data);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Level Order traversal: ");
                levelOrderTraversal(root);
                printf("\n");
                break;
            case 7:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                struct Node* result = search(root, key);
                if (result != NULL) {
                    printf("Key %d found in the tree.\n", key);
                } else {
                    printf("Key %d not found in the tree.\n", key);
                }
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
    return 0;
}