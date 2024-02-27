#include <stdio.h>
void findMinAndMax(int arr[], int low, int high, int *min, int *max) {
    int mid, minLeft, maxLeft, minRight, maxRight;

    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    mid = (low + high) / 2;
    findMinAndMax(arr, low, mid, &minLeft, &maxLeft);
    findMinAndMax(arr, mid + 1, high, &minRight, &maxRight);

    if (minLeft < minRight)
        *min = minLeft;
    else
        *min = minRight;

    if (maxLeft > maxRight)
        *max = maxLeft;
    else
        *max = maxRight;
}
int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinAndMax(arr, 0, n - 1, &min, &max);

    printf("Minimum element in the array: %d\n", min);
    printf("Maximum element in the array: %d\n", max);

    return 0;
}
