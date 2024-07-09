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
void display(struct node *start);
void counting(struct node *start);
void searching(struct node *start, int item);
struct node *intersection(struct node *start1, struct node *start2);
struct node *unionAtEnd(struct node *start1, struct node *start2);
struct node *unionAtBeg(struct node *start1, struct node *start2);
struct node *subtraction(struct node *start1, struct node *start2);
int isPresent(struct node *start, int data);

int main()
{
    struct node *start1 = NULL,*start2 = NULL;
    int choice, item;

    do
    {
        printf("\n1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Intersection\n");
        printf("6. Union at End\n");
        printf("7. Union at Beginning\n");
        printf("8. Subtraction\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start1 = Create(start1);
            break;
        case 2:
            start2 = Create(start2);
            break;
        case 3:
            display(start1);
            break;
        case 4:
            display(start2);
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
            exit(0);
        default:
            printf("Invalid input\n");
        }
    } while (choice != 9);

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