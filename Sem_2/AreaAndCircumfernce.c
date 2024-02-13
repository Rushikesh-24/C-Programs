//Area and Circumference of a Circle
#include<stdio.h>
int main()
{
    float area,circumference,radius;
    printf("Enter the radius of a circle :");
    scanf("%f",&radius);
    area=(22*radius*radius)/7;
    circumference=(2*22*radius)/7;
    printf("Area = %f \t Circumference=%f\n",area,circumference);
    return 0;
}