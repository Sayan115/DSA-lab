#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void create(struct node *head)
{
    struct node *ptr;
    struct node *new;
    ptr = head;
    printf("wanna enter more number y or n ");
    char ch;
    scanf(" %c", &ch);
    while (ch == 'y')
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("enter the value ");
        scanf("%d", &new->data);
        ptr->next = new;
        new->next = NULL;
        ptr = ptr->next;
        printf("wanna enter more number y or n ");
        scanf(" %c", &ch);
    }
}

void print(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void insertAtFirst(struct node *head)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->next = head;
    head = new;
    printf("enter the value of new block ");
    scanf("%d", &new->data);
    printf("new list is ");
    print(head);
}
void insertAtLast(struct node *head)
{
    struct node *new;
    struct node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter the value in new block ");
    scanf("%d", &new->data);
    new->next = NULL;
    ptr->next = new;
    print(head);
}
void insertAtPos(struct node *head)
{
    struct node *new;
    struct node *ptr;
    ptr = head;
    new = (struct node *)malloc(sizeof(struct node));
    int count = 1;
    printf("enter you wanna insert at which postion ");
    int p;
    scanf("%d", &p);
    while (ptr != NULL && count != p - 1)
    {
        ptr = ptr->next;
        count++;
    }
    new->next = ptr->next;
    printf("enter the value you wanna insert ");
    scanf("%d", &new->data);
    ptr->next = new;
    print(head);
}
int main()
{
    struct node *head;
    struct node *new;
    head = NULL;
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter the value ");
    scanf("%d", &new->data);
    new->next = NULL;
    head = new;

    create(head);
    printf("\nthe list is ");
        print(head);
    printf("\nwhere do you wanna insert, at first, last place or at a postion respond with 1,2,3 ");
    int op;
    scanf("%d", &op);
    switch (op)
    {
    case 1:
    {
        printf("\ninsertion at first place \n");
        insertAtFirst(head);
    }
    case 2:
    {
        printf("\ninsertion at last place \n");
        insertAtLast(head);
    }
    case 3:
    {
        insertAtPos(head);
    }
    }
    return 0;
}