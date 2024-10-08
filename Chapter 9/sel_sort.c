#include <stdio.h>

#define MAX_SIZE 1000  // Define a maximum size for the array

// Function to swap two integers in the array using indices
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Recursive selection sort function
void selection_sort(int arr[], int n) {
    // Base case: if the array size is 1 or less, it's already sorted
    if (n <= 1) {
        return;
    }

    // Find the index of the largest element in the array
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    // Swap the largest element with the last element of the array
    swap(arr, maxIndex, n - 1);

    // Recursively sort the first n-1 elements of the array
    selection_sort(arr, n - 1);
}

int main() {
    int n;
    int arr[MAX_SIZE];  // Declare a fixed-size array

    // Ask the user to enter the number of elements
    printf("Enter the number of integers (maximum %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Check if the entered number of integers is within the allowed range
    if (n > MAX_SIZE) {
        printf("The number of integers exceeds the maximum allowed size of %d.\n", MAX_SIZE);
        return 1;  // Exit the program if the input is invalid
    }

    // Ask the user to enter the elements of the array
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using selection sort
    selection_sort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
