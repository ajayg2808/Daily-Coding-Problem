#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, *arr, n;
    double product = 1;

    printf("\n Number of elements(?) : ");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    printf("\n Enter array %d elemnts : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }

    for (i = 0; i < n; i++)
    {
        product *= arr[i];
    }
	
    printf("\n Product Array : ");
    for(i = 0; i<n; i++ )
    {
        printf("%d  ", (int)(product/arr[i]));
    }

    free(arr);
    return 0;
}
