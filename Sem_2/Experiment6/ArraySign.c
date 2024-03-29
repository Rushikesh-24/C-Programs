#include<stdio.h>
int main()
{
    int array[10],pos=0,neg=0,even=0,odd=0;
    printf("Enter 10 numbers of the array");
    for(int i=0;i<10;i++)
    {
        scanf("%d", &array[i]);
    }
    for(int i=0;i<10;i++)
    {
        if(array[i]>=0)
        {
            pos++;
        }
        else{
            neg++;
        }
        if(array[i]%2==0)
        {
            even++;
        }
        else{
            odd++;
        }
    }
    printf("Positive = %d\nNegative = %d\nEven = %d\nOdd = %d",pos,neg,even,odd);
    return 0;
}