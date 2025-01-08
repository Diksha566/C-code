#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t sem_p1, sem_p2; // Semaphores for synchronization

void *process_p1(void *arg) {
    while (1) {
        sem_wait(&sem_p1); // Wait for signal from p2
        printf("C");
        fflush(stdout); // Ensure immediate output
        sem_post(&sem_p2); // Signal p2
        usleep(100000); // Small delay for readability
    }
    return NULL;
}

void *process_p2(void *arg) {
    while (1) {
        sem_wait(&sem_p2); // Wait for signal from p1
        printf("A");
        fflush(stdout); // Ensure immediate output
        sem_post(&sem_p1); // Signal p1
        usleep(100000); // Small delay for readability
    }
    return NULL;
}

int main() {
    pthread_t p1, p2;

    // Initialize semaphores
    sem_init(&sem_p1, 0, 1); // Start with p1
    sem_init(&sem_p2, 0, 0);

    // Create threads for processes
    pthread_create(&p1, NULL, process_p1, NULL);
    pthread_create(&p2, NULL, process_p2, NULL);

    // Wait for threads to complete (infinite loop here)
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    // Clean up semaphores
    sem_destroy(&sem_p1);
    sem_destroy(&sem_p2);

    return 0;
}
