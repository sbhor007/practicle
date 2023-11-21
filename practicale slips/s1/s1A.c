/*
) Write menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Insert element in a Binary Search Tree
- Displa
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct tree
{
    struct tree *leftAdd;
    int data;
    struct tree *rightAdd;
};

int menu()
{
    int ch;
    printf("\n1. Create\n2. Insert Element\n3. Search\n4. display\n5. Exit");
    printf("n\nEnter a choice : ");
    scanf("%d", &ch);
    return ch;
}

struct tree *getnode(struct tree *r)
{
    struct tree *newnode = (struct tree *)malloc(sizeof(struct tree));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->leftAdd = newnode->rightAdd = NULL;
    return newnode;
}
struct tree *create(struct tree *r, struct tree *newnode)
{
    if (r == NULL)
    {
        r = newnode;
    }
    else
    {
        if (r->data > newnode->data)
        {
            if (r->leftAdd == NULL)
                r->leftAdd = newnode;
            else
            {
                create(r->leftAdd, newnode);
            }
        }
        else if (r->data < newnode->data)
        {
            if (r->rightAdd == NULL)
                r->rightAdd = newnode;
            else
                create(r->rightAdd, newnode);
        }
        else if (r->data == newnode->data)
        {
            printf("\nDuplicate elements are not allow...!\n");
        }
    }
    return r;
}

void display(struct tree *r)
{
    if (r != NULL)
    {
        display(r->leftAdd);
        printf("%5d", r->data);
        display(r->rightAdd);
    }
}

int search(struct tree *r, int key)
{
    int flag = 0;
    struct tree *temp;
    if(r == NULL)
    {
        return flag;
    }

    if (r->data == key)
    {
        return flag = 1;
    }
    else if (r->data > key)
    {
        search(r->leftAdd, key);
    }
    else if (r->data < key)
    {
        search(r->rightAdd, key);
    }
}

int main()
{
    struct tree *root = NULL;
    char ch;
    int key, result;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                root = create(root, getnode(root));
                printf("\nWant to again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            root = create(root, getnode(root));
            break;
        case 3:
            printf("\nEnter Element to search : ");
            scanf("%d", &key);
            result = search(root, key);
            if (result == 0)
            {
                printf("\nElement not present");
            }
            else
                printf("\nelement present");
            break;
        case 4:
            display(root);
            break;
        case 5:
            return 0;
        }
    }
}
