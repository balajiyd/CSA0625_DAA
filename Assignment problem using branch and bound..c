#include <stdio.h>
#include <limits.h>

#define N 4 // Number of workers (or tasks)
#define INF INT_MAX // Infinity

// Function to print the assignments
void printAssignments(int assignments[]) {
    printf("Worker   Task\n");
    for (int i = 0; i < N; i++) {
        printf("  %d   -->   %d\n", i, assignments[i]);
    }
}

// Function to update the minimum cost and corresponding assignments
void updateMinCost(int costMatrix[N][N], int currentCost, int currentAssignment[], int minCost, int minAssignment[]) {
    for (int i = 0; i < N; i++) {
        if (!currentAssignment[i]) {
            currentCost += costMatrix[i][N - 1 - __builtin_clz(~currentAssignment[i])];
        }
    }

    if (currentCost < minCost) {
        minCost = currentCost;
        for (int i = 0; i < N; i++) {
            minAssignment[i] = currentAssignment[i];
        }
    }
}

// Function to find minimum cost using branch and bound
void branchAndBound(int costMatrix[N][N]) {
    int minAssignment[N]; // Stores the minimum assignment
    int currentAssignment[N]; // Stores the current assignment
    int minCost = INF; // Stores the minimum cost
    int currentCost = 0; // Stores the current cost

    // Initialize current assignment to 0
    for (int i = 0; i < N; i++) {
        currentAssignment[i] = 0;
    }

    // Start from worker 0
    currentAssignment[0] = 1;

    // Recursively search for the minimum cost
    updateMinCost(costMatrix, currentCost, currentAssignment, minCost, minAssignment);

    // Print the minimum cost and assignments
    printf("Minimum Cost: %d\n", minCost);
    printAssignments(minAssignment);
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    // Call branch and bound function to solve the assignment problem
    branchAndBound(costMatrix);

    return 0;
}
