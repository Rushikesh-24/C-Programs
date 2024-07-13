#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *Create(struct node *start);
struct node *addToBeg(struct node *start, int data);
struct node *addToEnd(struct node *start, int data);
struct node *addAtPost(struct node *start, int data, int pos);
void display(struct node *start);
void counting(struct node *start);
void searching(struct node *start, int item);
struct node *intersection(struct node *start1, struct node *start2);
struct node *unionAtEnd(struct node *start1, struct node *start2);
struct node *unionAtBeg(struct node *start1, struct node *start2);
struct node *subtraction(struct node *start1, struct node *start2);
int isPresent(struct node *start, int data);
struct node *reverse(struct node *start);
struct node *delete(struct node *start,int data);

int main()
{
    struct node *start1 = NULL, *start2 = NULL;
    int choice, item, pos;

    do
    {
        printf("\n1. Create List \n");
        printf("2. Display List \n");
        printf("3. Add at beggining of list\n");
        printf("4. Add at end of list\n");
        printf("5. Intersection\n");
        printf("6. Union on list 1\n");
        printf("7. Union on list 2\n");
        printf("8. Subtraction\n");
        printf("9. Add at a position in list \n");
        printf("10. Searching\n");
        printf("11. Counting the number of elements\n");
        printf("12.Reverse a list\n");
        printf("13.Delete a element\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter 1 to create linked list 1\n");
            printf("Enter 2 to create linked list 2\n");
            scanf("%d", &pos);
            if (pos == 1)
            {
                start1 = Create(start1);
                display(start1);
            }
            else
            {
                start2 = Create(start2);
                display(start2);
            }
            break;
        case 2:
            printf("Enter 1 to display elements the linked list 1\n");
            printf("Enter 2 to display elements the linked list 2\n");
            scanf("%d", &pos);
            if (pos == 1)
                display(start1);
            else
                display(start2);
            break;
        case 3:
            printf("Enter 1 to enter elements at beginning in the linked list 1\n");
            printf("Enter 2 to enter elements at beginning in the linked list 2\n");
            scanf("%d", &pos);
            if (pos == 1)
            {
                printf("Enter the element to be entered at beggining of list1 :");
                scanf("%d", &item);
                start1 = addToBeg(start1, item);
                display(start1);
            }
            else
            {
                printf("Enter the element to be entered at beggining of list2 :");
                scanf("%d", &item);
                start2 = addToBeg(start2, item);
                display(start2);
            }
            break;
        case 4:
            printf("Enter 1 to enter elements at end in the linked list 1\n");
            printf("Enter 2 to enter elements at end in the linked list 2\n");
            scanf("%d", &pos);
            if (pos == 1)
            {
                printf("Enter the element to be entered at the end of list1 :");
                scanf("%d", &item);
                start1 = addToEnd(start1, item);
                display(start1);
            }
            else
            {
                printf("Enter the element to be entered at the end of list2 :");
                scanf("%d", &item);
                start2 = addToEnd(start2, item);
                display(start2);
            }
            break;
        case 5:
            display(intersection(start1, start2));
            break;
        case 6:
            display(unionAtEnd(start1, start2));
            break;
        case 7:
            display(unionAtBeg(start1, start2));
            break;
        case 8:
            display(subtraction(start1, start2));
            break;
        case 9:
            printf("Enter 1 to enter elements at in the linked list 1\n");
            printf("Enter 2 to enter elements at in the linked list 2\n");
            scanf("%d", &pos);
            if (pos == 1)
            {
                printf("Enter the element to be entered and its position in the linked list 1 : ");
                scanf("%d%d", &item, &pos);
                start1 = addAtPost(start1, item, pos);
                display(start1);
            }
            else
            {
                printf("Enter the element to be entered and its position in the linked list 2 : ");
                scanf("%d%d", &item, &pos);
                start2 = addAtPost(start2, item, pos);
                display(start2);
            }
            break;
        case 10:
            printf("Enter 1 to search elements at in the linked list 1\n");
            printf("Enter 2 to search elements at in the linked list 2\n");
            scanf("%d", &pos);
            if (pos == 1)
            {
                printf("Enter the element to be searched in the linked list 1 : ");
                scanf("%d", &item);
                searching(start1, item);
            }
            else
            {
                printf("Enter the element to be searched in the linked list 2 : ");
                scanf("%d", &item);
                searching(start2, item);
            }

            break;
        case 11:
            printf("Enter 1 to count elements in the linked list 1\n");
            printf("Enter 2 to count elements in the linked list 2\n");
            scanf("%d", &pos);
            if (pos == 1)
            {

                counting(start1);
            }
            else
            {
                counting(start2);
            }
            break;
        case 12:
            printf("Enter 1 to count elements in the linked list 1\n");
            printf("Enter 2 to count elements in the linked list 2\n");
            scanf("%d", &pos);
            if (pos == 1)
            {
                start1 = reverse(start1);
                display(start1);
            }
            else{
                start2 = reverse(start2);
                display(start2);
            }
            break;
        case 13:
            printf("Enter 1 to delete elements in the linked list 1\n");
            printf("Enter 2 to delete elements in the linked list 2\n");
            scanf("%d", &pos);
            if (pos == 1)
            {
                printf("Enter data to be deleted");
                scanf("%d", &item);
                start1 = delete(start1,item);
                display(start1);
            }
            else{
                printf("Enter data to be deleted");
                scanf("%d", &item);
                start2 = delete(start2,item);
                display(start2);
            }
            break;
        case 14:
            exit(0);
        default:
            printf("Invalid input\n");
            break;
        }
    } while (choice != 14);

    return 0;
}

