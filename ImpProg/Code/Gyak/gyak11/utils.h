#ifndef UTILS_H
#define UTILS_H

struct DATE;
typedef struct DATE *date_t;

date_t createDate(int y, int m, int d);
void destroyDate(date_t dt);

// GETTERS & SETTERS
int getDay(date_t dt);
int getMonth(date_t dt);
int getYear(date_t dt);

// STATIC
static int checkDate(int y, int m, int d);

#endif