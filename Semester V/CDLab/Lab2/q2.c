#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *directives[] = {"#include", "#define", "#if"};
int is_directive(const char *str)
{
    for(int i = 0 ; i < sizeof(directives)/sizeof(char *); i++)
    {
        if(strncmp(str, directives[i], strlen(directives[i])) == 0)
            return 1;
    }
    return 0;
}
int main()
{
    char buffers[2048];
    FILE *fa, *fb;
    fa = fopen("input.c", "r");
    fb = fopen("output.c", "w");
    if(!fa || !fb)
    {
        perror("Cant Open File!\n");
        return 1;
    }
    while(fgets(buffers, 2048, fa))
    {
        if(!is_directive(buffers))
            fputs(buffers, fb);
    }
    fclose(fa);
    fclose(fb);
    fa = fopen("input.c", "w");
    fb = fopen("output.c", "r");
    char ch = getc(fb);
    while(ch != EOF)
    {
        putc(ch, fa);
        ch = getc(fb);
    } 
    fclose(fa);
    fclose(fb);  
}