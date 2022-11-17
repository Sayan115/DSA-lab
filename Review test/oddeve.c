#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *Head, *h1, *h2;
struct node *create(struct node *h, int d)
{
    struct node *New = (struct node *)malloc(sizeof(struct node));
    New->data = d;
    New->next = NULL;
    if (h == NULL)
    {
        h = New;
    }
    else
    {
        New->next = h;
        h = New;
    }
    return h;
}

void odd_even()
{
    struct node *p = Head;
    while (p != NULL)
    {
        int data = p->data;
        if (data % 2 == 0)
            h1 = create(h1, data);
        else
            h2 = create(h2, data);
        p = p->next;
    }
}

int main()
{
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    Head = NULL;
    Head = create(Head, d);
    int c = 0;
    printf("Enter 1 to enter more: ");
    scanf("%d", &c);
    while (c == 1)
    {
        printf("Enter data: ");
        scanf("%d", &d);
        Head = create(Head, d);

        scanf("%d", &c);
    }
    odd_even();
    printf("\n");
    struct node *p = h1;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    p = h2;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}