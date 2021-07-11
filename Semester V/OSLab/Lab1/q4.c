#include<stdio.h>
#include <unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{ 
    char c;
    int input, output;
    if(argc != 3)
    {
        printf("Insufficient Arguments\n");
        exit(1);
    }
    input = open(argv[1], O_RDWR);
    output = open(argv[2], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    if(input == -1 || output == -1)
    {
        printf("File not found\n");
        exit(1);
    }
    while(read(input, &c, 1) == 1)
        write(output, &c, 1);
    printf("Copy Success!\n");
    exit(0);
}