/*
Write a ‘C’ program to count all non-zero elements, odd numbers
and even numbers in the singly linked list.
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
node *temp;

node *getnode()
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
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
        temp = start;
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
    temp = start;
    if (start == NULL)
    {
        printf("\nList Was Empty.....!");
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

void count_zero_odd_even(node *start)
{
    int zero = 0;
    int odd = 0;
    int even = 0;
    temp = start;
    if (start == NULL)
    {
        printf("\nList Not Exist....!");
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == 0)
                zero++;
            else if (temp->data % 2 == 0)
                even++;
            else if (temp->data % 2 != 0)
                odd++;
            temp = temp->nextAdd;
        }
        printf("\nTotal ZERO no : %d", zero);
        printf("\nTotal ODD no : %d", odd);
        printf("\nTotal EVEN no : %d", even);
    }
}

int menu()
{
    int ch;
    printf("\n1. create\n2. display\n3. count zero,odd,even\n4. exit");
    printf("\nEnter Choice : ");
    scanf("%d", &ch);
    return ch;
}

int main()
{
    int ch;
    node *start = NULL;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                start = create(start, getnode());
                printf("\nWant To Again (y/n): ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            display(start);
            break;
        case 3:
            count_zero_odd_even(start);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Input...!");
            break;
        }
    }
}