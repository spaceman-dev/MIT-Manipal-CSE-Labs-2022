#include "lex_analyzer.h"
void program();
void declarations();
void datatype();
void idList();
void idListprime();
void idListprimePrime();
void stmtList();
void stmt();
void assignStat();
void expn();
void eprime();
void simpleExpn();
void seprime();
void term();
void tprime();
void factor();
void relop();
void addop();
void mulop();
void decStat();
void dPrime();
void loopStat();
struct token tkn;
FILE *f1;
int main()
{
    FILE *fa, *fb;
    int ca, cb;
    fa = fopen("sample.c", "r");
    if (fa == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    fb = fopen("output.c", "w+");
    ca = getc(fa);
    while (ca != EOF)
    {
        if (ca == ' ')
        {
            putc(ca, fb);
            while (ca == ' ')
                ca = getc(fa);
        }
        if (ca == '/')
        {
            cb = getc(fa);
            if (cb == '/')
            {
                while (ca != '\n')
                    ca = getc(fa);
            }
            else if (cb == '*')
            {
                do
                {
                    while (ca != '*')
                        ca = getc(fa);
                    ca = getc(fa);
                } while (ca != '/');
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
    fa = fopen("output.c", "r");
    if (fa == NULL)
    {
        printf("Cannot open file");
        return 0;
    }
    fb = fopen("temp.c", "w+");
    ca = getc(fa);
    while (ca != EOF)
    {
        if (ca == '"')
        {
            putc(ca, fb);
            ca = getc(fa);
            while (ca != '"')
            {
                putc(ca, fb);
                ca = getc(fa);
            }
        }
        else if (ca == '#')
        {
            while (ca != '\n')
                ca = getc(fa);
        }
        putc(ca, fb);
        ca = getc(fa);
    }
    fclose(fa);
    fclose(fb);
    fa = fopen("temp.c", "r");
    fb = fopen("output.c", "w");
    ca = getc(fa);
    while (ca != EOF)
    {
        putc(ca, fb);
        ca = getc(fa);
    }
    fclose(fa);
    fclose(fb);
    remove("temp.c");
    f1 = fopen("output.c", "r");
    if (f1 == NULL)
    {
        printf("Error! File cannot be opened!\n");
        return 0;
    }
    while ((tkn = getNextToken(f1)).row != -1)
    {
        if (strcmp(tkn.lexeme, "main") == 0)
        {
            program();
            break;
        }
    }
    fclose(f1);
}
void program()
{
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
                    tkn = getNextToken(f1);
                    declarations();
                    stmtList();
                    if (strcmp(tkn.lexeme, "}") == 0)
                    {
                        printf("Compilation successful!!\n");
                        return;
                    }
                    else
                    {
                        printf("ERROR: missing \"}\" at row=%d col=%d\n", tkn.row, tkn.col);
                        exit(1);
                    }
                }
                else
                {
                    printf("ERROR: missing \"{\" at row=%d col=%d\n", tkn.row, tkn.col);
                    exit(1);
                }
            }
            else
            {
                printf("ERROR: missing \")\" at row=%d col=%d\n", tkn.row, tkn.col);
                exit(1);
            }
        }
        else
        {
            printf("ERROR: missing \"(\" at row=%d col=%d\n", tkn.row, tkn.col);
            exit(1);
        }
    }
    else
    {
        printf("ERROR: missing \"main\" at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}
void declarations()
{
    if (isdtype(tkn.lexeme) == 0)
        return;
    datatype();
    idList();
    if (strcmp(tkn.lexeme, ";") == 0)
    {
        tkn = getNextToken(f1);
        declarations();
    }
    else
    {
        printf("ERROR: missing \";\" at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}
void datatype()
{
    if (strcmp(tkn.lexeme, "int") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else if (strcmp(tkn.lexeme, "char") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else
    {
        printf("ERROR: missing datatype(int or char) at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}

void idList()
{
    if (strcmp(tkn.type, "IDENTIFIER") == 0)
    {
        tkn = getNextToken(f1);
        idListprime();
    }
    else
    {
        printf("ERROR: missing IDENTIFIER at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}
void idListprime()
{
    if (strcmp(tkn.lexeme, ",") == 0)
    {
        tkn = getNextToken(f1);
        idList();
    }
    else if (strcmp(tkn.lexeme, "[") == 0)
    {
        tkn = getNextToken(f1);
        if (strcmp(tkn.type, "NUMBER") == 0)
        {
            tkn = getNextToken(f1);
            if (strcmp(tkn.lexeme, "]") == 0)
            {
                tkn = getNextToken(f1);
                idListprimePrime();
            }
            else
            {
                printf("ERROR: missing \"]\" at row=%d col=%d\n", tkn.row, tkn.col);
                exit(1);
            }
        }
        else
        {
            printf("ERROR: missing NUMBER at row=%d col=%d\n", tkn.row, tkn.col);
            exit(1);
        }
    }
}
void idListprimePrime()
{
    if (strcmp(tkn.lexeme, ",") == 0)
    {
        tkn = getNextToken(f1);
        idList();
    }
    else
        return;
}
void stmtList()
{
    if (strcmp(tkn.type, "IDENTIFIER") == 0 || strcmp(tkn.lexeme, "if") == 0 || strcmp(tkn.lexeme, "for") == 0 || strcmp(tkn.lexeme, "while") == 0)
    {
        stmt();
        stmtList();
    }
    return;
}
void stmt()
{
    if (strcmp(tkn.type, "IDENTIFIER") == 0)
    {
        assignStat();
        if (strcmp(tkn.lexeme, ";") == 0)
        {
            tkn = getNextToken(f1);
            return;
        }
        else
        {
            printf("ERROR: missing \";\" at row=%d col=%d\n", tkn.row, tkn.col);
            exit(1);
        }
    }
    else if (strcmp(tkn.lexeme, "if") == 0)
        decStat();
    else if ((strcmp(tkn.lexeme, "while") == 0) || (strcmp(tkn.lexeme, "for") == 0))
        loopStat();
    else
    {
        printf("%d.%d : Expected \" statement \"\n", tkn.row, tkn.col);
        exit(0);
    }
}
void assignStat()
{
    if (strcmp(tkn.type, "IDENTIFIER") == 0)
    {
        tkn = getNextToken(f1);
        if (strcmp(tkn.lexeme, "=") == 0)
        {
            tkn = getNextToken(f1);
            expn();
        }
        else
        {
            printf("ERROR: missing \"=\" at row=%d col=%d\n", tkn.row, tkn.col);
            exit(1);
        }
    }
    else
    {
        printf("ERROR: missing IDENTIFIER at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}
void expn()
{
    simpleExpn();
    eprime();
}
void eprime()
{
    if (strcmp(tkn.type, "RELATIONALOPERATOR") != 0)
        return;
    relop();
    simpleExpn();
}
void simpleExpn()
{
    term();
    seprime();
}
void seprime()
{
    if ((strcmp(tkn.lexeme, "+") != 0) && (strcmp(tkn.lexeme, "-") != 0))
        return;
    addop();
    term();
    seprime();
}
void term()
{
    factor();
    tprime();
}
void tprime()
{
    if ((strcmp(tkn.lexeme, "*") != 0) && (strcmp(tkn.lexeme, "/") != 0) && (strcmp(tkn.lexeme, "%") != 0))
        return;
    mulop();
    factor();
    tprime();
}
void factor()
{
    if (strcmp(tkn.type, "IDENTIFIER") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else if (strcmp(tkn.type, "NUMBER") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else
    {
        printf("ERROR: Expected IDENTIFIER or NUMBER at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}
void relop()
{
    if (strcmp(tkn.lexeme, "==") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else if (strcmp(tkn.lexeme, "!=") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else if (strcmp(tkn.lexeme, "<=") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else if (strcmp(tkn.lexeme, ">=") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else if (strcmp(tkn.lexeme, "<") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else if (strcmp(tkn.lexeme, ">") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else
    {
        printf("ERROR: Expected RELATIONAL OPERATOR or NUMBER at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}
void addop()
{
    if (strcmp(tkn.lexeme, "+") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else if (strcmp(tkn.lexeme, "-") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else
    {
        printf("ERROR: Expected \"+\" or \"-\" at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}
void mulop()
{
    if (strcmp(tkn.lexeme, "*") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else if (strcmp(tkn.lexeme, "/") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else if (strcmp(tkn.lexeme, "*") == 0)
    {
        tkn = getNextToken(f1);
        return;
    }
    else
    {
        printf("ERROR: Expected \"*\" or \"/\" or \"%%\" at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}
void decStat()
{
    if (strcmp(tkn.lexeme, "if") == 0)
    {
        tkn = getNextToken(f1);
        if (strcmp(tkn.lexeme, "(") == 0)
        {
            tkn = getNextToken(f1);
            expn();
            if (strcmp(tkn.lexeme, ")") == 0)
            {
                tkn = getNextToken(f1);
                if (strcmp(tkn.lexeme, "{") == 0)
                {
                    tkn = getNextToken(f1);
                    stmtList();
                    if (strcmp(tkn.lexeme, "}") == 0)
                    {
                        tkn = getNextToken(f1);
                        dPrime();
                        return;
                    }
                    else
                    {
                        printf("ERROR: missing \"}\" at row=%d col=%d\n", tkn.row, tkn.col);
                        exit(1);
                    }
                }
                else
                {
                    printf("ERROR: missing \"{\" at row=%d col=%d\n", tkn.row, tkn.col);
                    exit(1);
                }
            }
            else
            {
                printf("ERROR: missing \")\" at row=%d col=%d\n", tkn.row, tkn.col);
                exit(1);
            }
        }
        else
        {
            printf("ERROR: missing \"(\" at row=%d col=%d\n", tkn.row, tkn.col);
            exit(1);
        }
    }
    else
    {
        printf("ERROR: missing \"keyword\" at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}
void dPrime()
{
    if (strcmp(tkn.lexeme, "else") == 0)
    {
        tkn = getNextToken(f1);
        if (strcmp(tkn.lexeme, "{") == 0)
        {
            tkn = getNextToken(f1);
            stmtList();
            if (strcmp(tkn.lexeme, "}") == 0)
            {
                tkn = getNextToken(f1);
                return;
            }
            else
            {
                printf("ERROR: missing \"}\" at row=%d col=%d\n", tkn.row, tkn.col);
                exit(1);
            }
        }
        else
        {
            printf("ERROR: missing \"{\" at row=%d col=%d\n", tkn.row, tkn.col);
            exit(1);
        }
    }
    else
        return;
}
void loopStat()
{
    if (strcmp(tkn.lexeme, "while") == 0)
    {
        tkn = getNextToken(f1);
        if (strcmp(tkn.lexeme, "(") == 0)
        {
            tkn = getNextToken(f1);
            expn();
            if (strcmp(tkn.lexeme, ")") == 0)
            {
                tkn = getNextToken(f1);
                if (strcmp(tkn.lexeme, "{") == 0)
                {
                    tkn = getNextToken(f1);
                    stmtList();
                    if (strcmp(tkn.lexeme, "}") == 0)
                    {
                        tkn = getNextToken(f1);
                        return;
                    }
                    else
                    {
                        printf("ERROR: missing \"}\" at row=%d col=%d\n", tkn.row, tkn.col);
                        exit(1);
                    }
                }
                else
                {
                    printf("ERROR: missing \"{\" at row=%d col=%d\n", tkn.row, tkn.col);
                    exit(1);
                }
            }
            else
            {
                printf("ERROR: missing \")\" at row=%d col=%d\n", tkn.row, tkn.col);
                exit(1);
            }
        }
        else
        {
            printf("ERROR: missing \"(\" at row=%d col=%d\n", tkn.row, tkn.col);
            exit(1);
        }
    }
    else if (strcmp(tkn.lexeme, "for") == 0)
    {
        tkn = getNextToken(f1);
        if (strcmp(tkn.lexeme, "(") == 0)
        {
            tkn = getNextToken(f1);
            assignStat();
            if (strcmp(tkn.lexeme, ";") == 0)
            {
                tkn = getNextToken(f1);
                expn();
                if (strcmp(tkn.lexeme, ";") == 0)
                {
                    tkn = getNextToken(f1);
                    assignStat();
                    if (strcmp(tkn.lexeme, ")") == 0)
                    {
                        tkn = getNextToken(f1);
                        if (strcmp(tkn.lexeme, "{") == 0)
                        {
                            tkn = getNextToken(f1);
                            stmtList();
                            if (strcmp(tkn.lexeme, "}") == 0)
                            {
                                tkn = getNextToken(f1);
                                return;
                            }
                            else
                            {
                                printf("ERROR: missing \"}\" at row=%d col=%d\n", tkn.row, tkn.col);
                                exit(1);
                            }
                        }
                        else
                        {
                            printf("ERROR: missing \"{\" at row=%d col=%d\n", tkn.row, tkn.col);
                            exit(1);
                        }
                    }
                    else
                    {
                        printf("ERROR: missing \")\" at row=%d col=%d\n", tkn.row, tkn.col);
                        exit(1);
                    }
                }
                else
                {
                    printf("ERROR: missing \";\" at row=%d col=%d\n", tkn.row, tkn.col);
                    exit(1);
                }
            }
            else
            {
                printf("ERROR: missing \";\" at row=%d col=%d\n", tkn.row, tkn.col);
                exit(1);
            }
        }
        else
        {
            printf("ERROR: missing \"(\" at row=%d col=%d\n", tkn.row, tkn.col);
            exit(1);
        }
    }
    else
    {
        printf("ERROR: missing \"keyword\" at row=%d col=%d\n", tkn.row, tkn.col);
        exit(1);
    }
}