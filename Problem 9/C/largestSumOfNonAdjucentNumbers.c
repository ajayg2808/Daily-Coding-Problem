#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int i, n;
    printf("\n Enter no of elements in array : ");
    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);

    printf("\n Enter %d array elements : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int prev = 0;
    int large = 0;
    for (i = 0; i < n; i++)
    {
        int p = prev;
        prev = large;
        large = max(large, p + arr[i]);
    }

    printf("\n Largest Sum : %d", large);
    return 0;
}