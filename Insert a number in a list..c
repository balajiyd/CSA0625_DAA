#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the list

// Function to insert a number into a list at a given position
void insertNumber(int list[], int *size, int position, int number) {
    if (*size >= MAX_SIZE) {
        printf("List is full. Cannot insert more elements.\n");
        return;
    }

    // Shift elements to the right to make space for the new number
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }

    // Insert the number at the specified position
    list[position] = number;

    // Increment the size of the list
    (*size)++;
}

// Function to print the list
void printList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE];
    int size = 0; // Current size of the list

    // Example list
    list[0] = 10;
    list[1] = 20;
    list[2] = 30;
    size = 3; // Update the size

    int position, number;

    printf("Enter the position to insert the number: ");
    scanf("%d", &position);

    printf("Enter the number to insert: ");
    scanf("%d", &number);

    // Check if the position is valid
    if (position < 0 || position > size) {
        printf("Invalid position.\n");
    } else {
        // Insert the number into the list
        insertNumber(list, &size, position, number);
        // Print the updated list
        printList(list, size);
    }

    return 0;
}
