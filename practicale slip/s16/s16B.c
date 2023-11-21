/*
Write a ‘C’ program to accept the names of cities and store
them in array. Accept the city name from user and use linear
search algorithm to check whether the city is
present in array or not
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void accept(char str[][20], int no)
{
    printf("\nEnter a cityes :");
    for (int i = 0; i < no; i++)
    {
        scanf("%s", str[i]);
    }
}

int searchCiry(char str[][20], int no, char key[])
{
    int flag = 0;
    for (int i = 0; i < no; i++)
    {
        if (strcmp(str[i], key) == 0)
        {
            flag = i + 1;
        }
        else
        {
        }
    }
    if (flag != 0)
    {
        return flag;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int no, result;
    printf("\nHow Many Citi's To Enter : ");
    scanf("%d", &no);
    char city[no][20], key[20];
    // Accept city's
    accept(city, no);
    printf("\nEnter the City name to search : ");
    scanf("%s", key);
    // search  city
    result = searchCiry(city, no, key);
    if (result == -1)
    {
        printf("\n%s not present", key);
    }
    else
    {
        printf("\n%s present at %d position", key, result);
    }
    return 0;
}