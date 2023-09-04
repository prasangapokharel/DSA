#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort function
void counting_sort(int arr[], int n) {
    int max = find_max(arr, n);

    // Initialize the count array with zeros
    int *count = (int*) calloc((max + 1), sizeof(int));

    // Step 3: Count occurrences of each element in the array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 4: Update count array to store cumulative counts
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build the sorted array
    int *sorted_arr = (int*) malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        sorted_arr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }

    // Free the dynamically allocated memory
    free(count);
    free(sorted_arr);
}

int main() {
     int n;

    // Ask for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Ask for array elements
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    counting_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
