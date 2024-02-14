//modulo division by 2 and 3
#include<stdio.h>
int main()
{
    int num;
    printf("Enter the number");
    scanf("%d", &num);
    printf("%d modulo by 2 gives %d number modulo by 3 gives %d\n",num,num%2,num%3);
    return 0;
}