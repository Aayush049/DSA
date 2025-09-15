/*Write a menu driven program to create a structure to represent complex number and perform the
following operation using function :
1. addition of two complex number (call by value)
2. multiplication of two complex number (call by value)*/
#include<stdio.h>
int main() {
    struct Complex {
        float real;
        float imag;
    };
    struct Complex nums[2];
    for (int i = 0; i < 2; i++) {
        printf("Enter complex number %d: ", i + 1);
        scanf("%f %f", &nums[i].real, &nums[i].imag);
    }

    printf("MENU\n1. addition\n2. multiplication\n");
    int choice;
    printf("Enter the choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Sum = %f + %fi\n", (nums[0].real + nums[1].real), (nums[0].imag + nums[1].imag));
            break;
        case 2:
            float real = nums[0].real * nums[1].real - nums[0].imag * nums[1].imag;
            float imag = nums[0].imag * nums[1].real + nums[0].real * nums[1].imag;
            printf("Multiplication = %f + %fi\n", real, imag);
            break;
        default:
            printf("Invalid choice.");
            break;
    }
}