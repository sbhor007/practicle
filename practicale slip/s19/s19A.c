/*
Write a ‘C’ program which accept the string and reverse
each word of the string using Dynamic implementation of stack.
 Example: Input - This is an input string
 Output - sihTsinatupnignirts
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct stack
{
    char data;
    struct stack *nextAdd;
};
struct stack *top = NULL;
struct stack *newnode, *temp;
void push(char ch)
{
    newnode = (struct stack *)malloc(sizeof(struct stack));
    newnode->data = ch;
    newnode->nextAdd = NULL;
    if (newnode == NULL)
    {
        printf("\nMemory allocation fail....!");
        exit(1);
    }
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
void reverse(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            push(str[i]);
        }
        else
        {
            while (top != NULL)
            {
                printf("%c", pop());
            }
            printf(" ");
        }
    }
    while (top != NULL)
    {
        printf("%c", pop());
    }
}
int main()
{
    char str[50];
    printf("Enter a string : ");
    gets(str);
    reverse(str);
    return 0;
}