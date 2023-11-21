/*
)Implement Static implementation of circular queue of integers with following
operation:
- Initialize(),insert(), delete(), isempty(), isfull(), display(
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *nextAdd;
};
typedef struct Queue queue;

int menu()
{
    int ch;
    printf("\n1. Insert\n2. delete\n3. display\n4. exit");
    printf("\nEnter a choice : ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    queue *front = NULL;
    queue *rear = NULL;
}