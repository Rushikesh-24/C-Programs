#include<stdio.h>
int main(void)
{
    char operation;
    float a,b;
    printf("Enter the operation to be processed");
    scanf("%c", &operation);
    printf("Enter the numbers");
    scanf("%f%f", &a,&b);
   
    switch(operation){
        case '+':
        printf("Addition gives %f",a+b);
        break;
        case '-':
        printf("Subtraction gives %f",a-b);
        break;
        case '*':
        printf("Multiplication gives %f",a*b);
        break;
        case '/':
        printf("Multiplication gives %f",a/b);
        break;
        default:
        printf("Invalid operation");
        break;
    }
    return 0;
}
