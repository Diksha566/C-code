#include <stdio.h>

int main() {
    int arr1[] = {1, 3, 5, 7};  // First sorted array
    int arr2[] = {2, 4, 6, 8};  // Second sorted array
    int n1 = 4, n2 = 4;         // Sizes of the arrays

    // Create a third array to store the merged result
    int arr3[n1 + n2];
    int i = 0, j = 0, k = 0;

    // Merge the arrays into arr3
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];  // Add element from arr1 to arr3
        } else {
            arr3[k++] = arr2[j++];  // Add element from arr2 to arr3
        }
    }


    // Print the merged array
    printf("Merged array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}
