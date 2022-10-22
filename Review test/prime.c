#include <stdio.h>
void prime(int c)
{
    int a = 0;
    for (int i = 1; i <= c / 2; i++)
        if (c % i == 0)
            a++;
    if (a == 1)
        printf("Prime");
    else
        printf("Not Prime");
}

int main()
{
    int a;
    printf("Enter no: ");
    scanf("%d", &a);
    prime(a);
    return 0;
}