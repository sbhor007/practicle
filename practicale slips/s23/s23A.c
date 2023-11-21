/*
Write a menu driven program using ‘C’ for singly linked list-
- To create linked list.
- To display linked list
- To insert node at last position of linked list.
- To delete node from specific position of lin
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

node *getnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->nextAdd = NULL;
    return newnode;
}

node *create(node *start, node *newnoce)
{
    if (start == NULL)
    {
        start = newnoce;
    }
    else
    {
        node *temp = start;
        while (temp->nextAdd)
        {
            temp = temp->nextAdd;
        }
        temp->nextAdd = newnoce;
    }
    return start;
}

void display(node *start)
{
    node *temp = start;
    if (start == NULL)
        printf("\nList was Empty");
    else
    {
        while (temp)
        {
            printf("%5d", temp->data);
            temp = temp->nextAdd;
        }
    }
}

int count(node *start)
{
    int count = 0;
    node *temp = start;
    while (temp)
    {
        temp = temp->nextAdd;
        count++;
    }
    return count;
}

node *deleteMiddle(node *start)
{
    int pos;
    printf("\nEnter the possition to delete element between (1 to %d) : ", count(start));
    scanf("%d", &pos);
    if (pos > 1 && pos <= count(start))
    {
        node *temp = start;
        node *prev = NULL;
        for (int i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->nextAdd;
        }
        prev->nextAdd = temp->nextAdd;
        printf("\nDeleted element is : %d", temp->data);
        free(temp);
    }
    else if (pos == 1)
    {
        node *temp = start;
        start = temp->nextAdd;
        printf("\n%d element was deleted", temp->data);
        free(temp);
        return start;
    }
    else
    {
        printf("Invalide possion");
    }
    return start;
}

int menu()
{
    int ch;
    printf("\n1. Create List\n2. display\n3. delete specific node\n4. exit");
    printf("\nEnter a choice : ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    int no;
    char ch;
    node *start = NULL;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                printf("\nEnter A data : ");
                scanf("%d", &no);
                start = create(start, getnode(no));
                printf("\nWant To Again (y/n) : ");
                ch = getche();
            } while (ch == 'Y' || ch == 'y');
            break;
        case 2:
            display(start);
            break;
        case 3:
            start = deleteMiddle(start);
            break;
        case 4:
            return 0;
        default:
            printf("\nInvalid input");
            break;
        }
    }
}