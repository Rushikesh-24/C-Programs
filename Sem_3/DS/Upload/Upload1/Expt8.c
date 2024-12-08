#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *link;
};

struct Node *top = NULL;

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int a){
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = top;
    if(tmp==NULL){
        printf("Stack overflow");
        return;
    }
    tmp->info = a;
    tmp->link = top;
    top=tmp;
}
int pop(){
    struct Node *tmp;
    int character;
    if(isEmpty()){
        printf("Stack Overflow\n");
        exit(1);
    }
    tmp = top;
    character = tmp->info;
    top=top->link;
    free(tmp);
    return character;
}
void display(){
    struct Node *tmp=top;
    if(isEmpty()){
        printf("Empty\n");
        return;
    }
    printf("\n");
    while(tmp !=NULL){
        printf(" %d ", tmp->info);
        tmp = tmp->link;
    }
    printf("\n");
}
int main(){
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    int value;
                    printf("Enter the value to push: ");
                    scanf("%d", &value);
                    push(value);
                    display();
                    break;
                }
            case 2:
                {
                    int poppedValue = pop();
                    printf("Popped value: %d\n", poppedValue);
                    display();
                    break;
                }
            case 3:
                {
                    printf("Stack elements: ");
                    display();
                    printf("\n");
                    break;
                }
            case 4:
                {
                    printf("Exiting...\n");
                    break;
                }
            default:
                {
                    printf("Invalid choice! Please try again.\n");
                    break;
                }
        }
    } while(choice != 4);
    return 0;
}