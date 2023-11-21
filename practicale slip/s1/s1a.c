/* Write menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Insert element in a Binary Search Tree
- Displ*/

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
tree *newnode = NULL;
tree *temp;

tree *getnode(int no)
{
    newnode = (tree *)malloc(sizeof(tree));
    newnode->data = no;
    newnode->leftAdd = newnode->rightAdd = NULL;
    return newnode;
}

int menu()
{
    int ch;
    printf("\n1. Create Tree\n2. Insert Element\n3. Display\n4. exit");
    printf("\n----------------");
    printf("\nEnter Choise : ");
    scanf("%d", &ch);
    return ch;
}

tree *create(tree *r, tree *new)
{
    if (r == NULL)
    {
        r = new;
    }
    else
    {
        if (r->data > new->data)
        {
            if (r->leftAdd == NULL)
            {
                r->leftAdd = new;
            }
            else
            {
                create(r->leftAdd, new);
            }
        }
        else if (r->data < new->data)
        {
            if (r->rightAdd == NULL)
            {
                r->rightAdd = new;
            }
            else
            {
                create(r->rightAdd, new);
            }
        }
        else if (r->data == new->data)
        {
            printf("\nDuplicate Element are not allow\n");
        }
    }
    return r;
}

tree *display(tree *r)
{
    if (r != NULL)
    {
        display(r->leftAdd);
        printf("%5d", r->data);
        display(r->rightAdd);
    }
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
                printf("\nEnter Data :");
                scanf("%d", &no);
                newnode = getnode(no);
                root = create(root, newnode);
                printf("\nWant to again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            printf("\nEnter Data : ");
            scanf("%d", &no);
            newnode = getnode(no);
            root = create(root, newnode);
            break;
        case 3:
            display(root);
            break;
        case 4:
            exit(0);

        default:
            printf("\nPlease Enter Valid input....!\n");
        }
    }
    return 0;
}