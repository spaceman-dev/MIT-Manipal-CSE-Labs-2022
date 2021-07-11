#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
void *thread_code(void *param)
{
    int n = *((int *)param);
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
        arr[i] = arr[i - 2] + arr[i - 1];
    int *res = (int *)calloc(n, sizeof(int));
    memcpy(res, arr, sizeof(int) * n);
    return res;
}
void main()
{
    int n;
    printf("Enter the Number of Terms: \n");
    scanf("%d", &n);
    void *arr;
    pthread_t thread;
    pthread_create(&thread, 0, &thread_code, (void *)&n);
    printf("Thread created!\n");
    pthread_join(thread, &arr);
    int *arr2 = arr;
    for (int i = 0; i < n; i++)
        printf("%d ", (int)arr2[i]);
    printf("\n");
}