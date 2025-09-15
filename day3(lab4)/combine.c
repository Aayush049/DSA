#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;

// Insert a node at specific position
void insert(int data, int position) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    

    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        struct node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted\n");
}

// Delete a node from specific position
void deleteNode(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    if (position == 1) {
        head = head->next;
        free(temp);
        printf("Node deleted\n");
        return;
    }
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    printf("Node deleted\n");
}

// Count nodes
void countNodes() {
    struct node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("The total number of nodes: %d\n", count);
}

// Traverse the list
void traverse() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("The list is: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("-> ");
        temp = temp->next;
    }
    printf("\n");
}

// Search for an element
void search(int data) {
    struct node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element %d found at position %d\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", data);
}

// Sort list in ascending order
void sort() {
    if (head == NULL || head->next == NULL) {
        printf("List is too small to sort\n");
        return;
    }
    struct node* current = head;
    struct node* index;
    int temp;
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    printf("List sorted in ascending order\n");
}

// Reverse the list
void rev() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next;
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;      
    }
    head = prev; 
    printf("List reversed successfully\n");
}

int main() {
    int n, data, choice, position;

    // Create initial list
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(data, i + 1); // insert sequentially
    }

    // Menu-driven program
    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traversal\n");
        printf("5. Search an element\n");
        printf("6. Sort the list in ascending order\n");
        printf("7. Reverse the list\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insert(data, position);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteNode(position);
                break;
            case 3:
                countNodes();
                break;
            case 4:
                traverse();
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 6:
                sort();
                break;
            case 7:
                rev();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}