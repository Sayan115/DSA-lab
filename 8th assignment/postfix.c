#include <stdio.h>
#include <math.h>
int push(int *stack, int val, int top, int length)
{
    if (top == length - 1)
    {
        printf("overflow ");
    }
    else
    {
        top = top + 1;
        stack[top] = val;
    }
    return top;
}
int pop(int *stack, int *top)
{
    int p = *top;
    if (*top == -1)
    {
        printf("underflow");
    }
    else
    {
        *top = p - 1;
        return stack[p];
    }
}

int main()
{
    char val[50];
    int stack[50];
    int length = sizeof(stack) / sizeof(stack[0]);
    int top = -1;
    printf("Enter the expression ");
    scanf("%s", val);

    int i = 0;
    while (val[i] != '\0')
    {

        if (val[i] >= 48 && val[i] <= 57)
        {
            top = push(stack, val[i] - 48, top, length);
        }
        else if (val[i] == 42 || val[i] == 43 || val[i] == 45 || val[i] == 47 || val[i] == 94)
        {
            int a = pop(stack, &top);
            int b = pop(stack, &top);

            if (val[i] == '+')
            {
                top = push(stack, b + a, top, length);
            }
            else if (val[i] == '^')
            {
                int p = pow(b, a);
                top = push(stack, p, top, length);
            }
            else if (val[i] == '-')
            {
                top = push(stack, b - a, top, length);
            }
            else if (val[i] == '*')
            {
                top = push(stack, b * a, top, length);
            }
            else if (val[i] == '/')
            {
                top = push(stack, b / a, top, length);
            }
        }
        i++;
    }
    printf("answer is %d ", stack[0]);
}