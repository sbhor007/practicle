/*
Write a ‘C’ program to create linked list with given number in which data part of
each node contains individual digit of the number.
(Ex. Suppose the number is 368 then the nodes of linked list should contain 3, 6, 8)
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

node *getnode(int no)
{
    newnode = (node *)malloc(sizeof(node));
    newnode->data = no;
    newnode->nextAdd = NULL;
    return newnode;
}

node *create(node *start, node *newnode)
{
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->nextAdd = start;
        start = newnode;
    }
    return start;
}

void display(node *start)
{
    temp = start;
    if (start == NULL)
    {
        printf("\nList Was Empty...");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->nextAdd;
        }
    }
}

int main()
{
    node *start = NULL;
    int no, dig;
    printf("\nEnter a Number : ");
    scanf("%d", &no);
    while (no > 0)
    {
        newnode = getnode(no % 10);
        start = create(start, newnode);
        no /= 10;
    }
    display(start);
    return 0;
}