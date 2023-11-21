/*
 Write a ‘C’ program to create Circularly
 Doubly Linked list and display it.
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct sd_list
{
    struct sd_list *prevAdd;
    int data;
    struct sd_list *nextAdd;
};
typedef struct sd_list node;
// node *start = NULL;
node *newnode, *temp;

node *getnode()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = newnode->prevAdd = NULL;
    return newnode;
}

int menu()
{
    int ch;
    printf("\n1. Create\n2. Display\n3. Reverse List\n4. exit");
    printf("\n---------------");
    printf("\nEnter Your Choise : ");
    scanf("%d", &ch);
    return ch;
}

node *create(node *start, node *new)
{
    if (start == NULL)
    {
        start = new;
        new->nextAdd = start;
        new->prevAdd = start;
    }
    else
    {
        temp = start;
        while (temp->nextAdd != start)
        {
            temp = temp->nextAdd;
        }
        new->nextAdd = start;
        new->prevAdd = temp;
        start->prevAdd = new;
        temp->nextAdd = new;
    }
    return start;
}

void display(node *start)
{
    temp = start;
    if (start == NULL)
    {
        printf("\nList data are empty....");
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
void display_reverse(node *start)
{
    temp = start;
    if (start == NULL)
    {
        printf("\nList Data Are Empty...");
    }
    else
    {
        do
        {
            temp = temp->prevAdd;
            printf("%5d", temp->data);
        } while (temp != start);
    }
}
int main()
{
    node *start = NULL;
    char ch;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                newnode = getnode();
                start = create(start, newnode);
                printf("\nWant To Again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');

            break;
        case 2:
            display(start);
            break;
        case 3:
            display_reverse(start);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Input...!");
        }
    }
}
