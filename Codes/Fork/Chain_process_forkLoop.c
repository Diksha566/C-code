#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define NUM_PROCESSES 5

int main() {
    pid_t pid;
    for (int i = 0; i < NUM_PROCESSES; i++) {
        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            printf("Child process %d created with PID: %d\n", i + 1, getpid());
            exit(0); // Child process exits after printing
        } else {
            // Parent process
            wait(NULL); // Wait for child process to finish
        }
    }
    printf("All child processes have been created and completed.\n");
    return 0;
}