#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        // Error occurred
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process started. PID: %d\n", getpid());
        sleep(2); // Simulate some work in the child process
        printf("Child process finished.\n");
    } else {
        // Parent process
        printf("Parent process waiting for child to finish...\n");
        wait(NULL); // Wait for the child process to finish
        printf("Parent process detected child has finished.\n");
    }

    return 0;
}
