#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
struct shared_str
{
    int status;
    char alphabet;
};
int main(int argc, char const *argv[])
{
    int shmid = shmget((key_t)1234, sizeof(struct shared_str), 0666 | IPC_CREAT);
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Error in fork()\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        struct shared_str *shared_mem = shmat(shmid, (void *)0, 0);
        if (shared_mem == (void *)-1)
        {
            printf("shmat() failed\n");
            exit(-1);
        }
        printf("Memory attached at %p for child process\n", shared_mem);
        while (1)
        {
            if (shared_mem->status < 0)
            {
                if (shmdt(shared_mem) == -1)
                {
                    printf("shmdt failed\n");
                    exit(-1);
                }
                break;
            }
            if (shared_mem->status == 1)
            {
                char c = shared_mem->alphabet;
                printf("\n");
                if ((int)c >= 65 && (int)c <= 90)
                    c = ((c - 'A' + 1) % 26) + 'A';
                else if ((int)c >= 97 && (int)c <= 122)
                    c = ((c - 'a' + 1) % 26) + 'a';
                else
                    printf("Non-alphabetic character received\n");
                shared_mem->alphabet = c;
                shared_mem->status = 2;
            }
        }
    }
    else
    {
        sleep(1);
        struct shared_str *shared_mem = shmat(shmid, (void *)0, 0);
        if (shared_mem == (void *)-1)
        {
            printf("shmat() failed\n");
            exit(-1);
        }
        printf("Memory attached at %p for parent process\n", shared_mem);
        shared_mem->status = 0;
        while (1)
        {
            if (shared_mem->status == 1)
                continue;
            if (shared_mem->status == 2)
                printf("%c\n", shared_mem->alphabet);
            shared_mem->status = 0;
            char c, nl;
            printf("Enter an alphabet (0 to exit) : \n");
            scanf("%c", &c);
            scanf("%c", &nl);
            if (c == '0')
            {
                shared_mem->status = -1;
                printf("Exiting...\n");
                if (shmdt(shared_mem) == -1)
                {
                    printf("shmdt failed\n");
                    exit(-1);
                }
                if (shmctl(shmid, IPC_RMID, 0) == -1)
                {
                    printf("shmctl failed\n");
                    exit(-1);
                }
                break;
            }
            shared_mem->alphabet = c;
            shared_mem->status = 1;
        }
    }
    return 0;
}