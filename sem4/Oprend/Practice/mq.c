#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <mqueue.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define pt(fstr, ...) {printf("[%s] "fstr"\n", whoami ?: "N/A", ##__VA_ARGS__);}

void dummy_handler(int x){}

char* whoami = 0;

struct msg {
    long type;
    char text[1024];
};

int main() {
    key_t key = ftok("x", 1);
    int msgid = msgget(key, 0600 | IPC_CREAT);

    pid_t child = fork();
    
    if (child > 0) {
        whoami = "parent";
        
        // Send
        struct msg m;
        m.type = 1;
        const char* text = "Hello my child.";
        strncpy(m.text, text, strlen(text) + 1);
        sleep(1);
        msgsnd(msgid, &m, sizeof(m.text), 0);

        // Receive
        struct msg rec_m;
        msgrcv(msgid, &rec_m, 1024, 2, 0);
        pt("Received message: %li, %s", rec_m.type, rec_m.text);

        msgctl(msgid, IPC_RMID, NULL);
    }
    else {
        whoami = "child";
        
        // Receive
        struct msg rec_m;
        msgrcv(msgid, &rec_m, 1024, 1, 0);
        pt("Received message: %li, %s", rec_m.type, rec_m.text);
        
        // Send
        struct msg send_m;
        send_m.type = 2;
        const char* text = "Hello, parent!";
        strncpy(send_m.text, text, strlen(text) + 1);
        sleep(1);
        msgsnd(msgid, &send_m, sizeof(send_m.text), 0);
    }

    return 0;
}