struct node *Create(struct node *start)
{
    int data, n, i;
    printf("Enter the number of nodes you want to input: ");
    scanf("%d", &n);
    if (n == 0)
    {
        return start;
    }
    printf("Enter the data to be entered: ");
    scanf("%d", &data);
    start = addToBeg(start, data);
    for (i = 2; i <= n; i++)
    {
        printf("Enter the next data to be entered: ");
        scanf("%d", &data);
        start = addToEnd(start, data);
    }
    return start;
}

struct node *addToEnd(struct node *start, int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = NULL;

    if (start == NULL)
    {
        return temp;
    }

    p = start;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = temp;
    return start;
}

struct node *addAtPost(struct node *start, int data, int pos)
{
    struct node *temp, *p = start;
    int i;
    if (pos == 1)
    {
        start = addToBeg(start, data);
        return start;
    }
    for (i = 1; i < pos - 1 && p != NULL; i++)
    {
        p = p->link;
    }
    if (p == NULL)
    {
        printf("Less item than position %d\n", i);
        return start;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = p->link;
        p->link = temp;
        return start;
    }
    printf("\nControl should not reach here\n");
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

void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }
    p = start;
    printf("Contents of the list are:");
    while (p != NULL)
    {
        printf(" %d", p->info);
        p = p->link;
    }
    printf("\n");
}

void counting(struct node *start)
{
    struct node *p;
    int cnt = 0;
    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }
    p = start;
    while (p != NULL)
    {
        cnt++;
        p = p->link;
    }
    printf("Number of nodes are: %d\n", cnt);
}

void searching(struct node *start, int item)
{
    struct node *p;
    int pos = 1;
    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }
    p = start;
    while (p != NULL)
    {
        if (p->info == item)
        {
            printf("Item %d found at position %d\n", item, pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Item %d not found\n", item);
}

struct node *intersection(struct node *start1, struct node *start2)
{
    struct node *result = NULL, *p1 = start1, *p2;
    while (p1 != NULL)
    {
        p2 = start2;
        while (p2 != NULL)
        {
            if (p1->info == p2->info)
            {
                result = addToEnd(result, p1->info);
                break;
            }
            p2 = p2->link;
        }
        p1 = p1->link;
    }
    return result;
}

struct node *unionAtEnd(struct node *start1, struct node *start2)
{
    struct node *result = NULL, *p = start1;
    while (p != NULL)
    {
        if (!isPresent(result, p->info))
        {
            result = addToEnd(result, p->info);
        }
        p = p->link;
    }
    p = start2;
    while (p != NULL)
    {
        if (!isPresent(result, p->info))
        {
            result = addToEnd(result, p->info);
        }
        p = p->link;
    }
    return result;
}

struct node *unionAtBeg(struct node *start1, struct node *start2)
{
    struct node *result = NULL, *p = start2;
    while (p != NULL)
    {
        if (!isPresent(result, p->info))
        {
            result = addToBeg(result, p->info);
        }
        p = p->link;
    }
    p = start1;
    while (p != NULL)
    {
        if (!isPresent(result, p->info))
        {
            result = addToBeg(result, p->info);
        }
        p = p->link;
    }
    return result;
}

struct node *subtraction(struct node *start1, struct node *start2)
{
    struct node *result = NULL, *p1 = start1, *p2;
    int found;
    while (p1 != NULL)
    {
        p2 = start2;
        found = 0;
        while (p2 != NULL)
        {
            if (p1->info == p2->info)
            {
                found = 1;
                break;
            }
            p2 = p2->link;
        }
        if (!found)
        {
            result = addToEnd(result, p1->info);
        }
        p1 = p1->link;
    }
    return result;
}

int isPresent(struct node *start, int data)
{
    struct node *p = start;
    while (p != NULL)
    {
        if (p->info == data)
        {
            return 1;
        }
        p = p->link;
    }
    return 0;
}

struct node *reverse(struct node *start)
{
    struct node *prev, *next, *ptr;
    prev = NULL;
    ptr = start;
    while (ptr != NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    return start;
}

struct node *delete(struct node *start,int data){
    struct node *temp,*p=start;
    if(start == NULL){
        printf("List is empty\n");
        return start;
    }
    if(start->info == data){
        temp = start;
        start = start->link;
        free(temp);
        return start;
    }
    while(p->link != start){
        if(p->link->info == data){
            temp = p->link;
            p->link=temp->link;
            free(temp);
            return start;
        }
        p=p->link;
    }
    printf("Element not found\n");
    return start;
}