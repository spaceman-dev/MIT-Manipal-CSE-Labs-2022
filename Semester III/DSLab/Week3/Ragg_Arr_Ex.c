#include <stdio.h>
#include <stdlib.h>
int main()
{
int rowNum,colNum,i,j;
int **table;
printf("Enter The Number of Rows : \n");
scanf("%d",&rowNum);
table = (int **)calloc(rowNum+1,sizeof(int *));
for(i = 0 ; i < rowNum ; i++)
{
printf("Enter The Size of the '%d' Row : ",i+1);
scanf("%d",&colNum);
table[i] = (int *)calloc(colNum+1,sizeof(int));
printf("\nEnter the '%d' Row Elements : \n",i+1);
for(j = 1 ; j <= colNum ; j++)
    scanf("%d",&table[i][j]);
table[i][0] = colNum;
printf("Size of Row Number [%d] = %d\n",i+1,table[i][0]);
}
for(i = 0 ; i < rowNum ; i++)
{
printf("Displaying the '%d' Row Elements :\n",i+1);
for(j = 0 ; j <= *table[i] ; j++)
    printf("%d ",table[i][j]);
printf("\n");
}
for(i = 0 ; i < rowNum ; i++)
    free(table[i]);
free(table);
}