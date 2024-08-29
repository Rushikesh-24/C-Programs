#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1 + MAX_SIZE) % MAX_SIZE);
}
int isEmpty() {
    return front == -1;
}
void displayStep() {
    printf("\nQueue status:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("  %3d  ", i);
    }
    printf("\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf(" ------");
    }
    printf("\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if ((i >= front && i <= rear) || (front > rear && (i >= front || i <= rear))) {
            if (queue[i] >= 0 && queue[i] < 10)
                printf("  %2d  ", queue[i]);
            else if (queue[i] >= 10 && queue[i] < 100)
                printf("|  %2d  ", queue[i]);
            else if (queue[i] >= 100)
                printf("| %3d  ", queue[i]);
        } else {
            printf("|      ");
        }
    }
    printf("|\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf(" ------");
    }
    printf("\n");
    printf("Front = %-6d", front);
    printf("Rear = %d\n", rear);
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow.\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    displayStep();
}

void dequeue() {
    if (isEmpty()) {
        printf("\nQueue Underflow.\n");
        return;
    }
    int data = queue[front];
    queue[front] = -1; 
    if (front == rear) {
        front = rear = -1;  
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    displayStep();
    printf("Dequeued element is %d\n", data);
}

int main() {
    enqueue(74);enqueue(27);enqueue(64);enqueue(20);
    dequeue();dequeue();dequeue();enqueue(41);enqueue(109);
    enqueue(84);dequeue();enqueue(102);dequeue();dequeue();dequeue();
    return 0;
}
