#include <stdio.h>
int main()
{
    int i, j;
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-1; j++)
        {
            if ((a[j] % 2 != 0) && (a[j + 1] % 2 == 0))
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("New array\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}