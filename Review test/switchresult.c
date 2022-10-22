#include <stdio.h>
int try(char c)
{
    if (c == '+')
        return 1;
    else if (c == '-')
        return 2;
    else if (c == '*')
        return 3;
    else if (c == '/')
        return 4;
    else
        return 0;
}
void check(char c, int a, int b)
{
    int i = try(c);
    switch (i)
    {
        int t;
    case 1:
        t = a + b;
        printf("Sum: %d", t);
        break;
    case 2:
        if (a > b)
            t = a - b;
        else
            t = b - a;
        printf("Difference: %d", t);
        break;
    case 3:
        t = a * b;
        printf("Product: %d", t);
        break;
    case 4:
        t = a / b;
        printf("Quotient: %d\n", t);
        t = a % b;
        printf("Remainder: %d", t);
        break;
    default:
        printf("Wrong input");
    }
}
int main()
{
    int a, b;
    char ch;
    printf("Enter nos.: ");
    scanf("%d %d", &a, &b);
    printf("Enter operator: ");
    scanf(" %c", &ch);
    check(ch, a, b);
    return 0;
}