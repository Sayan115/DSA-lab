#include <stdio.h>
void sum(int c)
{
    int s = 0;
    for (int i = 1; i <= c; i++)
        s += i;
    printf("Sum=%d", s);
}

int main()
{
    int a;
    printf("Enter no: ");
    scanf("%d", &a);
    sum(a);
    return 0;
}