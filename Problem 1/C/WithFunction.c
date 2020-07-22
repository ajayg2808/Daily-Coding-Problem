#include<stdio.h>
#include<stdlib.h>

int checkSumPointe(int * arr, int k, int n);				// function declaration
		
int checkSumWithoutPointer(int arr[], int k, int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1; j<n; j++)
		{	
			if((arr[i]+arr[j]) == k)		// Check for addition
			{
				return 1;					// If found stop there only
			}
		}
	}
	return 0;
}
int main(){
	int i, k, n, found;
	int arr1[50], *arr2;								// int array and pointer for 'int' values
	
	printf("\nNumber of elements(?) : ");
	scanf("%d",&n);
	
	arr2 = (int *)malloc(sizeof(int) * n);	// Allocate spcae for 'n' 'int' elements
	// It will work for any numver of elements
	
	printf("\nEnter array %d elemnts : ", n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr2[i]);
		arr1[i] = arr2[i];
	}
	
	printf("\nEnter value of K : ");
	scanf("%d",&k);
	
	found = checkSumPointer(arr2, k, n);
	printf("\nOutput with pointer : ");
	if(found)								// Print result according to flag
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
	
	printf("\nOutput without pointer : ");
	if(checkSumWithoutPointer(arr1, k, n))
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
}

int checkSumPointer(int * arr, int k, int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=i+1; j<n; j++)
		{	
			if((*(arr+i) + *(arr+j)) == k)		// Check for addition
			{
				return 1;					// If found stop there only
			}
		}
	}
	return 0;
}
