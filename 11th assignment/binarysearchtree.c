#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
void insert(struct node *new, struct node *temp)
{
    struct node *ptr = temp;
    if (new->data > ptr->data)
    {
        if (ptr->right == NULL)
        {
            ptr->right = new;
            return;
        }
        insert(new, ptr->right);
    }
    else
    {
        if (ptr->left == NULL)
        {
            ptr->left = new;
            return;
        }
        insert(new, ptr->left);
    }
}
void createTree()
{
    int Data;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->left = NULL;
    new->right = NULL;
    printf("Enter data: ");
    scanf("%d", &Data);
    new->data = Data;
    if (root == NULL)
    {
        root = new;
        return;
    }
    insert(new, root);
}

void PreOrder(struct node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    printf("%d\t", Root->data);
    PreOrder(Root->left);
    PreOrder(Root->right);
}
void PostOrder(struct node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    PostOrder(Root->left);
    PostOrder(Root->right);
    printf("%d\t", Root->data);
}

void inOrder(struct node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    inOrder(Root->left);
    printf("%d\t", Root->data);
    inOrder(Root->right);
}

int main()
{
    createTree();
    int op = 1;

    while (op == 1)
    {
        printf("Do you want to add another element(1/0):");
        scanf("%d", &op);
        if (op == 1)
            createTree();
    }
    inOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");
    PreOrder(root);
}