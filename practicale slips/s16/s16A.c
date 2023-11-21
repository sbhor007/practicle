/*
Write a ‘C’ program which accept the string and reverse each word of the string
using Static implementation of stack.
Example: Input - This is an input string
 Output - sihTsinatupnignirts
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
    if (*top != NULL)
    {
        stack *temp = *top;
        *top = (*top)->nextAdd;
        ch = temp->data;
        free(temp);
        return ch;
    }
}

void reverseStr(char *str, stack **top)
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
        }
    }
    while (*top != NULL)
    {
        printf("%c", pop(top));
    }
}
int main()
{
    char str[100];
    stack *top = NULL;
    printf("\nEnter a string : ");
    gets(str);
    reverseStr(str, &top);
    return 0;
}