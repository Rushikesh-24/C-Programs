#include<stdio.h>
int main()
{
    float array[10],sum=0;
    printf("Enter 10 numbers of the array");
    for(int i=0;i<10;i++)
    {
        scanf("%f", &array[i]);
    }
    for(int i=0;i<10;i++)
    {
        sum += array[i];
    }
    printf("sum = %f\n",sum);
    return 0;
}