#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int count = 0;
int sumweights[100];
int sumvalues[100];
int k = 0;
//char totalitems[100][100];
void knapsack1(int *items, int * values, int * weights, int l, int cap)
{
	if(sumweights[k] > cap)
		return;
	sumweights[k] = sumweights[k] + (weights[0]);
	sumvalues[k] = sumvalues[k] + (values[0]);
	//totalitems[k] = totalitems[k] +" "+items[0];
	knapsack1(items+1, values+1, weights+1, l, cap);
}
void knapsack2(int *items, int *values, int *weights, int l, int cap)
{
	if(count < l)
	{
		knapsack1(items, values, weights, l, cap);
		count++;
		k++;
		knapsack2(items +1, values +1, weights+1, l, cap);
	}
	else
		return;
}
void main()
{
	int l, cap;
	printf("Enter Number of Items : \n");
	scanf("%d", &l);
	int values[l];
	int items[l];
	int weights[l];
	printf("Enter Maximum Capacity : \n");
	scanf("%d", &cap);
	printf("Enter Items : \n");
	for(int i = 0 ; i < l ; i++)
		scanf("%d", &items[i]);
	printf("Enter Values : \n");
	for(int i = 0 ; i < l ; i++)
		scanf("%d", &values[i]);
	printf("Enter Weights : \n");
	for(int i = 0 ; i < l ; i++)
		scanf("%d", &weights[i]);
	for(int i = 0 ; i < 100 ; i++)
	{
		sumweights[i] = 0;
		sumvalues[i] = 0;
		//totalitems[i] = "";
	}
	knapsack2(items, values, weights, l, cap);
	int max = sumvalues[0];
	char maxstr[100];
	for(int i = 0 ; i < k ; i++)
	{
		if(max < sumvalues[i])
		{
			max = sumvalues[i];
			//maxstr = totalitems[i];
		}
	}
	printf("Maximum Value is : %d\n", max);
	//printf("Maximum Items are : %s\n", maxstr);
}