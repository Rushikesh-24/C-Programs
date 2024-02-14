#include<stdio.h>
int main()
{
    int num1,num2,and,or;
    printf("Enter the two numbers");
    scanf("%d%d",&num1,&num2);
    and=num1&num2;
    or=num1|num2;
    printf("Bitwise AND operation of %d and %d gives %d and OR gives %d\n",num1,num2,and,or);
    return 0;
}