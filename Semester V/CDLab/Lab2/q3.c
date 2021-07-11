#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const char *Keywords[] = {"const", "char", "int","return", "for", "while", "do", "switch", "if", "else","case", "breaj"};
int is_keyword(const char *str)
{
    for(int i = 0 ; i < sizeof(Keywords) / sizeof(char *) ; i++)
    {
        if(strcmp(str, Keywords[i]) == 0)
            return 1;
    }
     return 0;
}
void strtoupper(char *str, const int l)
{
    for(int i = 0 ; i < l ; i++)
        str[i] = toupper(str[i]);
}
enum
{
    INSIDE_WORD,
    OUTSIDE_WORD
};
int main()
{
    FILE *fa;
    int line = 1, col = 1, j = 0;
    char c, buffers[1024];
    fa = fopen("input.c", "r");
    if(fa == NULL)
    {
        perror("Cant Open File!\n");
        return 1;
    }
    int state = OUTSIDE_WORD;
    printf("Keywords : \n");
    while((c = fgetc(fa)) != EOF)
    {
        switch(state)
        {
            case INSIDE_WORD:
                if(isalpha(c))
                    buffers[j++] = c;
                else
                {
                    buffers[j] = '\0';
                    if(is_keyword(buffers))
                    {
                        strtoupper(buffers, j);
                        printf("%s : at (%d , %d)\n", buffers, line, col - j);
                    }
                    j = 0;
                    state = OUTSIDE_WORD;
               }
                break;
            case OUTSIDE_WORD:
                if(isalpha(c))
                {
                    buffers[j++] = c;
                    state = INSIDE_WORD;
               }
                break;
        }
        if(c == '\n')
        {
            line++;
            col = 1;
        }
        else
            col++;
    }
  fclose(fa);
}