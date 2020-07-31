#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    int height;

} BinaryTreeNode;

int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int getHeight(BinaryTreeNode *ptr)
{
    if (ptr == NULL)
        return 0;
    return ptr->height;
}

int updateHeight(BinaryTreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL)
        root->left->height = updateHeight(root->left);
    if (root->right != NULL)
        root->right->height = updateHeight(root->right);
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root->height;
}

BinaryTreeNode *createNode(int data)
{
    BinaryTreeNode *node = (BinaryTreeNode *)
        malloc(sizeof(BinaryTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

BinaryTreeNode *insertLevelOrder(BinaryTreeNode *root, int data, int level, int *inserted)
{

    if (root == NULL)
    {
        *inserted = TRUE;
        return createNode(data);
    }
    if (level == 1)
    {
        return root;
    }
    else if (level > 1)
    {
        if (!*inserted)
            root->left = insertLevelOrder(root->left, data, level - 1, inserted);
        if (!*inserted)
            root->right = insertLevelOrder(root->right, data, level - 1, inserted);

        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        return root;
    }
}

BinaryTreeNode *insertNode(BinaryTreeNode *root, int data)
{
    int ch, inserted = FALSE;
    if (root == NULL)
    {
        return (createNode(data));
    }
    else
    {
        root = insertLevelOrder(root, data, root->height, &inserted);

        if (!inserted)
        {
            BinaryTreeNode *p = root;
            while (p->left != NULL)
            {
                p = p->left;
            }
            p->left = createNode(data);
            root->height = updateHeight(root);
        }
    }

    return root;
}

BinaryTreeNode *deleteTree(BinaryTreeNode *root)
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
        free(root);
        root == NULL;
    }
    return root;
}

void printInOrder(BinaryTreeNode *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

void printGivenLevel(BinaryTreeNode *root, int level, double space)
{
    int i;
    if (root == NULL)
    {
        for (i = 0; i < space / 2; i++)
            printf(" ");
        printf(" ");
        for (i = 1; i < space / 2; i++)
            printf(" ");
        return;
    }
    if (level == 1)
    {
        for (i = 0; i < space / 2; i++)
            printf(" ");
        printf("%d", root->data);
        for (i = 2; i < space / 2; i++)
            printf(" ");
    }
    else if (level > 1)
    {
        space /= 2;
        printGivenLevel(root->left, level - 1, space);
        printGivenLevel(root->right, level - 1, space);
    }
}

void printLevelOrder(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        printf("\n Tree is empty. \n");
        return;
    }
    int h = root->height;
    int i;
    double space = (pow(2, h - 2) * 3) / 2 * 8;

    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i, space);
        printf("\n\n\n");
    }
}