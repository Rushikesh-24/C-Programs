#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct node {
    char info;
    struct node* link;
};

struct node* top = NULL;
struct node* front = NULL;
struct node* rear = NULL;

void push(char item) {
    struct node* tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    tmp->info = item;
    tmp->link = top;
    top = tmp;
}

char pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return CHAR_MIN;
    }

    char item = top->info; // Changed int to char
    struct node* p = top;
    top = top->link;
    free(p);
    return item;
}

void insert(char data) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    tmp->info = data;
    tmp->link = NULL;
    if (front == NULL) {
        front = tmp;
    } else {
        rear->link = tmp;
    }
    rear = tmp;
}

char delete() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return CHAR_MIN;
    }
    struct node* tmp = front;
    char data = tmp->info;
    front = front->link;
    free(tmp);
    return data;
}

int palindrome(const char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        insert(str[i]);
        push(str[i]);
        i++;
    }

    while(top!=NULL && front!=NULL){
        char a=pop();
        char b=delete();
        if (a!=b){
            return 0;   
        }
    }

    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (palindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
    return 0;
}