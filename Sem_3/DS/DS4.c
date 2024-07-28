// implementations of queue  using array
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1, rear = -1;
int array[MAX];
int isFull() {
  if (rear == MAX - 1) {
    return 1;
  }
  return 0;
}
int isEmpty(){
    if(front == -1 || front > rear){
        return 1;
    }
    return 0;
}
void insert(int item) {
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    if(front == -1){
        front++;
    }
    rear ++;
    array[rear] = item;
}
int delete(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    int item = array[front];
    front=front + 1;
    return item;
}
int peek(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return array[front];
}
void display(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",array[i]);
    }
}
int main() {
    int n;
    int item;
    do{
        printf("\nEnter 1 to Insert a new item\n");
        printf("Enter 2 to Delete a item\n");
        printf("Enter 3 to Peek\n");
        printf("Enter 4 to Display the Queue\n");
        printf("Enter 5 to Exit\n");
        scanf("%d",&n);
        switch (n) {
            case 1:
                printf("Enter the item to be inserted\n");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                printf("Deleted Item :%d\n",delete());
                break;
            case 3:
                printf("Peek Item :%d\n",peek());
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exited");
                exit(0);
            default:
                printf("Wrong Input\n");
                break;
        }

    }while(n!=5);
  return 0;
}