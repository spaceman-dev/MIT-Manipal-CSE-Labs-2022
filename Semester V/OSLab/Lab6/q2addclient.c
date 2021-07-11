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
    printf("Starting Client..\n");
    int active = 1;
    MSG msgSent;
    char buff[BUFSIZ];
    int msgid = msgget((key_t)MSG_KEY, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("msgget()");
        exit(EXIT_FAILURE);
    }
    int hr = 11;
    int min = 0;
    while (active)
    {
        int num = rand() % 100;
        msgSent.msg_type = 1;
        msgSent.num = num;
        msgSent.hr = hr;
        msgSent.min = min;
        printf("Send Data:: Num:%d, HR:%d, MIN:%d\n", num, hr, min);
        if (msgsnd(msgid, (void *)&msgSent, sizeof(int) * 3, 0) == -1)
        {
            perror("msgsnd()");
            exit(EXIT_FAILURE);
        }
        if (msgSent.num == -1)
        {
            active = 0;
            printf("Shutting down client...\n");
            break;
        }
        min += 10;
        if (min >= 60)
        {
            min = 0;
            hr++;
        }
        sleep(1);
    }
    exit(EXIT_SUCCESS);
}