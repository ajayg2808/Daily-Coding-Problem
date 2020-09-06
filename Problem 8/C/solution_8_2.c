#include "BinaryTree.h"

int count = 0;
int countUnivalSubtrees(BinaryTreeNode *node)
{

    if (node != NULL)
    {
        int l = countUnivalSubtrees(node->left);
        int r = countUnivalSubtrees(node->right);
        if (!l || !r)
            return 0;

        if (node->left != NULL && node->data != node->left->data)
        {
            return 0;
        }
        if (node->right != NULL && node->data != node->right->data)
        {
            return 0;
        }

        count++;
        return 1;
    }
    return 1;
}

int main()
{
    int ch;
    BinaryTreeNode *tree = NULL;

    do
    {
        printf("\n 1. Insert Node.\n 2. Delete Node\n 3. Count Unival Subtrees.\n 4. Display Tree\n 5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        int data;
        switch (ch)
        {
        case 1:
            printf("\n Enter data to insert : ");
            scanf("%d", &data);
            tree = insertNode(tree, data);
            break;

        case 2:
            printf("\n Enter key to delete : ");
            scanf("%d", &data);
            tree = deleteNode(tree, data);
            break;

        case 3:
            count = 0;
            countUnivalSubtrees(tree);
            printf("\n Total Unival Subtrees : %d \n", count);
            break;

        case 4:
            printLevelOrder(tree);
            printf("\n\n Inorder : \n");
            printInOrder(tree);
            break;

        case 5:
            tree = deleteTree(tree);
            break;

        default:
            printf("\n INVALID CHOICE....!\n");
            break;
        }
    } while (ch != 5);
}