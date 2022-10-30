#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int data;
    struct Tree *lc, *rc;
};

void build_tree(struct Tree *ptr)
{
    struct Tree *New;

    int c = 0;
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->lc = NULL;
    ptr->rc = NULL;
    printf("Add left child for %d: (1/0)", ptr->data);
    scanf("%d", &c);
    if (c == 1)
    {
        New = (struct Tree *)malloc(sizeof(struct Tree));
        ptr->lc = New;
        build_tree(New);
    }
    printf("Add right child for %d: (1/0)", ptr->data);
    scanf("%d", &c);
    if (c == 1)
    {
        New = (struct Tree *)malloc(sizeof(struct Tree));
        ptr->rc = New;
        build_tree(New);
    }
}

void in(struct Tree *p)
{
    if (p == NULL)
    {
        return;
    }

    in(p->lc);
    printf("%d ", p->data);
    in(p->rc);
}
void pre(struct Tree *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    printf("%d ", ptr->data);
    in(ptr->lc);
    in(ptr->rc);
}
void post(struct Tree *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    in(ptr->lc);
    in(ptr->rc);
    printf("%d ", ptr->data);
}

void main()
{
    struct Tree *Root;
    Root = (struct Tree *)malloc(sizeof(struct Tree));
    build_tree(Root);
    in(Root);
    printf("\n");
    pre(Root);
    printf("\n");
    post(Root);
    printf("\n");
}