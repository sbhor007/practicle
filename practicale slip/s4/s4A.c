/* Write menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Traverse it by using Inorder and Postorder traversing technique
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
        else if (new->data > root->data)
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
        else if (root->data == new->data)
        {
            printf("\nduplicate elements are not allow...!");
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

void postorder(tree *root)
{
    if (root != NULL)
    {
        postorder(root->leftAdd);
        postorder(root->rightAdd);
        printf("%5d", root->data);
    }
}

int menu()
{
    int ch;
    printf("\n1. Create Tree\n2. Inorder Traverse\n3. Postorder Traverse\n4. exit");
    printf("\n-----------");
    printf("\nEnter your Choise : ");
    scanf("%d", &ch);
    return ch;
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
                newnode = getnode();
                root = create(root, newnode);
                printf("Do you want to continue? Y/N : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            exit(0);
        default:
            printf("invalid input...!\n");
        }
    }
}