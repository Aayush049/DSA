#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    printf("Element deleted\n");
}

void isEmpty() {
    if (front == NULL)
        printf("Queue is Empty\n");
    else
        printf("Queue is not Empty\n");
}

void traverse() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    int choice, element;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. Traverse\n5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            traverse();
            break;
        case 5:
            while (front != NULL) {
                struct Node* temp = front;
                front = front->next;
                free(temp);
            }
            exit(0);
        default:
            printf("Invalid option!\n");
        }
    }
}