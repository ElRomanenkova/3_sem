#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <wait.h>


char ** GetTokens(char * value) {

    size_t size = 1;

    char ** parts = malloc(sizeof(char *) * size);
    if (!parts) {
        exit(1);
    }

    char * temp_part = strtok(value, " ");

    while (temp_part) {

        if (strlen(temp_part) != 0) {

            char * part = strdup(temp_part);
            if (!part) {
                exit(1);
            }

            parts[size - 1] = part;

            parts = realloc(parts, (++size) * sizeof(char *));
            if (!parts) {
                exit(1);
            }
        }

        temp_part = strtok(NULL, " ");

    }

    parts[size - 1] = NULL;

    return parts;
}

int main() {

    while (1) {

        char * input = readline("(*-*)/ ");

        if (!input) {  // для выхода по Ctrl D
            exit(0);
        }

        if (strlen(input) != 0) {

            char ** tokens = GetTokens(input);

            if (fork() == 0) {

                if (execvp(tokens[0], tokens) == -1) {
                    printf("%s: command not found\n", input);
                    exit(0);
                }

            }

            free(tokens);
        }

        wait(NULL);
        free(input);

    }

}