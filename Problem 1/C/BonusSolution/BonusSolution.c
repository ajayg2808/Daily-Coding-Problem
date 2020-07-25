
/**
 * @author AJAY G.
 */
 
#include <stdio.h>
#include "Set.h"

int compare(const void *num1, const void *num2)
{
	int *intNum1 = (int *)num1;
	int *intNum2 = (int *)num2;
	return (*intNum1) - (*intNum2);
}

void print(const void *value)
{
	int *intValue = (int *)value;
	printf("%d", *intValue);
}

int main()
{
	Set * set = NULL;
	int i, j, k, n, found = 0 ;
	int *arr;								// Pointer for 'int' values
	
	printf("\nNumber of elements(?) : ");
	scanf("%d",&n);
	
	arr = (int *)malloc(sizeof(int) * n);	// Allocate spcae for 'n' 'int' elements
	// It will work for any numver of elements
	
	printf("\nEnter array %d elemnts : ", n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("\nEnter value of K : ");
	scanf("%d",&k);
	
	for(i=0;i<n;i++)
	{
		if(contains(set, &arr[i], NULL))
		{
			found = 1;
			break;
		}
		int *temp = (int * )malloc(sizeof(int));
		*temp = k -arr[i];
		set = add(set, temp, NULL);
	}
	
	if(found)								// Print result according to flag
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
	
	clear(set);

	return 0;
}
