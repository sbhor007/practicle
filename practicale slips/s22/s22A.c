/*
Write a ‘C’ program which accept an Expression and check whether the
expression is Parenthesized or not using stack. (Use Static/Dynamic implementation
of Stack
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack
{
    char data;
    struct Stack *nextAdd;
};
typedef struct Stack stack;

int isEmpty(stack *top)
{
    return top == NULL;
}

stack *push(stack *top, char op)
{
    stack *newnode = (stack *)malloc(sizeof(stack));
    if (newnode == NULL)
    {
        printf("\nMemory Error");
        exit(0);
    }
    newnode->data = op;
    newnode->nextAdd = top;
    return newnode;
}

char pop(stack **top)
{
    if (isEmpty(*top))
    {
        return '\0';
    }
    else
    {
        char ch;
        stack *temp = *top;
        *top = (*top)->nextAdd;
        ch = temp->data;
        free(temp);
        return ch;
    }
}

int isParenthesized(char *str, stack **top)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(')
        {
            *top = push(*top, '(');
        }
        else if (str[i] == ')')
        {
            char x = pop(top);
            if (x == '\0' || x != '(')
                return 0;
        }
    }
    return isEmpty(*top);
}

int main()
{
    char str[50];
    stack *top = NULL;
    printf("\nEnter Expression : ");
    gets(str);
    if (isParenthesized(str, &top))
    {
        printf("\nThis Expression is Parenthesized");
    }
    else
    {
        printf("\nThis Expression is Parenthesized");
    }

    if (!isEmpty(top))
    {
        printf("\nExtra opening Parentheses");
    }
    while (top)
    {
        stack *temp = top;
        top = top->nextAdd;
        free(temp);
    }
    return 0;
}
