#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<dirent.h>
int main()
{
    DIR * dp;
    struct dirent * entry;
    struct stat statbuf;
    if(!(dp = opendir(".")))
    {
        printf("Cannot open directory \n");
        return 0;
    }
    chdir(".");
    while(entry = readdir(dp))
    {
        lstat(entry->d_name, &statbuf);
        if(!S_ISDIR(statbuf.st_mode))
        {
            printf("%s \t \t", entry->d_name);
            printf((S_ISDIR(statbuf.st_mode)) ? "d" : "-");
            printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
            printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
            printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
            printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
            printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
            printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
            printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
            printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
            printf((statbuf.st_mode & S_IXOTH) ? "x" : "-");
            printf("\n");
        }
  }
}