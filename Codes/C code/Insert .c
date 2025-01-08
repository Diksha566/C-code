#include <stdio.h>

int main() {
    int arr[100];  // Array with a capacity of 100 elements
    int n, i;

    // Get the number of elements to insert
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the elements of the array
    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
