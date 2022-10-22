#include <stdio.h>
void sum(int c)
{
    int a = 0;
    while (c != 0)
    {
        int t = c % 10;
        c = c / 10;
        a += t;
    }
    printf("Sum: %d", a);
}

int main()
{
    int a;
    printf("Enter no: ");
    scanf("%d", &a);
    sum(a);
    return 0;
}