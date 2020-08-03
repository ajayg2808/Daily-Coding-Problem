#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    unsigned int both;
} Node;

Node *head = NULL, *tail = NULL;

const char *NULL_POINTER_ERROR = "\nUnable to allocate memory for Node : %d";
const char *REMOVE_ELEMENT_MSG = "\nRemoving element %d from doubly linked list.";
const char *EMPTY_LIST = "\nDoubly linked list is empty.";
const char *NEGATIVE_INDEX_ERROR = "\nNegative index is not possible.";

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node != NULL)
    {
        node->data = data;
        node->both = 0;
    }
    return node;
}

int insertFirst(int data)
{
    Node *temp = createNode(data);
    if (temp == NULL)
    {
        printf(NULL_POINTER_ERROR, data);
        return 0;
    }

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return 1;
    }
    else
    {
        unsigned int nextAdd = (unsigned int)head;
        unsigned int prevAdd = (unsigned int)temp;
        temp->both ^= nextAdd;
        head->both ^= prevAdd;
        head = temp;
        return 1;
    }

    printf("\nNot able to insert Node : %d at beginning to doubly linked list", data);

    free(temp);
    return 0;
}

int insertLast(int data)
{
    Node *temp = createNode(data);
    if (temp == NULL)
    {
        printf(NULL_POINTER_ERROR, data);
        return 0;
    }
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return 1;
    }
    else
    {
        unsigned int nextAdd = (unsigned int)temp;
        unsigned int prevAdd = (unsigned int)tail;
        tail->both ^= nextAdd;
        temp->both ^= prevAdd;
        tail = temp;
        return 1;
    }

    printf("\nNot able to insert Node : %d at last to doubly linked list", data);
    free(temp);
    return 0;
}

int insertAt(int index, int data)
{
    int count = 0;
    if (head == NULL)
    {
        printf(EMPTY_LIST);
        return 0;
    }
    if (index < 0)
    {
        printf(NEGATIVE_INDEX_ERROR);
        return 0;
    }
    if (index == 0)
    {
        return insertFirst(data);
    }
    Node *temp = createNode(data);

    if (temp == NULL)
    {
        printf(NULL_POINTER_ERROR, data);
        return 0;
    }
    Node *ptr = head;
    unsigned int prevAdd = 0;
    unsigned int nextAdd = 0;
    while (ptr != NULL && count != index)
    {
        nextAdd = prevAdd ^ ptr->both;
        prevAdd = (unsigned int)ptr;
        ptr = (Node *)nextAdd;
        count++;
    }
    if (index == count)
    {
        if (ptr != NULL)
        {
            ((Node *)prevAdd)->both ^= (unsigned int)ptr ^ (unsigned int)temp;
            temp->both = prevAdd ^ (unsigned int)ptr;
            ptr->both ^= prevAdd ^ (unsigned int)temp;
            return 1;
        }
        else
        {
            return insertLast(data);
        }
    }

    printf("\nNot able to insert Node : %d at index : %d", data, index);
    free(temp);
    return 0;
}

void traversDoublyLinkedList()
{
    Node *ptr = head;
    unsigned int prevAdd = 0;
    if (head == NULL)
    {
        tail = head;
        printf(EMPTY_LIST);
        return;
    }
    printf("\nElement in doubly linked list :");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        unsigned int temp = (unsigned int)ptr;
        ptr = (Node *)(ptr->both ^ prevAdd);
        prevAdd = temp;
    }
}

void traversDoublyLinkedListReverse()
{
    Node *ptr = tail;
    unsigned int nextAdd = 0;
    if (tail == NULL)
    {
        head = tail;
        printf(EMPTY_LIST);
        return;
    }
    printf("\nElement in doubly linked list (reverse order) :");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        unsigned int temp = (unsigned int)ptr;
        ptr = (Node *)(ptr->both ^ nextAdd);
        nextAdd = temp;
    }
}

int size()
{
    Node *ptr = head;
    int count = 0;
    unsigned int prevAdd = 0;
    while (ptr != NULL)
    {
        count++;
        unsigned int temp = (unsigned int)ptr;
        ptr = (Node *)(ptr->both ^ prevAdd);
        prevAdd = temp;
    }
    return count;
}

int removeFirst()
{
    if (head == NULL)
    {
        printf(EMPTY_LIST);
        return 0;
    }

    printf(REMOVE_ELEMENT_MSG, head->data);

    if (head == tail)
    {
        free(head);

        head = NULL;
        tail = NULL;
        return 1;
    }
    else
    {
        Node *temp = head;
        head = (Node *)temp->both;
        head->both ^= (unsigned int)temp;

        free(temp);
        return 1;
    }
    printf("\nNot able to remove 1st element from doubly liked list.");
    return 0;
}

int removeLast()
{
    if (head == NULL)
    {
        printf(EMPTY_LIST);
        return 0;
    }

    printf(REMOVE_ELEMENT_MSG, tail->data);

    if (head == tail)
    {
        free(head);

        head = NULL;
        tail = NULL;
        return 1;
    }
    else
    {
        Node *temp = tail;
        tail = (Node *)temp->both;
        tail->both ^= (unsigned int)temp;

        free(temp);
        return 1;
    }

    return 0;
}

