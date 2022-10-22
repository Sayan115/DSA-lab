#include <stdio.h>
void fibo(int c)
{
    int a = 0, b = 1, s = 1;
    while (c > 0)
    {
        printf("%d ", s);
        c--;
        s = a + b;
        a = b;
        b = s;
    }
}

int main()
{
    int a;
    printf("Enter no of terms: ");
    scanf("%d", &a);
    fibo(a);
    return 0;
}