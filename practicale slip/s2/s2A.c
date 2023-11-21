/* Write a ‘C’ program to accept a string from user and
reverse it using Static implementation of Stack*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
char stack[MAX], top = -1;

void push(char str)
{
    if (top == MAX - 1)
    {
        printf("\nStack is Overflow...!");
    }
    else
    {
        stack[++top] = str;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("\nStack is UNderflow....!");
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char str[MAX];
    printf("\nEnter a string : ");
    gets(str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            push(str[i]);
        }
        else
        {
            while (top != -1)
            {
                printf("%c", pop());
            }
            printf(" ");
        }
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
}