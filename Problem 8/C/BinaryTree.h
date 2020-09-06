#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TREE_EMPTY_MSG "\n Tree is empty.\n"
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

BinaryTreeNode *insertNode(BinaryTreeNode *root, int data)
{
    int ch;
    if (root == NULL)
    {
        return (createNode(data));
    }
    else
    {
        BinaryTreeNode *ptr1 = root, *ptr2;
        do
        {

            printf("\n 1. Insert left to : %d ", ptr1->data);
            printf("\n 2. Insert right to : %d ", ptr1->data);
            printf("\n Enter your choice : ");
            scanf("%d", &ch);

            ptr2 = ptr1;
            if (ch == 1)
            {
                ptr1 = ptr1->left;
            }
            else if (ch == 2)
            {
                ptr1 = ptr1->right;
            }
            else
            {
                printf("\n INVALID CHOICE.....!!\n Please choose correct option.");
            }

        } while (ptr1 != NULL);
        if (ch == 1)
        {
            ptr2->left = createNode(data);
        }
        else if (ch == 2)
        {
            ptr2->right = createNode(data);
        }
    }
    return root;
}

BinaryTreeNode *deleteNode(BinaryTreeNode *root, int data)
{
    if (root != NULL)
    {
        if (data == root->data)
        {
            BinaryTreeNode *temp;
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                root = NULL;
            }
            else if (root->left == NULL || root->right == NULL)
            {
                temp = root->left ? root->left : root->right;
                free(root);
                root = temp;
            }
            else
            {
                temp = root->left;
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }
                temp->right = root->right;
                temp = root;
                root = temp->left;
                free(temp);
            }
        }
        else
        {
            root->left = deleteNode(root->left, data);
            root->right = deleteNode(root->right, data);
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
        printf(" %d ", root->data);
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
        printf(TREE_EMPTY_MSG);
        return;
    }
    int h = updateHeight(root);
    int i;
    double space = (pow(2, h - 2) * 3) / 2 * 8;

    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i, space);
        printf("\n\n\n");
    }
}
