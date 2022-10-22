#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
};
struct node *push(struct node *stack, char n)
{
    struct node *NEW = (struct node *)malloc(sizeof(struct node));
    NEW->data = n;
    NEW->next = stack;
    return NEW;
}
char peek(struct node *stack)
{
    return stack->data;
}
struct node *pop(struct node *stack)
{
    if (stack == NULL)
    {
        printf("UNDERFLOW\n");
        return stack;
    }
    if (peek(stack) != '(')
        printf("%c", stack->data);
    return stack->next;
}

int main()
{
    struct node *stack = NULL;
    char e[20];
    int i = 0, j = 0, len = 0;
    printf("Enter infix expression\n");
    scanf("%s", e);

    stack = push(stack, '(');
    while (e[len] != '\0')
    {
        len++;
    }
    e[len] = ')';
    while (e[i] != '\0')
    {
        if ((int)e[i] >= 48 && (int)e[i] <= 57)
        {
            printf("%c", e[i]);
        }
        else if ((int)e[i] == 41)
        {
            while (peek(stack) != '(')
            {
                stack = pop(stack);
            }
            stack = pop(stack);
        }
        else
        {
            if (e[i] == '+')
            {
                while (peek(stack) == '-' || peek(stack) == '/' || peek(stack) == '*' || peek(stack) == '^')
                {
                    stack = pop(stack);
                }
            }
            else if (e[i] == '-')
            {
                while (peek(stack) == '+' || peek(stack) == '/' || peek(stack) == '*' || peek(stack) == '^')
                {
                    stack = pop(stack);
                }
            }
            else if (e[i] == '*')
            {
                while (peek(stack) == '/' || peek(stack) == '^')
                {
                    stack = pop(stack);
                }
            }
            else if (e[i] == '/')
            {
                while (peek(stack) == '*' || peek(stack) == '^')
                {
                    stack = pop(stack);
                }
            }
            else if (e[i] == '^')
            {
                while (peek(stack) == '/' || peek(stack) == '*')
                {
                    stack = pop(stack);
                }
            }
            stack = push(stack, e[i]);
        }
        i++;
    }
}