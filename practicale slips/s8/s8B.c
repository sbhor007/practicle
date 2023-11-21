/*
Write a ‘C’ program to accept and sort n elements in ascending order by using
insertion sort.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void acceptArr(int arr[], int no)
{
    for (int i = 0; i < no; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void displayArr(int arr[], int no)
{
    for (int i = 0; i < no; i++)
    {
        printf("%5d", arr[i]);
    }
}

void insertionSort(int arr[], int no)
{
    for (int i = 0; i < no; i++)
    {
        int min = i;
        for (int j = i + 1; j < no; j++)
        {
            if (arr[j] < arr[min])
                min = arr[j];
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int no;
    printf("\nHow many element to store in array : ");
    scanf("%d", &no);
    int arr[no];
    printf("\nEnter array elements : ");
    acceptArr(arr, no);
    printf("\nOroginal array\n");
    displayArr(arr, no);
    printf("\nSorted array\n");
    insertionSort(arr, no);
    displayArr(arr, no);
    return 0;
}