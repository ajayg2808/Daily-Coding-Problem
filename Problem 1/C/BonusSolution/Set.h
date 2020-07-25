
/**
 * @author AJAY G.
 */
 
#include <stdio.h>
#include "Tree/AVL_Tree.h"

typedef struct Node Set;
typedef unsigned int a_size;

// Default compare function for integer data
int intCompare(const void *num1, const void *num2)
{
    int *intNum1 = (int *)num1;
    int *intNum2 = (int *)num2;
    return (*intNum1) - (*intNum2);
}

// Create empty set
Set *createEmptySet()
{
    return NULL;
}

// Create set with provided array
Set *createSet(void *array[], const a_size size, int (*compare)(const void *, const void *))
{
    int i;
    Set *set = createEmptySet();
    if (compare == NULL)
    {
        compare = &intCompare;
    }
    for (i = 0; i < size; i++)
    {
        set = insertNode(set, array[i], compare);
    }

    return set;
}

// Add Element To Set
Set * add(Set *set, void *dataPtr, int (*compare)(const void *, const void *))
{
    if (compare == NULL)
    {
        compare = &intCompare;
    }
    if (!searchNode(set, dataPtr, compare))
    {
        set = insertNode(set, dataPtr, compare);
    }

    return set;
}

// Add All Element From Array To Set
Set * addAll(Set *set, void *array[], const a_size size, int (*compare)(const void *, const void *))
{
    int i;
    if (compare == NULL)
    {
        compare = &intCompare;
    }
    for (i = 0; i < size; i++)
    {
        set = insertNode(set, array[i], compare);
    }

    return set;
}

// Clear the Set (Make Set Empty)
void clear(Set *set)
{
    deleteTree(set);
}

// Check Set Contains Given Element OR Not
int contains(Set *set, void *dataPtr, int (*compare)(const void *, const void *))
{
    if (compare == NULL)
    {
        compare = &intCompare;
    }
    return searchNode(set, dataPtr, compare);
}

// Check Set Contains Given All Elements OR Not
int containsAll(Set *set, void *array[], const a_size size, int (*compare)(const void *, const void *))
{
    int i;
    if (compare == NULL)
    {
        compare = &intCompare;
    }
    for (i = 0; i < size; i++)
    {
        if (!searchNode(set, array[i], compare))
            return FALSE;
    }

    return TRUE;
}

// Check If Set is Empty OR Not
int isEmpty(Set * set)
{
    if(countTotalNodes(set) == 0)
        return TRUE;
    
    return FALSE;
}

// Remove Element From Set
Set * sRemove(Set * set, void *dataPtr, int (*compare)(const void *, const void *))
{
    if (compare == NULL)
    {
        compare = &intCompare;
    }
    
    if (searchNode(set, dataPtr, compare))
    {
        set = deleteNode(set, dataPtr, compare);
    }

    return set;
}

// Remove All Given Element From Set
Set * removeAll(Set *set, void *array[], const a_size size, int (*compare)(const void *, const void *))
{
    int i;
    if (compare == NULL)
    {
        compare = &intCompare;
    }
    for (i = 0; i < size; i++)
    {
        set = deleteNode(set, array[i], compare);
    }

    return set;
}

// Size Of Set
int size(Set * set)
{
    return countTotalNodes(set);
}

// Return Set As Array
int setToArray(Set * set, int *array[])
{
    return treeToArray(set, array, 0);
}
