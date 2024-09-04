#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position! Please try again.\n");
        return;
    }
    
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    int count = 1;
    
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL) {
        printf("Invalid position! Please try again.\n");
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
}

void reverse(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;
    
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp != NULL) {
        *head = temp->prev;
    }
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    if (temp->data == data) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Element not found in the list! Cannot delete.\n");
        return;
    }
    
    temp->prev->next = temp->next;
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    free(temp);
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search(struct Node* head, int data) {
    struct Node* temp = head;
    int position = 1;
    
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
        position++;
    }
    
    if (temp == NULL) {
        exit(1);
    }
    
    return position;
}

int countElements(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}
void insertAfter(struct Node* head, int data, int key) {
    if (head == NULL) {
        printf("List is empty! Cannot insert.\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Not found\n");
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
}

void insertBefore(struct Node* head, int data, int key) {
    if (head == NULL) {
        printf("List is empty! Cannot insert.\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    
    if (temp->data == key) {
        newNode->next = temp;
        temp->prev = newNode;
        head = newNode;
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Not found\n");
        return;
    }
    
    newNode->next = temp;
    newNode->prev = temp->prev;
    
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    }
    
    temp->prev = newNode;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position,count;
    
    while (1) {
        printf("Menu:\n");
        printf("1. Insert at end\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at position\n");
        printf("4. Delete node\n");
        printf("5. Reverse list\n");
        printf("6. Search element\n");
        printf("7. Count elements\n");
        printf("8. Display\n");
        printf("9. Reverse\n");
        printf("10. Add after a node\n");
        printf("11. Add before a node\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
       
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                display(head);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                display(head);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                display(head);
                break;
            case 4:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                display(head);
                break;
            case 5:
                reverse(&head);
                display(head);
                break;
            case 6:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                position = search(head, data);
                printf("Element found at position: %d\n", position);
                break;
            case 7:
                count = countElements(head);
                printf("Number of elements in the list: %d\n", count);
                break;
            case 8:
                display(head);
                break;
            case 9:
               reverse(&head);
                display(head);
                break;
            case 10:
                printf("Enter the data to be inserted after : ");
                scanf("%d", &position);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAfter(head, data, position);
                display(head);
                break;
            case 11:
                printf("Enter the data to be inserted before : ");
                scanf("%d", &position);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertBefore(head, data, position);
                display(head);
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}