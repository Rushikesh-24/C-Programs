#include <stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *Create(struct node *start);
struct node *addToBeg(struct node *start, int data);
struct node *addToEnd(struct node *start, int data);
void display(struct node *start);

int main()
{
    struct node *start=NULL;
    start = Create(start);
    display(start);
    return 0;
}
struct node *Create(struct node *start)
{
    int data, n,i;
    printf("Enter the number of nodes you mant to input");
    scanf("%d", &n);
    if (n == 0)
    {
        return start;
    }
    printf("Enter the data which have to be entered");
    scanf("%d", &data);
    start = addToBeg(start, data);
    for (i = 2; i <= n; i++){
        int data;
        printf("Enter the next data which have to be entered");
        scanf("%d", &data);
        start = addToEnd(start, data);
    }
    return start;
}

struct node *addToEnd(struct node *start, int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    p = start;
    while (p != NULL)
    {
        p = p->link;
    }
    temp->info = data;
    p->link = temp;
    temp->link = NULL;
    return start;
}

struct node *addToBeg(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = start;
    start = temp;
    return start;
}
void display(struct node *start){
  printf("\nHello world");
  struct node *p;
  p=start;
  if(start==NULL){
    printf("\nList is empty");
  }
  while(p!=NULL){
    printf("\n %d",p->info);
    p=p->link;
  }
  return;
}