#include <stdio.h>
int main()
{
    float pc, sum;
    printf("enter the number of pc");
    scanf("%f", &pc);
    if (pc <= 100)
    {
        sum = 200;
    }
    else if (pc <= 150)
    {
        sum = 200 + 0.6 * (pc - 100);
    }
    else if (pc <= 200)
    {
        sum = 200 + 0.6 * 50 + 0.5 * (pc - 150);
    }
    else
    {
        sum = 200 + 0.6 * 50 + 0.5 * 50 + 0.4 * (pc - 200);
    }
    printf("%f", sum);
    return 0;
}