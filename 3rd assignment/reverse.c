#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the Array: \n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int t;
    for (int i = 0; i < n / 2; i++)
    {
        t = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = t;
    }
    printf("Reverse array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}