//Final Code for Semester Result
#include <stdio.h>
struct sem
{
    int sub1;
    int sub2;
    int sub3;
    int sub4;
    float sgpa;
    char sub_code1[10];
    char sub_code2[10];
    char sub_code3[10];
    char sub_code4[10];
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
    char rollNo[20];
    float cgpa;
};

float grade(int marks);
float sgpaCalculator(struct sem semester);
char *gradeReverse(int marks);
void printSemesterMarks(struct student s, int sem);

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student classA[n];
    for (int i = 0; i < n; i++)
    {
        printf("STUDENT %d\n", i + 1);
        printf("Enter first name: ");
        scanf("%s", classA[i].Name.first_name);
        printf("Enter middle name: ");
        scanf("%s", classA[i].Name.middle_name);
        printf("Enter last name: ");
        scanf("%s", classA[i].Name.last_name);
        printf("Enter Roll number: ");
        scanf("%s", classA[i].rollNo);

        // Input for Semester 1
        printf("Enter semester 1 subject code and marks for subject 1: ");
        scanf("%s %d", classA[i].sem1.sub_code1, &classA[i].sem1.sub1);
        printf("Enter semester 1 subject code and marks for subject 2: ");
        scanf("%s %d", classA[i].sem1.sub_code2, &classA[i].sem1.sub2);
        printf("Enter semester 1 subject code and marks for subject 3: ");
        scanf("%s %d", classA[i].sem1.sub_code3, &classA[i].sem1.sub3);
        printf("Enter semester 1 subject code and marks for subject 4: ");
        scanf("%s %d", classA[i].sem1.sub_code4, &classA[i].sem1.sub4);

        // Input for Semester 2
        printf("Enter semester 2 subject code and marks for subject 1: ");
        scanf("%s %d", classA[i].sem2.sub_code1, &classA[i].sem2.sub1);
        printf("Enter semester 2 subject code and marks for subject 2: ");
        scanf("%s %d", classA[i].sem2.sub_code2, &classA[i].sem2.sub2);
        printf("Enter semester 2 subject code and marks for subject 3: ");
        scanf("%s %d", classA[i].sem2.sub_code3, &classA[i].sem2.sub3);
        printf("Enter semester 2 subject code and marks for subject 4: ");
        scanf("%s %d", classA[i].sem2.sub_code4, &classA[i].sem2.sub4);

        classA[i].sem1.sgpa = sgpaCalculator(classA[i].sem1);
        classA[i].sem2.sgpa = sgpaCalculator(classA[i].sem2);
        classA[i].cgpa = (classA[i].sem1.sgpa + classA[i].sem2.sgpa) / 2.0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nMarks of student %d:\n", i + 1);
        printSemesterMarks(classA[i], 1);
        printSemesterMarks(classA[i], 2);
        printf("CGPA: %.2f\n", classA[i].cgpa);
    }

    return 0;
}

float grade(int marks)
{
    if (marks > 107)
        return 10.0;
    if (marks > 99)
        return 9.5; // A+
    if (marks > 94)
        return 9.0; // A
    if (marks > 86)
        return 8.5; // B+
    if (marks > 82)
        return 8.0; // B
    if (marks > 69)
        return 7.0;
    if (marks > 63)
        return 6.0;
    if (marks > 57)
        return 5.0;
    if (marks > 50)
        return 4.0;
    return 0.0;
}

float sgpaCalculator(struct sem semester)
{
    return (grade(semester.sub1) + grade(semester.sub2) + grade(semester.sub3) + grade(semester.sub4)) / 4;
}

char *gradeReverse(int marks)
{
    if (marks > 107)
        return "O";
    if (marks > 99)
        return "A+"; // A+
    if (marks > 94)
        return "A";
    if (marks > 86)
        return "B+"; // B+
    if (marks > 82)
        return "B";
    if (marks > 69)
        return "C";
    if (marks > 63)
        return "D";
    if (marks > 57)
        return "E";
    if (marks > 50)
        return "P";
    return "F";
}

void printSemesterMarks(struct student s, int sem)
{
    struct sem currentSem = (sem == 1) ? s.sem1 : s.sem2;
    printf("Semester %d\n", sem);
    printf("%-10s %-6s %-5s\n", "Sub Code", "Marks", "Grade");
    printf("%-10s %-6d %-5s\n", currentSem.sub_code1, currentSem.sub1, gradeReverse(currentSem.sub1));
    printf("%-10s %-6d %-5s\n", currentSem.sub_code2, currentSem.sub2, gradeReverse(currentSem.sub2));
    printf("%-10s %-6d %-5s\n", currentSem.sub_code3, currentSem.sub3, gradeReverse(currentSem.sub3));
    printf("%-10s %-6d %-5s\n", currentSem.sub_code4, currentSem.sub4, gradeReverse(currentSem.sub4));
    printf("SGPA: %.2f\n", currentSem.sgpa);
}
