/*
Write a ‘C’ program to create doubly link list 
and display nodes having odd value
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct dlink
{
    struct dlink *prevAdd;
    int data;
    struct dlink *nextAdd;
};
typedef struct dlink node;
node *temp;

node *getnode()
{
    node *newnode = (node*)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d",&newnode->data);
    newnode->nextAdd = newnode->prevAdd = NULL;
    return newnode;
}

node *create(node *start,node *newnode)
{
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while(temp->nextAdd != NULL)
        {
            temp = temp->nextAdd;
        }
        newnode->prevAdd=temp;
        temp->nextAdd = newnode;

    }
    return start;
}

void display(node *start)
{
    temp = start;
    if(start == NULL)
    {
        printf("\nList was empty....!");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->nextAdd;
        }
    }
}
void reverse(node *start)
{
    temp = start;
    if(start == NULL)
    {
        printf("\nList was empty....!");
    }
    else
    {
        while(temp->nextAdd != NULL)
        {
            temp = temp->nextAdd;
        }
        while(temp != NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->prevAdd;
        }
        
    }
}

void dislayOddValue(node *start)
{
    temp = start;
    if(start == NULL)
    {
        printf("\nLisr was empty...!");
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data % 2 != 0)
                printf("%d-->",temp->data);
                temp = temp->nextAdd;
        }
    }
}

int main()
{
    node *start = NULL;
    char ch;
    do{
        start = create(start,getnode());
        printf("\nWant to again (y/n) : ");
        ch = getche();
    }while(ch == 'y' || ch == 'Y');
    display(start);
    printf("\n\nOdd elements : ");
    dislayOddValue(start);
    // reverse(start);
    return 0;
}
