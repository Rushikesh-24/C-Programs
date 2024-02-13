//celsius to fahrenheit
#include<stdio.h>
int main()
{
    int celsius,faren;
    printf("Enter temperature in degree celsius :");
    scanf("%d",celsius);
    faren=(9*celsius)/5+32;
    printf("%d degree celcius in farenheit is %d\n",celsius,faren);
    return 0;
}