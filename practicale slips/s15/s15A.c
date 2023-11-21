/*
 Write a ‘C’ program to accept an infix expression, convert it into its equivalent
postfix expression and display the result.(Use Dynamic Implementation of Stack)
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
    if (*top == NULL)
        return -1;
    else
    {
        stack *temp = *top;
        *top = (*top)->nextAdd;
        ch = temp->data;
        free(temp);
        return ch;
    }
}

int priority(int op)
{
    if (op == '(')
        return 0;
    else if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return -1;
}
void infixToPostfix(char *str, stack **top)
{
    char x;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalnum(str[i]))
        {
            printf("%c", str[i]);
        }
        else if (str[i] == '(')
        {
            *top = push(str[i], *top);
        }
        else if (str[i] == ')')
        {
            while ((x = pop(top) != '('))
            {
                printf("%c", x);
            }
        }
        else
        {
            while (*top != NULL && priority((*top)->data) > priority(str[i]))
            {
                printf("%c", pop(top));
            }
            *top = push(str[i], *top);
        }
    }
    while (*top)
    {
        printf("%c", pop(top));
    }
}

int main()
{
    char str[100];
    printf("\nEnter Infix Operation : ");
    scanf("%s", str);
    stack *top = NULL;
    infixToPostfix(str, &top);
    return 0;
}