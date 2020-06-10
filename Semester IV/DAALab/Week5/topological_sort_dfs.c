#include <stdio.h>
#include <stdlib.h>
int arr[100][100], visit[100], n, stack[100], t = 0;
void dfs(int v)
{
visit[v] = 1;
for(int i = 0; i<n; i++)
{
if(arr[v][i] && !visit[i])
    dfs(i);
}
stack[t++] = v;
}
void printS()
{
for(int i = n-1; i>=0; i--)
    printf("%d ", stack[i]);
printf("\n");
}
void main()
{
printf("Enter the Number of Vertices : \n");
scanf("%d", &n);
printf("Enter the Matrix : \n");
for(int i = 0; i<n; i++)
{
for(int j = 0; j<n; j++)
    scanf("%d", &arr[i][j]);
}
for(int i = 0; i<n; i++)
{
if(!visit[i])
    dfs(i);
}
printf("The Topological Sort Order is :\n");
printS();
}