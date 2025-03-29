#ifndef NYUSZI_H
#define NYUSZI_H

#include <stddef.h>
#define LEN_NAME 100
#define LEN_POEM 1024
#define LEN_NYUSZI_STR 1600

typedef struct Nyuszi {
    char name[LEN_NAME];
    char poem[LEN_POEM];
    int eggs;
} nyuszi_t;

void nyuszi_set_name(nyuszi_t* nyuszi, char* name);
void nyuszi_set_poem(nyuszi_t* nyuszi, char* poem);
void nyuszi_set_eggs(nyuszi_t* nyuszi, int eggs);
char* nyuszi_to_str(nyuszi_t* nyuszi);

typedef struct Nyuszik {
    nyuszi_t** data;
    size_t len;
} nyuszi_list_t;

void nyuszi_list_append(nyuszi_list_t* nyuszik, nyuszi_t* nyuszi);
void nyuszi_list_free(nyuszi_list_t* nyuszik);

#endif // !NYUSZI_H
