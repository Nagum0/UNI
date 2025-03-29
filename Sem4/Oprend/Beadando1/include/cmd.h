#ifndef CMD_H
#define CMD_H

/*
 *
 * ------- USER COMMANDS -------
 *
 * */

#include "nyuszi.h"
typedef enum {
    EXIT = 1,
    CHANGE_NAME,
    CHANGE_VERS,
    CHANGE_EGGS,
    LIST,
    SIGN_UP,
    DELETE_NYUSZI,
    MAN,
} cmd_t;

void flush_stdin();
void print_manual();
void sign_up_handler(nyuszi_list_t* nyuszik);
void list_handler(nyuszi_list_t* nyuszik);
void delete_handler(nyuszi_list_t* nyuszik);

#endif // !CMD_H
