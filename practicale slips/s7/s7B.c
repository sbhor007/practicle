/*
Write a ‘C’ program to create a singly linked list and count total number of nodes
in it and display the list and total number of Nodes.
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

node *getnode(int no)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = no;
    newnode->nextAdd = NULL;
    return newnode;
}

node *createList(node *start, node *newnode)
{
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        node *temp = start;
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
    node *temp = start;
    if (start == NULL)
    {
        printf("\nList was empty");
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

int count(node *start)
{
    int ctr = 0;
    node *temp = start;
    while (temp)
    {
        ctr++;
        temp = temp->nextAdd;
    }
    return ctr;
}
int menu()
{
    int ch;
    printf("\n1. Create List\n2. Display\n3. Count Node\n4. exit");
    printf("\nEnter Choice : ");
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
                printf("\nEnter Data : ");
                scanf("%d", &no);
                start = createList(start, getnode(no));
                printf("\nWant to again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("\nTotal No of Nodes is : %d", count(start));
            break;
        case 4:
            return 0;
        }
    }
}