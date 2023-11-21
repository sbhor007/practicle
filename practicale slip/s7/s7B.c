/*
Write a ‘C’ program to create a singly linked list and count
total number of nodes
in it and display the list and total number of Nodes.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct list
{
    struct list *nextAdd;
    int data;
};
typedef struct list node;
node *newnode, *temp;

node *getnode()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = NULL;
}

int count(node *start)
{
    int ctr = 0;
    temp = start;
    while (temp != NULL)
    {
        temp = temp->nextAdd;
        ctr++;
    }
    return ctr;
}

node *create(node *start, node *newnode)
{
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->nextAdd != NULL)
            temp = temp->nextAdd;
        temp->nextAdd = newnode;
    }
    return start;
}

void display(node *start)
{
    temp = start;
    if (start == NULL)
    {
        printf("\nList empty....");
    }
    else
    {
        printf("\nList Elements are : ");
        while (temp != NULL)
        {
            printf("%5d", temp->data);
            temp = temp->nextAdd;
        }
    }
}

int main()
{
    node *start = NULL;
    char ch;
    do
    {
        start = create(start, getnode());
        printf("\nWant To Again (y/n) : ");
        ch = getche();
    } while (ch == 'y' || ch == 'Y');
    display(start);
    printf("\nTotal No. of nodes in a list is : %d", count(start));
    return 0;
}