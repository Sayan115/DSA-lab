#include <stdio.h>
int dec(int c)
{
    int a = 0,p=0;
    while (c != 0)
    {
        int t = c % 10;
        c = c / 10;
        a = a +(t<<(p++));
    }
    return a;
}

int main()
{
    int a;
    printf("Enter no: ");
    scanf("%d", &a);
    printf("%d", dec(a));
    return 0;
}