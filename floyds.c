/*Design and implement C/C++ Program to solve All-Pairs Shortest Paths problem using Floyd's algorithm.*/

#include <stdio.h>

#define nV 4
#define INF 999

// Function to print the matrix
void printMatrix(int matrix[][nV]) {
    printf("All pairs shortest path is\n");
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[][nV]) {
    int matrix[nV][nV];

    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < nV; i++)
        for (int j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices
    for (int k = 0; k < nV; k++) {
        for (int i = 0; i < nV; i++) {
            for (int j = 0; j < nV; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printMatrix(matrix);
}

int main() {
    int graph[nV][nV] = {
        {INF, 1, 4, 6},
        {INF, INF, 7, 4},
        {2, INF, INF, 3},
        {INF, INF, INF, INF}
    };

    floydWarshall(graph);
    return 0;
}