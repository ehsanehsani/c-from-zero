/*
 * Simple Daemon Service in C
 *
 * This program runs as a daemon (background service) that writes timestamps
 * to a log file every 10 seconds.
 *
 * What it does:
 * - Detaches from the terminal and runs in the background.
 * - Writes a "Service started" message with timestamp to /tmp/my_service_log.txt.
 * - Every 10 seconds, appends a "Tick at" timestamp to the same log file.
 * - Listens for termination signals (SIGTERM, SIGINT) to gracefully stop
 *   and write a "Service stopped" message before exiting.
 *
 * How to compile:
 * gcc -o my_service my_service.c
 *
 * How to run:
 * ./my_service
 *
 * How to check logs:
 * tail -f /tmp/my_service_log.txt
 *
 * How to find the process:
 * ps aux | grep my_service
 *
 * How to stop the service:
 * kill <PID>
 * or
 * pkill my_service
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>

#define LOG_FILE "/tmp/my_service_log.txt"

volatile sig_atomic_t keep_running = 1;

void handle_signal(int sig) {
    keep_running = 0;
}

void daemonize() {
    pid_t pid = fork();

    if (pid < 0) exit(EXIT_FAILURE);     // Fork failed
    if (pid > 0) exit(EXIT_SUCCESS);     // Parent exits

    // Child continues
    if (setsid() < 0) exit(EXIT_FAILURE); // Create new session

    // Fork again to avoid terminal reacquisition
    pid = fork();
    if (pid < 0) exit(EXIT_FAILURE);
    if (pid > 0) exit(EXIT_SUCCESS);

    umask(0);                // Reset file mode mask
    chdir("/");              // Change working directory
    close(STDIN_FILENO);     // Close standard file descriptors
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

void write_timestamp(FILE *file, const char *prefix) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(file, "%s %04d-%02d-%02d %02d:%02d:%02d\n",
            prefix,
            t->tm_year + 1900,
            t->tm_mon + 1,
            t->tm_mday,
            t->tm_hour,
            t->tm_min,
            t->tm_sec);
    fflush(file);
}

int main() {
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    daemonize();

    FILE *file = fopen(LOG_FILE, "a");
    if (!file) exit(EXIT_FAILURE);

    write_timestamp(file, "Service started at");

    while (keep_running) {
        sleep(10);
        write_timestamp(file, "Tick at");
    }

    write_timestamp(file, "Service stopped at");
    fclose(file);

    return 0;
}
