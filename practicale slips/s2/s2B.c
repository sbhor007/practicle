/*
Write a ‘C’ program to create Circularly Doubly Linked list and display it.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct dlist
{
    struct dlist *prevAdd;
    int data;
    struct dlist *nextAdd;
};

struct dlist *getnode()
{
    struct dlist *newnode = (struct dlist *)malloc(sizeof(struct dlist));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = NULL;
     newnode->prevAdd = NULL;
    return newnode;
}

struct dlist *create(struct dlist *start, struct dlist *newnode)
{
    struct dlist *temp;
    if (start == NULL)
    {
        start = newnode;
        newnode->nextAdd = start;
        newnode->prevAdd = start;
    }
    else
    {
        temp = start;
        while (temp->nextAdd != start)
        {
            temp = temp->nextAdd;
        }
        newnode->nextAdd = start;
        newnode->prevAdd = temp;
        start->prevAdd = newnode;
        temp->nextAdd = newnode;
    }
    return start;
}

void display(struct dlist *start)
{
    struct dlist *temp = start;
    if (temp == NULL)
    {
        printf("\nList was Empty...");
    }
    else
    {
        do
        {
            printf("%5d", temp->data);
            temp = temp->nextAdd;
        } while (temp != start);
    }
}

int main()
{
    struct dlist *start = NULL;
    char ch;
    do
    {
        start = create(start, getnode());
        printf("\nWant to again (y/n) : ");
        ch = getche();
    } while (ch == 'y' || ch == 'Y');
    display(start);
    return 0;
}