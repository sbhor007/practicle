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
    int data;
    struct list *nextAdd;
};
typedef struct list node;
node *temp = NULL;

node *getnode(int no)
{
    node *newnode = (node *)malloc(sizeof(node));
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
        printf("\nList was epty\n");
    }
    else
    {
        printf("\nList data are : \n");
        while (temp != NULL)
        {
            printf("%5d", temp->data);
            temp = temp->nextAdd;
        }
    }
}
int main()
{
    int no;
    node *start = NULL;
    printf("Enter A Number : ");
    scanf("%d", &no);
    while (no > 0)
    {
        start = create(start, getnode(no % 10));
        no /= 10;
    }
    display(start);
    return 0;
}