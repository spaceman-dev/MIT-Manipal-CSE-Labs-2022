#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "q1addheader.h"
#include <string.h>
int main(int argc, char const *argv[])
{
    int shmid = shmget((key_t)1334, sizeof(struct shared_str), 0666 | IPC_CREAT);
    sleep(1);
    struct shared_str *shared_mem = shmat(shmid, (void *)0, 0);
    if (shared_mem == (void *)-1)
    {
        printf("shmat() failed\n");
        exit(-1);
    }
    printf("Memory attached at %p for producer process\n", shared_mem);
    shared_mem->status = 0;
    int running = 1;
    while (running == 1)
    {
        if (shared_mem->status == 0)
        {
            sleep(1);
            continue;
        }
        shared_mem->status = 0;
        char str[100];
        printf("The consumer received : %s\n", shared_mem->msg);
        if (strncmp(shared_mem->msg, "end", 3) == 0)
            running = 0;
    }
    return 0;
}