#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <sys/stat.h>
#include <getopt.h>
#include <errno.h>
#include <assert.h>

struct flag {
    int R;
    int l;
    int n;
    int a;
    int d;
    int i;
} Flag;

const struct option opts[] =
        {{"long",      0, NULL, 'l'},
         {"all",       0, NULL, 'a'}, //пока не прописано
         {"inode",     0, NULL, 'i'},
         {"numeric",   0, NULL, 'n'},
         {"recursive", 0, NULL, 'R'},
         {"directory", 0, NULL, 'd'}, //пока не прописано
         {NULL,        0, NULL, 0  }};


//int file_output(const char * filename) {   // for file
//    if (strcmp(filename, ".") != 0 && strcmp(filename, "..") != 0)
//        printf("%s\n", filename);
//    //printf("\n");
//    return 0;
//}

void print_data(struct dirent * elem, char * path_name) {

    if (Flag.l || Flag.n) {

    }
    else {
        if (Flag.i)
            printf("%lu ", elem->d_ino);

        printf("%s  ", elem->d_name);

//        if (Flag.opt_column)
        printf("\n");
    }
}

char * new_path_name (char * path_name, char * name_metadata) {

//    char * copy_dirname = strdup(old_path_name);
//    file_output(name_metadata); // change name or function
    char * name = strcat(path_name, "/");
    char * full_name = strcat(name, name_metadata);

    return full_name;

}

int dir_output (char * dirname) {

    DIR * directory = opendir(dirname);

    if (directory == NULL) {
        return -1;
    }

    struct dirent * metadata = NULL;

    while ((metadata = readdir(directory))) {

        if (errno) {
            perror("readdir");
            return -1;
        }
//        if (!metadata)
//            break;

        if (Flag.a == 0)
            if (metadata->d_name[0] == '.')
                continue;

//        if (strcmp(metadata->d_name, ".") != 0 && strcmp(metadata->d_name, "..") != 0) //почему-то падает
        print_data(metadata, dirname);

//        metadata = readdir(directory);
    }

//    closedir(directory);
//
//    directory = opendir(dirname);

    rewinddir(directory); //сброс на начало
    metadata = NULL;

    if (Flag.R) {

//        rewinddir(directory); //сброс на начало
//        metadata = readdir(directory);

        while ((metadata = readdir(directory))) {

            if (errno) {
                perror("readdir");
                return -1;
            }

            char * copy_dirname = strdup(dirname);
            char * metadata_path = new_path_name(dirname, metadata->d_name);
//            lstat(metadata_path, &st);

//            if (strcmp(metadata->d_name, ".") != 0 && strcmp(metadata->d_name, "..") != 0 && S_ISDIR(st.st_mode)) {
            if (strcmp(metadata->d_name, ".") != 0 && strcmp(metadata->d_name, "..") != 0 && metadata->d_type == DT_DIR) {
                printf("(%s)\n", metadata_path);
                if (dir_output(metadata_path) == -1) {
                    free(copy_dirname);
                    return -1;
                }
                free(copy_dirname);

            }

//            metadata = readdir(directory);

            free(copy_dirname);
        }
    }
//    printf("\n");

    closedir(directory);

    return 0;

}

int main(int argc, char * argv[]) {

    while (1) {

        int opt_res = getopt_long(argc, argv, "adilnR", opts, NULL);
        if (opt_res == -1)
            break;

        switch (opt_res) {
            case 'R':
                Flag.R = 1; /* true */
                break;

            case 'l':
                Flag.l = 1;
                break;

            case 'n':
                Flag.n = 1;
                break;

            case 'a':
                Flag.a = 1;
                break;

            case 'd':
                Flag.d = 1;
                break;

            case 'i':
                Flag.i = 1;
                break;

            default:
                break;
        }

    }

//    struct stat st;

    if (optind == argc) {
        dir_output("/");
        return 0;
    }

    for (int i = optind; i < argc; i++) {
        char * dir = strdup(argv[i]);
//        printf("optind %d\n", optind);

//        if (lstat(argv[i], &st) == 0 && (S_ISDIR(st.st_mode)) )
            dir_output(dir);

        free(dir);
    }

    return 0;
}