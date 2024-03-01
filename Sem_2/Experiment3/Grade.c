#include<stdio.h>
int main()
{
    float marks;
    printf("Enter the marks ");
    scanf("%f", &marks);
    if(marks>=90)
    {
        printf("\nA+");
    }
    else if(marks>=80){
            printf("\nA");
        }
        else if (marks>=70)
            {
                printf("\nB");
            }
            else if (marks>=60)
            {
                printf("\nC");
            }
            else if (marks>=50)
            {
                printf("\nD");
            }
            else
            {
                printf("\nFail");
            }
            return 0;
        }
        