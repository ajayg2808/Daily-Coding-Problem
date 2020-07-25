#include <stdio.h>
int main()
{
	int *arr, *leftProd, *rightProd, i, n;

	printf("\n Number of elements(?) : ");
	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int) * n);
	leftProd = (int *)malloc(sizeof(int) * n);
	rightProd = (int *)malloc(sizeof(int) * n);

	printf("\n Enter array %d elemnts : ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", (arr + i));
	}

	leftProd[0] = 1;

	for (i = 1; i < n; i++)
	{
		leftProd[i] = arr[i - 1] * leftProd[i - 1];
	}
	rightProd[n - 1] = 1;
	for (i = n - 2; i >= 0; i--)
	{
		rightProd[i] = arr[i + 1] * rightProd[i + 1];
	}

	printf("\n Product Array : ");
	for (i = 0; i < n; i++)
	{
		printf("%d  ", leftProd[i] * rightProd[i]);
	}

	free(arr);
	free(leftProd);
	free(rightProd);
	return 0;
}
