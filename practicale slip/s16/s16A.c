
/*
Write a ‘C’ program to read a postfix expression, evaluate it and display the result.
(Use Static Implementation of Stack).
*/
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("\nStack was Empty...!");
    }
    else
    {
        stack[++top] = ch;
    }
}

char pop()
{
    return stack[top--];
}

int priority(char op)
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
            while (top != -1 && priority(stack[top]) >= priority(str[i]))
            {
                printf("%c", pop());
            }
            push(str[i]);
        }
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
}

int main()
{
    char str[MAX];
    printf("\nEnter Infix Expression : ");
    scanf("%s", str);
    infixToPostfix(str);
    return 0;
}
