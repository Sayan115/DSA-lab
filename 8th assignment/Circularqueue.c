#include <stdio.h>
int queue[100], rear = -1, front = -1, size;
void cqinsert(int item)
{
    if ((front == (rear + 1) % size )|| rear == size-1)
    {
        printf("Overflow");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = item;
    }
}

int deque()
{
    int value;
    if (front == -1 && rear == -1)
    {
        printf("Underflow");
    }
    else if (front == rear)
        front = rear - 1;
    else
    {
        value = queue[front];
        front = (front + 1) % size;
        return value;
    }
}

void traverse()
{
    for (int i = front; i != rear; i = (i + 1) % size)
    {
        printf("%d ", queue[i]);
    }
    printf("%d", queue[rear]);
}

int main()
{
    printf("Enter the number of lists: ");
    scanf("%d", &size);
    int t = 0;
    queue[size];
    printf("1->insert\n2->delete\n3->traverse\n");
    scanf("%d", &t);
    while (t == 1 || t == 2 || t == 3)

    {
        if (t == 1)
        {
            printf("Enter number:");
            scanf("%d", &t);
            cqinsert(t);
            printf("Enter choice: ");
            scanf("%d", &t);
        }
        else if (t == 2)
        {
            printf("%d\n", deque());
            printf("Enter choice: ");
            scanf("%d", &t);
        }

        else if (t == 3)
        {
            traverse();
            printf("Enter choice: ");
            scanf("%d", &t);
        }
    }
}
