/*Design and implement C/C++ Program to find the transitive closure using Warshal's algorithm.*/

#include <stdio.h>

int n, a[10][10], p[10][10];

void warshall() {
    // Initialize the path matrix with the adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            p[i][j] = a[i][j];

    // Warshall's algorithm to compute transitive closure
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][k] && p[k][j])
                    p[i][j] = 1;
            }
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    warshall();

    printf("The path matrix is shown below:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    return 0;
}