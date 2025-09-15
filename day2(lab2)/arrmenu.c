/* WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array */

#include <stdio.h>
int n;
void insert(int elem, int pos, int arr[]) {
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
    } else {
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos-1] = elem;
        n++;
        printf("Element inserted successfully.\n");
    }
}

void delete(int delPos, int arr[]) {
    if (delPos < 0 || delPos >= n) {
        printf("Invalid position!\n");
    } else {
        for (int i = delPos-1; i < n; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("Element deleted successfully.\n");
    }
}

void search(int searchElem, int arr[]) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchElem) {
            printf("Element %d found at position %d.\n", searchElem, i+1);
            found = 1;
            break;
        }
    }
    if (found==0) { 
        printf("Element %d not found in the array.\n", searchElem);
    }
}
void travel(int arr[]) {
    printf("Array elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int x;
    printf("\nChoose from the following\n");
    printf("1. Insert element into array.\n");
    printf("2. Delete specific element from array.\n");
    printf("3. Linear search for element.\n");
    printf("4. Print the array.\n");
    printf("Enter your choice: ");
    scanf("%d", &x);

    switch (x) {
        case 1: {
            int elem, pos;
            printf("Enter the element to insert and its position: ");
            scanf("%d %d", &elem, &pos);
            insert(elem, pos, arr);
            break;
        }
        case 2: {
            int delPos;
            printf("Enter the position of element to delete: ");
            scanf("%d", &delPos);
            delete(delPos, arr);
            break;
        }
        case 3: {
            int searchElem;
            printf("Enter the element to search: ");
            scanf("%d", &searchElem);
            search(searchElem, arr);
            break;
        }
        case 4:
            travel(arr);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}