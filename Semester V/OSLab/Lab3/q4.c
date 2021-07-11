#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("Error\n");
        exit(-1);
    }
    if (pid == 0)
    {
        exit(0);
        printf("Child Process\n");
    }
    else
    {
        sleep(2);
        printf("Parent Process\n");
    }
    return 0;
}