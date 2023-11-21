/*
Write a ‘C’ program to accept an infix expression, convert it into its equivalent
postfix expression and display the result.(Use Dynamic Implementation of Stack)
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    struct node *nextAdd;
    char data;
};
typedef struct node stack;
stack *top = NULL;
stack *newnode, *temp;

void push(char ch)
{
    newnode = (stack *)malloc(sizeof(stack));
    if (newnode == NULL)
    {
        printf("\nMemory allocation fail....!");
        exit(1);
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
}

char pop()
{
    char ch;
    temp = top;
    top = top->nextAdd;
    ch = temp->data;
    free(temp);
    return ch;
}
int priority(char ch)
{
    if (ch == '(')
        return 0;
    else if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return -1;
}

void infixToPostfix(char *str)
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
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (top != NULL && priority(top->data) >= priority(str[i]))
            {
                printf("%c", pop());
            }
            push(str[i]);
        }
    }
    while (top != NULL)
        printf("%c", pop());
}
int main()
{
    char str[50];
    printf("\nEnter Infix expression : ");
    scanf("%s", str);
    infixToPostfix(str);
    return 0;
}