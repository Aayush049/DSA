/*Write a menu driven program to create a stack using linked list and perform the following operation
using function
a. Push
b. Pop
c. IsEmpty
d. display the stack elements*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; // top of stack

// Function to push an element onto the stack
void push(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow!\n");
        return;
    }
    newNode->data = element;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("%d deleted from Stack\n", top->data);
    top = top->next;
    free(temp);
}

// Function to check if stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to traverse stack using while loop
void traverse() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main program
int main() {
    int choice, element;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to be pushed into the stack: ");
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
                traverse();
                break;

            case 5:
                // Free all nodes before exiting
                while (!isEmpty()) {
                    pop();
                }
                exit(0);

            default:
                printf("Invalid option! Try again.\n");
        }
    }
    return 0;
}
