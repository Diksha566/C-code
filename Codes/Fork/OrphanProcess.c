#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(5);  // Simulate some work in child process
        printf("Child process (orphan): Parent PID = %d, My PID = %d\n", getppid(), getpid());
    } else {
        // Parent process
        printf("Parent process exiting. My PID = %d\n", getpid());
        exit(0);  // Parent exits, leaving child orphaned
    }

    return 0;
}
