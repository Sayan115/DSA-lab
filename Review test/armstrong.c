#include <stdio.h>
int sum(int c)
{
    int a = 0;
    while (c != 0)
    {
        int t = c % 10;
        c = c / 10;
        a += t * t * t;
    }
    return a;
}

int main()
{
    int a;
    printf("Enter no: ");
    scanf("%d", &a);
    if (sum(a) == a)
        printf("Armstrong");
    else
        printf("Not Armstrong");

    return 0;
}