//Farenheit to celsius
#include<stdio.h>
int main()
{
    float celcius,faren;
    printf("Enter temperature in degree farenheit :");
    scanf("%f",&faren);
    celcius=((faren-32)/9)*5;
    printf("%f degree farenheit in celcius is %f\n",faren,celcius);
    return 0;
}