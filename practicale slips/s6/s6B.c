/*
Write a ‘C’ program to accept and sort n elements in ascending order by using
bubble sort.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void getElement(int a[], int no)
{
    for (int i = 0; i < no; i++)
    {
        printf("\nEnter Element NO %d : ", i + 1);
        scanf("%d", &a[i]);
    }
}
void display(int a[], int no)
{
    for (int i = 0; i < no; i++)
    {
        printf("%5d", a[i]);
    }
}

void bsort(int a[], int no)
{
    for (int i = 0; i < no - 1; i++)
    {
        for (int j = 0; j < no - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int no;
    printf("\nHow many elements enter : ");
    scanf("%d", &no);
    int a[no];
    printf("Enter array elements : \n");
    getElement(a, no);
    printf("\nOriginal array : ");
    display(a, no);
    printf("\nSorted array : ");
    bsort(a, no);
    display(a, no);
    return 0;
}