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

int main()
{
    struct node *start = NULL;
    int choice, item;

    do
    {
        printf("\n1. Create\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Search\n");
        printf("5. Enter element at the beginning\n");
        printf("6. Enter element at the end\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = Create(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            counting(start);
            break;
        case 4:
            printf("Enter element to be searched: ");
            scanf("%d", &item);
            searching(start, item);
            break;
        case 5:
            printf("Enter the element to be entered at the start");
            scanf("%d", &item);
            start = addToBeg(start, item);
            break;
        case 6:
            printf("Enter the element to be entered at the end");
            scanf("%d", &item);
            start = addToEnd(start, item);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid input\n");
        }
    } while (choice != 7);

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
