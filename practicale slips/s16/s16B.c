/*
Write a ‘C’ program to create to a Singly linked list. Accept the number from user,
search the number in the list.If the number is present display the Position of node .If
number not present print the message “Number not Found”.
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
        node *temp = start;
        while (temp->nextAdd)
            temp = temp->nextAdd;
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
        while (temp)
        {
            printf("%d", temp->data);
            temp = temp->nextAdd;
        }
    }
}

int search(node *start, int key)
{
    node *temp = start;
    int i = 1;
    while (temp)
    {
        if (temp->data == key)
        {
            return i;
        }
        temp = temp->nextAdd;
        i++;
    }
    return 0;
}

int menu()
{
    int ch;
    printf("\n1. Create List\n2. Display\n3. Search\n4. Exit");
    printf("\nEnter choice : ");
    scanf("%d", &ch);
    return ch;
}

int main()
{
    int no, key, result;
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
                start = create(start, getnode(no));
                printf("\nWant to again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("\nEnter Element to search : ");
            scanf("%d", &key);
            result = search(start, key);
            if (result != 0)
            {
                printf("\n%d element present at the %d position", key, result);
            }
            else
            {
                printf("\n%d element not present", key);
            }
            break;
        case 4:
            return 0;
        }
    }
}