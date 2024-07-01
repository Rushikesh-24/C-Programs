#include <stdio.h>
#include <string.h>

struct sem
{
    char sub1;
    char sub2;
    char sub3;
    char sub4;
};
struct name
{
    char first_name[100];
    char middle_name[100];
    char last_name[100];
};
struct student
{
    struct name Name;
    struct sem sem1;
    struct sem sem2;
};
float grade(char grade)
{
    switch (grade)
    {
    case 'A':
        return 4.0;
    case 'B':
        return 3.0;
    case 'C':
        return 2.0;
    case 'D':
        return 1.0;
    case 'F':
        return 0.0;
    default:
        return 0.0;
    }
}
char gradeReverse(int grade)
{
    switch (grade)
    {
    case 4:
        return 'A';
    case 3:
        return 'B';
    case 2:
        return 'C';
    case 1:
        return 'D';
    case 0:
        return 'F';
    default:
        return 0.0;
    }
}

float c(struct sem semester)
{
    float totalPoints = 0.0;
    totalPoints += grade(semester.sub1);
    totalPoints += grade(semester.sub2);
    totalPoints += grade(semester.sub3);
    totalPoints += grade(semester.sub4);
    return totalPoints / 4;
}

int main()
{
    struct student rushi;
    int no_of_students = 0;
    printf("Enter the number of students");
    scanf("%d", &no_of_students);
    struct student class[no_of_students];
    for (int i = 0; i < no_of_students; i++)
    {
        printf("Enter first name\n");
        scanf("%s %s %s",&class[i].Name.first_name,&class[i].Name.middle_name,&class[i].Name.last_name);
        printf("Enter Semester 1 grade");
        scanf("%s %s %s %s",&class[i].sem1.sub1, &class[i].sem1.sub2, &class[i].sem1.sub3, &class[i].sem1.sub4);
        printf("Enter Semester 2 grade");
        scanf("%s %s %s %s",&class[i].sem2.sub1, &class[i].sem2.sub2, &class[i].sem2.sub3, &class[i].sem2.sub4);
        float gradePointSem1 = c(class[i].sem1);
        float gradePointSem2 = c(class[i].sem2);
        float total = (gradePointSem1 + gradePointSem2) / 2;
        char grade = gradeReverse(total);
        printf("Cumulative Grade : %c\n", grade);
    }
    return 0;
}