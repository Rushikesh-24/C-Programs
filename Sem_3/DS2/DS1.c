#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack{
    char brac;
    struct stack *link;
};
struct stack *top = NULL;

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char a){
    struct stack *tmp = (struct stack *)malloc(sizeof(struct stack));
    struct stack *p = top;
    if(tmp==NULL){
        printf("stack overflow");
        return;
    }
    tmp->brac = a;
    tmp->link = top;
    top=tmp;
}
char pop(){
    struct stack *tmp;
    char character;
    if(isEmpty()){
        printf("Stack Overflow\n");
        exit(1);
    }
    tmp = top;
    character = tmp->brac;
    top=top->link;
    free(tmp);
    return character;
}
void display(){
    struct stack *tmp=top;
    if(isEmpty()){
        printf("Empty\n");
        return;
    }
    while(tmp !=NULL){
        printf("%c", tmp->brac);
        tmp = tmp->link;
    }
}
int check(char *exp){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top==NULL)
                return 0;
            char element=top->brac;
            if((exp[i]==')' && element!='(') || (exp[i]=='}' && element!='{') || (exp[i]==']' && element!='['))
                return 0;
            pop();
        }
        else{
            continue;
        }
    }
    return 1;
}
 


int main(){
    char string[100];
    printf("Enter the string of paranthesis\n");
    scanf("%s",string);
    if (check(string))
        printf("Balanced Paranthesis\n");
    else
        printf("Not Balanced Paranthesis\n");
    return 0;
}