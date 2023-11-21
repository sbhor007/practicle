/*
 Write a ‘C’ program to accept and sort n elements
  in ascending order by using insertion sort.
*/

#include <stdio.h>
#include <conio.h>

void accept_array(int a[], int no)
{
    printf("\nEnter array elements : ");
    for (int i = 0; i < no; i++)
        scanf("%d", &a[i]);
}
void display(int a[], int no)
{
    for (int i = 0; i < no; i++)
        printf("%5d", a[i]);
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
    printf("\nHow many elements to enter : ");
    scanf("%d", &no);
    int a[no];
    accept_array(a, no);
    printf("\nOriginal array : ");
    display(a, no);
    printf("\nSorted Array : ");
    insertion_Sort(a, no);
    display(a, no);
    return 0;
}