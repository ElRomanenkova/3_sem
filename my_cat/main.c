#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void ReadWriteFile (int fd) {

    int bytes_read = 0;
    const int size = 10;

    do {
        char buf[1024];
        bytes_read = read(fd, buf, size);
        int written = 0;
        while (written < bytes_read) {
            int bytes_write = write(1, buf + written, bytes_read - written);
            written += bytes_write;
        }
    }
    while (bytes_read != 0);
}

int main(int argc, char ** argv) {

    int fd_arg;

    if (argc == 1) { // cat without arguments
        ReadWriteFile(0);
    }

    else { // cat with arguments

        for (int i = 1; i < argc; ++i) {
            fd_arg = open(argv[i], O_RDONLY);
            ReadWriteFile(fd_arg);
            close(fd_arg);
        }

    }

    return 0;
}