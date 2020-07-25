
/**
 * @author AJAY G.
 */
 
#include <stdlib.h>
#define COUNT 10
#define TRUE 1
#define FALSE 0

struct Node
{
	void *dataPtr;
	struct Node *left;
	struct Node *right;
	int height;
};

int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Get Height of Node
int getHeight(struct Node *ptr)
{
	if (ptr == NULL)
		return 0;
	return ptr->height;
}

// Get Balance Factor
int getBalanceFactor(struct Node *ptr)
{
	if (ptr == NULL)
		return 0;
	return getHeight(ptr->left) - getHeight(ptr->right);
}

// Create New Node
struct Node *createNode(void *dataPtr)
{
	struct Node *node = (struct Node *)
		malloc(sizeof(struct Node));
	node->dataPtr = (void *)dataPtr;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

// Return Node with minimum value
struct Node *getMinValueNode(struct Node *root)
{
	struct Node *current = root;

	while (current->left != NULL)
		current = current->left;

	return current;
}

// Return Node with maximum value
struct Node *getMaxValueNode(struct Node *root)
{
	struct Node *current = root;

	while (current->right != NULL)
		current = current->right;

	return current;
}

// 1. Right rotate
struct Node *rightRotate(struct Node *ptr)
{
	struct Node *ptrLeft = ptr->left;
	struct Node *pLRight = ptrLeft->right;

	ptrLeft->right = ptr;
	ptr->left = pLRight;

	ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;
	ptrLeft->height = max(getHeight(ptrLeft->left), getHeight(ptrLeft->right)) + 1;

	return ptrLeft;
}

// 2. Left rotate
struct Node *leftRotate(struct Node *ptr)
{
	struct Node *ptrRight = ptr->right;
	struct Node *pRLeft = ptrRight->left;

	ptrRight->left = ptr;
	ptr->right = pRLeft;

	ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;
	ptrRight->height = max(getHeight(ptrRight->left), getHeight(ptrRight->right)) + 1;

	return ptrRight;
}

// Insert Node Into AVL Tree
struct Node *insertNode(struct Node *root, void *dataPtr, int (*compare)(const void *, const void *))
{
	// Find the correct position to insertNode the node and insertNode it
	if (root == NULL)
	{
		return (createNode(dataPtr));
	}

	int compResult = (*compare)(dataPtr, root->dataPtr);

	if (compResult < 0)
	{
		root->left = insertNode(root->left, dataPtr, compare);
	}
	else if (compResult > 0)
	{
		root->right = insertNode(root->right, dataPtr, compare);
	}
	else
	{
		return root;
	}
	// Update the balance factor of each node and Balance the tree
	root->height = 1 + max(getHeight(root->left),
						   getHeight(root->right));

	int balance = getBalanceFactor(root);

	if (balance > 1 && (*compare)(dataPtr, root->left->dataPtr) < 0)
	{
		return rightRotate(root);
	}

	if (balance < -1 && (*compare)(dataPtr, root->right->dataPtr) > 0)
	{
		return leftRotate(root);
	}

	if (balance > 1 && (*compare)(dataPtr, root->left->dataPtr) > 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && (*compare)(dataPtr, root->right->dataPtr) < 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

// Delete Node with key from AVL Tree
struct Node *deleteNode(struct Node *root, void *dataPtr, int (*compare)(const void *, const void *))
{
	// Find the node and delete it
	if (root == NULL)
		return root;

	int compResult = (*compare)(dataPtr, root->dataPtr);

	if (compResult < 0)
	{
		root->left = deleteNode(root->left, dataPtr, compare);
	}
	else if (compResult > 0)
	{
		root->right = deleteNode(root->right, dataPtr, compare);
	}

	else
	{
		if ((root->left == NULL) || (root->right == NULL))
		{
			struct Node *temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				root = temp;
			}
			free(temp);
		}
		else
		{
			struct Node *temp = getMinValueNode(root->right);

			root->dataPtr = temp->dataPtr;

			root->right = deleteNode(root->right, temp->dataPtr, compare);
		}
	}

	if (root == NULL)
		return root;

	// Update the balance factor of each node and Balance the tree
	root->height = 1 + max(getHeight(root->left),
						   getHeight(root->right));

	int balance = getBalanceFactor(root);
	if (balance > 1 && getBalanceFactor(root->left) >= 0)
	{
		return rightRotate(root);
	}

	if (balance > 1 && getBalanceFactor(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && getBalanceFactor(root->right) <= 0)
	{
		return leftRotate(root);
	}

	if (balance < -1 && getBalanceFactor(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

// Check Node with given key value is present or not
int searchNode(struct Node *root, void *dataPtr, int (*compare)(const void *, const void *))
{
	if (root == NULL)
	{
		return FALSE;
	}

	if ((*compare)(dataPtr, root->dataPtr) < 0)
	{
		return searchNode(root->left, dataPtr, compare);
	}
	else if ((*compare)(dataPtr, root->dataPtr) > 0)
	{
		return searchNode(root->right, dataPtr, compare);
	}
	else
	{
		return TRUE;
	}
}

// Delete AVL Tree
int deleteTree(struct Node *root)
{
	if (root != NULL)
	{
		if (root->left != NULL)
		{
			deleteTree(root->left);
		}
		if (root->right != NULL)
		{
			deleteTree(root->right);
		}
		free(root->dataPtr);
		free(root);
		return TRUE;
	}
	return FALSE;
}

// Count Total Number of Nodes in AVL Tree
int countTotalNodes(struct Node *root)
{
	if (root == NULL)
		return 0;

	int count = 1;

	count += (countTotalNodes(root->left) + countTotalNodes(root->right));

	return count;
}

// Create Array For All Nodes in AVL Tree
int treeToArray(struct Node *root, int *array[], int i)
{
	if (root == NULL)
		return i;

	if (root->left != NULL)
		i = treeToArray(root->left, array, i);

	array[i] = (int *)root->dataPtr;
	i++;

	if (root->right != NULL)
		i = treeToArray(root->right, array, i);

	return i;
}

// Print the AVL Tree
void printInOrder(struct Node *root, void (*print)(const void *))
{
	if (root != NULL)
	{
		printInOrder(root->left, print);
		(*print)(root->dataPtr);
		//printf(":%d  ", root->height);
		printInOrder(root->right, print);
	}
}

