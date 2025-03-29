#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/nyuszi.h"
#include "../include/cmd.h"

void flush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_manual() {
    printf("-------- MANUAL --------\n");
    printf("%-22s %d\n", "EXIT", 1);
    printf("%-22s %d\n", "CHANGE NAME", 2);
    printf("%-22s %d\n", "CHANGE POEM", 3);
    printf("%-22s %d\n", "CHANGE EGGS", 4);
    printf("%-22s %d\n", "LIST PARTICIPANTS", 5);
    printf("%-22s %d\n", "SIGN UP A PARTICIPANT", 6);
    printf("%-22s %d\n", "DELETE PARTICIPANT", 7);
    printf("%-22s %d\n", "MANUAL", 8);
}

void sign_up_handler(nyuszi_list_t* nyuszik) {
    flush_stdin();

    nyuszi_t* nyuszi = malloc(sizeof(nyuszi_t));

    printf("Participant name: ");
    char name_buffer[LEN_NAME];
    if (fgets(name_buffer, LEN_NAME, stdin) == NULL) {
        fprintf(stderr, "Error while signing up new participant...\n");
        exit(1);
    }
    nyuszi_set_name(nyuszi, name_buffer);
    
    if (strlen(nyuszi->name) == LEN_NAME - 1)
        flush_stdin();

    printf("Participant poem: ");
    char poem_buffer[LEN_POEM];
    if (fgets(poem_buffer, LEN_POEM, stdin) == NULL) {
        fprintf(stderr, "Error while signing up new participant...\n");
        exit(1);
    }
    nyuszi_set_poem(nyuszi, poem_buffer);
    
    if (strlen(nyuszi->poem) == LEN_POEM - 1)
        flush_stdin();

    printf("Participant eggs: ");
    scanf("%d", &nyuszi->eggs);

    nyuszi_list_append(nyuszik, nyuszi);
}

void list_handler(nyuszi_list_t* nyuszik) {
    for (size_t i = 0; i < nyuszik->len; ++i) {
        nyuszi_print(nyuszik->data[i]);
    }
}

void delete_handler(nyuszi_list_t* nyuszik) {
    flush_stdin();

    printf("Participant name: ");
    char buffer[LEN_NAME];
    if (fgets(buffer, LEN_NAME, stdin) == NULL) {
        fprintf(stderr, "Error while deleting participant...\n");
        exit(1);
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    if (strlen(buffer) == LEN_NAME - 1) 
        flush_stdin();
    
    nyuszi_list_delete(nyuszik, buffer);
}
