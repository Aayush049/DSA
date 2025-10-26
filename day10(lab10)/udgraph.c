#include <stdio.h>

int main() {
    int n;
    char ans;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n]; // adjacency matrix

    // Initialize all elements to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Create adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("Vertices %d & %d are Adjacent ? (Y/N): ", i + 1, j + 1);
            scanf(" %c", &ans); // note the space before %c to ignore whitespace

            if (ans == 'y' || ans == 'Y') {
                adj[i][j] = adj[j][i] = 1; // undirected graph
            }
        }
    }

    // Display degree of each vertex
    printf("\nVertex\tDegree\n");
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            degree += adj[i][j];
        }
        printf("%d\t%d\n", i + 1, degree);
    }

    return 0;
}
