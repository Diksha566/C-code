#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

// Declare semaphores
sem_t sem_p1, sem_p2, sem_p3;

void *process_p1(void *arg) {
    sem_wait(&sem_p2); // Wait for p2 to signal
    printf("are ");
    fflush(stdout); // Ensure immediate output
    sem_post(&sem_p3); // Signal p3
    return NULL;
}

void *process_p2(void *arg) {
    sem_wait(&sem_p1); // Wait for p1 to signal
    printf("who ");
    fflush(stdout); // Ensure immediate output
    sem_post(&sem_p2); // Signal p2
    return NULL;
}

void *process_p3(void *arg) {
    sem_wait(&sem_p3); // Wait for p3 to signal
    printf("you\n");
    fflush(stdout); // Ensure immediate output
    sem_post(&sem_p1); // Signal p1 to restart the sequence
    return NULL;
}

int main() {
    pthread_t p1, p2, p3;

    // Initialize semaphores
    sem_init(&sem_p1, 0, 1); // Start with p2 (who)
    sem_init(&sem_p2, 0, 0); // Block p1 (are)
    sem_init(&sem_p3, 0, 0); // Block p3 (you)

    // Create threads for processes
    pthread_create(&p1, NULL, process_p1, NULL);
    pthread_create(&p2, NULL, process_p2, NULL);
    pthread_create(&p3, NULL, process_p3, NULL);

    // Wait for threads (infinite loop here for continuous printing)
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);

    // Clean up semaphores
    sem_destroy(&sem_p1);
    sem_destroy(&sem_p2);
    sem_destroy(&sem_p3);

    return 0;
}
