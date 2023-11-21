/*
Write menu driven program using ‘C’ for Dynamic implementation of Stack. The
menu includes following operations:
- Push
- Pop
- Display
- Exit
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *nextAdd;
};
typedef struct Stack stack;

stack *push(int no, stack *top)
{
    stack *newnode = (stack *)malloc(sizeof(stack));
    newnode->data = no;
    newnode->nextAdd = NULL;
    if (top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode->nextAdd = top;
        top = newnode;
    }
    return top;
}

stack *pop(stack *top)
{
    if (top == NULL)
    {
        printf("\nStack was emplty");
    }
    else
    {
        stack *temp = top;
        top = top->nextAdd;
        printf("\nDeleted element was : %d", temp->data);
        free(temp);
    }
    return top;
}

void display(stack *top)
{
    stack *temp = top;
    if (top == NULL)
    {
        printf("\nStack was empty");
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

int menu()
{
    int ch;
    printf("\n1. push\n2. pop\n3. display\n4. exit");
    printf("\nEnter Choice : ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    stack *top = NULL;
    int no;
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("\nEnter A Data : ");
            scanf("%d", &no);
            top = push(no, top);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            return 0;
        }
    }
}