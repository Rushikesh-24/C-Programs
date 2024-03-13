#include<stdio.h>
int main()
{
    float number,fact=1,sum=0;
    printf("Enter the number ");
    scanf("%f", &number);
    for (int i = 1; i <= number; i++)
    {
        fact = fact * i;
        sum+= 1/fact;
    }
        printf("%f ",sum );
}