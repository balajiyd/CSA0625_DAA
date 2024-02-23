#include<stdio.h>
#include<math.h>
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power(base, exponent - 1);
    }
}
int countDigits(int num) {
    if (num == 0) {
        return 0;
    } else {
        return 1 + countDigits(num / 10);
    }
}
int isArmstrong(int num, int n) {
    if (num == 0) {
        return 0;
    } else {
        return power(num % 10, n) + isArmstrong(num / 10, n);
    }
}

int main() {
    int num, numCopy, n, result;

    printf("Enter a number to check if it is an Armstrong number: ");
    scanf("%d", &num);

    numCopy = num;
    n = countDigits(num);
    result = isArmstrong(num, n);

    if (result == numCopy) {
        printf("%d is an Armstrong number.\n", numCopy);
    } else {
        printf("%d is not an Armstrong number.\n", numCopy);
    }

    return 0
}
