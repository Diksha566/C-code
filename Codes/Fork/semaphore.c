#include <stdio.h>
#include <semaphore.h>

int main() {
    sem_t s; // Declare semaphore

    // Initialize semaphore 's' with value 10
    sem_init(&s, 0, 10);

    int value;
    sem_getvalue(&s, &value); // Get the current value of the semaphore

    printf("Semaphore value: %d\n", value);

    sem_destroy(&s); // Clean up the semaphore
    return 0;
}
