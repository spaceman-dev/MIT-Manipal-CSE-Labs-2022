#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lex_analyzer.h"
#include "initialize.h"
FILE *f1;
struct token tkn;
void Program();
void declarations();
int data_type();
void identifier_list(struct token);
void assign_stat(struct token);
void invalid(struct token *tkn)
{
    printf("error at row: %d, col: %d for lexeme \" %s \" \n", tkn->row, tkn->col, tkn->lexeme);
    printf("-----------------ERROR!----------------\n");
    exit(0);
}
void valid()
{
    printf("----------------SUCCESS!---------------\n");
    exit(0);
}
void Program()
{
    tkn = getNextToken(f1);
    if (strcmp(tkn.lexeme, "main") == 0)
    {
        tkn = getNextToken(f1);
        if (strcmp(tkn.lexeme, "(") == 0)
        {
            tkn = getNextToken(f1);
            if (strcmp(tkn.lexeme, ")") == 0)
            {
                tkn = getNextToken(f1);
                if (strcmp(tkn.lexeme, "{") == 0)
                {
                    declarations();
                    tkn = getNextToken(f1);
                    if (strcmp(tkn.lexeme, "}") == 0)
                        return;
                    else
                        invalid(&tkn);
                }
                else
                    invalid(&tkn);
            }
            else
                invalid(&tkn);
        }
        else
            invalid(&tkn);
    }
    else
        invalid(&tkn);
}
void declarations()
{
    tkn = getNextToken(f1);
    if (data_type(tkn.lexeme))
    {
        tkn = getNextToken(f1);
        identifier_list(tkn);
        tkn = getNextToken(f1);
        if (strcmp(tkn.lexeme, ";") == 0)
            declarations();
        else
            invalid(&tkn);
    }
    else
        assign_stat(tkn);
}
int data_type(char *lx)
{

    if (strcmp(lx, "int") == 0 || strcmp(lx, "char") == 0)
        return 1;
    else
        return 0;
}
void identifier_list(struct token tkn)
{
    struct token tkn2;
    tkn2 = tkn;
    if (strcmp(tkn2.type, "identifier") == 0)
    {
        tkn2 = getNextToken(f1);
        if (strcmp(tkn2.lexeme, ",") == 0)
        {
            tkn2 = getNextToken(f1);
            identifier_list(tkn);
        }
        else if (strcmp(tkn2.lexeme, ";") == 0)
        {
            fseek(f1, -1, SEEK_CUR);
            return;
        }
        else
            invalid(&tkn2);
    }
}
void assign_stat(struct token tkn)
{
    struct token tkn2;
    if (strcmp(tkn.type, "identifier") == 0)
    {
        tkn2 = getNextToken(f1);
        if (strcmp(tkn2.lexeme, "=") == 0)
        {
            tkn2 = getNextToken(f1);
            if (strcmp(tkn2.type, "number") == 0 || strcmp(tkn2.type, "identifier"))
            {
                tkn2 = getNextToken(f1);
                if (strcmp(tkn2.lexeme, ";") == 0)
                    return;
                else
                    invalid(&tkn);
            }
            else
                invalid(&tkn);
        }
        else
            invalid(&tkn);
    }
}
int main()
{
    f1 = fopen("sample.c", "r");
    if (f1 == NULL)
    {
        printf("Error! File cannot be opened!\n");
        return 0;
    }
    struct sttable st[10][100];
    int flag = 0, i = 0, j = 0;
    int tabsz[10];
    char w[25];
    w[0] = '\0';
    Program();
    valid();
}