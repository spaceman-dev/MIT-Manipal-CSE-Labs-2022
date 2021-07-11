#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    struct stat sb;
    int ret;
    if (argc < 2)
    {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }
    ret = stat(argv[1], &sb);
    if (ret)
    {
        perror("stat");
        return 1;
    }
    printf("Inode number for %s is: %ld\n", argv[1], sb.st_ino);
    return 0;
}