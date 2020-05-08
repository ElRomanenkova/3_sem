#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

const int RADIX = 10;

int main(int argc, char * argv[]) {

    if (argc == 1) {           // проверка, что agrv[1] есть
        printf("USAGE: %s filename\n", argv[0]);
        exit(1);
    }

    long int num = 0;

    char * end;
    num = strtol(argv[1], &end, RADIX);

    printf("Parent %d\n", getpid());
//    printf("\n");

    for (long int i = 0; i < num; ++i) {

        if (fork() == 0) {

            sleep(1);

            printf("Child %d %d\n", getpid(), getppid());
            wait(NULL);
            exit(0);
        }

        for (long int j = 0; j < num; ++j) {
    wait(NULL);
        }

    }


    return 0;
}