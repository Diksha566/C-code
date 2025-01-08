#include <stdio.h>
#include <semaphore.h>
#include <unistd.h> // For sleep()

int main() {
    sem_t s; // Declare semaphore

    // Initialize semaphore 's' with value 10
    sem_init(&s, 0, 10);

    int value;

    // Apply semaphore operations
    sem_wait(&s); // Decrement by 1
    sem_wait(&s); // Decrement by 1
    sem_getvalue(&s, &value);
    printf("After two sem_wait() calls, semaphore value: %d\n", value);

    sem_post(&s); // Increment by 1
    sem_post(&s); // Increment by 1
    sem_getvalue(&s, &value);
    printf("After two sem_post() calls, semaphore value: %d\n", value);

    sem_wait(&s); // Decrement by 1
    sem_getvalue(&s, &value);
    printf("After one more sem_wait() call, semaphore value: %d\n", value);

    sem_destroy(&s); // Clean up the semaphore
    return 0;
}