int removeAt(int index)
{
    if (index < 0)
    {
        printf(NEGATIVE_INDEX_ERROR);
        return 0;
    }

    if (head == NULL)
    {
        printf(EMPTY_LIST);
        return 0;
    }
    if (index == 0)
    {
        return removeFirst();
    }
    int count = 0;
    Node *ptr = head;
    unsigned int prevAdd = 0;
    unsigned int nextAdd = 0;
    while (ptr != NULL && count != index)
    {
        nextAdd = prevAdd ^ ptr->both;
        prevAdd = (unsigned int)ptr;
        ptr = (Node *)nextAdd;
        count++;
    }
    if (index == count)
    {
        if (ptr != NULL)
        {
            printf(REMOVE_ELEMENT_MSG, ptr->data);
            nextAdd = ptr->both ^ prevAdd;
            ((Node *)prevAdd)->both ^= (unsigned int)ptr ^ nextAdd;
            ((Node *)nextAdd)->both ^= (unsigned int)ptr ^ prevAdd;
            free(ptr);
            return 1;
        }
        else
        {
            return removeLast();
        }
    }

    printf("\nNot able to remove Node at index : %d", index);
    return 0;
}

void clear()
{
    Node *ptr = head;
    unsigned int prevAdd = 0;
    if (head == NULL)
    {
        tail = head;
        printf(EMPTY_LIST);
        return;
    }
    while (ptr != NULL)
    {
        unsigned int temp = (unsigned int)ptr;
        ptr = (Node *)(ptr->both ^ prevAdd);
        prevAdd = temp;
        free((Node *)temp);
    }
    head = tail = NULL;
    printf("\n Deleted doubly linked list.");
}

int *get(int index)
{
    if (index < 0)
    {
        printf(NEGATIVE_INDEX_ERROR);
        return NULL;
    }
    Node *ptr = head;
    int count = 0, *temp = NULL;
    unsigned int prevAdd = 0;
    while (ptr != NULL && count != index)
    {
        count++;
        unsigned int temp = (unsigned int)ptr;
        ptr = (Node *)(ptr->both ^ prevAdd);
        prevAdd = temp;
    }
    if (count == index)
    {
        if (ptr != NULL)
        {
            temp = (int)malloc(sizeof(int));
            *temp = ptr->data;
        }
    }
    if (temp == NULL)
        printf("\nIndex %d not possible in doubly linked list.", index);
    return temp;
}

int main()
{
    int ch, data, index, *x, s;
    const char *ENTER_ELEMENT = "\n Enter element to add at %s : ";
    const char *SEPERATOR = "\n======================================================================\n";
    do
    {
        printf(SEPERATOR);
        printf("\n* * * * * * * MENU * * * * * * *\n");
        printf("\n 1.  Insert First\n 2.  Insert Last\n 3.  Insert At Index");
        printf("\n 4.  Remove First\n 5.  Remove Last\n 6.  Remove From Index");
        printf("\n 7.  Get Element At Index\n 8.  Size\n 9.  Clear \n 10. Display\n 11. Display Reverse");
        printf("\n 12. Exit\nEnter Your Choice : ");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf(SEPERATOR);
            printf(ENTER_ELEMENT, "beginning");
            scanf("%d", &data);
            insertFirst(data);
            break;

        case 2:
            printf(SEPERATOR);
            printf(ENTER_ELEMENT, "last");
            scanf("%d", &data);
            insertLast(data);
            break;

        case 3:
            printf(SEPERATOR);
            printf("\n Enter index : ");
            scanf("%d", &index);
            char str[16]; //= "index-";
            sprintf(str,"index-%d", index);
            printf(ENTER_ELEMENT, str);
            scanf("%d", &data);
            insertAt(index, data);
            break;

        case 4:
            printf(SEPERATOR);
            removeFirst();
            break;

        case 5:
            printf(SEPERATOR);
            removeLast();
            break;

        case 6:
            printf(SEPERATOR);
            printf("\n Enter index : ");
            scanf("%d", &index);
            removeAt(index);
            break;

        case 7:
            printf(SEPERATOR);
            printf("\n Enter index : ");
            scanf("%d", &index);
            x = get(index);
            if (x != NULL)
            {
                printf("\n Element at index : %d is %d.", index, *x);
            }
            break;

        case 8:
            printf(SEPERATOR);
            s = size();
            printf("\n Size of doubly linked list is : %d", s);
            break;

        case 9:
            printf(SEPERATOR);
            clear();
            break;

        case 10:
            printf(SEPERATOR);
            traversDoublyLinkedList();
            break;

        case 11:
            printf(SEPERATOR);
            traversDoublyLinkedListReverse(index);
            break;

        case 12:
            break;

        default:
            printf("\n INVALID CHOICE......!");
            break;
        }
    } while (ch != 12);

    return 0;
}
