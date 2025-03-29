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
    sprintf(buffer, "%-20s %-5d %s", nyuszi->name, nyuszi->eggs, nyuszi->poem);
    return buffer;
}
