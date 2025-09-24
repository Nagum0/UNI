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

#define MAX_MESSAGE_LEN 50
struct mq_attr attr = {
    .mq_maxmsg = 5,               // maximum hány üzenet lehet a sorban
    .mq_msgsize = MAX_MESSAGE_LEN // egyenként legfeljebb mekkorák
};

int main()
{
    char *mq_name = "/ThIsIdShOuLdBeUnIqUe";
    mqd_t priority_mq = mq_open(mq_name, O_RDWR | O_CREAT, 0600, &attr);
    if (priority_mq == -1)
    {
        printf("mq_open error reason code: %d\n", errno);
        return 1;
    }
    pid_t fork_ret = fork();
    if (fork_ret > 0)
    { // parent
        char *to_send_msg = "low priority message";
        if (mq_send(priority_mq, to_send_msg, strlen(to_send_msg) + 1, 8) == -1)
        {
            printf("mq_send error reason code: %d\n", errno);
            kill(fork_ret, SIGKILL);
        }
        else
        {
            // késleltethetjük a magasabb prioritású üzenetet
            // sleep(2);
            to_send_msg = "higher priority message";
            if (mq_send(priority_mq, to_send_msg, strlen(to_send_msg) + 1, 30) == -1)
            {
                printf("mq_send error reason code: %d\n", errno);
                kill(fork_ret, SIGKILL);
            }
            else
            {
                wait(NULL);
            }
        }
        mq_close(priority_mq);
        if (mq_unlink(mq_name) == -1)
        {
            printf("mq_unlink error reason code: %d\n", errno);
        }
    }
    else if (fork_ret == 0)
    { // child
        char msg_buffer[MAX_MESSAGE_LEN];
        unsigned read_priority;
        ssize_t msg_read_bytes;
        if ((msg_read_bytes = mq_receive(priority_mq, msg_buffer,
                                         MAX_MESSAGE_LEN, &read_priority)) != -1)
        {
            printf("message having priority %u and length of %zd read:%s\n", read_priority, msg_read_bytes, msg_buffer);
        }
        if ((msg_read_bytes = mq_receive(priority_mq, msg_buffer,
                                         MAX_MESSAGE_LEN, &read_priority)) != -1)
        {
            printf("message having priority %u and length of %zd read:%s\n", read_priority, msg_read_bytes, msg_buffer);
        }
        mq_close(priority_mq);
    }
    else
    {
        mq_close(priority_mq);
        if (mq_unlink(mq_name) == -1)
        {
            printf("mq_unlink error reason code: %d\n", errno);
        }
    }
    return 0;
}
