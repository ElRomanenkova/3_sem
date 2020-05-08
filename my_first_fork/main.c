#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

const int RADIX = 10;

int main(int argc, char * argv[]) {

    long int num = 0;

    for (long int i = 1; i < argc; ++i) {

        if (fork() == 0) {

            char * end;
            num = strtol(argv[i], &end, RADIX);

            usleep(num * 1000);
            printf("%ld ", num);

            exit(0);
        }

    }

    for (long int j = 0; j < argc; ++j) {
        wait(NULL);
    }

    printf("\n");


    return 0;
}