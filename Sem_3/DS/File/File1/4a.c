#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char info;
    struct node *link;
};
struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;
void push(char item) {
    struct node *tmp;
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

    char item = top->info;
    struct node *p = top;
    top = top->link;
    free(p);
    return item;
}
void insert(char data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
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
    struct node *tmp = front;
    char data = tmp->info;
    front = front->link;
    free(tmp);
    return data;
}
void displayStack() {
    int i = 0;
    struct node *p = top;
    printf("\n\n  top\n");
    printf("----------\n");
    if (top == NULL) {
        printf("|  NULL  |\n");
        printf("----------\n");
    } else {
        printf("|%08x|\n", top);
        printf("----------\n");
        printf("   |");
        printf("\t\t");
        for (p = top; p != NULL; p = p->link) {
            printf("   --------------    ");
        }
        printf("\n");
        printf("   |-------------->");

        for (p = top; p != NULL; p = p->link, i++) {
            if (p->link == NULL) {
                printf("| %c |  NULL  |", p->info);
            } else {
                printf("| %c |%08x|------>", p->info, p->link);
            }
        }
        printf("\n \t\t");
        for (p = top; p != NULL; p = p->link) {
            printf("   --------------    ");
        }
        printf("\n \t\t");
        for (p = top; p != NULL; p = p->link) {
            printf("      %08x       ", p);
        }
    }
}
int palindrome(const char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        insert(str[i]);
        push(str[i]);
        printf("\nInserted and pushed %c", str[i]);
        displayStack();
        i++;
    }
    while (top != NULL && front != NULL) {
        char a = pop();
        char b = delete();
        printf("\nPopped from stack: %c, Deleted from queue: %c\n", a, b);
        displayStack(); 
        if (a != b) {
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
        printf("\n\n%s is a palindrome\n", str);
    } else {
        printf("\n\n%s is not a palindrome\n", str);
    }
    return 0;
}