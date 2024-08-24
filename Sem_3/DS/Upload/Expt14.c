#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *addAtBeginning(int data, struct node *last) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = last->link;
    last->link = temp;
    return last;
}

struct node *addAtPosition(int data, int position, struct node *last) {
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    p = last->link;
    for (int i = 1; i < position - 1; i++) {
        p = p->link;
    }
    temp->link = p->link;
    p->link = temp;
    if (p == last) {
        last = temp;
    }
    return last;
}

struct node *addAfter(int data, int afterData, struct node *last) {
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    p = last->link;
    do {
        if (p->info == afterData) {
            temp->link = p->link;
            p->link = temp;
            if (p == last) {
                last = temp;
            }
            return last;
        }
        p = p->link;
    } while (p != last->link);
    printf("%d not found in the list\n", afterData);
    return last;
}

struct node *addBefore(int data, int beforeData, struct node *last) {
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (last->link->info == beforeData) {
        temp->link = last->link;
        last->link = temp;
        return last;
    }
    p = last->link;
    while (p->link != last->link) {
        if (p->link->info == beforeData) {
            temp->link = p->link;
            p->link = temp;
            return last;
        }
        p = p->link;
    }
    printf("%d not found in the list\n", beforeData);
    return last;
}

struct node *reverse(struct node *last) {
    struct node *prev, *current, *next;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    prev = last;
    current = last->link;
    next = current->link;
    do {
        current->link = prev;
        prev = current;
        current = next;
        next = next->link;
    } while (current != last->link);
    last->link = prev;
    return last;
}

struct node *search(int data, struct node *last) {
    struct node *p;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    p = last->link;
    do {
        if (p->info == data) {
            printf("%d found in the list\n", data);
            return last;
        }
        p = p->link;
    } while (p != last->link);
    printf("%d not found in the list\n", data);
    return last;
}

int count(struct node *last) {
    struct node *p;
    int count = 0;
    if (last == NULL) {
        printf("List is empty\n");
        return count;
    }
    p = last->link;
    do {
        count++;
        p = p->link;
    } while (p != last->link);
    printf("Number of nodes in the list: %d\n", count);
    return count;
}
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
            printf(" → |%d|%x|",p->info,p->link);
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
        printf("_______________");\
        p=p->link;
    }while(p!=last->link);
    printf("|");
    printf("\n");
}
struct node *deleteNode(int data, struct node *last) {
    struct node *temp, *p;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (last->link->info == data) {
        temp = last->link;
        last->link = temp->link;
        free(temp);
        return last;
    }
    p = last->link;
    while (p->link != last->link) {
        if (p->link->info == data) {
            temp = p->link;
            p->link = temp->link;
            free(temp);
            return last;
        }
        p = p->link;
    }
    printf("%d not found in the list\n", data);
    return last;
}
int main(){
    struct node *last = NULL;
    int choice, data, position, afterData, beforeData;
    
    do {
        printf("\n\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Add at Beginning\n");
        printf("4. Add at Position\n");
        printf("5. Add after Data\n");
        printf("6. Add before Data\n");
        printf("7. Reverse List\n");
        printf("8. Search Data\n");
        printf("9. Count Nodes\n");
        printf("10. Delete Nodes\n");
        printf("11. Add at End\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                last = createList(last);
                display(last);
                break;
            case 2:
                display(last);
                break;
            case 3:
                printf("Enter the data to add at the beginning: ");
                scanf("%d", &data);
                last = addAtBeginning(data, last);
                break;
            case 4:
                printf("Enter the data to add: ");
                scanf("%d", &data);
                printf("Enter the position to add at: ");
                scanf("%d", &position);
                last = addAtPosition(data, position, last);
                display(last);
                break;
            case 5:
                printf("Enter the data to add: ");
                scanf("%d", &data);
                printf("Enter the data after which to add: ");
                scanf("%d", &afterData);
                last = addAfter(data, afterData, last);
                display(last);
                break;
            case 6:
                printf("Enter the data to add: ");
                scanf("%d", &data);
                printf("Enter the data before which to add: ");
                scanf("%d", &beforeData);
                last = addBefore(data, beforeData, last);
                display(last);
                break;
            case 7:
                last = reverse(last);
                display(last);
                break;
            case 8:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                last = search(data, last);
                display(last);
                break;
            case 9:
                count(last);
                break;
            case 10:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                last = deleteNode(data, last);
                display(last);
                break;
            case 11:
                printf("Enter the data to add at the end: ");
                scanf("%d", &data);
                last = addAtEnd(data, last);
                display(last);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);
}