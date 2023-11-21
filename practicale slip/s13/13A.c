/*
Write a C program to accept an infix expression and convert it into
 postfix form.(Use Static Implementation of Stack)
Example: - A * B + C as AB*C+
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
int stack[MAX], top = -1;

void push(char data)
{
    if (top == MAX - 1)
        printf("\nStack is overflow....!");
    else
    {
        stack[++top] = data;
    }
}
char pop()
{
    return stack[top--];
}

char priority(char op)
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
            while (top != -1 && priority(str[i]) <= priority(stack[top]))
            {
                printf("%c", pop());
            }
            push(str[i]);
        }
    }
    while (top != -1)
        printf("%c", pop());
}
int main()
{
    char str[MAX];
    printf("\nEnter a Infix Expression : ");
    scanf("%s", str);
    infixToPostfix(str);
    return 0;
}