#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fa, *fb;
    int ca, cb;
    fa = fopen("input.c", "r");
    if(!fa)
    {
        printf("Cant Open File!\n");
        exit(0);
    }
    fb = fopen("output.c", "w");
    ca = getc(fa);
    while(ca != EOF)
    {
        if(ca == ' ')
        {
            putc(ca, fb);
            while(ca == ' ')
                ca = getc(fa);
        }
        if(ca == '/')
        {
            cb = getc(fb);
            if(cb == '/')
            {
                while(ca != '\n')
                    ca = getc(fa);
            }
            else if(cb == '*')
            {
                do
                {
                    while(ca != '*')
                        ca = getc(fa);
                    ca = getc(fa);
                } while(ca != '/');
            }
            else
            {
                putc(ca, fb);
                putc(cb, fb);
            }
        }
        else
            putc(ca, fb);
        ca = getc(fa);
    }
    fclose(fa);
    fclose(fb);
    return 0;
}