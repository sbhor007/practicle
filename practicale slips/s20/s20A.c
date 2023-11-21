/*
Write a ‘C’ program which accept the string and check whether the string is
Palindrome or not using stack. (Use Static/Dynamic implementation of Stack)
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

stack *push(stack *top, char ch)
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
    if (*top != NULL)
    {
        char ch;
        stack *temp = *top;
        *top = (*top)->nextAdd;
        ch = temp->data;
        free(temp);
        return ch;
    }
}

void checkPalindrome(char *str, stack **top)
{
    int flag = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        *top = push(*top, str[i]);
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != pop(top))
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("\n%s string is palindrom", str);
    }
    else
    {
        printf("\n%s string is not palindrom", str);
    }
}

int main()
{
    char str[20];
    stack *top = NULL;
    printf("\nEnter a string : ");
    gets(str);
    checkPalindrome(str, &top);
    return 0;
}
