#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/nyuszi.h"

void nyuszi_set_name(nyuszi_t* nyuszi, char* name) {
    strncpy(nyuszi->name, name, LEN_NAME);
    nyuszi->name[strcspn(nyuszi->name, "\n")] = '\0';
}

void nyuszi_set_poem(nyuszi_t* nyuszi, char* poem) {
    strncpy(nyuszi->poem, poem, LEN_POEM);
    nyuszi->poem[strcspn(nyuszi->poem, "\n")] = '\0';
}

void nyuszi_set_eggs(nyuszi_t* nyuszi, int eggs) {
    nyuszi->eggs = eggs;
}

char* nyuszi_to_str(nyuszi_t* nyuszi) {
    char* buffer = malloc(LEN_NYUSZI_STR);
    if (buffer == NULL) {
        fprintf(stderr, "Error while converting nyuszi to string...\n");
        exit(1);
    }
    sprintf(buffer, "%-20s %-5d %s", nyuszi->name, nyuszi->eggs, nyuszi->poem);

    return buffer;
}

void nyuszi_list_append(nyuszi_list_t* nyuszik, nyuszi_t* nyuszi) {
    nyuszik->data = realloc(nyuszik->data, (nyuszik->len + 1) * sizeof(nyuszi_t*));
    if (nyuszik->data == NULL) {
        fprintf(stderr, "Error while appending nyuszi to nyuszik...\n");
        exit(1);
    }
    nyuszik->data[nyuszik->len] = nyuszi;
    nyuszik->len++;
}

void nyuszi_list_free(nyuszi_list_t* nyuszik) {
    for (size_t i = 0; i < nyuszik->len; ++i) {
        free(nyuszik->data[i]);
    }

    free(nyuszik->data);
    free(nyuszik);
}
