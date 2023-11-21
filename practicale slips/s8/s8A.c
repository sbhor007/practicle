/*
Write menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Display
- Search the element in Binary Search Tree
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

struct tree *getnode(int no)
{
    struct tree *newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->data = no;
    newnode->leftAdd = newnode->rightAdd = NULL;
    return newnode;
}

struct tree *createBST(struct tree *root, struct tree *newnode)
{
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        if (root->data > newnode->data)
        {
            if (root->leftAdd == NULL)
            {
                root->leftAdd = newnode;
            }
            else
            {
                root->leftAdd = createBST(root->leftAdd, newnode);
            }
        }
        else if (root->data < newnode->data)
        {
            if (root->rightAdd == NULL)
            {
                root->rightAdd = newnode;
            }
            else
            {
                root->rightAdd = createBST(root->rightAdd, newnode);
            }
        }
        else if (root->data == newnode->data)
        {
            printf("\nDuplicate elements are not allow");
        }
    }
    return root;
}

void display(struct tree *root)
{
    if (root != NULL)
    {
        display(root->leftAdd);
        printf("%5d", root->data);
        display(root->rightAdd);
    }
}

struct tree *searchBST(struct tree *root, int key)
{
    int flag = 0;
    if (root == NULL)
        return flag;
    else if (root->data == key)
    {
        return flag = 1;
    }
    else if (root->data > key)
    {
        searchBST(root->leftAdd, key);
    }
    else if (root->data < key)
    {
        searchBST(root->rightAdd, key);
    }
}

int menu()
{
    int ch;
    printf("\n1. Create BST\n2. Display\n3. Search Element on BST\n4. Exit");
    printf("\nEnter Choice : ");
    scanf("%d", &ch);
    return ch;
}

int main()
{
    int no, key;
    char ch;
    struct tree *root = NULL;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                printf("\nEnter data : ");
                scanf("%d", &no);
                root = createBST(root, getnode(no));
                printf("\nWant to again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            display(root);
            break;
        case 3:
            if (root != NULL)
            {
                printf("\nEnter The element to search : ");
                scanf("%d", &key);
                if (searchBST(root, key) == 1)
                {
                    printf("\nElement present");
                }
                else
                {
                    printf("\nElement not present");
                }
            }
            else
            {
                printf("\nTree not exist");
            }
            break;
        case 4:
            return 0;
        default:
            printf("\nInvalid input");
            break;
        }
    }
}