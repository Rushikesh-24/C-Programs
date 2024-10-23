#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *addToEmpty(int data,struct node *last){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    last=temp;
    last->link=last;
    return last;
}
struct node *addAtEnd(int data,struct node *last){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=last->link;
    last->link=temp;
    last=temp;
    return last;
}
struct node *createList(struct node *last){
    int data,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    if(n<1) return last;
    printf("Element 1: ");
    scanf("%d",&data);
    last=addToEmpty(data,last);
    for(int i=2;i<=n;i++){
        printf("Element %d: ",i);
        scanf("%d",&data);
        last=addAtEnd(data,last);
    }
    return last;
}
void display(struct node *last){
    if(last==NULL)return;
    struct node *p=last->link;
    printf("\n");
    do{
        if(p!=last)
            printf(" → |%d|%08x|",p->info,p->link);
        else
            printf(" |%d|%08x|  ⎻⌍ ",p->info,p->link);
        p=p->link;
    }while(p!=last->link);
    printf("\n");
     do{
        if(p==last->link)
            printf("|    %08x   ",p);
        else if(p!=last)
            printf("    %08x   ",p);
        else
            printf("   %08x    |",p);
        p=p->link;
    }while(p!=last->link);
    printf("\n");
    printf("|");
    do{
        printf("_______________");\
        p=p->link;
    }while(p!=last->link);
    printf("|");
    printf("\n\n");
}
struct node *deleteAlternateNodes(struct node *last){
    struct node *p,*temp;
    if(last==NULL){
        printf("List Empty\n");
        return last;
    }
    p=last->link;
    do{
        temp=p->link;
        p->link=temp->link;
        if(temp==last){
            last=p;
        }
        free(temp);
        p=p->link;
    }while(p!=last->link && p->link!=last->link);
    return last;
}
int main(){
    struct node *last=NULL;
    last = createList(last);
    display(last);
    last = deleteAlternateNodes(last);
    display(last);
}