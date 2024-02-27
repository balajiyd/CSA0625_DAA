#include <stdio.h>
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}
void printPascalTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoeff(i, j));
        }
        printf("\n");
    }
}

int main() {
    int numRows;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);
    
    printPascalTriangle(numRows);
    
    return 0;
}
