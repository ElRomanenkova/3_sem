#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

#define SUCCESS 0

int CompareInt (const void * a_ptr, const void * b_ptr) {
    return *((int *)a_ptr) - *((int *)b_ptr);
}

struct sorted {
    int * buff; // begin
    int * curr_smallest;
    int * end;
    size_t size;
};

void * Par_Sort (void * data) {

    struct sorted * buff = (struct sorted *) data;

    qsort(buff->buff, buff->size, sizeof(int), &CompareInt);
    buff->curr_smallest = buff->buff;
    buff->end = buff->buff + buff->size;

    return SUCCESS;
}

int * FinalSort(struct sorted ** buff, int * out_buff, size_t num_elem, int num_thr) {

    for(size_t i = 0; i < num_elem; i++) {
        int min = 0x7fffffff;
        int index = 0;
        for(int j = 0; j < num_thr; j++) {
            if (*(buff[j]->curr_smallest) < min && (buff[j]->curr_smallest != buff[j]->end)) {
                min = *(buff[j]->curr_smallest);
                index = j;
            }
        }
        (buff[index]->curr_smallest)++;
        out_buff[i] = min;
    }

    return out_buff;
}

int main(int argc, char ** argv) {

    if (argc != 3) {
        perror("Incorrect number of argc");
        exit(EXIT_FAILURE);
    }

    int size_of_array = atoi(argv[1]);

    int number_of_stream = atoi(argv[2]);
    int size = size_of_array/number_of_stream + 1;

    int * data = malloc(sizeof(int) * size_of_array);
    int * copy_data = malloc(sizeof(int) * size_of_array);
    int * res = malloc(sizeof(int) * size_of_array);

    for (int i = 0; i < size_of_array; i++) {
        copy_data[i] = data[i] = rand() % (size_of_array + 1);
    }

    pthread_t id_s[number_of_stream];
    int status_adr_s = 0;
    int status = 0;

    struct sorted ** sorted_ind = malloc(sizeof(struct sorted *) * number_of_stream);
    for (int i = 0; i < number_of_stream; i++) {
        sorted_ind[i] = malloc(sizeof(struct sorted));
    }

    int * already_sorted = data;

    for (int i = 0; i < number_of_stream; i++) {

        if (already_sorted < data + size_of_array) {
            sorted_ind[i]->buff = already_sorted;
            sorted_ind[i]->curr_smallest = NULL;
            sorted_ind[i]->end = already_sorted + (size - 1);
            sorted_ind[i]->size = size;
            if (sorted_ind[i]->end >= data + size_of_array) {
                sorted_ind[i]->end = data + size_of_array - 1;
                sorted_ind[i]->size = data + size_of_array - already_sorted;
            }
        }

//        printf("%ld - buff, %ld - curr, %ld - end, %ld - size\n", sorted_ind[i]->buff - data, sorted_ind[i]->curr_smallest - data, sorted_ind[i]->end - data, sorted_ind[i]->size);
        status = pthread_create(&id_s[i], NULL, &Par_Sort, (void *)sorted_ind[i]);

        already_sorted = sorted_ind[i]->end + 1;
        sorted_ind[i] = sorted_ind[i];

        if (status != SUCCESS) {
            printf("Can't join thread, status = %d\n", status);
            exit(1);
        }

    }

    for (long int j = 0; j < number_of_stream; ++j) {
        status = pthread_join(id_s[j], (void**)&status_adr_s);

        if (status != SUCCESS) {
            printf("Can't join thread, status = %d\n", status);
            exit(2);
        }
    }

    res = FinalSort(sorted_ind, res, size_of_array, number_of_stream);

    qsort(copy_data, size_of_array, sizeof(int), &CompareInt);

    int flag = 1;

    for (int i = 0; i < size_of_array; i++) {
        if (copy_data[i] != res[i])
            flag = 0;
    }

    if (flag == 1)
        printf ("OK :3\n");
    else
        printf("NOT OK (|_|)\n");

    for (int i = 0; i < number_of_stream; i++) {
        free(sorted_ind[i]);
    }
    free(sorted_ind);
    free(data);
    free(copy_data);
    free(res);

    return 0;
}
