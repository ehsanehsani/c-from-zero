#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler function
void handle_sigint(int sig) {
    printf("Caught signal %d\n", sig);
    exit(0);
}

int main() {
    int counter = 0;

    // Register signal handler for SIGINT
    // This will catch Ctrl+C (SIGINT) and call handle_sigint
    signal(SIGINT, handle_sigint); 

    while (1) {
        printf("%d\n", counter);
        printf("press Ctrl+C to stop\n");
        counter++;
        sleep(2);
    }

    return 0;
}