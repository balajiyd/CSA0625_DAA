#include <stdio.h>

void strassen(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int i, j;
    int newSize = n / 2;

    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];

    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    strassen(newSize, A11, subtract(newSize, B12, B22), P1);
    strassen(newSize, add(newSize, A11, A12), B22, P2);
    strassen(newSize, add(newSize, A21, A22), B11, P3);
    strassen(newSize, A22, subtract(newSize, B21, B11), P4);
    strassen(newSize, add(newSize, A11, A22), add(newSize, B11, B22), P5);
    strassen(newSize, subtract(newSize, A12, A22), add(newSize, B21, B22), P6);
    strassen(newSize, subtract(newSize, A11, A21), add(newSize, B11, B12), P7);

    int tmp1[newSize][newSize], tmp2[newSize][newSize];
    add(newSize, P5, P4, tmp1);
    subtract(newSize, tmp1, P2, tmp2);
    add(newSize, tmp2, P6, C11);

    add(newSize, P1, P2, C12);
    add(newSize, P3, P4, C21);

    add(newSize, P5, P1, tmp1);
    subtract(newSize, tmp1, P3, tmp2);
    subtract(newSize, tmp2, P7, C22);

    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

void add(int n, int A[][n], int B[][n], int C[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int n, int A[][n], int B[][n], int C[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void printMatrix(int n, int matrix[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; 
    int A[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int B[][4] = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};
    int C[n][n]; 

    strassen(n, A, B, C);

    printf("Matrix A:\n");
    printMatrix(n, A);
    printf("\nMatrix B:\n");
    printMatrix(n, B);
    printf("\nResultant Matrix C:\n");
    printMatrix(n, C);

    return 0;
}
