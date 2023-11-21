/*
 Write a ‘C’ program to accept a string from user and reverse it using Static
implementation of Stack
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

struct stack
{
    char strArr[MAX];
    int top;
};

void isInnitialize(struct stack *s)
{
    s->top = -1;
}

int isFull(struct stack *s)
{
    return (s->top == MAX - 1);
}
int isEmpty(struct stack *s)
{
    return (s->top == -1);
}

void push(struct stack *s, char ch)
{
    if (isFull(s))
    {
        printf("\nstack is full");
    }
    else
    {
        s->strArr[++s->top] = ch;
    }
}

char pop(struct stack *s)
{
    return s->strArr[s->top--];
}

void reverseStr(struct stack *s, char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            push(s, str[i]);
        }
        else
        {
            while (!isEmpty(s))
            {
                printf("%c", pop(s));
            }
            printf(" ");
        }
    }
    while (!isEmpty(s))
    {
        printf("%c", pop(s));
    }
}

int main()
{
    struct stack *s;
    isInnitialize(s);
    char str[MAX];
    printf("\nEnter the string to reverse : ");
    gets(str);
    reverseStr(s, str);
    return 0;
}