#include <stdio.h>
#include <string.h>
#include "Tree/CompleteBinaryTree.h"

const int charSize = sizeof(char);

// Concatenate str1 and str2
char *concate(char *str1, char *str2)
{
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    char *str = (char *)malloc(charSize * (l1 + l2 + 1));
    int i, j;
    i = 0;
    j = 0;
    while (str1[i])
    {
        str[j] = str1[i];
        i++;
        j++;
    }
    i = 0;
    while (str2[i])
    {
        str[j] = str2[i];
        j++;
        i++;
    }
    str[j] = '\0';

    return str;
}

// Serialize Tree into string
char *serialize(BinaryTreeNode *root)
{
    char *str = "[";
    char data[10];
    char *left, *right;
    if (root != NULL)
    {
        itoa(root->data, data, 10);

        left = serialize(root->left);
        right = serialize(root->right);

        str = concate(str, data);
        str = concate(str, ",");
        str = concate(str, left);
        str = concate(str, right);
        free(left);
        free(right);
    }
    str = concate(str, "]");
    return str;
}

// Remove char at given index
void removeAt(char *str, int index)
{
    memmove(&str[index], &str[index + 1], strlen(str) - index);
}

// Return index of char in string
int indexOf(char *str, char ch)
{
    int index = -1;
    const char *ptr = strchr(str, ch);
    if (ptr)
    {
        index = ptr - str;
    }
    return index;
}

// Substring of str
// from included
// to excluded
char *substring(char *str, int from, int to)
{
    char *sub = NULL;
    int i, j = 0;
    if (to <= strlen(str))
    {
        sub = (char *)malloc(charSize * (to - from));
        for (i = from, j = 0; i < to; i++, j++)
        {
            sub[j] = str[i];
        }
        sub[j] = '\0';
    }
    return sub;
}

// return index of closing delimeter form serialized string
int getNodeEndIndex(char *str, int fromIndex, char openChar, char closeChar)
{
    int index = -1, i, j, len = strlen(str);
    int count = 0;
    if (fromIndex < len)
    {
        for (i = fromIndex; i < len; i++)
        {
            if (str[i] == openChar || str[i] == closeChar)
            {
                if (str[i] == openChar)
                {
                    count++;
                }
                if (str[i] == closeChar)
                {
                    count--;
                }
                if (count == 0)
                {
                    index = i;
                    break;
                }
            }
        }
    }
    return index;
}

// Desrialize string into tree
BinaryTreeNode *deSerialize(char *str)
{
    BinaryTreeNode *root = NULL;
    int len = strlen(str), i, j, data;
    char *sub, *left, *right;
    if (len > 2)
    {
        removeAt(str, 0);
        removeAt(str, strlen(str) - 1);
        i = indexOf(str, ',');
        sub = substring(str, 0, i);
        data = atoi(sub);

        root = createNode(data);

        i = indexOf(str, '[');
        j = getNodeEndIndex(str, i, '[', ']');
        left = substring(str, i, j + 1);

        root->left = deSerialize(left);

        i = j + 1;
        j = getNodeEndIndex(str, i, '[', ']');
        right = substring(str, i, j + 1);

        root->right = deSerialize(right);
        root->height = updateHeight(root);

        free(sub);
        free(left);
        free(right);
    }
    return root;
}

// Driver program
int main()
{
    int x;
    char ch;
    BinaryTreeNode *originalTree = NULL, *deserializedTree = NULL;
    do
    {
        printf("\n Enter data for new node : ");
        scanf("%d", &x);
        originalTree = insertNode(originalTree, x);
        printf("\n New node added in tree.");
        printf("\n\n Do you add more nodes\n Enter choice(Y/N) : ");
        fflush(stdin);
        scanf("%c", &ch);

    } while (ch == 'Y' || ch == 'y');

    printf("\n Original Tree : \n");
    printLevelOrder(originalTree);

    printf("\n Inorder of original tree : ");
    printInOrder(originalTree);
    printf("\n\n");

    // Serialize operation
    char *serializedTreeString = serialize(originalTree);
    printf("\n Serialized string : %s\n", serializedTreeString);

    originalTree = deleteTree(originalTree);
    printf("\n Original Tree deleted successfully.\n");

    // Desrialize operation
    deserializedTree = deSerialize(serializedTreeString);
    printf("\n Deserialized Tree : \n");
    printLevelOrder(deserializedTree);

    printf("\n Inorder of deserialized tree tree : ");
    printInOrder(deserializedTree);
    printf("\n\n");

    deserializedTree = deleteTree(deserializedTree);
    printf("\n Desrialized Tree deleted successfully.\n");

    free(serializedTreeString);
    return 0;
}
