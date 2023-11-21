/*
 Write a ‘C’ program to swap mth and nth element of singly linked
  list
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *nextAdd;
};
typedef struct list node;
node *temp;

node *getnode()
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = NULL;
    return newnode;
}

int count(node *start)
{
    int i = 0;
    temp = start;
    while (temp != NULL)
    {
        temp = temp->nextAdd;
        i++;
    }
    return i;
}

node *crete(node *start, node *newnode)
{
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->nextAdd != NULL)
        {
            temp = temp->nextAdd;
        }
        temp->nextAdd = newnode;
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
        while (temp != NULL)
        {
            printf("%5d", temp->data);
            temp = temp->nextAdd;
        }
    }
}

void swap(node *start, int pos1, int pos2)
{
    node *temp2;
    if (pos1 > 0 && pos1 <= count(start))
    {
        if (pos2 > 0 && pos2 <= count(start))
        {
            if (pos1 != pos2)
            {
                temp2 = start;
                for (int i = 1; i < pos1; i++)
                {
                    temp2 = temp2->nextAdd;
                }
                temp = start;
                for (int i = 1; i < pos2; i++)
                {
                    temp = temp->nextAdd;
                }
                int t = temp->data;
                temp->data = temp2->data;
                temp2->data = t;
            }
            else
            {
                printf("\nSame Possition Not Allow....!");
            }
        }
        else
        {
            printf("\nInvalid Possition...");
        }
    }
    else
    {
        printf("\nInvalid Possition...");
    }
}

int menu()
{
    int ch;
    printf("\n\n1. create.\n2. display.\n3. swap\n4. exit");
    printf("\nEnter Choice : ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    node *start = NULL;
    int pos1, pos2;
    char ch;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                start = crete(start, getnode());
                printf("\nWant To again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("\nEnter First Position : ");
            scanf("%d", &pos1);
            printf("\nEnter Second position : ");
            scanf("%d", &pos2);
            swap(start, pos1, pos2);
            break;
        case 4:
            exit(0);
        }
    }
}