#include <stdio.h>
#include <stdlib.h>

size_t _getline(char **lineptr, size_t *n, FILE *stream) {
    size_t pos = 0;
    char *new_lineptr;
    int c;

    if (*lineptr == NULL || *n == 0) {
        *n = 128;  
        *lineptr = malloc(*n);
        if (*lineptr == NULL) {
            return -1; 
        }
    }

    while ((c = fgetc(stream)) != EOF) {
        if (pos + 1 >= *n) {
            *n *= 2;
            new_lineptr = realloc(*lineptr, *n);
            if (new_lineptr == NULL) {
                return -1;
            }
            *lineptr = new_lineptr;
        }

        (*lineptr)[pos++] = c;

        if (c == '\n') {
            break;
        }
    }

    (*lineptr)[pos] = '\0';
    return pos;
}

