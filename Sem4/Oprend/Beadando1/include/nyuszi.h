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
void nyuszi_print(nyuszi_t* nyuszi);
char* nyuszi_to_str(nyuszi_t* nyuszi);
nyuszi_t* nyuszi_str_conv(char* line);

typedef struct Nyuszik {
    nyuszi_t** data;
    size_t len;
} nyuszi_list_t;

nyuszi_list_t* load_from_file(const char* path);
void nyuszi_list_append(nyuszi_list_t* nyuszik, nyuszi_t* nyuszi);
void nyuszi_list_free(nyuszi_list_t* nyuszik);
void nyuszi_list_update_name(nyuszi_list_t* nyuszik, char* search, char* new_name);
void nyuszi_list_update_poem(nyuszi_list_t* nyuszik, char* search, char* new_poem);
void nyuszi_list_update_eggs(nyuszi_list_t* nyuszik, char* search, int new_eggs);
void nyuszi_list_delete(nyuszi_list_t* nyuszik, char* search);

#endif // !NYUSZI_H
