#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;
    int power;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Insert at end of linked list
void insert(struct Node** head, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            insert(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            insert(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power == poly2->power) {
            insert(&result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->power > poly2->power) {
            insert(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else {
            insert(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
    }
    return result;
}

// Function to display polynomial
void display(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->power);
        poly = poly->next;
        if (poly != NULL)
            printf("+");
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    int maxPower, coeff;

    // Polynomial 1
    printf("Polynomial-1:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxPower);
    for (int i = maxPower; i >= 0; i--) {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        insert(&poly1, coeff, i);
    }

    // Polynomial 2
    printf("\nPolynomial-2:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxPower);
    for (int i = maxPower; i >= 0; i--) {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        insert(&poly2, coeff, i);
    }

    // Add polynomials
    sum = addPolynomials(poly1, poly2);

    // Display result
    printf("\nSum: ");
    display(sum);

    return 0;
}
