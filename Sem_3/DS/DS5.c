#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1))
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow.\n");
        return;
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = data;
        printf("%d enqueued to the queue.\n", data);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow.\n");
        return;
    } else {
        int data = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX_SIZE;
        printf("%d dequeued from the queue.\n", data);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    } else {
        printf("Elements in the queue are: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}
int peek() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        exit(1);
    } else {
        return queue[front];
    }
}
int main() {
    int choice;
do {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            {
                int data;
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            }
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
            break;
    }
} while (choice != 4);

    return 0;
}