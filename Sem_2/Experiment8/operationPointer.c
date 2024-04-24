#include<stdio.h>
int main()
{
    float a =10,b=20;
    float *pointer = &a;
    float *pointer2 = &b;
    printf("Address of a = %u\n",pointer);
    pointer++;
    printf("Address after increment = %u\n",pointer);
    pointer--;
    printf("Address after decrement = %u\n",pointer);
    pointer-=8;
    printf("Address after Adding 5 = %u\n",pointer);
    pointer-=5;
    printf("Address after subtracting 8 = %u\n",pointer);
    if(pointer==pointer2)
    printf("Address is same");
    else
    printf("Address is different");
}