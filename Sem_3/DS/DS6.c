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
    while(tmp !=NULL){
        printf("%d", tmp->info);
        tmp = tmp->link;
    }
}
int main(){
    push(1);
    return 0;
}