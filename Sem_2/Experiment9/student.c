#include<stdio.h>
struct student
{
    int RollNo;
    char Name[30];
    char Department[30];
    char course[30];
    int year;
};
int yearCheck(struct student a[]);
int main()
{
    struct student stud[5];
    for(int i=0; i<5; i++)
    {
        printf("Enter the Roll no ,Name ,Department ,Course and year of joining of student %d\n",i+1);
        scanf("%d%s%s%s%d",&stud[i].RollNo,&stud[i].Name,&stud[i].Department,&stud[i].course,&stud[i].year);
    }
    yearCheck(stud);
}
int yearCheck(struct student a[])
{
    int year;
    printf("What is the year?");
    scanf("%d",&year);
    for(int i = 0; i < 5; i++){
        if(a[i].year == year)
        printf("%s\n",a[i].Name);
    }
    return 0;
}
