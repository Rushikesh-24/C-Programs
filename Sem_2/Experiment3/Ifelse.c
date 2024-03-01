#include<stdio.h>
int main()
{
    float a,b,c,greatest;
    printf("Enter the 3 numbers \n");
    scanf("%f%f%f",&a,&b,&c);
    if(a>b)
    {
        if(a>c)
        {
            greatest = a;
        }
        else{
            greatest = c;
        }
    }
    else{
        if (b>c)
        {
            greatest = b;
        }
        else{
            greatest = c;
        }
        
    }
    printf("Greatest of all is %f",greatest);
    return 0;
}