//Write a program to read two numbers and compare the numbers using function call by address.
#include<stdio.h>
void compare(int *a, int *b) 
{
    if (*a > *b)
        printf("%d is greater than %d\n", *a, *b);
    else if (*a < *b)
        printf("%d is less than %d\n", *a, *b);
    else
        printf("Both numbers are equal: %d = %d\n", *a, *b);
}
void main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    compare(&a, &b);
}