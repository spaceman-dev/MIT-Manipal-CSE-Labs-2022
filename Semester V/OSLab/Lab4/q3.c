#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Insufficient arguments\n");
        return;
    }
    char new_path[100] = "linkedinq3.txt";
    struct stat start;
    int ret1 = stat(argv[1], &start);
    printf("Number of hard links:%ld\n", start.st_nlink);
    system("ls");
    printf("Linking..\n");
    int ret2 = link(argv[1], new_path);
    struct stat intermediate;
    int ret3 = stat(argv[1], &intermediate);
    printf("Number of hard links:%ld\n", intermediate.st_nlink);
    printf("New path:%s\n", new_path);
    system("cat linkedinq3.txt");
    int ret4 = unlink(argv[1]);
    struct stat ending;
    int ret5 = stat(new_path, &ending);
    printf("Unlinking...\n");
    printf("Number of hard links after unlinking:%ld\n", ending.st_nlink);
    system("ls");
}