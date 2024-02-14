//Sum and average of 4 numbers
#include<stdio.h>
int main()
{
    float num1,num2,num3,num4,average,sum;
    printf("Enter 4 numbers :");
    scanf("%f%f%f%f",&num1,&num2,&num3,&num4);
    sum=num1+num2+num3+num4;
    average=(sum)/4;
    printf("Sum = %f \t Average=%f\n",sum,average);
    return 0;
}