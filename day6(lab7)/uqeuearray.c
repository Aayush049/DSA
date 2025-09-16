#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1, size;

void enqueue(int x) {
    if (rear == size - 1) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Element deleted\n");
        front++;
    }
}

void isEmpty() {
    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else
        printf("Queue is not Empty\n");
}

void isFull() {
    if (rear == size - 1)
        printf("Queue is Full\n");
    else
        printf("Queue is not Full\n");
}

void traverse() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

void main() {
    int choice, element;

    printf("Enter the size of Queue: ");
    scanf("%d", &size);
    queue = (int*)malloc(size * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

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
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            traverse();
            break;
        case 6:
            free(queue);
            exit(0);
        default:
            printf("Invalid option!\n");
        }
    }
    return 0;
}