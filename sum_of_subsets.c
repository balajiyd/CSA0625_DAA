#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the set

// Function to print the subset with the current elements
void printSubset(int subset[], int subsetSize) {
    printf("Subset: {");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Function to find all subsets with the given target sum using backtracking
void findSubsets(int set[], int subset[], int n, int subsetSize, int sum, int targetSum, int index) {
    if (sum == targetSum) {
        printSubset(subset, subsetSize); // Print the subset
    }

    for (int i = index; i < n; i++) {
        // Include the current element in the subset
        subset[subsetSize] = set[i];
        // Recursively call the function with the next index and updated sum
        findSubsets(set, subset, n, subsetSize + 1, sum + set[i], targetSum, i + 1);
    }
}

// Main function to find subsets with the given target sum
void subsetSum(int set[], int n, int targetSum) {
    int subset[MAX_SIZE]; // Array to store the current subset
    findSubsets(set, subset, n, 0, 0, targetSum, 0);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int targetSum = 35;

    printf("Subsets with sum %d:\n", targetSum);
    subsetSum(set, n, targetSum);

    return 0;
}
