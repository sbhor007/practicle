/*
Write menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Traverse it by using Inorder and Preorder traversing technique
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

int menu()
{
    int ch;
    printf("\n1. Create Tree\n2. Inorder\n3. Postorder\n4. exit.");
    printf("\nEnter Choice : ");
    scanf("%d", &ch);
    return ch;
}

tree *getnode()
{
    tree *newnode = (tree *)malloc(sizeof(tree));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->leftAdd = newnode->rightAdd = NULL;
    return newnode;
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
            if (root->leftAdd == NULL)
            {
                root->leftAdd = newnode;
            }
            else
            {
                create(root->leftAdd, newnode);
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
                create(root->rightAdd, newnode);
            }
        }
        else if (root->data == newnode->data)
        {
            printf("\nDuplicate elements are not allow\n");
        }
    }
    return root;
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
                printf("\nWant to again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            break;
        case 4:
            return 0;
        }
    }
}