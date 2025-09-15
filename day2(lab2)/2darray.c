/*Write a program to perform the following operations on a given square matrix using functions: 
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal */

#include <stdio.h>

void nonzero(int n, int arr[n][n]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0)
                count++;
        }
    }
    printf("%d\n", count);
}

void upper(int n, int array[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j)
                array[i][j] = 0;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void updown(int n, int arry[n][n]) {
    printf("Elements just above  the main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < n - 1 && j == i + 1)
                printf("%d ", arry[i][j]);
        }
    }
    printf("\n");
    printf("Elements just below the main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0 && j == i - 1)
                printf("%d ", arry[i][j]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of square matrix: ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("No. of non-zero elements: ");
    nonzero(n, arr);

    updown(n, arr);

    printf("Upper triangular matrix:\n");
    upper(n, arr);

    return 0;
}
