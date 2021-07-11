#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
int main()
{
    int countline = 0, countc = 0;
    char c;
    FILE *fptr;
    fptr = fopen("input.txt", "r");
    if(!fptr)
    {
        printf("Cant Open File!\n");
        exit(0);
    }
    c = getc(fptr);
    while(c != EOF)
    { 
        if(c == '\n')
            countline++;
        else if(c != ' ' && c != '\n')
            countc++;
        c = getc(fptr);
     }
    if(countc > 0)
        countline++;
    printf("Total Number of Lines: %d\n", countline);
    printf("Total Number of Characters: %d\n", countc);
    return 0;
}