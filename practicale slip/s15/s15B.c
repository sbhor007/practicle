/*
Write menu driven program using ‘C’ for Dynamic implementation of Stack.
The menu includes following operations:
- Push
- Pop
- Display
- Exit
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *nextAdd;
    int data;
};
typedef struct node stack;
stack *top = NULL;
stack *newnode, *temp;

void push(int no)
{
    newnode = (stack *)malloc(sizeof(stack));
    newnode->data = no;
    newnode->nextAdd = NULL;
    if (top == NULL)
        top = newnode;
    else
    {
        newnode->nextAdd = top;
        top = newnode;
    }
}

int pop()
{
    int no;
    if (top == NULL)
        printf("\nStack is Empty...!");
    else
    {
        temp = top;
        top = temp->nextAdd;
        no = temp->data;
        free(temp);
        return no;
    }
}

void display()
{
    if (top == NULL)
        printf("\nStack is Empty...!");
    else
    {
        temp = top;
        while (top != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->nextAdd;
        }
    }
}

int menu()
{
    int ch;
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
    printf("\nEnter your choise : ");
    scanf("%d", &ch);
    return ch;
}

int main()
{
    int no;
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("\nEnter a number : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            printf("%d", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid input...!");
            break;
        }
    }
}