// function to calculate leap year
#include <stdio.h>
void leapYear(int);
int main()
{
    int year;
    printf("Enter year");
    scanf("%d", &year);
    leapYear(year);
    return 0;
}
void leapYear(int year)
{
    if(year == 1900)
    {
        printf("Not a leap year");
    }
    else if (year % 4 == 0)
    {
        printf("Leap year");
    }
    else
    {
        printf("Not a leap year");
    }
}
