#include <stdio.h>
int main()
{
    int number,i=1;
    printf("Enter the number for which multiplication table is to be calculated:");
    scanf("%d", &number);
    do{
        printf("%d * %d = %d\n",number,i, number*i);
        i++;
    }while(i <11);
    return 0;
}