#include<stdio.h>
void swap(int *a, int *b); 
int main()
{
    int num1 = 5 , num2 = 10;
    printf("\nBefore swapping numbers are %d and %d", num1, num2);
    swap(&num1,&num2);
    printf("\nAfter swapping numbers are %d and %d", num1, num2);
    return 0;
}
void swap(int *num1, int *num2)
{
    int temp =  *num1;
    *num1 = *num2;
    *num2= temp;
}