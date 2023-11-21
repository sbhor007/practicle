/*
Write a ‘C’ program to accept names from the user and sort in alphabetical order
using bubble sort - Accept n name
- Bubble sort Function
- Display
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void acceptName(char name[][10], int no)
{
    for (int i = 0; i < no; i++)
    {
        scanf("%s", &name[i]);
    }
}

void display(char name[][10], int no)
{
    for (int i = 0; i < no; i++)
        printf("%s\t", name[i]);
}

void bsort(char name[][10], int no)
{
    char temp[10];
    for (int i = 0; i < no - 1; i++)
    {
        for (int j = 0; j < no - i - 1; j++)
        {
            if (strcmp(name[j], name[j + 1]) > 0)
            {
                strcpy(temp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], temp);
            }
        }
    }
}

int main()
{
    int no;
    printf("\nHow many Student Name store in a array : ");
    scanf("%d", &no);
    char name[no][10];
    printf("\nEnter the student name : \n");
    acceptName(name, no);
    printf("\nOriginal order of student name : \n");
    display(name, no);
    printf("\nAfter sorting student names : \n");
    bsort(name, no);
    display(name, no);
    return 0;
}