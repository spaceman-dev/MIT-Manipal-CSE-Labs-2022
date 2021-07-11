#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>
#define MAX_TEXT 512
struct my_msg_st
{
    long int my_msg_type;
    int msg;
};
int reverse(int x)
{
    int y = 0;
    while (x > 0)
    {
        y *= 10;
        y += x % 10;
        x /= 10;
    }
    return y;
}
int main(int argc, char const *argv[])
{
    int running = 1;
    struct my_msg_st some_data;
    long int msg_to_receive = 0;
    int msgid;
    int num;
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        fprintf(stderr, "msgget failed with error%d\n", errno);
        exit(EXIT_FAILURE);
    }
    while (running)
    {
        if (msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0) == -1)
        {
            fprintf(stderr, "msgrc failedwith error %d\n", errno);
            exit(EXIT_FAILURE);
        }
        printf("You wrote  %d\n", some_data.msg);
        if (some_data.msg == reverse(some_data.msg))
            printf("Number received is a palindrome\n");
        else
            printf("Number received is not a palindrome\n");
        if (some_data.msg == -1)
            running = 0;
    }
    if (msgctl(msgid, IPC_RMID, 0) == -1)
    {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}