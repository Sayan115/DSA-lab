// double ended queue
#include <stdio.h>

void fenqueue(int *front, int *rear, int *deque, int length)
{
    printf("Enter the value ");
    int val;
    scanf("%d", &val);
    if ((*rear + 1) % length == *front)
    {
        printf("Overflow ");
    }

    else if (*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
        deque[*front] = val;
    }
    else if (*front == 0)
    {
        if ((*rear + 1) % length == *front)
        {
            printf("Overflow");
            return;
        }
        *front = length - 1;
        deque[*front] = val;
    }

    else
    {
        *front = *front - 1;
        deque[*front] = val;
    }
}
void renqueue(int *front, int *rear, int *deque, int length)
{
    printf("Enter the value ");
    int val;
    scanf("%d", &val);
    if ((*rear + 1) % length == *front)
    {
        printf("Overflow");
    }

    else if (*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
        deque[*front] = val;
    }
    else
    {
        *rear = (*rear + 1) % length;
        deque[*rear] = val;
    }
}

void peek(int pos, int *deque)
{
    printf("\nElement is %d ", deque[pos]);
}
void fdequeue(int *front, int *rear, int *deque, int length)
{
    if (*front == -1 && *rear == -1)
    {
        printf("Underflow\n");
        return;
    }
    else if (*front == *rear)
    {
        peek(*front, deque);
        *front = -1;
        *rear = -1;
    }
    else
    {
        peek(*front, deque);
        *front = (*front + 1) % length;
    }
}

void rdequeue(int *front, int *rear, int *deque, int length)
{
    if (*front == -1 && *rear == -1)
    {
        printf("Underflow\n");
        return;
    }
    else if (*front == *rear)
    {
        peek(*front, deque);
        *front = -1;
        *rear = -1;
    }
    else if (*rear == 0)
    {
        peek(*rear, deque);
        *rear = length - 1;
    }
    else
    {
        peek(*rear, deque);
        *rear = (*rear - 1) % length;
    }
}

void show(int front, int rear, int *deque, int length)
{
    int i;
    if (front == -1)
    {
        printf("\n");
        return;
    }
    for (i = front; i != (rear + 1) % length; i = (i + 1) % length)
    {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main()
{
    int deque[10], front = -1, rear = -1, op1, op2;
    int length = sizeof(deque) / sizeof(deque[0]);
    do
    {
        printf("1.Enqueue\n2.Dequeue ");
        scanf("%d", &op1);
        if (op1 == 1)
        {
            printf("1.Front\n2.Rear ");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                fenqueue(&front, &rear, deque, length);
                printf("Queue is ");
                show(front, rear, deque, length);
            }
            else if (op2 == 2)
            {
                renqueue(&front, &rear, deque, length);
                printf("Queue is ");
                show(front, rear, deque, length);
            }
        }
        else if (op1 == 2)
        {
            printf("1.Front\n2.Rear");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                fdequeue(&front, &rear, deque, length);
                printf("Queue is ");
                show(front, rear, deque, length);
            }
            else if (op2 == 2)
            {
                rdequeue(&front, &rear, deque, length);
                printf("Queue is ");
                show(front, rear, deque, length);
            }
        }
    } while ((op1 == 1 || op1 == 2) && (op2 == 1 || op2 == 2));
}
