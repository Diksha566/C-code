#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 4, 5, 6};
    int n1 = 5, n2 = 4;

    printf("Unique elements: ");

    // Print elements in arr1 not in arr2
    for (int i = 0; i < n1; i++) {
        int isUnique = 1;
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            printf("%d ", arr1[i]);
        }
    }

    // Print elements in arr2 not in arr1
    for (int i = 0; i < n2; i++) {
        int isUnique = 1;
        for (int j = 0; j < n1; j++) {
            if (arr2[i] == arr1[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            printf("%d ", arr2[i]);
        }
    }

    return 0;
}
