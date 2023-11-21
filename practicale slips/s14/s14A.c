/*
Write a ‘C’ program to accept a string from user and reverse it using Dynamic
implementation of Stack.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Stack
{
    char data;
    struct Stack *nextAdd;
};
typedef struct Stack stack;

stack *push(char ch, stack *top)
{
    stack *newnode = (stack *)malloc(sizeof(stack));
    if (newnode == NULL)
    {
        printf("memory allocation fail");
        return 0;
    }
    newnode->data = ch;
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

char pop(stack **top)
{
    char ch;
    if (top != NULL)
    {
        stack *temp = *top;
        *top = (*top)->nextAdd;
        ch = temp->data;
        free(temp);
        return ch;
    }
}

void reverseString(char *str, stack **top)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            *top = push(str[i], *top);
        }
        else
        {
            while (*top != NULL)
            {
                printf("%c", pop(top));
            }
            printf(" ");
        }
    }
    while (*top)
    {
        printf("%c", pop(top));
    }
}

int main()
{
    stack *satck1 = NULL;
    char str[100];
    printf("\nEnter A String : ");
    gets(str);
    reverseString(str, &satck1);
    return 0;
}