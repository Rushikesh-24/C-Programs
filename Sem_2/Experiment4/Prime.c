#include <stdio.h>
int main()
{
    int number, temp;
    printf("Enter the number ");
    scanf("%d", &number);
    if (number == 0)
    {
        printf("0 is neither prime nor composite");
        return 0;
    }
    temp = number - 1;
    while (temp > 1)
    {
        if (number % temp == 0)
        {
            printf("Not prime");
            return 0;
        }
        else
            temp--;
    }
    printf("prime");
    return 0;
}