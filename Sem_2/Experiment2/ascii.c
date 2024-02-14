#include<stdio.h>
int main()
{
    char exp1,exp2,exp3;
    exp1 = 'A'-'D';
    exp2 = 'a'-'D';
    exp3 = 'd'-'a';
    printf("A-D gives %d\na-D gives %d\nd-a gives %d\n",exp1,exp2,exp3);
    return 0;
}