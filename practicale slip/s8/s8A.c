/*
Write menu driven program using ‘C’ for Binary Search Tree. The menu includes - Create a Binary Search Tree
- Display
- Search the element in Binary Search Tree
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Tree
{
    struct Tree *leftAdd;
    int data;
    struct Tree *rightAdd;
};
typedef struct Tree tree;
tree *newnode, *temp;

tree *getnode()
{
    newnode = (tree *)malloc(sizeof(tree));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->leftAdd = newnode->rightAdd = NULL;
    return newnode;
}

tree *create(tree *root, tree *new)
{
    if (root == NULL)
    {
        root = new;
    }
    else
    {
        if (new->data < root->data)
        {
            if (root->leftAdd == NULL)
            {
                root->leftAdd = new;
            }
            else
            {
                create(root->leftAdd, new);
            }
        }
        else
        {
            if (new->data > root->data)
            {
                if (root->rightAdd == NULL)
                {
                    root->rightAdd = new;
                }
                else
                {
                    create(root->rightAdd, new);
                }
            }
        }
    }
    return root;
}

int search(tree *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
            return key;
        else if (key < root->data)
        {
            return search(root->leftAdd, key);
        }
        else if (key > root->data)
        {
            return search(root->rightAdd, key);
        }
        return -1;
    }
}

void display(tree *root)
{
    if (root != NULL)
    {
        display(root->leftAdd);
        display(root->rightAdd);
        printf("%5d", root->data);
    }
}

int menu()
{
    int ch;
    printf("\n1. Create tree\n2. Display\n.3. search\n4. exit");
    printf("\n------------");
    printf("\nEnter a choise : ");
    scanf("%d", &ch);
    return ch;
}

int main()
{
    tree *root = NULL;
    int no, key, result;
    char ch;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                newnode = getnode();
                root = create(root, newnode);
                printf("\nWant To Again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            display(root);
            break;
        case 3:
            printf("\nEnter the element to search : ");
            scanf("%d", &key);
            result = search(root, key);
            if (key == result)
            {
                printf("\nElement Present.. ");
            }
            else
            {
                printf("\nelement not present");
            }
            break;
        case 4:
            break;
        default:
            printf("\nInvalid Choise...\n");
        }
    }
}