//WAP to represent a given sparse matrix in 3-tuple format using 2-D array. 

#include <stdio.h>
int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c], count = 0;
    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0) count++;
        }

    int trip[count + 1][3]; // +1 for header row
    trip[0][0] = r;
    trip[0][1] = c;
    trip[0][2] = count;

    int k = 1;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) 
            if (a[i][j] != 0) {
                trip[k][0] = i;
                trip[k][1] = j;
                trip[k][2] = a[i][j];
                k++;
            }

    printf("\n3-Tuple representation:\n");
    for (int i = 0; i <= count; i++)
        printf("%d %d %d\n", trip[i][0], trip[i][1], trip[i][2]);
}