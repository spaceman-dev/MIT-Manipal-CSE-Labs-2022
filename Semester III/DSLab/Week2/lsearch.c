#include<stdio.h>
#include<stdlib.h>

int* Lsearch(int *arr,int n,int f)
{
int i;
for(i=0;i<n;i++)
{if (arr[i]==f){
printf("The value %d is found at position %d\n",f,i+1);
}
}
return (arr+2);
}
int main()
{
	int *a;
	int i,n,f;
	printf("Enter the value of n \n");
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
		scanf("%d",(a+i));
	printf("Enter the element to be found\n");
	scanf("%d",&f);
	printf("%d",*(Lsearch(a,n,f)));
	free(a);

	return 0;	
}

