#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main() {
    char buff[100] = "This is me before getting forked lol.";
    printf("%s\n", buff);

    pid_t child = fork();

    if (child < 0) {
        fprintf(stderr, "Child was not created.\n");
        return 1;
    }
    else if (child > 0) {
        strcpy(buff, "I got forked...");
        printf("Hello, from child: %d %s\n", getpid(), buff);
    }
    else {
        strcpy(buff, "I am parent haha");
        printf("Hello, from parent: %d %s\n", getpid(), buff);
    }

    return 0;
}
