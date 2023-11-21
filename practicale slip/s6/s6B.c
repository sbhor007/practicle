/*
Write a ‘C’ program to accept and sort n elements in ascending order by using
bubble sort
*/
#include <stdio.h>
#include <conio.h>

void accept_array(int a[], int no)
{
    printf("Enter a Element : \n");
    for (int i = 0; i < no; i++)
        scanf("%d", &a[i]);
}
void dispay(int a[], int no)
{
    for (int i = 0; i < no; i++)
        printf("%5d", a[i]);
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
    printf("\nHow manny elements are entered : ");
    scanf("%d", &no);
    int a[no];
    accept_arrayS(a, no);
    printf("\nOriginal array\n");
    dispay(a, no);
    // sorting
    bsort(a, no);
    printf("\nSorted array\n");
    dispay(a, no);
    return 0;
}