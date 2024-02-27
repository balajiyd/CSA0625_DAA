#include <stdio.h>
#include <stdbool.h>

#define N 8 // Size of the chessboard

// Function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check left side of the row
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

// Recursive function to solve N Queens problem
bool solveNQueens(int board[N][N], int col) {
    if (col >= N)
        return true; // All queens are placed successfully

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen
            if (solveNQueens(board, col + 1)) {
                return true;
            }
            board[i][col] = 0; // Backtrack if placing queen at board[i][col] doesn't lead to a solution
        }
    }

    return false; // If queen cannot be placed in any row of the current column
}

// Main function to solve N Queens problem and print the solution
void nQueens() {
    int board[N][N] = {{0}};

    if (solveNQueens(board, 0)) {
        printf("Solution exists:\n");
        printSolution(board);
    } else {
        printf("Solution does not exist.\n");
    }
}

int main() {
    nQueens(); // Solve N Queens problem
    return 0;
}
