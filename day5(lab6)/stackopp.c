/*6.1 Write a menu driven program to create a stack using array and perform the following operation using
function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements*/

#include <stdio.h>
#include <stdlib.h>
int top = -1;
int size;   // stack size will be entered by user
int *stack; // dynamic array for stack
int isEmpty();
int isFull();
// Function to push element
void push(int element) {
    if (isFull()) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        stack[top] = element;
    }
}
// Function to pop element
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
    } else {
        printf("%d deleted from Stack\n", stack[top]);
        top--;
    }
}
// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}
// Function to check if stack is full
int isFull() {
    return top == size - 1;
}
// Function to display stack
void traverse() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
void main() {
    int choice, element;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    // Dynamic memory allocation for stack
    stack = (int*)malloc(size * sizeof(int));
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
    while (1) {
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty())
                    printf("Stack empty: True\n");
                else
                    printf("Stack empty: False\n");
                break;
            case 4:
                if (isFull())
                    printf("Stack full: True\n");
                else
                    printf("Stack full: False\n");
                break;
            case 5:
                traverse();
                break;
            case 6:
                free(stack); // free allocated memory
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    }
}