#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <values.h>
#include <errno.h>
#include <unistd.h>

#define SUCCESS 0

const int RADIX = 10;
int arg = 0;

long int LoadArgv (const char * num_in_str) {

    long int num = 0;
    char * end;

    errno = 0;

    num = strtol(num_in_str, &end, RADIX);

    if (((num == LONG_MAX || num == LONG_MIN) && errno == ERANGE) || *end != 0) {
        printf("Uncorrected number in file\n");
        exit(2);
    }

    if (end == num_in_str) {
        fprintf(stderr, "No digits were found\n");
        exit(3);
    }

    return num;
}

void * IncrFunc () {

    ++arg;
    return SUCCESS;

}

int main(int argc, char * argv[]) {

    if (argc == 1) {           // проверка, что agrv[1] есть
        printf("USAGE: %s filename\n", argv[0]);
        exit(1);
    }

    long int num = LoadArgv(argv[1]);

    pthread_t thread;

    int status = 0;
    int status_adr = 0;

    for (long int i = 0; i < num; ++i) {

        status = pthread_create(&thread, NULL, IncrFunc, NULL);

        if (status != SUCCESS) {
            printf("Can't create thread, status = %d\n", status);
            exit(4);
        }

        status = pthread_join(thread, (void**)&status_adr);

        if (status != SUCCESS) {
            printf("Can't join thread, status = %d\n", status);
            exit(5);
        }

    }

    printf("Result: %d\n", arg);

    return 0;
}