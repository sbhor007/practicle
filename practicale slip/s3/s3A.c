/*
)Write a program to create two singly linked list of elements of type integer and find
the union of the linked lists. (Accept elements in the sorted order)
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
node *newnode, *temp, *prev, *next;

node *getnode()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = NULL;
    return newnode;
}

node *create(node *start, node *new)
{
    if (start == NULL)
    {
        start = new;
    }
    else
    {
        temp = start;
        while (temp->nextAdd != NULL)
        {
            temp = temp->nextAdd;
        }
        temp->nextAdd = new;
    }
    return start;
}

void display(node *start)
{
    temp = start;
    if (start == NULL)
    {
        printf("\nList is Emply....");
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

node *union_element(node *uni, node *start1, node *start2)
{
    uni = start1;
    temp = uni;
    while (temp->nextAdd != NULL)
        temp = temp->nextAdd;
    temp->nextAdd = start2;
    return uni;
}

int menu()
{
    int ch;
    printf("\n1. Create First List\n2. Display First List\n3. create second list\n4. display second list\n5. union of list\n6. exit");
    printf("\n----------------");
    printf("\nEnter Choise : ");
    scanf("%d", &ch);
    return ch;
}

int main()
{
    node *list1 = NULL;
    node *list2 = NULL;
    node *uni = NULL;
    char ch;
    while (1)
    {
        switch (menu())
        {
        case 1:

            do
            {
                newnode = getnode();
                list1 = create(list1, newnode);
                printf("\nWant to again (y/n): ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            display(list1);
            break;
        case 3:
            do
            {
                newnode = getnode();
                list2 = create(list2, newnode);
                printf("\nWant to again (y/n): ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 4:
            display(list2);
            break;
        case 5:
            uni = union_element(uni, list1, list2);
            display(uni);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}