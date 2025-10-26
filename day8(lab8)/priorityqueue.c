#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;

// Function to insert an element into the priority queue
void enqueue(int val, int pri) {
    struct node *temp, *q;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->priority = pri;
    temp->next = NULL;

    // If queue is empty or new node has higher priority
    if (front == NULL || pri < front->priority) {
        temp->next = front;
        front = temp;
    } else {
        q = front;
        while (q->next != NULL && q->next->priority <= pri)
            q = q->next;
        temp->next = q->next;
        q->next = temp;
    }
}

// Function to remove the highest priority element
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("Deleted item: %d (Priority %d)\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

// Function to display all elements
void display() {
    struct node *q = front;
    if (q == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Priority Queue:\nPriority\tItem\n");
    while (q != NULL) {
        printf("%d\t\t%d\n", q->priority, q->data);
        q = q->next;
    }
}

int main() {
    int ch, val, pri;
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                printf("Enter priority: ");
                scanf("%d", &pri);
                enqueue(val, pri);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
