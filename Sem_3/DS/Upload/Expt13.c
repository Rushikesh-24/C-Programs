#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *addatEnd(struct Node *start,int data){
 struct Node *tmp,*p = start;
 tmp = (struct Node*)malloc(sizeof(struct Node));
 tmp->data = data;
 if(start == NULL){
    tmp->next = NULL;
    tmp->prev = NULL;
    start = tmp;
 } else {
    while(p->next != NULL){
        p = p->next;
    }
    tmp->next = NULL;
    tmp->prev = p;
    p->next = tmp;
 }
 return start;
}
struct Node *create(struct Node *start){
    int n,data;
    printf("Enter the number of node :");
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        printf("Enter the element of %d node :",i+1);
        scanf("%d",&data);
        start = addatEnd(start,data);
    }
    return start;
}
void display(struct Node *start){
    struct Node *p;
    if(start == NULL){
        printf("Linked list is empty.\n");
        return;
    }
    p = start;
    printf("Linked list: ");
    while(p != NULL){
        if(p->prev==NULL){
            printf(" |NULL|%d|%x| -> ",p->data,p->next);
        }
        else if(p->next==NULL){
            printf("|%x|%d|NULL| ",p->prev,p->data);
        }
        else printf("|%x|%d|%x| -> ",p->prev,p->data,p->next);
        p = p->next;
    }
    printf("\n\n");
}
struct Node *changeAlternate(struct Node *start) {
    struct Node *p = start;
    struct Node *newStart = NULL;
    struct Node *prev = NULL;

    while (p != NULL && p->next != NULL) {
        struct Node *q = p->next;
        p->next = q->next;
        q->next = p;
        q->prev = prev;
        p->prev=q;
        if (prev != NULL) {
            prev->next = q;
        } else {
            newStart = q;
        }
        if (p->next != NULL) {
            p->next->prev = p;
        }
        
        prev = p;
        p = p->next;
    }
    if (newStart == NULL) {
        newStart = start;
    }

    return newStart;
}



int main(){
    struct Node *start = NULL;
    start = create(start);
    display(start);
    start = changeAlternate(start);
    display(start);
}