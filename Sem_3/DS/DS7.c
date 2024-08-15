#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node* link;
};

struct node *front=NULL, *rear=NULL;

int isEmpty() {
    if(front==NULL)
        return 1;
    return 0;
}

void enqueue(int item) {
    struct node* tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp==NULL){
        printf("Queue Overflow");
        return;
    }
    tmp->info=item;
    tmp->link=NULL;
    if(front == NULL){
        front=tmp;
    }
    else
        rear->link=tmp;
    rear=tmp;
    return;
}

int dequeue() {
    if (isEmpty()){
        printf("Queue Underflow");
        exit(1);
    }
    struct node* temp = front;
    int item = front->info;
    temp=front;
    front=front->link;
    free(temp);
    return item;
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    struct node* temp = front;
    while(temp != NULL){
        printf("%-16s", " __________");
        temp= temp->link;
        printf(" ");
    }
    printf("\n");
    temp=front;
    while(temp != NULL){
        printf("|   %d    | ---> ", temp->info);
        temp= temp->link;
    }
    
    printf("NULL\n");
    temp=front;
    while(temp != NULL){
        printf("%-16s", " ----------");
        temp= temp->link;
        printf(" ");
    }
    temp=front;
    printf("\n");
    while(temp != NULL){
        printf("%-15x", temp);
        temp= temp->link;
        printf(" ");
    }
    printf("\n");

    printf("\n");
}
int main() {
    enqueue( 10);
    enqueue( 20);
    enqueue( 30);
    enqueue( 40);
    displayQueue();
    printf("Queue elements: \n");
    displayQueue();
    dequeue();
    displayQueue();
    return 0;
}