#ifndef NYUSZI_H
#define NYUSZI_H

#define NYUSZI_NAME_CAPACITY 100
#define VERS_CAPACITY 1024

typedef struct Nyuszi {
    char name[NYUSZI_NAME_CAPACITY];
    char vers[VERS_CAPACITY];
    int eggs;
} nyuszi_t;


void nyuszi_print(nyuszi_t nyuszi);

#endif // !NYUSZI_H
