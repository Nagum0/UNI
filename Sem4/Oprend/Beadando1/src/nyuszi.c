#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/nyuszi.h"

#define FOR_EACH_NYUSZI(body) \
    for (size_t i = 0; i < nyuszik->len; ++i) { \
        nyuszi_t* nyuszi = nyuszik->data[i]; \
        if (nyuszi != NULL && strcmp(nyuszi->name, search) == 0) { \
            body \
        } \
    } \

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

void nyuszi_print(nyuszi_t* nyuszi) {
    if (nyuszi == NULL)
        printf("REMOVED\n");
    else
        printf("%-20s %-5d %s\n", nyuszi->name, nyuszi->eggs, nyuszi->poem);
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

char* read_file(const char* path) {
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        fprintf(stderr, "Error while loading data\n");
        exit(1);
    }
    
    fseek(f, 0, SEEK_END);
    size_t f_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* contents = malloc(f_size);
    if (contents == NULL) {
        fprintf(stderr, "Error while loading data\n");
        exit(1);
    }

    fread(contents, 1, f_size, f);
    printf("%s\n", contents);

    fclose(f);
    
    return contents;
}

nyuszi_list_t* load_from_file(const char* path) {
    char* data_str = read_file(path);
       
    return NULL;
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

nyuszi_t* nyuszi_list_search(nyuszi_list_t* nyuszik, const char* name) {
    nyuszi_t* result = NULL;

    for (size_t i = 0; i < nyuszik->len; ++i) {
        nyuszi_t* nyuszi = nyuszik->data[i];
        if (nyuszi != NULL && strcmp(nyuszi->name, name) == 0) {
            result = nyuszi;
            break;
        }
    }

    return result;
}

void nyuszi_list_delete(nyuszi_list_t* nyuszik, char* search) {
    FOR_EACH_NYUSZI( 
        free(nyuszik->data[i]); 
        nyuszik->data[i] = NULL; 
        break;
    )
}

void nyuszi_list_update_name(nyuszi_list_t* nyuszik, char* search, char* new_name) {
    FOR_EACH_NYUSZI(
        nyuszi_set_name(nyuszi, new_name);
        break;
    )
}

void nyuszi_list_update_poem(nyuszi_list_t* nyuszik, char* search, char* new_poem) {
    FOR_EACH_NYUSZI(
        nyuszi_set_poem(nyuszi, new_poem);
        break;
    )
}

void nyuszi_list_update_eggs(nyuszi_list_t* nyuszik, char* search, int new_eggs) {
    FOR_EACH_NYUSZI(
        nyuszi_set_eggs(nyuszi, new_eggs);
        break;
    )
}
