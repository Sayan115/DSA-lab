#include <stdio.h>
int main()
{
    int n, s1, s2;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter element 1: ");
    scanf("%d", &s1);
    printf("Enter element 2: ");
    scanf("%d", &s2);
    int c = 0, p;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == s1)
            {p = i;
                break;
            }
    }
    for (int j = p; j < n; j++)
    {
        c++;
        printf("%d ", a[j]);
        if (a[j] == s2)
            break;
    }
    printf("No of elements: %d", c);
    return 0;
}