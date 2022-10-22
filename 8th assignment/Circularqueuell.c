#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *front, *rear;

void CQinsert()
{
    int item;
    printf("Enter element: ");
    scanf("%d", &item);

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    if (front == NULL)
    {
        front = new;
        rear = new;
    }

    else
    {
        rear->next = new;
        rear = new;
    }
    new->val = item;
    new->next = front;
}

void CQdel()
{
    if (front == NULL)
        printf("QUEUE UNDERFLOW\n");

    else
    {
        printf("%d removed from queue\n", front->val);
        struct Node *temp = front;

        if (front == rear)
            front = rear = NULL;
        else
        {
            front = front->next;
            rear->next = front;
        }
        free(temp);
    }
}

void CQtraverse()
{
    if (front == NULL)
        printf("Queue is empty");
    else
    {
        struct Node *ptr = front;
        do
        {
            printf("%d ", ptr->val);
            ptr = ptr->next;
        } while (ptr != front);
    }
    printf("\n");
}
int main()
{

    int t;
    front = rear = NULL;
    printf("1->insert\n2->delete\n3->traverse\n");
    scanf("%d", &t);
    while (t == 1 || t == 2 || t == 3)
    {

        switch (t)
        {
        case 1:
            CQinsert();
            break;
        case 2:
            CQdel();
            break;
        case 3:
            CQtraverse();
            break;
        default:
            break;
        }
        printf("Choice: ");
        scanf("%d", &t);
    };
    return 0;
}