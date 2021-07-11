#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSG_TO_RECV 0
#define MSG_KEY 1234
typedef struct msg_st
{
    long int msg_type;
    int num;
    int hr;
    int min;
} MSG;
int main()
{
    int active = 1;
    MSG msgRecv;
    char buff[BUFSIZ];
    int msgid = msgget((key_t)MSG_KEY, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("msgget()");
        exit(EXIT_FAILURE);
    }
    printf("Starting Server...\n");
    int count = 0;
    int sum = 0;
    while (active)
    {
        if (msgrcv(msgid, (void *)&msgRecv, BUFSIZ, MSG_TO_RECV, 0) == -1)
        {
            perror("msgrecv()");
            exit(EXIT_FAILURE);
        }
        if (msgRecv.num == -1)
        {
            active = 0;
            printf("Shutting down Server...\n");
            break;
        }
        printf("Active Users: %d, HR:%d, MIN:%d\n", msgRecv.num, msgRecv.hr, msgRecv.min);
        count++;
        sum += msgRecv.num;
        if (count == 6)
        {
            printf("AVG USERS in (HR-%d):%d\n", msgRecv.hr, sum / count);
            count = 0;
            sum = 0;
        }
    }
    if (msgctl(msgid, IPC_RMID, 0) == -1)
    {
        perror("msgctl");
        exit(1);
    }
    exit(EXIT_SUCCESS);
}