#include <stdio.h>
void rev(int c)
{
    int a = 0;
    while (c != 0)
    {
        int t = c % 10;
        c = c / 10;
        a = a * 10 + t;
    }
    printf("Reverse: %d", a);
}

int main()
{
    int a;
    printf("Enter no: ");
    scanf("%d", &a);
    rev(a);
    return 0;
}