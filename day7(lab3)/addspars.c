#include <stdio.h>

struct term {
    int row, col, val;
};

int main() {
    struct term a[50], b[50], c[100];
    int m, n, t1, t2;
    int i, j, k;

    // Input sparse matrix-1
    printf("Enter sparse matrix-1 in 3-tuple format\n");
    scanf("%d %d %d", &m, &n, &t1);
    a[0].row = m; a[0].col = n; a[0].val = t1;
    for (i = 1; i <= t1; i++)
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);

    // Input sparse matrix-2
    printf("Enter sparse matrix-2 in 3-tuple format\n");
    scanf("%d %d %d", &m, &n, &t2);
    b[0].row = m; b[0].col = n; b[0].val = t2;
    for (i = 1; i <= t2; i++)
        scanf("%d %d %d", &b[i].row, &b[i].col, &b[i].val);

    // Add matrices
    i = j = k = 1;
    c[0].row = m; c[0].col = n;

    while (i <= t1 && j <= t2) {
        if (a[i].row < b[j].row || 
           (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[++k] = a[i++];
        }
        else if (b[j].row < a[i].row || 
                (b[j].row == a[i].row && b[j].col < a[i].col)) {
            c[++k] = b[j++];
        }
        else { // same position
            c[++k] = a[i];
            c[k].val = a[i].val + b[j].val;
            i++; j++;
        }
    }

    // Copy remaining terms
    while (i <= t1) c[++k] = a[i++];
    while (j <= t2) c[++k] = b[j++];

    c[0].val = k - 1;

    // Output Result
    printf("Resultant Matrix in 3-tuple format\n");
    printf("%d %d %d\n", c[0].row, c[0].col, c[0].val);
    for (i = 1; i <= c[0].val; i++)
        printf("%d %d %d\n", c[i].row, c[i].col, c[i].val);

    return 0;
}