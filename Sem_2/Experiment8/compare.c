#include<stdio.h>
int compare(int *a,int *b);
int main()
{
    int arrayOne[] = {1, 2, 3, 4, 5};
    int arrayTwo[] = {1, 2, 3, 4, 5};
    int *a,*b;
    a=arrayOne;
    b=arrayTwo;
    int value = compare(arrayOne,arrayTwo);
    printf("%d",value);
    return 0;
}
int compare(int *a, int *b)
{
    for(int i=0;i<5;i++)
    {
        if (*a!=*b)
        return 0;
        else{
            a++;
            b++;
        } 
    }
    return 1;
}
