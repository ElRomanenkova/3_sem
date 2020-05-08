#include <stdio.h>
#include <stdlib.h>
#include <values.h>
#include <errno.h>

const int RADIX = 10;

long int LoadFile (const char * num_in_str) {

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

int main(int argc, char * argv[]) {

    if (argc == 1) {           // проверка, что agrv[1] есть
        printf("USAGE: %s filename\n", argv[0]);
        exit(1);
    }

    long int num = LoadFile(argv[1]);

    if(num > 0)
        for(long int i = 1; i <= num; ++i) {
            printf("%ld ", i);
        }

//    printf("%ld", num);

    return 0;
}