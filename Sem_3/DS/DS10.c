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
    struct node *p=last->link;
    printf("\n");
    do{
        if(p!=last)
            printf("\x1b[31m"" → |%d|%x|",p->info,p->link);
        else
            printf(" |%d|%x|  ⎻⌍ ",p->info,p->link);
        p=p->link;
    }while(p!=last->link);
    printf("\n");
     do{
        if(p==last->link)
            printf("|    %x   ",p);
        else if(p!=last)
            printf("    %x   ",p);
        else
            printf("   %x    |",p);
        p=p->link;
    }while(p!=last->link);
    printf("\n");
    printf("|");
    do{
        printf("________________");\
        p=p->link;
    }while(p!=last->link);
    printf("|");
    printf("\n");
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
    // printf("%lu %lu",sizeof(struct node),sizeof(struct node*));
}