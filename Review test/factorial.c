#include <stdio.h>
void fact(int c)
{
    int s;
    for (int j = 0; j <= c; j++)
    {
        s = 1;
        if (c > 0)
            for (int i = 1; i <= j; i++)
                s *= i;
        printf("%d ", s);
    }
}

int main()
{
    int a;
    printf("Enter no: ");
    scanf("%d", &a);
    fact(a);
    return 0;
}