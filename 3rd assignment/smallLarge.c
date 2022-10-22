#include <stdio.h>
int main()
{
    int n, l, s;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the Array:\n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    l = s = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > l)
            l = a[i];
        if (a[i] < s)
            s = a[i];
    }
    printf("The largest element is %d", l);
    printf("\nThe smallest element is %d", s);
    return 0;
}