//(x*y*z)/(x*y)
//(2*x)/(y+z)
#include <stdio.h>
int main()
{
    float x, y, z, exp1, exp2;
    printf("Enter x,y,z\n");
    scanf("%f%f%f", &x, &y, &z);
    exp1 = (x*y*z)/(x-y);
    exp2 = (2*x)/(y+z);
    printf("Expression (x*y*z)/(x*y) gives %f\nExpression (2*x)/(y+z) gives %f\n", exp1,exp2);
    return 0;
}