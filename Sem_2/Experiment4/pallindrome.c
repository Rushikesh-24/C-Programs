#include <stdio.h>
int main()
{
    int number, remainder, sum = 0, temp;
    printf("Enter the number ");
    scanf("%d", &number);
    temp = number;
    while (number > 0)
    {
        remainder = number % 10;
        sum = sum * 10 + remainder;
        number /= 10;
    }
    if (temp == sum)
        printf("The Entered number is a Pallindrome");
    else
        printf("The Entered number is not a pallindrome");
    return 0;
}