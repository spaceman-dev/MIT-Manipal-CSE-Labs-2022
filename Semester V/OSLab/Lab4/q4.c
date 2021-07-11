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
    char new_path[100] = "linkedinq4.txt";
    struct stat start;
    int ret1 = stat(argv[1], &start);
    system("ls");
    printf("Linking..\n");
    int ret2 = symlink(argv[1], new_path);
    struct stat intermediate;
    int ret3 = stat(argv[1], &intermediate);
    printf("New path:%s\n", new_path);
    system("ls");
    int ret4 = unlink(argv[1]);
    struct stat ending;
    int ret5 = stat(new_path, &ending);
    printf("Unlinking...\n");
    system("ls");
}