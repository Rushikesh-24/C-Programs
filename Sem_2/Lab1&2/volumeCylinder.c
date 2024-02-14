//Volume of Cylinder
#include<stdio.h>
int main()
{
    float radius,length,volume;
    printf("Enter radius and length \n");
    scanf("%f%f",&radius,&length);
    volume=(22*radius*radius*length)/7;
    printf("Volume=%f\n",volume);
    return 0;
}