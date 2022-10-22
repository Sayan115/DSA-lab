#include <stdio.h>
void check(int c)
{
    switch (c)
    {
        int a, b, t;
    case 1:
        printf("Enter the no.s: ");
        scanf("%d %d", &a, &b);
        t = a + b;
        printf("Sum: %d", t);
        break;
    case 2:
        printf("Enter the no.s: ");
        scanf("%d %d", &a, &b);
        if (a > b)
            t = a - b;
        else
            t = b - a;
        printf("Difference: %d", t);
        break;
    case 3:
        printf("Enter the no.s: ");
        scanf("%d %d", &a, &b);
        t = a * b;
        printf("Product: %d", t);
        break;
    case 4:
        printf("Enter the no.s: ");
        scanf("%d %d", &a, &b);
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
    int c;
    printf("1=Addition\n2=Subtraction\n3=Multiplication\n4=Division\nEnter:");
    scanf("%d", &c);
    check(c);
    return 0;
}