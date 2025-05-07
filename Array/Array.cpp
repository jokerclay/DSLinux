#include "Array.h"
#include <cstdio>

void demostrateRowFirstArray(int* array, int row, int column, int size)
{
    if ((row * column) != size) {
        printf("wrong size, expected %d but got %d \n", row * column, size);
        return;
    }

    printf("Displaying matrix (row-first interpretation):\n");

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            // row-first layout: array[i * column + j]
            printf("%d ", array[i * column + j]);
        }
        printf("\n");
    }
}

void demostrateColumnFirstArray(int* array, int row, int column, int size)
{
    if ((row * column) != size) {
        printf("wrong size, expected %d but got %d \n", row * column, size);
        return;
    }

    printf("Displaying matrix (column-first interpretation):\n");

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            // column-first layout: array[j * row + i]
            printf("%d ", array[j * row + i]);
        }
        printf("\n");
    }
}


void demonstrateSymmetricPackedMatrix(int* packed, int n)
{
    printf("demonstrateSymmetricPackedMatrix (%dx%d):\n", n, n);

    // Allocate full matrix in memory
    int matrix[n][n];

    // Reconstruct full symmetric matrix from packed lower triangle
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int value = packed[index++];
            matrix[i][j] = value;
            matrix[j][i] = value;  // fill symmetric value
        }
    }

    // Print matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}



void demonstrateSparseMatrix(const int* matrix, int rows, int cols)
{
    printf("demonstrateSparseMatrix (%dx%d):\n", rows, cols);

    // Print full matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%2d ", matrix[i * cols + j]);
        }
        printf("\n");
    }

    // Print sparse (non-zero) entries
    printf("\nSparse representation (i j a_ij):\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int val = matrix[i * cols + j];
            if (val != 0) {
                printf("%d %d %d\n", i, j, val);
            }
        }
    }
}

