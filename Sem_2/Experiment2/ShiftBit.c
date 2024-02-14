#include<stdio.h>
int main()
{
    int number;
    printf("Enter the number");
    scanf("%d", &number);
    number=number>>3;
    printf("Shifting by 3 bits gives = %d\n",number);
    return 0;
}