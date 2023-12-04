#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

struct DATE {
    int year;
    int month;
    int day;
};

typedef struct DATE *date_t;

date_t createDate(int y, int m, int d) {
    date_t dt;
    
    if (checkDate(y, m, d) == 1) {
        printf("Incorrect date format!\n");
        return NULL;
    }

    if (NULL == (dt = (date_t) malloc(sizeof(struct DATE)))) {
        printf("Error while creating the new date!\n");
        return NULL;
    }

    dt->year = y;
    dt->month = m;
    dt->day = d;

    return dt;
}

void destroyDate(date_t dt) {
    free(dt);
}

// GETTERS & SETTERS
int getDay(date_t dt) {
    return dt->day;
}

int getMonth(date_t dt) {
    return dt->month;
}

int getYear(date_t dt) {
    return dt->year;
}

// STATIC
static int checkDate(int y, int m, int d) {
    if ((1985 < y && y < 2024) && (1 < m && m < 12) && (1 < d && d < 31)) {
        return 0;
    }
    
    return 1;
}