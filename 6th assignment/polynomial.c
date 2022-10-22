#include <stdio.h>
#include <stdlib.h>
struct node
{
    int co, ex;
    struct node *n1;
} * NEW1, *h1, *ptr;
struct Node
{
    int co, ex;
    struct Node *n2;
} * NEW2, *h2, *Ptr;
struct addition
{
    int co, ex;
    struct addition *NEXT;
    struct addition *sum;
    struct addition *insert;
} * NEW, *HEAD, *p;
int p1()
{
    h1 = NULL;
    NEW1 = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter coefficient and power:");
    scanf("%d %d", &NEW1->co, &NEW1->ex);
    NEW1->n1 = NULL;
    h1 = NEW1;
    ptr = h1;
    int i;
    printf("\nadd more by pressing 1:");
    scanf("%d", &i);
    while (i == 1)
    {
        NEW1 = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter coefficient and power:");
        scanf("%d %d", &NEW1->co, &NEW1->ex);
        NEW1->n1 = NULL;
        ptr->n1 = NEW1;
        ptr = NEW1;
        printf("\nadd more by pressing 1:");
        scanf("%d", &i);
    }
    printf("p1=");
    ptr = h1;
    while (ptr->n1 != NULL)
    {
        printf("%dx^%d+", ptr->co, ptr->ex);
        ptr = ptr->n1;
    }
    printf("%dx^%d", ptr->co, ptr->ex);
}
int p2()
{
    h2 = NULL;
    NEW2 = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter coefficient and power:");
    scanf("%d %d", &NEW2->co, &NEW2->ex);
    NEW2->n2 = NULL;
    h2 = NEW2;
    Ptr = h2;
    int i;
    printf("\nadd more by pressing 1:");
    scanf("%d", &i);
    while (i == 1)
    {
        NEW2 = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter coefficient and power:");
        scanf("%d %d", &NEW2->co, &NEW2->ex);
        NEW2->n2 = NULL;
        Ptr->n2 = NEW2;
        Ptr = NEW2;
        printf("\nadd more by pressing 1:");
        scanf("%d", &i);
    }
    printf("p2=");
    Ptr = h2;
    while (Ptr->n2 != NULL)
    {
        printf("%dx^%d+", Ptr->co, Ptr->ex);
        Ptr = Ptr->n2;
    }
    printf("%dx^%d", Ptr->co, Ptr->ex);
}
int addition()
{
    HEAD = NULL;
    NEW = (struct addition *)malloc(sizeof(struct addition));
    NEW->NEXT = NULL;
    HEAD = NEW;
    p = HEAD;
    ptr = h1;
    Ptr = h2;
    if (ptr->ex == Ptr->ex)
    {
        HEAD = NULL;
        NEW = (struct addition *)malloc(sizeof(struct addition));
        NEW->co = ptr->co + Ptr->co;
        NEW->ex = ptr->ex;
        NEW->NEXT = NULL;
        HEAD = NEW;
        p = HEAD;
        ptr = ptr->n1;
        Ptr = Ptr->n2;
    }
    else if (ptr->ex > Ptr->ex)
    {

        HEAD = NULL;
        NEW = (struct addition *)malloc(sizeof(struct addition));
        NEW->co = ptr->co;
        NEW->ex = ptr->ex;
        NEW->NEXT = NULL;
        HEAD = NEW;
        p = HEAD;
        ptr = ptr->n1;
    }
    else
    {

        HEAD = NULL;
        NEW = (struct addition *)malloc(sizeof(struct addition));
        NEW->co = Ptr->co;
        NEW->ex = Ptr->ex;
        NEW->NEXT = NULL;
        HEAD = NEW;
        p = HEAD;
        Ptr = Ptr->n2;
    }
    while (ptr != NULL && Ptr != NULL)
    {
        if (ptr->ex == Ptr->ex)
        {

            NEW = (struct addition *)malloc(sizeof(struct addition));
            NEW->co = ptr->co + Ptr->co;
            NEW->ex = ptr->ex;
            NEW->NEXT = NULL;
            p->NEXT = NEW;
            p = NEW;
            ptr = ptr->n1;
            Ptr = Ptr->n2;
        }
        else if (ptr->ex > Ptr->ex)
        {
            NEW = (struct addition *)malloc(sizeof(struct addition));
            NEW->co = ptr->co;
            NEW->ex = ptr->ex;
            NEW->NEXT = NULL;
            p->NEXT = NEW;
            p = NEW;
            ptr = ptr->n1;
        }
        else
        {
            NEW = (struct addition *)malloc(sizeof(struct addition));
            NEW->co = Ptr->co;
            NEW->ex = Ptr->ex;
            NEW->NEXT = NULL;
            p->NEXT = NEW;
            p = NEW;
            Ptr = Ptr->n2;
        }
    }
    while (ptr != NULL)
    {
        // HEAD=insert(HEAD,ptr->ex,ptr->co);
        NEW = (struct addition *)malloc(sizeof(struct addition));
        NEW->co = ptr->co;
        NEW->ex = ptr->ex;
        NEW->NEXT = NULL;
        p->NEXT = NEW;
        p = NEW;
        ptr = ptr->n1;
    }
    while (Ptr != NULL)
    {
        NEW = (struct addition *)malloc(sizeof(struct addition));
        NEW->co = Ptr->co;
        NEW->ex = Ptr->ex;
        NEW->NEXT = NULL;
        p->NEXT = NEW;
        p = NEW;
        Ptr = Ptr->n2;
    }
    printf("Hence sum is pf=");
    p = HEAD;
    while (p->NEXT != NULL)
    {
        printf("%dx^%d+", p->co, p->ex);
        p = p->NEXT;
    }
    printf("%dx^%d", p->co, p->ex);
}

int main()
{
    printf("lets make first polynomial:\n");
    p1();
    printf("\nlets make second polynomial:\n");
    p2();
    printf("\n lets do sum\n");

    addition(h1, HEAD);
}