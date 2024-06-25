#include <stdio.h>
#include <math.h>

// Function to input a matrix
void inputMatrix(int matrix[10][10], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[10][10], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 1. Check Multiplicability of Two Matrices
int canMultiply(int cols1, int rows2) {
    if (cols1 == rows2)
        return 1; // Multiplication possible
    else
        return 0; // Multiplication not possible
}

// 2. Check if two matrices are equal
int areEqual(int matrix1[10][10], int matrix2[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix1[i][j] != matrix2[i][j])
                return 0; // Matrices are not equal
        }
    }
    return 1; // Matrices are equal
}

// 3. Find the Sum of Each Row and Column of a MxN Matrix
void sumRowColumn(int matrix[10][10], int rows, int cols) {
    int sumRow, sumCol;

    // Sum of each row
    printf("Sum of each row:\n");
    for (int i = 0; i < rows; i++) {
        sumRow = 0;
        for (int j = 0; j < cols; j++) {
            sumRow += matrix[i][j];
        }
        printf("Row %d: %d\n", i + 1, sumRow);
    }

    // Sum of each column
    printf("\nSum of each column:\n");
    for (int j = 0; j < cols; j++) {
        sumCol = 0;
        for (int i = 0; i < rows; i++) {
            sumCol += matrix[i][j];
        }
        printf("Column %d: %d\n", j + 1, sumCol);
    }
    printf("\n");
}

// 4. Find Determinant of a Matrix (for 2x2 and 3x3 matrices)
int determinant(int matrix[10][10], int n) {
    int det = 0;
    if (n == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else if (n == 3) {
        det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
            - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
            + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    }
    return det;
}

// 5. Find Transpose of a Matrix
void transpose(int matrix[10][10], int rows, int cols) {
    int transposed[10][10];

    // Compute transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Print transpose
    printf("Transpose of the matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d\t", transposed[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 6. Perform Addition, Subtraction on 2D matrices at even element positions
void addSubtractEvenPositions(int matrix1[10][10], int matrix2[10][10], int rows, int cols) {
    int resultAdd[10][10], resultSub[10][10];

    // Compute addition and subtraction at even positions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i + j) % 2 == 0) {
                resultAdd[i][j] = matrix1[i][j] + matrix2[i][j];
                resultSub[i][j] = matrix1[i][j] - matrix2[i][j];
            } else {
                resultAdd[i][j] = 0;
                resultSub[i][j] = 0;
            }
        }
    }

    // Print results
    printf("Addition at even element positions:\n");
    printMatrix(resultAdd, rows, cols);

    printf("Subtraction at even element positions:\n");
    printMatrix(resultSub, rows, cols);
}

// 7. Find the trace of a matrix
int trace(int matrix[10][10], int n) {
    int trace = 0;
    for (int i = 0; i < n; i++) {
        trace += matrix[i][i];
    }
    return trace;
}

// 8. Find the adjacency matrix (for a graph represented by a matrix)
void adjacencyMatrix(int matrix[10][10], int n) {
    int adjMatrix[10][10] = {0};

    // Populate adjacency matrix based on input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                adjMatrix[i][j] = 1;
            }
        }
    }

    // Print adjacency matrix
    printf("Adjacency Matrix:\n");
    printMatrix(adjMatrix, n, n);
}

// 9. Find the inverse of a matrix (for 2x2 matrix only)
void inverseMatrix(int matrix[10][10]) {
    int det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    if (det == 0) {
        printf("Inverse does not exist.\n");
        return;
    }

    int invMatrix[10][10];
    invMatrix[0][0] = matrix[1][1];
    invMatrix[0][1] = -matrix[0][1];
    invMatrix[1][0] = -matrix[1][0];
    invMatrix[1][1] = matrix[0][0];

    printf("Inverse of the matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", invMatrix[i][j] / det);
        }
        printf("\n");
    }
    printf("\n");
}

// 10. Check if a matrix is an Identity Matrix (for square matrices only)
int isIdentityMatrix(int matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                return 0; // Not an identity matrix
            }
        }
    }
    return 1; // Identity matrix
}

int main() {
    int choice, rows, cols, n;
    int matrix1[10][10], matrix2[10][10];

    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input first matrix
    printf("Matrix 1:\n");
    inputMatrix(matrix1, rows, cols);

    // Input second matrix for specific questions
    printf("Matrix 2:\n");
    inputMatrix(matrix2, rows, cols);

    // Menu for different matrix operations
    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Check Multiplicability of Two Matrices\n");
        printf("2. Check if Two Matrices are Equal\n");
        printf("3. Sum of Each Row and Column of a MxN Matrix\n");
        printf("4. Find Determinant of a Matrix (for 2x2 and 3x3)\n");
        printf("5. Find Transpose of a Matrix\n");
        printf("6. Addition, Subtraction on 2D Matrices at Even Element Positions\n");
        printf("7. Find the trace of a matrix\n");
        printf("8. Find the adjacency matrix (for a graph represented by a matrix)\n");
        printf(" 9. Find the inverse of a matrix (for 2x2 matrix only)\n");
        printf("10. Check if a matrix is an Identity Matrix (for square matrices only)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (canMultiply(cols, rows)) {
                    printf("Matrices can be multiplied.\n");
                } else {
                    printf("Matrices cannot be multiplied.\n");
                }
                break;
            case 2:
                if (areEqual(matrix1, matrix2, rows, cols)) {
                    printf("Matrices are equal.\n");
                } else {
                    printf("Matrices are not equal.\n");
                }
                break;
            case 3:
                sumRowColumn(matrix1, rows, cols);
                break;
            case 4:
                if (rows == cols) {
                    printf("Determinant of Matrix 1: %d\n", determinant(matrix1, rows));
                    printf("Determinant of Matrix 2: %d\n", determinant(matrix2, rows));
                } else {
                    printf("Determinant calculation only for square matrices (2x2 and 3x3).\n");
                }
                break;
            case 5:
                transpose(matrix1, rows, cols);
                transpose(matrix2, rows, cols);
                break;
            case 6:
                addSubtractEvenPositions(matrix1, matrix2, rows, cols);
                break;
            case 7:
                if (rows == cols) {
                    printf("Trace of Matrix 1: %d\n", trace(matrix1, rows));
                    printf("Trace of Matrix 2: %d\n", trace(matrix2, rows));
                } else {
                    printf("Trace can only be found for square matrices.\n");
                }
                break;
            case 8:
                if (rows == cols) {
                    adjacencyMatrix(matrix1, rows);
                    adjacencyMatrix(matrix2, rows);
                } else {
                    printf("Adjacency matrix is defined only for square matrices.\n");
                }
                break;
            case 9:
                if (rows == 2 && cols == 2) {
                    inverseMatrix(matrix1);
                    inverseMatrix(matrix2);
                } else {
                    printf("Inverse matrix calculation only for 2x2 matrices.\n");
                }
                break;
            case 10:
                if (rows == cols) {
                    if (isIdentityMatrix(matrix1, rows)) {
                        printf("Matrix 1 is an Identity Matrix.\n");
                    } else {
                        printf("Matrix 1 is not an Identity Matrix.\n");
                    }
                    if (isIdentityMatrix(matrix2, rows)) {
                        printf("Matrix 2 is an Identity Matrix.\n");
                    } else {
                        printf("Matrix 2 is not an Identity Matrix.\n");
                    }
                } else {
                    printf("Identity matrix check only for square matrices.\n");
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}
