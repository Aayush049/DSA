/*WAP to represent the polynomial of single variable using 1-D array and perform the addition of two
polynomial equations.*/

#include <stdio.h>

void main() {
    int degree, i;

    printf("Enter maximum degree of x: ");
    scanf("%d", &degree);

    int poly1[degree + 1], poly2[degree + 1], result[degree + 1];

    printf("Enter Polynomial-1 from lowest degree to highest degree: ");
    for (i = 0; i <= degree; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter Polynomial-2: ");
    for (i = 0; i <= degree; i++) {
        scanf("%d", &poly2[i]);
    }

    // Polynomial Addition
    for (i = 0; i <= degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }

    // Printing Result
    printf("Resultant Polynomial: ");
    for (i = degree; i >= 0; i--) {
        if (i != 0)
            printf("%dx^%d+", result[i], i);
        else
            printf("%dx^%d", result[i], i);
    }
}
