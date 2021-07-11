#include <stdio.h>
#include <stdlib.h>
int main()
{
    int flag = 0;
    char c;
    FILE *fa, *fb;
    fa = fopen("input.c", "r");
    fb = fopen("output.txt", "w");
    if(!fa || !fb)
    {
        perror("Cant Open File!\n");
        return 1;
    } 
    while(1)
    {
        c = fgetc(fa);
        if(c == EOF)
            break;
        else if(!flag && (c == ' ' || c == '\t'))
        {
            fputc(' ', fb);
            flag = 1;
        }
        else if(!(c == ' ' || c == '\t'))
        {
            flag = 0;
            fputc(c, fb);
        }
    }
    fclose(fa);
    fclose(fb);
}