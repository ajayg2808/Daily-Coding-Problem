#include <stdio.h>
#include <stdlib.h>

// This function will always work correct for local system
// Chances of working fine on online compiler are less
// As because of Dynamic memory allocation
int firstMissingPositive(int *nums, int numsSize)
{

    int i;
    if (numsSize == 0) // Array size is 0
        return 1;

    // As we need to find positive missing i.e {1....n}
    // and array has index from 0 i.e {0...n-1}
    // Example
    // Array  = [1, 2]
    // Size	  = 2
    // MissindNo = 3		i.e {size + 1} for such cases we added 0 as extra element in array
    // i.e extra element is used for condition where array has all the element upto array size

    nums = (int *)realloc(nums, numsSize + 1);
    nums[numsSize] = 0;
    numsSize++;

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] <= 0 || nums[i] >= numsSize) // Since we want the positive no only
        {                                        // We will replace negative no with 0
            nums[i] = 0;                         // and also no >= arraySize since missing no must be smaller than or equal to array-size
        }                                        // (we have incremented array-size by 1
    }

    //displayArray(nums, numsSize);

    for (i = 0; i < numsSize; i++) // Uses HASH like functionality as all remained array elements are less than array size
    {
        nums[nums[i] % numsSize] += numsSize;
    }

    //displayArray(nums, numsSize);

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] / numsSize == 0) // First array index with element less than aaray size is the missing number(index)
            return i;
    }

    //displayArray(nums, numsSize);

    return numsSize; // All element in array are in sequence and no missing number in that so next number (array size)
                     // Example 			[1, 2, 3, 4, 5] 		size = 5
                     // increased array 	[1, 2, 3, 4, 5, 0]		size = 6
                     // Missing number = 6 i.e. increased array size
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
