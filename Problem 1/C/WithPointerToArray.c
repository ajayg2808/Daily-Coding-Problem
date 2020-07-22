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
		for(j=i+1; j<n; j++)
		{	
			if((arr[i]+arr[j]) == k)		// Check for addition
			{
				found = 1;					// If found stop there only
				break;
			}
		}
		if(found)							// Exit from both loop if found
			break;
	}
	if(found)								// Print result according to flag
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
}
