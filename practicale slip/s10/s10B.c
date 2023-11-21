/*
 Write a ‘C’ program to sort randomly generated array elements using
Insertion sort method. (Use Random Function)
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void display(int a[], int no)
{
    for (int i = 0; i < no; i++)
        printf("%5d", a[i]);
}
void random_array(int a[], int no)
{
    for (int i = 0; i < no; i++)
        a[i] = rand() % 100;
}

void insertion_Sort(int a[], int no)
{
    for (int i = 1; i < no; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int no;
    printf("\nenter the no. elements to generate randome array : ");
    scanf("%d", &no);
    int a[no];
    random_array(a, no);
    printf("\nRandome Array Elements : ");
    display(a, no);
    printf("\nAfter Sorting : ");
    insertion_Sort(a, no);
    display(a, no);
    return 0;
}
