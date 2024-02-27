#include <stdio.h>
void printPatternRow(int n, int row, int col) {
    if (col > row) { 
        printf("\n"); 
        return;
    }

    printf("%d ", col); 
    printPatternRow(n, row, col + 1); 
}

void printPattern(int n, int row) {
    if (row > n) 
        return;

    printPatternRow(n, row, 1); 
    printPattern(n, row + 1);
}

int main() {
    int n = 4; 
    printPattern(n, 1); 
    return 0;
}
