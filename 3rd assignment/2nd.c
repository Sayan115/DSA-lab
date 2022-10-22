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
        for (j = 0; j < n; j++)
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Second smallest number is : %d\n", a[1]);
    printf("Second largest number is : %d", a[n-2]);
    return 0;
}