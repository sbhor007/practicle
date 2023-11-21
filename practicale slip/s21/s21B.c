/*
Write a ‘C’ program Accept n elements from user store it in an array.
Accept a value from the user and use linear/Sequential search method
to check whether the value is present in array or not. Display proper message
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void accept(int a[], int no)
{
    printf("\nEnter Array Elements : ");
    for (int i = 0; i < no; i++)
    {
        scanf("%d", &a[i]);
    }
}
void display(int a[], int no)
{
    for (int i = 0; i < no; i++)
        printf("%5d", a[i]);
}

int search(int a[], int no, int key)
{
    // int flag = 0;
    for (int i = 0; i < no; i++)
    {
        if (key == a[i])
        {
            return i+1;
        }
    }
    return -1;
}

int main()
{
    int no;
    printf("\nEnter no of elements in a array : ");
    scanf("%d", &no);
    int a[no];
    accept(a, no);
    printf("\nArray elements\n");
    display(a, no);
    int key;
    printf("\nEnter Element To search : ");
    scanf("%d", &key);
    int pos = search(a, no, key);
    if (pos == -1)
    {
        printf("\n%d is not present...!");
    }
    else
    {
        printf("\n%d is present at %d possition.", key, pos);
    }
    return 0;
}