/* Write menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Display
- Delete a given element from Binary Search Tree
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

tree *getnode(int no)
{
    tree *newnode = (tree *)malloc(sizeof(tree));
    newnode->data = no;
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
        else
        {
            printf("\nduplicate elements are not allow");
        }
    }
    return root;
}

void display(tree *root)
{
    if (root != NULL)
    {
        display(root->leftAdd);
        printf("%5d", root->data);
        display(root->rightAdd);
    }
}

tree *minVal(tree *root)
{
    tree *temp = root;
    if (temp != NULL && temp->leftAdd != NULL)
    {
        temp = temp->leftAdd;
    }
    return temp;
}

tree *deleteNode(tree *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->leftAdd = deleteNode(root->leftAdd, key);
    }
    else if (key > root->data)
    {
        root->rightAdd = deleteNode(root->rightAdd, key);
    }
    else
    {
        if (root->leftAdd == NULL)
        {
            tree *temp = root->rightAdd;
            free(root);
            return temp;
        }
        else if (root->rightAdd == NULL)
        {
            tree *temp = root->leftAdd;
            free(root);
            return temp;
        }
        tree *temp = minVal(root->rightAdd);
        root->data = temp->data;
        root->rightAdd = deleteNode(root->rightAdd, temp->data);
    }
    return root;
}

tree *delete(tree *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->leftAdd = delete (root->leftAdd, key);
    }
    else if (key > root->data)
    {
        root->rightAdd = delete (root->rightAdd, key);
    }
    else
    {
        if (root->leftAdd == NULL)
        {
            tree *temp = root->rightAdd;
            free(root);
            return temp;
        }
        else if (root->rightAdd == NULL)
        {
            tree *temp = root->leftAdd;
            free(root);
            return temp;
        }
        tree *temp = minVal(root->rightAdd);
        root->data = temp->data;
        root->rightAdd = delete (root->rightAdd, temp->data);
    }
    return root;
}

int menu()
{
    int ch;
    printf("\n1. Create Tree\n2. display Tree\n3. delete node\n4. exit");
    printf("\nEnter A Choise : ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    int no, key;
    char ch;
    tree *root = NULL;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                printf("\nEnter Data : ");
                scanf("%d", &no);
                root = create(root, getnode(no));
                printf("\nWant to again (y/n) : ");
                ch = getche();
            } while (ch == 'Y' || ch == 'y');
            break;
        case 2:
            display(root);
            break;
        case 3:
            if (root != NULL)
            {
                printf("\nEnter The element to delete : ");
                scanf("%d", &key);
                root = delete (root, key);
            }
            else
            {
                printf("\nTree not Exist");
            }
            break;
        case 4:
            return 0;
        default:
            printf("\nInvalid input");
        }
    }
}