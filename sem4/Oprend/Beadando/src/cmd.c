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
    printf("%-22s %d\n", "SAVE", 9);
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

    // printf("Participant eggs: ");
    // scanf("%d", &nyuszi->eggs);
    nyuszi->eggs = 0;

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

void change_name_handler(nyuszi_list_t* nyuszik) {
    flush_stdin();

    printf("Participant name: ");
    char name_buffer[LEN_NAME];
    if (fgets(name_buffer, LEN_NAME, stdin) == NULL) {
        fprintf(stderr, "Error while renaming participant...\n");
        exit(1);
    }
    name_buffer[strcspn(name_buffer, "\n")] = '\0';

    if (strlen(name_buffer) == LEN_NAME - 1) 
        flush_stdin();

    printf("New name: ");
    char new_name_buffer[LEN_NAME];
    if (fgets(new_name_buffer, LEN_NAME, stdin) == NULL) {
        fprintf(stderr, "Error while renaming participant...\n");
        exit(1);
    }
    new_name_buffer[strcspn(new_name_buffer, "\n")] = '\0';

    if (strlen(new_name_buffer) == LEN_NAME - 1) 
        flush_stdin();
    
    nyuszi_list_update_name(nyuszik, name_buffer, new_name_buffer);
}

void change_poem_handler(nyuszi_list_t* nyuszik) {
    flush_stdin();

    printf("Participant name: ");
    char name_buffer[LEN_NAME];
    if (fgets(name_buffer, LEN_NAME, stdin) == NULL) {
        fprintf(stderr, "Error while renaming participant...\n");
        exit(1);
    }
    name_buffer[strcspn(name_buffer, "\n")] = '\0';

    if (strlen(name_buffer) == LEN_NAME - 1) 
        flush_stdin();

    printf("New poem: ");
    char new_poem_buffer[LEN_POEM];
    if (fgets(new_poem_buffer, LEN_POEM, stdin) == NULL) {
        fprintf(stderr, "Error while renaming participant...\n");
        exit(1);
    }
    new_poem_buffer[strcspn(new_poem_buffer, "\n")] = '\0';

    if (strlen(new_poem_buffer) == LEN_POEM - 1) 
        flush_stdin();
    
    nyuszi_list_update_poem(nyuszik, name_buffer, new_poem_buffer);
}

void change_eggs_handler(nyuszi_list_t* nyuszik) {
    flush_stdin();

    printf("Participant name: ");
    char name_buffer[LEN_NAME];
    if (fgets(name_buffer, LEN_NAME, stdin) == NULL) {
        fprintf(stderr, "Error while renaming participant...\n");
        exit(1);
    }
    name_buffer[strcspn(name_buffer, "\n")] = '\0';

    if (strlen(name_buffer) == LEN_NAME - 1) 
        flush_stdin();
    
    printf("New egg count: ");
    int new_eggs;
    scanf("%d", &new_eggs);
        
    nyuszi_list_update_eggs(nyuszik, name_buffer, new_eggs);
}

void save_handler(const char* path, nyuszi_list_t* nyuszik) {
    flush_stdin();
    save_to_file(path, nyuszik);
}

void winner_handler(nyuszi_list_t* nyuszik) {
    nyuszi_t* winner = nyuszi_list_winner(nyuszik);
    if (winner != NULL) {
        printf("The winner is: ");
        nyuszi_print(winner);
    }
}
