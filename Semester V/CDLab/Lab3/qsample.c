#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char c, buf[10];
    FILE *fp = fopen("input.c", "r");
    FILE *fo = fopen("output.txt", "w+");
    c = fgetc(fp);
    if (!fp || !fo)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    while (c != EOF)
    {
        int i = 0;
        buf[0] = '\0';
        if (c == '=')
        {
            buf[i++] = c;
            c = fgetc(fp);
            if (c == '=')
            {
                buf[i++] = c;
                buf[i] = '\0';
                fprintf(fo, "\n Relational operator : %s", buf);
            }
            else
                {
                    buf[i] = '\0';
                    fprintf(fo, "\n Assignment operator: %s", buf);
                }
        }
        else
        {
            if (c == '<' || c == '>' || c == '!')
            {
                buf[i++] = c;
                c = fgetc(fp);
                if (c == '=')
                    buf[i++] = c;
                buf[i] = '\0';
                fprintf(fo, "\n Relational operator : %s", buf);
            }
            else
                buf[i] = '\0';
        }
        c = fgetc(fp);
    }
}