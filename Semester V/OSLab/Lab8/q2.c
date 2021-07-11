#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
void *thread_code(void *n)
{
    int sum = 0;
    int lim = *((int *)n);
    for (int i = 1; i <= lim; i++)
        sum += i;
    *((int *)n) = sum;
}
void main()
{
    int n, n1;
    printf("Enter The Number of Elements: \n");
    scanf("%d", &n);
    n1 = n;
    pthread_t thread;
    pthread_create(&thread, 0, &thread_code, (void *)&n);
    pthread_join(thread, NULL);
    printf("Sum of all non-negetive numbers from '1' to '%d' is: '%d'\n", n1, n);
}