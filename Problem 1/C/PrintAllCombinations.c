#include<stdio.h>
#include<stdlib.h>

int main(){
	int i, j, k, n, found;
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
		for(j=i+1; j<n; j++)				// J=i+1 to avoid repetation. try giving 'j = 0' 
		{	
			/* Condition for 'j=0' to avoid addtion of same index element like arr[i=0] + arr[j=0]
			if(i==j)
				continue;
				*/
				
			if((arr[i]+arr[j]) == k)		// Check for addition
			{
				// to print all such combinations
				printf("\n%d + %d = %d", arr[i], arr[j], k);
			}
		}
	}
}
