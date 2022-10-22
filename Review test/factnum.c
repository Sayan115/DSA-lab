#include <stdio.h>
void fact(int c)
{
    int s = 1;
    if (c > 0)
    {
        for (int i = 1; i <= c; i++)
            s *= i;
    }
    printf("Factorial:%d", s);
}

int main()
{
    int a;
    printf("Enter no: ");
    scanf("%d", &a);
    fact(a);
    return 0;
}