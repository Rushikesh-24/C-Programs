//simple interest
#include<stdio.h>
int main()
{

float r,t,p,Si;
printf("Enter principal amount ,rate of interest and time\n");
scanf("%f%f%f",&p,&r,&t);
Si=(p*r*t)/100;
printf("Simple interest is %f\n",Si);
printf("Final amount = %f\n",Si+p);
return 0;
}