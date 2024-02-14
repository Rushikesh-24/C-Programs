//swapping two numbers using a temporary variable
#include<stdio.h>
int main(){
    int num1,num2,temp;
    printf("Enter numbers which have to be swapped\t");
    scanf("%d%d",&num1,&num2);
    printf("Numbers before swapping num1=%d num2=%d\n",num1,num2);
    temp=num2;
    num2=num1;
    num1=temp;
    printf("Numbers after swapping num1=%d num2=%d\n",num1,num2);
    return 0;
}