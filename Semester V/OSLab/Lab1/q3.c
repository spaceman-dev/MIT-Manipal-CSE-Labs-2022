#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
// extern int errno;
int main()
{
    int a = 100;
    float b = 99.99;
    char c = 'A';
    char s[] = "This is a string";
    printf(" a = %d\n b = %f\n c = %c\n s = %s\n hexadecimal for a = %x\n", a, b, c, s, a);
    errno = EPERM;
    printf(" Error Access Errno: %m\n");
}