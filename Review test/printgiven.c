#include <stdio.h>
void sum(int c)
{
    for (int i = 1; i <= c; i++)
        printf("%d ", i);
}

int main()
{
    int a;
    printf("Enter no: ");
    scanf("%d", &a);
    sum(a);
    return 0;
}