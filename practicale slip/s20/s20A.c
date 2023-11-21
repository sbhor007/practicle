/*
 Write a ‘C’ program which accept the string and check whether the string is
Palindrome or not using stack. (Use Static/Dynamic implementation of Stack)
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow....");
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
int check_str_palindrome(char *str)
{
    char ch;
    int flag = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if ((ch = pop()) != str[i])
        {
            return flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    return flag;
}

int main()
{
    char str[MAX];
    printf("\nEnter a string : ");
    // gets(str);
    scanf("%s", str);
    int r = check_str_palindrome(str);
    if (r == 0)
    {
        printf("\nstring is palindrome...");
    }
    else
    {
        printf("\nstring is not palindrome...");
    }
    return 0;
}