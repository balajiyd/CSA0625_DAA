#include <stdio.h>

#define MAX_ITEMS 100 // Maximum number of items
#define MAX_CONTAINERS 100 // Maximum number of containers

// Function to pack items into containers using a greedy algorithm
int packItems(int items[], int numItems, int containerSize) {
    int containers[MAX_CONTAINERS] = {0}; // Array to store the remaining space in each container
    int numContainers = 0; // Number of containers used

    for (int i = 0; i < numItems; i++) {
        int currentItem = items[i];
        int j;

        // Try to place the current item into an existing container
        for (j = 0; j < numContainers; j++) {
            if (containers[j] >= currentItem) {
                containers[j] -= currentItem; // Update remaining space in the container
                break;
            }
        }

        // If the item couldn't fit into any existing container, use a new container
        if (j == numContainers) {
            containers[numContainers++] = containerSize - currentItem;
        }
    }

    return numContainers; // Return the number of containers used
}

int main() {
    int items[MAX_ITEMS]; // Array to store item sizes
    int numItems, containerSize;

    // Input number of items and container size
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the sizes of the items:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }

    printf("Enter the size of the containers: ");
    scanf("%d", &containerSize);

    // Pack items into containers
    int numContainers = packItems(items, numItems, containerSize);

    // Output the number of containers used
    printf("Number of containers required: %d\n", numContainers);

    return 0;
}
