/*
Write menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Traverse it by using Inorder and Preorder traversing technique
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

void preorder(tree *root)
{
    if (root != NULL)
    {
        printf("%5d", root->data);
        preorder(root->leftAdd);
        preorder(root->rightAdd);
    }
}

void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->leftAdd);
        printf("%5d", root->data);
        inorder(root->rightAdd);
    }
}

int menu()
{
    int ch;
    printf("\n1. Create tree\n2. Inorder\n.3. preorder\n4. exit");
    printf("\n------------");
    printf("\nEnter a choise : ");
    scanf("%d", &ch);
    return ch;
}

int main()
{
    tree *root = NULL;
    int no;
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
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            break;
        default:
            printf("\nInvalid Choise...\n");
        }
    }
}