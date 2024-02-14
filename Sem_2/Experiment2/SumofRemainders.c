#include<stdio.h>
int main()
{
    int num1,num2,num3,num4,num5,remainder;
    printf("Enter the 5 numbers\n");
    scanf("%d%d%d%d%d",&num1,&num2,&num3,&num4,&num5);
    remainder = (num1%3)+(num2%3)+(num3%3)+(num4%3)+(num5%3);
    printf("The sum of remainders of the 5 number after dividing by 3 is %d\n",remainder);
    return 0;
}