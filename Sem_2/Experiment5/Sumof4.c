#include <stdio.h>
int Recursive(int);
int NonRecursive(int);
int main()
{
    int number, sum = 0;
    printf("Enter the number you want to find a sum ");
    scanf("%d", &number);
    sum = Recursive(number);
    printf("Sum using Recursive function is %d\n", sum);
    printf("Sum using Non recurcive function is %d\n", NonRecursive(number));
    return 0;
}
int Recursive(int number)
{
    if (number == 0)
        return 0;
    return (number % 10 + Recursive(number / 10));
}
int NonRecursive(int number)
{
    int remainder, sum = 0;
    while (number > 0)
    {
        remainder = number % 10;
        sum = sum + remainder;
        number /= 10;
    }
    return (sum);
}