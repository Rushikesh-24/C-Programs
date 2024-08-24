#include<stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if ((rear + 1) % MAX_SIZE == front)
        return 1;
    else
        return 0;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = data;
    printf("%d enqueued.\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Underflow");
        return;
    } else if (front == rear) {
        printf("%d dequeued.\n", queue[front]);
        front = rear = -1;
    } else {
        printf("%d dequeued.\n", queue[front]);
        front = (front + 1) % MAX_SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }
    printf("Elements in the queue are: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int choice, data;
    do {
        printf("Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}