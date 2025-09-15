/*Write a program to represent the given sparse matrix using header single linked list and
display it.*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for sparse matrix representation
struct Node {
    int row, col, value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
void insertNode(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display sparse matrix in 3-tuple format
void displaySparse(struct Node* head, int rows, int cols, int count) {
    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", rows, cols, count);

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d %d %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int rows, cols;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter elements of sparse matrix: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    struct Node* head = NULL;
    int count = 0;

    // Convert matrix to linked list
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                insertNode(&head, i, j, matrix[i][j]);
                count++;
            }
        }
    }

    // Display in 3-tuple format
    displaySparse(head, rows, cols, count);

    return 0;
}