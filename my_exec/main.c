#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <sys/time.h>
#include <bits/time.h>
#include <time.h>

const int MAX_SIZE = 1024;

void GetTime (struct timespec * t1, struct timespec * t2) {

    printf("time - %.3lf\n", (t2->tv_sec - t1->tv_sec) + (t2->tv_nsec - t1->tv_nsec) * 0.000000001);

}

int main(int argc, char ** argv) {

    if (argc == 1) {           // проверка, что agrv[1] есть
        printf("USAGE: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct timespec t1, t2;

    clock_gettime(CLOCK_MONOTONIC, &t1);


    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int cpid = fork();
    if (cpid == -1) {
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {

//        close(1);
//        dup(pipe_fd[1]);
        dup2(pipe_fd[1], 1);
        close(pipe_fd[1]);
        close(pipe_fd[0]);

        if (execvp(argv[1], &argv[1]) == -1) {
            printf("%s: command not found\n", argv[1]);
            exit(0);
        }

    }

    close(pipe_fd[1]);

//    int * p;
//    wait(p);

//    wait(NULL);

    int lines = 0;
    int words = 0;
    int bytes = 0;

    while(1) {

        char output_buf[MAX_SIZE];

        int b_read = read(pipe_fd[0], output_buf, MAX_SIZE);
        if (b_read < 0) {
            perror("Data didn't read\n");
            break;
        }
//    printf("%s", output_buf);

        if (b_read == 0)
            break;

        int i = 0;

        while(output_buf[i]) {

            if (output_buf[i] == '\n') {
                lines++;
                words++;
            }

            if (output_buf[i] == ' ')
                words++;

            i++;
        }

        bytes += b_read;

        if (bytes != 0 && output_buf[i - 1] != '\n') {
            words++;
            lines++;
        }
        else if (bytes != 0 && output_buf[i - 1] == '\n') {
            lines++;
        }

        int b_write = write(1, output_buf, b_read);
        if(b_write < 0) {
            perror("Data didn't write\n");

            break;
        }

    }

//    while (output_buf[bytes] != 0) {
//        if (output_buf[bytes] == '\n')
//            ++lines;
//        if (output_buf[bytes] == ' ')
//            ++words;
//        ++bytes;
//    }
//
//    if (bytes != 0)
//        ++words;

    printf("\nlines: %d\n" "words: %d\n" "bytes: %d\n", lines, words, bytes);

    wait(NULL);

    clock_gettime(CLOCK_MONOTONIC, &t2);

    GetTime(&t1, &t2);

    close(pipe_fd[0]);

    return 0;
}