/*Write a program to create a structure to store the information of n number of Employees. Employee’s
information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the
information of employees with gross salary. Use array of structure.*/
#include <stdio.h>
void main(){
    struct Employee{
        int emp_id;
        char name[30];
        char destination[30];
        float basic_salary;
        float hra_percentage;
        float da_percentage;
    };
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee emp[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Emp-id: ");
        scanf("%d", &emp[i].emp_id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Designation: ");
        scanf("%s", emp[i].destination);
        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);
        printf("HRA Percentage: ");
        scanf("%f", &emp[i].hra_percentage);
        printf("DA Percentage: ");
        scanf("%f", &emp[i].da_percentage);
    }
        printf("\nEmployee Details:\n");
        printf("Emp-id\tName\tDesignation\tBasic Salary\tHRA%%\tDA%%\tGross Salary\n");
        for (int i=0; i<n; i++)
        {
            float hra = (emp[i].hra_percentage / 100) * emp[i].basic_salary;
            float da = (emp[i].da_percentage / 100) * emp[i].basic_salary;
            float gross_salary = emp[i].basic_salary + hra + da;
            printf("%d\t%s\t%s\t%.2f\\tt%.2f\t\t%.2f\t\t%.2f\n", 
                emp[i].emp_id, emp[i].name, emp[i].destination, 
                emp[i].basic_salary, emp[i].hra_percentage, 
                emp[i].da_percentage, gross_salary);
        }
        printf("\n");
}