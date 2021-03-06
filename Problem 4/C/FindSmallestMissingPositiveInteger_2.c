#include <stdio.h>
#include <stdlib.h>

// This function will always work fine on both online as well as local compiler
// Temp variable is used for extra element in array [see line no. 30]
// extra if....else used in for loop for temp variable
int firstMissingPositive(int *nums, int numsSize)
{

    int i;
    if (numsSize == 0)
        return 1;

    if (numsSize == 1)
    {
        if (nums[numsSize - 1] == 1)
            return 2;
        return 1;
    }

    // As we need to find positive missing i.e {1....n}
    // and array has index from 0 i.e {0...n-1}
    // Example
    // Array = [1, 2]
    // Size = 2
    // MissindNo = 3
    // i.e temp is used for condition where array has all the element upto array size
    // temp is an extra element for {arraySize + 1} missing no in above condition.

    int temp = 0;
    int n = numsSize + 1;

    // Since we want the positive no only
    // We will replace negative no with 0
    // and also no >= arraySize since missing no must be smaller than or equal to array-size
    // (we have incremented array-size by 1)
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] <= 0 || nums[i] >= n)
        {
            nums[i] = 0;
        }
    }

    // Uses HASH like functionality as all remained array elements are less than array size
    for (i = 0; i < n; i++)
    {
        int a, b;
        if (i == numsSize)
            a = temp;
        else
            a = nums[i];

        b = a % n;

        if (b == numsSize)
            temp += n;
        else
            nums[b] += n;
    }

    // First array index with element less than aaray size is the missing number(index)
    for (i = 0; i < n; i++)
    {
        if (i == numsSize)
        {
            if (temp / n == 0)
                return i;
        }
        else if (nums[i] / n == 0)
            return i;
    }

    return n;
}

int main()
{
    int i, result1, n, *arr;
    printf("\nEnter no of elements : ");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    printf("\nEnter %d array elements : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    result1 = firstMissingPositive(arr, n);

    printf("\nFirst missing positive integer : %d", result1);

    return 0;
}
