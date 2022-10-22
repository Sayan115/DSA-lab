#include <stdio.h>
int MAX_SIZE = 20;
int push(int stack[], int f)
{
    if (f >= MAX_SIZE - 1)
    {
        printf("OVERFLOW\n");
        return f;
    }
    int n;
    printf("Enter data: ");
    scanf("%d", &n);
    stack[++f] = n;
    return f;
}
int pop(int stack[], int f)
{
    if (f == -1)
    {
        printf("UNDERFLOW\n");
        return f;
    }
    printf("Deleted element: %d\n", stack[f]);
    return --f;
}
void display(int stack[], int f)
{
    if (f == -1)
    {
        printf("EMPTY STACK");
        return;
    }
    for (int i = f; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int stack[MAX_SIZE];
    int f = -1;
    char choice;
    scanf(" %c", &choice);
    while (choice == 'Y' || choice == 'y')
    {
        f = push(stack, f);
        printf("Do you want to add (Y/N)\n");
        scanf(" %c", &choice);
    }
    int ch = 1;
    while (ch == 1 || ch == 2 || ch == 3)
    {
        printf("Enter 1 to push\n2 to pop \n3 to display stack\nEnter any other number to exit: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            f = push(stack, f);
        }
        else if (ch == 2)
        {
            f = pop(stack, f);
        }
        else if (ch == 3)
        {
            display(stack, f);
        }
        else
        {
            break;
        }
    }
}