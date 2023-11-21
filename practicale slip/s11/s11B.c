/*
Write a menu driven program using ‘C’ for Dynamic implementation of Queue for
integers. The menu includes - Insert - Delete
- Display
- Exit
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *nextAdd;
};

typedef struct queue Q;

Q *front = NULL;
Q *rear = NULL;

Q *getnode(int data)
{
    Q *newnode = (Q *)malloc(sizeof(Q));
    newnode->data = data;
    newnode->nextAdd = NULL;
    return newnode;
}

void enQueue(Q *newnode)
{
    if (rear == NULL)
    {
        rear = newnode;
        front = newnode;
    }
    else
    {
        rear->nextAdd = newnode;
        rear = newnode;
    }
}

void deQueue()
{
    if (front == NULL)
    {
        printf("\nQueue was empty");
        rear = NULL;
    }
    else
    {
        Q *temp = front;
        front = front->nextAdd;
        printf("\n%d element was deleted", temp->data);
        free(temp);
    }
}
void display()
{
    Q *temp = front;
    if (front == NULL)
    {
        printf("\nQueue was empty");
    }
    else
    {
        while (temp)
        {
            printf("%5d", temp->data);
            temp = temp->nextAdd;
        }
    }
}

int menu()
{
    int ch;
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
    printf("\nEnter Choice : ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    int no;
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("\nEnter data : ");
            scanf("%d", &no);
            enQueue(getnode(no));
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("\nInvalid input");
        }
    }
}