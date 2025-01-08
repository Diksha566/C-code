#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

int main() {
    sem_t s; // Declare semaphore
    sem_init(&s, 0, 1); // Initialize semaphore with value 1

    // Display value 6 and pattern "00110011..."
    printf("Value: 6\nPattern: ");
    for (int i = 0; i < 8; i++) {
        printf("%d", i % 4 < 2 ? 0 : 1); // Prints "00" and "11" alternately
    }
    printf("\n");

    // Display value 7 and pattern "CACA"
    printf("Value: 7\nPattern: CACA\n");

    // Display value 8 and repeating patterns "PPWC DOS"
    printf("Value: 8\nPattern: ");
    for (int i = 0; i < 3; i++) { // Repeat the sequence 3 times
        printf("PPWC DOS ");
    }
    printf("\n");

    sem_destroy(&s); // Clean up the semaphore
    return 0;
}
