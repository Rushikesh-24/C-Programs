#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int item;
    struct Queue *next;
};
struct Queue* front = NULL;
struct Queue* rear = NULL;

int isEmpty() {
    return (rear == NULL);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    struct Queue* current = front;
    printf("Elements in the queue: ");
    while (current != NULL) {
        printf("%d ", current->item);
        current = current->next;
    }
    printf("\n");
}


void enqueue(int item) {
    struct Queue* tmp = (struct Queue*)malloc(sizeof(struct Queue));
    tmp->item = item;
    tmp->next = NULL;

    if (isEmpty()) {
        front =tmp;
        rear = tmp;
    } else {
        rear->next = tmp;
        rear = tmp;
    }
    printf("%d enqueued to the queue.\n", item);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(1);
    }
    int item = (front)->item;
    struct Queue *temp = front;
    front = front->next;
    free(temp);
    return item;
}

int main() {
    int choice, item;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                display();
                break;
            case 2:
                item = dequeue();
                if (item != -1) {
                    printf("%d dequeued from the queue.\n", item);
                }
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
