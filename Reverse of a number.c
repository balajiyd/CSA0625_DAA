#include <stdio.h>
int reverseNumber(int num) {
    static int reversedNum = 0;

    if (num == 0)
        return 0;

    int digit = num % 10;

    reversedNum = reversedNum * 10 + digit;
    reverseNumber(num / 10);

    return reversedNum;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int reversed = reverseNumber(num);
    printf("Reverse of %d is %d\n", num, reversed);

    return 0;
}
