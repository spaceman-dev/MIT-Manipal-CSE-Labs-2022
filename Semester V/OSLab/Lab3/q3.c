#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("Error creating child process\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        printf("Child Process executing\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        printf("Child PID: %d\n", pid);
    }
    else
    {
        wait(NULL);
        printf("Parent Process executing\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        printf("Child PID: %d\n", pid);
    }
    return 0;
}