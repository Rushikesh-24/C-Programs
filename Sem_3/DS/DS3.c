#include<stdio.h>
struct sem
{
    int sub1;
    int sub2;
    int sub3;
    int sub4;
    int sgpa;
};
struct name
{
    char first_name[100];
    char middle_name[100];
    char last_name[100];
};
struct student{
        struct name Name;
        struct sem sem1;
        struct sem sem2;
        char rollNo[20];
        float cgpa;
};
int sgpaCalculator(struct sem semester);
char gradeReverse(int marks);
float grade(int marks);
int main()
{
    int n;
    printf("Enter the number of students:");
    scanf("%d", &n);
    struct student classA[n];
    for(int i=0; i<n; i++)
    {
        printf("STUDENT %d\n", i+1);
        printf("Enter first name\n");
        scanf("%s %s %s",&classA[i].Name.first_name,&classA[i].Name.middle_name,&classA[i].Name.last_name);
        printf("\nEnter the Roll no of the student : ");
        scanf("%s",&classA[i].rollNo);
        printf("\nEnter semester 1 marks ");
        scanf("%d %d %d %d",&classA[i].sem1.sub1,&classA[i].sem1.sub2,&classA[i].sem1.sub3,&classA[i].sem1.sub4);
        printf("\nEnter semester 2 marks ");
        scanf("%d %d %d %d",&classA[i].sem2.sub1,&classA[i].sem2.sub2,&classA[i].sem2.sub3,&classA[i].sem2.sub4);
        classA[i].sem1.sgpa =  sgpaCalculator(classA[i].sem1);
        classA[i].sem2.sgpa =  sgpaCalculator(classA[i].sem2);
        classA[i].cgpa = classA[i].sem1.sgpa + classA[i].sem2.sgpa;
    }
    for(int i=0;i<n;i++)
    {
        printf("\nMarks of student %d: ",i+1);
        char a,b,c,d,e,f,g,h;
        a = gradeReverse(classA[i].sem1.sub1);
        b = gradeReverse(classA[i].sem1.sub2);
        c =gradeReverse(classA[i].sem1.sub3);
        d= gradeReverse(classA[i].sem1.sub4);
        e=gradeReverse(classA[i].sem2.sub1);
        f =gradeReverse(classA[i].sem2.sub2);
        g =gradeReverse(classA[i].sem2.sub3);
        h= gradeReverse(classA[i].sem2.sub4);
        printf("Semester 1\n");
        printf("Subject Code    Marks   Grade\n");
        printf("CE101           %d      %c\n",classA[i].sem1.sub1,a);
        printf("CE102           %d      %c\n",classA[i].sem1.sub2,b);
        printf("CE103           %d      %c\n",classA[i].sem1.sub3,c);
        printf("CE104           %d      %c\n",classA[i].sem1.sub4,d);
        printf("SGPA : %d",classA[i].sem1.sgpa);
        printf("\n\n");
        printf("Semester 1\n");
        printf("Subject Code    Marks   Grade\n");
        printf("CE101           %d      %c\n",classA[i].sem2.sub1,e);
        printf("CE102           %d      %c\n",classA[i].sem2.sub2,f);
        printf("CE103           %d      %c\n",classA[i].sem2.sub3,g);
        printf("CE104           %d      %c\n",classA[i].sem2.sub4,h);
        printf("SGPA : %d",classA[i].sem2.sgpa);
    }
    return 0;
}
float grade(int marks)
{
    if(marks>107)
    {
        return 10.0;
    }
    else if(marks > 94)
    {
        return 9.0;
    }
    else if(marks > 82)
    {
        return 8.0;
    }
    else if(marks > 69)
    {
        return 7.0;
    }
    else if(marks > 63)
    {
        return 6.0;
    }
    else if(marks > 57)
    {
        return 5.0;
    }
    else if(marks > 50)
    {
        return 4.0;
    }
    else {
        return 0.0;
    }
}
int sgpaCalculator(struct sem semester)
{
    int gradeofsub1 = (grade(semester.sub1)+grade(semester.sub2)+grade(semester.sub3)+grade(semester.sub4))/4;
    return gradeofsub1;
}

char gradeReverse(int marks){
    if(marks>107)
    {
        return '0';
    }
    else if(marks > 94)
    {
        return 'A';
    }
    else if(marks > 82)
    {
        return 'A';
    }
    else if(marks > 69)
    {
        return 'B';
    }
    else if(marks > 63)
    {
        return 'B';
    }
    else if(marks > 57)
    {
        return 'C';
    }
    else if(marks > 50)
    {
        return 'P';
    }
    else {
        return 'F';
    }
}