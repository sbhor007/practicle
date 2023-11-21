/*
Write a menu driven program using ‘C’ for singly linked list-
- To create linked list.
- To display linked list
- To search node in linked list.
- Insert at last position
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct slist
{
    int data;
    struct slist *nextAdd;
};
typedef struct slist node;
node *newnode, *temp;

int menu()
{
    int ch;
    printf("\n1. create list\n2. display list\n3. search list\n4. insert last node\n5. exit");
    printf("\n--------------");
    printf("\nEnter Your choise : ");
    scanf("%d", &ch);
    return ch;
}

node *getnode()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = NULL;
    return newnode;
}

node *create(node *start, node *new)
{
    if (start == NULL)
    {
        start = new;
    }
    else
    {
        temp = start;
        while (temp->nextAdd != NULL)
            temp = temp->nextAdd;
        temp->nextAdd = new;
    }
    return start;
}

void display(node *start)
{
    temp = start;
    if (start == NULL)
    {
        printf("\nList Was Empty....");
    }
    else
    {
        printf("\nList data is : ");
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->nextAdd;
        }
    }
}

int search(node *start, int key)
{

    int i = 0;
    temp = start;
    if (start == NULL)
    {
        printf("\nList dos not exist ....!");
    }
    else
    {

        while (temp != NULL)
        {
            i++;
            if (temp->data == key)
            {
                return i;
                // break;
            }
            temp = temp->nextAdd;
        }
    }
    return -1;
}

node *inseartLast(node *start, node *new)
{
    if (start == NULL)
    {
        start = new;
    }
    else
    {
        temp = start;
        while (temp->nextAdd != NULL)
            temp = temp->nextAdd;
        temp->nextAdd = new;
    }
    return start;
}
int main()
{
    int key, result;
    char ch;

    node *start = NULL;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                newnode = getnode();
                start = create(start, newnode);
                printf("\nwant to again (y/n) : ");
                ch = getche();
            } while (ch == 'Y' || ch == 'y');
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("\nEnter the element to search : ");
            scanf("%d", &key);
            result = search(start, key);
            if (result == -1)
            {
                printf("\n %d is not in a list.\n", key);
            }
            else
            {
                printf("\n%d is present at %d position.\n", key, result);
            }
            break;
        case 4:
            start = inseartLast(start, getnode());
            break;
        case 5:
            return 0;
        default:
            printf("\nInvalide input....!");
            break;
        }
    }
}