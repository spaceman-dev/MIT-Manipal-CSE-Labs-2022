#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if(!(dp = opendir(dir)))
    {
        fprintf(stderr, "Cannot Open Directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while(entry = readdir(dp))
    {
        lstat(entry->d_name, &statbuf);
        if(S_ISDIR(statbuf.st_mode))
        {
            // Found a directory ignore . and ..
            if(strcmp(".", entry->d_name) == 0 ||strcmp("..", entry->d_name) == 0)
                continue;
            printf("%*s%s/\n",depth, "", entry->d_name);
            printdir(entry->d_name, depth+4); // Recurse at a new indent level
        }
        else
            printf("%*s%s\n", depth, "", entry->d_name);
    }
    chdir("..");
    closedir(dp);
}
int main()
{
    printf("Scaning current Directory: \n");
    printdir(".", 0);
    printf("Done\n");
    exit(0);
}