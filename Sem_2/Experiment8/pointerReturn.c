#include<stdio.h>
int *sum(int *a, int *b);
int main()
{
 int a =20,b=20;
 int *c = sum(&a,&b);
 printf("sum=%d",*c);
 return 0;
}

int *sum(int *a, int *b)
{
    int c,*d;
    d=&c;
    c=*a+*b;
    return d;
}
