#include<stdio.h>
struct cricketer
{
    char name[30];
    int age;
    int noTest;
    float AvgRuns;
};
int main()
{
    struct cricketer a = {"Tarun",20,40,57.76};
    printf("Name = %s\nAge = %d\nNoTest = %d\nAvgRuns = %f",a.name,a.age,a.noTest,a.AvgRuns);
    return 0;   
}