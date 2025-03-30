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

// ERROR: Valgrind uninitialized stack value error
char** read_file_lines(const char* path, size_t* line_count) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error while loading data\n");
        exit(1);
    }

    char** lines = NULL;
    size_t c = 0;
    char* line;
    size_t line_len;
    size_t read;

    while ((read = getline(&line, &line_len, file)) != -1) {
        line[strcspn(line, "\n")] = '\0';

        lines = realloc(lines, (c + 1) * sizeof(char*));
        if (lines == NULL) {
            fprintf(stderr, "Error while loading data\n");
            exit(1);
        }

        lines[c] = malloc(read);
        if (lines[c] == NULL) {
            fprintf(stderr, "Error while loading data\n");
            exit(1);
        }
        strcpy(lines[c], line);

        c++;
    }

    fclose(file);
    free(line);

    *line_count = c;
    return lines;
}

nyuszi_list_t* load_from_file(const char* path) {
    size_t line_count = 0;
    char** data_lines = read_file_lines(path, &line_count);

    
    
    for (size_t i = 0; i < line_count; ++i) {
        printf("%li: %s\n", i, data_lines[i]);
        free(data_lines[i]);
    }
    free(data_lines);

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
