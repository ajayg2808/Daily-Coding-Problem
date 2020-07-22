#include<stdio.h>

int main(){
	int i, j, k, n, found;
	int arr[20];	// Work only for 20 elements.
	printf("\nNumber of elements(?) : ");
	scanf("%d",&n);
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
