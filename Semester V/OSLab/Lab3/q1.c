#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
    int status;
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        printf("Error in creating child process\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        printf("Child Process executing\n");
        exit(0);
    }
    else
    {
        wait(&status);
        printf("Parent Process executing\n");
        printf("Child returned status : %d\n", status);
    }
    return 0;
}