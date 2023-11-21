/*
Write a ‘C’ program to accept names from the user and sort in
alphabetical order using bubble sort
- Accept n name
- Bubble sort Function
- Display
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void acceptName(char a[][20], int no)
{
    for (int i = 0; i < no; i++)
    {
        scanf("%s", a[i]);
    }
}
void display(char a[][20], int no)
{
    for (int i = 0; i < no; i++)
        printf("\n%s", a[i]);
}

void bsort(char a[][20], int no)
{
    char temp[20];
    for (int i = 0; i < no - 1; i++)
    {
        for (int j = 0; j < no - i - 1; j++)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
                /*temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;*/
            }
        }
    }
}

int main()
{
    int no;
    printf("\nhow many NAME to enter : ");
    scanf("%d", &no);
    char a[no][20];
    printf("\nEnter Names \n");
    acceptName(a, no);
    printf("\n\nbefore sorting\n");
    display(a, no);
    printf("\n\nafter sorting...\n");
    bsort(a, no);
    display(a, no);
    return 0;
}