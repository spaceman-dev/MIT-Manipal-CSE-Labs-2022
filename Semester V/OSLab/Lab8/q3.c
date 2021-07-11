#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
void *prime(void *arr)
{
    int n1 = *((int *)arr);
    int n2 = *(((int *)(arr + sizeof(int))));
    printf("The Prime Numbers between '%d' and '%d' are: \n", n1, n2);
    for (int i = n1; i <= n2; i++)
    {
        int flag = 0;
        for (int j = 2; j <= i / 2; j++)
        {
            if ((i % j) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            printf("%d ", i);
    }
    printf("\n");
}
int main()
{
    int arr[2];
    printf("Enter the Lower Limit: \n");
    scanf("%d", &arr[0]);
    printf("Enter the Upper Limit: \n");
    scanf("%d", &arr[1]);
    pthread_t thread;
    pthread_create(&thread, 0, &prime, (void *)arr);
    pthread_join(thread, NULL);
}