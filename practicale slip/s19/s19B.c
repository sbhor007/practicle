/*
 Write a ‘C’ program to create a singly Link
 list and display its alternative nodes.
(start displaying from first node)
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
node *getnode()
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data :");
    scanf("%d", &newnode->data);
    newnode->nextAdd = NULL;
    return newnode;
}

node *create(node *start, node *newnode)
{
    node *temp;
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
    node *temp = start;
    if (start == NULL)
        printf("\nList was empty....");
    else
    {
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
        printf("\nWant To Again (y/n) :");
        ch = getche();
    } while (ch == 'y' || ch == 'Y');
    display(start);
    return 0;
}