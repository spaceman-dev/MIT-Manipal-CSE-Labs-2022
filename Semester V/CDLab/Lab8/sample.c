#include <stdio.h>
#include <stdbool.h>
int sum(int a, int b)
{
    int s = a + b;
    return s;
}
bool search(int *arr, int key)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == key)
            return true;

        else
            return false;
    }
}
main()
{
    int a[20], n, res;
    printf("Enter the Array Elements: \n");
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: \n");
    scanf("%d", &n);
    res = sum(a, n);
    printf("%d", search(a, res));
}