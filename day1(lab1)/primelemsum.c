/*Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of
all the prime elements of the array using function and de-allocate the memory of the array after its use.*/
#include <stdio.h> 
#include <stdlib.h> 
int isPrime(int num) {
    for (int i = num / 2; i > 1; i--) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
void main() {
    int n, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    } 
    printf("Sum of prime elements: %d\n", sum); 
    free(arr); 
}