#include <stdio.h>
int main()
{
    int n;
    printf("Enter no of elements: ");
    scanf("%d", &n);

    int a[n], max, min;
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    max = a[0];
    min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    printf("Max:%d\n", max);
    printf("Min:%d", min);

    return 0;
}