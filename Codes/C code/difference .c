#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 4, 5, 6};
    int n1 = 5, n2 = 4;

    printf("Difference (arr1 - arr2): ");
    for (int i = 0; i < n1; i++) {
        int j;
        for (j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                break; // Element found in arr2, skip printing
            }
        }
        if (j == n2) {
            // If no match found in arr2, print the element
            printf("%d ", arr1[i]);
        }
    }

    return 0;
}
