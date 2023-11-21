/*
 Write a ‘C’ program to create a singly Link list and display its alternative nodes.
(start displaying from first node)
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

node *create(node *start, int no)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->nextAdd = NULL;
    newnode->data = no;
    if (newnode == NULL)
    {
        printf("\nMemory allocation fail");
        exit(0);
    }
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        node *temp = start;
        while (temp->nextAdd)
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
    if (temp == NULL)
    {
        printf("\nList was empty");
    }
    else
    {
        while (temp)
        {
            printf("%5d", temp->data);
            temp = temp->nextAdd;
        }
    }
}

void alternativeNode(node *start)
{
    node *temp = start;
    if (temp == NULL)
    {
        printf("\nList Was Empty");
    }
    else
    {
        int i = 1;
        while (temp)
        {
            if (i % 2 != 0)
                printf("%5d", temp->data);
            temp = temp->nextAdd;
            i++;
        }
    }
}
int menu()
{
    int ch;
    printf("\n1. Create\n2. Display\n3. Alternative nodes\n4. Exit");
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
                printf("\nEnter a Number : ");
                scanf("%d", &no);
                start = create(start, no);
                printf("\nWant to again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            display(start);
            break;
        case 3:
            alternativeNode(start);
            break;
        case 4:
            return 0;
        default:
            printf("\nInvalid Input");
            break;
        }
    }
}