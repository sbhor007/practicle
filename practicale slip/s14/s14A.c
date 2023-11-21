/*
Write a ‘C’ program to accept a string from user and
reverse it using Dynamic implementation of Stack.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("\nmemory allocation fail...!");
        exit(11);
    }
    newnode->data = ch;
    newnode->nextAdd = NULL;
    if (top == NULL)
        top = newnode;
    else
    {
        newnode->nextAdd = top;
        top = newnode;
    }
}
char pop()
{
    char ch;
    if (top == NULL)
    {
        printf("\nsatck is empty...!");
    }
    else
    {
        temp = top;
        top = top->nextAdd;
        ch = temp->data;
        free(temp);
        return ch;
    }
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
        printf("%c", pop());
}
int main()
{
    char str[100];
    printf("\nEnter a string : ");
    gets(str);
    reverse(str);
    return 0;
}