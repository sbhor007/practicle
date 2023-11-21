/*
Write menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Traverse it by using Preorder and Postorder traversing technique
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct TREE
{
    struct TREE *leftAdd;
    int data;
    struct TREE *rightAdd;
};
typedef struct TREE tree;

tree *getnode()
{
    tree *newnode = (tree *)malloc(sizeof(tree));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->leftAdd = newnode->rightAdd = NULL;
    return newnode;
}

int menu()
{
    int ch;
    printf("\n1. Create tree\n2. Preorder traversing\n3. Postorder traversing\n4. Exit");
    printf("\nEnter Choice : ");
    scanf("%d", &ch);
    return ch;
}

tree *create(tree *root, tree *newnode)
{
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        if (root->data > newnode->data)
        {
            (root->leftAdd == NULL) ? root->leftAdd = newnode : create(root->leftAdd, newnode);
        }
        else if (root->data < newnode->data)
        {
            (root->rightAdd == NULL) ? root->rightAdd = newnode : create(root->rightAdd, newnode);
        }
        else if (root->data == newnode->data)
        {
            printf("\nDuplicate Elements are not allow\n");
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
void postorder(tree *root)
{
    if (root != NULL)
    {
        preorder(root->leftAdd);
        preorder(root->rightAdd);
        printf("%5d", root->data);
    }
}

int main()
{
    char ch;
    tree *root = NULL;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                root = create(root, getnode());
                printf("\nWant To Again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            return 0;
        default:
            printf("\nInvalid Input\nPlease Tray Again\n");
        }
    }
}