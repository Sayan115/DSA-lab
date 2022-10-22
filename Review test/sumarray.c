#include <stdio.h>
int main()
{
    int n;
    printf("Enter no of elements: ");
    scanf("%d", &n);

    int a[n], b[n], s[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < n; i++)
        s[i] = a[i] + b[i];
    for (int i = 0; i < n; i++)
        printf("%d ", s[i]);
    return 0;
}