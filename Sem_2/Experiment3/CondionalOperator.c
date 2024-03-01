#include <stdio.h>
int main()
{
    float a, b, c, greatest;
    printf("Enter the 3 numbers \n");
    scanf("%f%f%f", &a, &b, &c);
    greatest = a > b ? a > c ? a : c : b > c ? b
                                             : c;
    printf("Greatest of all is %f", greatest);
    return 0;
}