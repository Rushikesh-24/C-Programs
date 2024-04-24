#include<stdio.h>
int main()
{
    int arrayOne[] = {1, 2, 3, 4, 5};
    int *a;
    int sum=0;
    a=arrayOne;
    for(int i = 0; i < 5; i++)
    {
        printf("Address of Array at index %d = %u and value=%d\n", i,a,*a);
        sum+=*a;
        a++;
    }
    printf("Sum=%d\n",sum);
}