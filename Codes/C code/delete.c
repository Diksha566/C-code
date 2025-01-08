#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5; // Size of the array
    int key = 30; // Element to be deleted
    int i, j;

    // Find the element to delete
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            break;
        }
    }

    // Shift elements to the left to remove the element
    if (i < n) {
        for (j = i; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        n--; // Reduce the size of the array
    }

    // Print the array after deletion
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
