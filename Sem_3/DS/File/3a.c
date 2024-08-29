#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int front = -1, rear = -1, array[MAX];

int isFull() { return rear == MAX - 1; }
int isEmpty() { return front == -1 || front > rear; }

void displaySteps() {
    printf("\nQueue status:\n");
    for (int i = 0; i < MAX; i++) printf("  %3d  ", i);
    printf("\n");
    for (int i = 0; i < MAX; i++) printf(" ------");
    printf("\n");
    for (int i = 0; i < MAX; i++) {
        if (i >= front && i <= rear)
            printf("| %3d  ", array[i]);
        else
            printf("|      ");
    }
    printf("|\n");
    for (int i = 0; i < MAX; i++) printf(" ------");
    printf("\n");
}

void insert(int item) {
    if(isFull()){
        printf("\nStack Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    array[++rear] = item;
    displaySteps();
}

void delete() {
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    printf("Dequeued element : %d\n", array[front++]);
    displaySteps();
}
int peek(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return array[front];
}

int main() {
    insert(85); insert(107); insert(105); insert(25);
    delete(); delete();
    insert(57);
    delete(); delete(); delete(); delete();
    insert(13);
    delete();
}
