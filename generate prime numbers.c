#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n, int i) {
    if (n <= 2) {
        return (n == 2) ? true : false;
    }
    if (n % i == 0) {
        return false;
    }
    if (i * i > n) {
        return true;
    }
    return isPrime(n, i + 1);
}
void printPrimes(int limit, int current) {
    if (current > limit) {
        return;
    }
    if (isPrime(current, 2)) {
        printf("%d ", current);
    }
    printPrimes(limit, current + 1);
}

int main() {
    int limit;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are: ", limit);
    printPrimes(limit, 2);

    return 0;
}
