#include <stdio.h>
#include <stdlib.h>

enum Commands {
    QUIT,
    ADD_VALUE,
    ADD_BLOCK
};

typedef struct {
    char key[256];
    char value[256]; 
} Value;

typedef struct {
    Value values[50];
} Block;

Block *createBlock();

int main(void) {
    int cmd;

    Block *jsonBlocks = createBlock();

    do {
        printf("$ ");
        scanf("%d", &cmd);

        switch (cmd) {
            case 0:
                exit(0);
            case 1:
                printf("add_val\n");
                break;
            case 2:
                printf("add_block\n");
                break;
            default:
                printf("Non existent command!\n");
                break;
        }

    } while (cmd != QUIT);

    return 0;
}

Block *createBlock() {
    Value val;

    printf("key: ");
    
}