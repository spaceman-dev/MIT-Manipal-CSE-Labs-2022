#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
void *even(void *brr)
{
    int *arr = (int *)brr;
    int size = arr[0];
    int sum = 0;
    for (int i = 1; i <= size; i++)
        if (arr[i] % 2 == 0)
            sum += arr[i];
    return (void *)sum;
}
void *odd(void *brr)
{
    int *arr = (int *)brr;
    int size = arr[0];
    int sum = 0;
    for (int i = 1; i <= size; i++)
        if (arr[i] % 2 != 0)
            sum += arr[i];
    return (void *)sum;
}
int main()
{
    int n, evenSum, oddSum;
    printf("Enter The Number of Elements of the Array: \n");
    scanf("%d", &n);
    int arr[n + 1];
    arr[0] = n;
    printf("Enter The Elements in the Array:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    pthread_t t1, t2;
    pthread_create(&t1, 0, &even, (void *)arr);
    pthread_create(&t2, 0, &odd, (void *)arr);
    pthread_join(t1, (void *)&evenSum);
    pthread_join(t2, (void *)&oddSum);
    printf("The Sum of Even Numbers of the Array is: %d\n", (int)evenSum);
    printf("The Sum of Odd Numbers of the Array is: %d\n", (int)oddSum);
}