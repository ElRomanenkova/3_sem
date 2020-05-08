#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <bits/time.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


struct my_data {
    long int value;
};

void Increm1(struct my_data * data) {
    data->value++;
}

void Increm2(struct my_data * data) {

    int id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0777);

    struct sembuf * sops;

    semop(id, sops, 1);

//    p(s);
    data->value++;
//    v(s);
}

int main(int argc, char ** argv) {

    if (argc != 3) {
        perror("Incorrect number of argc");
        exit(EXIT_FAILURE);
    }

    struct timespec t1, t2;

    clock_gettime(CLOCK_MONOTONIC, &t1);

    int n_workers = atoi(argv[1]);
    int m_times = atoi(argv[2]);

    int id = shmget(IPC_PRIVATE, sizeof(struct my_data), IPC_CREAT | 0777);
    struct my_data * p = shmat(id, NULL, 0);

    p->value = 0;

    for (int i = 0; i < n_workers; i++) {

        if (fork() == 0) {

            for (int j = 0; j < m_times; j++) {
                Increm1(p);
            }

            exit(0);
        }
    }

    for (long int j = 0; j < n_workers; ++j) {
        wait(NULL);
    }

    printf("value = %ld\n", p->value);

    clock_gettime(CLOCK_MONOTONIC, &t2);

    printf("time - %.3lf\n", (t2.tv_sec - t1.tv_sec) + (t2.tv_nsec - t1.tv_nsec) * 0.000000001);

//////////////////////////////////////////////////////////////////

    p->value = 0;

    for (int i = 0; i < n_workers; i++) {

        if (fork() == 0) {

            for (int j = 0; j < m_times; j++) {
                Increm2(p);
            }

            exit(0);
        }
    }

    for (long int j = 0; j < n_workers; ++j) {
        wait(NULL);
    }

    printf("value = %ld\n", p->value);

    shmdt(p);

    shmctl(id, IPC_RMID, NULL);

    return 0;
}