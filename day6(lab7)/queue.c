/*Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue,
Traverse, IsEmpty, IsFull using array.*/

#include <stdio.h>
#include <stdlib.h>

int *cqueue;
int front = -1, rear = -1, size;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % size == front);
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1) {
        
    }
}



int main() {
    int choice, element;

    printf("Enter Queue size: ");
    scanf("%d", &size);

    cqueue = (int*)malloc(size * sizeof(int));

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
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
            printf("Queue Empty: %s\n", isEmpty() ? "True" : "False");
            break;
        case 4:
            printf("Queue Full: %s\n", isFull() ? "True" : "False");
            break;
        case 5:
            traverse();
            break;
        case 6:
            free(cqueue);
            exit(0);
        default:
            printf("Invalid option!\n");
        }
    }
    return 0;
}