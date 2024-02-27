#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratio1 = ((double)(((struct Item *)a)->value) / ((struct Item *)a)->weight);
    double ratio2 = ((double)(((struct Item *)b)->value) / ((struct Item *)b)->weight);
    return (ratio2 > ratio1) ? 1 : -1;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), compare);

    int curWeight = 0; 
    double finalValue = 0.0;  

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int W; 
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    int n;  
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item arr[n];  

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
