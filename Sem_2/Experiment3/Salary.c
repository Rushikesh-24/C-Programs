#include<stdio.h>
int main()
{
    float Basesalary,DA,HRA,Gross_salary;
    printf("Enter the base salary");
    scanf("%f", &Basesalary);
    if(Basesalary <= 25000)
    {
        DA=0.1*Basesalary;
        HRA=0.15*Basesalary;
    }
    else if (Basesalary <= 40000)
    {
        DA=0.12*Basesalary;
        HRA=0.18*Basesalary;
    }
    else{
        DA=0.15*Basesalary;
        HRA=0.2*Basesalary;
    }
    Gross_salary=DA+HRA+Basesalary;
    printf("Gross salary is %f\n",Gross_salary);
    return 0;
}